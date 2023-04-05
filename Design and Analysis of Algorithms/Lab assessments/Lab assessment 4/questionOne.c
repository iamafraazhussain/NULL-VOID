#include <stdio.h>
#include <string.h>



void computeLPSArray(char* pattern, int patternLength, int* lPSArray)
{
    int length = 0;
    lPSArray[0] = 0;
    int index = 1;

    while (index < patternLength)
    {
        if (pattern[index] == pattern[length])
        {
            length++;
            lPSArray[index] = length;
            index++;
        }
        else
        {
            if (length != 0) length = lPSArray[length - 1];
            else
            {
                lPSArray[index] = 0;
                index++;
            }
        }
    }
}

void knuthMorrisPratt(char* text, char* pattern)
{
    int textLength = strlen(text);
    int patternLength = strlen(pattern);

    int lPSArray[patternLength];
    computeLPSArray(pattern, patternLength, lPSArray);

    int index = 0;
    int secondaryIndex = 0;
    while (index < textLength)
    {
        if (pattern[secondaryIndex] == text[index])
        {
            secondaryIndex++;
            index++;
        }

        if (secondaryIndex == patternLength)
        {
            printf("Pattern found at index %d\n", index - secondaryIndex);
            secondaryIndex = lPSArray[secondaryIndex - 1];
        }

        else if (index < textLength && pattern[secondaryIndex] != text[index])
        {
            if (secondaryIndex != 0) secondaryIndex = lPSArray[secondaryIndex - 1];
            else index = index + 1;
        }
    }
}



int main()
{
    printf("Name: Afraaz Hussain\nAdmission number: 20BDS0374\n\n\n");
    
    char text[1000], pattern[1000];

    printf("Enter the text: ");
    scanf("%s", text);

    printf("Enter the pattern: ");
    scanf("%s", pattern);

    knuthMorrisPratt(text, pattern);

    return 0;
}
