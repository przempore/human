namespace Gem
{
    template <class T_>
    inline Singleton<T_>::Singleton()
    {
        GEM_ASSERT(s_instance == nullptr);

        int offset = (int)(T_*)1 - (int)(Singleton<T_>*)(T_*)1;

        s_instance = (T_*)((int)this + offset);
    }

    template <class T_>
    inline Singleton<T_>::~Singleton()
    {
        GEM_ASSERT(s_instance != nullptr);

        s_instance = nullptr;
    }

    template <class T_>
    inline T_& Singleton<T_>::Instance()
    {
        GEM_ASSERT(s_instance != nullptr);

        return *s_instance;
    }

    template <class T_>
    inline T_* Singleton<T_>::InstancePtr()
    {
        return s_instance;
    }
}
