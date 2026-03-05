#include <stdio.h>
#include <string.h>
#include "product.h"

void addProduct(Product products[], int *count) {
    Product p;
    printf("Enter product ID: ");
    scanf("%d", &p.id);
    getchar(); // absorb newline

    printf("Enter product name: ");
    fgets(p.name, sizeof(p.name), stdin);
    p.name[strcspn(p.name, "\n")] = '\0'; // remove newline

    printf("Enter price: ");
    scanf("%f", &p.price);

    printf("Enter quantity: ");
    scanf("%d", &p.quantity);

    products[*count] = p;
    (*count)++;
    printf("Product added successfully.\n");
}

void viewProducts(Product products[], int count) {
    printf("\n--- Product List ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d\n", products[i].id);
        printf("Name: %s\n", products[i].name);
        printf("Price: %.2f\n", products[i].price);
        printf("Quantity: %d\n", products[i].quantity);
        printf("----------------------\n");
    }
}

void updateProduct(Product products[], int count) {
    int id, found = 0;
    printf("Enter product ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (products[i].id == id) {
            printf("Enter new name: ");
            getchar();
            fgets(products[i].name, sizeof(products[i].name), stdin);
            products[i].name[strcspn(products[i].name, "\n")] = '\0';

            printf("Enter new price: ");
            scanf("%f", &products[i].price);

            printf("Enter new quantity: ");
            scanf("%d", &products[i].quantity);

            printf("Product updated.\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Product not found.\n");
}

void deleteProduct(Product products[], int *count) {
    int id, found = 0;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < *count; i++) {
        if (products[i].id == id) {
            for (int j = i; j < *count - 1; j++) {
                products[j] = products[j + 1];
            }
            (*count)--;
            printf("Product deleted.\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Product not found.\n");
}
