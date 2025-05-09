#include <stdlib.h>
#include <stddef.h>
#include <assert.h>
#include "node.h"
#include <stdbool.h>

// typedef's
typedef struct Int32List{
    Int32Node* head;
    size_t size;
}Int32List;

Int32List* Int32List_Create();
void Int32List_Delete(Int32List*);
bool Int32List_PushBack(Int32List* , int32_t);
bool Int32List_PushFront(Int32List* , int32_t);
int32_t Int32List_Get(Int32List*, size_t);
size_t Int32List_Size(Int32List*);
