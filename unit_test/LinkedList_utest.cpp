#include "container/linked_list.hxx"
#include <iostream>
#include <gtest/gtest.h>


TEST(LL_test, LL_Front) {
    impl::linked_list list;
    list.push_front(1);
    EXPECT_EQ(1, list.front());
    list.push_front(2);
    EXPECT_EQ(2, list.front());
    list.push_front(3);
    EXPECT_EQ(3, list.front());
    list.push_front(4);
    EXPECT_EQ(4, list.front());
    list.pop_front();
    EXPECT_EQ(3, list.front());
    list.pop_front();
    EXPECT_EQ(2, list.front());
}

TEST(LL_test, LL_Back) {
    impl::linked_list list;
    list.push_back(1);
    EXPECT_EQ(1, list.back());
    list.push_back(2);
    EXPECT_EQ(2, list.back());
    list.push_back(3);
    EXPECT_EQ(3, list.back());
    list.push_back(4);
    EXPECT_EQ(4, list.back());
    list.pop_back();
    EXPECT_EQ(3, list.back());
    list.pop_back();
    EXPECT_EQ(2, list.back());
}

TEST(LL_test, LL_Begin) {
    impl::linked_list list;
    list.push_front(1);
    EXPECT_EQ(1, *list.begin());
    list.push_front(2);
    EXPECT_EQ(2, *list.begin());
    list.push_front(3);
    EXPECT_EQ(3, *list.begin());
    list.push_front(4);
    EXPECT_EQ(4, *list.begin());
}


TEST(LL_test, LL_Size) {
    impl::linked_list list;
    EXPECT_EQ(0, list.size());
    list.push_back(10);
    EXPECT_EQ(1, list.size());
    list.push_back(10);
    EXPECT_EQ(2, list.size());
    list.push_back(10);
    EXPECT_EQ(3, list.size());
    list.pop_back();
    EXPECT_EQ(2, list.size());
    list.pop_back();
    EXPECT_EQ(1, list.size());
    list.pop_back();
    EXPECT_EQ(0, list.size());
}

TEST(LL_test, LL_Empty) {
    impl::linked_list list;
    EXPECT_EQ(true, list.empty());
    list.push_back(10);
    EXPECT_EQ(false, list.empty());
    list.pop_back();
    EXPECT_EQ(true, list.empty());
}

TEST(LL_test, LL_Push_Front) {
    impl::linked_list list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);
    size_t j = 4;
    for(impl::linked_list::iterator i = list.begin(); i != list.end(); ++i)
    {
        EXPECT_EQ(j, *i);
        --j;
    }
}

TEST(LL_test, LL_Pop_Front) {
    impl::linked_list list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    EXPECT_EQ(4, list.size());
    list.pop_front();
    list.pop_front();
    EXPECT_EQ(2, list.size());
    impl::linked_list::iterator i = list.begin();
    EXPECT_EQ(3, *i);
    ++i;
    EXPECT_EQ(4, *i);
}

TEST(LL_test, LL_Push_Back) {
    impl::linked_list list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);
    size_t j = 4;
    for(impl::linked_list::iterator i = list.begin(); i != list.end(); ++i)
    {
        EXPECT_EQ(j, *i);
        --j;
    }
}

TEST(LL_test, LL_Pop_Back) {
    impl::linked_list list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    EXPECT_EQ(4, list.size());
    list.pop_back();
    list.pop_back();
    EXPECT_EQ(2, list.size());
    impl::linked_list::iterator i = list.begin();
    EXPECT_EQ(1, *i);
    ++i;
    EXPECT_EQ(2, *i);
}

TEST(LL_test, LL_Clear) {
    impl::linked_list list;
    list.push_front(5);
    list.push_front(5);
    list.push_front(5);
    EXPECT_EQ(3, list.size());
    list.clear();
    EXPECT_EQ(0, list.size());
}

TEST(LL_test, LL_Resize) {
    impl::linked_list list;
    list.push_front(5);
    list.push_front(5);
    list.push_front(5);
    EXPECT_EQ(3, list.size());
    list.resize(7);
    impl::linked_list::iterator i = list.begin();
    ++i;
    ++i;
    ++i;
    for(i; i != list.end(); ++i){
        EXPECT_EQ(0, *i);
    }
    EXPECT_EQ(7, list.size());
    list.resize(2);
    EXPECT_EQ(2, list.size());
    list.resize(4,2);
    impl::linked_list::iterator j = list.begin();
    EXPECT_EQ(5, *j);
    ++j;
    EXPECT_EQ(5, *j);
    ++j;
    EXPECT_EQ(2, *j);
    ++j;
    EXPECT_EQ(2, *j);

}




int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}