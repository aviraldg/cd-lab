/**
 * Write a recursive descent parser for:
 * S -> cAd
 * A -> ab | a
 *
 * S -> cAd
 * A -> aAp
 * Ap -> b | $
 */

 #include <stdio.h>
 #include <stdlib.h>

int match(char **input, char *test) {
    char *tmp = *input;
    while(**input == *test && *test != '\0') {
        (*input)++;
        test++;
    }
    if(*test != '\0')
        *input = tmp;
    return *test == '\0';
}

int Ap(char **);

int A(char **input) {
    return match(input, "a") && Ap(input);
}

int Ap(char **input) {
    return (match(input, "b") && Ap(input)) || 1;
}

int S(char **input) {
    return match(input, "c") && A(input) && match(input, "d");
}

char accept(char *input) {
    return S(&input) ? *input : '\0';
}

int main(int argc, char *argv[]) {
    char buffer[1024];
    fgets(buffer, sizeof(buffer), stdin);
    if(accept(buffer) == '\n') {
        puts("Input string matched.\n");
    } else {
        puts("Input string did not match.\n");
    }
    return EXIT_SUCCESS;
}
