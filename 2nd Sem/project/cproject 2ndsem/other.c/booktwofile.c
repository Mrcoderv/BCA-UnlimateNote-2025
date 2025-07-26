#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct addbook {
    char name[50];
    char author[50];
    int number;
    float cost;
    int year;
    int quantity;
} a[100];

struct Book {
    char customer_name[50];
    char customer_number[50];
    char name[50];
    int number;
    char author[50];
    float cost;
    int year;
} b[100];

int count = 0;
int flag = 0;

// Function to save information in file
void save_books() {
    FILE *fp = fopen("book.txt", "w");
    if (fp == NULL) {
        printf("\tError opening file.\n");
        return;
    }

    // Save books available in store
    for (int i = 0; i < flag; i++) {
        if (a[i].quantity > 0) {
            fprintf(fp, "%s,%s,%d,%.2f,%d,%d\n", a[i].name, a[i].author, a[i].number, a[i].cost, a[i].year, a[i].quantity);
        }
    }

    fclose(fp);
    printf("\tBook information saved to 'book.txt'.\n");
}

// Function to save sold books in a separate file
void save_sold_books() {
    FILE *fp = fopen("sold_books.txt", "w");
    if (fp == NULL) {
        printf("\tError opening file.\n");
        return;
    }

    // Save sold books
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s,%s,%s,%d,%s,%.2f,%d\n", b[i].customer_name, b[i].customer_number, b[i].name, b[i].number, b[i].author, b[i].cost, b[i].year);
    }

    fclose(fp);
    printf("\tSold book information saved to 'sold_books.txt'.\n");
}

// Function to add books in store
void add_books() {
    int x;
    printf("\tEnter the number of books to add in store: ");
    scanf("%d", &x);
    printf("\t-------------------------------------------\n");

    if (flag + x > 100) {
        printf("\tMaximum number of books reached. Cannot add more.\n");
        return;
    }

    for (int i = 0; i < x; i++) {
        printf("\tEnter details of book %d\n", i + 1);

        printf("\tEnter book name: ");
        while (getchar() != '\n');
        fgets(a[flag + i].name, sizeof(a[flag + i].name), stdin);
        a[flag + i].name[strcspn(a[flag + i].name, "\n")] = '\0'; // Remove newline character

        printf("\tEnter book number: ");
        scanf("%d", &a[flag + i].number);

        printf("\tEnter author name: ");
        while (getchar() != '\n');
        fgets(a[flag + i].author, sizeof(a[flag + i].author), stdin);
        a[flag + i].author[strcspn(a[flag + i].author, "\n")] = '\0'; // Remove newline character

        printf("\tEnter book cost: ");
        scanf("%f", &a[flag + i].cost);

        printf("\tEnter published year: ");
        scanf("%d", &a[flag + i].year);

        printf("\tEnter quantity: ");
        scanf("%d", &a[flag + i].quantity);
        printf("\t-------------------------------------------\n");
    }

    flag += x;
    printf("\t%d books added successfully.\n", x);
    save_books();
}

// Function to search books if they are available in store or not
void search_book() {
    char search_name[50];
    printf("\tEnter the book name to search: ");
    while (getchar() != '\n');
    fgets(search_name, sizeof(search_name), stdin);
    search_name[strcspn(search_name, "\n")] = '\0'; // Remove newline character

    printf("\tSearch Results:\n");
    int found = 0;
    for (int i = 0; i < flag; i++) {
        if (strstr(a[i].name, search_name)) {
            printf("%d. \n\tBook name: %s \tBook number: %d\n \tAuthor name: %s \tBook cost: %.2f\n \tQuantity: %d\n",
                   i + 1, a[i].name, a[i].number, a[i].author, a[i].cost, a[i].quantity);
            found++;
        }
    }
    if (found == 0) {
        printf("\tNo books found with the given name.\n");
    }
}

// Function to delete the required book in store which are unavailable
void delete_book() {
    int book_number;
    printf("\tEnter the book number to delete: ");
    scanf("%d", &book_number);

    int index = -1;
    for (int i = 0; i < flag; i++) {
        if (a[i].number == book_number) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("\tBook not found.\n");
        return;
    }

    for (int i = index; i < flag - 1; i++) {
        a[i] = a[i + 1];
    }
    flag--;
    printf("\tBook deleted successfully.\n");
    printf("\t-------------------------------------------\n");
    save_books();
}

// Function to display books which are in store
void display_book() {
    if (flag == 0) {
        printf("\tNo books available.\n");
        return;
    }
    printf("\tBooks List:\n");
    for (int i = 0; i < flag; i++) {
        printf("%d. \n\tBook name: %s \tBook number: %d\n \tAuthor name: %s \tBook cost: %.2f\n \tPublished year: %d\n\tQuantity: %d\n",
               i + 1, a[i].name, a[i].number, a[i].author, a[i].cost, a[i].year, a[i].quantity);
    }
}

void sale_books() {
    int n;
    printf("\tEnter the number of books to sale: ");
    scanf("%d", &n);
    printf("\t-------------------------------------------\n");

    if (n > flag) {
        printf("\tNot enough books in store.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("\tEnter details for sale of book %d\n", i + 1);
        char search_name[50];
        printf("\tEnter the book name to search: ");
        while (getchar() != '\n'); // Clear the input buffer
        fgets(search_name, sizeof(search_name), stdin);
        search_name[strcspn(search_name, "\n")] = '\0'; // Remove newline character

        printf("\tSearch Results:\n");
        int found = 0;
        for (int j = 0; j < flag; j++) {
            if (strstr(a[j].name, search_name)) {
                if (a[j].quantity > 0) {
                    printf("\tEnter customer name: ");
                    fgets(b[count].customer_name, sizeof(b[count].customer_name), stdin);
                    b[count].customer_name[strcspn(b[count].customer_name, "\n")] = '\0'; // Remove newline character

                    printf("\tEnter customer phone number: ");
                    fgets(b[count].customer_number, sizeof(b[count].customer_number), stdin);
                    b[count].customer_number[strcspn(b[count].customer_number, "\n")] = '\0'; // Remove newline character

                    strcpy(b[count].name, a[j].name);
                    b[count].number = a[j].number;
                    strcpy(b[count].author, a[j].author);
                    b[count].cost = a[j].cost;
                    b[count].year = a[j].year;

                    a[j].quantity--;
                    count++;
                    found++;
                    break; // Exit search loop once book is found and sold
                } else {
                    printf("\tBook '%s' is out of stock.\n", a[j].name);
                    found++;
                    break; // Exit search loop if book is found but out of stock
                }
            }
        }

        if (found == 0) {
            printf("\tNo books found with the given name.\n");
        }
    }

    save_books();
    save_sold_books();
}

void displaysold_book() {
    FILE *fp = fopen("sold_books.txt", "r");
    if (fp == NULL) {
        printf("\tNo sold books recorded.\n");
        return;
    }

    printf("\tSales List:\n");
    char line[256];
    int i = 0;
    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%[^,],%[^,],%[^,],%d,%[^,],%f,%d",
               b[i].customer_name, b[i].customer_number, b[i].name, &b[i].number, b[i].author, &b[i].cost, &b[i].year);
        printf("%d. \n\tCustomer name: %s \tCustomer phone number: %s\n \tBook name: %s \tBook number: %d\n \tAuthor name: %s \tBook cost: %.2f\n \tPublished year: %d\n",
               i + 1, b[i].customer_name, b[i].customer_number, b[i].name, b[i].number, b[i].author, b[i].cost, b[i].year);
        i++;
    }
    fclose(fp);
}

int main() {
    int choice;
    while (1) {
        printf("\n\tWelcome to Bookshop Management System:\n");
        printf("\t-------------------BMS---------------------\n");
        printf("\t1. Add Books\n");
        printf("\t2. Search Book\n");
        printf("\t3. Display books available in store\n");
        printf("\t4. Delete Book\n");
        printf("\t5. Sale Book\n");
        printf("\t6. Display sold Books\n");
        printf("\t7. Exit\n");
        printf("\tEnter your choice: ");
        scanf("%d", &choice);
        printf("\t-------------------------------------------\n");

        switch (choice) {
            case 1:
                add_books();
                break;

            case 2:
                search_book();
                break;

            case 3:
                display_book();
                break;

            case 4:
                delete_book();
                break;

            case 5:
                sale_books();
                break;

            case 6:
                displaysold_book();
                break;

            case 7:
                printf("Exiting...\n");
                printf("The program ended.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}
