#ifndef INTERFACE_PY_H
#define INTERFACE_PY_H

/*
    - C interface with python.
    - calls python functions to update sentences.txt, leaderboard.txt and
      to upload score from score.txt.
    - parses above files.
    - all functions prefixed with inpy_ (interface with python) (prefix is to be confirmed).
    - no_ shortcut for number of.
*/

#define NO_ROUNDS 3      /* number of rounds */
#define MAX_NAME_LEN 20  /* maximum length of player's name */
#define MAX_SEN_LEN 50   /* maximum length of sentences */

typedef struct  {
    char *name;
    int score;
} player;

typedef int error_code; /* type for different error codes from python or server*/

enum error_codes { /* Sample errors. all errors with err_ prefix*/
    err_success = 0,
    err_server_failure = 1, /* Plus other errors */
};

/* Fetch sentences from sentences.txt and fill sentences parameter 
   return success or appropriate err_ */
error_code inpy_fetch_sentences(char **sentences);

/* Update server with player info or return err_ */
error_code inpy_upload_score(player new_player);

/* Fetch leaderboard from server and fill players parameter of players_size 
   and update number of players read */
error_code inpy_fetch_leaderboard(player *players, int players_size, int *num_players_read);

#endif /* INTERFACE_PY_H */
