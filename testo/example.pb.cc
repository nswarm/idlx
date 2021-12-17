// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: example.proto

#include "example.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG
namespace pkg {
constexpr Example::Example(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : str_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , i32_(0){}
struct ExampleDefaultTypeInternal {
  constexpr ExampleDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~ExampleDefaultTypeInternal() {}
  union {
    Example _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT ExampleDefaultTypeInternal _Example_default_instance_;
}  // namespace pkg
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_example_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_example_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_example_2eproto = nullptr;

const uint32_t TableStruct_example_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::pkg::Example, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::pkg::Example, str_),
  PROTOBUF_FIELD_OFFSET(::pkg::Example, i32_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::pkg::Example)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::pkg::_Example_default_instance_),
};

const char descriptor_table_protodef_example_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\rexample.proto\022\003pkg\"#\n\007Example\022\013\n\003str\030\001"
  " \001(\t\022\013\n\003i32\030\002 \001(\005b\006proto3"
  ;
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_example_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_example_2eproto = {
  false, false, 65, descriptor_table_protodef_example_2eproto, "example.proto", 
  &descriptor_table_example_2eproto_once, nullptr, 0, 1,
  schemas, file_default_instances, TableStruct_example_2eproto::offsets,
  file_level_metadata_example_2eproto, file_level_enum_descriptors_example_2eproto, file_level_service_descriptors_example_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable* descriptor_table_example_2eproto_getter() {
  return &descriptor_table_example_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_example_2eproto(&descriptor_table_example_2eproto);
namespace pkg {

// ===================================================================

class Example::_Internal {
 public:
};

Example::Example(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:pkg.Example)
}
Example::Example(const Example& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  str_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    str_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_str().empty()) {
    str_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_str(), 
      GetArenaForAllocation());
  }
  i32_ = from.i32_;
  // @@protoc_insertion_point(copy_constructor:pkg.Example)
}

inline void Example::SharedCtor() {
str_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  str_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
i32_ = 0;
}

Example::~Example() {
  // @@protoc_insertion_point(destructor:pkg.Example)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void Example::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  str_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void Example::ArenaDtor(void* object) {
  Example* _this = reinterpret_cast< Example* >(object);
  (void)_this;
}
void Example::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void Example::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void Example::Clear() {
// @@protoc_insertion_point(message_clear_start:pkg.Example)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  str_.ClearToEmpty();
  i32_ = 0;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Example::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // string str = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          auto str = _internal_mutable_str();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "pkg.Example.str"));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // int32 i32 = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 16)) {
          i32_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* Example::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:pkg.Example)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // string str = 1;
  if (!this->_internal_str().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_str().data(), static_cast<int>(this->_internal_str().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "pkg.Example.str");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_str(), target);
  }

  // int32 i32 = 2;
  if (this->_internal_i32() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(2, this->_internal_i32(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:pkg.Example)
  return target;
}

size_t Example::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:pkg.Example)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string str = 1;
  if (!this->_internal_str().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_str());
  }

  // int32 i32 = 2;
  if (this->_internal_i32() != 0) {
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32SizePlusOne(this->_internal_i32());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Example::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    Example::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Example::GetClassData() const { return &_class_data_; }

void Example::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<Example *>(to)->MergeFrom(
      static_cast<const Example &>(from));
}


void Example::MergeFrom(const Example& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:pkg.Example)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_str().empty()) {
    _internal_set_str(from._internal_str());
  }
  if (from._internal_i32() != 0) {
    _internal_set_i32(from._internal_i32());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Example::CopyFrom(const Example& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:pkg.Example)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Example::IsInitialized() const {
  return true;
}

void Example::InternalSwap(Example* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &str_, lhs_arena,
      &other->str_, rhs_arena
  );
  swap(i32_, other->i32_);
}

::PROTOBUF_NAMESPACE_ID::Metadata Example::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_example_2eproto_getter, &descriptor_table_example_2eproto_once,
      file_level_metadata_example_2eproto[0]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace pkg
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::pkg::Example* Arena::CreateMaybeMessage< ::pkg::Example >(Arena* arena) {
  return Arena::CreateMessageInternal< ::pkg::Example >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
