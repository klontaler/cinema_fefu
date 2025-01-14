#include "pages.h"

char hello(char* k) {
    char life = 1;
    char choice;
    do {
        printf("Привет!\n");
        print_help('1');
        key_listener(k);
        switch (*k){
            case 'l':
                choice = 'l';
                life = 0;
                break;
            case 's':
                choice = 's';
                life = 0;
                break;
            default:
                print_help('1');
                break;
        }
    } while (life);
    return choice;
}

// second login check 
// выход
user* sign_up(char* k) {
    user* item = (user*) malloc(sizeof(user));
    char* login = (char*)malloc(25 * sizeof(char));
    char* password = (char*)malloc(25 * sizeof(char));
    char* card = (char*)malloc(20 * sizeof(char)); 

    do {
        printf("Придумайте логин: ");
        scanf("%s", login);
    } while (!login_validation(login));
    clear_screen();

    do {    
        printf("Придумайте пароль: ");
        scanf("%s", password);
    } while (!password_validation(password));
    clear_screen();

    do {
        printf("Введите номер своей карты: ");
        scanf("%s", card);
    } while (!card_validation(card));
    clear_screen();

    item = create_user(login, password, card);
    return item;
}

// выход
user* log_in(char* k, User_Node* users_list) {
    char is_login = 0;
    char is_password = 0;

    user* item = (user*) malloc(sizeof(user));
    char* login = (char*)malloc(25 * sizeof(char));
    char* password = (char*)malloc(25 * sizeof(char));
    char* card = (char*)malloc(20 * sizeof(char)); 

    while (!is_login) {
        printf("Введите логин: ");
        scanf("%s", login);
        clear_screen();
        User_Node* current = users_list;
        while (current != NULL) {
            if (strcmp(login, current->data->login)) {
                is_login = 1;
                item = current->data;
                break;
            } else {
                current= current->next;
            }
        }
    }

    while (!is_password) {
        printf("Введите пароль: ");
        scanf("%s", password);
        clear_screen();
        User_Node* current = users_list;
        if (strcmp(password, item->password)) {
            is_password = 1;
        }
    }

    return item;
}

char home(char* k, char* username) {
    char choice;
    char life = 1;
    clear_screen();
    print_header(username);
    print_help('h');
    do {
        key_listener(k);
        switch (*k) {
        case 'm':
            choice = 'm';
            life = 0;
            break;
        case 'f':
            choice = 'f';
            life = 0;
            break;
        case 'c':
            choice = 'c';
            life = 0;
            break;
        default:
            print_help('h');
            break;
        }
    } while (life);
    return choice;
}

// unfav
void more(char* k, char* username, Movies_Node* a, Movies_Node* favs) {
    char life = 1;
    clear_screen();
    print_header(username);
    print_more(a);
    print_help('m');
    while (life) {
        key_listener(k);

        switch (*k) {
            case 'f':
                add_item(favs, a->data);
                clear_screen();
                print_header(username);
                print_more(a);
                printf("Successfully added to favorites!\n\n");
                print_help('m');
                break;
            case 'u':
                break;
            case 'b':
                life = 0;
                break;
            
            default:
                print_help('m');
                break;
        }
    }
}

void list(char* k, char* username, Movies_Node* a, Movies_Node* favs) {
    char life = 1;
    clear_screen();
    print_header(username);
    print_movielist(a);
    print_help('l');

    do {
        key_listener(k);
        switch (*k) {
            case 'a':
                clear_screen();
                print_header(username);
                a = a->prev;
                print_movielist(a);
                print_help('l');
                break;
            case 'd':
                clear_screen();
                print_header(username);
                a = a->next;
                print_movielist(a);
                print_help('l');
                break;
            case 'w':
                more(k, username, a, favs);
                clear_screen();
                print_header(username);
                print_movielist(a);
                print_help('l');
                break;
            case 'f':
                add_item(favs, a->data);
                clear_screen();
                print_header(username);
                print_movielist(a);
                printf("Successfully added to favorites!\n\n");
                print_help('l');
                break;
            case 'b':
                life = 0;
                break;
            default:
                print_help('l');
                break;
        }
    } while (life);
}

void favs(char* k, char* username, Movies_Node* a) {
    char life = 1;
    clear_screen();
    if (a->data->name == NULL) {
        while (life) {
            clear_screen();
            print_header(username);
            printf("В вашем избранном пока ничего нет :(\n");
            print_help('b');
            key_listener(k);
            if (*k == 'b') {
                life = 0;
            }
        }
    } else {
        print_header(username);
        print_movielist(a);
        print_help('f');
            do {
                key_listener(k);
                switch (*k) {
                case 'a':
                    clear_screen();
                    print_header(username);
                    a = a->prev;
                    print_movielist(a);
                    print_help('f');
                    break;
                case 'd':
                    clear_screen();
                    print_header(username);
                    a = a->next;
                    print_movielist(a);
                    print_help('f');
                    break;
                case 'w':
                    more(k, username, a, a);
                    clear_screen();
                    print_header(username);
                    print_movielist(a);
                    print_help('f');
                    break;
                case 'u':
                    delete_item(a);
                    if (a->data->name == NULL) {
                        while (life) {
                            clear_screen();    
                            print_header(username);
                            printf("В вашем избранном теперь ничего нет :(\n");
                            print_help('b');
                            key_listener(k);
                            if (*k == 'b') {
                                life = 0;
                            }
                        }
                    } else {
                        clear_screen();   
                        print_header(username);
                        print_movielist(a);
                        print_help('f');
                    }
                    break;
                case 'b':
                    life = 0;
                    break;
                default:
                    print_help('f');
                    break;
                }
            } while (life);

    }
}
