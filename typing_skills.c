#include <python3.10/Python.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h> // using unistd for linux 
#include <stdbool.h>
#include <stdlib.h>
#include </home/romeoraj/Desktop/C Prog/Typing Test/functions.c>




int main() {
    //Py_Initialize();
    // Declare variables
    time_t start_time, end_time;
    double elapsed_time;
    char words[500];
    int cmd;
    bool exit = false;
    
    //Py_FinalizeEx();
    // Game Menu Loop
    do{
    system("clear");
    printf("welcome to typing skills v1.0\n\n1 - start\n2 - show leaderboard\n3 - Quit\ninput:");
    scanf("%d",&cmd);

    switch(cmd){
    case 1:
        Game(start_time,&exit);
        break;
    case 2:
        Leaderboard();
        system("clear");
        break;
    case 3:
        exit = true;
        break;
    }
    }while(!exit);

    // Calculate the elapsed time
    elapsed_time = difftime(end_time, start_time);
    

    // Display the elapsed time
    //printf("Elapsed time: %.2f seconds\n", elapsed_time);

    return 0;
}
