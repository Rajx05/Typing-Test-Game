
// all functions
void timer_start(time_t *start  ){
    // Get the start time
    time(*&start);
    printf("Timer started...\n"); 
}

void timer_end(time_t *end  ){
    // Get the end time
    time(*&end);
    printf("Timer stopped.\n"); 
}

void Game(time_t start_time,bool *ex){
    // clear previous output
    system("clear");
    
    // counter loop
    for(int i=3; i>=1; i--){
        printf("\rGame starting in %d",i);
        fflush(stdout);
        sleep(1);
    }
    
    //timer_start(&start_time);
    
    *ex = true;

}

void Leaderboard(){
    
}
