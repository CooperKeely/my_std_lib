#include <stdlib.h>
#include <stddef.h>
#include <assert.h>
#include "node.h"

// typedef's

typedef struct List{
    struct Node* head;
    int32_t size;
}List;

typedef enum {
    INSERT_SUCCESS,
    INSERT_FAILED
}InsertResult;

typedef enum{
    REMOVE_SUCCESS,
    REMOVE_FAILED
}RemoveResult;

struct Node* node_create(int32_t);
struct List* list_create();
InsertResult push_back(List* , int32_t);
InsertResult push_front(List* , int32_t);
