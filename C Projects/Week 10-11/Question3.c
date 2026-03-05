#include <stdio.h>
#include <string.h>

struct student
{
	char firstName[15], lastName[15];
	struct{
		int housenumber;
		char street[25], city[20], state[3], zipCode[6];
    }homeAddress;
};

int main() {

    struct student s;

    printf("Enter first name: ");
    scanf(" %14s", &s.firstName);

    printf("Enter last name: ");
    scanf("%14s", &s.lastName);

    printf("Enter house number: ");
    scanf("%d", &s.homeAddress.housenumber);
    getchar(); // clear newline after number input
  
    printf("Enter street: ");
    fgets(s.homeAddress.street, sizeof(s.homeAddress.street), stdin);
    s.homeAddress.street[strcspn(s.homeAddress.street, "\n")] = '\0'; // remove newline

    printf("Enter city: ");
    fgets(s.homeAddress.city, sizeof(s.homeAddress.city), stdin);
    s.homeAddress.city[strcspn(s.homeAddress.city, "\n")] = '\0'; // remove newline

    printf("Enter state (2 letters): ");
    scanf("%2s", &s.homeAddress.state);

    printf("Enter zip code: ");
    scanf("%5s", &s.homeAddress.zipCode);

    printf("\n--- Student Information ---\n");
    printf("Name: %s %s\n", s.firstName, s.lastName);
    printf("Address: %d %s, %s, %s, %s\n",
           s.homeAddress.housenumber,
           s.homeAddress.street,
           s.homeAddress.city,
           s.homeAddress.state,
           s.homeAddress.zipCode);

    return 0;
};