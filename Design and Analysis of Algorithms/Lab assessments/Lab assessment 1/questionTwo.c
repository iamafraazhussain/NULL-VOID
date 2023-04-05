#include <stdio.h>
#include <math.h>



float calculateDistance(float xOne, float yOne, float xTwo, float yTwo)
{
    float distance = ((xTwo - xOne) * (xTwo - xOne)) + ((yTwo - yOne) * (yTwo - yOne));
    return sqrt(distance);
}



void main()
{
    printf("Name: Afraaz Hussain\nAdmission number: 20BDS0374\n\n\n");

    int numberOfCities, row, column, index, origin;
    printf("Please enter the total number of cities: ");
    scanf("%d", &numberOfCities);
    printf("\n");

    float cityLocation[numberOfCities][2], cityDistance[numberOfCities][numberOfCities];
    for (index = 0; index < numberOfCities; index++)
    {
        printf("Please enter the location of city %d: ", index + 1);
        scanf("%f %f", &cityLocation[index][0], &cityLocation[index][1]);
    }
    for (row = 0; row < numberOfCities; row++)
    {
        for (column = 0; column < numberOfCities; column++)
        {
            cityDistance[row][column] = calculateDistance(cityLocation[row][0], cityLocation[row][1], cityLocation[column][0], cityLocation[column][1]);
        }
    }

    printf("\nEnter the city you would like to start from: ");
    scanf("%d", &origin);
    origin--;
    int numberCombinations[numberOfCities - 1], counter = 0;
    for (index = 0; index < numberOfCities; index++)
    {
        if (origin != index)
        {
            numberCombinations[counter] = index;
            counter++;
        }
    }

    float leastDistance = -1.0, currentLeastDistance;
    int temporary, bestRoute[numberOfCities + 1];

    for (row = 1; row <= numberOfCities - 1; row++)
    {
        for (column = 0; column < numberOfCities - 2; column++)
        {
            currentLeastDistance = 0;
            temporary = numberCombinations[column];
            numberCombinations[column] = numberCombinations[column + 1];
            numberCombinations[column + 1] = temporary;

            currentLeastDistance = cityDistance[origin][numberCombinations[0]] + cityDistance[origin][numberCombinations[numberOfCities - 2]];
            for (index = 0; index < numberOfCities - 2; index++) currentLeastDistance += cityDistance[numberCombinations[index]][numberCombinations[index + 1]];
            if (leastDistance == -1.0)
            {
                leastDistance = currentLeastDistance;
                bestRoute[0] = origin;
                bestRoute[numberOfCities] = origin;
                for (index = 1; index < numberOfCities; index++) bestRoute[index] = numberCombinations[index - 1];
            }
            else if (leastDistance > currentLeastDistance)
            {
                leastDistance = currentLeastDistance;
                bestRoute[0] = origin;
                bestRoute[numberOfCities] = origin;
                for (index = 1; index < numberOfCities; index++) bestRoute[index] = numberCombinations[index - 1];
            }
        }
    }

    printf("\nthe least distance was calculated to be: %f\n", leastDistance);
    printf("To achieve this, you'll have to use the following route: %d", origin + 1);
    for (index = 1; index < numberOfCities + 1; index++) printf(" -> %d", bestRoute[index] + 1);
}