#include "../include/linkedlist.h"

struct List* list_create(){
    struct List* list = (struct List*) malloc(sizeof(struct List));
    assert(list != NULL);
    list->head = node_create(0);
    list->size = 1;
    return list;
}

InsertResult push_back(List* list, int32_t val){
    Node* insert_node = node_create(val);
    Node* current = list->head;
    while(current->next != NULL){
        current = current->next;
    }
    current->next = insert_node;
    list->size += 1;
    return INSERT_SUCCESS;
}

InsertResult push_front(List* list, int32_t val){
    Node* insert_node = node_create(val);
    Node* current = list->head;
    Node* next = current->next;    
    insert_node->next = next;
    current->next = insert_node;
    list->size += 1;
    return INSERT_SUCCESS;
}

RemoveResult remove(List* list, int val){
    Node* current = list->head;
    Node* prev = NULL;
    while(current->next != NULL){
        prev = current;
        current = current->next;
        if(current->val == val){
            prev->next = current->next;
            free(current);
            current = NULL;
            list->size -= 1;
            return REMOVE_SUCCESS;
        }
    }
    return REMOVE_FAILED;
}
