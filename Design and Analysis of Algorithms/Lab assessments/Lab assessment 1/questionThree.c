#include <stdio.h>



void findMinimumAndMaximum(int numberArray[], int low, int high, int *min, int *max)
{
    if (low == high)
    {
        *min = numberArray[low];
        *max = numberArray[low];
        return;
    }

    if (low + 1 == high)
    {
        if (numberArray[low] > numberArray[high])
        {
            *min = numberArray[high];
            *max = numberArray[low];
        }

        else
        {
            *min = numberArray[low];
            *max = numberArray[high];
        }
        return;
    }

    int middleElement = (low + high) / 2;
    findMinimumAndMaximum(numberArray, low, middleElement, min, max);
    findMinimumAndMaximum(numberArray, middleElement + 1, high, min, max);

    if (numberArray[middleElement] > *max) *max = numberArray[middleElement];
    if (numberArray[middleElement] < *min) *min = numberArray[middleElement];
}



void main()
{
    printf("Name: Afraaz Hussain\nAdmission number: 20BDS0374\n\n\n");

    int numberOfElements, min, max;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &numberOfElements);

    int numberArray[numberOfElements];

    printf("Enter all the elements in the array: ");
    for (int index = 0; index < numberOfElements; index++) scanf("%d", &numberArray[index]);

    findMinimumAndMaximum(numberArray, 0, numberOfElements - 1, &min, &max);
    printf("\n\nSmallest element in the given array: %d", min);
    printf("\nLargest element in the given array: %d", max);
}