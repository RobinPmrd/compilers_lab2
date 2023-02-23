#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NO_OF_STATES_IDENTIFIER 2
#define NO_OF_SYMBOLS_IDENTIFIER 3

int identifier_transitions[NO_OF_STATES_IDENTIFIER][NO_OF_SYMBOLS_IDENTIFIER];
char initial_keyword_letters[] = {'w','i','e','m','r'};
char other_letters_numbers[] = {'a','b','c','d','f','g','h','j','k','l','n','o','p','q','s','t','u','v','x','y','z',
                                'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
                                '0','1','2','3','4','5','6','7','8','9'};

// 0 represents other_letters_numbers i and 1 initial_keyword_letters 2 represents ' '
void initIdentifierTransitionTable()
{
    identifier_transitions[0][0] = 1; // from state 0, with " it goes to state 1
    identifier_transitions[0][1] = -1; // from state 0, with any character of alphabet, it goes to state 3 (empty state)
    identifier_transitions[0][2] = -1;
    identifier_transitions[1][0] = 1; // from state 1, with " it goes to state 2, the final state
    identifier_transitions[1][1] = 1; // from state 1, with any character of alphabet, it stays to state 1
    identifier_transitions[1][2] = 2;
}

/**
 * Check whether an array al contain c
*/
int contains3(char al[], char c) {
    for (int i = 0; i < strlen(al); i++)
    {
        if (al[i] == c) return 1;
    }
    return 0;
}

int getIdentifierNextState(int currentState, char symbol)
{
    int symbolIndex;

    if (contains3(initial_keyword_letters, symbol))
    {
        symbolIndex = 1; // 1 represents any character from alphabet
    }
    else if (contains3(other_letters_numbers, symbol))
    {
        symbolIndex = 0; // 0 represents "
    }
    else if (symbol == ' ') {
        symbolIndex = 2;
    }
    else
    {
        return -1;
    }

    return identifier_transitions[currentState][symbolIndex];
}