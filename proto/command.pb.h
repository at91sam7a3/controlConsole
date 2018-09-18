// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: command.proto

#ifndef PROTOBUF_command_2eproto__INCLUDED
#define PROTOBUF_command_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3005001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace protobuf_command_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[4];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
void InitDefaultsCommandToServoImpl();
void InitDefaultsCommandToServo();
void InitDefaultsResponceFromServoImpl();
void InitDefaultsResponceFromServo();
void InitDefaultsMoveCommandImpl();
void InitDefaultsMoveCommand();
void InitDefaultsLegMoveCommandImpl();
void InitDefaultsLegMoveCommand();
inline void InitDefaults() {
  InitDefaultsCommandToServo();
  InitDefaultsResponceFromServo();
  InitDefaultsMoveCommand();
  InitDefaultsLegMoveCommand();
}
}  // namespace protobuf_command_2eproto
namespace Command {
class CommandToServo;
class CommandToServoDefaultTypeInternal;
extern CommandToServoDefaultTypeInternal _CommandToServo_default_instance_;
class LegMoveCommand;
class LegMoveCommandDefaultTypeInternal;
extern LegMoveCommandDefaultTypeInternal _LegMoveCommand_default_instance_;
class MoveCommand;
class MoveCommandDefaultTypeInternal;
extern MoveCommandDefaultTypeInternal _MoveCommand_default_instance_;
class ResponceFromServo;
class ResponceFromServoDefaultTypeInternal;
extern ResponceFromServoDefaultTypeInternal _ResponceFromServo_default_instance_;
}  // namespace Command
namespace Command {

// ===================================================================

class CommandToServo : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:Command.CommandToServo) */ {
 public:
  CommandToServo();
  virtual ~CommandToServo();

  CommandToServo(const CommandToServo& from);

  inline CommandToServo& operator=(const CommandToServo& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  CommandToServo(CommandToServo&& from) noexcept
    : CommandToServo() {
    *this = ::std::move(from);
  }

  inline CommandToServo& operator=(CommandToServo&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const CommandToServo& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const CommandToServo* internal_default_instance() {
    return reinterpret_cast<const CommandToServo*>(
               &_CommandToServo_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(CommandToServo* other);
  friend void swap(CommandToServo& a, CommandToServo& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline CommandToServo* New() const PROTOBUF_FINAL { return New(NULL); }

  CommandToServo* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const CommandToServo& from);
  void MergeFrom(const CommandToServo& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(CommandToServo* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required string name = 1;
  bool has_name() const;
  void clear_name();
  static const int kNameFieldNumber = 1;
  const ::std::string& name() const;
  void set_name(const ::std::string& value);
  #if LANG_CXX11
  void set_name(::std::string&& value);
  #endif
  void set_name(const char* value);
  void set_name(const char* value, size_t size);
  ::std::string* mutable_name();
  ::std::string* release_name();
  void set_allocated_name(::std::string* name);

  // required uint32 servoId = 2;
  bool has_servoid() const;
  void clear_servoid();
  static const int kServoIdFieldNumber = 2;
  ::google::protobuf::uint32 servoid() const;
  void set_servoid(::google::protobuf::uint32 value);

  // optional int32 param1 = 3;
  bool has_param1() const;
  void clear_param1();
  static const int kParam1FieldNumber = 3;
  ::google::protobuf::int32 param1() const;
  void set_param1(::google::protobuf::int32 value);

  // optional int32 param2 = 4;
  bool has_param2() const;
  void clear_param2();
  static const int kParam2FieldNumber = 4;
  ::google::protobuf::int32 param2() const;
  void set_param2(::google::protobuf::int32 value);

  // optional int32 param3 = 5;
  bool has_param3() const;
  void clear_param3();
  static const int kParam3FieldNumber = 5;
  ::google::protobuf::int32 param3() const;
  void set_param3(::google::protobuf::int32 value);

  // optional int32 param4 = 6;
  bool has_param4() const;
  void clear_param4();
  static const int kParam4FieldNumber = 6;
  ::google::protobuf::int32 param4() const;
  void set_param4(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:Command.CommandToServo)
 private:
  void set_has_name();
  void clear_has_name();
  void set_has_servoid();
  void clear_has_servoid();
  void set_has_param1();
  void clear_has_param1();
  void set_has_param2();
  void clear_has_param2();
  void set_has_param3();
  void clear_has_param3();
  void set_has_param4();
  void clear_has_param4();

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::internal::ArenaStringPtr name_;
  ::google::protobuf::uint32 servoid_;
  ::google::protobuf::int32 param1_;
  ::google::protobuf::int32 param2_;
  ::google::protobuf::int32 param3_;
  ::google::protobuf::int32 param4_;
  friend struct ::protobuf_command_2eproto::TableStruct;
  friend void ::protobuf_command_2eproto::InitDefaultsCommandToServoImpl();
};
// -------------------------------------------------------------------

class ResponceFromServo : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:Command.ResponceFromServo) */ {
 public:
  ResponceFromServo();
  virtual ~ResponceFromServo();

  ResponceFromServo(const ResponceFromServo& from);

  inline ResponceFromServo& operator=(const ResponceFromServo& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  ResponceFromServo(ResponceFromServo&& from) noexcept
    : ResponceFromServo() {
    *this = ::std::move(from);
  }

  inline ResponceFromServo& operator=(ResponceFromServo&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const ResponceFromServo& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const ResponceFromServo* internal_default_instance() {
    return reinterpret_cast<const ResponceFromServo*>(
               &_ResponceFromServo_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    1;

  void Swap(ResponceFromServo* other);
  friend void swap(ResponceFromServo& a, ResponceFromServo& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline ResponceFromServo* New() const PROTOBUF_FINAL { return New(NULL); }

  ResponceFromServo* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const ResponceFromServo& from);
  void MergeFrom(const ResponceFromServo& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(ResponceFromServo* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required int32 result = 1;
  bool has_result() const;
  void clear_result();
  static const int kResultFieldNumber = 1;
  ::google::protobuf::int32 result() const;
  void set_result(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:Command.ResponceFromServo)
 private:
  void set_has_result();
  void clear_has_result();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::int32 result_;
  friend struct ::protobuf_command_2eproto::TableStruct;
  friend void ::protobuf_command_2eproto::InitDefaultsResponceFromServoImpl();
};
// -------------------------------------------------------------------

class MoveCommand : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:Command.MoveCommand) */ {
 public:
  MoveCommand();
  virtual ~MoveCommand();

  MoveCommand(const MoveCommand& from);

  inline MoveCommand& operator=(const MoveCommand& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  MoveCommand(MoveCommand&& from) noexcept
    : MoveCommand() {
    *this = ::std::move(from);
  }

  inline MoveCommand& operator=(MoveCommand&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const MoveCommand& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const MoveCommand* internal_default_instance() {
    return reinterpret_cast<const MoveCommand*>(
               &_MoveCommand_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    2;

  void Swap(MoveCommand* other);
  friend void swap(MoveCommand& a, MoveCommand& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline MoveCommand* New() const PROTOBUF_FINAL { return New(NULL); }

  MoveCommand* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const MoveCommand& from);
  void MergeFrom(const MoveCommand& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(MoveCommand* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required string command = 1;
  bool has_command() const;
  void clear_command();
  static const int kCommandFieldNumber = 1;
  const ::std::string& command() const;
  void set_command(const ::std::string& value);
  #if LANG_CXX11
  void set_command(::std::string&& value);
  #endif
  void set_command(const char* value);
  void set_command(const char* value, size_t size);
  ::std::string* mutable_command();
  ::std::string* release_command();
  void set_allocated_command(::std::string* command);

  // optional int32 steps = 2;
  bool has_steps() const;
  void clear_steps();
  static const int kStepsFieldNumber = 2;
  ::google::protobuf::int32 steps() const;
  void set_steps(::google::protobuf::int32 value);

  // optional int32 parameter = 3;
  bool has_parameter() const;
  void clear_parameter();
  static const int kParameterFieldNumber = 3;
  ::google::protobuf::int32 parameter() const;
  void set_parameter(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:Command.MoveCommand)
 private:
  void set_has_command();
  void clear_has_command();
  void set_has_steps();
  void clear_has_steps();
  void set_has_parameter();
  void clear_has_parameter();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::internal::ArenaStringPtr command_;
  ::google::protobuf::int32 steps_;
  ::google::protobuf::int32 parameter_;
  friend struct ::protobuf_command_2eproto::TableStruct;
  friend void ::protobuf_command_2eproto::InitDefaultsMoveCommandImpl();
};
// -------------------------------------------------------------------

class LegMoveCommand : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:Command.LegMoveCommand) */ {
 public:
  LegMoveCommand();
  virtual ~LegMoveCommand();

  LegMoveCommand(const LegMoveCommand& from);

  inline LegMoveCommand& operator=(const LegMoveCommand& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  LegMoveCommand(LegMoveCommand&& from) noexcept
    : LegMoveCommand() {
    *this = ::std::move(from);
  }

  inline LegMoveCommand& operator=(LegMoveCommand&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const LegMoveCommand& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const LegMoveCommand* internal_default_instance() {
    return reinterpret_cast<const LegMoveCommand*>(
               &_LegMoveCommand_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    3;

  void Swap(LegMoveCommand* other);
  friend void swap(LegMoveCommand& a, LegMoveCommand& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline LegMoveCommand* New() const PROTOBUF_FINAL { return New(NULL); }

  LegMoveCommand* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const LegMoveCommand& from);
  void MergeFrom(const LegMoveCommand& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(LegMoveCommand* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required uint32 leg = 1;
  bool has_leg() const;
  void clear_leg();
  static const int kLegFieldNumber = 1;
  ::google::protobuf::uint32 leg() const;
  void set_leg(::google::protobuf::uint32 value);

  // required int32 x = 2;
  bool has_x() const;
  void clear_x();
  static const int kXFieldNumber = 2;
  ::google::protobuf::int32 x() const;
  void set_x(::google::protobuf::int32 value);

  // required int32 y = 3;
  bool has_y() const;
  void clear_y();
  static const int kYFieldNumber = 3;
  ::google::protobuf::int32 y() const;
  void set_y(::google::protobuf::int32 value);

  // required int32 z = 4;
  bool has_z() const;
  void clear_z();
  static const int kZFieldNumber = 4;
  ::google::protobuf::int32 z() const;
  void set_z(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:Command.LegMoveCommand)
 private:
  void set_has_leg();
  void clear_has_leg();
  void set_has_x();
  void clear_has_x();
  void set_has_y();
  void clear_has_y();
  void set_has_z();
  void clear_has_z();

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::uint32 leg_;
  ::google::protobuf::int32 x_;
  ::google::protobuf::int32 y_;
  ::google::protobuf::int32 z_;
  friend struct ::protobuf_command_2eproto::TableStruct;
  friend void ::protobuf_command_2eproto::InitDefaultsLegMoveCommandImpl();
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// CommandToServo

// required string name = 1;
inline bool CommandToServo::has_name() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void CommandToServo::set_has_name() {
  _has_bits_[0] |= 0x00000001u;
}
inline void CommandToServo::clear_has_name() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void CommandToServo::clear_name() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_name();
}
inline const ::std::string& CommandToServo::name() const {
  // @@protoc_insertion_point(field_get:Command.CommandToServo.name)
  return name_.GetNoArena();
}
inline void CommandToServo::set_name(const ::std::string& value) {
  set_has_name();
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:Command.CommandToServo.name)
}
#if LANG_CXX11
inline void CommandToServo::set_name(::std::string&& value) {
  set_has_name();
  name_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:Command.CommandToServo.name)
}
#endif
inline void CommandToServo::set_name(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_name();
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:Command.CommandToServo.name)
}
inline void CommandToServo::set_name(const char* value, size_t size) {
  set_has_name();
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:Command.CommandToServo.name)
}
inline ::std::string* CommandToServo::mutable_name() {
  set_has_name();
  // @@protoc_insertion_point(field_mutable:Command.CommandToServo.name)
  return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* CommandToServo::release_name() {
  // @@protoc_insertion_point(field_release:Command.CommandToServo.name)
  clear_has_name();
  return name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void CommandToServo::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    set_has_name();
  } else {
    clear_has_name();
  }
  name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:Command.CommandToServo.name)
}

// required uint32 servoId = 2;
inline bool CommandToServo::has_servoid() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void CommandToServo::set_has_servoid() {
  _has_bits_[0] |= 0x00000002u;
}
inline void CommandToServo::clear_has_servoid() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void CommandToServo::clear_servoid() {
  servoid_ = 0u;
  clear_has_servoid();
}
inline ::google::protobuf::uint32 CommandToServo::servoid() const {
  // @@protoc_insertion_point(field_get:Command.CommandToServo.servoId)
  return servoid_;
}
inline void CommandToServo::set_servoid(::google::protobuf::uint32 value) {
  set_has_servoid();
  servoid_ = value;
  // @@protoc_insertion_point(field_set:Command.CommandToServo.servoId)
}

// optional int32 param1 = 3;
inline bool CommandToServo::has_param1() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void CommandToServo::set_has_param1() {
  _has_bits_[0] |= 0x00000004u;
}
inline void CommandToServo::clear_has_param1() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void CommandToServo::clear_param1() {
  param1_ = 0;
  clear_has_param1();
}
inline ::google::protobuf::int32 CommandToServo::param1() const {
  // @@protoc_insertion_point(field_get:Command.CommandToServo.param1)
  return param1_;
}
inline void CommandToServo::set_param1(::google::protobuf::int32 value) {
  set_has_param1();
  param1_ = value;
  // @@protoc_insertion_point(field_set:Command.CommandToServo.param1)
}

// optional int32 param2 = 4;
inline bool CommandToServo::has_param2() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void CommandToServo::set_has_param2() {
  _has_bits_[0] |= 0x00000008u;
}
inline void CommandToServo::clear_has_param2() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void CommandToServo::clear_param2() {
  param2_ = 0;
  clear_has_param2();
}
inline ::google::protobuf::int32 CommandToServo::param2() const {
  // @@protoc_insertion_point(field_get:Command.CommandToServo.param2)
  return param2_;
}
inline void CommandToServo::set_param2(::google::protobuf::int32 value) {
  set_has_param2();
  param2_ = value;
  // @@protoc_insertion_point(field_set:Command.CommandToServo.param2)
}

// optional int32 param3 = 5;
inline bool CommandToServo::has_param3() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void CommandToServo::set_has_param3() {
  _has_bits_[0] |= 0x00000010u;
}
inline void CommandToServo::clear_has_param3() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void CommandToServo::clear_param3() {
  param3_ = 0;
  clear_has_param3();
}
inline ::google::protobuf::int32 CommandToServo::param3() const {
  // @@protoc_insertion_point(field_get:Command.CommandToServo.param3)
  return param3_;
}
inline void CommandToServo::set_param3(::google::protobuf::int32 value) {
  set_has_param3();
  param3_ = value;
  // @@protoc_insertion_point(field_set:Command.CommandToServo.param3)
}

// optional int32 param4 = 6;
inline bool CommandToServo::has_param4() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void CommandToServo::set_has_param4() {
  _has_bits_[0] |= 0x00000020u;
}
inline void CommandToServo::clear_has_param4() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void CommandToServo::clear_param4() {
  param4_ = 0;
  clear_has_param4();
}
inline ::google::protobuf::int32 CommandToServo::param4() const {
  // @@protoc_insertion_point(field_get:Command.CommandToServo.param4)
  return param4_;
}
inline void CommandToServo::set_param4(::google::protobuf::int32 value) {
  set_has_param4();
  param4_ = value;
  // @@protoc_insertion_point(field_set:Command.CommandToServo.param4)
}

// -------------------------------------------------------------------

// ResponceFromServo

// required int32 result = 1;
inline bool ResponceFromServo::has_result() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void ResponceFromServo::set_has_result() {
  _has_bits_[0] |= 0x00000001u;
}
inline void ResponceFromServo::clear_has_result() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void ResponceFromServo::clear_result() {
  result_ = 0;
  clear_has_result();
}
inline ::google::protobuf::int32 ResponceFromServo::result() const {
  // @@protoc_insertion_point(field_get:Command.ResponceFromServo.result)
  return result_;
}
inline void ResponceFromServo::set_result(::google::protobuf::int32 value) {
  set_has_result();
  result_ = value;
  // @@protoc_insertion_point(field_set:Command.ResponceFromServo.result)
}

// -------------------------------------------------------------------

// MoveCommand

// required string command = 1;
inline bool MoveCommand::has_command() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void MoveCommand::set_has_command() {
  _has_bits_[0] |= 0x00000001u;
}
inline void MoveCommand::clear_has_command() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void MoveCommand::clear_command() {
  command_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_command();
}
inline const ::std::string& MoveCommand::command() const {
  // @@protoc_insertion_point(field_get:Command.MoveCommand.command)
  return command_.GetNoArena();
}
inline void MoveCommand::set_command(const ::std::string& value) {
  set_has_command();
  command_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:Command.MoveCommand.command)
}
#if LANG_CXX11
inline void MoveCommand::set_command(::std::string&& value) {
  set_has_command();
  command_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:Command.MoveCommand.command)
}
#endif
inline void MoveCommand::set_command(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_command();
  command_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:Command.MoveCommand.command)
}
inline void MoveCommand::set_command(const char* value, size_t size) {
  set_has_command();
  command_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:Command.MoveCommand.command)
}
inline ::std::string* MoveCommand::mutable_command() {
  set_has_command();
  // @@protoc_insertion_point(field_mutable:Command.MoveCommand.command)
  return command_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* MoveCommand::release_command() {
  // @@protoc_insertion_point(field_release:Command.MoveCommand.command)
  clear_has_command();
  return command_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void MoveCommand::set_allocated_command(::std::string* command) {
  if (command != NULL) {
    set_has_command();
  } else {
    clear_has_command();
  }
  command_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), command);
  // @@protoc_insertion_point(field_set_allocated:Command.MoveCommand.command)
}

// optional int32 steps = 2;
inline bool MoveCommand::has_steps() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void MoveCommand::set_has_steps() {
  _has_bits_[0] |= 0x00000002u;
}
inline void MoveCommand::clear_has_steps() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void MoveCommand::clear_steps() {
  steps_ = 0;
  clear_has_steps();
}
inline ::google::protobuf::int32 MoveCommand::steps() const {
  // @@protoc_insertion_point(field_get:Command.MoveCommand.steps)
  return steps_;
}
inline void MoveCommand::set_steps(::google::protobuf::int32 value) {
  set_has_steps();
  steps_ = value;
  // @@protoc_insertion_point(field_set:Command.MoveCommand.steps)
}

// optional int32 parameter = 3;
inline bool MoveCommand::has_parameter() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void MoveCommand::set_has_parameter() {
  _has_bits_[0] |= 0x00000004u;
}
inline void MoveCommand::clear_has_parameter() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void MoveCommand::clear_parameter() {
  parameter_ = 0;
  clear_has_parameter();
}
inline ::google::protobuf::int32 MoveCommand::parameter() const {
  // @@protoc_insertion_point(field_get:Command.MoveCommand.parameter)
  return parameter_;
}
inline void MoveCommand::set_parameter(::google::protobuf::int32 value) {
  set_has_parameter();
  parameter_ = value;
  // @@protoc_insertion_point(field_set:Command.MoveCommand.parameter)
}

// -------------------------------------------------------------------

// LegMoveCommand

// required uint32 leg = 1;
inline bool LegMoveCommand::has_leg() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void LegMoveCommand::set_has_leg() {
  _has_bits_[0] |= 0x00000001u;
}
inline void LegMoveCommand::clear_has_leg() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void LegMoveCommand::clear_leg() {
  leg_ = 0u;
  clear_has_leg();
}
inline ::google::protobuf::uint32 LegMoveCommand::leg() const {
  // @@protoc_insertion_point(field_get:Command.LegMoveCommand.leg)
  return leg_;
}
inline void LegMoveCommand::set_leg(::google::protobuf::uint32 value) {
  set_has_leg();
  leg_ = value;
  // @@protoc_insertion_point(field_set:Command.LegMoveCommand.leg)
}

// required int32 x = 2;
inline bool LegMoveCommand::has_x() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void LegMoveCommand::set_has_x() {
  _has_bits_[0] |= 0x00000002u;
}
inline void LegMoveCommand::clear_has_x() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void LegMoveCommand::clear_x() {
  x_ = 0;
  clear_has_x();
}
inline ::google::protobuf::int32 LegMoveCommand::x() const {
  // @@protoc_insertion_point(field_get:Command.LegMoveCommand.x)
  return x_;
}
inline void LegMoveCommand::set_x(::google::protobuf::int32 value) {
  set_has_x();
  x_ = value;
  // @@protoc_insertion_point(field_set:Command.LegMoveCommand.x)
}

// required int32 y = 3;
inline bool LegMoveCommand::has_y() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void LegMoveCommand::set_has_y() {
  _has_bits_[0] |= 0x00000004u;
}
inline void LegMoveCommand::clear_has_y() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void LegMoveCommand::clear_y() {
  y_ = 0;
  clear_has_y();
}
inline ::google::protobuf::int32 LegMoveCommand::y() const {
  // @@protoc_insertion_point(field_get:Command.LegMoveCommand.y)
  return y_;
}
inline void LegMoveCommand::set_y(::google::protobuf::int32 value) {
  set_has_y();
  y_ = value;
  // @@protoc_insertion_point(field_set:Command.LegMoveCommand.y)
}

// required int32 z = 4;
inline bool LegMoveCommand::has_z() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void LegMoveCommand::set_has_z() {
  _has_bits_[0] |= 0x00000008u;
}
inline void LegMoveCommand::clear_has_z() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void LegMoveCommand::clear_z() {
  z_ = 0;
  clear_has_z();
}
inline ::google::protobuf::int32 LegMoveCommand::z() const {
  // @@protoc_insertion_point(field_get:Command.LegMoveCommand.z)
  return z_;
}
inline void LegMoveCommand::set_z(::google::protobuf::int32 value) {
  set_has_z();
  z_ = value;
  // @@protoc_insertion_point(field_set:Command.LegMoveCommand.z)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace Command

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_command_2eproto__INCLUDED
