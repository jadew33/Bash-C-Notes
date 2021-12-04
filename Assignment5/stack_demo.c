#include <stdio.h>
#include <stddef.h>
#include "stack.h"
#include "stack_utils.h"

void test_stack_reverse();
void test_stack_equals();

int main(void)
{
    test_stack_reverse();
    test_stack_equals();
}

void print_str(const void *s)
{
    printf("%s", (char *)s);
}

bool compare_str(const void *a, const void *b)
{
    return (char *)a == (char *)b;
}

void test_stack_reverse()
{
    stack *s1 = stack_init();

    stack *s2 = stack_init();
    stack_push(s2, "d");

    stack *s3 = stack_init();
    stack_push(s3, "a");
    stack_push(s3, "b");
    stack_push(s3, "c");

    // stack_print(s1, &print_str);
    // stack_print(s2, &print_str);
    stack_print(s3, &print_str);

    // stack_reverse(s1);
    // stack_reverse(s2);
    stack_reverse(s3);

    // stack_print(s1, &print_str);
    // stack_print(s2, &print_str);
    stack_print(s3, &print_str);

    stack_free(s1, NULL);
    stack_free(s2, NULL);
    stack_free(s3, NULL);
}

void test_stack_equals()
{
    stack *s1 = stack_init();
    stack_push(s1, "a");
    stack_push(s1, "b");
    stack_push(s1, "c");

    stack *s2 = stack_init();
    stack_push(s2, "a");
    stack_push(s2, "b");
    stack_push(s2, "c");

    stack *s3 = stack_init();
    stack_push(s3, "b");
    stack_push(s3, "a");
    stack_push(s3, "c");

    stack *s4 = stack_init();
    stack_push(s4, "d");

    stack *s5 = stack_init();
    stack_push(s5, "d");

    stack *s6 = stack_init();
    stack_push(s6, "e");

    stack *s7 = stack_init();

    stack *s8 = stack_init();

    printf("%s\n", stack_equals(s7, s8, &compare_str) ? "True" : "False"); // Empty
    printf("%s\n", stack_equals(s4, s5, &compare_str) ? "True" : "False"); // Size 1 ==
    printf("%s\n", stack_equals(s5, s6, &compare_str) ? "True" : "False"); // Size 1 !=
    printf("%s\n", stack_equals(s1, s2, &compare_str) ? "True" : "False"); // Size 3 ==
    printf("%s\n", stack_equals(s2, s3, &compare_str) ? "True" : "False"); // Size 3 !=

    stack_free(s1, NULL);
    stack_free(s2, NULL);
    stack_free(s3, NULL);
    stack_free(s4, NULL);
    stack_free(s5, NULL);
    stack_free(s6, NULL);
    stack_free(s7, NULL);
    stack_free(s8, NULL);
}