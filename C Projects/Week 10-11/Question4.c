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

    struct student s[5];

    for (int i = 0; i < 5; i++) {

        printf("Enter student %d first name: ", i + 1);
        scanf(" %14s", &s[i].firstName);

        printf("Enter student %d last name: ", i + 1);
        scanf("%14s", &s[i].lastName);

        printf("Enter student %d house number: ", i + 1);
        scanf("%d", &s[i].homeAddress.housenumber);
        getchar(); // clear newline after number input
  
        printf("Enter student %d street: ", i + 1);
        fgets(s[i].homeAddress.street, sizeof(s[i].homeAddress.street), stdin);
        s[i].homeAddress.street[strcspn(s[i].homeAddress.street, "\n")] = '\0'; // remove newline

        printf("Enter student %d city: ", i + 1);
        fgets(s[i].homeAddress.city, sizeof(s[i].homeAddress.city), stdin);
        s[i].homeAddress.city[strcspn(s[i].homeAddress.city, "\n")] = '\0'; // remove newline

        printf("Enter student %d state (2 letters): ", i + 1);
        scanf("%2s", &s[i].homeAddress.state);

        printf("Enter student %d zip code: ", i + 1);
        scanf("%5s", &s[i].homeAddress.zipCode);
        getchar(); // clear newline after zip code
    
    };

    // Display the information for the last student entered
    for (int i = 0; i < 5; i++) {
        printf("\n--- Student %d Information ---\n", i + 1);
        printf("Name: %s %s\n", s[i].firstName, s[i].lastName);
        printf("Address: %d %s, %s, %s, %s\n",
            s[i].homeAddress.housenumber,
            s[i].homeAddress.street,
            s[i].homeAddress.city,
            s[i].homeAddress.state,
            s[i].homeAddress.zipCode);
        printf("\n");
    };
    
    return 0;
};