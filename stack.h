#ifndef SRC_STACK_H_
#define SRC_STACK_H_

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

enum priority {
    UNARY_MINUS = 5,
    UNARY_PLUS = 5,
    UNARY_SIN = 5,
    UNARY_COS = 5,
    UNARY_TAN = 5,
    UNARY_CTG = 5,
    UNARY_SQRT = 5,
    UNARY_LN = 5,
    UNARY_ACOS = 5,
    UNARY_ASIN = 5,
    UNARY_ATAN = 5,
    UNARY_LOG = 5,
    DIVISION = 4,
    MULTIPLICATION = 4,
    MOD = 4,
    POW = 4,
    MINUS = 3,
    PLUS = 3,
    OPEN_BRACKET = 2
};

enum sign {
    UNARY_MINUS_SIGN = 1,
    UNARY_SIN_SIGN = 2,
    UNARY_COS_SIGN = 3,
    UNARY_TAN_SIGN = 4,
    UNARY_CTG_SIGN = 5,
    UNARY_SQRT_SIGN = 6,
    UNARY_LN_SIGN = 7,
    DIVISION_SIGN = 8,
    MULTIPLICATION_SIGN = 9,
    MINUS_SIGN = 10,
    PLUS_SIGN = 11,
    UNARY_PLUS_SIGN = 12,
    UNARY_ACOS_SIGN = 13,
    UNARY_ASIN_SIGN = 14,
    UNARY_ATAN_SIGN = 15,
    UNARY_LOG_SIGN = 16,
    MOD_SIGN = 17,
    POW_SIGN = 18
};

struct stack_digits {
    double digits[MAX];
    int top;
};

void init_digits(struct stack_digits* stack);

void push_digits(struct stack_digits* stack, double value);

double pop_digits(struct stack_digits* stack, int* error);

struct operation {
    int priority;
    char operation[5];
    int count;
    int sign;
};

struct stack_operations {
    struct operation operations[MAX];
    int top;
};

void init_operation(struct stack_operations* stack);

void push_operation(struct stack_operations* stack, struct operation operation);

struct operation pop_operation(struct stack_operations* stack, int* error);

#endif  // SRC_STACK_H_
