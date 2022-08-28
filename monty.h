#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

extern char **montycmd; /*Global variable to manage dimensional arrays.*/
extern int line_number; /*Global variable to keep tabs on line count.*/

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct list_s - linked list node
 * @str: string length
 * @len: the length
 * @next: point to the next node
 * Description:
 */
typedef struct list_s
{
char *str;
unsigned int len;
struct list_s *next;
} list_t;

char **separate(char *string, const char *s);
int count_words(char *string);
void arrayfree(char **string);
void freestack(stack_t *mystack);
int _strlen(char *s);
void push(stack_t **head, unsigned int line_number);
void pall(stack_t **head, unsigned int line_number);
void pint(stack_t **head, unsigned int line_number);
void pop(stack_t **head, unsigned int line_number);
void swap(stack_t **head, unsigned int line_number);
void add(stack_t **head, unsigned int line_number);
void nop(stack_t **head, unsigned int line_number);
void (*get_op_func(char *s))(stack_t **head, unsigned int line_number);
#endif
