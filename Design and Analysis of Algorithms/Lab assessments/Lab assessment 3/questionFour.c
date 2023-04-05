#include <stdio.h>
#include <string.h>



void rabinKarp(int textSize, char text[], int patternSize, char pattern[], int hashValue)
{
    int index, secondaryIndex, textHash = 0, patternHash = 0, hash = 1, spuriousHits = 0, base = 256;

    printf("Choose a base for the hash function: ");
    scanf("%d", &base);
    printf("\n\n");

    for (index = 0; index < patternSize - 1; index++) hash = (hash * base) % hashValue;

    for (index = 0; index < patternSize; index++)
    {
        patternHash = (base * patternHash + pattern[index]) % hashValue;
        textHash = (base * textHash + text[index]) % hashValue;
    }

    for (index = 0; index <= textSize - patternSize; index++)
    {
        if (patternHash == textHash)
        {
            for (secondaryIndex = 0; secondaryIndex < patternSize; secondaryIndex++) if (text[index + secondaryIndex] != pattern[secondaryIndex]) break;
            
            if (secondaryIndex == patternSize) printf("Pattern found at index %d \n", index);
            else spuriousHits++;
        }

        if (index < textSize - patternSize)
        {
            textHash = (base * (textHash - text[index] * hash) + text[index + patternSize]) % hashValue;
            if (textHash < 0) textHash = textHash + hashValue;
        }
    }
    printf("\nA total of %d spurious hit(s) were encountered!", spuriousHits);
}



int main()
{
    printf("Name: Afraaz Hussain\nAdmission number: 20BDS0374\n\n\n");

    int textSize, patternSize, hashValue = 121;
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
    printf("\nEnter a hash value (preferably a prime number): ");
    scanf("%d", &hashValue);

    rabinKarp(textSize, text, patternSize, pattern, hashValue);
    return 0;
}
