#include <stdio.h>
#include <string.h>

// Function to replace all occurrences of 'pattern' in 'str' with 'replacement'
void replacePattern(char *str, const char *pattern, const char *replacement) {
    char result[100];
    int i = 0, j = 0;
    int patLen = strlen(pattern);
    int repLen = strlen(replacement);

    while (str[i]) {
        // If the pattern is found at the current position
        if (strncmp(&str[i], pattern, patLen) == 0) {
            strcpy(&result[j], replacement);
            j += repLen;
            i += patLen;
        } else {
            result[j++] = str[i++];
        }
    }
    result[j] = '\0';
    strcpy(str, result); // Copy result back to str
}

int main() {
    char str[100], pattern[20], replacement[20];

    printf("Enter the string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    printf("Enter the pattern: ");
    fgets(pattern, sizeof(pattern), stdin);
    pattern[strcspn(pattern, "\n")] = '\0';

    printf("Enter the replacement: ");
    fgets(replacement, sizeof(replacement), stdin);
    replacement[strcspn(replacement, "\n")] = '\0';

    replacePattern(str, pattern, replacement);

    printf("Updated string: %s\n", str);

    return 0;
}

