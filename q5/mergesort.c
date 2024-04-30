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

void merge(studentinfo s[], int mid, int low, int high)
{

    int i, j, k;
    studentinfo B[10];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (strcmp(s[j].name, s[i].name) > 0)
        {
            B[k] = s[i];
            k++;
            i++;
        }
        else
        {
            B[k] = s[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        B[k] = s[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k] = s[j];
        k++;
        j++;
    }
    for (i = low; i <= high; i++)
    {
        s[i] = B[i];
    }
}

void mergesort(studentinfo s[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergesort(s, low, mid);
        mergesort(s, mid + 1, high);
        merge(s, mid, low, high);
    }
}

int main()
{
    studentinfo s[10];

    strcpy(s[0].name, "Grace");
    strcpy(s[0].id, "ID7890123456");
    s[0].enroll_year = 2019;
    s[0].cgpa = 3.4;

    strcpy(s[1].name, "Charlie");
    strcpy(s[1].id, "ID3456789012");
    s[1].enroll_year = 2021;
    s[1].cgpa = 3.9;

    strcpy(s[2].name, "Isabel");
    strcpy(s[2].id, "ID9012345678");
    s[2].enroll_year = 2023;
    s[2].cgpa = 3.7;

    strcpy(s[3].name, "Emily");
    strcpy(s[3].id, "ID5678901234");
    s[3].enroll_year = 2018;
    s[3].cgpa = 3.6;

    strcpy(s[4].name, "Frank");
    strcpy(s[4].id, "ID6789012345");
    s[4].enroll_year = 2022;
    s[4].cgpa = 3.8;

    strcpy(s[5].name, "David");
    strcpy(s[5].id, "ID4567890123");
    s[5].enroll_year = 2020;
    s[5].cgpa = 3.7;

    strcpy(s[6].name, "Bob");
    strcpy(s[6].id, "ID2345678901");
    s[6].enroll_year = 2019;
    s[6].cgpa = 3.5;

    strcpy(s[7].name, "Hannah");
    strcpy(s[7].id, "ID8901234567");
    s[7].enroll_year = 2021;
    s[7].cgpa = 3.9;

    strcpy(s[8].name, "Jack");
    strcpy(s[8].id, "ID0123456789");
    s[8].enroll_year = 2022;
    s[8].cgpa = 3.5;

    strcpy(s[9].name, "Alice");
    strcpy(s[9].id, "ID1234567890");
    s[9].enroll_year = 2020;
    s[9].cgpa = 3.8;
    printf("Before sorting: \n");
    for (int i = 0; i < 10; i++)
    {
        printf("name: %s", s[i].name);
        printf("\n");
    }
    clock_t time_req;
    time_req = clock();
    mergesort(s, 0, 9);

    printf("After sorting: \n");
    for (int i = 0; i < 10; i++)
    {
        printf("name: %s", s[i].name);
        printf("\n");
    }
    time_req = clock() - time_req;
    printf("Processor time taken for linear search: %f "
           "seconds\n",
           (float)time_req / CLOCKS_PER_SEC);
}