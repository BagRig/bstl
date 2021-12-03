#pragma once

#include <cstddef>
#include <iostream>


namespace impl
{

class linked_list
{
public:
    using value_type = int;
    using size_type = std::size_t;
    using reference = value_type&;
    using const_reference = const value_type&;

    class node
    {
    public:
        node(value_type value, node* next, node* prev)
            : Value(value)
            , Next(next)
            , Prev(prev)
        { }
    public:
        value_type Value;
        node* Next;
        node* Prev;
    };

    class iterator
    {
    public:
        iterator(node* pointer)
            : m_pointer(pointer)
        { }

        iterator(const iterator& other)
            : m_pointer(other.m_pointer)
        { }

        iterator& operator=(const iterator& other)
        {
            m_pointer = other.m_pointer;
            return *this;
        }
        iterator operator++()
        {
            iterator tmp(*this);
            m_pointer = m_pointer->Next;
            return tmp;
        }

        iterator& operator++(int)
        {
            m_pointer = m_pointer->Next;
            return *this;
        }

        iterator operator--()
        {
            iterator tmp(*this);
            m_pointer = m_pointer->Prev;
            return tmp;
        }

        iterator& operator--(int)
        {
            m_pointer = m_pointer->Prev;
            return *this;
        }

        bool operator!=(const iterator& other)
        {
            return m_pointer != other.m_pointer;
        }

        value_type operator*() const
        {
            return m_pointer->Value;
        }

    private:
        node* m_pointer;
    };

public:
    linked_list()
        : m_pHead(nullptr)
        , m_pTail(nullptr)
        , m_size(0)
    { }

    ~linked_list()
    {
        clear();
    }

    /**
    * @brief Returns an iterator to the first element of the list.
    * If the list is empty, the returned iterator will be equal to end().
    */
    iterator begin()
    {
        if(empty()) {
            return end();
        } else {
            return iterator(m_pHead);
        }
    }

    /**
    * @brief Returns an iterator to the element following the last element of the list.
    */
    iterator end()
    {
        return iterator(m_pTail->Next);
    }

    /**
    * @brief Checks if the container has no elements, i.e. whether begin() == end().
    */
    bool empty() const
    {
        return nullptr == m_pHead;
        // return begin() == end();
    }

    /**
    * @brief Returns the number of elements in the container.
    */
    size_type size() const
    {
        return m_size;
    }

    /**
    * @brief Returns a reference to the first element in the container.
    * Calling front on an empty container is undefined.
    */
    reference front()
    {
        return m_pHead->Value;
    }

    /**
    * @brief Returns a reference to the first element in the container.
    * Calling front on an empty container is undefined.
    */
    const_reference front() const
    {
        return m_pHead->Value;
    }

    /**
    * @brief Returns a reference to the last element in the container.
    * Calling back on an empty container causes undefined behavior.
    */
    reference back()
    {
        return m_pTail->Value;
    }

    /**
    * @brief Returns a reference to the last element in the container.
    * Calling back on an empty container causes undefined behavior.
    */
    const_reference back() const
    {
        return m_pTail->Value;
    }

    /**
    * @brief Prepends the given element value to the beginning of the container.
    * No iterators or references are invalidated.
    *
    * @param[in] value - the value of the element to prepend
    */
    void push_front(const_reference value)
    {
        m_pHead = new node(value, m_pHead, nullptr);
        if (nullptr == m_pTail) {
            m_pTail = m_pHead;
        }
        ++m_size;
    }

    /**
    * @brief Removes the first element of the container. If there are no elements in the container, the behavior is undefined.
    * References and iterators to the erased element are invalidated.
    */
    void pop_front()
    {
        node* temp = m_pHead;
        m_pHead = m_pHead->Next;
        if (nullptr != m_pHead) {
            m_pHead->Prev = nullptr;
        } else {
            m_pTail = m_pHead;
        }
        delete temp;
        --m_size;
    }

    /**
    * @brief Appends the given element value to the end of the container.
    * No iterators or references are invalidated.
    *
    * @param[in] value - the value of the element to append
    */
    void push_back(const_reference value)
    {
        node* temp = new node(value, nullptr, m_pTail);
        if (nullptr == m_pHead) {
            m_pTail = temp;
            m_pHead = m_pTail;
        } else {
            m_pTail->Next = temp;
            m_pTail = m_pTail->Next;
        }
        ++m_size;
    }

    /**
    * @brief Removes the last element of the container.
    * Calling pop_back on an empty container results in undefined behavior.
    * References and iterators to the erased element are invalidated.
    */
    void pop_back()
    {
        node* temp = m_pTail;
        m_pTail = m_pTail->Prev;
        if (nullptr != m_pTail) {
            m_pTail->Next = nullptr;
        } else {
            m_pHead = m_pTail;
        }
        delete temp;
        --m_size;
    }

    /**
    * @brief Erases all elements from the container. After this call, size() returns zero.
    * Invalidates any references, pointers, or iterators referring to contained elements.
    * Any past-the-end iterator remains valid.
    */
    void clear()
    {
        for (node* ptr = m_pHead; nullptr != ptr; ptr = m_pHead) {
            m_pHead = m_pHead->Next;
            delete ptr;
        }
        m_pHead = nullptr;
        m_pTail = nullptr;
        m_size = 0;
    }


public:
    node* m_pHead;
    node* m_pTail;
    size_type m_size;

}; // linked_list

} // namespace impl