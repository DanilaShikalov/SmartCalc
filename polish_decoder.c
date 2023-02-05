#include "polish_decoder.h"
#include "stack.h"

void multi_if_else(struct stack_operations* stackOperations, struct stack_digits* stackDigits, int* error) {
    struct operation ope = pop_operation(stackOperations, error);
    if (ope.count == 2 && (*stackDigits).top >= 2) {
        double value1 = pop_digits(stackDigits, error);
        double value2 = pop_digits(stackDigits, error);
        if (ope.sign == MINUS_SIGN) {
            push_digits(stackDigits, value2 - value1);
        } else if (ope.sign == PLUS_SIGN) {
            push_digits(stackDigits, value1 + value2);
        } else if (ope.sign == DIVISION_SIGN) {
            push_digits(stackDigits, value2 / value1);
        } else if (ope.sign == MULTIPLICATION_SIGN) {
            push_digits(stackDigits, value1 * value2);
        } else if (ope.sign == MOD_SIGN) {
            push_digits(stackDigits, fmod(value2, value1));
        } else if (ope.sign == POW_SIGN) {
            push_digits(stackDigits, pow(value2, value1));
        } else {
            *error = 1;
        }
    } else if (ope.count == 1 && (*stackDigits).top >= 1) {
        double value = pop_digits(stackDigits, error);
        if (ope.sign == UNARY_MINUS_SIGN) {
            push_digits(stackDigits, -value);
        } else if (ope.sign == UNARY_SIN_SIGN) {
            push_digits(stackDigits, sin(value));
        } else if (ope.sign == UNARY_COS_SIGN) {
            push_digits(stackDigits, cos(value));
        } else if (ope.sign == UNARY_CTG_SIGN) {
            push_digits(stackDigits, 1 / tan(value));
        } else if (ope.sign == UNARY_LN_SIGN) {
            push_digits(stackDigits, log(value));
        } else if (ope.sign == UNARY_TAN_SIGN) {
            push_digits(stackDigits, tan(value));
        } else if (ope.sign == UNARY_SQRT_SIGN) {
            push_digits(stackDigits, sqrt(value));
        } else if (ope.sign == UNARY_PLUS_SIGN) {
            push_digits(stackDigits, value);
        } else if (ope.sign == UNARY_ACOS_SIGN) {
            push_digits(stackDigits, acos(value));
        } else if (ope.sign == UNARY_ASIN_SIGN) {
            push_digits(stackDigits, asin(value));
        } else if (ope.sign == UNARY_ATAN_SIGN) {
            push_digits(stackDigits, atan(value));
        } else if (ope.sign == UNARY_LOG_SIGN) {
            push_digits(stackDigits, log10(value));
        } else {
            *error = 1;
        }
    } else {
        *error = 1;
    }
}

void decoder(struct stack_digits *stackDigits, struct stack_operations *stackOperations,
        struct operation operation, int* error) {
    int result = 1;
    if ((*stackOperations).top == 0 || operation.priority == OPEN_BRACKET) {
        push_operation(stackOperations, operation);
        result = 0;
    }

    if (result && (*stackOperations).top > 0 &&
        (*stackOperations).operations[(*stackOperations).top - 1].priority <= operation.priority) {
        push_operation(stackOperations, operation);
        result = 0;
    }
    if (result) {
        while ((*stackOperations).top > 0 &&
               (*stackOperations).operations[(*stackOperations).top - 1].priority > operation.priority) {
            multi_if_else(stackOperations, stackDigits, error);
        }
        push_operation(stackOperations, operation);
    }
}

void decoder_close_bracket(struct stack_digits *stackDigits,
        struct stack_operations *stackOperations, int* error) {
    while ((*stackOperations).top > 0 &&
           (*stackOperations).operations[(*stackOperations).top - 1].priority != OPEN_BRACKET) {
        multi_if_else(stackOperations, stackDigits, error);
    }
    pop_operation(stackOperations, error);
}

void decoder_end(struct stack_digits *stackDigits, struct stack_operations *stackOperations, int* error) {
    multi_if_else(stackOperations, stackDigits, error);
}
