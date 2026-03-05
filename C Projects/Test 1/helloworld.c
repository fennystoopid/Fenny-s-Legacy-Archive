#include<stdio.h>
#include<string.h>
char bodh[] = "";
char j[] = "Jamal";

int main(){
    printf("Input a less or equal to 10 word :\n");
    scanf("%s", &bodh);
    if (strcmp(bodh, j) == 0) {
        printf("woohoo ");
    };
    printf("The word is %s", bodh);
    
    return 0;
};