#ifndef GEM_SINGLETON_HPP
#define GEM_SINGLETON_HPP

#include "NonCopyable.hpp"

namespace Gem
{
    template <class T_> class Singleton : NonCopyable
    {
    public:
        inline Singleton();
        inline ~Singleton();

    public:
        static inline T_& Instance();
        static inline T_* InstancePtr();

    private:
        static T_* s_instance;
    };

    template <class T_> T_* Singleton<T_>::s_instance = 0;
}

#include "Singleton.inl"

#endif
