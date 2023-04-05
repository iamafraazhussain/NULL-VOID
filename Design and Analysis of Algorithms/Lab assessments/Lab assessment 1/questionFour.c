#include <stdio.h>
#include <math.h>
#include <windows.h>



boolean isPowerOfTwo(int number)
{
    if (number == 0) return 0;
    while (number != 1)
    {
        if (number % 2 != 0) return 0;
        number = number / 2;
    }
    return 1;
}

int assignedOrder;
void divideAndConquer(int matrixOne[assignedOrder][assignedOrder], int matrixTwo[assignedOrder][assignedOrder], int resultantMatrix[assignedOrder][assignedOrder], int order)
{
    for (int row = 0; row < order; row++)
    {
        for (int column = 0; column < order; column++)
        {
            resultantMatrix[row][column] = 0;
            for (int dimension = 0; dimension < order; dimension++) 
            {
                resultantMatrix[row][column] += (matrixOne[row][dimension] * matrixTwo[dimension][column]);
            }
        }
    }

    printf("\n\nThe product matrix is...\n");
    for (int row = 0; row < order; row++)
    {
        for (int column = 0; column < order; column++) printf("%d ", resultantMatrix[row][column]);
        printf("\n");
    }
}

void matrixMultiplication()
{
    printf("\e[1;1H\e[2J");
    printf("Name: Afraaz Hussain\nAdmission number: 20BDS0374\n\n\n");

    int order;
    printf("Enter the order of the square matrices: ");
    scanf("%d", &order);
    int matrixOne[order][order], matrixTwo[order][order], resultantMatrix[order][order], row, column;
    printf("\n\nEnter the elements of the first matrix...\n");
    for(row = 0; row < order; row++)
    {
        for(column = 0; column < order; column++) scanf("%d", &matrixOne[row][column]);
    }
    printf("\n\nEnter the elements of the second matrix...\n");
    for(row = 0; row < order; row++)
    {
        for(column = 0; column < order; column++) scanf("%d", &matrixTwo[row][column]);
    }

    assignedOrder = order;
    divideAndConquer(matrixOne, matrixTwo, resultantMatrix, order);
}

void strassenMatrixMultiplication()
{
    printf("\e[1;1H\e[2J");
    printf("Name: Afraaz Hussain\nAdmission number: 20BDS0374\n\n\n");

    int order;
    printf("Enter the order of the square matrices: ");
    scanf("%d", &order);
    if (isPowerOfTwo(order) && order == 2)
    {
        int matrixOne[order][order], matrixTwo[order][order], resultantMatrix[order][order], row, column;
        printf("\n\nEnter the elements of the first matrix...\n");
        for(row = 0; row < order; row++)
        {
            for(column = 0; column < order; column++) scanf("%d", &matrixOne[row][column]);
        }
        printf("\n\nEnter the elements of the second matrix...\n");
        for(row = 0; row < order; row++)
        {
            for(column = 0; column < order; column++) scanf("%d", &matrixTwo[row][column]);
        }

        int elements[7];
        elements[0] = (matrixOne[0][0] + matrixOne[1][1]) * (matrixTwo[0][0] + matrixTwo[1][1]);
        elements[1] = (matrixOne[1][0] + matrixOne[1][1]) * matrixTwo[0][0];
        elements[2] = matrixOne[0][0] * (matrixTwo[0][1] + matrixTwo[1][1]);
        elements[3] = matrixOne[1][1] * (matrixTwo[1][0] + matrixTwo[0][0]);
        elements[4] = (matrixOne[0][0] + matrixOne[0][1]) * matrixTwo[1][1];
        elements[5] = (matrixOne[1][0] - matrixOne[0][0]) * (matrixTwo[0][0] + matrixTwo[0][1]);
        elements[6] = (matrixOne[0][1] - matrixOne[1][1]) * (matrixTwo[1][0] + matrixTwo[1][1]);

        resultantMatrix[0][0] = elements[0] + elements[3] - elements[4] + elements[6];
        resultantMatrix[0][1] = elements[2] + elements[4];
        resultantMatrix[1][0] = elements[1] + elements[3];
        resultantMatrix[1][1] = elements[0] + elements[1] - elements[2] + elements[5];

        printf("\n\nThe product matrix is...\n");
        for(row = 0; row < order; row++)
        {
            for(column = 0; column < order; column++)
            {
                printf("%d ", resultantMatrix[row][column]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("\n\nOrder of your matrices must be a power of 2");
        sleep(3);
        strassenMatrixMultiplication();
    }
}

void menu()
{
    printf("\e[1;1H\e[2J");
    printf("Name: Afraaz Hussain\nAdmission number: 20BDS0374\n\n\n");

    while (1)
    {
        printf("Please sleect an option...\n");
        printf("(A) Multiplication using divide and conquer approach\n");
        printf("(B) Strassen's matrix multiplication\n\n");
        printf("Your choice: ");
        char option, runAgain;
        scanf(" %c", &option);

        switch (option)
        {
        case 'A':
            matrixMultiplication();
            break;
        
        case 'B':
            strassenMatrixMultiplication();
            break;

        default:
            printf("\nThat was not a valid option.");
            sleep(3);
            menu();
            break;
        }

        printf("\n\n\nWould you like to run the program again? [Y / N]: ");
        scanf(" %c", &runAgain);
        if (runAgain == 'Y' || runAgain == 'y') menu();
        else
        {
            printf("\nExiting the program...");
            sleep(2);
            break;
        }
    }
    

}



void main()
{
    printf("\e[1;1H\e[2J");
    printf("Name: Afraaz Hussain\nAdmission number: 20BDS0374\n\n\n");

    menu();
}