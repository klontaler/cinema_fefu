#include "structs.h"
#include <stdlib.h>
#include <string.h>

void free_movie(movie* item) {
    free(item->name);
    free(item->origin);
    free(item->genres);
    free(item);
}

void free_movie_Node(Movies_Node* item) {
    free_movie(item->data);
    free(item);
}

user* create_user(char* login, char* password, char* card) {
    user* temp = (user*) malloc(sizeof(user));
    temp->login = login;
    temp->password = password;
    temp->card = card;
    temp->fav_size = 0;
    temp->is_admin = 0;
    return temp;
}

void push_user(User_Node** list, user* data) {
    User_Node* temp = (User_Node*) malloc(sizeof(User_Node));
    temp->data = data;
    temp->next = NULL;

    if (*list == NULL) {
        *list = temp;
    } else {
        User_Node* current = *list;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = temp;
    }

}

User_Node* init_user_list(FILE* data) {
    User_Node* list = NULL;
    while (!feof(data)) {
        char buffer[100];

        user* item = create_user(NULL, NULL, NULL);
        if (fgets(buffer, sizeof(buffer), data) != 0) {
            buffer[strcspn(buffer, "\n")] = '\0';
            item->login = strdup(buffer);
        }
        if (fgets(buffer, sizeof(buffer), data) != 0) {
            buffer[strcspn(buffer, "\n")] = '\0';
            item->password = strdup(buffer);
        }
        if (fgets(buffer, sizeof(buffer), data) != 0) {
            buffer[strcspn(buffer, "\n")] = '\0';
            item->card = strdup(buffer);
        }
        if (item->login) {
            push_user(&list, item);
        }
    }

    return list;
}
