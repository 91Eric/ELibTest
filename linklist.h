#ifndef LINKLIST_H
#define LINKLIST_H

#include <iostream>

using namespace std;

namespace ELibTest {

template<typename T>
class LinkList
{
protected:
    struct Node
    {
        T value;
        Node* next;
    };

    mutable struct
    {
        char reserved[sizeof(T)];
        Node* next;
    }m_header;
    int m_lenght;

public:
    LinkList()
    {
        m_header.next = NULL;
        m_lenght = 0;
    }

    Node* position(int i) const
    {
        Node* current = reinterpret_cast<Node*>(&m_header);

        for(int j = 0;j < i;j++)
        {
            current = current->next;
        }

        return current;
    }

    bool insert(int i,const T& e)
    {
        bool ret = (i >= 0) && (i <= m_lenght);

        if(ret)
        {
            Node* node = new Node;
            if(node != NULL)
            {
                Node* current = position(i);

                node->value = e;
                node->next = current->next;
                current->next = node;

                m_lenght++;
            }
            else
            {
                throw "no enough memory";
            }
        }

        return ret;
    }

    bool insert(const T& e)
    {
        return insert(m_lenght,e);
    }

    bool remove(int i)
    {
        bool ret = (i >= 0) && (i < m_lenght);

        if(ret)
        {
            Node* current = position(i);

            Node* toDel = current->next;
            current->next = toDel->next;

            delete toDel;

            m_lenght--;
        }
        else
        {
            throw "out of range";
        }
    }

    bool set(int i,const T& e)
    {
        bool ret = (i >= 0) && (i < m_lenght);

        if(ret)
        {
            position(i)->next->value = e;
        }
        else
        {
            throw "out of range";
        }

        return ret;
    }

    T get(int i) const
    {

        T ret;
        if(get(i,ret))
        {
            return ret;
        }
        else
        {
            throw "out of range";
        }

        return ret;
    }

    bool get(int i,T& e) const
    {
        bool ret = (i >= 0) && (i < m_lenght);

        if(ret)
        {
            e = position(i)->next->value;
        }
        else
        {
            throw "out of range";
        }

        return ret;
    }

    int length() const
    {
        return m_lenght;
    }

    void clear()
    {
        while (m_header.next != NULL)
        {
            Node* toDel = m_header.next;

            m_header.next = toDel->next;
            delete toDel;
            m_lenght--;
        }

        m_lenght = 0;
    }

    int find(const T& e) const
    {
        Node* current = m_header.next;
        int ret = -1;
        int pos = 0;
        while (current)
        {
            if(current->value == e)
            {
                ret = pos;
                break;
            }
            else
            {
                current = current->next;
            }
            pos++;
        }

        return ret;
    }
    ~ LinkList()
    {
        clear();
    }
};


}

#endif // LINKLIST_H
