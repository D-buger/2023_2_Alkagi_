// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: User.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_User_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_User_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3021000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3021012 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_User_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
    class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_User_2eproto {
    static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_User_2eproto;
namespace tutorial {
    class User;
    struct UserDefaultTypeInternal;
    extern UserDefaultTypeInternal _User_default_instance_;
}  // namespace tutorial
PROTOBUF_NAMESPACE_OPEN
template<> ::tutorial::User* Arena::CreateMaybeMessage<::tutorial::User>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace tutorial {

    // ===================================================================

    class User final :
        public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:tutorial.User) */ {
    public:
        inline User() : User(nullptr) {}
        ~User() override;
        explicit PROTOBUF_CONSTEXPR User(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

        User(const User& from);
        User(User&& from) noexcept
            : User() {
            *this = ::std::move(from);
        }

        inline User& operator=(const User& from) {
            CopyFrom(from);
            return *this;
        }
        inline User& operator=(User&& from) noexcept {
            if (this == &from) return *this;
            if (GetOwningArena() == from.GetOwningArena()
#ifdef PROTOBUF_FORCE_COPY_IN_MOVE
                && GetOwningArena() != nullptr
#endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
                ) {
                InternalSwap(&from);
            }
            else {
                CopyFrom(from);
            }
            return *this;
        }

        inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
            return _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance);
        }
        inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
            return _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
        }

        static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
            return GetDescriptor();
        }
        static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
            return default_instance().GetMetadata().descriptor;
        }
        static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
            return default_instance().GetMetadata().reflection;
        }
        static const User& default_instance() {
            return *internal_default_instance();
        }
        static inline const User* internal_default_instance() {
            return reinterpret_cast<const User*>(
                &_User_default_instance_);
        }
        static constexpr int kIndexInFileMessages =
            0;

        friend void swap(User& a, User& b) {
            a.Swap(&b);
        }
        inline void Swap(User* other) {
            if (other == this) return;
#ifdef PROTOBUF_FORCE_COPY_IN_SWAP
            if (GetOwningArena() != nullptr &&
                GetOwningArena() == other->GetOwningArena()) {
#else  // PROTOBUF_FORCE_COPY_IN_SWAP
            if (GetOwningArena() == other->GetOwningArena()) {
#endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
                InternalSwap(other);
            }
            else {
                ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
            }
            }
        void UnsafeArenaSwap(User * other) {
            if (other == this) return;
            GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
            InternalSwap(other);
        }

        // implements Message ----------------------------------------------

        User* New(::PROTOBUF_NAMESPACE_ID::Arena * arena = nullptr) const final {
            return CreateMaybeMessage<User>(arena);
        }
        using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
        void CopyFrom(const User & from);
        using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
        void MergeFrom(const User & from) {
            User::MergeImpl(*this, from);
        }
    private:
        static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message & to_msg, const ::PROTOBUF_NAMESPACE_ID::Message & from_msg);
    public:
        PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
        bool IsInitialized() const final;

        size_t ByteSizeLong() const final;
        const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext * ctx) final;
        uint8_t* _InternalSerialize(
            uint8_t * target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream * stream) const final;
        int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

    private:
        void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena * arena, bool is_message_owned);
        void SharedDtor();
        void SetCachedSize(int size) const final;
        void InternalSwap(User * other);

    private:
        friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
        static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
            return "tutorial.User";
        }
    protected:
        explicit User(::PROTOBUF_NAMESPACE_ID::Arena * arena,
            bool is_message_owned = false);
    public:

        static const ClassData _class_data_;
        const ::PROTOBUF_NAMESPACE_ID::Message::ClassData* GetClassData() const final;

        ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

        // nested types ----------------------------------------------------

        // accessors -------------------------------------------------------

        enum : int {
            kReplayFieldNumber = 7,
            kIdFieldNumber = 2,
            kPwFieldNumber = 3,
            kNickFieldNumber = 4,
            kUidFieldNumber = 1,
            kGameNumFieldNumber = 5,
            kWinNumFieldNumber = 6,
        };
        // repeated string replay = 7;
        int replay_size() const;
    private:
        int _internal_replay_size() const;
    public:
        void clear_replay();
        const std::string& replay(int index) const;
        std::string* mutable_replay(int index);
        void set_replay(int index, const std::string & value);
        void set_replay(int index, std::string && value);
        void set_replay(int index, const char* value);
        void set_replay(int index, const char* value, size_t size);
        std::string* add_replay();
        void add_replay(const std::string & value);
        void add_replay(std::string && value);
        void add_replay(const char* value);
        void add_replay(const char* value, size_t size);
        const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>& replay() const;
        ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>* mutable_replay();
    private:
        const std::string& _internal_replay(int index) const;
        std::string* _internal_add_replay();
    public:

        // required string id = 2;
        bool has_id() const;
    private:
        bool _internal_has_id() const;
    public:
        void clear_id();
        const std::string& id() const;
        template <typename ArgT0 = const std::string&, typename... ArgT>
        void set_id(ArgT0 && arg0, ArgT... args);
        std::string* mutable_id();
        PROTOBUF_NODISCARD std::string* release_id();
        void set_allocated_id(std::string * id);
    private:
        const std::string& _internal_id() const;
        inline PROTOBUF_ALWAYS_INLINE void _internal_set_id(const std::string & value);
        std::string* _internal_mutable_id();
    public:

        // required string pw = 3;
        bool has_pw() const;
    private:
        bool _internal_has_pw() const;
    public:
        void clear_pw();
        const std::string& pw() const;
        template <typename ArgT0 = const std::string&, typename... ArgT>
        void set_pw(ArgT0 && arg0, ArgT... args);
        std::string* mutable_pw();
        PROTOBUF_NODISCARD std::string* release_pw();
        void set_allocated_pw(std::string * pw);
    private:
        const std::string& _internal_pw() const;
        inline PROTOBUF_ALWAYS_INLINE void _internal_set_pw(const std::string & value);
        std::string* _internal_mutable_pw();
    public:

        // optional string nick = 4;
        bool has_nick() const;
    private:
        bool _internal_has_nick() const;
    public:
        void clear_nick();
        const std::string& nick() const;
        template <typename ArgT0 = const std::string&, typename... ArgT>
        void set_nick(ArgT0 && arg0, ArgT... args);
        std::string* mutable_nick();
        PROTOBUF_NODISCARD std::string* release_nick();
        void set_allocated_nick(std::string * nick);
    private:
        const std::string& _internal_nick() const;
        inline PROTOBUF_ALWAYS_INLINE void _internal_set_nick(const std::string & value);
        std::string* _internal_mutable_nick();
    public:

        // required int32 uid = 1;
        bool has_uid() const;
    private:
        bool _internal_has_uid() const;
    public:
        void clear_uid();
        int32_t uid() const;
        void set_uid(int32_t value);
    private:
        int32_t _internal_uid() const;
        void _internal_set_uid(int32_t value);
    public:

        // required int32 gameNum = 5;
        bool has_gamenum() const;
    private:
        bool _internal_has_gamenum() const;
    public:
        void clear_gamenum();
        int32_t gamenum() const;
        void set_gamenum(int32_t value);
    private:
        int32_t _internal_gamenum() const;
        void _internal_set_gamenum(int32_t value);
    public:

        // required int32 winNum = 6;
        bool has_winnum() const;
    private:
        bool _internal_has_winnum() const;
    public:
        void clear_winnum();
        int32_t winnum() const;
        void set_winnum(int32_t value);
    private:
        int32_t _internal_winnum() const;
        void _internal_set_winnum(int32_t value);
    public:

        // @@protoc_insertion_point(class_scope:tutorial.User)
    private:
        class _Internal;

        // helper for ByteSizeLong()
        size_t RequiredFieldsByteSizeFallback() const;

        template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
        typedef void InternalArenaConstructable_;
        typedef void DestructorSkippable_;
        struct Impl_ {
            ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
            mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
            ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string> replay_;
            ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr id_;
            ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr pw_;
            ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr nick_;
            int32_t uid_;
            int32_t gamenum_;
            int32_t winnum_;
        };
        union { Impl_ _impl_; };
        friend struct ::TableStruct_User_2eproto;
        };
    // ===================================================================


    // ===================================================================

#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// User

// required int32 uid = 1;
    inline bool User::_internal_has_uid() const {
        bool value = (_impl_._has_bits_[0] & 0x00000008u) != 0;
        return value;
    }
    inline bool User::has_uid() const {
        return _internal_has_uid();
    }
    inline void User::clear_uid() {
        _impl_.uid_ = 0;
        _impl_._has_bits_[0] &= ~0x00000008u;
    }
    inline int32_t User::_internal_uid() const {
        return _impl_.uid_;
    }
    inline int32_t User::uid() const {
        // @@protoc_insertion_point(field_get:tutorial.User.uid)
        return _internal_uid();
    }
    inline void User::_internal_set_uid(int32_t value) {
        _impl_._has_bits_[0] |= 0x00000008u;
        _impl_.uid_ = value;
    }
    inline void User::set_uid(int32_t value) {
        _internal_set_uid(value);
        // @@protoc_insertion_point(field_set:tutorial.User.uid)
    }

    // required string id = 2;
    inline bool User::_internal_has_id() const {
        bool value = (_impl_._has_bits_[0] & 0x00000001u) != 0;
        return value;
    }
    inline bool User::has_id() const {
        return _internal_has_id();
    }
    inline void User::clear_id() {
        _impl_.id_.ClearToEmpty();
        _impl_._has_bits_[0] &= ~0x00000001u;
    }
    inline const std::string& User::id() const {
        // @@protoc_insertion_point(field_get:tutorial.User.id)
        return _internal_id();
    }
    template <typename ArgT0, typename... ArgT>
    inline PROTOBUF_ALWAYS_INLINE
        void User::set_id(ArgT0&& arg0, ArgT... args) {
        _impl_._has_bits_[0] |= 0x00000001u;
        _impl_.id_.Set(static_cast<ArgT0&&>(arg0), args..., GetArenaForAllocation());
        // @@protoc_insertion_point(field_set:tutorial.User.id)
    }
    inline std::string* User::mutable_id() {
        std::string* _s = _internal_mutable_id();
        // @@protoc_insertion_point(field_mutable:tutorial.User.id)
        return _s;
    }
    inline const std::string& User::_internal_id() const {
        return _impl_.id_.Get();
    }
    inline void User::_internal_set_id(const std::string& value) {
        _impl_._has_bits_[0] |= 0x00000001u;
        _impl_.id_.Set(value, GetArenaForAllocation());
    }
    inline std::string* User::_internal_mutable_id() {
        _impl_._has_bits_[0] |= 0x00000001u;
        return _impl_.id_.Mutable(GetArenaForAllocation());
    }
    inline std::string* User::release_id() {
        // @@protoc_insertion_point(field_release:tutorial.User.id)
        if (!_internal_has_id()) {
            return nullptr;
        }
        _impl_._has_bits_[0] &= ~0x00000001u;
        auto* p = _impl_.id_.Release();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.id_.IsDefault()) {
            _impl_.id_.Set("", GetArenaForAllocation());
        }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
        return p;
    }
    inline void User::set_allocated_id(std::string* id) {
        if (id != nullptr) {
            _impl_._has_bits_[0] |= 0x00000001u;
        }
        else {
            _impl_._has_bits_[0] &= ~0x00000001u;
        }
        _impl_.id_.SetAllocated(id, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.id_.IsDefault()) {
            _impl_.id_.Set("", GetArenaForAllocation());
        }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
        // @@protoc_insertion_point(field_set_allocated:tutorial.User.id)
    }

    // required string pw = 3;
    inline bool User::_internal_has_pw() const {
        bool value = (_impl_._has_bits_[0] & 0x00000002u) != 0;
        return value;
    }
    inline bool User::has_pw() const {
        return _internal_has_pw();
    }
    inline void User::clear_pw() {
        _impl_.pw_.ClearToEmpty();
        _impl_._has_bits_[0] &= ~0x00000002u;
    }
    inline const std::string& User::pw() const {
        // @@protoc_insertion_point(field_get:tutorial.User.pw)
        return _internal_pw();
    }
    template <typename ArgT0, typename... ArgT>
    inline PROTOBUF_ALWAYS_INLINE
        void User::set_pw(ArgT0&& arg0, ArgT... args) {
        _impl_._has_bits_[0] |= 0x00000002u;
        _impl_.pw_.Set(static_cast<ArgT0&&>(arg0), args..., GetArenaForAllocation());
        // @@protoc_insertion_point(field_set:tutorial.User.pw)
    }
    inline std::string* User::mutable_pw() {
        std::string* _s = _internal_mutable_pw();
        // @@protoc_insertion_point(field_mutable:tutorial.User.pw)
        return _s;
    }
    inline const std::string& User::_internal_pw() const {
        return _impl_.pw_.Get();
    }
    inline void User::_internal_set_pw(const std::string& value) {
        _impl_._has_bits_[0] |= 0x00000002u;
        _impl_.pw_.Set(value, GetArenaForAllocation());
    }
    inline std::string* User::_internal_mutable_pw() {
        _impl_._has_bits_[0] |= 0x00000002u;
        return _impl_.pw_.Mutable(GetArenaForAllocation());
    }
    inline std::string* User::release_pw() {
        // @@protoc_insertion_point(field_release:tutorial.User.pw)
        if (!_internal_has_pw()) {
            return nullptr;
        }
        _impl_._has_bits_[0] &= ~0x00000002u;
        auto* p = _impl_.pw_.Release();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.pw_.IsDefault()) {
            _impl_.pw_.Set("", GetArenaForAllocation());
        }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
        return p;
    }
    inline void User::set_allocated_pw(std::string* pw) {
        if (pw != nullptr) {
            _impl_._has_bits_[0] |= 0x00000002u;
        }
        else {
            _impl_._has_bits_[0] &= ~0x00000002u;
        }
        _impl_.pw_.SetAllocated(pw, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.pw_.IsDefault()) {
            _impl_.pw_.Set("", GetArenaForAllocation());
        }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
        // @@protoc_insertion_point(field_set_allocated:tutorial.User.pw)
    }

    // optional string nick = 4;
    inline bool User::_internal_has_nick() const {
        bool value = (_impl_._has_bits_[0] & 0x00000004u) != 0;
        return value;
    }
    inline bool User::has_nick() const {
        return _internal_has_nick();
    }
    inline void User::clear_nick() {
        _impl_.nick_.ClearToEmpty();
        _impl_._has_bits_[0] &= ~0x00000004u;
    }
    inline const std::string& User::nick() const {
        // @@protoc_insertion_point(field_get:tutorial.User.nick)
        return _internal_nick();
    }
    template <typename ArgT0, typename... ArgT>
    inline PROTOBUF_ALWAYS_INLINE
        void User::set_nick(ArgT0&& arg0, ArgT... args) {
        _impl_._has_bits_[0] |= 0x00000004u;
        _impl_.nick_.Set(static_cast<ArgT0&&>(arg0), args..., GetArenaForAllocation());
        // @@protoc_insertion_point(field_set:tutorial.User.nick)
    }
    inline std::string* User::mutable_nick() {
        std::string* _s = _internal_mutable_nick();
        // @@protoc_insertion_point(field_mutable:tutorial.User.nick)
        return _s;
    }
    inline const std::string& User::_internal_nick() const {
        return _impl_.nick_.Get();
    }
    inline void User::_internal_set_nick(const std::string& value) {
        _impl_._has_bits_[0] |= 0x00000004u;
        _impl_.nick_.Set(value, GetArenaForAllocation());
    }
    inline std::string* User::_internal_mutable_nick() {
        _impl_._has_bits_[0] |= 0x00000004u;
        return _impl_.nick_.Mutable(GetArenaForAllocation());
    }
    inline std::string* User::release_nick() {
        // @@protoc_insertion_point(field_release:tutorial.User.nick)
        if (!_internal_has_nick()) {
            return nullptr;
        }
        _impl_._has_bits_[0] &= ~0x00000004u;
        auto* p = _impl_.nick_.Release();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.nick_.IsDefault()) {
            _impl_.nick_.Set("", GetArenaForAllocation());
        }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
        return p;
    }
    inline void User::set_allocated_nick(std::string* nick) {
        if (nick != nullptr) {
            _impl_._has_bits_[0] |= 0x00000004u;
        }
        else {
            _impl_._has_bits_[0] &= ~0x00000004u;
        }
        _impl_.nick_.SetAllocated(nick, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.nick_.IsDefault()) {
            _impl_.nick_.Set("", GetArenaForAllocation());
        }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
        // @@protoc_insertion_point(field_set_allocated:tutorial.User.nick)
    }

    // required int32 gameNum = 5;
    inline bool User::_internal_has_gamenum() const {
        bool value = (_impl_._has_bits_[0] & 0x00000010u) != 0;
        return value;
    }
    inline bool User::has_gamenum() const {
        return _internal_has_gamenum();
    }
    inline void User::clear_gamenum() {
        _impl_.gamenum_ = 0;
        _impl_._has_bits_[0] &= ~0x00000010u;
    }
    inline int32_t User::_internal_gamenum() const {
        return _impl_.gamenum_;
    }
    inline int32_t User::gamenum() const {
        // @@protoc_insertion_point(field_get:tutorial.User.gameNum)
        return _internal_gamenum();
    }
    inline void User::_internal_set_gamenum(int32_t value) {
        _impl_._has_bits_[0] |= 0x00000010u;
        _impl_.gamenum_ = value;
    }
    inline void User::set_gamenum(int32_t value) {
        _internal_set_gamenum(value);
        // @@protoc_insertion_point(field_set:tutorial.User.gameNum)
    }

    // required int32 winNum = 6;
    inline bool User::_internal_has_winnum() const {
        bool value = (_impl_._has_bits_[0] & 0x00000020u) != 0;
        return value;
    }
    inline bool User::has_winnum() const {
        return _internal_has_winnum();
    }
    inline void User::clear_winnum() {
        _impl_.winnum_ = 0;
        _impl_._has_bits_[0] &= ~0x00000020u;
    }
    inline int32_t User::_internal_winnum() const {
        return _impl_.winnum_;
    }
    inline int32_t User::winnum() const {
        // @@protoc_insertion_point(field_get:tutorial.User.winNum)
        return _internal_winnum();
    }
    inline void User::_internal_set_winnum(int32_t value) {
        _impl_._has_bits_[0] |= 0x00000020u;
        _impl_.winnum_ = value;
    }
    inline void User::set_winnum(int32_t value) {
        _internal_set_winnum(value);
        // @@protoc_insertion_point(field_set:tutorial.User.winNum)
    }

    // repeated string replay = 7;
    inline int User::_internal_replay_size() const {
        return _impl_.replay_.size();
    }
    inline int User::replay_size() const {
        return _internal_replay_size();
    }
    inline void User::clear_replay() {
        _impl_.replay_.Clear();
    }
    inline std::string* User::add_replay() {
        std::string* _s = _internal_add_replay();
        // @@protoc_insertion_point(field_add_mutable:tutorial.User.replay)
        return _s;
    }
    inline const std::string& User::_internal_replay(int index) const {
        return _impl_.replay_.Get(index);
    }
    inline const std::string& User::replay(int index) const {
        // @@protoc_insertion_point(field_get:tutorial.User.replay)
        return _internal_replay(index);
    }
    inline std::string* User::mutable_replay(int index) {
        // @@protoc_insertion_point(field_mutable:tutorial.User.replay)
        return _impl_.replay_.Mutable(index);
    }
    inline void User::set_replay(int index, const std::string& value) {
        _impl_.replay_.Mutable(index)->assign(value);
        // @@protoc_insertion_point(field_set:tutorial.User.replay)
    }
    inline void User::set_replay(int index, std::string&& value) {
        _impl_.replay_.Mutable(index)->assign(std::move(value));
        // @@protoc_insertion_point(field_set:tutorial.User.replay)
    }
    inline void User::set_replay(int index, const char* value) {
        GOOGLE_DCHECK(value != nullptr);
        _impl_.replay_.Mutable(index)->assign(value);
        // @@protoc_insertion_point(field_set_char:tutorial.User.replay)
    }
    inline void User::set_replay(int index, const char* value, size_t size) {
        _impl_.replay_.Mutable(index)->assign(
            reinterpret_cast<const char*>(value), size);
        // @@protoc_insertion_point(field_set_pointer:tutorial.User.replay)
    }
    inline std::string* User::_internal_add_replay() {
        return _impl_.replay_.Add();
    }
    inline void User::add_replay(const std::string& value) {
        _impl_.replay_.Add()->assign(value);
        // @@protoc_insertion_point(field_add:tutorial.User.replay)
    }
    inline void User::add_replay(std::string&& value) {
        _impl_.replay_.Add(std::move(value));
        // @@protoc_insertion_point(field_add:tutorial.User.replay)
    }
    inline void User::add_replay(const char* value) {
        GOOGLE_DCHECK(value != nullptr);
        _impl_.replay_.Add()->assign(value);
        // @@protoc_insertion_point(field_add_char:tutorial.User.replay)
    }
    inline void User::add_replay(const char* value, size_t size) {
        _impl_.replay_.Add()->assign(reinterpret_cast<const char*>(value), size);
        // @@protoc_insertion_point(field_add_pointer:tutorial.User.replay)
    }
    inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>&
        User::replay() const {
        // @@protoc_insertion_point(field_list:tutorial.User.replay)
        return _impl_.replay_;
    }
    inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>*
        User::mutable_replay() {
        // @@protoc_insertion_point(field_mutable_list:tutorial.User.replay)
        return &_impl_.replay_;
    }

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

    // @@protoc_insertion_point(namespace_scope)

    }  // namespace tutorial

    // @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_User_2eproto
