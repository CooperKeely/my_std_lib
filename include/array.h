#include <stdint.h>
#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int32_t* items;
    size_t length;
    size_t capacity;
} Int32Array;

int32_t Int32Array_Get(Int32Array* array, size_t index);

bool Int32Array_Set(Int32Array* array, size_t index, int32_t val);

bool Int32Array_Push(Int32Array* array, int32_t val);

void Int32Array_Delete(Int32Array* array);

Int32Array* Int32Array_Create(size_t size);
