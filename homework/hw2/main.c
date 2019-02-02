#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    FILE *tmpfile();
    char maxSize[25];
    bool a = true;

    while(a){
        printf("msh> ");
        if(fgets(maxSize, sizeof(maxSize), stdin) == NULL) {
            break;
        }
        else if(strncmp("exit", maxSize, 4) == 0){
            a = false;
        }else {
            printf("%s", maxSize);
        }
    }

//    printf("\n");
    return 0;
}