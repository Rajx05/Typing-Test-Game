#include <stdio.h>
#include <stdlib.h>
#include <Python.h>
#include "interface_py.h"

/* 
    - A demonstration of how to use interface_py header file.
    - Python interpreter initialization is must before calling any interface_py function.
    - Don't forget to finalize the interpreter at the end.

    Note:
        - When calling inpy_fetch_sentences,
            memory for pointers to sentences(char*) should be allocated beforehand,
            because the number of sentences is fixed.
        - When calling inpy_fetch_leaderboard,
            memory management will be done internally because
            the size of leaderboard is dynamic.
*/

int main() {
    /* Initialize the Python interpreter */
    Py_Initialize();

    /* Example call to inpy_fetch_sentences() */
    printf("Fetching sentences...\n\n");
    char **p_sentences = malloc(sizeof(char*) * NO_ROUNDS);
    if(inpy_fetch_sentences(p_sentences) != err_success) {
        /* Sentence fetching failed, maybe exit() */
        exit(1);
    }
    int i = 0;
    while(i < NO_ROUNDS) {
        printf("%s", p_sentences[i]);
        i++;
    }

    /* Example call to inpy_upload_score() */
    printf("\nUploading score..\n\n");
    player thor = {"thor", 45};
    printf("%d\n", inpy_upload_score(thor)); /* Output of 0 will indicate err_success*/

    /* Example call to inpy_fetch_leaderboard() */
    printf("\nPrinting leaderboard..\n\n");
    player *p_players = NULL;
    size_t num_players_read = 0;
    inpy_fetch_leaderboard(&p_players, &num_players_read);
    for(int i = 0; i < num_players_read; i++) {
        printf("    %d. %s - %d\n", i+1,  p_players[i].name, p_players[i].score);
    }

    /* Finalize the Python interpreter */
    Py_Finalize();

    /* Make sure to free() *p_sentencces and p_sentences itself,
       Also free() *p_players and p_players itself. 
    */
    return 0;
}
