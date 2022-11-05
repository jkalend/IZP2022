#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int check_number(const char *number) {
    char *check = NULL;
    if (*number == '0' && strlen(number) == 1) {
        return 0;
    }
    strtoull(number, &check, 10);
    if (*check != '\0') {
        return 1;
    }

    return 0;
}

void check_correct(const char *search, const char *name, const char *number, int *print) {
    char check[202] = {0};
    strncpy(check, name, 201);
    strncat(check, " ", 201);
    strncat(check, number, 201);
    unsigned long length = strlen(check);

    for (int i = 0; i < length; i++) {
        check[i] = (char) tolower(check[i]);
        switch (check[i]) {
        case 'a': case 'b': case 'c':
            check[i] = '2';
            break;
        case 'd': case 'e': case 'f':
            check[i] = '3';
            break;
        case 'g': case 'h': case 'i':
            check[i] = '4';
            break;
        case 'j': case 'k': case 'l':
            check[i] = '5';
            break;
        case 'm': case 'n': case 'o':
            check[i] = '6';
            break;
        case 'p': case 'q': case 'r': case 's':
            check[i] = '7';
            break;
        case 't': case 'u': case 'v':
            check[i] = '8';
            break;
        case 'w': case 'x': case 'y': case 'z':
            check[i] = '9';
            break;
        case '+':
            check[i] = '0';
            break;
        default:
            break;
        }
    }

    if (strstr(check, search) != NULL) {
        printf("%s, %s\n", name, number);
        *print = 1;
    }
}

int main(int argc, char *argv[]) {
    int all = 0;
    if (argc > 2) {
        fprintf(stderr, "Usage: ./a.out [number]\n");
        return 1;
    } else if (argc == 1) {
        all = 1;
    } else {
        if (check_number(argv[1]) != 0) {
            fprintf(stderr, "Usage: ./a.out <number>\n");
            return 1;
        }
    }

    int print = 0;
    char line[102] = {0};
    char contact[102] = {0};
    while (fgets(line, 102, stdin) != NULL) {
        if (isspace(line[0])) {
            continue;
        }
        if (line[100] != '\n' && strlen(line) == 101) {
            fprintf(stderr, "Error: Contact is too long\n");
            return 1;
        }
        line[strlen(line) - 1] = 0;

        if (contact[0] == 0) {
            strncpy(contact, line, 101);
        } else {
            if (all) {
                printf("%s, %s\n", contact, line);
                print = 1;
                contact[0] = 0;
            } else {
                check_correct(argv[1], contact, line, &print);
                contact[0] = 0;
            }
        }
    }
    if (!print) {
        printf("Not found\n");
    }
    return 0;
}
