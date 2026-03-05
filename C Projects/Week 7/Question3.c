#include <stdio.h>

int numofstud;

int score[100];
char studname[100][50];

int registerStudent(int n) 
{
    for(int i = 0; i < n; i++)
    {
        printf("\nStudent %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", &studname[i]);
        printf("Score: ");
        scanf("%d", &score[i]);
    }
}

float avgScore(int n)
{
    float sum = 0;

    for(int i = 0; i < n; i++)
    {
        sum += score[i];
    }

    return sum / n;
}

int printresults(int n)
{
    printf("\nAverage Score: %.1f\n", avgScore(numofstud));
    printf("Name\tScore\tResult\n");
    for(int i = 0; i < n; i++)
    {
        printf("%s\t%d\t", studname[i], score[i]);
        if (score[i] >= 50)
        {
            printf("Pass\n");
        }
        else
        {
            printf("Fail\n");
        }
    }
}

int main() 
{

    printf("Enter the number of students: ");
    scanf("%d", &numofstud);

    registerStudent(numofstud);
    avgScore(numofstud);
    printresults(numofstud);

}