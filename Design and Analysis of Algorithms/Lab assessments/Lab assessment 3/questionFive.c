#include <stdio.h>
#include <string.h>

void computeLPSArray(char* pattern, int pattern_length, int* lps_array) {
    int len = 0;
    lps_array[0] = 0;
    int i = 1;
    while (i < pattern_length) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps_array[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps_array[len - 1];
            }
            else {
                lps_array[i] = 0;
                i++;
            }
        }
    }
}

void kmp(char* text, char* pattern) {
    int text_length = strlen(text);
    int pattern_length = strlen(pattern);

    int lps_array[pattern_length];
    computeLPSArray(pattern, pattern_length, lps_array);

    int i = 0;
    int j = 0;
    while (i < text_length) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }

        if (j == pattern_length) {
            printf("Pattern found at index %d\n", i - j);
            j = lps_array[j - 1];
        }

        else if (i < text_length && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps_array[j - 1];
            }
            else {
                i = i + 1;
            }
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

    kmp(text, pattern);

    return 0;
}
