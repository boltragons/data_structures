#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"

bool comparer_equal(void *content, void *args) {
    int *list_value = (int *) content;
    int *compare_value = (int *) args;

    return *list_value == *compare_value;
}

bool comparer_greater(void *element01, void *element02) {
    int *value01 = (int *) element01;
    int *value02 = (int *) element02;

    return *value01 > *value02;
}

void printer(void *content, void *args) {
    printf("VALUE: %d\n", *((int *) content));
}

int main() {
    /* Test Artifacts */
    void *object = NULL;
    list_t *list = NULL;

    /* List Elements */
    int *t0 = malloc(sizeof(int));
    *t0 = 0;
    int *t1 = malloc(sizeof(int));
    *t1 = 1;
    int *t2 = malloc(sizeof(int));
    *t2 = 2;
    int *t3 = malloc(sizeof(int));
    *t3 = 3;
    int *t4 = malloc(sizeof(int));
    *t4 = 4;
    int *t5 = malloc(sizeof(int));
    *t5 = 5;
    int *t6 = malloc(sizeof(int));
    *t6 = 6;

    /* TEST 01 - CREATE LIST */
    list = list_new();
    assert(list != NULL);

    /* TEST 02 - PUSH BACK INITIAL ELEMENTS */
    assert(list_push_back(list, t0) == t0);
    assert(list_push_back(list, t1) == t1);
    assert(list_push_back(list, t2) == t2);
    assert(list_push_back(list, t3) == t3);
    assert(list_push_back(list, t4) == t4);

    /* TEST 03 - PRINT INITIAL ELEMENTS */
    printf("\nFOREACH #1\n");
    list_foreach(list, &printer, NULL);

    /* TEST 04 - GET ELEMENT */
    object = list_get(list, 2);
    assert(object != NULL);
    assert(*((int *) object) == 2);

    /* TEST 05 - REMOVE ELEMENT */
    object = list_remove(list, 2);
    assert(object != NULL);
    assert(*((int *) object) == 2);
    free(object);

    /* TEST 06 - POP BACK */
    object = list_pop_back(list);
    assert(object != NULL);
    assert(*((int *) object) == 4);
    free(object);

    /* TEST 07 - PUSH AFTER POP */
    assert(list_push_back(list, t6) == t6);
    assert(list_push_back(list, t5) == t5);

    /* TEST 08 - PRINT ELEMENTS AFTER SORT */
    assert(list_sort(list, &comparer_greater) == true);
    printf("\nFOREACH #2\n");
    list_foreach(list, &printer, NULL);

    /* TEST 09 - GET FIRST ELEMENT */
    object = list_get(list, 0);
    assert(object != NULL);
    assert(*((int *) object) == 0);
    assert(list_get(list, 0) == list_front(list));

    /* TEST 10 - GET LAST ELEMENT */
    object = list_get(list, list_size(list) - 1);
    assert(object != NULL);
    assert(*((int *) object) == 6);
    assert(list_get(list, list_size(list) - 1) == list_back(list));

    /* TEST 11 - LIST SIZE */
    assert(list_size(list) == 5);

    /* TEST 12 - LIST SEARCH */
    assert(list_search(list, &comparer_equal, t5) == t5);
    assert(list_search(list, &comparer_equal, t4) == NULL);

    /* TEST 13 - LIST SEARCH AND REMOVE */
    assert(list_search_remove(list, &comparer_equal, t5, &free) == true);
    assert(list_search_remove(list, &comparer_equal, t4, &free) == false);

    /* TEST 14 - FREE LIST */
    list_delete(list, &free);
    
    return 0;
}
