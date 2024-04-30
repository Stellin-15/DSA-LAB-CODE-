#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char id[100];
    char name[100];
    char dob[100];
    float cgpa;
} studentinfo;

typedef struct
{

    int size;
    int top;
    studentinfo *arr;
} stack;

void spacing(char data[4][100], char line[100])
{
    int begin = 0, word = 0;
    int i, j;

    for (int i = 0; i < strlen(line); i++)
    {
        if (line[i + 1] == ' ' || i == strlen(line) - 1)
        {
            for (j = begin; j <= i; j++)
            {
                data[word][j - begin] = line[j];
            }
            begin = i + 2;
            word++;
        }
    }
}

int isfull(stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isempty(stack *stk)
{
    if (stk->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(studentinfo s, stack *stk)
{
    if (isfull(stk))
    {
        printf("overflow condition and data cannot be pushed into stack \n");
    }
    else
    {
        stk->top++;
        stk->arr[stk->top] = s;
    }
}

studentinfo pop(stack *stk)
{
    if (isempty(stk))
    {
        printf("Underflow Conditon and the stack is empty \n");
    }

    return (stk->arr[stk->top]);
}

void main()
{
    stack *stk = (stack *)malloc(sizeof(stack));
    stk->size = 5;
    stk->top = -1;
    stk->arr = (studentinfo *)(malloc(stk->size * sizeof(studentinfo)));

    char line[100];
    FILE *file = fopen("text.txt", "r");
    char data[4][100];

    printf("This is the data being pushed into the stack\n");

    while (fgets(line, 100, file) != NULL)
    {
        spacing(data, line);
        studentinfo s;
        strcpy(s.id, data[0]);
        strcpy(s.name, data[1]);
        strcpy(s.dob, data[2]);
        s.cgpa = atof(data[3]);
        printf("%s %s %s %f\n", s.id, s.name, s.dob, s.cgpa);
        push(s, stk);
    }

    printf("This is the data being pushed out of the stack\n");

    FILE *fo = fopen("outputfile.txt", "a");
    while (stk->top != -1)
    {
        studentinfo s = pop(stk);
        printf("%s %s %s %f\n", s.id, s.name, s.dob, s.cgpa);
        stk->top--;
        fprintf(fo, "%s %s %s %f\n", s.id, s.name, s.dob, s.cgpa);
    }
}
