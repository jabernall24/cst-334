#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAXSTR 120

int main() {
    while(true){
        char string[MAXSTR + 3];
        printf("msh> ");
        if(fgets(string, MAXSTR + 3, stdin) == NULL || strncmp(string, "exit", 4) == 0) {
            break;
        }else {
            size_t n = strlen(string) - 1;
            if (n > MAXSTR){
                printf("error: input too long\n");
                char c;
                while((c = getchar())){
                    if(c == '\n') break;
                }
            }else{
                printf("%s", string);
            }
        }
    }

    return 0;
}
