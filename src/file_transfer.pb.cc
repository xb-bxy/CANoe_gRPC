// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: file_transfer.proto
// Protobuf C++ Version: 5.26.1

#include "file_transfer.pb.h"

#include <algorithm>
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/extension_set.h"
#include "google/protobuf/wire_format_lite.h"
#include "google/protobuf/descriptor.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/reflection_ops.h"
#include "google/protobuf/wire_format.h"
#include "google/protobuf/generated_message_tctable_impl.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"
PROTOBUF_PRAGMA_INIT_SEG
namespace _pb = ::google::protobuf;
namespace _pbi = ::google::protobuf::internal;
namespace _fl = ::google::protobuf::internal::field_layout;
namespace filetransfer {

inline constexpr TransferStatus::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : message_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        success_{false},
        _cached_size_{0} {}

template <typename>
PROTOBUF_CONSTEXPR TransferStatus::TransferStatus(::_pbi::ConstantInitialized)
    : _impl_(::_pbi::ConstantInitialized()) {}
struct TransferStatusDefaultTypeInternal {
  PROTOBUF_CONSTEXPR TransferStatusDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~TransferStatusDefaultTypeInternal() {}
  union {
    TransferStatus _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 TransferStatusDefaultTypeInternal _TransferStatus_default_instance_;

inline constexpr FileRequest::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : path_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        _cached_size_{0} {}

template <typename>
PROTOBUF_CONSTEXPR FileRequest::FileRequest(::_pbi::ConstantInitialized)
    : _impl_(::_pbi::ConstantInitialized()) {}
struct FileRequestDefaultTypeInternal {
  PROTOBUF_CONSTEXPR FileRequestDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~FileRequestDefaultTypeInternal() {}
  union {
    FileRequest _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 FileRequestDefaultTypeInternal _FileRequest_default_instance_;

inline constexpr FileChunk::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : filename_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        content_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        filesize_{::uint64_t{0u}},
        is_dir_{false},
        _cached_size_{0} {}

template <typename>
PROTOBUF_CONSTEXPR FileChunk::FileChunk(::_pbi::ConstantInitialized)
    : _impl_(::_pbi::ConstantInitialized()) {}
struct FileChunkDefaultTypeInternal {
  PROTOBUF_CONSTEXPR FileChunkDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~FileChunkDefaultTypeInternal() {}
  union {
    FileChunk _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 FileChunkDefaultTypeInternal _FileChunk_default_instance_;
}  // namespace filetransfer
static ::_pb::Metadata file_level_metadata_file_5ftransfer_2eproto[3];
static constexpr const ::_pb::EnumDescriptor**
    file_level_enum_descriptors_file_5ftransfer_2eproto = nullptr;
static constexpr const ::_pb::ServiceDescriptor**
    file_level_service_descriptors_file_5ftransfer_2eproto = nullptr;
const ::uint32_t
    TableStruct_file_5ftransfer_2eproto::offsets[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
        protodesc_cold) = {
        ~0u,  // no _has_bits_
        PROTOBUF_FIELD_OFFSET(::filetransfer::FileChunk, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
        PROTOBUF_FIELD_OFFSET(::filetransfer::FileChunk, _impl_.filename_),
        PROTOBUF_FIELD_OFFSET(::filetransfer::FileChunk, _impl_.content_),
        PROTOBUF_FIELD_OFFSET(::filetransfer::FileChunk, _impl_.is_dir_),
        PROTOBUF_FIELD_OFFSET(::filetransfer::FileChunk, _impl_.filesize_),
        ~0u,  // no _has_bits_
        PROTOBUF_FIELD_OFFSET(::filetransfer::FileRequest, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
        PROTOBUF_FIELD_OFFSET(::filetransfer::FileRequest, _impl_.path_),
        ~0u,  // no _has_bits_
        PROTOBUF_FIELD_OFFSET(::filetransfer::TransferStatus, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
        PROTOBUF_FIELD_OFFSET(::filetransfer::TransferStatus, _impl_.success_),
        PROTOBUF_FIELD_OFFSET(::filetransfer::TransferStatus, _impl_.message_),
};

static const ::_pbi::MigrationSchema
    schemas[] ABSL_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
        {0, -1, -1, sizeof(::filetransfer::FileChunk)},
        {12, -1, -1, sizeof(::filetransfer::FileRequest)},
        {21, -1, -1, sizeof(::filetransfer::TransferStatus)},
};
static const ::_pb::Message* const file_default_instances[] = {
    &::filetransfer::_FileChunk_default_instance_._instance,
    &::filetransfer::_FileRequest_default_instance_._instance,
    &::filetransfer::_TransferStatus_default_instance_._instance,
};
const char descriptor_table_protodef_file_5ftransfer_2eproto[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
    protodesc_cold) = {
    "\n\023file_transfer.proto\022\014filetransfer\"P\n\tF"
    "ileChunk\022\020\n\010filename\030\001 \001(\t\022\017\n\007content\030\002 "
    "\001(\014\022\016\n\006is_dir\030\003 \001(\010\022\020\n\010filesize\030\004 \001(\004\"\033\n"
    "\013FileRequest\022\014\n\004path\030\001 \001(\t\"2\n\016TransferSt"
    "atus\022\017\n\007success\030\001 \001(\010\022\017\n\007message\030\002 \001(\t2\223"
    "\001\n\014FileTransfer\022A\n\006Upload\022\027.filetransfer"
    ".FileChunk\032\034.filetransfer.TransferStatus"
    "(\001\022@\n\010Download\022\031.filetransfer.FileReques"
    "t\032\027.filetransfer.FileChunk0\001b\006proto3"
};
static ::absl::once_flag descriptor_table_file_5ftransfer_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_file_5ftransfer_2eproto = {
    false,
    false,
    356,
    descriptor_table_protodef_file_5ftransfer_2eproto,
    "file_transfer.proto",
    &descriptor_table_file_5ftransfer_2eproto_once,
    nullptr,
    0,
    3,
    schemas,
    file_default_instances,
    TableStruct_file_5ftransfer_2eproto::offsets,
    file_level_metadata_file_5ftransfer_2eproto,
    file_level_enum_descriptors_file_5ftransfer_2eproto,
    file_level_service_descriptors_file_5ftransfer_2eproto,
};

// This function exists to be marked as weak.
// It can significantly speed up compilation by breaking up LLVM's SCC
// in the .pb.cc translation units. Large translation units see a
// reduction of more than 35% of walltime for optimized builds. Without
// the weak attribute all the messages in the file, including all the
// vtables and everything they use become part of the same SCC through
// a cycle like:
// GetMetadata -> descriptor table -> default instances ->
//   vtables -> GetMetadata
// By adding a weak function here we break the connection from the
// individual vtables back into the descriptor table.
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_file_5ftransfer_2eproto_getter() {
  return &descriptor_table_file_5ftransfer_2eproto;
}
namespace filetransfer {
// ===================================================================

class FileChunk::_Internal {
 public:
};

FileChunk::FileChunk(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:filetransfer.FileChunk)
}
inline PROTOBUF_NDEBUG_INLINE FileChunk::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena* arena,
    const Impl_& from)
      : filename_(arena, from.filename_),
        content_(arena, from.content_),
        _cached_size_{0} {}

FileChunk::FileChunk(
    ::google::protobuf::Arena* arena,
    const FileChunk& from)
    : ::google::protobuf::Message(arena) {
  FileChunk* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_);
  ::memcpy(reinterpret_cast<char *>(&_impl_) +
               offsetof(Impl_, filesize_),
           reinterpret_cast<const char *>(&from._impl_) +
               offsetof(Impl_, filesize_),
           offsetof(Impl_, is_dir_) -
               offsetof(Impl_, filesize_) +
               sizeof(Impl_::is_dir_));

  // @@protoc_insertion_point(copy_constructor:filetransfer.FileChunk)
}
inline PROTOBUF_NDEBUG_INLINE FileChunk::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : filename_(arena),
        content_(arena),
        _cached_size_{0} {}

inline void FileChunk::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
  ::memset(reinterpret_cast<char *>(&_impl_) +
               offsetof(Impl_, filesize_),
           0,
           offsetof(Impl_, is_dir_) -
               offsetof(Impl_, filesize_) +
               sizeof(Impl_::is_dir_));
}
FileChunk::~FileChunk() {
  // @@protoc_insertion_point(destructor:filetransfer.FileChunk)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void FileChunk::SharedDtor() {
  ABSL_DCHECK(GetArena() == nullptr);
  _impl_.filename_.Destroy();
  _impl_.content_.Destroy();
  _impl_.~Impl_();
}

const ::google::protobuf::MessageLite::ClassData*
FileChunk::GetClassData() const {
  PROTOBUF_CONSTINIT static const ::google::protobuf::MessageLite::
      ClassDataFull _data_ = {
          {
              nullptr,  // OnDemandRegisterArenaDtor
              PROTOBUF_FIELD_OFFSET(FileChunk, _impl_._cached_size_),
              false,
          },
          &FileChunk::MergeImpl,
          &FileChunk::kDescriptorMethods,
      };
  return &_data_;
}
PROTOBUF_NOINLINE void FileChunk::Clear() {
// @@protoc_insertion_point(message_clear_start:filetransfer.FileChunk)
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.filename_.ClearToEmpty();
  _impl_.content_.ClearToEmpty();
  ::memset(&_impl_.filesize_, 0, static_cast<::size_t>(
      reinterpret_cast<char*>(&_impl_.is_dir_) -
      reinterpret_cast<char*>(&_impl_.filesize_)) + sizeof(_impl_.is_dir_));
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

const char* FileChunk::_InternalParse(
    const char* ptr, ::_pbi::ParseContext* ctx) {
  ptr = ::_pbi::TcParser::ParseLoop(this, ptr, ctx, &_table_.header);
  return ptr;
}


PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<2, 4, 0, 39, 2> FileChunk::_table_ = {
  {
    0,  // no _has_bits_
    0, // no _extensions_
    4, 24,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967280,  // skipmap
    offsetof(decltype(_table_), field_entries),
    4,  // num_field_entries
    0,  // num_aux_entries
    offsetof(decltype(_table_), field_names),  // no aux_entries
    &_FileChunk_default_instance_._instance,
    ::_pbi::TcParser::GenericFallback,  // fallback
    #ifdef PROTOBUF_PREFETCH_PARSE_TABLE
    ::_pbi::TcParser::GetTable<::filetransfer::FileChunk>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    // uint64 filesize = 4;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint64_t, offsetof(FileChunk, _impl_.filesize_), 63>(),
     {32, 63, 0, PROTOBUF_FIELD_OFFSET(FileChunk, _impl_.filesize_)}},
    // string filename = 1;
    {::_pbi::TcParser::FastUS1,
     {10, 63, 0, PROTOBUF_FIELD_OFFSET(FileChunk, _impl_.filename_)}},
    // bytes content = 2;
    {::_pbi::TcParser::FastBS1,
     {18, 63, 0, PROTOBUF_FIELD_OFFSET(FileChunk, _impl_.content_)}},
    // bool is_dir = 3;
    {::_pbi::TcParser::SingularVarintNoZag1<bool, offsetof(FileChunk, _impl_.is_dir_), 63>(),
     {24, 63, 0, PROTOBUF_FIELD_OFFSET(FileChunk, _impl_.is_dir_)}},
  }}, {{
    65535, 65535
  }}, {{
    // string filename = 1;
    {PROTOBUF_FIELD_OFFSET(FileChunk, _impl_.filename_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUtf8String | ::_fl::kRepAString)},
    // bytes content = 2;
    {PROTOBUF_FIELD_OFFSET(FileChunk, _impl_.content_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kBytes | ::_fl::kRepAString)},
    // bool is_dir = 3;
    {PROTOBUF_FIELD_OFFSET(FileChunk, _impl_.is_dir_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kBool)},
    // uint64 filesize = 4;
    {PROTOBUF_FIELD_OFFSET(FileChunk, _impl_.filesize_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUInt64)},
  }},
  // no aux_entries
  {{
    "\26\10\0\0\0\0\0\0"
    "filetransfer.FileChunk"
    "filename"
  }},
};

::uint8_t* FileChunk::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:filetransfer.FileChunk)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  // string filename = 1;
  if (!this->_internal_filename().empty()) {
    const std::string& _s = this->_internal_filename();
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
        _s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "filetransfer.FileChunk.filename");
    target = stream->WriteStringMaybeAliased(1, _s, target);
  }

  // bytes content = 2;
  if (!this->_internal_content().empty()) {
    const std::string& _s = this->_internal_content();
    target = stream->WriteBytesMaybeAliased(2, _s, target);
  }

  // bool is_dir = 3;
  if (this->_internal_is_dir() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteBoolToArray(
        3, this->_internal_is_dir(), target);
  }

  // uint64 filesize = 4;
  if (this->_internal_filesize() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt64ToArray(
        4, this->_internal_filesize(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:filetransfer.FileChunk)
  return target;
}

::size_t FileChunk::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:filetransfer.FileChunk)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string filename = 1;
  if (!this->_internal_filename().empty()) {
    total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                    this->_internal_filename());
  }

  // bytes content = 2;
  if (!this->_internal_content().empty()) {
    total_size += 1 + ::google::protobuf::internal::WireFormatLite::BytesSize(
                                    this->_internal_content());
  }

  // uint64 filesize = 4;
  if (this->_internal_filesize() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt64SizePlusOne(
        this->_internal_filesize());
  }

  // bool is_dir = 3;
  if (this->_internal_is_dir() != 0) {
    total_size += 2;
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}


void FileChunk::MergeImpl(::google::protobuf::MessageLite& to_msg, const ::google::protobuf::MessageLite& from_msg) {
  auto* const _this = static_cast<FileChunk*>(&to_msg);
  auto& from = static_cast<const FileChunk&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:filetransfer.FileChunk)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_filename().empty()) {
    _this->_internal_set_filename(from._internal_filename());
  }
  if (!from._internal_content().empty()) {
    _this->_internal_set_content(from._internal_content());
  }
  if (from._internal_filesize() != 0) {
    _this->_impl_.filesize_ = from._impl_.filesize_;
  }
  if (from._internal_is_dir() != 0) {
    _this->_impl_.is_dir_ = from._impl_.is_dir_;
  }
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void FileChunk::CopyFrom(const FileChunk& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:filetransfer.FileChunk)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

PROTOBUF_NOINLINE bool FileChunk::IsInitialized() const {
  return true;
}

void FileChunk::InternalSwap(FileChunk* PROTOBUF_RESTRICT other) {
  using std::swap;
  auto* arena = GetArena();
  ABSL_DCHECK_EQ(arena, other->GetArena());
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.filename_, &other->_impl_.filename_, arena);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.content_, &other->_impl_.content_, arena);
  ::google::protobuf::internal::memswap<
      PROTOBUF_FIELD_OFFSET(FileChunk, _impl_.is_dir_)
      + sizeof(FileChunk::_impl_.is_dir_)
      - PROTOBUF_FIELD_OFFSET(FileChunk, _impl_.filesize_)>(
          reinterpret_cast<char*>(&_impl_.filesize_),
          reinterpret_cast<char*>(&other->_impl_.filesize_));
}

::google::protobuf::Metadata FileChunk::GetMetadata() const {
  return ::_pbi::AssignDescriptors(&descriptor_table_file_5ftransfer_2eproto_getter,
                                   &descriptor_table_file_5ftransfer_2eproto_once,
                                   file_level_metadata_file_5ftransfer_2eproto[0]);
}
// ===================================================================

class FileRequest::_Internal {
 public:
};

FileRequest::FileRequest(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:filetransfer.FileRequest)
}
inline PROTOBUF_NDEBUG_INLINE FileRequest::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena* arena,
    const Impl_& from)
      : path_(arena, from.path_),
        _cached_size_{0} {}

FileRequest::FileRequest(
    ::google::protobuf::Arena* arena,
    const FileRequest& from)
    : ::google::protobuf::Message(arena) {
  FileRequest* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_);

  // @@protoc_insertion_point(copy_constructor:filetransfer.FileRequest)
}
inline PROTOBUF_NDEBUG_INLINE FileRequest::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : path_(arena),
        _cached_size_{0} {}

inline void FileRequest::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
}
FileRequest::~FileRequest() {
  // @@protoc_insertion_point(destructor:filetransfer.FileRequest)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void FileRequest::SharedDtor() {
  ABSL_DCHECK(GetArena() == nullptr);
  _impl_.path_.Destroy();
  _impl_.~Impl_();
}

const ::google::protobuf::MessageLite::ClassData*
FileRequest::GetClassData() const {
  PROTOBUF_CONSTINIT static const ::google::protobuf::MessageLite::
      ClassDataFull _data_ = {
          {
              nullptr,  // OnDemandRegisterArenaDtor
              PROTOBUF_FIELD_OFFSET(FileRequest, _impl_._cached_size_),
              false,
          },
          &FileRequest::MergeImpl,
          &FileRequest::kDescriptorMethods,
      };
  return &_data_;
}
PROTOBUF_NOINLINE void FileRequest::Clear() {
// @@protoc_insertion_point(message_clear_start:filetransfer.FileRequest)
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.path_.ClearToEmpty();
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

const char* FileRequest::_InternalParse(
    const char* ptr, ::_pbi::ParseContext* ctx) {
  ptr = ::_pbi::TcParser::ParseLoop(this, ptr, ctx, &_table_.header);
  return ptr;
}


PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<0, 1, 0, 37, 2> FileRequest::_table_ = {
  {
    0,  // no _has_bits_
    0, // no _extensions_
    1, 0,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967294,  // skipmap
    offsetof(decltype(_table_), field_entries),
    1,  // num_field_entries
    0,  // num_aux_entries
    offsetof(decltype(_table_), field_names),  // no aux_entries
    &_FileRequest_default_instance_._instance,
    ::_pbi::TcParser::GenericFallback,  // fallback
    #ifdef PROTOBUF_PREFETCH_PARSE_TABLE
    ::_pbi::TcParser::GetTable<::filetransfer::FileRequest>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    // string path = 1;
    {::_pbi::TcParser::FastUS1,
     {10, 63, 0, PROTOBUF_FIELD_OFFSET(FileRequest, _impl_.path_)}},
  }}, {{
    65535, 65535
  }}, {{
    // string path = 1;
    {PROTOBUF_FIELD_OFFSET(FileRequest, _impl_.path_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUtf8String | ::_fl::kRepAString)},
  }},
  // no aux_entries
  {{
    "\30\4\0\0\0\0\0\0"
    "filetransfer.FileRequest"
    "path"
  }},
};

::uint8_t* FileRequest::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:filetransfer.FileRequest)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  // string path = 1;
  if (!this->_internal_path().empty()) {
    const std::string& _s = this->_internal_path();
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
        _s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "filetransfer.FileRequest.path");
    target = stream->WriteStringMaybeAliased(1, _s, target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:filetransfer.FileRequest)
  return target;
}

::size_t FileRequest::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:filetransfer.FileRequest)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string path = 1;
  if (!this->_internal_path().empty()) {
    total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                    this->_internal_path());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}


void FileRequest::MergeImpl(::google::protobuf::MessageLite& to_msg, const ::google::protobuf::MessageLite& from_msg) {
  auto* const _this = static_cast<FileRequest*>(&to_msg);
  auto& from = static_cast<const FileRequest&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:filetransfer.FileRequest)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_path().empty()) {
    _this->_internal_set_path(from._internal_path());
  }
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void FileRequest::CopyFrom(const FileRequest& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:filetransfer.FileRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

PROTOBUF_NOINLINE bool FileRequest::IsInitialized() const {
  return true;
}

void FileRequest::InternalSwap(FileRequest* PROTOBUF_RESTRICT other) {
  using std::swap;
  auto* arena = GetArena();
  ABSL_DCHECK_EQ(arena, other->GetArena());
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.path_, &other->_impl_.path_, arena);
}

::google::protobuf::Metadata FileRequest::GetMetadata() const {
  return ::_pbi::AssignDescriptors(&descriptor_table_file_5ftransfer_2eproto_getter,
                                   &descriptor_table_file_5ftransfer_2eproto_once,
                                   file_level_metadata_file_5ftransfer_2eproto[1]);
}
// ===================================================================

class TransferStatus::_Internal {
 public:
};

TransferStatus::TransferStatus(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:filetransfer.TransferStatus)
}
inline PROTOBUF_NDEBUG_INLINE TransferStatus::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena* arena,
    const Impl_& from)
      : message_(arena, from.message_),
        _cached_size_{0} {}

TransferStatus::TransferStatus(
    ::google::protobuf::Arena* arena,
    const TransferStatus& from)
    : ::google::protobuf::Message(arena) {
  TransferStatus* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_);
  _impl_.success_ = from._impl_.success_;

  // @@protoc_insertion_point(copy_constructor:filetransfer.TransferStatus)
}
inline PROTOBUF_NDEBUG_INLINE TransferStatus::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : message_(arena),
        _cached_size_{0} {}

inline void TransferStatus::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
  _impl_.success_ = {};
}
TransferStatus::~TransferStatus() {
  // @@protoc_insertion_point(destructor:filetransfer.TransferStatus)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void TransferStatus::SharedDtor() {
  ABSL_DCHECK(GetArena() == nullptr);
  _impl_.message_.Destroy();
  _impl_.~Impl_();
}

const ::google::protobuf::MessageLite::ClassData*
TransferStatus::GetClassData() const {
  PROTOBUF_CONSTINIT static const ::google::protobuf::MessageLite::
      ClassDataFull _data_ = {
          {
              nullptr,  // OnDemandRegisterArenaDtor
              PROTOBUF_FIELD_OFFSET(TransferStatus, _impl_._cached_size_),
              false,
          },
          &TransferStatus::MergeImpl,
          &TransferStatus::kDescriptorMethods,
      };
  return &_data_;
}
PROTOBUF_NOINLINE void TransferStatus::Clear() {
// @@protoc_insertion_point(message_clear_start:filetransfer.TransferStatus)
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.message_.ClearToEmpty();
  _impl_.success_ = false;
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

const char* TransferStatus::_InternalParse(
    const char* ptr, ::_pbi::ParseContext* ctx) {
  ptr = ::_pbi::TcParser::ParseLoop(this, ptr, ctx, &_table_.header);
  return ptr;
}


PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<1, 2, 0, 43, 2> TransferStatus::_table_ = {
  {
    0,  // no _has_bits_
    0, // no _extensions_
    2, 8,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967292,  // skipmap
    offsetof(decltype(_table_), field_entries),
    2,  // num_field_entries
    0,  // num_aux_entries
    offsetof(decltype(_table_), field_names),  // no aux_entries
    &_TransferStatus_default_instance_._instance,
    ::_pbi::TcParser::GenericFallback,  // fallback
    #ifdef PROTOBUF_PREFETCH_PARSE_TABLE
    ::_pbi::TcParser::GetTable<::filetransfer::TransferStatus>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    // string message = 2;
    {::_pbi::TcParser::FastUS1,
     {18, 63, 0, PROTOBUF_FIELD_OFFSET(TransferStatus, _impl_.message_)}},
    // bool success = 1;
    {::_pbi::TcParser::SingularVarintNoZag1<bool, offsetof(TransferStatus, _impl_.success_), 63>(),
     {8, 63, 0, PROTOBUF_FIELD_OFFSET(TransferStatus, _impl_.success_)}},
  }}, {{
    65535, 65535
  }}, {{
    // bool success = 1;
    {PROTOBUF_FIELD_OFFSET(TransferStatus, _impl_.success_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kBool)},
    // string message = 2;
    {PROTOBUF_FIELD_OFFSET(TransferStatus, _impl_.message_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUtf8String | ::_fl::kRepAString)},
  }},
  // no aux_entries
  {{
    "\33\0\7\0\0\0\0\0"
    "filetransfer.TransferStatus"
    "message"
  }},
};

::uint8_t* TransferStatus::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:filetransfer.TransferStatus)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  // bool success = 1;
  if (this->_internal_success() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteBoolToArray(
        1, this->_internal_success(), target);
  }

  // string message = 2;
  if (!this->_internal_message().empty()) {
    const std::string& _s = this->_internal_message();
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
        _s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "filetransfer.TransferStatus.message");
    target = stream->WriteStringMaybeAliased(2, _s, target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:filetransfer.TransferStatus)
  return target;
}

::size_t TransferStatus::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:filetransfer.TransferStatus)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string message = 2;
  if (!this->_internal_message().empty()) {
    total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                    this->_internal_message());
  }

  // bool success = 1;
  if (this->_internal_success() != 0) {
    total_size += 2;
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}


void TransferStatus::MergeImpl(::google::protobuf::MessageLite& to_msg, const ::google::protobuf::MessageLite& from_msg) {
  auto* const _this = static_cast<TransferStatus*>(&to_msg);
  auto& from = static_cast<const TransferStatus&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:filetransfer.TransferStatus)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_message().empty()) {
    _this->_internal_set_message(from._internal_message());
  }
  if (from._internal_success() != 0) {
    _this->_impl_.success_ = from._impl_.success_;
  }
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void TransferStatus::CopyFrom(const TransferStatus& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:filetransfer.TransferStatus)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

PROTOBUF_NOINLINE bool TransferStatus::IsInitialized() const {
  return true;
}

void TransferStatus::InternalSwap(TransferStatus* PROTOBUF_RESTRICT other) {
  using std::swap;
  auto* arena = GetArena();
  ABSL_DCHECK_EQ(arena, other->GetArena());
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.message_, &other->_impl_.message_, arena);
        swap(_impl_.success_, other->_impl_.success_);
}

::google::protobuf::Metadata TransferStatus::GetMetadata() const {
  return ::_pbi::AssignDescriptors(&descriptor_table_file_5ftransfer_2eproto_getter,
                                   &descriptor_table_file_5ftransfer_2eproto_once,
                                   file_level_metadata_file_5ftransfer_2eproto[2]);
}
// @@protoc_insertion_point(namespace_scope)
}  // namespace filetransfer
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google
// @@protoc_insertion_point(global_scope)
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2
static ::std::false_type _static_init_ PROTOBUF_UNUSED =
    (::_pbi::AddDescriptors(&descriptor_table_file_5ftransfer_2eproto),
     ::std::false_type{});
#include "google/protobuf/port_undef.inc"
