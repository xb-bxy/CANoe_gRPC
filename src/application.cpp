#include <atlbase.h>
#include "CANoe.h"

class VApplication
{
public
  VApplication() : mApplication(NULL) {}
  ~VApplication() {}
  bool Connect(const char* pcName);
private
  CComPtr<IApplication> mApplication;
}

bool VApplication::Connect(const char* pcName)
{
  if (mApplication != NULL)
    mApplication.Release();
  const IID IID_IApplication = __uuidof(IApplication);
  MULTI_QI qi = {&IID_IApplication, NULL, S_OK};
  // Get the CLSID
  CLSID clsid;
  HRESULT hr = CLSIDFromProgID(L"CANoe.Application", &clsid);
  if (!SUCCEEDED(hr))
    return false;
  // Set up the NULL security information
  COAUTHINFO athn = {0};
  athn.dwAuthnLevel = RPC_C_AUTHN_LEVEL_NONE;
  athn.dwAuthnSvc = RPC_C_AUTHN_WINNT;
  athn.dwAuthzSvc = RPC_C_AUTHZ_NONE;
  athn.dwCapabilities = EOAC_NONE;
  athn.dwImpersonationLevel = RPC_C_IMP_LEVEL_IMPERSONATE;
  athn.pAuthIdentityData = NULL;
  athn.pwszServerPrincName = NULL;
  // Set up server info
  int len=strlen(pcName)+1;
  wchar_t* buffer = new wchar_t[len];
  MultiByteToWideChar(CP_ACP, NULL, pcName, -1, buffer, len);
  COSERVERINFO serverInfo = {0};
  serverInfo.pwszName = buffer;
  // try to establish the connection
  if ( SUCCEEDED( ::CoInitializeSecurity( NULL, -1, NULL, NULL, RPC_C_AUTHN_LEVEL_NONE, RPC_C_IMP_LEVEL_IMPERSONATE, NULL, EOAC_NONE, NULL)))
  {
    // (try to) connect to CANoe
    hr = CoCreateInstanceEx(clsid, NULL, CLSCTX_LOCAL_SERVER | CLSCTX_REMOTE_SERVER, &serverInfo, 1, &qi);
  }
  else
    hr = E_FAIL;
  delete[] buffer;
  if (!SUCCEEDED(hr))
    return false;
  mApplication.Attach((IApplication2*)qi.pItf);
  return (mApplication != NULL);
}

int main(int argc, char** argv)
{
  CComModule module;
  VApplication* app;
  // Initialize the COM interface; this must be done exactly once per thread
  ::CoInitializeEx( NULL, COINIT_MULTITHREADED);
  module.Init(NULL, ::GetModuleHandle( NULL));
  // Establish a connection to CANoe via DCOM. The remote PC must be in the same network.
  app = new VApplication();
  if (app->Connect("MyCANoePC"))   // replace MyCANoePC with name of the PC
  {
  // Work with the connection here
    printf("Connection established\n");
  }
  else   // something went wrong
  {
    printf("Couldn't connect to CANoe\n");
  }
  // Shutdown the connection and cleanup
  delete app;
  // Uninitialize the COM interface; this must be done exactly once per thread
  module.Term();
  ::CoUninitialize();
  return 0;
}