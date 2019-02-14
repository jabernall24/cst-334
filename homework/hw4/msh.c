#include <stdio.h>
#include <string.h>
#include <time.h>
#include <zconf.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <errno.h>

#define MAXSTR 120

void printDate();

int main() {
    time_t rawtime;
    struct tm *timeinfo;
    char s[MAXSTR + 3];

    while(1){
        printf("msh> ");
        char *string = fgets(s, MAXSTR + 3, stdin);

        // exit if ^d or exit is entered
        if(string == NULL || strcmp(string, "exit\n") == 0) {
            exit(EXIT_SUCCESS);
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
                    continue;
                }else if(strcmp(string, "today\n") == 0){
                    time(&rawtime);
                    timeinfo = localtime(&rawtime);
                    printf("%02d/%02d/%4d\n", 1 + timeinfo->tm_mon, timeinfo->tm_mday, 1900 + timeinfo->tm_year);
                    continue;
                } else{
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

                            if(strcmp(a[0], "cd") == 0) {
                                // TODO: Implement cd command
                                printf("%s\n", getenv("~"));
                                break;
                            }

                            // executes the linux command, if it fails(returns) it prints out error message
                            execvp(a[0], a);
                            printf("msh: %s: %s\n", a[0], strerror(errno));
                            break;

                        }else{
                            wait(NULL);
                        }
                    }
                }
            }
        }
    return 0;
}
