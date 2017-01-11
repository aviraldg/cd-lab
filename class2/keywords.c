#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool int
#define true 1
#define false 0

char *keywords[] = {
    "auto",
    "break",
    "case",
    "char",
    "const",
    "continue",
    "default",
    "do",
    "double",
    "else",
    "enum",
    "extern",
    "float",
    "for",
    "goto",
    "if",
    "int",
    "long",
    "register",
    "return",
    "short",
    "signed",
    "sizeof",
    "static",
    "struct",
    "switch",
    "typedef",
    "union",
    "unsigned",
    "void",
    "volatile",
    "while"
};

int kw_count = sizeof(keywords)/sizeof(char *);

#define SEPARATORS (",; \t()=+-\\/{}[]*;")

bool is_keyword(char *token) {
    for(int i=0; i<kw_count; i++) {
        if(strcmp(token, keywords[i]) == 0) {
            return true;
        }
    }

    return false;
}

int main(int argc, char *argv[]) {
    FILE *input = fopen(argv[1], "r");
    fseek(input, 0, SEEK_END);
    size_t size = ftell(input);
    char *buffer = malloc(sizeof(char) * size);
    fseek(input, 0, SEEK_SET);
    fread(buffer, size, 1, input);

    int token_count = 0;

    for(char *token = strtok(buffer, SEPARATORS); token != NULL; token = strtok(NULL, SEPARATORS)) {
        if(is_keyword(token)) {
            printf("Found token: %s\n", token);
            token_count++;
        }
    }

    printf("Found a total of %d tokens.\n", token_count);

    fclose(input);

    return EXIT_SUCCESS;
}
