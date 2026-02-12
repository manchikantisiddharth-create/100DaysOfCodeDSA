/*Problem: A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.

Input:
- Single line: a lowercase string containing only alphabetic characters (no spaces)

Output:
- Print the transformed code name after applying the mirror operation

Example:
Input:
hello

Output:
olleh

Explanation: The first character moves to the last position, the second to the second-last, and so on until the entire string is mirrored */
#include <stdio.h>
#include <string.h> 
void mirrorString(char str[]) {
    int length = strlen(str);
    char mirrored[length + 1];
    for(int i = 0; i < length; i++) {
        mirrored[i] = str[length - 1 - i];
    }
    mirrored[length] = '\0';
    printf("Mirrored code name: %s\n", mirrored);
}   
int main() {
    char codeName[100];
    printf("Enter the code name: ");
    scanf("%s", codeName);
    mirrorString(codeName);
    return 0;
}