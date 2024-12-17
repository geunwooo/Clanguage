#include <stdio.h>
int main(void)
{
    int len, k = 1;
    char str[100];
    scanf("%s", str);
    len = strlen(str);
    
    for(int i = 0; i < len / 2; i++){
        if(str[i] != str[len - 1 - i]) {
            k = 0;
            break;
        }
    }
    
    printf("%d", k);
    return 0;
}