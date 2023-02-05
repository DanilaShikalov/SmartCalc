#ifndef SRC_POLISH_DECODER_H_
#define SRC_POLISH_DECODER_H_

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

void decoder(struct stack_digits* stackDigits, struct stack_operations* stackOperations,
        struct operation operation, int* error);

void decoder_end(struct stack_digits* stackDigits, struct stack_operations* stackOperations, int* error);

void decoder_close_bracket(struct stack_digits *stackDigits,
        struct stack_operations *stackOperations, int* error);

void init_operation_struct(struct operation* operation, char name[20], int count, int priority, int sign);

#endif  // SRC_POLISH_DECODER_H_
