#include <stdio.h>
#include <stdbool.h>



void printSolution(int board[], int numberOfQueens)
{
    for (int index = 0; index < numberOfQueens; index++)
    {
        for (int secondaryIndex = 0; secondaryIndex < numberOfQueens; secondaryIndex++)
        {
            if (board[index] == secondaryIndex) printf("Q\t");
            else printf(".\t");
        }
        printf("\n\n\n");
    }
    printf("\n");
}

bool underAttack(int board[], int row, int column)
{
    for (int index = 0; index < row; index++) if (board[index] == column || board[index] - index == column - row || board[index] + index == column + row) return true;
    return false;
}

bool nQueens(int board[], int row, int numberOfQueens)
{
    if (row == numberOfQueens) return true;

    for (int column = 0; column < numberOfQueens; column++)
    {
        if (!underAttack(board, row, column))
        {
            board[row] = column;
            if (nQueens(board, row + 1, numberOfQueens)) return true;
            board[row] = -1;
        }
    }
    return false;
}



int main()
{
    printf("Name: Afraaz Hussain\nAdmission number: 20BDS0374\n\n\n");

    int numberOfQueens;
    printf("Enter the number of queens: ");
    scanf("%d", &numberOfQueens);

    int board[numberOfQueens];
    for (int index = 0; index < numberOfQueens; index++) board[index] = -1;

    if (nQueens(board, 0, numberOfQueens))
    {
        printf("\n\nHere is one of many solutions for the given number of queens:\n\n");
        printSolution(board, numberOfQueens);
    }
    else printf("\nAn appropriate solution for the given number of queens was not found.\n");

    return 0;
}
