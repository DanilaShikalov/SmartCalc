#include "graph.h"
#include "polish_decoder.h"

void field_paint(char text1[255]);

//int main() {
//    char text1[255] = "atan(acos(asin(log(sqrt(2)))))";
//    printf("%lf\n", calc_parser(text1));
//    printf("%lf", atan(acos(asin(log10(sqrt(2))))));
//    return 0;
//}

void field_paint(char text1[255]) {
    double pi = 3.14159;
    double oX = 4 * pi / (SCALE - 1);
    double x = 0;
    int error = 0;
    int c = 0;
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < SCALE; x += oX, j++) {
            if (!error) {
                c = (int) round(12 * (1 - parser_polish(text1, x, &error)));
            }
            if (i == c && !error) {
                printf("*");
            } else if (!error) {
                printf(".");
            }
            if ((j == (SCALE - 1)) && (i < 24) && !error) {
                x = 0;
                printf("\n");
            }
        }
    }
    if (error == 1) {
        printf("FAILED");
    }
}

double calc_parser(char text[255]) {
    int error = 0;
    int x = 0;
    return parser_polish(text, x, &error);
}

void init_operation_struct(struct operation *operation, char name[20], int count, int priority, int sign) {
    strcpy((*operation).operation, name);
    (*operation).priority = priority;
    (*operation).count = count;
    (*operation).sign = sign;
}

void check_oper(char word[20], struct stack_operations *stackOperations,
        struct stack_digits *stackDigits, int* error, int* unary_minus, int* unary_plus) {
    if (strlen(word) == 1 && word[0] == '/') {
        struct operation operation;
        init_operation_struct(&operation, word, 2, DIVISION, DIVISION_SIGN);
        decoder(stackDigits, stackOperations, operation, error);
        *unary_minus = 1;
        *unary_plus = 1;
    } else if (strlen(word) == 1 && word[0] == '*') {
        struct operation operation;
        init_operation_struct(&operation, word, 2, MULTIPLICATION, MULTIPLICATION_SIGN);
        decoder(stackDigits, stackOperations, operation, error);
        *unary_minus = 1;
        *unary_plus = 1;
    } else if (strlen(word) == 1 && word[0] == '^') {
        struct operation operation;
        init_operation_struct(&operation, word, 2, POW, POW_SIGN);
        decoder(stackDigits, stackOperations, operation, error);
        *unary_minus = 1;
        *unary_plus = 1;
    } else if (strlen(word) == 3 && word[0] == 'm' && word[1] == 'o' && word[2] == 'd') {
        struct operation operation;
        init_operation_struct(&operation, word, 2, MOD, MOD_SIGN);
        decoder(stackDigits, stackOperations, operation, error);
        *unary_minus = 1;
        *unary_plus = 1;
    } else if (strlen(word) == 1 && word[0] == '-') {
        struct operation operation;
        if (*unary_minus == 1) {
            init_operation_struct(&operation, word, 1, UNARY_MINUS, UNARY_MINUS_SIGN);
            decoder(stackDigits, stackOperations, operation, error);
            *unary_minus = 1;
            *unary_plus = 1;
        } else if (*unary_minus == 0) {
            init_operation_struct(&operation, word, 2, MINUS, MINUS_SIGN);
            decoder(stackDigits, stackOperations, operation, error);
            *unary_minus = 1;
            *unary_plus = 1;
        }
    } else if (strlen(word) == 1 && word[0] == '+') {
        struct operation operation;
        if (*unary_plus == 1) {
            init_operation_struct(&operation, word, 1, UNARY_PLUS,UNARY_PLUS_SIGN);
            decoder(stackDigits, stackOperations, operation, error);
            *unary_minus = 1;
            *unary_plus = 1;
        } else if (*unary_plus == 0) {
            init_operation_struct(&operation, word, 2, PLUS, PLUS_SIGN);
            decoder(stackDigits, stackOperations, operation, error);
            *unary_minus = 1;
            *unary_plus = 1;
        }
    } else {
        *error = 1;
    }
}

void check_oper_unary(char word[20], struct stack_operations *stackOperations,
        struct stack_digits *stackDigits, int* error) {
    struct operation operation;
    if (strlen(word) == 3 && word[0] == 'c' && word[1] == 'o' && word[2] == 's') {
        init_operation_struct(&operation, word, 1, UNARY_COS, UNARY_COS_SIGN);
        decoder(stackDigits, stackOperations, operation, error);
    } else if (strlen(word) == 3 && word[0] == 's' && word[1] == 'i' && word[2] == 'n') {
        init_operation_struct(&operation, word, 1, UNARY_SIN, UNARY_SIN_SIGN);
        decoder(stackDigits, stackOperations, operation, error);
    } else if (strlen(word) == 3 && word[0] == 't' && word[1] == 'a' && word[2] == 'n') {
        init_operation_struct(&operation, word, 1, UNARY_TAN, UNARY_TAN_SIGN);
        decoder(stackDigits, stackOperations, operation, error);
    } else if (strlen(word) == 3 && word[0] == 'c' && word[1] == 't' && word[2] == 'g') {
        init_operation_struct(&operation, word, 1, UNARY_CTG, UNARY_CTG_SIGN);
        decoder(stackDigits, stackOperations, operation, error);
    } else if (strlen(word) == 4 && word[0] == 's' && word[1] == 'q' && word[2] == 'r' && word[3] == 't') {
        init_operation_struct(&operation, word, 1, UNARY_SQRT, UNARY_SQRT_SIGN);
        decoder(stackDigits, stackOperations, operation, error);
    } else if (strlen(word) == 2 && word[0] == 'l' && word[1] == 'n') {
        init_operation_struct(&operation, word, 1, UNARY_LN, UNARY_LN_SIGN);
        decoder(stackDigits, stackOperations, operation, error);
    } else if (strlen(word) == 4 && word[0] == 'a' && word[1] == 'c' && word[2] == 'o' && word[3] == 's') {
        init_operation_struct(&operation, word, 1, UNARY_ACOS, UNARY_ACOS_SIGN);
        decoder(stackDigits, stackOperations, operation, error);
    } else if (strlen(word) == 4 && word[0] == 'a' && word[1] == 's' && word[2] == 'i' && word[3] == 'n') {
        init_operation_struct(&operation, word, 1, UNARY_ASIN, UNARY_ASIN_SIGN);
        decoder(stackDigits, stackOperations, operation, error);
    } else if (strlen(word) == 4 && word[0] == 'a' && word[1] == 't' && word[2] == 'a' && word[3] == 'n') {
        init_operation_struct(&operation, word, 1, UNARY_ATAN, UNARY_ATAN_SIGN);
        decoder(stackDigits, stackOperations, operation, error);
    } else if (strlen(word) == 3 && word[0] == 'l' && word[1] == 'o' && word[2] == 'g') {
        init_operation_struct(&operation, word, 1, UNARY_LOG, UNARY_LOG_SIGN);
        decoder(stackDigits, stackOperations, operation, error);
    } else {
        *error = 1;
    }
}

void iterator_polish(int* flag, char** start, struct stack_operations *stackOperations,
        struct stack_digits *stackDigits, double x, int* error) {
    char word[20] = {0};
    int unary_minus = 1;
    int unary_plus = 1;
    while (*flag && **start != '\n' && strlen(*start) != 0) {
        if (*flag && sscanf(*start, "%10[0-9]", word)) {
            double digit = atof(word);
            push_digits(stackDigits, digit);
            unary_minus = 0;
        } else if (*flag && sscanf(*start, "%1[/-+*^]", word)) {
            check_oper(word, stackOperations, stackDigits, error, &unary_minus, &unary_plus);
        } else if (*flag && sscanf(*start, "%3[mod]", word)) {
            check_oper(word, stackOperations, stackDigits, error, &unary_minus, &unary_plus);
        } else if (*flag && sscanf(*start, "%10[x]", word)) {
            if (strlen(word) == 1 && word[0] == 'x') {
                push_digits(stackDigits, x);
                unary_minus = 0;
            } else {
                flag = 0;
            }
        } else if (*flag && sscanf(*start, "%1[)]", word)) {
            decoder_close_bracket(stackDigits, stackOperations, error);
            unary_minus = 0;
        } else if (*flag && sscanf(*start, "%1[(]", word)) {
            struct operation operation;
            init_operation_struct(&operation, word, -1, OPEN_BRACKET, OPEN_BRACKET);
            decoder(stackDigits, stackOperations, operation, error);
            unary_minus = 1;
        } else if (*flag && sscanf(*start, "%10[cosintangqrln]", word)) {
            check_oper_unary(word, stackOperations, stackDigits, error);
            unary_minus = 0;
        } else {
            *error = 1;
            *flag = 0;
        }
        *start += strlen(word);
        memset(word, 0, strlen(word));
    }
}

double parser_polish(char text1[255], double x, int* error) {
    char text[255] = {0}, *start_t = text;
    for (size_t i = 0; i < strlen(text1); i++) {
        if (text1[i] != ' ') {
            *start_t = text1[i];
            start_t++;
        }
    }
    char *start = text;
    int flag = 1;
    struct stack_digits stackDigits;
    init_digits(&stackDigits);
    struct stack_operations stackOperations;
    init_operation(&stackOperations);
    iterator_polish(&flag, &start, &stackOperations, &stackDigits, x, error);
    while (stackOperations.top > 0) {
        decoder_end(&stackDigits, &stackOperations, error);
    }
    if (stackDigits.top > 1) {
        *error = 1;
    }
    return pop_digits(&stackDigits, error);
}
