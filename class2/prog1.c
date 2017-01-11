#include <stdio.h>
#include <stdlib.h>

typedef enum _State {
    S_START,
    S_1,
    S_0,
    S_INVALID
} State;

#define S_END S_0

State dfa(State s, char *input) {
    if(*input == '\0' || *input == '\n') return s;

    if(*input == '1') return dfa(S_1, input+1);
    else if(*input == '0') return dfa(S_0, input+1);
    else return S_INVALID;
}

int main(int argc, char *argv[]) {
    char buffer[1024];
    fgets(buffer, sizeof(buffer), stdin);
    State s = dfa(S_START, buffer);
    
    if(s == S_INVALID) {
        printf("Invalid input\n");
    } else {
        printf("The given binary number is %s\n", s == S_END ? "even" : "odd");
    }

    return EXIT_SUCCESS;
}
