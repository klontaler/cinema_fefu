#include "print.h"

static char* SPACE = "      ";

int shitty_str(char* str) {
    int length = strlen(str)%2 + strlen(str)/2 + 3;
    int spaces = 0;
    int shit = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isspace(str[i])) {
            spaces++;
        } else if (ispunct(str[i])) {
            shit++;
        }    
    }


    return length + spaces/2 + shit/2 + shit%2;
}

void clear_screen() {
    printf("\033[H\033[J");
}


void print_hello() {
    
}

void print_movielist(Movies_Node* a) {
    int len_l, len_m, len_r;
    len_l = shitty_str(a->prev->data->name);
    len_m = shitty_str(a->data->name);
    len_r = shitty_str(a->next->data->name);


    char l[len_l], m[len_m], r[len_r];

    for (int i = 0; i<len_l-1; i++) {
        l[i] = ' ';
    }
    l[len_l] = '\0';
    for (int i = 0; i<len_m-1; i++) {
        m[i] = ' ';
    }
    m[len_m] = '\0';
    for (int i = 0; i<len_r-1; i++) {
        r[i] = ' ';
    }
    r[len_r] = '\0';

    printf("\u250C%s\u2510%s\u2554%s\u2557%s\u250C%s\u2510\n", l, SPACE, m, SPACE, r);
    printf("\u2502 %s \u2502%s\u2551 %s \u2551%s\u2502 %s \u2502\n", a->prev->data->name, SPACE, a->data->name, SPACE, a->next->data->name);
    printf("\u2514%s\u2518%s\u255A%s\u255D%s\u2514%s\u2518\n", l, SPACE, m, SPACE, r);

}

void print_more(Movies_Node* a) {
    movie* item = a->data;

    int l_name = shitty_str(item->name);
    int l_origin= shitty_str(item->origin);
    int l_genres = shitty_str(item->genres);
    int len;
    if (l_name>=l_origin && l_name>=l_genres) {
        len = l_name;
    } else if (l_origin >=l_genres) {
        len = l_origin;
    } else {
        len = l_genres;
    }

    char spaces[len];
    for (int i = 0; i<len-1; i++) {
        spaces[i] = ' ';
    }
    spaces[len - 1] = '\0';

    printf("\u2551 %s \u2551\n", spaces);
    printf("\u2551 %s\n", item->name);
    printf("\u2551 %d\n", item->year);
    printf("\u2551 %s\n", item->origin);
    printf("\u2551 %s\n", item->genres);
    printf("\u2551 %0.1f\n", item->rating);
    printf("\u2551 %s \u2551\n", spaces);

}

void print_help(char mode) {
    switch (mode)
    {
    case '1':
        printf("l - log in, s - sign up\n");
        break;
    case 'h':
        printf("m - movies, f - favorites, c - close\n");
        break;
    case 'l':
        printf("a - prev, d - next, f - fav, w - open, b - back\n");
        break;
    case 'm':
        printf("f - fav, u - unfav, b - back\n");
        break;
    case 'f':
        printf("a - prev, d - next, u - unfav, w - open, b - back\n");
        break;
    case 'b':
        printf("b - back\n");
        break;
    }
}

void print_header(char* username) {
    printf("текущий аккаунт - %s\n\n", username);
}