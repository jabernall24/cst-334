#include <stdio.h>
#include <string.h>
#include <time.h>
#include <zconf.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>

#define MAXSTR 120

void runCommand(char *string);

int main(int argc, char **argv) {
    char s[MAXSTR + 3];
    bool readFromFile = false;


    while(!readFromFile){
        if(argc > 1){
            FILE *file = fopen(argv[1], "r");
            while(fgets(s, MAXSTR, file)){
                runCommand(s);
            }
            readFromFile = true;
        }else{
            printf("msh> ");
            runCommand(fgets(s, MAXSTR + 3, stdin));
        }
    }
    return 0;
}

void runCommand(char *string){
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
            }else if(strcmp(string, "today\n") == 0){
                time_t rawtime;
                struct tm *timeinfo;
                time(&rawtime);
                timeinfo = localtime(&rawtime);
                printf("%02d/%02d/%4d\n", 1 + timeinfo->tm_mon, timeinfo->tm_mday, 1900 + timeinfo->tm_year);
            } else{
                char *a[MAXSTR] = {NULL};

                char *tokens = strtok(string, " \n");
                int i = 0;

                // store file names if any redirection occurs
                char *inFileName = "";
                char *outFileName = "";

                // takes each token and puts them in an array
                while(tokens){
                    if(strcmp(tokens, ">") == 0){
                        // TODO: handle output redirection
                        tokens = strtok(NULL, " \n");
                        outFileName = tokens;
                        tokens = strtok(NULL, " \n");
                        continue;
                    }else if(strcmp(tokens, "<") == 0){
                        // TODO: handle input redirection
                        tokens = strtok(NULL, " \n");
                        inFileName = tokens;
                        tokens = strtok(NULL, " \n");
                    }else{
                        a[i] = strdup(tokens);
                        i++;
                        tokens = strtok(NULL, " \n");
                    }
                }

                // handles the cd command
                if(strcmp(a[0], "cd") == 0) {
                    if(a[1] == NULL){
                        if(chdir(getenv("HOME")) != 0){
                            printf("msh: cd: No such file or directory\n");
                        }
                    }else{
                        if(chdir(a[1]) != 0){
                            printf("msh: cd: No such file or directory\n");
                        }
                    }
                }else{
                    int rc = fork();

                    if(rc < 0){
                        fprintf(stderr, "fork failed\n");
                        exit(1);
                    }else if(rc == 0){
                        // executes the linux command, if it fails(returns) it prints out error message
                        FILE *outFile = fopen(outFileName, "w");
                        FILE *inFile = fopen(inFileName, "r");
                        if(strcmp(outFileName, "") == 0 && strcmp(inFileName, "") == 0){
                            // no input/output redirection
                            execvp(a[0], a);
                        }else if(strcmp(outFileName, "") != 0 && strcmp(inFileName, "") == 0){
                            // output redirection
                            dup2(fileno(outFile), 1);
                            execvp(a[0], a);
                        }else if(strcmp(inFileName, "") != 0 && strcmp(outFileName, "") == 0){
                            // input redirection
                            dup2(fileno(inFile), 0);
                            execvp(a[0], a);
                        }else{
                            // input and output redirection
                            dup2(fileno(inFile), 0);
                            dup2(fileno(outFile), 1);
                            execvp(a[0], a);
                        }

                        printf("msh: %s: %s\n", a[0], strerror(errno));
                        exit(EXIT_SUCCESS);
                    }else{
                        wait(NULL);
                    }
                }
            }
        }
    }
}