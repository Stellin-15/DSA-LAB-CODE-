#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[20];
    char id[20];
    float cgpa;
    struct node *next;
} node;

node *create(node *head)
{
    node *temp = (node *)malloc(sizeof(node));
    temp = head;
    char name[20] = {0};
    char id[10];
    float cgpa;
    int index = 0;
    node *nn = (node *)malloc(sizeof(node));
    printf("\n");
    printf("Enter the name of the student: \n");
    scanf("%s", &name);
    strcpy(nn->name, name);
    printf("Enter the ID of the student: \n");
    scanf("%s", &id);
    strcpy(nn->id, id);
    printf("Enter the CGPA of the student: \n");
    scanf("%f", &cgpa);
    nn->cgpa = cgpa;
    printf("Enter the postion of the student: \n");
    scanf("%d", &index);

    printf("%s\t%s\t%.2f\n", nn->name, nn->id, nn->cgpa);

    for (int i = 1; i < index; i++)
    {
        temp = temp->next;
    }
    nn->next = temp->next;
    temp->next = nn;

    return head;
}
void display(node *head)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr = head;

    if (ptr == NULL)
        printf("The list is empty:");
    else
    {

        while (ptr != NULL)
        {
            printf("%s\t%s\t%.2f\n", ptr->name, ptr->id, ptr->cgpa);
            ptr = ptr->next;
        }
    }
}
int findname(node *head, char name[20])
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr = head;
    int pos = 1;

    while (ptr != NULL)
    {
        if (strcmp(ptr->name, name) == 0)
        {
            return pos;
        }

        ptr = ptr->next;
        pos++;
    }
    return -1;
}
node *delete(node *head, char name[])
{
    node *ptr1 = (node *)malloc(sizeof(node));
    ptr1 = head;
    node *ptr2 = (node *)malloc(sizeof(node));
    ptr2 = head;
    int temp = 1;

    while (strcmp(ptr1->name, name) != 0)
    {
        ptr2 = ptr1;
        ptr1 = ptr1->next;
    }
    ptr2->next = ptr1->next;
    free(ptr1);

    return head;
}

int size(node *head)
{
    node *temp = (node *)malloc(sizeof(node));
    temp = head;
    int count = 0;
    while (temp->next != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

int isEmpty(node *head)
{
    if (head->next == NULL)
        return 1;
    else
        return -1;
}
void stu_details(node *head)
{
    node *temp = (node *)malloc(sizeof(node));
    temp = head;
    int index = 0;

    printf("Enter the postion of the student: \n");
    scanf("%d", &index);
    for (int i = 1; i < index; i++)
    {
        temp = temp->next;
    }
    printf("%s\t%s\t%.2f\n", temp->name, temp->id, temp->cgpa);
}
int main()
{
    node *head = (node *)malloc(sizeof(node));
    head = NULL;
    int run = 1;
    int option = 0;

    node *n1 = (node *)malloc(sizeof(node));
    strcpy(n1->name, "Ann");
    strcpy(n1->id, "2018A7PS0001");
    n1->cgpa = 9.0;

    if (head == NULL)
    {
        n1->next = NULL;
        head = n1;
    }
    else
    {
        n1->next = head;
        head = n1;
    }
    node *n2 = (node *)malloc(sizeof(node));
    strcpy(n2->name, "Shot");
    strcpy(n2->id, "2018A7PS0002");
    n2->cgpa = 8.5;
    n2->next = head;
    head = n2;

    node *n3 = (node *)malloc(sizeof(node));
    strcpy(n3->name, "Titanium");
    strcpy(n3->id, "2018A7PS0003");
    n3->cgpa = 6.5;
    n3->next = head;
    head = n3;

    node *n4 = (node *)malloc(sizeof(node));
    strcpy(n4->name, "Kiki");
    strcpy(n4->id, "2018A7PS0004");
    n4->cgpa = 9.5;
    n4->next = head;
    head = n4;

    node *n5 = (node *)malloc(sizeof(node));
    strcpy(n5->name, "Youyou");
    strcpy(n5->id, "2018A7PS0005");
    n5->cgpa = 9.5;
    n5->next = head;
    head = n5;

    while (run != 0)
    {
        printf("Enter the option you want: \n");

        printf("Add a student record to the list - 1\n");
        printf("Find a student record by name - 2 \n");
        printf("Delete a student record from the list - 3 \n");
        printf("Display the list - 4\n");
        printf("isEmpty - 5 \n");
        printf("Size - 6 \n");
        printf("Enter the index for their Student details - 7 \n");
        printf("Exit - 8\n");

        scanf("%d", &option);

        switch (option)
        {
        case 1:
            head = create(head);
            break;
        case 2:
            char nam[20] = {0};
            printf("Enter the name of the student: \n");
            scanf("%s", &nam);
            int pos = findname(head, nam);

            if (pos == -1)
            {

                printf("The student is not there in the linked list\n");
            }
            else
            {

                printf("The student is there in the liked list\n");
                printf("The index: %d\n", pos);
            }

            break;
        case 3:
            char name[20] = {0};
            printf("Enter the name of the student you want to delete: \n");
            scanf("%s", &name);

            int position = findname(head, name);
            if (position == -1)
            {

                printf("The student is not there in the linked list\n");
                printf("The deletion is not possible \n");
            }
            else
            {
                printf("The student is there in the liked list\n");
                head = delete (head, name);
                printf("The studen thas been deleted\n");
            }
            break;
        case 4:
            display(head);
            break;
        case 5:
            int temp = isEmpty(head);
            if (temp)
            {
                printf("The list is not empty\n");
            }
            else
            {
                printf("The list is empty\n");
            }
            break;
        case 6:
            int count = size(head);
            printf("The size of the Linked List is: %d \n", count);
            break;
        case 7:
            stu_details(head);
            break;
        case 8:
            return -1;
            break;
        }
    }
}
