#include <stdio.h>
#include <stdlib.h>
#include "interface_py.h"

/* 
    - Sample usage of functions from interface_py.h header file.
    - _p prefix for pointers.
*/

int main() {
    /* example call to inpy_fetch_sentences() */
    char **p_sentences = malloc(sizeof(char*) * NO_ROUNDS);
    inpy_fetch_sentences(p_sentences);
    int i = 0;
    while(i < NO_ROUNDS) {
        printf("%s", p_sentences[i]);
        i++;
    }

    /* example call to inpy_upload_score() */
    player thor = {"thor", 45};
    switch(inpy_upload_score(thor)) {
        case err_success:
            printf("successfully updated\n");
        case err_server_failure:
            printf("Server failed to update\n");
    }

    /* example call to inpy_fetch_leaderboard() */
    player players[3];
    int players_size = 3, num_players_read = 0;
    inpy_fetch_leaderboard(players, players_size, &num_players_read);
    for(int i = 0; i < num_players_read; i++) {
        printf("%s - %d", players[i].name, players[i].score);
    }
}
