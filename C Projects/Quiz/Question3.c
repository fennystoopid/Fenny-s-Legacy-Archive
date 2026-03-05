#include <stdio.h>

int main() {

    int numofcity, city;
    float temp[5][7]; // Assuming max 5 cities and 7 days

    //input number of cities
    printf("Enter the number of cities (max 5): ");
    scanf("%d", &numofcity);

    //input temperature for each city, each day
    for (int i = 0; i < numofcity; i++) {
        printf("\n---Enter the temperature for city %d---\n", i + 1);
        city = i;
        for (int j = 0; j < 7; j++) {
            printf("Day %d: ", j + 1);
            scanf("%f", &temp[city][j]);
        }
    }

    // Displaying the all temperature data
    printf("\n---Temperature data---");
    for (int i = 0; i < numofcity; i++) {
        city = i + 1;
        printf("\nCity %d: ", city);
        for (int j = 0; j < 7; j++) {
            printf("%.1f,", temp[i][j]);
        }
    }

    //average temperature
    printf("\n");   
    for (int i = 0; i < numofcity; i++) {
        float sum = 0;
        for (int j = 0; j < 7; j++) {
            sum += temp[i][j];
        }
        printf("\nAverage Temperature for City %d: %.1f", i + 1, sum / 7);
    }

    //highest temperature
    printf("\n");
    int maxday, maxcity;
    for (int i = 0; i < numofcity; i++){
        float max = temp[i][0];
        for (int j = 1; j < 7; j++) {
            if (temp[i][j] > max) {
                max = temp[i][j];
                maxday = j + 1;
                maxcity = i + 1;
            }
        }
    }

    //lowest temperature
    int lowday, lowcity;
    for (int i = 0; i < numofcity; i++){
        float lowest = temp[i][0];
        for (int j = 0; j < 7; j++) {
            if (temp[i][j] <= lowest) {
                lowest = temp[i][j];
                lowday = j + 1;
                lowcity = i + 1;
            }
        }
    }

    // Displaying the highest and lowest temperature
    printf("\nHighest Temperature: (City %d, Day %d) %.1f", maxcity, maxday, temp[maxcity - 1][maxday - 1]);
    printf("\nLowest Temperature: (City %d, Day %d) %.1f", lowcity, lowday, temp[lowcity - 1][lowday - 1]);

}