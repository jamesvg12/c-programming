#include <stdio.h>
#include <stdbool.h>

#define MAX_ITEMS 5

typedef struct {
    int code;
    char name[20];
    float price;
    int quantity;
} Item;

// Sample shop items
Item shopItems[MAX_ITEMS] = {
    {1, "Apple", 0.50, 0},
    {2, "Bread", 1.00, 0},
    {3, "Milk", 1.50, 0},
    {4, "Eggs", 2.00, 0},
    {5, "Cheese", 2.50, 0}
};

void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Add items to shopping cart\n");
    printf("2. Show current total\n");
    printf("3. Check out\n");
    printf("4. Cancel session\n");
    printf("q. Quit\n");
    printf("Choose an option: ");
}

void displayItems() {
    printf("\nAvailable items:\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        printf("%d - %s - $%.2f\n", shopItems[i].code, shopItems[i].name, shopItems[i].price);
    }
}

float calculateTotal() {
    float total = 0.0;
    for (int i = 0; i < MAX_ITEMS; i++) {
        total += shopItems[i].price * shopItems[i].quantity;
    }
    return total;
}

void displayCart() {
    printf("\nYour shopping cart:\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (shopItems[i].quantity > 0) {
            printf("%s - %d x $%.2f = $%.2f\n",
                   shopItems[i].name, shopItems[i].quantity,
                   shopItems[i].price,
                   shopItems[i].price * shopItems[i].quantity);
        }
    }
    printf("Total: $%.2f\n", calculateTotal());
}

void clearCart() {
    for (int i = 0; i < MAX_ITEMS; i++) {
        shopItems[i].quantity = 0;
    }
}

bool confirmAction(const char* action) {
    char response;
    printf("Are you sure you want to %s? (y/n): ", action);
    scanf(" %c", &response);
    return response == 'y' || response == 'Y';
}

int main() {
    char option;
    bool running = true;

    while (running) {
        displayMenu();
        scanf(" %c", &option);

        switch (option) {
            case '1': {
                displayItems();
                int code, qty;
                printf("Enter the item code to add: ");
                scanf("%d", &code);

                if (code < 1 || code > MAX_ITEMS) {
                    printf("Invalid item code.\n");
                    break;
                }

                printf("Enter the quantity: ");
                scanf("%d", &qty);
                shopItems[code - 1].quantity += qty;
                printf("Added %d x %s to your cart.\n", qty, shopItems[code - 1].name);
                break;
            }

            case '2': {
                printf("\nCurrent total: $%.2f\n", calculateTotal());
                break;
            }

            case '3': {
                if (confirmAction("check out")) {
                    displayCart();
                    clearCart();
                    printf("\nSession reset. Start a new shopping session.\n");
                }
                break;
            }

            case '4': {
                if (confirmAction("cancel the session")) {
                    clearCart();
                    printf("\nSession canceled. Start a new shopping session.\n");
                }
                break;
            }

            case 'q': {
                if (confirmAction("quit the program")) {
                    running = false;
                }
                break;
            }

            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    printf("Thank you for shopping!\n");
    return 0;
}
