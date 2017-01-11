#include <stdio.h>
#include <stdlib.h>

typedef enum _State {
    S_START,
    S_A,
    S_AA,
    S_AAB,
    S_INVALID
} State;

#define S_END S_AAB

State dfa(State s, char *input) {
    if(*input == '\0' || *input == '\n') return s;

    if(s == S_END) return S_END;

    if (s == S_END) {
        return s;
    } else if(s == S_A) {
        if(*input == 'a') return dfa(S_AA, input+1);
        if(*input == 'b') return dfa(S_START, input+1);
    } else if(s == S_AA) {
        if(*input == 'a') return dfa(S_AA, input+1);
        if(*input == 'b') return dfa(S_AAB, input+1);
    } else {
        if(*input == 'a') return dfa(S_A, input+1);
        else if(*input == 'b') return dfa(S_START, input+1);
    }
    return S_INVALID;
}

int main(int argc, char *argv[]) {
    char buffer[1024];
    fgets(buffer, sizeof(buffer), stdin);
    State s = dfa(S_START, buffer);
    
    printf("The given string %s\n", s == S_END ? "matches" : "does not match");

    return EXIT_SUCCESS;
}
