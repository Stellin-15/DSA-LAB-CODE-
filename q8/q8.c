#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

typedef struct node
{
    char *hostname;
    char *ip_address;
    struct node *next;

} node;

typedef struct hashtable
{
    int capacity;
    node **arr;
} hashtable;

void intializehashmap(hashtable *ht)
{
    ht->capacity = 17;

    ht->arr = (node **)malloc(sizeof(struct node *) * ht->capacity);
    return;
}

int hashing(char hostname[], int size)
{
    int hash = 0;
    int a = 33;

    for (int i = 0; i < size; i++)
    {
        int ascii = hostname[i];
        hash = hash + ascii * pow(a, i);
    }
    int indx = hash % 17;
    // printf("inside hash fuction and hash is %d",indx);
    return indx;
}
void display(hashtable ht)
{
}

void main()
{
    int i = 1;
    int opt = 0;

    hashtable *ht = (hashtable *)malloc(sizeof(hashtable));

    intializehashmap(ht);
    while (i)
    {

        printf("Insert - 1 \n");
        printf("Find - 2 \n");
        printf("Display - 3 \n");
        printf("Exit - 4 \n");
        printf("Enter the operation: ");
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:

            char hostname[30] = {};
            char ip_address[30] = {};
            printf("Enter the hostname: ");
            scanf("%s", hostname);
            printf("Enter the IP address: ");
            scanf("%s", ip_address);

            int size = strlen(hostname);
            int indx = hashing(hostname, size);
            printf("teh indes is:%d",indx);

            node *newNode = (struct node *)malloc(sizeof(struct node));
            newNode->hostname = hostname;
            newNode->ip_address = ip_address;
            newNode->next = NULL;
            printf("%s %s", newNode->hostname, newNode->ip_address);

            if (ht->arr[indx] == NULL)
            {
                printf("inside if part" );
                ht->arr[indx] = newNode;
            }
            else
            {
                printf("inside the else part");
                newNode->next = ht->arr[indx];
                ht->arr[indx] = newNode;
            }

            break;
        case 2:
            break;
        case 3:
            for (int i = 0; i < 17; i++)
            {
                if (ht->arr[i] == NULL)
                {
                    continue;
                }
                else
                {
                    node *temp = (struct node *)malloc(sizeof(struct node));
                    temp = ht->arr[];
                    while (temp != NULL)
                    {
                        printf("hostname : %s \nIP Address : %s\n", temp->hostname, temp->ip_address);
                        temp = temp->next;
                    }
                }
            }
            break;
        case 4:
            i = 0;
            break;
        }
    }
}
