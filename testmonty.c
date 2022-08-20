#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "monty.h"

char **montycmd = NULL; /*variable global*/
int main(int argc, char **argv)
{
    int txtinput = 0, line_number = 0; 
    size_t size = 0; /**/
    char *text = NULL;
    FILE *fd = NULL; /*file descriptor por fopen()*/
    stack_t *mystack = NULL;
    void (*f)(stack_t **, unsigned int) = NULL;

    if(argc == 2)
    {
        fd = fopen(argv[1], "r");
        if(fd == NULL)
        {
            return (-1);
        }
        while((txtinput = getline(&text, &size, fd)) > 0)
        {
            line_number++; /*used to know the line number*/
            montycmd = separate(text, " \n"); /*tokenzing the monty file*/
            f = get_op_func(montycmd[0]);
            if(f == NULL)
            {
                free(montycmd);
                free(text);
                exit(EXIT_FAILURE);
                /*imprimo un error*/
            }            
            f(&mystack, line_number);
            size = 0;
            free(text);
		    text = NULL;
            free(montycmd);
            montycmd = NULL;
        }
    }
    free(text);
    text = NULL;
    freestack(mystack);
    
    free(montycmd);
    montycmd = NULL;
    fclose(fd);
    fd = NULL;
    return (0);
}