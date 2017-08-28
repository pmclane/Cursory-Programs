#include <iostream>
using namespace std;

class Heap
{
public:
    Heap()
    {
        m_members = nullptr;
        m_size = 0;
        m_ordered = true;
    }
    ~Heap()
    {
        if (m_members != nullptr )
        {
            delete[] m_members;
        }
    }
    void AddMember( int newMember )
    {
        int* arrayHolder = new int[m_size+1];
        if (m_members != nullptr)
        {   for (int i = 0; i < m_size; i++)
            {
                arrayHolder[i] = m_members[i];
            }
            delete[] m_members;
        }
        arrayHolder[m_size] = newMember;
        m_members = arrayHolder;

        m_size++;

        if ( m_size > 1 )
        {
            m_ordered = false;
        }
    }
    void RemoveFirstMember()
    {
        m_size--;
        int* arrayHolder = new int[m_size];
        for (int i = 0; i < m_size; i++)
        {
            arrayHolder[i] = m_members[i+1];
        }
            delete[] m_members;
            m_members = arrayHolder;
    }
    bool IsOrdered()
    {
        return m_ordered;
    }
    void SortHeap()
    {
        if (!IsOrdered())
        {
            OrderMembers();
        }
       int* arrayHolder = new int[m_size];
       int sizeHolder = m_size;
       for (int i = 0; i < sizeHolder; i++)
       {
           arrayHolder[i] = m_members[0];
           RemoveFirstMember();
           OrderMembers();
       }
       delete[] m_members;
       m_members = arrayHolder;
       m_size = sizeHolder;
    }
    void OrderMembers()
    {
        m_ordered = false;
        while ( !m_ordered )
        {
            bool didSwap = false;
            int child = m_size-1;


            while ( child > 0 )
            {
                int parent = (child-1)/2;

                if ( m_members[child] < m_members[parent] )
                {
                    swap(m_members[child], m_members[parent]);
                    didSwap = true;
                }

                child--;
            }
            if (!didSwap)
            {
                m_ordered = true;
            }
        }
    }
    void ListAllMembers()
    {
        for (int i = 0; i < m_size; i++)
        {
            ListMember(i);
            cout << endl;
        }
    }
    void ListMember(int index)
    {
        cout << m_members[index];
    }

private:
    int* m_members;
    int m_size;
    bool m_ordered;
};
