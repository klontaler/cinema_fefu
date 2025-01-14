#ifndef MOVIES_H
#define MOVIES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

movie* create_movie(FILE* data);

void add_item(Movies_Node* list, movie* item);

Movies_Node* delete_item(Movies_Node* list);

Movies_Node* init_list(FILE* data);

#endif