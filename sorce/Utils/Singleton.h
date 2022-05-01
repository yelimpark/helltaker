#pragma once
#include <assert.h>

template < typename T >
class Singleton {
private:
    static T* instance;

protected:
    Singleton()
    {
        assert(instance == nullptr);
        instance = static_cast<T*> (this);
    }

    ~Singleton()
    {
        assert(instance != nullptr);
        instance = nullptr;
    }

public:
    inline static T* Instance()
    {
        assert(instance != nullptr);
        return instance;
    }
};

template <typename T>
T* Singleton<T>::instance = nullptr;