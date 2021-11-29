#pragma once

#include "linked_list.hxx"

#include <iostream>

namespace bstl
{

class queue
{
private:
    using container_t = linked_list;

public:
    using value_type = container_t::value_type;
    using size_type = container_t::size_type;
    using reference = container_t::reference;
    using const_reference = container_t::const_reference;

public:
    queue()
        : m_container()
    { }

    ~queue()
    { }

    size_type size()
    {
        return m_container.size();
    }

    bool empty() const
    {
        return m_container.empty();
    }

    reference front()
    {
        return m_container.front();
    }

    const_reference front() const
    {
        return m_container.front();
    }

    reference back()
    {
        return m_container.back();
    }

    const_reference back() const
    {
        return m_container.back();
    }

    void push(value_type val)
    {
        m_container.push_back(val);
    }

    void pop()
    {
        m_container.pop_front();
    }

private:
    container_t m_container;

}; // queue

} // namespace bstl