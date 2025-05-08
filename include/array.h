#include <stdint.h>
#include <assert.h>
#include <stdbool.h>

typedef struct{
    int32_t* items;
    int32_t length;
    int32_t capacity;
} Int32Array;

int32_t Int32Array_Get(Int32Array array, int32_t index);
