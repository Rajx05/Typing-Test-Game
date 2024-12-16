#ifndef INTERFACE_PY_H
#define INTERFACE_PY_H

#include <stddef.h>

/*
    - C interface with python.
    - Calls python functions to update sentences.txt, leaderboard.txt and
      to upload score from score.txt.
    - Parses above files.
    - All functions prefixed with inpy_ (interface with python) (TODO: prefix to be confirmed).
    - no_ shortcut for number of.
*/

#define NO_ROUNDS 4      /* number of rounds */
#define MAX_NAME_LEN 32  /* maximum length of player's name */
#define MAX_SEN_LEN 64   /* maximum length of sentences */

typedef struct  {
    char name[MAX_NAME_LEN];
    int score;
} player;

typedef int error_code; /* type for different error codes from python or server */

enum error_codes { /* Sample errors. all errors with prefix err_ */
    err_success = 0,
    err_server_failure = 1,
    err_py_module_import = 2,
    err_py_fun_name = 3,
    err_py_returned_null = 4,
    err_file_open = 5,
    err_mem_malloc = 6,
    err_mem_realloc = 7
    /* other erros */
};

/* Fetch sentences from server and fill sentences parameter 
   return err_success or appropriate err_ */
error_code inpy_fetch_sentences(char **sentences);

/* Update server with player info
   return err_success or appropriate err_ */
error_code inpy_upload_score(const player new_player);

/* Fetch leaderboard from server and allocates memory for players parameter 
   Updates number of players read and players parameter
   Or return appropriate err_ */
error_code inpy_fetch_leaderboard(player **players, size_t *num_players_read);

#endif /* INTERFACE_PY_H */
