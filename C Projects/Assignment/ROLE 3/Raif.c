#include <stdio.h>
#include <string.h>

#define MAX_ID 10
#define MAX_NAME 50
#define MAX_ITEMS 100

typedef struct {
    char id[MAX_ID];
    char name[MAX_NAME];
} Category;

typedef struct {
    char id[MAX_ID];
    char name[MAX_NAME];
    char contact[MAX_NAME];
} Supplier;

// -------------------- CATEGORY PROTOTYPE FUNCTIONS --------------------
void addCategory();
void viewCategories();
void updateCategory();
void deleteCategory();
void sortCategories();
void searchCategoryByIdOrName(); 

// -------------------- SUPPLIER PROTOTYPE FUNCTIONS --------------------
void addSupplier();
void viewSuppliers();
void updateSupplier();
void deleteSupplier();
void sortSuppliers();
void searchSupplierByIdOrName(); 

// -------------------- CATEGORY FUNCTIONS --------------------

void addCategory() {
    FILE *f = fopen("categories.txt", "a");
    if (!f) return;

    Category c;
    printf("Enter Category ID: ");
    scanf("%s", c.id);
    printf("Enter Category Name: ");
    scanf(" %[^\n]", c.name);

    fprintf(f, "%s|%s\n", c.id, c.name);
    fclose(f);
    printf("Category added :3!");
}

void viewCategories() {
    FILE *f = fopen("categories.txt", "r");
    if (!f) { printf("No categories :/");
         return; 
    }

    Category c;
    printf("\nList of Categories:\n");
    while (fscanf(f, "%[^|]|%[^\n]\n", c.id, c.name) == 2)
        printf("ID: %s, Name: %s", c.id, c.name);
    fclose(f);
}

void updateCategory() {
    Category list[MAX_ITEMS];
    int count = 0;
    FILE *f = fopen("categories.txt", "r");
    if (!f) { printf("No categories."); 
        return; 
    }

    while (fscanf(f, "%[^|]|%[^\n]\n", list[count].id, list[count].name) == 2)
        count++;
    fclose(f);

    char id[MAX_ID];
    printf("Enter Category ID to update: ");
    scanf("%s", id);

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(list[i].id, id) == 0) {
            printf("Enter new name: ");
            scanf(" %[^\n]", list[i].name);
            found = 1;
            break;
        }
    }
    if (!found) { printf("Category not found"); return; }

    f = fopen("categories.txt", "w");
    for (int i = 0; i < count; i++)
        fprintf(f, "%s|%s\n", list[i].id, list[i].name);
    fclose(f);
    printf("Category updated");
}

void deleteCategory() {
    Category list[MAX_ITEMS];
    int count = 0;
    FILE *f = fopen("categories.txt", "r");
    if (!f) { printf("No categories"); return; }

    while (fscanf(f, "%[^|]|%[^\n]\n", list[count].id, list[count].name) == 2)
        count++;
    fclose(f);

    char id[MAX_ID];
    printf("Enter Category ID to delete: ");
    scanf("%s", id);

    f = fopen("categories.txt", "w");
    for (int i = 0; i < count; i++)
        if (strcmp(list[i].id, id) != 0)
            fprintf(f, "%s|%s\n", list[i].id, list[i].name);
    fclose(f);
    printf("Category deleted :>");
}

//bubble sort untuk sort by categories alphabetically huhu (extra features ni)
void sortCategories() {
    Category list[MAX_ITEMS];
    int count = 0;
    FILE *f = fopen("categories.txt", "r");
    if (!f) { printf("No categories.\n"); return; }

    while (fscanf(f, "%[^|]|%[^\n]\n", list[count].id, list[count].name) == 2)
        count++;
    fclose(f);

    for (int i = 0; i < count - 1; i++)
        for (int j = 0; j < count - i - 1; j++)
            if (strcmp(list[j].name, list[j + 1].name) > 0) {
                Category tmp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = tmp;
            }

    printf("\nSorted Categories:\n");
    for (int i = 0; i < count; i++)
        printf("ID: %s, Name: %s\n", list[i].id, list[i].name);
}

void searchCategoryByIdOrName() {
    FILE *f = fopen("categories.txt", "r");
    if (!f) {
        printf("No categories found.\n");
        return;
    }

    char keyword[MAX_NAME];
    int found = 0;
    printf("Enter Category ID or Name to search: ");
    scanf(" %[^\n]", keyword);

    Category c;
    printf("\nSearch Results:\n");
    while (fscanf(f, "%[^|]|%[^\n]\n", c.id, c.name) == 2) {
        if (strcmp(c.id, keyword) == 0 || strcasecmp(c.name, keyword) == 0) {
            printf("ID: %s, Name: %s\n", c.id, c.name);
            found = 1;
        }
    }

    if (!found) {
        printf("No matching category found.\n");
    }

    fclose(f);
}

// -------------------- SUPPLIER FUNCTIONS --------------------

void addSupplier() {
    FILE *f = fopen("suppliers.txt", "a");
    if (!f) return;

    Supplier s;
    printf("Enter Supplier ID: ");
    scanf("%s", s.id);
    printf("Enter Supplier Name: ");
    scanf(" %[^\n]", s.name);
    printf("Enter Supplier Contact: ");
    scanf(" %[^\n]", s.contact);

    fprintf(f, "%s|%s|%s\n", s.id, s.name, s.contact);
    fclose(f);
    printf("Supplier added :p");
}

void viewSuppliers() {
    FILE *f = fopen("suppliers.txt", "r");
    if (!f) { printf("No suppliers :("); return; }

    Supplier s;
    printf("\nList of Suppliers:\n");
    while (fscanf(f, "%[^|]|%[^|]|%[^\n]\n", s.id, s.name, s.contact) == 3)
        printf("ID: %s, Name: %s, Contact: %s", s.id, s.name, s.contact);
    fclose(f);
}

void updateSupplier() {
    Supplier list[MAX_ITEMS];
    int count = 0;
    FILE *f = fopen("suppliers.txt", "r");
    if (!f) { printf("No suppliers"); return; }

    while (fscanf(f, "%[^|]|%[^|]|%[^\n]\n", list[count].id, list[count].name, list[count].contact) == 3)
        count++;
    fclose(f);

    char id[MAX_ID];
    printf("Enter Supplier ID to update: ");
    scanf("%s", id);

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(list[i].id, id) == 0) {
            printf("Enter new name: ");
            scanf(" %[^\n]", list[i].name);
            printf("Enter new contact: ");
            scanf(" %[^\n]", list[i].contact);
            found = 1;
            break;
        }
    }
    if (!found) { printf("Supplier not found..."); return; }

    f = fopen("suppliers.txt", "w");
    for (int i = 0; i < count; i++)
        fprintf(f, "%s|%s|%s\n", list[i].id, list[i].name, list[i].contact);
    fclose(f);
    printf("Supplier updated :D");
}

void deleteSupplier() {
    Supplier list[MAX_ITEMS];
    int count = 0;
    FILE *f = fopen("suppliers.txt", "r");
    if (!f) { printf("No suppliers"); return; }

    while (fscanf(f, "%[^|]|%[^|]|%[^\n]\n", list[count].id, list[count].name, list[count].contact) == 3)
        count++;
    fclose(f);

    char id[MAX_ID];
    printf("Enter Supplier ID to delete: ");
    scanf("%s", id);

    f = fopen("suppliers.txt", "w");
    for (int i = 0; i < count; i++)
        if (strcmp(list[i].id, id) != 0)
            fprintf(f, "%s|%s|%s\n", list[i].id, list[i].name, list[i].contact);
    fclose(f);
    printf("Supplier deleted ;(");
}

// this one is also bubble sort where it sorts suppliers alhabetically too huhu (extra features too :/) 
void sortSuppliers() {
    Supplier list[MAX_ITEMS];
    int count = 0;
    FILE *f = fopen("suppliers.txt", "r");
    if (!f) { printf("No suppliers"); return; }

    while (fscanf(f, "%[^|]|%[^|]|%[^\n]\n", list[count].id, list[count].name, list[count].contact) == 3)
        count++;
    fclose(f);

    for (int i = 0; i < count - 1; i++)
        for (int j = 0; j < count - i - 1; j++)
            if (strcmp(list[j].name, list[j + 1].name) > 0) {
                Supplier tmp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = tmp;
            }

    printf("\nSorted Suppliers:\n");
    for (int i = 0; i < count; i++)
        printf("ID: %s, Name: %s, Contact: %s\n", list[i].id, list[i].name, list[i].contact);
}

// extra features where it searches by name or ID yeay :>>
void searchSupplierByIdOrName() {
    FILE *f = fopen("suppliers.txt", "r");
    if (!f) {
        printf("No suppliers found.\n");
        return;
    }

    char keyword[MAX_NAME];
    int found = 0;
    printf("Enter Supplier ID or Name to search: ");
    scanf(" %[^\n]", keyword);

    Supplier s;
    printf("\nSearch Results:\n");
    while (fscanf(f, "%[^|]|%[^|]|%[^\n]\n", s.id, s.name, s.contact) == 3) {
        if (strcmp(s.id, keyword) == 0 || strcasecmp(s.name, keyword) == 0) {
            printf("ID: %s, Name: %s, Contact: %s\n", s.id, s.name, s.contact);
            found = 1;
        }
    }

    if (!found) {
        printf("No matching supplier found.\n");
    }

    fclose(f);
}

// -------------------- MAIN MENU --------------------

int main() {
    int choice;

    do {
        printf("\n===============================================\n");
        printf("   Pharmacy Category & Supplier Management\n");
        printf("===============================================\n");
        printf("  1. Add Category\n");
        printf("  2. View Categories\n");
        printf("  3. Update Category\n");
        printf("  4. Delete Category\n");
        printf("  5. Sort Categories\n");
        printf("  6. Add Supplier\n");
        printf("  7. View Suppliers\n");
        printf("  8. Update Supplier\n");
        printf("  9. Delete Supplier\n");
        printf(" 10. Sort Suppliers\n");
        printf(" 11. Search Category by ID or Name\n");
        printf(" 12. Search Supplier by ID or Name\n");
        printf("  0. Exit\n");
        printf("===============================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("-----------------------------------------------\n");

        switch (choice) {
            case 1: addCategory(); 
                break;
            case 2: viewCategories(); 
                break;
            case 3: updateCategory(); 
                break;
            case 4: deleteCategory(); 
                break;
            case 5: sortCategories(); 
                break;
            case 6: addSupplier(); 
                break;
            case 7: viewSuppliers(); 
                break;
            case 8: updateSupplier(); 
                break;
            case 9: deleteSupplier(); 
                break;
            case 10: sortSuppliers(); 
                break;
            case 11: searchCategoryByIdOrName(); 
                break;
            case 12: searchSupplierByIdOrName(); 
                break;
            case 0: printf("Exiting the system. Goodbye!\n"); 
                break;
            default: printf("Invalid choice. Please try again....\n");
        }

    } while (choice != 0);

    return 0;
}
