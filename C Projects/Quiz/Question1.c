#include <stdio.h>



int main() {

    int marks[10][5][3];
    int i, j, k;
    int avgmark[10][5];


    //input marks of 10 students in 5 subjects with 3 tests each
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 5; j++) {
            for (k = 0; k < 3; k++) {
                printf("Enter marks of student %d in subject %d test %d: ", i + 1, j + 1, k + 1);
                scanf("%d", &marks[i][j][k]);
            }
        }
    }
    
    //average of each students in 5 subjects with 3 tests each
    for (i = 0; i < 10; i++) {
        float avg[5];
        for (j = 0; j < 5; j++) {
            int sum = 0;
            for (k = 0; k < 3; k++) {
                sum += marks[i][j][k];
            }
            avg[j] = sum / 3.0;
        }
        for (j = 0; j < 5; j++) {
            avgmark[i][j] = avg[j];
        }
    }

    //display ranking of students based on average marks
    printf("\nRanking of students based on average marks:\n");
    for (i = 0; i < 10; i++) {
        for (j = i + 1; j < 10; j++) {
            if (avgmark[i][0] < avgmark[j][0]) {
                int temp[5];
                for (k = 0; k < 5; k++) {
                    temp[k] = avgmark[i][k];
                    avgmark[i][k] = avgmark[j][k];
                    avgmark[j][k] = temp[k];
                }
            }
        }
    }
    
    //display sum average marks of each student
    for (i = 0; i < 10; i++) {
        printf("Student %d", i + 1);
        int sum = 0;
        for (j = 0; j < 5; j++) {
            sum += avgmark[i][j];
            printf("%d ", sum);
            printf("%d", i + 1);
        }
        printf("\n");
    }

}