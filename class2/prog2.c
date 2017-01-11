#include <stdio.h>
#include <stdlib.h>

typedef enum _State {
    S_START,
    S_A,
    S_B,
    S_INVALID
} State;

#define S_END S_A

State dfa(State s, char *input) {
    if(*input == '\0' || *input == '\n') return s;

    if(*input == 'a') return dfa(S_A, input+1);
    else if(*input == 'b') return dfa(S_B, input+1);
    else return S_INVALID;
}

int main(int argc, char *argv[]) {
    char buffer[1024];
    fgets(buffer, sizeof(buffer), stdin);
    State s = dfa(S_START, buffer);
    
    printf("The given string %s\n", s == S_END ? "matches" : "does not match");

    return EXIT_SUCCESS;
}
