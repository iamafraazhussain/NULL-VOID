#include <stdio.h>
#include <limits.h>



void findOptimalSolution(int sTable[][100], int index, int secondaryIndex) {
    if (index == secondaryIndex) printf("A%d", index);
    else
    {
        printf("(");
        findOptimalSolution(sTable, index, sTable[index][secondaryIndex]);
        findOptimalSolution(sTable, sTable[index][secondaryIndex] + 1, secondaryIndex);
        printf(")");
    }
}

void matrixChainMultiplication(int dimension[], int numberOfMatrices, int mTable[][100], int sTable[][100])
{
    int index, secondaryIndex, tertiaryIndex, element, temporaryValue;
    for (index = 1; index <= numberOfMatrices; index++) mTable[index][index] = 0;
    
    for (element = 2; element <= numberOfMatrices; element++)
    {
        for (index = 1; index <= numberOfMatrices - element + 1; index++)
        {
            secondaryIndex = index + element - 1;
            mTable[index][secondaryIndex] = INT_MAX;
            for (tertiaryIndex = index; tertiaryIndex <= secondaryIndex - 1; tertiaryIndex++)
            {
                temporaryValue = mTable[index][tertiaryIndex] + mTable[tertiaryIndex + 1][secondaryIndex] + dimension[index - 1] * dimension[tertiaryIndex] * dimension[secondaryIndex];
                if (temporaryValue < mTable[index][secondaryIndex])
                {
                    mTable[index][secondaryIndex] = temporaryValue;
                    sTable[index][secondaryIndex] = tertiaryIndex;
                }
            }
        }
    }
}



int main()
{
    printf("Name: Afraaz Hussain\nAdmission number: 20BDS0374\n\n\n");

    int numberOfMatrices, index, secondaryIndex;
    printf("Enter the number of matrices: ");
    scanf("%d", &numberOfMatrices);
    int dimension[numberOfMatrices + 1], mTable[100][100], sTable[100][100];
    printf("Enter dimensions of matrices: ");
    for (index = 0; index <= numberOfMatrices; index++) {
        scanf("%d", &dimension[index]);
    }
    matrixChainMultiplication(dimension, numberOfMatrices, mTable, sTable);
    printf("\n\nMinimum number of scalar multiplications: %d\n", mTable[1][numberOfMatrices]);
    printf("Optimal parenthesization: ");
    findOptimalSolution(sTable, 1, numberOfMatrices);
    printf("\n\n\n");

    printf("The M-table is given as follows:\n\n");
    for (index = 1; index <= numberOfMatrices; index++) {
        for (secondaryIndex = 1; secondaryIndex <= numberOfMatrices; secondaryIndex++) {
            if (index > secondaryIndex) printf("       .");
            else printf("%8d", mTable[index][secondaryIndex]);
        }
        printf("\n\n");
    }

    printf("\nThe S-table is give as follows:\n\n");
    for (index = 1; index <= numberOfMatrices; index++) {
        for (secondaryIndex = 1; secondaryIndex <= numberOfMatrices; secondaryIndex++) {
            if (index >= secondaryIndex) printf("    .");
            else printf("%5d", sTable[index][secondaryIndex]);
        }
        printf("\n\n");
    }
    return 0;
}
