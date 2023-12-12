// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: User.proto

#include "User.pb.h"

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

namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = _pb::internal;

namespace tutorial {
    PROTOBUF_CONSTEXPR User::User(
        ::_pbi::ConstantInitialized) : _impl_{
            /*decltype(_impl_._has_bits_)*/{}
          , /*decltype(_impl_._cached_size_)*/{}
          , /*decltype(_impl_.replay_)*/{}
          , /*decltype(_impl_.id_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
          , /*decltype(_impl_.pw_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
          , /*decltype(_impl_.nick_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
          , /*decltype(_impl_.uid_)*/0
          , /*decltype(_impl_.gamenum_)*/0
          , /*decltype(_impl_.winnum_)*/0 } {}
    struct UserDefaultTypeInternal {
        PROTOBUF_CONSTEXPR UserDefaultTypeInternal()
            : _instance(::_pbi::ConstantInitialized{}) {}
        ~UserDefaultTypeInternal() {}
        union {
            User _instance;
        };
    };
    PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 UserDefaultTypeInternal _User_default_instance_;
}  // namespace tutorial
static ::_pb::Metadata file_level_metadata_User_2eproto[1];
static constexpr ::_pb::EnumDescriptor const** file_level_enum_descriptors_User_2eproto = nullptr;
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_User_2eproto = nullptr;

const uint32_t TableStruct_User_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::tutorial::User, _impl_._has_bits_),
  PROTOBUF_FIELD_OFFSET(::tutorial::User, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::tutorial::User, _impl_.uid_),
  PROTOBUF_FIELD_OFFSET(::tutorial::User, _impl_.id_),
  PROTOBUF_FIELD_OFFSET(::tutorial::User, _impl_.pw_),
  PROTOBUF_FIELD_OFFSET(::tutorial::User, _impl_.nick_),
  PROTOBUF_FIELD_OFFSET(::tutorial::User, _impl_.gamenum_),
  PROTOBUF_FIELD_OFFSET(::tutorial::User, _impl_.winnum_),
  PROTOBUF_FIELD_OFFSET(::tutorial::User, _impl_.replay_),
  3,
  0,
  1,
  2,
  4,
  5,
  ~0u,
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 13, -1, sizeof(::tutorial::User)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::tutorial::_User_default_instance_._instance,
};

const char descriptor_table_protodef_User_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
"\n\nUser.proto\022\010tutorial\"j\n\004User\022\013\n\003uid\030\001 "
"\002(\005\022\n\n\002id\030\002 \002(\t\022\n\n\002pw\030\003 \002(\t\022\014\n\004nick\030\004 \001("
"\t\022\017\n\007gameNum\030\005 \002(\005\022\016\n\006winNum\030\006 \002(\005\022\016\n\006re"
"play\030\007 \003(\t"
;
static ::_pbi::once_flag descriptor_table_User_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_User_2eproto = {
    false, false, 130, descriptor_table_protodef_User_2eproto,
    "User.proto",
    &descriptor_table_User_2eproto_once, nullptr, 0, 1,
    schemas, file_default_instances, TableStruct_User_2eproto::offsets,
    file_level_metadata_User_2eproto, file_level_enum_descriptors_User_2eproto,
    file_level_service_descriptors_User_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_User_2eproto_getter() {
    return &descriptor_table_User_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_User_2eproto(&descriptor_table_User_2eproto);
namespace tutorial {

    // ===================================================================

    class User::_Internal {
    public:
        using HasBits = decltype(std::declval<User>()._impl_._has_bits_);
        static void set_has_uid(HasBits* has_bits) {
            (*has_bits)[0] |= 8u;
        }
        static void set_has_id(HasBits* has_bits) {
            (*has_bits)[0] |= 1u;
        }
        static void set_has_pw(HasBits* has_bits) {
            (*has_bits)[0] |= 2u;
        }
        static void set_has_nick(HasBits* has_bits) {
            (*has_bits)[0] |= 4u;
        }
        static void set_has_gamenum(HasBits* has_bits) {
            (*has_bits)[0] |= 16u;
        }
        static void set_has_winnum(HasBits* has_bits) {
            (*has_bits)[0] |= 32u;
        }
        static bool MissingRequiredFields(const HasBits& has_bits) {
            return ((has_bits[0] & 0x0000003b) ^ 0x0000003b) != 0;
        }
    };

    User::User(::PROTOBUF_NAMESPACE_ID::Arena* arena,
        bool is_message_owned)
        : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
        SharedCtor(arena, is_message_owned);
        // @@protoc_insertion_point(arena_constructor:tutorial.User)
    }
    User::User(const User& from)
        : ::PROTOBUF_NAMESPACE_ID::Message() {
        User* const _this = this; (void)_this;
        new (&_impl_) Impl_{
            decltype(_impl_._has_bits_){from._impl_._has_bits_}
          , /*decltype(_impl_._cached_size_)*/{}
          , decltype(_impl_.replay_){from._impl_.replay_}
          , decltype(_impl_.id_){}
          , decltype(_impl_.pw_){}
          , decltype(_impl_.nick_){}
          , decltype(_impl_.uid_){}
          , decltype(_impl_.gamenum_){}
          , decltype(_impl_.winnum_){} };

        _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
        _impl_.id_.InitDefault();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        _impl_.id_.Set("", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (from._internal_has_id()) {
            _this->_impl_.id_.Set(from._internal_id(),
                _this->GetArenaForAllocation());
        }
        _impl_.pw_.InitDefault();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        _impl_.pw_.Set("", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (from._internal_has_pw()) {
            _this->_impl_.pw_.Set(from._internal_pw(),
                _this->GetArenaForAllocation());
        }
        _impl_.nick_.InitDefault();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        _impl_.nick_.Set("", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (from._internal_has_nick()) {
            _this->_impl_.nick_.Set(from._internal_nick(),
                _this->GetArenaForAllocation());
        }
        ::memcpy(&_impl_.uid_, &from._impl_.uid_,
            static_cast<size_t>(reinterpret_cast<char*>(&_impl_.winnum_) -
                reinterpret_cast<char*>(&_impl_.uid_)) + sizeof(_impl_.winnum_));
        // @@protoc_insertion_point(copy_constructor:tutorial.User)
    }

    inline void User::SharedCtor(
        ::_pb::Arena* arena, bool is_message_owned) {
        (void)arena;
        (void)is_message_owned;
        new (&_impl_) Impl_{
            decltype(_impl_._has_bits_){}
          , /*decltype(_impl_._cached_size_)*/{}
          , decltype(_impl_.replay_){arena}
          , decltype(_impl_.id_){}
          , decltype(_impl_.pw_){}
          , decltype(_impl_.nick_){}
          , decltype(_impl_.uid_){0}
          , decltype(_impl_.gamenum_){0}
          , decltype(_impl_.winnum_){0}
        };
        _impl_.id_.InitDefault();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        _impl_.id_.Set("", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
        _impl_.pw_.InitDefault();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        _impl_.pw_.Set("", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
        _impl_.nick_.InitDefault();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        _impl_.nick_.Set("", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
    }

    User::~User() {
        // @@protoc_insertion_point(destructor:tutorial.User)
        if (auto* arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
            (void)arena;
            return;
        }
        SharedDtor();
    }

    inline void User::SharedDtor() {
        GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
        _impl_.replay_.~RepeatedPtrField();
        _impl_.id_.Destroy();
        _impl_.pw_.Destroy();
        _impl_.nick_.Destroy();
    }

    void User::SetCachedSize(int size) const {
        _impl_._cached_size_.Set(size);
    }

    void User::Clear() {
        // @@protoc_insertion_point(message_clear_start:tutorial.User)
        uint32_t cached_has_bits = 0;
        // Prevent compiler warnings about cached_has_bits being unused
        (void)cached_has_bits;

        _impl_.replay_.Clear();
        cached_has_bits = _impl_._has_bits_[0];
        if (cached_has_bits & 0x00000007u) {
            if (cached_has_bits & 0x00000001u) {
                _impl_.id_.ClearNonDefaultToEmpty();
            }
            if (cached_has_bits & 0x00000002u) {
                _impl_.pw_.ClearNonDefaultToEmpty();
            }
            if (cached_has_bits & 0x00000004u) {
                _impl_.nick_.ClearNonDefaultToEmpty();
            }
        }
        if (cached_has_bits & 0x00000038u) {
            ::memset(&_impl_.uid_, 0, static_cast<size_t>(
                reinterpret_cast<char*>(&_impl_.winnum_) -
                reinterpret_cast<char*>(&_impl_.uid_)) + sizeof(_impl_.winnum_));
        }
        _impl_._has_bits_.Clear();
        _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
    }

    const char* User::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
        _Internal::HasBits has_bits{};
        while (!ctx->Done(&ptr)) {
            uint32_t tag;
            ptr = ::_pbi::ReadTag(ptr, &tag);
            switch (tag >> 3) {
                // required int32 uid = 1;
            case 1:
                if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
                    _Internal::set_has_uid(&has_bits);
                    _impl_.uid_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
                    CHK_(ptr);
                }
                else
                    goto handle_unusual;
                continue;
                // required string id = 2;
            case 2:
                if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
                    auto str = _internal_mutable_id();
                    ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
                    CHK_(ptr);
#ifndef NDEBUG
                    ::_pbi::VerifyUTF8(str, "tutorial.User.id");
#endif  // !NDEBUG
                }
                else
                    goto handle_unusual;
                continue;
                // required string pw = 3;
            case 3:
                if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 26)) {
                    auto str = _internal_mutable_pw();
                    ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
                    CHK_(ptr);
#ifndef NDEBUG
                    ::_pbi::VerifyUTF8(str, "tutorial.User.pw");
#endif  // !NDEBUG
                }
                else
                    goto handle_unusual;
                continue;
                // optional string nick = 4;
            case 4:
                if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 34)) {
                    auto str = _internal_mutable_nick();
                    ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
                    CHK_(ptr);
#ifndef NDEBUG
                    ::_pbi::VerifyUTF8(str, "tutorial.User.nick");
#endif  // !NDEBUG
                }
                else
                    goto handle_unusual;
                continue;
                // required int32 gameNum = 5;
            case 5:
                if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 40)) {
                    _Internal::set_has_gamenum(&has_bits);
                    _impl_.gamenum_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
                    CHK_(ptr);
                }
                else
                    goto handle_unusual;
                continue;
                // required int32 winNum = 6;
            case 6:
                if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 48)) {
                    _Internal::set_has_winnum(&has_bits);
                    _impl_.winnum_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
                    CHK_(ptr);
                }
                else
                    goto handle_unusual;
                continue;
                // repeated string replay = 7;
            case 7:
                if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 58)) {
                    ptr -= 1;
                    do {
                        ptr += 1;
                        auto str = _internal_add_replay();
                        ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
                        CHK_(ptr);
#ifndef NDEBUG
                        ::_pbi::VerifyUTF8(str, "tutorial.User.replay");
#endif  // !NDEBUG
                        if (!ctx->DataAvailable(ptr)) break;
                    } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<58>(ptr));
                }
                else
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
        _impl_._has_bits_.Or(has_bits);
        return ptr;
    failure:
        ptr = nullptr;
        goto message_done;
#undef CHK_
    }

    uint8_t* User::_InternalSerialize(
        uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
        // @@protoc_insertion_point(serialize_to_array_start:tutorial.User)
        uint32_t cached_has_bits = 0;
        (void)cached_has_bits;

        cached_has_bits = _impl_._has_bits_[0];
        // required int32 uid = 1;
        if (cached_has_bits & 0x00000008u) {
            target = stream->EnsureSpace(target);
            target = ::_pbi::WireFormatLite::WriteInt32ToArray(1, this->_internal_uid(), target);
        }

        // required string id = 2;
        if (cached_has_bits & 0x00000001u) {
            ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
                this->_internal_id().data(), static_cast<int>(this->_internal_id().length()),
                ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
                "tutorial.User.id");
            target = stream->WriteStringMaybeAliased(
                2, this->_internal_id(), target);
        }

        // required string pw = 3;
        if (cached_has_bits & 0x00000002u) {
            ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
                this->_internal_pw().data(), static_cast<int>(this->_internal_pw().length()),
                ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
                "tutorial.User.pw");
            target = stream->WriteStringMaybeAliased(
                3, this->_internal_pw(), target);
        }

        // optional string nick = 4;
        if (cached_has_bits & 0x00000004u) {
            ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
                this->_internal_nick().data(), static_cast<int>(this->_internal_nick().length()),
                ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
                "tutorial.User.nick");
            target = stream->WriteStringMaybeAliased(
                4, this->_internal_nick(), target);
        }

        // required int32 gameNum = 5;
        if (cached_has_bits & 0x00000010u) {
            target = stream->EnsureSpace(target);
            target = ::_pbi::WireFormatLite::WriteInt32ToArray(5, this->_internal_gamenum(), target);
        }

        // required int32 winNum = 6;
        if (cached_has_bits & 0x00000020u) {
            target = stream->EnsureSpace(target);
            target = ::_pbi::WireFormatLite::WriteInt32ToArray(6, this->_internal_winnum(), target);
        }

        // repeated string replay = 7;
        for (int i = 0, n = this->_internal_replay_size(); i < n; i++) {
            const auto& s = this->_internal_replay(i);
            ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
                s.data(), static_cast<int>(s.length()),
                ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
                "tutorial.User.replay");
            target = stream->WriteString(7, s, target);
        }

        if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
            target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
                _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
        }
        // @@protoc_insertion_point(serialize_to_array_end:tutorial.User)
        return target;
    }

    size_t User::RequiredFieldsByteSizeFallback() const {
        // @@protoc_insertion_point(required_fields_byte_size_fallback_start:tutorial.User)
        size_t total_size = 0;

        if (_internal_has_id()) {
            // required string id = 2;
            total_size += 1 +
                ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
                    this->_internal_id());
        }

        if (_internal_has_pw()) {
            // required string pw = 3;
            total_size += 1 +
                ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
                    this->_internal_pw());
        }

        if (_internal_has_uid()) {
            // required int32 uid = 1;
            total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_uid());
        }

        if (_internal_has_gamenum()) {
            // required int32 gameNum = 5;
            total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_gamenum());
        }

        if (_internal_has_winnum()) {
            // required int32 winNum = 6;
            total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_winnum());
        }

        return total_size;
    }
    size_t User::ByteSizeLong() const {
        // @@protoc_insertion_point(message_byte_size_start:tutorial.User)
        size_t total_size = 0;

        if (((_impl_._has_bits_[0] & 0x0000003b) ^ 0x0000003b) == 0) {  // All required fields are present.
            // required string id = 2;
            total_size += 1 +
                ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
                    this->_internal_id());

            // required string pw = 3;
            total_size += 1 +
                ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
                    this->_internal_pw());

            // required int32 uid = 1;
            total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_uid());

            // required int32 gameNum = 5;
            total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_gamenum());

            // required int32 winNum = 6;
            total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_winnum());

        }
        else {
            total_size += RequiredFieldsByteSizeFallback();
        }
        uint32_t cached_has_bits = 0;
        // Prevent compiler warnings about cached_has_bits being unused
        (void)cached_has_bits;

        // repeated string replay = 7;
        total_size += 1 *
            ::PROTOBUF_NAMESPACE_ID::internal::FromIntSize(_impl_.replay_.size());
        for (int i = 0, n = _impl_.replay_.size(); i < n; i++) {
            total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
                _impl_.replay_.Get(i));
        }

        // optional string nick = 4;
        cached_has_bits = _impl_._has_bits_[0];
        if (cached_has_bits & 0x00000004u) {
            total_size += 1 +
                ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
                    this->_internal_nick());
        }

        return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
    }

    const ::PROTOBUF_NAMESPACE_ID::Message::ClassData User::_class_data_ = {
        ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
        User::MergeImpl
    };
    const ::PROTOBUF_NAMESPACE_ID::Message::ClassData* User::GetClassData() const { return &_class_data_; }


    void User::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
        auto* const _this = static_cast<User*>(&to_msg);
        auto& from = static_cast<const User&>(from_msg);
        // @@protoc_insertion_point(class_specific_merge_from_start:tutorial.User)
        GOOGLE_DCHECK_NE(&from, _this);
        uint32_t cached_has_bits = 0;
        (void)cached_has_bits;

        _this->_impl_.replay_.MergeFrom(from._impl_.replay_);
        cached_has_bits = from._impl_._has_bits_[0];
        if (cached_has_bits & 0x0000003fu) {
            if (cached_has_bits & 0x00000001u) {
                _this->_internal_set_id(from._internal_id());
            }
            if (cached_has_bits & 0x00000002u) {
                _this->_internal_set_pw(from._internal_pw());
            }
            if (cached_has_bits & 0x00000004u) {
                _this->_internal_set_nick(from._internal_nick());
            }
            if (cached_has_bits & 0x00000008u) {
                _this->_impl_.uid_ = from._impl_.uid_;
            }
            if (cached_has_bits & 0x00000010u) {
                _this->_impl_.gamenum_ = from._impl_.gamenum_;
            }
            if (cached_has_bits & 0x00000020u) {
                _this->_impl_.winnum_ = from._impl_.winnum_;
            }
            _this->_impl_._has_bits_[0] |= cached_has_bits;
        }
        _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
    }

    void User::CopyFrom(const User& from) {
        // @@protoc_insertion_point(class_specific_copy_from_start:tutorial.User)
        if (&from == this) return;
        Clear();
        MergeFrom(from);
    }

    bool User::IsInitialized() const {
        if (_Internal::MissingRequiredFields(_impl_._has_bits_)) return false;
        return true;
    }

    void User::InternalSwap(User* other) {
        using std::swap;
        auto* lhs_arena = GetArenaForAllocation();
        auto* rhs_arena = other->GetArenaForAllocation();
        _internal_metadata_.InternalSwap(&other->_internal_metadata_);
        swap(_impl_._has_bits_[0], other->_impl_._has_bits_[0]);
        _impl_.replay_.InternalSwap(&other->_impl_.replay_);
        ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
            &_impl_.id_, lhs_arena,
            &other->_impl_.id_, rhs_arena
        );
        ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
            &_impl_.pw_, lhs_arena,
            &other->_impl_.pw_, rhs_arena
        );
        ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
            &_impl_.nick_, lhs_arena,
            &other->_impl_.nick_, rhs_arena
        );
        ::PROTOBUF_NAMESPACE_ID::internal::memswap<
            PROTOBUF_FIELD_OFFSET(User, _impl_.winnum_)
            + sizeof(User::_impl_.winnum_)
            - PROTOBUF_FIELD_OFFSET(User, _impl_.uid_)>(
                reinterpret_cast<char*>(&_impl_.uid_),
                reinterpret_cast<char*>(&other->_impl_.uid_));
    }

    ::PROTOBUF_NAMESPACE_ID::Metadata User::GetMetadata() const {
        return ::_pbi::AssignDescriptors(
            &descriptor_table_User_2eproto_getter, &descriptor_table_User_2eproto_once,
            file_level_metadata_User_2eproto[0]);
    }

    // @@protoc_insertion_point(namespace_scope)
}  // namespace tutorial
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE::tutorial::User*
Arena::CreateMaybeMessage< ::tutorial::User >(Arena* arena) {
    return Arena::CreateMessageInternal< ::tutorial::User >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
