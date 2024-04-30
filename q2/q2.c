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
    int f;
    int r;
    int size;
    studentinfo *arr;
} queue;

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

// this is circular queue implementation.
void enqueue(studentinfo s, queue *q)
{
    if (((q->r + 1) % q->size) == q->f)
    {
        printf("It is overflow condition!!\n");
    }
    else
    {
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = s;
    }
}

studentinfo dequeue(queue *q)
{
    if (q->r == q->f)
    {
        printf("It is underflow condition!!\n");
    }
    else
    {
        q->f = (q->f + 1) % q->size;
        return q->arr[q->f];
    }
}

void above_9_cpgpa(queue *q)
{
    int front = q->f;
    int rear = q->r;

    for (int i = front; i != rear; i = (i + 1) % q->size)
    {
        studentinfo s;
        s = q->arr[i];
        if (s.cgpa < 9)
        {
            printf("%s %s %s %f\n", s.id, s.name, s.dob, s.cgpa);
        }
    }
}

void main()
{
    queue *q = (queue *)malloc(sizeof(queue));
    q->size = 5;
    q->f = -1;
    q->r = -1;
    q->arr = (studentinfo *)malloc(q->size * sizeof(studentinfo));

    char line[100];
    FILE *file = fopen("studentin_ex2.dat", "r");
    char data[4][100];

    printf("This is the data being pushed into the queue\n");

    while (fgets(line, 100, file) != NULL)
    {
        spacing(data, line);
        studentinfo s;
        strcpy(s.id, data[0]);
        strcpy(s.name, data[1]);
        strcpy(s.dob, data[2]);
        s.cgpa = atof(data[3]);
        // printf("%s %s %s %f\n", s.id, s.name, s.dob, s.cgpa);
        enqueue(s, q);
    }
    printf("This is the data being pushed out of the queue\n");

    int front = q->f;
    int rear = q->r;

    // above_9_cpgpa(q);

    printf("The studenst with cgpa below 9: \n");
    above_9_cpgpa(q);

    FILE *fo = fopen("outputexp2.dat", "a");
    for (int i = front; i != rear; i = (i + 1) % q->size)
    {

        studentinfo s = dequeue(q);
        // printf("%s %s %s %f\n", s.id, s.name, s.dob, s.cgpa);
        fprintf(fo, "%s %s %s %f\n", s.id, s.name, s.dob, s.cgpa);
    }
}
