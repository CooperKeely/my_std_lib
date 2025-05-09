#include "../include/linkedlist.h"

Int32List* Int32List_Create(){
    Int32List* list = (Int32List*) malloc(sizeof(Int32List));
    list->head = NULL;
    list->size = 0;
    return list;
}

bool Int32List_PushBack(Int32List* list, int32_t val){
    Int32Node* insert_node = Int32Node_Create(val);
    Int32Node* current = list->head;
    while(current->next != NULL){
        current = current->next;
    }
    current->next = insert_node;
    list->size += 1;
    return true;
}

bool Int32List_PushFront(Int32List* list, int32_t val){
    Int32Node* insert_node = Int32Node_Create(val);
    if(list->head != NULL) insert_node->next = list->head->next;
    list->head = insert_node;
    list->size += 1;
    return true;
}

bool Int32List_Remove(Int32List* list, int32_t val){
    Int32Node* current = list->head;
    Int32Node* prev = NULL;
    while(current->next != NULL){
        prev = current;
        current = current->next;
        if(current->val == val){
            prev->next = current->next;
            free(current);
            current = NULL;
            list->size -= 1;
            return true;
        }
    }
    return false;
}

int32_t Int32List_Get(Int32List* list, size_t index){
    if(list->size <= index) assert(false);

    Int32Node* current = list->head;
    size_t current_index = 0;
   
    while(current != NULL){
       if(current_index == index){
           return current->val;
       }
       current = current->next;
       current_index += 1;
    }
    assert(false); 
    return -1;
}

void Int32List_Delete(Int32List* list){
    Int32Node* current = list->head;
    Int32Node* prev = NULL;
    while(current->next != NULL){
        current = current->next;
        prev = current;
        Int32Node_Delete(prev);
    }
    Int32Node_Delete(current);
    free(list);
}

size_t Int32List_Size(Int32List* list){
    return list->size;
}
