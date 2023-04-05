#include <stdio.h>



void naiveMethod()
{
    int textSize, patternSize, index, secondaryIndex, counter, patternCount = 0;
    printf("Enter the size of the text: ");
    scanf("%d", &textSize);
    char text[textSize + 1];
    printf("Enter the text: ");
    scanf("%s", &text);

    printf("\nEnter the size of the pattern: ");
    scanf("%d", &patternSize);
    char pattern[patternSize];
    printf("Enter the pattern: ");
    scanf("%s", &pattern);

    for (index = 0; index < textSize; index++)
    {
        counter = 0;
        for (secondaryIndex = 0; secondaryIndex < patternSize; secondaryIndex++)
        {
            if (pattern[secondaryIndex] == text[index + secondaryIndex]) counter++;
            else break;
        }

        if (counter == patternSize)
        {
            printf("\nAn instance of the pattern was found at index %d", index);
            patternCount++;
        }
    }

    if (patternCount == 0) printf("\nThe given pattern was not found in the string provided.");
    else printf("\n\nA total of %d pattern(s) were found!", patternCount);
}



int main()
{
    printf("Name: Afraaz Hussain\nAdmission number: 20BDS0374\n\n\n");

    naiveMethod();

    return 0;
}