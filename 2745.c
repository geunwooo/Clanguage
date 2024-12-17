#include <stdio.h>
int main(void) 
{
    char N[36] = {0};
    int B, ans = 0;

    scanf("%s %d",N,&B);

    for (int i = 0; i < strlen(N); i++) {
        if (N[i] >= 'A' && N[i] <= 'Z') {
            ans += (N[i] - 55) * pow(B,strlen(N) - i - 1);
        }
        else {
            ans += (N[i] - 48) * pow(B,strlen(N) - i - 1);
        }
    }

    printf("%d", ans);

    return 0;
}