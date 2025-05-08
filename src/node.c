#include "../include/node.h"

struct Node* node_create(int32_t val){
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    assert(node != NULL);
    node->next = NULL;
    node->val = val;
    return node;
}

