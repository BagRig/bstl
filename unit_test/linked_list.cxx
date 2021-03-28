#include "../container/linked_list.hxx"

#include <iostream>
#include <list>

void TEST(std::string msg, bool exp)
{
    std::cout << msg << ": ";
    if (exp) {
        std::cout << "Passed" << std::endl;
    } else {
        std::cout << "Failed" << std::endl;
    }
}

int main()
{
    impl::linked_list list;
    std::list<int> golden;
    TEST("1. Empty", list.empty() == golden.empty());
    TEST("2. Size", list.size() == golden.size());
    list.push_back(4);
    golden.push_back(4);
    TEST("3. Front", list.front() == golden.front());
    list.push_back(5);
    golden.push_back(5);
    TEST("4. Back & Pushback", list.back() == golden.back());
    TEST("5. Size", list.size() == golden.size());
    list.pop_back();
    golden.pop_back();
    list.pop_front();
    golden.pop_front();
    TEST("6. Pop_back & Pop_front", list.empty() == golden.empty());
    list.push_front(4);
    golden.push_front(4);
    TEST("7. PushFront", list.front() == golden.front());
    list.push_front(4);
    golden.push_front(4);
    list.push_back(4);
    golden.push_back(4);
    TEST("8. Size", list.size() == golden.size());
    list.clear();
    golden.clear();
    TEST("9. Clear", list.empty() == golden.empty());
    TEST("10. Size", list.size() == golden.size());

    return 0;
}
