#include <stdio.h>



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

    for (index = 0; index < numberOfItems; ++index) 
    {
        for (secondaryIndex = index + 1; secondaryIndex < numberOfItems; ++secondaryIndex) 
        {
            if (items[index][2] < items[secondaryIndex][2]) 
            {
                temporaryStorage[0][0] = items[index][0];
                temporaryStorage[0][1] = items[index][1];
                temporaryStorage[0][2] = items[index][2];
                temporaryRatio = ratio[index];
                items[index][0] = items[secondaryIndex][0];
                items[index][1] = items[secondaryIndex][1];
                items[index][2] = items[secondaryIndex][2];
                ratio[index] = ratio[secondaryIndex];
                items[secondaryIndex][0] = temporaryStorage[0][0];
                items[secondaryIndex][1] = temporaryStorage[0][1];
                items[secondaryIndex][2] = temporaryStorage[0][2];
                ratio[secondaryIndex] = temporaryRatio;
            }
        }
    }

    if (items[0][1] > knapsackSize)
        {
            printf("\n\nNone of the items can be in the knapsack of given size.");
            return;
        }
    for (index = 0; index < numberOfItems; index++)
    {
        if (items[index][1] <= knapsackSize)
        {
            itemsToInclude[counter] = items[index][2];
            value += items[index][0];
            knapsackSize -= items[index][1];
            counter++;
        }

        else break;
    }

    printf("\n\nThe following are the items that can be put in the knapsack:");
    for (index = 0; index < counter; index++) printf(" %d", itemsToInclude[index]);
    printf("\nThe total profit was calculated to be: %d", value);
    
    return;
}

void fractionalKnapsack(int numberOfItems, int knapsackSize)
{
    int itemsToInclude[numberOfItems], items[numberOfItems][3], temporaryStorage[1][3], index, secondaryIndex, counter = 0, additionalItem = 0;
    float temporaryRatio, ratio[numberOfItems], value = 0;

    printf("\n\n");
    for (index = 0; index < numberOfItems; index++)
    {
        printf("Please enter the value and weight of item %d: ", index + 1);
        scanf("%d %d", &items[index][0], &items[index][1]);
        ratio[index] = (float)items[index][0] / (float)items[index][1];
        items[index][2] = index + 1;
    }

    for (index = 0; index < numberOfItems; ++index) 
    {
        for (secondaryIndex = index + 1; secondaryIndex < numberOfItems; ++secondaryIndex) 
        {
            if (items[index][2] < items[secondaryIndex][2]) 
            {
                temporaryStorage[0][0] = items[index][0];
                temporaryStorage[0][1] = items[index][1];
                temporaryStorage[0][2] = items[index][2];
                temporaryRatio = ratio[index];
                items[index][0] = items[secondaryIndex][0];
                items[index][1] = items[secondaryIndex][1];
                items[index][2] = items[secondaryIndex][2];
                ratio[index] = ratio[secondaryIndex];
                items[secondaryIndex][0] = temporaryStorage[0][0];
                items[secondaryIndex][1] = temporaryStorage[0][1];
                items[secondaryIndex][2] = temporaryStorage[0][2];
                ratio[secondaryIndex] = temporaryRatio;
            }
        }
    }

    if (items[0][1] > knapsackSize)
        {
            printf("\n\nNone of the items can be in the knapsack of given size.");
            return;
        }
    for (index = 0; index < numberOfItems; index++)
    {
        if (items[index][1] <= knapsackSize)
        {
            itemsToInclude[counter] = items[index][2];
            value += items[index][0];
            knapsackSize -= items[index][1];
            counter++;
        }
    
        else
        {
            if (ratio[index] < knapsackSize)
            {
                value += ratio[index] * (float)knapsackSize;
                additionalItem = items[index][2];
                knapsackSize = 0;
                break;
            }
        }
    }
    
    printf("\n\nThe following are the items that can be put in the knapsack:");
    for (index = 0; index < counter; index++) printf(" %d", itemsToInclude[index]);
    if (additionalItem != 0) printf(" %d", additionalItem);
    printf("\nThe total profit was calculated to be: %f", value);
    
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
    
    while (1)
    {
        char choice;

        printf("\nPlease select an option...\n");
        printf("(A) Perform 0|1 knapsack\n");
        printf("(B) Perform fractional knapsack\n");
        printf("\nYour choice: ");
        scanf(" %c", &choice);

        if (choice == 'a' || choice == 'A')
        {
            zeroByOneKnapsack(numberOfItems, knapsackSize);
            break;
        }
        else if (choice == 'b' || choice == 'B')
        {
            fractionalKnapsack(numberOfItems, knapsackSize);
            break;
        }
        else
        {
            printf("\nPlease try again by choosing a valid option...\n\n");
            continue;
        }
    }
}