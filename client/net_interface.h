/* net_interface.h
   Interface for client-server communication.
   Provides the functions to interact with server for sentences, leaderboard 
   and to update player score*/

#ifndef NET_INTERFACE_H
#define NET_INTERFACE_H

#define PORT       8080       /* TODO: update with actual PORT number */
#define SERVER_IP "127.0.0.1" /* TODO: update with actual IP */
#define NO_ROUNDS 3
#define NAME_LEN_LIMIT 20
#define SUCCESS 0
#define SERVER_FAILURE -1

/* Represent the details of a player, including their name and score*/
typedef struct {
    char name[NAME_LEN_LIMIT];
    int score;                /* TODO: type to be decided */
} player_details;

/* Fills the "sentences" array with NO_ROUNDS pointers to strings and
   returns -1 on server failure */
int net_get_sentences(char *sentences[]);

/* Updates the server with player details and
   returns -
      0 on success
     -1 on server failure
     -2 if "player.name" already exists */
int net_upload_score(player_details player);

/* Expects the size of "players" array,
   fills players array and
   returns - 
      number of players on success
     -1 on server failure
     -2 if size is less than the actual users in leaderboard
      on memory insufficiency fills exactly "size" elements of the array*/
int net_get_leaderboard(player_details *players, int size);
#endif /* net_interface.h */
