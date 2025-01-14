// написать free для страктов
// разобраться с ебучим односвязным списком юзеров
#ifdef __STDC_ALLOC_LIB__
#define __STDC_WANT_LIB_EXT2__ 1
#else
#define _POSIX_C_SOURCE 200809L
#endif

#include "movies.h"
#include "print.h"
#include "utilites.h"
#include "pages.h"

int main() {
    FILE* movies_data = fopen("films.txt", "r");
    Movies_Node* movie_list = init_list(movies_data);
    fclose(movies_data);

    FILE* users_data = fopen("users.txt", "r");
    User_Node* users_list = init_user_list(users_data);

    FILE* favs_data = fopen("favorites.txt", "r");
    Movies_Node* favs_list = init_list(favs_data);
    fclose(favs_data);


    Movies_Node* current = movie_list;
    Movies_Node* current_fav = favs_list;
    char k;

    clear_screen();     

    char view_page;
    char life = 1;
    while (life) {
        char user_life = 1;
        char l_s = hello(&k);

        user* current_user = (user*) malloc(sizeof(user));
        switch (l_s) {
            case 'l':
                current_user = log_in(&k, users_list);
                break;
            case 's':
                current_user = sign_up(&k);
                push_user(&users_list, current_user);
                break;
        }

        char* username = current_user->login;

        while (user_life) {
            view_page = home(&k, username);
            switch (view_page) {
                case 'm':
                    list(&k, username, movie_list, favs_list);
                    break;
                case 'f':
                    favs(&k, username, favs_list);
                    break;
                case 'c':
                    printf("Goodbye!\n");
                    user_life = 0;
                    life = 0;
                    break;
            }
        }
    }

    favs_data = fopen("favorites.txt", "w");
    if (favs_list->data->name) {
        current = favs_list;
        char buffer[10];
        if (!strcmp(current->data->name, current->next->data->name)) {
            fprintf(favs_data,"%s\n", current->data->name);
            snprintf(buffer, 10, "%d", current->data->year);
            fprintf(favs_data, "%s\n", buffer);
            fprintf(favs_data, "%s\n", current->data->origin);
            fprintf(favs_data, "%s\n", current->data->genres);
            snprintf(buffer, 10, "%0.1f", current->data->rating);
            fprintf(favs_data, "%s", buffer);
        } else {
            fprintf(favs_data,"%s\n", current->data->name);
            snprintf(buffer, 10, "%d", current->data->year);
            fprintf(favs_data, "%s\n", buffer);
            fprintf(favs_data, "%s\n", current->data->origin);
            fprintf(favs_data, "%s\n", current->data->genres);
            snprintf(buffer, 10, "%0.1f", current->data->rating);
            fprintf(favs_data, "%s", buffer);
            current = current->next;

            while (strcmp(current->data->name, favs_list->data->name)) {
                fprintf(favs_data,"\n%s\n", current->data->name);
                snprintf(buffer, 10, "%d", current->data->year);
                fprintf(favs_data, "%s\n", buffer);
                fprintf(favs_data, "%s\n", current->data->origin);
                fprintf(favs_data, "%s\n", current->data->genres);
                snprintf(buffer, 10, "%0.1f", current->data->rating);
                fprintf(favs_data, "%s", buffer);
                current = current->next;
            }
        }
    }

    fclose(favs_data);

    users_data = fopen("users.txt", "w");
    if (users_list->data->login) {
        if (users_list != NULL) {
            char buffer[10];
            fprintf(users_data,"%s\n", users_list->data->login);
            fprintf(users_data,"%s\n", users_list->data->password);
            fprintf(users_data,"%s\n", users_list->data->card);
            snprintf(buffer, 10, "%d", users_list->data->fav_size);
            fprintf(users_data,"%s\n", buffer);
            snprintf(buffer, 10, "%d", users_list->data->is_admin);
            fprintf(users_data,"%s", buffer);
            users_list = users_list->next;

            while (users_list != NULL) {
                fprintf(users_data,"\n%s\n", users_list->data->login);
                fprintf(users_data,"%s\n", users_list->data->password);
                fprintf(users_data,"%s\n", users_list->data->card);
                snprintf(buffer, 10, "%d", users_list->data->fav_size);
                fprintf(users_data,"%s\n", buffer);
                snprintf(buffer, 10, "%d", users_list->data->is_admin);
                fprintf(users_data,"%s", buffer);
                users_list = users_list->next;
            }
        }
    }

    fclose(users_data);

    return 0;
}
