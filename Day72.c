/*Problem Statement
Given a string s consisting of lowercase letters, find the first repeated character in the string. A character is considered repeated if it appears more than once, and among all such characters, the one whose second occurrence has the smallest index should be returned.

Input Format
A single string s.

Output Format
Print the first repeated character. If no character is repeated, print -1.

Sample Input
geeksforgeeks

Sample Output
e*/
#include <stdio.h>
#include <string.h>
#define MAX 26
int main() {
    char s[100];
    int count[MAX] = {0}; // To count occurrences of each character
    printf("Enter a string: ");
    scanf("%s", s);
    char first_repeated = -1; // Initialize to -1 (no repeated character)
    
    for (int i = 0; s[i] != '\0'; i++) {
        int index = s[i] - 'a'; // Map 'a' to 0, 'b' to 1, ..., 'z' to 25
        count[index]++;
        if (count[index] == 2) { // Found the second occurrence
            first_repeated = s[i];
            break; // Stop after finding the first repeated character
        }
    }
    
    if (first_repeated != -1) {
        printf("First repeated character: %c\n", first_repeated);
    } else {
        printf("-1\n"); // No repeated character found
    }
    
    return 0;
}
