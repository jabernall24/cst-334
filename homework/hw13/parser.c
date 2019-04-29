#include "lexer.h"
#include "error.h"
#include "expr.h"
#include "stmt.h"
#include "prog.h"

//
// a predictive parser for a super-minimal programming language
//
// refer to the BNF  

// types of functions used below
void match();
PROG *parse(), *prog();
STMT *get_stmt();
EXPR *get_expr();

int lookahead;    // most recent token

// check that current token is t, and read next token
void match(int t) { 
    if (lookahead == t)
        lookahead = lexan();
    else error("syntax error");
} 

// parse a program
PROG *parse() {
    PROG *p;
    lookahead = lexan();
    p = prog();
    match(DONE);
    return p;
}

// one or more statements
PROG *prog() {

    // YOUR CODE HERE
    // replace the code directly below, which was added so that
    // everything will compile
    
    PROG *c_prog;
    
    switch (lookahead) {
        case ID:
            c_prog = prog_create(get_stmt(), prog());
            break;
        default:
            return NULL;
    }

    // you will create additional functions in this file for the
    // other non-terminals in your BNF grammar
    return c_prog;
}

STMT *get_stmt() {
    char *id = lexer_id_val();
    match(ID);
    int type = -1;
    switch (lookahead) {
        case '(':
            type = CALL_TYPE;
            match('(');
            break;
        case '=':
            type = ASSIGN_TYPE;
            match('=');
            break;
        default:
            break;
    }

    STMT *stmt;
    if(type == ASSIGN_TYPE) {
        stmt = stmt_create_assign(id, get_expr());
        match(';');
    }else if(type == CALL_TYPE){
        stmt = stmt_create_call(id, get_expr());
        match(')');
        match(';');
    }
    return stmt;
}

EXPR *get_expr() {
    EXPR *expr;
    char *id;
    switch (lookahead) {
        case ID:
            id = lexer_id_val();
            match(ID);
            if(lookahead == '(') {
                match('(');
                expr = expr_create_fcall(id, get_expr());
                match(')');
            }else {
                expr = expr_create_var(id);
            }
            break;
        case NUM:
            expr = expr_create_num(lexer_num_val());
            match(NUM);
            break;
        default:
            break;
    }
    return expr;
}
