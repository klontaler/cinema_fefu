#ifndef PRINT_H
#define PRINT_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "structs.h"

int shitty_str(char* ch);

void clear_screen();

void print_hello();

void print_movielist(Movies_Node* a);

void print_more(Movies_Node* a);

void print_help(char mode);

void print_header(char* username);

#endif