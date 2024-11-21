#include <stdio.h>
#include <string.h>

// Function to read a string
void read(char *s) {
    fgets(s, 100, stdin);
    s[strcspn(s, "\n")] = '\0'; // Remove trailing newline
}

// Function to copy one string to another
void strcopy(char *s1, char *s2) {
    int i;
    for (i = 0; s2[i] != '\0'; i++) {
        s1[i] = s2[i];
    }
    s1[i] = '\0';
}

// Function to find a pattern in a string and replace it
int matchnreplace(char *str, char *pat, char *rep) {
    char ans[100];
    int i = 0, m = 0, c = 0, j = 0, flag = 0, k;

    while (str[c] != '\0') {
        if (str[m] == pat[i]) {
            i++;
            m++;
            if (pat[i] == '\0') { // Pattern found
                flag = 1;
                for (k = 0; rep[k] != '\0'; k++, j++) { // Copy replacement
                    ans[j] = rep[k];
                }
                c = m; // Move to the next character in str after pattern
                i = 0; // Reset pattern index
            }
        } else {
            ans[j++] = str[c++];
            m = c;
            i = 0;
        }
    }
    ans[j] = '\0'; // Null-terminate the result string
    strcopy(str, ans); // Copy the result back to str
    return flag;
}

int main() {
    char str[100], pat[20], rep[20];
    int flag = 0;

    printf("Enter the string: ");
    read(str);

    printf("Enter the pattern: ");
    read(pat);

    printf("Enter the replacement string: ");
    read(rep);

    flag = matchnreplace(str, pat, rep);

    if (flag == 1) {
        printf("The updated string is: %s\n", str);
    } else {
        printf("The pattern was not found.\n");
    }

    return 0;
}
