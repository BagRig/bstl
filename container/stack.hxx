#pragma once

#include "linked_list.hxx"

#include <iostream>

namespace bstl
{

class stack
{
private:
    using container_t = linked_list;

public:
    using value_type = container_t::value_type;
    using size_type = container_t::size_type;
    using reference = container_t::reference;
    using const_reference = container_t::const_reference;

public:
    stack()
        : m_container()
    { }

    ~stack()
    { }

    bool empty() const
    {
        return m_container.empty();
    }

    size_type size()
    {
        return m_container.size();
    }

    void push(value_type value)
    {
        m_container.push_front(value);
    }

    void pop()
    {
        m_container.pop_front();
    }

    reference top()
    {
        return m_container.front();
    }

    const_reference top() const
    {
        return m_container.front();
    }

private:
    container_t m_container;

}; // stack

} // namespace bstl
