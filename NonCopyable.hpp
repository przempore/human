#ifndef GEM_NON_COPYABLE_HPP
#define GEM_NON_COPYABLE_HPP

struct NonCopyable
{
    NonCopyable& operator=(const NonCopyable&) = delete;
    NonCopyable(const NonCopyable&) = delete;
    NonCopyable() = default;
};

#endif
