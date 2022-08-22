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
while ((txtinput = getline(&text, &size, fd)) > 0)
{
line_number++;                    /*To know the line number*/
montycmd = separate(text, " \n"); /*Tokenzing the monty file*/
f = get_op_func(montycmd[0]);
if (f == NULL)
{
free(montycmd);
free(text);
exit(EXIT_FAILURE);
}
f(&mystack, line_number);
size = 0; /*Reset everything, 0/NULL, free the memory allocated*/
free(text);
text = NULL;
free(montycmd);
montycmd = NULL;
}
/*Reset everything again out of loop, 0/NULL, free the memory allocated*/
free(text);
text = NULL;
freestack(mystack);
montycmd = NULL;
free(montycmd);
fclose(fd);
fd = NULL;
exit(EXIT_SUCCESS);
}
