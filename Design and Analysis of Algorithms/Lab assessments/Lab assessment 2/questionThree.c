#include <stdio.h>
 


int findMaximum(int numberOne, int numberTwo) { return (numberOne > numberTwo) ? numberOne : numberTwo; }

void zeroByOneKnapsack(int numberOfItems, int knapsackSize)
{
    int itemsToInclude[numberOfItems], items[numberOfItems][3], temporaryStorage[1][3], value = 0, index, secondaryIndex, counter = 0;
    float temporaryRatio, ratio[numberOfItems];

    printf("\n\n");
    for (index = 0; index < numberOfItems; index++)
    {
        printf("Please enter the value and weight of item %d: ", index + 1);
        scanf("%d %d", &items[index][0], &items[index][1]);
        ratio[index] = (float)items[index][0] / (float)items[index][1];
        items[index][2] = index + 1;
    }

    int knapsack[numberOfItems + 1][knapsackSize + 1];

    for (index = 0; index <= numberOfItems; index++)
    {
        for (secondaryIndex = 0; secondaryIndex <= knapsackSize; secondaryIndex++)
        {
            if (index == 0 || secondaryIndex == 0) knapsack[index][secondaryIndex] = 0;
            else if (items[index - 1][1] <= secondaryIndex) knapsack[index][secondaryIndex] = findMaximum(items[index - 1][0] + knapsack[index - 1][secondaryIndex - items[index - 1][1]],  knapsack[index - 1][secondaryIndex]);
            else knapsack[index][secondaryIndex] = knapsack[index - 1][secondaryIndex];
        }
    }

    printf("\nThe total profit was calculated to be: %d", knapsack[numberOfItems][knapsackSize]);

    return;
}



void main()
{
    printf("Name: Afraaz Hussain\nAdmission number: 20BDS0374\n\n\n");
    
    int knapsackSize, numberOfItems;

    printf("Enter the number of items: ");
    scanf("%d", &numberOfItems);
    printf("Enter the size of the knapsack: ");
    scanf("%d", &knapsackSize);
    zeroByOneKnapsack(numberOfItems, knapsackSize);
}