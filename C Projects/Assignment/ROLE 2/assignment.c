#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 50
#define INVENTORY_FILE "inventory.txt"

// ---------- Data Structure for Stock Item ----------
typedef struct {
    int id;
    char name[NAME_LENGTH];
    int quantity;
    int lowStockThreshold;
    int isActive;  // 1 = Active, 0 = Discontinued
} StockItem;

StockItem inventory[MAX_ITEMS];
int itemCount = 0;

// ---------- Function Declarations ----------
void addStockItem();
void updateStockLevel();
void removeStockItem();
void viewInventory();
void checkLowStock();
void generateInventoryReport();
void saveInventoryToFile();
void loadInventoryFromFile();
void menu();

// ---------- Main Function ----------
int main() {
    int choice;

    loadInventoryFromFile();  // Load existing inventory (if any)

    do {
        menu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar();  // To consume newline left by scanf

        switch(choice) {
            case 1: addStockItem(); break;
            case 2: updateStockLevel(); break;
            case 3: removeStockItem(); break;
            case 4: viewInventory(); break;
            case 5: checkLowStock(); break;
            case 6: generateInventoryReport(); break;
            case 0: 
                saveInventoryToFile();  // Save before exiting
                printf("\nExiting... Inventory saved. Thank you!\n"); 
                break;
            default: printf("\nInvalid choice! Try again.\n");
        }
    } while(choice != 0);

    return 0;
}

// ---------- Menu ----------
void menu() {
    printf("\n=== Pharmacy Inventory Management ===\n");
    printf("1. Add Stock Item\n");
    printf("2. Update Stock Level\n");
    printf("3. Remove Discontinued Item\n");
    printf("4. View Current Inventory\n");
    printf("5. Check Low Stock Alerts\n");
    printf("6. Generate Inventory Report\n");
    printf("0. Exit\n");
}

// ---------- Add New Stock Item ----------
void addStockItem() {
    if(itemCount >= MAX_ITEMS) {
        printf("\nInventory full! Cannot add more items.\n");
        return;
    }

    StockItem item;
    item.id = itemCount + 1;

    printf("\nEnter item name: ");
    fgets(item.name, NAME_LENGTH, stdin);
    item.name[strcspn(item.name, "\n")] = '\0';  // Remove newline char

    printf("Enter quantity: ");
    scanf("%d", &item.quantity);

    printf("Set low stock threshold: ");
    scanf("%d", &item.lowStockThreshold);

    item.isActive = 1;

    inventory[itemCount++] = item;

    printf("\nItem added successfully with ID: %d\n", item.id);
    saveInventoryToFile();  // Save after adding
}

// ---------- Update Stock Level ----------
void updateStockLevel() {
    int id, change;
    printf("\nEnter Item ID to update: ");
    scanf("%d", &id);

    for(int i = 0; i < itemCount; i++) {
        if(inventory[i].id == id && inventory[i].isActive) {
            printf("Current quantity of '%s': %d\n", inventory[i].name, inventory[i].quantity);
            printf("Enter quantity change (+ to add, - to reduce): ");
            scanf("%d", &change);

            inventory[i].quantity += change;

            if(inventory[i].quantity < 0)
                inventory[i].quantity = 0;

            printf("Updated quantity: %d\n", inventory[i].quantity);
            saveInventoryToFile();  // Save after update
            return;
        }
    }
    printf("\nItem ID not found or inactive.\n");
}

// ---------- Remove Discontinued Item ----------
void removeStockItem() {
    int id;
    printf("\nEnter Item ID to remove (discontinue): ");
    scanf("%d", &id);

    for(int i = 0; i < itemCount; i++) {
        if(inventory[i].id == id && inventory[i].isActive) {
            inventory[i].isActive = 0;
            printf("Item '%s' marked as discontinued.\n", inventory[i].name);
            saveInventoryToFile();  // Save after removal
            return;
        }
    }
    printf("\nItem ID not found or already discontinued.\n");
}

// ---------- View Current Inventory ----------
void viewInventory() {
    printf("\n--- Current Inventory Status ---\n");
    printf("ID\tName\t\tQty\tStatus\n");

    for(int i = 0; i < itemCount; i++) {
        if(inventory[i].isActive) {
            printf("%d\t%-15s\t%d\tActive\n", inventory[i].id, inventory[i].name, inventory[i].quantity);
        }
    }
}

// ---------- Low Stock Alert ----------
void checkLowStock() {
    printf("\n--- Low Stock Items ---\n");
    int found = 0;

    for(int i = 0; i < itemCount; i++) {
        if(inventory[i].isActive && inventory[i].quantity <= inventory[i].lowStockThreshold) {
            printf("ALERT: Item '%s' (ID: %d) has low stock: %d (Threshold: %d)\n",
                inventory[i].name, inventory[i].id, inventory[i].quantity, inventory[i].lowStockThreshold);
            found = 1;
        }
    }

    if(!found) {
        printf("All items are sufficiently stocked.\n");
    }
}

// ---------- Inventory Report ----------
void generateInventoryReport() {
    printf("\n--- Inventory Report ---\n");
    printf("ID\tName\t\tQty\tThreshold\tStatus\n");

    for(int i = 0; i < itemCount; i++) {
        printf("%d\t%-15s\t%d\t%d\t\t%s\n",
            inventory[i].id,
            inventory[i].name,
            inventory[i].quantity,
            inventory[i].lowStockThreshold,
            inventory[i].isActive ? "Active" : "Discontinued");
    }
}

// ---------- Save Inventory to File ----------
void saveInventoryToFile() {
    FILE *file = fopen(INVENTORY_FILE, "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }

    for (int i = 0; i < itemCount; i++) {
        fprintf(file, "%d,%s,%d,%d,%d\n",
                inventory[i].id,
                inventory[i].name,
                inventory[i].quantity,
                inventory[i].lowStockThreshold,
                inventory[i].isActive);
    }

    fclose(file);
    printf("Inventory saved to '%s'.\n", INVENTORY_FILE);
}

// ---------- Load Inventory from File ----------
void loadInventoryFromFile() {
    FILE *file = fopen(INVENTORY_FILE, "r");
    if (file == NULL) {
        printf("No previous inventory found. Starting fresh.\n");
        return;
    }

    itemCount = 0;
    while (fscanf(file, "%d,%49[^,],%d,%d,%d\n",
                  &inventory[itemCount].id,
                  inventory[itemCount].name,
                  &inventory[itemCount].quantity,
                  &inventory[itemCount].lowStockThreshold,
                  &inventory[itemCount].isActive) == 5) {
        itemCount++;
    }

    fclose(file);
    printf("Inventory loaded from '%s'.\n", INVENTORY_FILE);
}


