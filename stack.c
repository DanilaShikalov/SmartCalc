#include "stack.h"

void init_digits(struct stack_digits* stack) {
    (*stack).top = 0;
}

void push_digits(struct stack_digits* stack, double value) {
    if ((*stack).top < MAX) {
        (*stack).digits[(*stack).top] = value;
        (*stack).top++;
    }
}

double pop_digits(struct stack_digits* stack, int* error) {
    double number = 0;
    if ((*stack).top > 0) {
        (*stack).top--;
        number = (*stack).digits[(*stack).top];
    } else {
        *error = 1;
    }
    if (*error) {
        number = 0;
    }
    return number;
}

void init_operation(struct stack_operations* stack) {
    (*stack).top = 0;
}

void push_operation(struct stack_operations* stack, struct operation operation) {
    if ((*stack).top < MAX) {
        (*stack).operations[(*stack).top] = operation;
        (*stack).top++;
    }
}

struct operation pop_operation(struct stack_operations* stack, int* error) {
    struct operation operation;
    if ((*stack).top > 0) {
        (*stack).top--;
        operation = (*stack).operations[(*stack).top];
    } else {
        *error = 1;
    }
    if (*error) {
        operation = (struct operation) {0, {0}, 0, 0};
    }
    return operation;
}
