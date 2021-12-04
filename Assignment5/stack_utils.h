#ifndef STACK_UTILS_H
#define STACK_UTILS_H

typedef bool (*compare_equals_function)(const void *elem, const void *elem2);

void stack_reverse(struct stack *s);

bool stack_equals(const stack *s, const stack *t, compare_equals_function comp_stack);

#endif 