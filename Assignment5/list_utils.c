#include <stdio.h>
#include "list.h"
#include "list_utils.h"

list *join_helper(const list *p)
{
    int arr[list_size(p)];
    for (int i = 0; i < list_size(p); i++)
        arr[i] = list_get(p, i);
    return list_init_arr(list_size(p), arr);
}

/**
 * If both are null, return an empty list. If one is null, 
 * return the other list by itself using join_helper. If they are both valid lists, 
 * we make a new list with everything in the first list, then inserting 
 * the second after the first. We return whatever the new array is.
*/
list *list_join(const list *p, const list *q)
{
    list *new;
    if (!p && !q)
        new = list_init_empty();
    else if (!p)
        new = join_helper(q);
    else if (!q)
        new = join_helper(p);
    else
    {
        new = list_init_empty();
        for (int i = 0; i < list_size(p); i++)
            list_add(new, list_get(p, i));
        for (int i = 0; i < list_size(q); i++)
            list_insert(new, list_size(p) + i, list_get(q, i));
    }
    return new;
}

/** 
 * For every element that does not match the condition (equal to the elem), 
 * it will be added to a new list, which is set to p. If the number of elements 
 * in the list is equal to the occurences of the element (remove everything) 
 * a new list will be returned.
*/
void *list_remove_all(const list *p, int elem)
{
    list *new = list_init_empty();
    int count = 0;
    for (int i = 0; i < list_size(p); i++)
    {
        if (list_get(p, i) != elem)
            list_add(new, list_get(p, i));
        else
            count++;
    }
    if (list_size(p) == count)
        p = list_init_empty();
    p = new;
}