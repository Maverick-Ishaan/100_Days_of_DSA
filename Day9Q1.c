#include <stdio.h>
#include <string.h>

int main() {
    char str[1001];
    
    if (scanf("%1000s", str) != 1) {
        return 0;
    }

    int len = strlen(str);
    int i, j;
    char temp;

    for (i = 0, j = len - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    printf("%s\n", str);

    return 0;
}
