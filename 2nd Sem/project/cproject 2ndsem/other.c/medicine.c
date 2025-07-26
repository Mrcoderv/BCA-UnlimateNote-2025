#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Structure to store medicine information
typedef struct {
    char name[50];
    int quantity;
    float price;
    char expiration_date[10];
} Medicine;

// Function to add a new medicine to the inventory
void add_medicine(Medicine *inventory, int *size) {
    Medicine new_medicine;
    printf("Enter medicine name: ");
    scanf("%s", new_medicine.name);
    printf("Enter quantity: ");
    scanf("%d", &new_medicine.quantity);
    printf("Enter price: ");
    scanf("%f", &new_medicine.price);
    printf("Enter expiration date (DD/MM/YYYY): ");
    scanf("%s", new_medicine.expiration_date);

    inventory[*size] = new_medicine;
    (*size)++;
}

// Function to display all medicines in the inventory
void display_medicines(Medicine *inventory, int size) {
    printf("Medicine Inventory:\n");
    for (int i = 0; i < size; i++) {
        printf("Name: %s, Quantity: %d, Price: %.2f, Expiration Date: %s\n",
               inventory[i].name, inventory[i].quantity, inventory[i].price, inventory[i].expiration_date);
    }
}

// Function to search for a medicine by name
void search_medicine(Medicine *inventory, int size) {
    char search_name[50];
    printf("Enter medicine name to search: ");
    scanf("%s", search_name);

    int found = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(inventory[i].name, search_name) == 0) {
            printf("Medicine found: Name: %s, Quantity: %d, Price: %.2f, Expiration Date: %s\n",
                   inventory[i].name, inventory[i].quantity, inventory[i].price, inventory[i].expiration_date);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Medicine not found.\n");
    }
}

// Function to update the quantity of a medicine
void update_quantity(Medicine *inventory, int size) {
    char update_name[50];
    printf("Enter medicine name to update: ");
    scanf("%s", update_name);

    int found = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(inventory[i].name, update_name) == 0) {
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Quantity updated successfully.\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Medicine not found.\n");
    }
}

// Function to delete a medicine from the inventory
void delete_medicine(Medicine *inventory, int *size) {
    char delete_name[50];
    printf("Enter medicine name to delete: ");
    scanf("%s", delete_name);

    int found = 0;
    for (int i = 0; i < *size; i++) {
        if (strcmp(inventory[i].name, delete_name) == 0) {
            for (int j = i; j < *size - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            (*size)--;
            printf("Medicine deleted successfully.\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Medicine not found.\n");
    }
}

// Function to save the inventory to a CSV file
void save_to_file(Medicine *inventory, int size) {
    FILE *file = fopen("medicine.csv", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    fprintf(file, "Name,Quantity,Price,Expiration Date\n");
    for (int i = 0; i < size; i++) {
        fprintf(file, "%s,%d,%.2f,%s\n", inventory[i].name, inventory[i].quantity, inventory[i].price, inventory[i].expiration_date);
    }
    fclose(file);
    printf("Inventory saved to medicine.csv\n");
}

// Function to load the inventory from a CSV file
void load_from_file(Medicine *inventory, int *size) {
    FILE *file = fopen("medicine.csv", "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }
    char line[100];
    fgets(line, sizeof(line), file); // Skip the header line
    while (fgets(line, sizeof(line), file)) {
        Medicine new_medicine;
        sscanf(line, "%[^,],%d,%f,%[^,\n]", new_medicine.name, &new_medicine.quantity, &new_medicine.price, new_medicine.expiration_date);
        inventory[*size] = new_medicine;
        (*size)++;
    }
    fclose(file);
    printf("Inventory loaded from medicine.csv\n");
}

int main() {
    Medicine inventory[100];
    int size = 0;

    load_from_file(inventory, &size);

    int choice;
    while (1) {
        printf("Medical Store Management System\n");
        printf("1. Add Medicine\n");
        printf("2. Display Medicines\n");
        printf("3. Search Medicine\n");
        printf("4. Update Quantity\n");
        printf("5. Delete Medicine\n");
        printf("6. Save and Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_medicine(inventory, &size);
                break;
            case 2:
                display_medicines(inventory, size);
                break;
            case 3:
                search_medicine(inventory, size);
                break;
            case 4:
                update_quantity(inventory, size);
                break;
            case 5:
                delete_medicine(inventory, &size);
                break;
            case 6:
                save_to_file(inventory, size);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
