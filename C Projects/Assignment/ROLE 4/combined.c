#include <stdio.h>
#include <string.h>

// ---------- STRUCT DEFINITIONS ----------

typedef struct {
    int userID;
    char username[50];
    char password[30];
    char role[20];
    int active;
} User;

typedef struct {
    int transactionID;
    int userID;
    char date[20];
    char status[20];
    float amount;
    int active;
} Transaction;

// ---------- USER FUNCTIONS ----------

#define USER_FILE "users.txt"

// Register a new user (text-based)
void registerNewUser() {
    FILE *f = fopen(USER_FILE, "a");
    User u;

    printf("Registering a new user now!\n");
    printf("Enter User ID: ");
    scanf("%d", &u.userID);
    printf("Choose a username: ");
    scanf("%s", u.username);
    printf("Create a password: ");
    scanf("%s", u.password);
    printf("Role (admin/staff): ");
    scanf("%s", u.role);
    u.active = 1;

    fprintf(f, "%d,%s,%s,%s,%d\n", u.userID, u.username, u.password, u.role, u.active);
    fclose(f);
    printf("✅ User registered successfully!\n");
}

// Authenticate login (text-based)
int authenticateUser(const char *username, const char *password) {
    FILE *f = fopen(USER_FILE, "r");
    User u;

    if (!f) return -1;

    while (fscanf(f, "%d,%49[^,],%29[^,],%19[^,],%d\n",
                  &u.userID, u.username, u.password, u.role, &u.active) == 5) {
        if (u.active && strcmp(username, u.username) == 0 && strcmp(password, u.password) == 0) {
            fclose(f);
            return u.userID;
        }
    }
    fclose(f);
    return -1;
}

// Show users (text-based)
void showUsers() {
    FILE *f = fopen(USER_FILE, "r");
    User u;
    int count = 0;

    if (!f) {
        printf("No users found yet!\n");
        return;
    }

    printf("\n--- Active Users ---\n");
    while (fscanf(f, "%d,%49[^,],%29[^,],%19[^,],%d\n",
                  &u.userID, u.username, u.password, u.role, &u.active) == 5) {
        if (u.active) {
            printf("ID: %d | Username: %s | Role: %s\n", u.userID, u.username, u.role);
            count++;
        }
    }
    if (count == 0) {
        printf("No active users at this moment.\n");
    }
    fclose(f);
}

// Edit user (rewrites the whole file)
void editUser() {
    FILE *f = fopen(USER_FILE, "r");
    FILE *temp = fopen("temp_users.txt", "w");
    User u;
    int id, found = 0;

    if (!f || !temp) {
        printf("Error opening files.\n");
        return;
    }

    printf("Enter User ID to edit: ");
    scanf("%d", &id);

    while (fscanf(f, "%d,%49[^,],%29[^,],%19[^,],%d\n",
                  &u.userID, u.username, u.password, u.role, &u.active) == 5) {
        if (u.userID == id && u.active) {
            printf("Update Username: ");
            scanf("%s", u.username);
            printf("Update Password: ");
            scanf("%s", u.password);
            printf("Update Role: ");
            scanf("%s", u.role);
            found = 1;
        }
        fprintf(temp, "%d,%s,%s,%s,%d\n", u.userID, u.username, u.password, u.role, u.active);
    }

    fclose(f);
    fclose(temp);
    remove(USER_FILE);
    rename("temp_users.txt", USER_FILE);

    if (found)
        printf("✅ User updated!\n");
    else
        printf("User not found.\n");
}

// Archive user (rewrites the whole file)
void archiveUser() {
    FILE *f = fopen(USER_FILE, "r");
    FILE *temp = fopen("temp_users.txt", "w");
    User u;
    int id, found = 0;

    if (!f || !temp) {
        printf("Error opening files.\n");
        return;
    }

    printf("Enter User ID to archive: ");
    scanf("%d", &id);

    while (fscanf(f, "%d,%49[^,],%29[^,],%19[^,],%d\n",
                  &u.userID, u.username, u.password, u.role, &u.active) == 5) {
        if (u.userID == id && u.active) {
            u.active = 0;
            found = 1;
        }
        fprintf(temp, "%d,%s,%s,%s,%d\n", u.userID, u.username, u.password, u.role, u.active);
    }

    fclose(f);
    fclose(temp);
    remove(USER_FILE);
    rename("temp_users.txt", USER_FILE);

    if (found)
        printf("✅ User archived!\n");
    else
        printf("User not found or already archived.\n");
}

// ---------- TRANSACTION FUNCTIONS ----------

#define TRANSACTION_FILE "transactions.txt"

// Add a new transaction (binary)
void recordTransaction(int userID) {
    FILE *f = fopen(TRANSACTION_FILE, "ab");
    Transaction t;

    printf("Creating a new transaction...\n");
    printf("Transaction ID: ");
    scanf("%d", &t.transactionID);
    t.userID = userID;
    printf("Date (dd/mm/yyyy): ");
    scanf("%s", t.date);
    printf("Status: ");
    scanf("%s", t.status);
    printf("Amount: ");
    scanf("%f", &t.amount);
    t.active = 1;

    fwrite(&t, sizeof(Transaction), 1, f);
    fclose(f);
    printf("✅ Transaction recorded!\n");
}

// Show transactions (binary)
void showTransactions() {
    FILE *f = fopen(TRANSACTION_FILE, "rb");
    Transaction t;
    int count = 0;

    if (!f) {
        printf("No transactions yet!\n");
        return;
    }

    printf("\n--- Transactions ---\n");
    while (fread(&t, sizeof(Transaction), 1, f)) {
        if (t.active) {
            printf("ID: %d | UserID: %d | Date: %s | Status: %s | Amount: %.2f\n",
                   t.transactionID, t.userID, t.date, t.status, t.amount);
            count++;
        }
    }
    if (count == 0) {
        printf("No active transactions found.\n");
    }
    fclose(f);
}

// Edit transaction (binary)
void editTransaction() {
    FILE *f = fopen(TRANSACTION_FILE, "r+b");
    Transaction t;
    int id, found = 0;

    printf("Enter Transaction ID to edit: ");
    scanf("%d", &id);

    while (fread(&t, sizeof(Transaction), 1, f)) {
        if (t.active && t.transactionID == id) {
            printf("Update Status: ");
            scanf("%s", t.status);
            printf("Update Amount: ");
            scanf("%f", &t.amount);

            fseek(f, -sizeof(Transaction), SEEK_CUR);
            fwrite(&t, sizeof(Transaction), 1, f);
            found = 1;
            printf("✅ Transaction updated!\n");
            break;
        }
    }

    if (!found) printf("Transaction not found!\n");
    fclose(f);
}

// Archive transaction (binary)
void archiveTransaction() {
    FILE *f = fopen(TRANSACTION_FILE, "r+b");
    Transaction t;
    int id, found = 0;

    printf("Enter Transaction ID to archive: ");
    scanf("%d", &id);

    while (fread(&t, sizeof(Transaction), 1, f)) {
        if (t.active && t.transactionID == id) {
            t.active = 0;
            fseek(f, -sizeof(Transaction), SEEK_CUR);
            fwrite(&t, sizeof(Transaction), 1, f);
            found = 1;
            printf("✅ Transaction archived!\n");
            break;
        }
    }

    if (!found) printf("Transaction not found or already archived.\n");
    fclose(f);
}

// ---------- MAIN FUNCTION ----------

int main() {
    int choice, userID;
    char username[50], password[30];

    while (1) {
        printf("\n=== Welcome to User & Transaction System ===\n");
        printf("1. Register New User\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            registerNewUser();
        } else if (choice == 2) {
            printf("Username: ");
            scanf("%s", username);
            printf("Password: ");
            scanf("%s", password);

            userID = authenticateUser(username, password);
            if (userID == -1) {
                printf("Login failed! Check your username or password.\n");
            } else {
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
                        case 9: printf("Logged out.\n"); goto main_menu;
                        default: printf("Invalid option! Please select again.\n");
                    }
                }
            }
        } else if (choice == 3) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
        main_menu:;
    }
    return 0;
}