#include <stddef.h>
#include "list.h"
#include "list_utils.h"

void list_join_demo();
void list_remove_demo();

int main(void)
{
    list_join_demo();
    list_remove_demo();
}

void list_join_demo()
{
    list *q1_1 = list_init_empty();
    list *q1_2 = list_init_empty();
    for (int i = 1; i < 4; i++)
        list_add(q1_1, i);
    for (int i = 10; i < 13; i++)
        list_add(q1_2, i);
    list_print(list_join(q1_1, q1_2));
    list_print(list_join(NULL, q1_2));
    list_print(list_join(q1_1, NULL));
    list_print(list_join(NULL, NULL));

    list_free(q1_1);
    list_free(q1_2);
}

void list_remove_demo()
{
    int arr[] = {4, 3, 2, 1, 2, 3, 4};
    int arr2[] = {4, 4, 4, 4, 4};
    list *q2_1 = list_init_arr(7, arr); // Remove 5, 0 times
    list_print(list_remove_all(q2_1, 5));
    list *q2_2 = list_init_arr(7, arr); // Remove 1, 1 time
    list_print(list_remove_all(q2_2, 1));
    list *q2_3 = list_init_arr(7, arr); // Remove 4, 2 times
    list_print(list_remove_all(q2_3, 4));
    list *q2_4 = list_init_arr(5, arr2); // Remove 4, 5 times
    list_print(list_remove_all(q2_4, 4));

    list_free(q2_1);
    list_free(q2_2);
    list_free(q2_3);
    list_free(q2_4);
}