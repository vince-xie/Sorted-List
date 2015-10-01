//
//  main.c
//  Sorted List
//
//  Created by Vince Xie, Jacob Rizer on 9/24/15.
//  Copyright © 2015 Vince Xie. All rights reserved.
//

#include <stdio.h>
#include "sorted-list.h"

/*
 * Creates and allocates memory for a new node for the linked list.
 */
Node *createNewNode(){
    Node *node = (Node *)malloc(sizeof(Node));
    node->next = NULL;
    node->data = NULL;
    node->prev = NULL;
    return node;
}

/*
 * SLCreate creates a new, empty sorted list.  The caller must provide
 * a comparator function that can be used to order objects that will be
 * kept in the list, and a destruct function that gets rid of the objects
 * once they are no longer in the list or referred to in an iterator.
 *
 * If the function succeeds, it returns a (non-NULL) SortedListT object,
 * otherwise, it returns NULL.
 *
 * You need to fill in this function as part of your implementation.
 */

SortedListPtr SLCreate(CompareFuncT cf, DestructFuncT df){
    SortedListPtr list = (SortedListPtr)malloc(sizeof(struct SortedList));
    list->compareFuncT = cf;
    list->destructFuncT = df;
    list->head = createNewNode();
    return list;
}

/*
 * SLDestroy destroys a list, freeing all dynamically allocated memory.
 *
 * You need to fill in this function as part of your implementation.
 */
void SLDestroy(SortedListPtr list){
    
}


/*
 * SLInsert inserts a given object into a sorted list, maintaining sorted
 * order of all objects in the list.  If the new object is equal to an object
 * already in the list (according to the comparator function), then the operation should fail.
 *
 * If the function succeeds, it returns 1, otherwise it returns 0.
 *
 * You need to fill in this function as part of your implementation.
 */

int SLInsert(SortedListPtr list, void *newObj){
    SortedListIteratorPtr it = SLCreateIterator(list);
    it->current = list->head;
    if(it->current->data == NULL){
        it->current->data = (void *)malloc(sizeof(void));
        it->current->data = newObj;
    }
    return 1;
}


/*
 * SLRemove removes a given object from a sorted list.  Sorted ordering
 * should be maintained.  SLRemove may not change the object whose
 * pointer is passed as the second argument.  This allows you to pass
 * a pointer to a temp object equal to the object in the sorted list you
 * want to remove.
 *
 * If the function succeeds, it returns 1, otherwise it returns 0.
 *
 * You need to fill in this function as part of your implementation.
 */

int SLRemove(SortedListPtr list, void *newObj){
    return 1;
}


/*
 * SLCreateIterator creates an iterator object that will allow the caller
 * to "walk" through the list from beginning to the end using SLNextItem.
 *
 * If the function succeeds, it returns a non-NULL pointer to a
 * SortedListIterT object, otherwise it returns NULL.  The SortedListT
 * object should point to the first item in the sorted list, if the sorted
 * list is not empty.  If the sorted list object is empty, then the iterator
 * should have a null pointer.
 *
 * You need to fill in this function as part of your implementation.
 */

SortedListIteratorPtr SLCreateIterator(SortedListPtr list){
    if(list == NULL){
        return NULL;
    }
    SortedListIteratorPtr it = (SortedListIteratorPtr)malloc(sizeof(struct SortedListIterator));
    it->current = list->head;
    return it;
}


/*
 * SLDestroyIterator destroys an iterator object that was created using
 * SLCreateIterator().  Note that this function should destroy the
 * iterator but should NOT affect the original list used to create
 * the iterator in any way.
 *
 * You need to fill in this function as part of your implementation.
 */

void SLDestroyIterator(SortedListIteratorPtr iter){
    
}


/*
 * SLGetItem returns the pointer to the data associated with the
 * SortedListIteratorPtr.  It should return 0 if the iterator
 * advances past the end of the sorted list.
 *
 * You need to fill in this function as part of your implementation.
 */

void * SLGetItem( SortedListIteratorPtr iter ){
    return NULL;
}

/*
 * SLNextItem returns the pointer to the data associated with the
 * next object in the list associated with the given iterator.
 * It should return a NULL when the end of the list has been reached.
 *
 * One complication you MUST consider/address is what happens if a
 * sorted list associated with an iterator is modified while that
 * iterator is active.  For example, what if an iterator is "pointing"
 * to some object in the list as the next one to be returned but that
 * object is removed from the list using SLRemove() before SLNextItem()
 * is called.
 *
 * You need to fill in this function as part of your implementation.
 */

void * SLNextItem(SortedListIteratorPtr iter){
    return NULL;
}

int main(int argc, const char * argv[]) {
    char *string = "Hello";
    SortedListPtr list = SLCreate( (int(*)( void *, void * ))strcmp , (void(*)(void *))SLDestroy);
    SLInsert(list, string);
    printf("%s", list->head->data);
    return 0;
}
