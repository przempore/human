namespace Gem
{
    template <class T_>
    inline Singleton<T_>::Singleton()
    {
        GEM_ASSERT(s_instance == 0);

        int offset = (int)(T_*)1 - (int)(Singleton<T_>*)(T_*)1;

        s_instance = (T_*)((int)this + offset);
    }

    template <class T_>
    inline Singleton<T_>::~Singleton()
    {
        GEM_ASSERT(s_instance != 0);

        s_instance = 0;
    }

    template <class T_>
    inline T_& Singleton<T_>::Instance()
    {
        GEM_ASSERT(s_instance != 0);

        return *s_instance;
    }

    template <class T_>
    inline T_* Singleton<T_>::InstancePtr()
    {
        return s_instance;
    }
}
