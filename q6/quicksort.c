#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct
{
    char name[100];
    char id[100];
    int enroll_year;
    float cgpa;

} studentinfo;

int partition(studentinfo s[], int low, int high)
{

    char pivot[50];
    strcpy(pivot, s[low].name);
    int i = low + 1;
    int j = high;

    do
    {
        while (strcmp(s[i].name, pivot) > 0)
        {
            i++;
        }
        while (strcmp(s[j].name, pivot) < 0)
        {
            j--;
        }

        if (i < j)
        {
            studentinfo temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }

    } while (i < j);

    studentinfo temp = s[low];
    s[low] = s[j];
    s[j] = temp;

    return j;
}
void quicksort(studentinfo s[], int low, int high)
{

    int partitionindex;

    if (low < high)
    {
        partitionindex = partition(s, low, high);
        quicksort(s, low, partitionindex - 1);
        quicksort(s, partitionindex + 1, high);
    }
}
int main()
{

    studentinfo s[10];

    strcpy(s[1].name, "Grace");
    strcpy(s[1].id, "ID7890123456");
    s[1].enroll_year = 2019;
    s[1].cgpa = 3.4;

    strcpy(s[2].name, "Charlie");
    strcpy(s[2].id, "ID3456789012");
    s[2].enroll_year = 2021;
    s[2].cgpa = 3.9;

    strcpy(s[3].name, "Isabel");
    strcpy(s[3].id, "ID9012345678");
    s[3].enroll_year = 2023;
    s[3].cgpa = 3.7;

    strcpy(s[4].name, "Emily");
    strcpy(s[4].id, "ID5678901234");
    s[4].enroll_year = 2018;
    s[4].cgpa = 3.6;

    strcpy(s[5].name, "Frank");
    strcpy(s[5].id, "ID6789012345");
    s[5].enroll_year = 2022;
    s[5].cgpa = 3.8;

    strcpy(s[6].name, "David");
    strcpy(s[6].id, "ID4567890123");
    s[6].enroll_year = 2020;
    s[6].cgpa = 3.7;

    strcpy(s[7].name, "Bob");
    strcpy(s[7].id, "ID2345678901");
    s[7].enroll_year = 2019;
    s[7].cgpa = 3.5;

    strcpy(s[8].name, "Hannah");
    strcpy(s[8].id, "ID8901234567");
    s[8].enroll_year = 2021;
    s[8].cgpa = 3.9;

    strcpy(s[9].name, "Jack");
    strcpy(s[9].id, "ID0123456789");
    s[9].enroll_year = 2022;
    s[9].cgpa = 3.5;

    strcpy(s[10].name, "Alice");
    strcpy(s[10].id, "ID1234567890");
    s[10].enroll_year = 2020;
    s[10].cgpa = 3.8;
    printf("Before sorting: \n");
    for (int i = 1; i <= 10; i++)
    {
        printf("name: %s", s[i].name);
        printf("\n");
    }
    clock_t time_req;
    time_req = clock();

    quicksort(s, 1, 10);

    printf("After sorting: \n");

    for (int i = 1; i <= 10; i++)
    {
        printf("name: %s", s[i].name);
        printf("\n");
    }

    time_req = clock() - time_req;
    printf("Processor time taken for linear search: %f "
           "seconds\n",
           (float)time_req / CLOCKS_PER_SEC);
}