#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "stack_utils.h"

void stack_reverse(struct stack *s)
{
    // node *m = s->top;
    node *n = s->top;
    node *o = n->next;
    int count = 0;

    while (n)
    {
        // n = s->top;
        // if (o)
        // {
        //     s->top = o->elem;
        // }

        // o = n->next;
        // printf("Iteration: %d\n", count);
        // printf("m after ress: %s", (char *)m->elem);
        // printf("stack top is %s\n", (char *)s->top->elem);
        // printf("n is %s\n", (char *)n->elem);
        // if (o)
        //     printf("o is %s\n", (char *)o->elem);
        // else
        //     puts("false o dne");
        s->top = o;
        // s->top->next = n;
        o = n;
    //    printf("top after reassignment is %s\n", (char *)s->top->elem);
        // printf("o after ress: %s", (char *)o->elem);
        count++;
        n = n->next;
        o = o->next;
    }
}

/** 
 * Returns 1 if true, 0 if false. First checks size, then iterates through stack
 * to see if the 2 elements of different stacks are equal.
 */
bool stack_equals(const stack *s, const stack *t, compare_equals_function compare)
{
    if (stack_size(s) != stack_size(t))
        return false;
    node *t1 = s->top;
    node *t2 = t->top;
    int count = 0;
    while (t1 && t2)
    {
        if (!compare(t1->elem, t2->elem))
            return false;
        t1 = t1->next;
        t2 = t2->next;
    }
    return true;
}
