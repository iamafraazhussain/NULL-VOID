#include <stdio.h>
#include <string.h>



void longestCommonSubsequence()
{
    int lCSTable[20][20], index, secondaryIndex;
    char stringOne[20], stringTwo[20], crossMatrix[20][20];

    printf("Enter the first string: ");
    scanf("%s", stringOne);
    printf("Enter the second string: ");
    scanf("%s", stringTwo);

    int lengthOne = strlen(stringOne), lengthTwo = strlen(stringTwo);

    for (index = 0; index <= lengthOne; index++) lCSTable[index][0] = 0;
    for (index = 0; index <= lengthTwo; index++) lCSTable[0][index] = 0;

    for (index = 1; index <= lengthOne; index++)
    {
        for (secondaryIndex = 1; secondaryIndex <= lengthTwo; secondaryIndex++)
        {
            if (stringOne[index - 1] == stringTwo[secondaryIndex - 1]) lCSTable[index][secondaryIndex] = lCSTable[index - 1][secondaryIndex - 1] + 1;
            else if (lCSTable[index - 1][secondaryIndex] >= lCSTable[index][secondaryIndex - 1]) lCSTable[index][secondaryIndex] = lCSTable[index - 1][secondaryIndex];
            else lCSTable[index][secondaryIndex] = lCSTable[index][secondaryIndex - 1];
        }
    }

    int element = lCSTable[lengthOne][lengthTwo], counter = 0;
    char lCSAlgorithm[element + 1];
    lCSAlgorithm[index] = '\0';
    index = lengthOne;
    secondaryIndex = lengthTwo;

    while (index > 0 && secondaryIndex > 0)
    {
        if (stringOne[index - 1] == stringTwo[secondaryIndex - 1])
        {
            lCSAlgorithm[element - 1] = stringOne[index - 1];
            index--;
            secondaryIndex--;
            element--;
            counter++;
        }
        else if (lCSTable[index - 1][secondaryIndex] > lCSTable[index][secondaryIndex - 1]) index--;
        else secondaryIndex--;
    }
    lCSAlgorithm[counter] = '\0';

    printf("\n\nString one: %s \nString two: %s\n\n", stringOne, stringTwo);
    printf("Longest Common Subsequence: %s", lCSAlgorithm);

}



int main()
{
    printf("Name: Afraaz Hussain\nAdmission number: 20BDS0374\n\n\n");
    
    longestCommonSubsequence();
}