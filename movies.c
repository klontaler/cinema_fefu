#include "movies.h"

movie* create_movie(FILE* data) {
    movie* item = (movie*) malloc(sizeof(movie));
    char buffer[100];
    
    if (fgets(buffer, sizeof(buffer), data) != 0) {
        buffer[strcspn(buffer, "\n")] = '\0';
        item->name = strdup(buffer);
    } else {
        item->name = NULL;
    }

    if (fgets(buffer, sizeof(buffer), data) != 0) {
        item->year = atoi(buffer);
    } else {
        item->year = 0;
    }

    if (fgets(buffer, sizeof(buffer), data) != 0) {
        buffer[strcspn(buffer, "\n")] = '\0';
        item->origin = strdup(buffer);
    } else {
        item->origin = NULL;
    }

    if (fgets(buffer, sizeof(buffer), data) != 0) {
        buffer[strcspn(buffer, "\n")] = '\0';
        item->genres = strdup(buffer);
    } else {
        item->genres = NULL;
    }

    if (fgets(buffer, sizeof(buffer), data) != 0) {
        item->rating = atof(buffer);
    } else {
        item->rating = 0.0f;
    }

    return item;
}

void add_item(Movies_Node* list, movie* item) {
    if (list->data->name == NULL) {
        list->data = item;
    } else {
        Movies_Node *temp, *a;
        temp = (Movies_Node*) malloc(sizeof(Movies_Node));
        a = list->next;

        temp->data = item;

        temp->prev = list->prev;
        list->prev->next = temp;
        list->prev = temp;
        temp->next = list;
    }
}

// not ok
Movies_Node* delete_item(Movies_Node* list) {
    if (!strcmp(list->next->data->name, list->data->name)) {
        free_movie(list->data);
        return list;
    } else {
        Movies_Node* next = list->next;

        list->prev->next = next;
        next->prev = list->prev;
        
        *list = *next;
        return list;
    }
}

Movies_Node* init_list(FILE* data) {
    Movies_Node *temp;
    temp = (Movies_Node*) malloc(sizeof(Movies_Node));
    temp->data = create_movie(data);
    temp->prev = temp;
    temp->next = temp;

    while (!feof(data)) {
        add_item(temp, create_movie(data));
    }

    return(temp);
}