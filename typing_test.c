#include <stdio.h>
#include <time.h>
#include <unistd.h> // using unistd for linux 


void timer_start(time_t *start  ){
    // start the timer
    time(*&start);
    printf("Timer started...\n"); 
}

void timer_end(time_t *end  ){
    // end the timer
    time(*&end);
    printf("Timer stopped.\n"); 
}



int main() {
    // Declare variables
    time_t start_time, end_time;
    double elapsed_time;
    char words[500];

    //time started
    timer_start(&start_time);
    

    printf("enter words:");
    fgets(words,sizeof(words),stdin);
    
    //time ended
    timer_end(&end_time);

    // Calculate the elapsed time
    elapsed_time = difftime(end_time, start_time);
    

    // Display the elapsed time
    printf("Elapsed time: %.2f seconds\n", elapsed_time);

    return 0;
}
