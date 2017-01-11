#include <stdio.h>
#include <stdlib.h>

typedef enum _State {
    S_START,
    S_ODD,
    S_EVEN,
    S_INVALID
} State;

#define S_END S_ODD

State dfa(State s, char *input) {
    if(*input == '\0' || *input == '\n') return s;

    if(*input == '1') return dfa(s == S_ODD ? S_EVEN : S_ODD, input+1);
    else if(*input == '0') return dfa(s, input+1);
    else return S_INVALID;
}

int main(int argc, char *argv[]) {
    char buffer[1024];
    fgets(buffer, sizeof(buffer), stdin);
    State s = dfa(S_START, buffer);
    
    printf("The given string %s\n", s == S_END ? "matches" : "does not match");

    return EXIT_SUCCESS;
}
