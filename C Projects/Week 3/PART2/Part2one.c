#include <stdio.h>
#include <string.h>

int main()
{	
    float totalhours, hourlywage, weeklypay;
    char empname[50];
	printf("Enter name: ");
	scanf("%s",&empname);
    printf("Enter total number of hours worked: ");
	scanf("%f",&totalhours);
    printf("Enter hourly rate RM : ");
	scanf("%f",&hourlywage);
	if (totalhours <= 40) {
        weeklypay = totalhours * hourlywage;
    } else if (totalhours > 40) {
        weeklypay = (40 * hourlywage) + ((totalhours - 40) * 1.5 * hourlywage);
    }
	printf("%s recieved RM %.2f\n", empname, weeklypay);
}
