#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int binarysearch(int new_array[], int low, int high, int num)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (new_array[mid] == num)
            return mid;

        if (new_array[mid] < num)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}
void insertionSort(int *new_array, int num)
{
    int j;
    for (int i = 1; i <= num - 1; i++)
    {
        int key = new_array[i];
        j = i - 1;
        while (j >= 0 && new_array[j] > key)
        {
            new_array[j + 1] = new_array[j];
            j--;
        }
        new_array[j + 1] = key;
    }
}

int main()
{
    int test_case_size[15];
    FILE *f = fopen("testCaseSize.txt", "r");

    if (f == NULL)
        printf("The file is empty: ");

    // to collect the size of the data from the testCaseSize file
    for (int i = 0; i < 15; i++)
    {
        fscanf(f, "%d", &test_case_size[i]);
    }

    fclose(f);
    // just to check if the content has been copied
    printf("SIZES: \n");
    for (int i = 0; i < 15; i++)
    {
        printf(" %d \n", test_case_size[i]);
    }

    int num;
    int indx;
    printf("\n");
    printf("Enter the index of the data it will be in: \t");
    scanf("%d", &indx);
    printf("Enter the number you want to find: \t");
    scanf("%d", &num);

    FILE *searchfile = fopen("searchTestCase.txt", "r");
    if (searchfile == NULL)
    {
        printf("The file is empty: ");
    }

    char line[50000];
    char array[50000];
    int count = 0;
    int i = 0;

    while (fgets(line, sizeof line, searchfile))
    {
        count++;
        if (count == indx)
        {
            strcpy(array, line);
        }
    }

    char *token;
    char *search_array[50000];
    int size = 0;
    token = strtok(array, " ");
    search_array[i] = token;
    while (token != NULL)
    {

        search_array[i] = token;
        token = strtok(NULL, " ");
        i++;
        size++;
    }

    int new_array[size];

    for (int i = 0; i < size; i++)
    {
        new_array[i] = atoi(search_array[i]);
    }
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", new_array[i]);
    }

    // linear seach
    FILE *fptr;
    fptr = fopen("linearSearchResults.txt", "a");
    printf("\nLINEAR SEARCH: \n");
    clock_t time_req;
    time_req = clock();
    for (int i = 0; i < size; i++)
    {
        if (new_array[i] == num)
        {
            printf("\nThe element is: %d\n", new_array[i]);
            printf("The index is: %d\n", i - 1);
            fprintf(fptr, "The element is: %d\n", new_array[i]);
            fprintf(fptr, "The index is: %d\n", i - 1);
        }
    }
    time_req = clock() - time_req;
    printf("Processor time taken for linear search: %f "
           "seconds\n",
           (float)time_req / CLOCKS_PER_SEC);

    fprintf(fptr, "Processor time taken for linear search: %f " 
    "seconds\n",
    (float)time_req / CLOCKS_PER_SEC);
    fclose(fptr);

    // sort the array before binary search
    insertionSort(new_array, size);

    for (int i = 0; i < size; i++)
    {
        printf("%d\t", new_array[i]);
    }

    // binary search
    clock_t btime_req;
    FILE *bfptr;
    bfptr = fopen("binarySearchResults.txt", "a");
    printf("\nBINARY SEARCH: \n");
    btime_req = clock();
    int result = binarysearch(new_array, 0, size, num);
    if (result == -1)
    {
        printf("Element not found");
        fprintf(bfptr, "Element not found");
    }
    else
    {
        printf("\nThe element is: %d\n", num);
        printf("Element found at index %d\n", result);

        fprintf(bfptr, "The element is: %d\n", num);
        fprintf(bfptr, "Element found at index %d\n", result);
    }
    btime_req = clock() - btime_req;
    printf("Processor time taken for binary search: %f "
           "seconds\n",
           (float)btime_req / CLOCKS_PER_SEC);
    fprintf(bfptr, "Processor time taken for binary search: %f " "seconds\n",(float)btime_req / CLOCKS_PER_SEC);
    fclose(bfptr);
}
