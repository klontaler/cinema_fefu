#include "utilites.h"

void key_listener(char* k) {
        scanf("%s", k);
        *k = tolower(*k);
}

char login_validation(char* login) {
        int length = strlen(login);
        if (length < 3 && length > 20) {
                return 0;
        }
        for (int i = 0; i < length; i++) {
                if (!isalnum(login[i])) {
                        return 0;
                }
        }
        return 1;
}

char password_validation(char* password) {
        char upper = 0;
        char lower = 0;
        char digit = 0;
        int length = strlen(password);
        
        if (length < 6 && length > 20) {
                return 0;
        }
        for (int i = 0; i < length; i++) {
                if (!isalnum(password[i])) {
                        return 0;
                }
                if (isupper(password[i])) {
                        upper = 1;
                } else if (islower(password[i])) {
                        lower = 1;
                } else if (isdigit(password[i])) {
                        digit = 1;
                }
        }
        return 1;
}

char card_validation(char* card) {
        if (strlen(card) != 16) {
                return 0;
        }
        for (int i = 0; i < 16; i++) {
                if (!isdigit(card[i])) {
                        return 0;
                }
        }
        return 1;
}
