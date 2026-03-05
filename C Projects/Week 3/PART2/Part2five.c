#include <stdio.h>

int main() 
{
  
    int numofexpyear, age, qualified;
	printf("Enter number of year of experience: ");
	scanf("%f", &numofexpyear);
    printf("Enter age: ");
	scanf("%d", &age);
    printf("Qualified (1 - Yes, 0 - No): ");
	scanf("%d", &qualified);

    if (qualified == 1 && numofexpyear > 5 && age > 30) {
        printf("Decision : Call for interview");
    } else if (qualified == 1 && numofexpyear > 5 && age < 30) {
        printf("Decision : Call for interview");
    } else if (qualified == 1 && numofexpyear < 5 && age > 30) {
        printf("Decision : Rejected");
    } else if (qualified == 1 && numofexpyear < 5 && age < 30) {
        printf("Decision : Record will be kept on file");
    } else if (qualified == 0 && numofexpyear > 5 && age > 30) {
        printf("Decision : Call for interview");
    } else if (qualified == 0 && numofexpyear < 5 && age < 30) {
        printf("Decision : Record will be kept on file");
    } else if (qualified == 0 && numofexpyear < 5 && age > 30) {
        printf("Decision : Rejected");
    } else {
        printf("Decision : Rejected");
    }

    return 0;
}