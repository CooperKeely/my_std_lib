#include "unity/unity.h"
#include "../include/array.h"
#include "../include/linkedlist.h"

void setUp(void) {}
void tearDown(void) {}

/* Array Tests */
void test_array_push_and_get(void) {
    Int32Array* arr = Int32Array_Create(5);
    TEST_ASSERT_TRUE(Int32Array_Push(arr, 10));
    TEST_ASSERT_EQUAL(10, Int32Array_Get(arr, 0));
    Int32Array_Delete(arr);
}

void test_array_bounds_check(void) {
    Int32Array* arr = Int32Array_Create(2);
    Int32Array_Push(arr, 1);
    Int32Array_Push(arr, 2);
    TEST_ASSERT_FALSE(Int32Array_Push(arr, 3)); // overflow
    Int32Array_Delete(arr);
}

void test_array_set(void) {
    Int32Array* arr = Int32Array_Create(3);
    Int32Array_Push(arr, 0);
    Int32Array_Push(arr, 0);
    Int32Array_Push(arr, 0);
    TEST_ASSERT_TRUE(Int32Array_Set(arr, 1, 42));
    TEST_ASSERT_EQUAL(42, Int32Array_Get(arr, 1));
    Int32Array_Delete(arr);
}

// linked list test
void test_list_push_front_and_get(void) {
    Int32List* list = Int32List_Create();
    Int32List_PushFront(list, 5);
    Int32List_PushFront(list, 10);
    TEST_ASSERT_EQUAL(10, Int32List_Get(list, 0));
    TEST_ASSERT_EQUAL(5, Int32List_Get(list, 1));
    Int32List_Delete(list);
}

void test_list_push_back(void) {
    Int32List* list = Int32List_Create();
    Int32List_PushBack(list, 1);
    Int32List_PushBack(list, 2);
    TEST_ASSERT_EQUAL(1, Int32List_Get(list, 0));
    TEST_ASSERT_EQUAL(2, Int32List_Get(list, 1));
    Int32List_Delete(list);
}

void test_list_size(void) {
    Int32List* list = Int32List_Create();
    TEST_ASSERT_EQUAL(0, Int32List_Size(list));
    Int32List_PushBack(list, 1);
    Int32List_PushBack(list, 2);
    Int32List_PushFront(list, 3);
    TEST_ASSERT_EQUAL(3, Int32List_Size(list));
    Int32List_Delete(list);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_array_push_and_get);
    RUN_TEST(test_array_bounds_check);
    RUN_TEST(test_array_set);
    RUN_TEST(test_list_push_front_and_get);
    RUN_TEST(test_list_push_back);
    RUN_TEST(test_list_size);
    return UNITY_END();
}

