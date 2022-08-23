#include "monty.h"

/**
 *  main - A function that executes the commands inside a monty file.
 * @argc: Contains the size of the arguments.
 * @argv: Contains the arguments.
 * Return: EXIT_SUCCES OR EXIT_FAILURE
 */

char **montycmd = NULL; /*Global variable for dimensional array*/
int line_number = 0;    /*Global variable for line count.*/
int main(int argc, char **argv)
{
    int txtinput = 0;
    size_t size = 0; /**/
    char *text = NULL;
    FILE *fd = NULL; /*file descriptor por fopen()*/
    stack_t *mystack = NULL;
    void (*f)(stack_t **, unsigned int) = NULL;

    if (argc != 2) /*If the user doesn't specify a file when executing.*/
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    fd = fopen(argv[1], "r"); /*If file can't be open.*/
    if (fd == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    while ((txtinput = getline(&text, &size, fd)) > -1)
    {
        /*printf("Textinput is:%d\n", txtinput);*/
        line_number++;                    /*To know the line number*/
        if (strlen(text) == 1) /*if there is a blank line, ignore it*/
        {
            size = 0;
            free(text);
            text = NULL;
            continue;
        }
        montycmd = separate(text, " \n"); /*Tokenzing the monty file*/
        /*printf("Montycmd is:%s\n", montycmd[0]);*/
        f = get_op_func(montycmd[0]);
        if (f == NULL)
        {
            if(montycmd[0] == NULL)
            {
                arrayfree(montycmd);
                free(text);
                montycmd = NULL;
                text = NULL;
                continue;
            }
            fprintf(stderr, "L%d: unknown instruction %s\n", line_number, montycmd[0]);
            freestack(mystack);
            fclose(fd);
            exit(EXIT_FAILURE);
            
        }
        if (montycmd[1] == NULL && strcmp("pall", montycmd[0]) != 0)
	    {
	    	fprintf(stderr, "L%d: usage: push integer\n", line_number);
            arrayfree(montycmd);
            free(text);
            freestack(mystack);
            fclose(fd);
			exit (EXIT_FAILURE);
	    }
        f(&mystack, line_number);
        size = 0; /*Reset everything, 0/NULL, free the memory allocated*/
        free(text);
        text = NULL;
        arrayfree(montycmd);
        montycmd = NULL;
    }
    /*Reset everything again out of loop, 0/NULL, free the memory allocated*/
    free(text);
    text = NULL;
    freestack(mystack);
    arrayfree(montycmd);
    montycmd = NULL;
    fclose(fd);
    fd = NULL;
    exit(EXIT_SUCCESS);
}
