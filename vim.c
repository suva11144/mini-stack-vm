#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>



typedef enum {

    INST_PUSH,
    INST_POP,
    INST_ADD,
    INST_SUB,
    INST_MUL,
    INST_DIV,
    INST_PRINT,
} Inst_Set ;

typedef struct{
    Inst_Set type;
    int value ;
} Inst ;


#define DEF_INST_PUSH(x) { .type = INST_PUSH, .value = (x) }
#define DEF_INST_POP { .type = INST_POP, .value = 0 }
#define DEF_INST_ADD { .type = INST_ADD, .value = 0 }   
#define DEF_INST_SUB { .type = INST_SUB, .value = 0 }
#define DEF_INST_MUL { .type = INST_MUL, .value = 0 }
#define DEF_INST_DIV { .type = INST_DIV, .value = 0 }
#define DEF_INST_PRINT { .type = INST_PRINT, .value = 0 }


Inst program[]  = {


    DEF_INST_PUSH(13),
    DEF_INST_PUSH(11),
    DEF_INST_SUB,

};

#define PROGRAM_SIZE (sizeof(program) / sizeof(program[0]))


#define MAX_STACK_SIZE 1024 

int stack [MAX_STACK_SIZE] ;

int stack_size ;

void push(int value)
{
    if (stack_size >= MAX_STACK_SIZE) {
        fprintf(stderr, "ERROR: Stack overflow\n");
        exit(1);
    }
    stack[stack_size++] = value;
}

int pop ()
{
    if (stack_size <= 0){
        fprintf(stderr, "ERROR: Stack underflow\n");
        exit(1);
    }
    return stack[--stack_size] ;
}
void print_stack()
{
    printf("Stack: ");
    for (size_t i = 0; i < stack_size; i++)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}


int main()
{
    int a , b ; 

    for (size_t ip = 0; ip < PROGRAM_SIZE; ip++)
    {
        switch ((program[ip].type))
        {
        case INST_PUSH:
            push(program[ip].value);
            break;
        case INST_POP:
            pop();
            break;
        case INST_ADD:
            a = pop();
            b = pop();
            push(a + b);
            break;
        case INST_SUB:
            a = pop();
            b = pop();
            push(b - a);
            break;
        case INST_MUL:
            a = pop();
            b = pop();
            push(a * b);
            break;
        case INST_DIV:
            a = pop();
            b = pop();
            push(a / b);
            break;
        case INST_PRINT:
            printf("%d\n", pop());
            break;
        default:
            break;
        }
    }

    print_stack();
    
    printf("Hello, Vim!\n");
    return 0;
}