#include "unity/unity.h"
#include "../include/array.h"
#include "../include/linkedlist.h"

void setUp(void) {}
void tearDown(void) {}

/* Array Tests */
void test_array_push_and_get(void) {
    Array* arr = array_create(5);
    TEST_ASSERT_TRUE(array_push(arr, 10));
    TEST_ASSERT_EQUAL(10, array_get(arr, 0));
    array_destroy(arr);
}

void test_array_bounds_check(void) {
    Array* arr = array_create(2);
    array_push(arr, 1);
    array_push(arr, 2);
    TEST_ASSERT_FALSE(array_push(arr, 3)); // overflow
    array_destroy(arr);
}

void test_array_set(void) {
    Array* arr = array_create(3);
    array_push(arr, 0);
    array_push(arr, 0);
    array_push(arr, 0);
    TEST_ASSERT_TRUE(array_set(arr, 1, 42));
    TEST_ASSERT_EQUAL(42, array_get(arr, 1));
    array_destroy(arr);
}

/* Linked List Tests */
void test_list_push_front_and_get(void) {
    LinkedList* list = list_create();
    list_push_front(list, 5);
    list_push_front(list, 10);
    TEST_ASSERT_EQUAL(10, list_get(list, 0));
    TEST_ASSERT_EQUAL(5, list_get(list, 1));
    list_destroy(list);
}

void test_list_push_back(void) {
    LinkedList* list = list_create();
    list_push_back(list, 1);
    list_push_back(list, 2);
    TEST_ASSERT_EQUAL(1, list_get(list, 0));
    TEST_ASSERT_EQUAL(2, list_get(list, 1));
    list_destroy(list);
}

void test_list_size(void) {
    LinkedList* list = list_create();
    TEST_ASSERT_EQUAL(0, list_size(list));
    list_push_back(list, 1);
    list_push_back(list, 2);
    list_push_front(list, 3);
    TEST_ASSERT_EQUAL(3, list_size(list));
    list_destroy(list);
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

