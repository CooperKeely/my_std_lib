#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Int32Node{
    struct Int32Node* next;
    int32_t val;
}Int32Node;

Int32Node* Int32Node_Create(int32_t);
void Int32Node_Delete(Int32Node* );
