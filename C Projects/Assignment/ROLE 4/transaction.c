#include <stdio.h>
#include <string.h>
#include "transaction.h"

#define FILE_NAME "transactions.txt"

// Add a new transaction
void recordTransaction(int userID) {
    FILE *f = fopen(FILE_NAME, "a");
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

// Show transactions
void showTransactions() {
    FILE *f = fopen(FILE_NAME, "r");
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

// Edit transaction
void editTransaction() {
    FILE *f = fopen(FILE_NAME, "r+");
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

// Archive a transaction
void archiveTransaction() {
    FILE *f = fopen(FILE_NAME, "r+");
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
