#ifndef TRANSACTION_H
#define TRANSACTION_H

typedef struct {
    int transactionID;
    int userID;
    char date[20];
    char status[20];
    float amount;
    int active;
} Transaction;

void recordTransaction(int);
void showTransactions();
void editTransaction();
void archiveTransaction();

#endif
