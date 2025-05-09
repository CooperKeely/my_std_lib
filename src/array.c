#include "../include/array.h"

int32_t Int32Array_Get(Int32Array* array, size_t index){
    if(index <= array->length){
           return array->items[index];
    }
    assert(false);
    return 0;
}

bool Int32Array_Set(Int32Array* array, size_t index, int32_t val){
     if(index <= array->length){
        array->items[index] = val;
        return true;
    }
    return false;
}

bool Int32Array_Push(Int32Array* array, int32_t val){
    if(array->length < array->capacity){
        Int32Array_Set(array, array->length, val);
        array->length += 1;
        return true;
    }
    return false;
}

void Int32Array_Delete(Int32Array* array){
    free(array->items);
    free(array); 
    array = NULL;
}

Int32Array* Int32Array_Create(size_t size){
    Int32Array* array = (Int32Array*) malloc(sizeof(Int32Array));
    array->items = malloc(size * sizeof(int32_t)); 
    array->length = 0;
    array->capacity = size;
    return array;
}
