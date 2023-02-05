#ifndef SRC_GRAPH_H_
#define SRC_GRAPH_H_

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define SCALE 80

double parser_polish(char text1[255], double x, int* error);

double calc_parser(char text[255]);

#endif  // SRC_GRAPH_H_
