#include <stdio.h>
#include <stdlib.h>

#include <ctype.h>
#include <string.h>


static int const LOWER_TO_UPPER_DIFF = 'a' - 'A';


static void permutate(char *word, int len, int index);

static void make_lower(char *word);

static void usage();


static void permutate(char *word, int len, int index) {
    if(index == len) {
        fprintf(stdout, "%s\n", word);
        fflush(stdout);
        return;
    }

    //Move to next letter if lowercase, or not letter
    permutate(word, len, index + 1);
    if(!isalpha(word[index])) {
        return;
    }

    //Make uppercase and move to next letter again
    word[index] -= LOWER_TO_UPPER_DIFF;
    permutate(word, len, index + 1);
    word[index] += LOWER_TO_UPPER_DIFF;
}

static void make_lower(char *word) {
    int len = strlen(word);
    int index;

    for(index = 0; index < len; index++) {
        if((!isalpha(word[index])) || (word[index] >= 'a')) {
            continue;
        } 
        word[index] = word[index] + LOWER_TO_UPPER_DIFF;
    }
}

static void usage(char **argv) {
    fprintf(stdout, "Usage: %s <word>\n", argv[0]);
    fflush(stdout);
}


int main(int narg, char **argv) {
    if(narg != 2) {
        usage(argv);
        return 1;
    }

    char word[strlen(argv[1])];
    strcpy(word, argv[1]);
    
    make_lower(word);
    permutate(word, strlen(word), 0);

    return 0;
}