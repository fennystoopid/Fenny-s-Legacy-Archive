#include <stdio.h>
#include <string.h>

union Contact
{
	char email[50];
	long int phoneNumber;
	int number;
};

//prompt the user to fill in primary contact method and display the primary contact information at the end of the program.
int main() 
{
    union Contact UserInfo;
	int choice;

    printf("Select your primary contact method:\n1. Email\n2. Phone Number\nInsert your choice (1 or 2): ");
	scanf(" %d", &choice);

	if (choice == 1) {
		printf("Enter your email address: ");
		scanf(" %49s", &UserInfo.email);
		printf("Primary contact (Email): %s\n", UserInfo.email);
	} else if (choice == 2) {
		printf("Enter your phone number: ");
		scanf(" %ld", &UserInfo.phoneNumber);
		printf("Primary contact (Phone Number): %ld\n", UserInfo.phoneNumber);
	} else {
		printf("Invalid choice. Please run the program again.\n");
		return 1;
	}

	return 0;
};
