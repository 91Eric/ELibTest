#ifndef _STATICLIST_H_
#define _STATICLIST_H_

#include <cassert>

namespace ELibTest {

template<typename T,int N>
class StaticList
{
private:
    T m_space[N];
    int m_length;
private:


public:
    StaticList(const T& e){}
    StaticList<T,N>& operator =(const T& e){}
    StaticList()
    {
        m_length = 0;
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
        return (const_cast<StaticList<T,N>&>(*this))[i];
    }

    int find(const T& e) const
    {
       int ret = -1;
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

    int capacity()
    {
       return N;
    }
    int length() const
    {
        return m_length;
    }

    void clear()
    {
        m_length = 0;
    }
};

}

#endif // STATICLIST_H
