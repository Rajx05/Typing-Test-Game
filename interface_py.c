#include "interface_py.h"
#include <stdio.h>
#include <stdlib.h>

/* 
    - Sample implementation of interface_py.h
    - Using preix p_ for pointers.
    - Sample usage of these functions is given in sample_inpy_functions.c
*/

error_code inpy_fetch_sentences(char **p_sentences) {
    /* TODO: call python functions */
    FILE *sentences_file = fopen("sentences.txt", "r");
    int i = 0;
    p_sentences[i] = malloc(MAX_SEN_LEN);
    while(fgets(p_sentences[i], MAX_SEN_LEN, sentences_file) != NULL && i < NO_ROUNDS) {
        i++;
        p_sentences[i] = malloc(MAX_SEN_LEN);
    }
    return err_success;              /* Assuming everything is OK*/
}

error_code inpy_upload_score(player new_player) {
    /* TODO: Implement actual logic*/
    return err_server_failure;       /* Sample error_code */
}

error_code inpy_fetch_leaderboard(player *players, int players_size, int *num_players_read) {
    /* Fill with actual data*/
    players[0].name = "hari";
    players[0].score = 42;
    *num_players_read = 1;
    return err_success;              /* Assuming everything is OK*/
}
