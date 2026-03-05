#ifndef USER_H
#define USER_H

typedef struct {
    int userID;
    char username[50];
    char password[30];
    char role[20];
    int active;
} User;

void registerNewUser();
int authenticateUser(const char *, const char *);
void showUsers();
void editUser();
void archiveUser();

#endif
