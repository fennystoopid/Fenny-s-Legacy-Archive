#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Admin.h"

//main function
int main() 
{
    int choice;
    do {
        printf("\n==================================\n");
        printf("--Administration Management Menu--");
        printf("\n==================================\n");
        printf("1. Create a new Text File\n");
        printf("2. Read a Text File\n");
        printf("3. Add/Append Data into Text File\n");
        printf("4. Delete data from Text File\n");
        printf("5. Update data in Text File\n");
        printf("6. Print a Report\n");
        printf("7. View all Text File in a Folder\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: create_file(); break;
            case 2: read_file(); break;
            case 3: append_data(); break;
            case 4: delete_data(); break;
            case 5: update_data(); break;
            case 6: print_report(); break;
            case 7: file_list(); break;
            case 0: printf("Exiting program.\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 0);

    return 0;
}