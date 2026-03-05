#include <stdio.h>
#include <string.h>
#include "user.h"

#define FILE_NAME "users.txt"

// Register a new user
void registerNewUser() {
    FILE *f = fopen(FILE_NAME, "a");
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

    fwrite(&u, sizeof(User), 1, f);
    fclose(f);
    printf("✅ User registered successfully!\n");
}

// Check login
int authenticateUser(const char *username, const char *password) {
    FILE *f = fopen(FILE_NAME, "r");
    User u;

    if (!f) return -1;

    while (fread(&u, sizeof(User), 1, f)) {
        if (u.active && strcmp(username, u.username) == 0 && strcmp(password, u.password) == 0) {
            fclose(f);
            return u.userID;
        }
    }
    fclose(f);
    return -1;
}

// Display active users
void showUsers() {
    FILE *f = fopen(FILE_NAME, "r");
    User u;
    int count = 0;

    if (!f) {
        printf("No users found yet!\n");
        return;
    }

    printf("\n--- Active Users ---\n");
    while (fread(&u, sizeof(User), 1, f)) {
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

// Edit existing user
void editUser() {
    FILE *f = fopen(FILE_NAME, "r+");
    User u;
    int id, found = 0;

    printf("Enter User ID to edit: ");
    scanf("%d", &id);

    while (fread(&u, sizeof(User), 1, f)) {
        if (u.active && u.userID == id) {
            printf("Update Username: ");
            scanf("%s", u.username);
            printf("Update Password: ");
            scanf("%s", u.password);
            printf("Update Role: ");
            scanf("%s", u.role);

            fseek(f, -sizeof(User), SEEK_CUR);
            fwrite(&u, sizeof(User), 1, f);
            found = 1;
            printf("✅ User updated!\n");
            break;
        }
    }

    if (!found) printf("User not found!\n");
    fclose(f);
}

// Archive a user
void archiveUser() {
    FILE *f = fopen(FILE_NAME, "r+");
    User u;
    int id, found = 0;

    printf("Enter User ID to archive: ");
    scanf("%d", &id);

    while (fread(&u, sizeof(User), 1, f)) {
        if (u.active && u.userID == id) {
            u.active = 0;
            fseek(f, -sizeof(User), SEEK_CUR);
            fwrite(&u, sizeof(User), 1, f);
            found = 1;
            printf("✅ User archived!\n");
            break;
        }
    }

    if (!found) printf("User not found or already archived.\n");
    fclose(f);
}
