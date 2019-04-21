#include <stdio.h>
#include <string.h>

// Instructions:
// Edit the code below ONLY at the comments showing YOUR CODE HERE.

// Hints:
// You may need additional scanf() statements, but they can be just
// like the scanf() statements already in the code below.

// check whether the input can be derived from this grammar
// A ::= 0 B  
// B ::= 1 A | 2 B | ;

int A(), B();

int A() {
    int n;
    char tok[10];

    // read a string from input
    n = scanf("%s", &tok);
    
    // YOUR CODE HERE
    if(strcmp(tok, "0") == 0) {
        B();
    }else{
        printf("no");
    }
    
    return 0;
}

int B() {
    int n;
    char tok[10];

    n = scanf("%s", &tok);

    // YOUR CODE HERE
    if(strcmp(tok, "1") == 0) {
        A();
    }else if(strcmp(tok, "2") == 0) {
        B();
    }else if(strcmp(tok, ";") == 0) {
        int c = fgetc(stdin);
        if(c == '\n') {
            printf("yes");
        }else {
            printf("no");
        }
    }else {
        printf("no");
    }
    
    return 0;
}

int main() {
    A();
}

