#ifndef PAGES_H
#define PAGES_H

#include "structs.h"
#include "print.h"
#include "movies.h"
#include "utilites.h"

char hello(char* k);

user* sign_up(char* k);

user* log_in(char* k, User_Node* users_list);

char home(char* k, char* username);

void list(char* k, char* username, Movies_Node* a, Movies_Node* favs);

void more(char* k, char* username, Movies_Node* a, Movies_Node* favs);

void favs(char* k, char* username, Movies_Node* a);

void null_list(char* k, char* username, Movies_Node* a);
#endif