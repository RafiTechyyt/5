#include <stdio.h>

int main()
{
    int a[100];
    int n, i, j, min, temp, choice;
    int sorted = 0;

    do
    {
        printf("\n--- MENU ---\n");
        printf("1. Enter Array\n");
        printf("2. Perform Sort\n");
        printf("3. Display Array\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter number of elements: ");
                scanf("%d", &n);

                printf("Enter the elements: ");

                for (i = 0; i < n; i++)
                    scanf("%d", &a[i]);

                sorted = 0;
                break;

            case 2:
                for (i = 0; i < n - 1; i++)
                {
                    min = i;

                    for (j = i + 1; j < n; j++)
                    {
                        if (a[j] < a[min])
                            min = j;
                    }

                    temp = a[i];
                    a[i] = a[min];
                    a[min] = temp;
                }

                sorted = 1;

                printf("Sorting performed successfully.\n");
                break;

            case 3:
                if (sorted == 0)
                    printf("Unsorted Array: ");
                else
                    printf("Sorted Array: ");

                for (i = 0; i < n; i++)
                    printf("%d ", a[i]);

                printf("\n");
                break;

            case 4:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 4);

    return 0;
}
