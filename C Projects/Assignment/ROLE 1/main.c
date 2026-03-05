#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "product.h"

void showMenu();
void loadProducts(Product products[], int *count);
void saveProducts(Product products[], int count);

int main() {
    Product products[100]; // maximum of 100 products
    int count = 0;
    int choice;

    loadProducts(products, &count);

    do {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to catch newline

        switch(choice) {
            case 1: addProduct(products, &count); break;
            case 2: viewProducts(products, count); break;
            case 3: updateProduct(products, count); break;
            case 4: deleteProduct(products, &count); break;
            case 5: saveProducts(products, count); printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while(choice != 5);

    return 0;
}

void showMenu() {
    printf("\n=== Pharmacy Inventory Management ===\n");
    printf("1. Add Product\n");
    printf("2. View Products\n");
    printf("3. Update Product\n");
    printf("4. Delete Product\n");
    printf("5. Save and Exit\n");
}

void loadProducts(Product products[], int *count) {
    FILE *file = fopen("products.txt", "r");
    if (file == NULL) {
        printf("No existing data found.\n");
        return;
    }

    while (fscanf(file, "%d %s %f %d", 
        &products[*count].id, 
        products[*count].name, 
        &products[*count].price, 
        &products[*count].quantity) != EOF) {
        (*count)++;
    }

    fclose(file);
}

void saveProducts(Product products[], int count) {
    FILE *file = fopen("products.txt", "w");
    if (file == NULL) {
        printf("Could not save data.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%d %s %.2f %d\n", 
            products[i].id, 
            products[i].name, 
            products[i].price, 
            products[i].quantity);
    }

    fclose(file);
}
