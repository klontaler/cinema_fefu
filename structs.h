#ifndef STRUCTS_H
#define STRUCTS_H

#include <stdio.h>

typedef struct Movies_Node Movies_Node;
typedef struct User_Node User_Node;

typedef struct {
    char* name;
    int year;
    char* origin;
    char* genres;
    float rating;
} movie;

struct Movies_Node {
    movie* data;
    Movies_Node* prev;
    Movies_Node* next;
};

typedef struct {
    char* login;
    char* password;
    char* card;
    int fav_size;
    char is_admin;
} user;

struct User_Node {
    user* data;
    User_Node* next;
};

void free_movie(movie* item);

void free_movie_Node(Movies_Node* item);

user* create_user(char* login, char* password, char* card);

void push_user(User_Node** list, user* data);

User_Node* init_user_list(FILE* data);


#endif