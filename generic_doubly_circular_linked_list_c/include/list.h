#ifndef LIST_H
#define LIST_H

#include <stddef.h>
#include <stdbool.h>

/* Data Types */

/* Function Pointers */
typedef void (*ConsumerFunction)(void*);
typedef void (*IterationFunction)(void*, void*);
typedef bool (*CompareFunction)(void*, void*);

/* Forward Declaration */
struct list_t;

/* Object Type Definition */
typedef struct list_t list_t;

/* Public Functions */

list_t *list_new(void);

void list_delete(list_t *list, ConsumerFunction deleter);

void *list_push_back(list_t *list, void *object);

void *list_pop_back(list_t *list);

void *list_front(const list_t *list);

void *list_back(const list_t *list);

size_t list_size(const list_t *list);

bool list_empty(const list_t *list);

void *list_remove(list_t *list, size_t index);

void *list_get(const list_t *list, size_t index);

void list_foreach(const list_t *list, IterationFunction function, void *args);

void *list_search(const list_t *list, CompareFunction function, void *object);

bool list_search_remove(list_t *list, CompareFunction function, void *object, ConsumerFunction deleter);

bool list_sort(list_t *list, CompareFunction function);

#endif
