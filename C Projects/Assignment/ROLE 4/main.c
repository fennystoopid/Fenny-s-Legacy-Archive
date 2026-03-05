#include <stdio.h>
#include <string.h>
#include "user.h"
#include "transaction.h"

// Main entry point
int main() {
    int choice, userID;
    char username[50], password[30];

    printf("=== Welcome to User & Transaction System ===\n");
    printf("Please log in first!\nUsername: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    userID = authenticateUser(username, password);
    if (userID == -1) {
        printf("Login failed! Check your username or password.\n");
        return 0;
    }

    while (1) {
        printf("\n--- Main Menu ---\n");
        printf("1. Register User\n2. Edit User\n3. Archive User\n4. View Users\n");
        printf("5. Record Transaction\n6. Edit Transaction\n7. Archive Transaction\n8. View Transactions\n9. Logout\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: registerNewUser(); break;
            case 2: editUser(); break;
            case 3: archiveUser(); break;
            case 4: showUsers(); break;
            case 5: recordTransaction(userID); break;
            case 6: editTransaction(); break;
            case 7: archiveTransaction(); break;
            case 8: showTransactions(); break;
            case 9: printf("Bye! Thanks for using the system.\n"); return 0;
            default: printf("Invalid option! Please select again.\n");
        }
    }
}
