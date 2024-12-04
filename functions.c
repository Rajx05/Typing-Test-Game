// ALL BACKEND FUNCTIONS

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

void Sentence_Writing(){
    // read first sentence from sentences.txt and put it in an array
    char sentence[100];

    FILE *file;
    file = fopen("sentences.txt","r");
    char line[100];

    while(fgets(line,sizeof(line),file)!=NULL){
        printf("%s\n",line);
        fflush(stdout);
        sleep(1);
    }
    fclose(file);
}

void Counter(){
    // counter loop { game starting in 3 2 1...}
    for(int i=3; i>=1; i--){
        printf("\rGame starting in %d",i);
        fflush(stdout);
        sleep(1);
    }
}

void Game(time_t start_time,bool *ex){
    // clear previous output
    system("clear");
    int inp;

    printf("1 - Sentence writing\n2 - paragraph writing (coming soon)\ninput:");
    scanf("%d",&inp);

    switch(inp){
        case 1:
            system("clear");
            Sentence_Writing();
            break;
        
        case 2:
            printf("coming soon");
            fflush(stdout);
            sleep(1);
            break;

    }
    //timer_start(&start_time);
}

void Leaderboard(){
    // to be added
}
