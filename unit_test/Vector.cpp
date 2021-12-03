#include "container/vector.hxx"
#include <iostream>
#include <gtest/gtest.h>


TEST(Vector_test, Vec_capacity_reserve) {
    bstl::vector vec;
    ASSERT_EQ(5, vec.capacity());
    vec.reserve(10);
    ASSERT_EQ(10, vec.capacity());
}

TEST(Vector_test, Vec_clear) {
    bstl::vector vec;
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(1);
    ASSERT_EQ(3, vec.size());
    vec.clear();
    ASSERT_EQ(0, vec.size());

}

TEST(Vector_test, Vec_push_back_opbrackets) {
    bstl::vector vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    ASSERT_EQ(3, vec[2]);
    ASSERT_EQ(2, vec[1]);
    ASSERT_EQ(1, vec[0]);
}

TEST(Vector_test, Vec_pop_back_at) {
    bstl::vector vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(6);
    ASSERT_EQ(6, vec.at(5));
    vec.pop_back();
    ASSERT_EQ(5, vec.at(4));
    vec.pop_back();
    ASSERT_EQ(4, vec.back());
}

TEST(Vector_test, Vec_size) {
    bstl::vector vec;
    ASSERT_EQ(0, vec.size());
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    ASSERT_EQ(3, vec.size());
    vec.pop_back();
    vec.pop_back();
    ASSERT_EQ(1, vec.size());
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.clear();
    ASSERT_EQ(0, vec.size());
}

TEST(Vector_test, Vec_empty) {
    bstl::vector vec;
    ASSERT_EQ(true, vec.empty());
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    ASSERT_EQ(false, vec.empty());
    vec.pop_back();
    vec.pop_back();
    ASSERT_EQ(false, vec.empty());
    vec.pop_back();
    ASSERT_EQ(true, vec.empty());
}

TEST(Vector_test, Vec_front) {
    bstl::vector vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    EXPECT_EQ(1, vec.front());
    vec.clear();
    vec.push_back(2);
    vec.push_back(4);
    vec.push_back(6);
    EXPECT_EQ(2, vec.front());
}

TEST(Vector_test, Vec_back) {
    bstl::vector vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    EXPECT_EQ(3, vec.back());
    vec.pop_back();
    EXPECT_EQ(2, vec.back());
    vec.pop_back();
    EXPECT_EQ(1, vec.back());
}

TEST(Vector_test, Vec_Insert_CapGsize) {
    bstl::vector vec;
    vec.push_back(10);
    vec.push_back(10);
    vec.push_back(10);
    vec.push_back(10);
    EXPECT_EQ(4, vec.size());
    EXPECT_EQ(5, vec.capacity());
    bstl::vector::iterator pos = vec.begin();
    EXPECT_EQ(11, *vec.insert(pos, 11));
}

TEST(Vector_test, Vec_Insert_CapEQsize) {
    bstl::vector vec;
    vec.push_back(10);
    vec.push_back(10);
    vec.push_back(10);
    vec.push_back(10);
    vec.push_back(10);
    EXPECT_EQ(5, vec.size());
    EXPECT_EQ(5, vec.capacity());
    bstl::vector::iterator pos = vec.begin();
    EXPECT_EQ(11, *vec.insert(pos, 11));
}

TEST(Vector_test, Vec_Erase) {
    bstl::vector vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(6);
    bstl::vector::iterator pos = vec.begin();
    ++pos;
    vec.erase(pos);
    EXPECT_EQ(3, *pos);
    ++pos;
    ++pos;
    EXPECT_EQ(6, *(vec.erase(pos)));
}

TEST(Vector_test, Vec_Resize) {
    bstl::vector vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(6);
    vec.resize(4);
    EXPECT_EQ(4, vec.size());
    vec.clear();
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(6);
    vec.resize(8);
    EXPECT_EQ(8, vec.size());
    EXPECT_EQ(0, vec[6]);
    EXPECT_EQ(0, vec[7]);
    vec.clear();
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(6);
    vec.resize(8, 4);
    EXPECT_EQ(8, vec.size());
    EXPECT_EQ(4, vec[6]);
    EXPECT_EQ(4, vec[7]);
}

TEST(Vector_test, Vec_data) {
    bstl::vector vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(6);
    EXPECT_EQ(1, *vec.data());
    EXPECT_EQ(2, *(vec.data() + 1));
    EXPECT_EQ(3, *(vec.data() + 2));
    EXPECT_EQ(4, *(vec.data() + 3));
    EXPECT_EQ(5, *(vec.data() + 4));
    EXPECT_EQ(6, *(vec.data() + 5));
}

TEST(Vector_test, Vec_swap) {
    bstl::vector vec1;
    bstl::vector vec2;
    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(3);
    vec2.push_back(4);
    vec2.push_back(5);
    vec2.push_back(6);
    bstl::vector& refvec = vec2;
    vec1.swap(refvec);
    EXPECT_EQ(1, *vec2.data());
    EXPECT_EQ(2, *(vec2.data() + 1));
    EXPECT_EQ(3, *(vec2.data() + 2));
    EXPECT_EQ(4, *vec1.data());
    EXPECT_EQ(5, *(vec1.data() + 1));
    EXPECT_EQ(6, *(vec1.data() + 2));
}

TEST(Vector_test, Vec_Assign) {
    bstl::vector vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(6);
    bstl::vector::iterator first = vec.begin();
    bstl::vector::iterator last = vec.end();
    ++first;
    ++first;
    --last;
    --last;
    --last;
    vec.assign(first, last);
    EXPECT_EQ(3, *(vec.data()));
    EXPECT_EQ(2, vec.size());
    EXPECT_EQ(4, *(vec.data() + vec.size() - 1));
}

TEST(Vector_test, Vec_ShrinkToFit) {
    bstl::vector vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    EXPECT_EQ(5, vec.capacity());
    vec.shrink_to_fit();
    EXPECT_EQ(3, vec.capacity());
}


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

