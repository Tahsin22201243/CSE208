
#include <stdio.h>
#include <string.h>

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to find the longest common subsequence (LCS)
int lcs(char *string1, char *string2) {
    int n = strlen(string1);
    int m = strlen(string2);

    int dp[n + 1][m + 1];

    // Initialize the DP table
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (string1[i - 1] == string2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int length = dp[n][m];
    char lcsString[length + 1];

    int i = n, j = m;
    lcsString[length] = '\0';

    // Backtrack to find the LCS string
    while (i > 0 && j > 0) {
        if (string1[i - 1] == string2[j - 1]) {
            lcsString[length - 1] = string1[i - 1];
            i--, j--, length--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    printf("Longest Common Subsequence: %s\n", lcsString);

    printf("Longest Common Subsequence Length: ");
    return dp[n][m];
}

int main() {
    char s1[100], s2[100];

    printf("Enter the first string: ");
    fgets(s1, sizeof(s1), stdin);
    s1[strcspn(s1, "\n")] = '\0';  // Remove trailing newline character

    printf("Enter the second string: ");
    fgets(s2, sizeof(s2), stdin);
    s2[strcspn(s2, "\n")] = '\0';  // Remove trailing newline character

    printf("%d\n", lcs(s1, s2));

    return 0;
}
