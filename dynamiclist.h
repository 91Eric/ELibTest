#ifndef _DYNAMICLIST_H_
#define _DYNAMICLIST_H_

#include <new>
#include <iostream>

namespace ELibTest
{

template<typename T>
class DynamicList
{
public:
    DynamicList& operator =(const DynamicList& e)
    {}
    DynamicList(int capacity)
    {
        if(m_space != NULL)
        {
            m_capacity = capacity;
            m_length = 0;
        }
    }

    bool insert(int i, const T& e)
    {
        bool ret = (i >= 0) && (i <= m_length);
        ret &= (m_length + 1) < capacity();

        if(ret)
        {
            for(int j = m_length - 1;j >= i;j--)
            {
                m_space[j + 1] = m_space[j];
            }

            m_space[i] = e;
            m_length++;
        }

        return ret;
    }

    bool insert(const T& e)
    {
        return insert(m_length,e);
    }

    bool remove(int i)
    {
        bool ret = (i >= 0) && (i < m_length); //
        if(ret)
        {
            for(int j = i;j < m_length - 1;j++)
            {
                m_space[j] = m_space[j + 1];
            }

            m_length--;
        }

        return ret;
    }

    bool set(int i,const T& e)
    {
        bool ret = (i >= 0) && (i < m_length);

        if(ret)
        {
            m_space[i] = e;
        }

        return ret;
    }
    bool get(int i,T& e) const
    {
        bool ret = (i >= 0) && (i < m_length);

        if(ret)
        {
            e = m_space[i] ;
        }

        return ret;
    }

    T& operator [](int i)
    {
        if((i >= 0) && (i < m_length))
            return m_space[i];
        else
            assert(0);
    }

    T operator [](int i) const
    {
        return (const_cast<DynamicList<T>&>(*this))[i];
    }

    int find(const T& e) const
    {
       int re = -1;

       for(int i = 0;i < m_length;i++)
       {
           if(m_space[i] == e)
           {
               ret = i;
               break;
           }
       }

       return ret;
    }

    void resize(int newcapacity)
    {
        if(this->m_capacity != newcapacity)
        {
            T* space = new T[newcapacity];

            if(space != NULL)
            {
                int length = (this->m_length < newcapacity ? this->m_length:newcapacity);

                for(int i = 0;i < length;i++)
                {
                    space[i] = this->m_space[i];
                }

                T* tmp = this->m_space;
                this->m_space = space;
                this->m_length = length;
                this->m_capacity = newcapacity;
                delete[] tmp;
            }
        }
    }

    int length() const
    {
        return m_length;
    }

    int capacity()
    {
       return m_capacity;
    }

    void clear()
    {
        m_length = 0;
    }
private:
    T* m_space;
    int m_capacity;
    int m_length;

};


}

#endif // DYNAMICLIST_H
