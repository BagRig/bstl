#pragma once
#include<iostream>

namespace bstl
{

class vector
{
public:
    using value_type = int;
    using size_type = std::size_t;
    using reference = int&;
    using const_reference = const int&;
git
    class iterator
    {
    public:
        explicit iterator(value_type* n)
            : m_ptr(n)
        { }

        iterator operator++()
        {
            iterator temp(m_ptr);
            m_ptr++;
            return temp;
        }

        iterator operator++(int)
        {
            ++m_ptr;
            return *this;
        }

        iterator operator--()
        {
            iterator temp(m_ptr);
            m_ptr--;
            return temp;
        }

        iterator operator--(int)
        {
            --m_ptr;
            return *this;
        }

        iterator& operator=(const iterator& other)
        {
            m_ptr = other.m_ptr;
            return *this;
        }

        bool operator!=(const iterator& other)
        {
            return m_ptr != other.m_ptr;
        }

        bool operator==(const iterator& other)
        {
            return m_ptr == other.m_ptr;
        }

        value_type& operator*()
        {
            return *m_ptr;
        }


    private:
        value_type* m_ptr;

    };

public:
    vector()
        : m_cap(0)
        , m_size(0)
        , m_pArr(nullptr)
    {
        reserve(5);
    }

    ~vector()
    {
        clear();
        delete [] m_pArr;
    }


    iterator begin()
    {

        return iterator(m_pArr);
    }

    iterator end()
    {
        return iterator(m_pArr + m_size);
    }

    reference at(size_type pos )
    {
        return const_cast<reference>(static_cast<const vector &>(*this).at(pos));
    }

    const_reference at(size_type pos ) const
    {
        if (!(pos < size())) {
            throw std::out_of_range( "position is out of range" );
        } else {
            return m_pArr[pos];
        }
    }

    reference operator[](size_type pos )
    {
        return const_cast<reference>(static_cast<const vector &>(*this).operator[](pos));
    }

    const_reference operator[](size_type pos ) const
    {
        return m_pArr[pos];
    }


    reference front()
    {
        return const_cast<reference>(static_cast<const vector &>(*this).front());
    }

    const_reference front() const
    {
        return m_pArr[0];
    }


    reference back()
    {
        return const_cast<reference>(static_cast<const vector &>(*this).back());
    }

    const_reference back() const
    {
        return m_pArr[m_size - 1];
    }

    bool empty() const
    {
        return m_size == 0;
    }

    size_type size() const
    {
        return m_size;
    }

    void reserve( size_type new_cap )
    {
        if (new_cap >= capacity()) {
            value_type* new_vec = new value_type[new_cap];
            for (std::size_t i = 0; i < m_size; ++i) {
                new_vec[i] = m_pArr[i];
            }
            delete [] m_pArr;
            m_pArr = new_vec;
            m_cap = new_cap;
        }
    }

    size_type capacity() const
    {
        return m_cap;
    }

    void clear()
    {
        m_size = 0;
    }

    void push_back( const value_type& value )
    {
        if (m_size == m_cap) {

            reserve(m_cap + m_cap / 2);
        }
        m_pArr[m_size] = value;
        ++m_size;
    }

    void pop_back()
    {
        --m_size;
    }

    iterator insert( iterator pos, const value_type& value )
    {
        if(m_size == m_cap) {
            int count = 0;
            for (iterator i = begin(); i != pos; ++i)
            {
                ++count;
            }
            reserve(m_size + m_size/2);
            iterator posi(m_pArr + count);
            pos = end();
            --pos;
            for (iterator i = end(); i != posi; --i)
            {
                *i = *pos;
                --pos;
            }
            *posi = value;
            ++m_size;
            return posi;
        } else {
            iterator a = end();
            --a;
            for (iterator i = end(); i != pos; --i)
            {
                *i = *a;
                --a;
            }
            *pos = value;
            ++m_size;
            return pos;
        }
    }

    iterator erase( iterator pos )
    {
        iterator a = pos;
        ++a;
        for (iterator i = a; i != end(); ++i)
        {
            *pos = *i;
            ++pos;
        }
        --m_size;
        return a;
    }

    void resize( size_type count, value_type value = value_type())
    {
        if (m_size > count) {
            while (m_size > count) {
                pop_back();
            }
        } else {
            if (m_cap >= count) {
                for (size_type i = m_size; i < count; ++i)
                {
                    m_pArr[i] = value;
                }
                m_size = count;
            } else {
                reserve(count);
                for (size_type i = m_size; i < count; ++i)
                {
                    m_pArr[i] = value;
                }
                m_size = count;
            }
        }
    }

    void shrink_to_fit()
    {
        value_type* new_vec = new value_type[m_size];
        for (std::size_t i = 0; i < m_size; ++i) {
            new_vec[i] = m_pArr[i];
        }
        delete [] m_pArr;
        m_pArr = new_vec;
        m_cap = m_size;
    }

    value_type* data()
    {
        return m_pArr;
    }

    void swap( vector& other )
    {
        value_type* new_vec = new value_type[m_cap];
        new_vec = m_pArr;
        m_pArr = other.m_pArr;
        other.m_pArr = new_vec;
    }

    void assign (iterator first, iterator last)
    {
        value_type* new_vec = new value_type;
        ++last;
        size_t j = 0;
        for(iterator i = first; i != last; ++i) {
            *(new_vec + j) = *i;
            ++j;
        }
        delete[] m_pArr;
        m_pArr = new_vec;
        m_size = j;
        m_cap = m_size;
    }

private:
    value_type* m_pArr;
    size_type m_size;
    size_type m_cap;

};

} // namespace bstl

