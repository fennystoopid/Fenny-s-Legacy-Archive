#ifndef PRODUCT_H
#define PRODUCT_H

typedef struct {
    int id;
    char name[30];
    float price;
    int quantity;
} Product;

void addProduct(Product products[], int *count);
void viewProducts(Product products[], int count);
void updateProduct(Product products[], int count);
void deleteProduct(Product products[], int *count);

#endif
