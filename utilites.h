#ifndef UTILITIES_H
#define UTILITIES_H

#include <stdio.h>
#include <ctype.h>
#include <string.h>

void key_listener(char* k);
char login_validation(char* login);
char password_validation(char* password);
char card_validation(char* card);

#endif