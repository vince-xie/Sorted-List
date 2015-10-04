//
//  main.c
//  Sorted List
//
//  Created by Vince Xie on 10/3/15.
//  Copyright © 2015 Vince Xie. All rights reserved.
//

#include <stdio.h>
#include "sorted-list.h"

/*
 * Prints out the list. For testing purposes only. MUST change printf statement depending on type.
 */
void printList(SortedListPtr list){
    SortedListIteratorPtr it = SLCreateIterator(list);
    it->current = list->head;
    printf("%s %d\n", it->current->data, it->current->refrences);
    while(it->current->next != NULL){
        printf("%s %d\n", SLNextItem(it), it->current->refrences);
    }
    SLDestroyIterator(it);
}

int main(int argc, const char * argv[]) {
    SortedListPtr list = SLCreate( (int(*)( void *, void * ))strcasecmp , (void(*)(void *))SLDestroy);
    SLInsert(list, "Hello");
    SLInsert(list, "ZZZ");
    SLInsert(list, "Awesome");
    SLInsert(list, "apple");
    SLInsert(list, "Zed");
    SLInsert(list, "Time");
    SLInsert(list, "Rate");
    SLInsert(list, "Test");
    printList(list);
    printf("%d\n", SLInsert(list, "Time"));
    printf("%d\n", SLInsert(list, "apple"));
    printf("%d\n", SLInsert(list, "ZZZ"));
    return 0;
}