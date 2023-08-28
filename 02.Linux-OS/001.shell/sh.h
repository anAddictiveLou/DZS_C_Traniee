#ifndef _SH_H
#define _SH_H

#define BUF_SIZE 100
#define TOKEN_SIZE BUF_SIZE
#define ARGS 10
#define RD 0
#define WR 1

enum Type 
{
    EXEC,   
    REDIR,
    PIPE,
    BACK
};

enum Redir_type
{
    INPUT,
    OUTPUT
};

struct exec
{
    char* name;
    char** args;
};

struct redir
{
    struct exec prog;
    char* file_name;
    enum Redir_type redir_type;
};

struct pipe
{
    struct exec prog[2];
};

struct back
{
    struct exec prog;
};

struct cmd 
{
    enum Type type;
    union Run
    {
        struct exec handle_exec;
        struct redir handle_redir;
        struct pipe handle_pipe;    
        struct back handle_back;
    } run;
};

#endif