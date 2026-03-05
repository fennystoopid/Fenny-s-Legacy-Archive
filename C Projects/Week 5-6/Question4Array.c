#include <stdio.h>

int main() {

    int first[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}}, i, j;

    for (i = 0; i < 3;i++) {
        for (j = 0; j < 3;j++) {
            printf("%d ", first[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < 3;i++) {
        int csum=0;
        for (j = 0; j < 3;j++) {
            csum = csum + first[j][i];
        }
        printf("%d ", csum);
    }

}