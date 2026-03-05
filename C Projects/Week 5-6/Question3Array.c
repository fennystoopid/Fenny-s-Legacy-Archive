#include <stdio.h>

int main() {

    int ItemCode[7] = {1001, 1002, 1003, 1004, 1005, 1006, 1007}, option, searchkey_int, ordernum, var = 0;
    float Price[7] = {3.00, 6.00, 5.00, 10.00, 2.50, 3.50, 9.00}, priceorder[100], quantity, total;

    menu:
    printf("\nMenu\n1: New Transaction\n2: Exit\nOption: ");
    scanf("%i", &option);
    printf("\n");

    while (option == 1) {

        printf("Enter Item Code (Enter -1 to checkout) : ");
        scanf("%i", &searchkey_int);

        if (searchkey_int == -1) {
            for (int k = 0; k <= var;k++) {
                total += priceorder[k];
            }
            printf("Total Amount (RM): %.2f\n", total);
            var = 0;
            option = 2;
            goto menu;
        }

        for (int i = 0; i < 7;i++) {
            if (ItemCode[i] == searchkey_int) {
                ordernum = i;
                printf("Enter Quantity : ");
                scanf("%f", &quantity);
                priceorder[var] = Price[ordernum] * quantity;
                var++;
                break;
            }
        }

        
        
    }
    
}