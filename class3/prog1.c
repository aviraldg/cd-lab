/**
 * Write a recursive descent parser for:
 * E -> E+T | T
 * T -> i
 *
 * E -> iEp
 * Ep -> +iEp | $
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

int Ep(char **);

int E(char **input) {
    return match(input, "i") && Ep(input);
}

int Ep(char **input) {
    return (match(input, "+i") && Ep(input)) || 1;
}

char accept(char *input) {
    return E(&input) ? *input : '\0';
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
