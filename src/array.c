#include "../include/array.h"

int32_t Int32Array_Get(Int32Array array, int32_t index){
    if(index >= 0 && index <= array.length){
           return array.items[index];
    }
    assert(false);
    return 0;
}
