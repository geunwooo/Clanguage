#include <stdio.h>
int main()
{
    int table[9][9], max = 0, row = 1, column = 1;
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            scanf("%d", &table[i][j]);
            if(max < table[i][j]) {
                max = table[i][j];
                row = i + 1;
                column = j + 1;                   
            }
        }
    }
 printf("%d\n%d %d", max, row, column);
    return 0;
}