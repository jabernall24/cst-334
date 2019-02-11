#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <zconf.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <errno.h>

#define MAXSTR 120

void printDate();

int main() {
    while(true){
        char string[MAXSTR + 3];
        printf("msh> ");
        // exit if ^d or exit is entered
        if(fgets(string, MAXSTR + 3, stdin) == NULL || strcmp(string, "exit\n") == 0) {
            break;
        }else {
            size_t n = strlen(string) - 1;
            // check that input is not too long
            if (n > MAXSTR){
                printf("error: input too long\n");
                // clears remaining characters in input buffer
                char c;
                while((c = getchar())){
                    if(c == '\n') break;
                }
            }else{
                if(strcmp(string, "help\n") == 0){
                    printf("enter Linux commands, or ‘exit’ to exit\n");
                }else if(strcmp(string, "today\n") == 0){
                    printDate();
                }else{
                    int rc = fork();

                    if(rc < 0){
                        fprintf(stderr, "fork failed\n");
                        exit(1);
                    }else if(rc == 0){
                        char *a[MAXSTR] = {NULL};

                        char *tokens = strtok(string, " \n");
                        int i = 0;
                        // takes each token and puts them in an array
                        while(tokens){
                            a[i] = strdup(tokens);
                            i++;
                            tokens = strtok(NULL, " \n");
                        }

                        // executes the linux command, if it fails(returns) it prints out error message
                        if(execvp(a[0], a)){
                            printf("msh: %s: %s\n", a[0], strerror(errno));
                            break;
                        }
                    }else{
                        int rc_wait = wait(NULL);
                    }
                }
            }
        }
    }

    return 0;
}

// prints out the date in MM/DD/YYYY format
void printDate() {
    time_t currentDate = time(NULL);
    char *time = asctime(localtime(&currentDate));
    if(time[4] == 'J' && time[5] == 'a'){
        printf("01");
    }else if(time[4] == 'F'){
        printf("02");
    }else if(time[4] == 'M' && time[6] == 'r'){
        printf("03");
    }else if(time[4] == 'A' && time[5] == 'p'){
        printf("04");
    }else if(time[4] == 'M' && time[6] == 'y'){
        printf("05");
    }else if(time[4] == 'J' && time[6] == 'n'){
        printf("06");
    }else if(time[4] == 'J' && time[6] == 'l'){
        printf("07");
    }else if(time[4] == 'A' && time[5] == 'u'){
        printf("08");
    }else if(time[4] == 'S'){
        printf("09");
    }else if(time[4] == 'O'){
        printf("10");
    }else if(time[4] == 'N'){
        printf("11");
    }else if(time[4] == 'D'){
        printf("12");
    }

    if(time[8] == ' '){
        printf("/0");
    }else{
        printf("/%c", time[8]);
    }
    printf("%c/%c%c%c%c\n", time[9], time[20], time[21], time[22], time[23]);
}