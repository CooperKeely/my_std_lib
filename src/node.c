#include "../include/node.h"

Int32Node* Int32Node_Create(int32_t val){
    Int32Node* node = (struct Int32Node*) malloc(sizeof(struct Int32Node));
    assert(node != NULL);
    node->next = NULL;
    node->val = val;
    return node;
}

void Int32Node_Delete(Int32Node* node){
    free(node);
    node = NULL;
}
