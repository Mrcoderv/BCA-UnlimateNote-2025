#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct book
{
    char std_name[50];
    int  lib_id;
    char std_semester[20];
    char book_name[50];
    char author_name[50];
    char edition[20];
    char issued_date[11];
    char return_date[11];
};

struct book b[50];
int count = 0;

// Function to save book records to file
void save_books()
{
    FILE *fp;
    fp = fopen("LMS.txt", "w");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    fprintf(fp, "%d\n", count); // Save the count of books first

    for (int i = 0; i < count; i++)
    {
        fprintf(fp, "%s %d %s %s %s %s %s %s\n",
            b[i].std_name, b[i].lib_id, b[i].std_semester,
            b[i].book_name, b[i].author_name, b[i].edition,
            b[i].issued_date, b[i].return_date);
    }

    fclose(fp);
    printf("Book records saved successfully.\n");
}

// Function to load book records from file
void load_books()
{
    FILE *fp;
    fp = fopen("LMS.txt", "r");
    if (fp == NULL)
    {
        printf("No existing records found.\n");
        return;
    }

    fscanf(fp, "%d\n", &count); // Read the count of books first

    for (int i = 0; i < count; i++)
    {
        fscanf(fp, "%s %d %s %s %s %s %s %s\n",
            b[i].std_name, &b[i].lib_id, b[i].std_semester,
            b[i].book_name, b[i].author_name, b[i].edition,
            b[i].issued_date, b[i].return_date);
    }

    fclose(fp);
    printf("Book records loaded successfully.\n");
}

void add_book()
{
    if (count >= 50)
    {
        printf("Sorry, can't add more books.\n");
        return;
    }
    else
    {
        printf("\n\nAdd the details of book borrower.\n \n");
        printf("Enter the student name: ");
        scanf("%s", b[count].std_name);
        printf("Enter the library ID number: ");
        scanf("%d", &b[count].lib_id);
        printf("Enter the semester of student: ");
        scanf("%s", b[count].std_semester);
        printf("Enter the book name: ");
        scanf("%s", b[count].book_name);
        printf("Enter the author name: ");
        scanf("%s", b[count].author_name);
        printf("Enter the edition of book: ");
        scanf("%s", b[count].edition);
        printf("Enter the book issued date (DD/MM/YYYY): ");
        scanf("%s", b[count].issued_date);
        printf("Enter the book return date (DD/MM/YYYY): ");
        scanf("%s", b[count].return_date);
        
        count++;
        printf("\n\t\tCongrats\nThe borrower details added successfully.\n");
    }
}

void search_book()
{
    int id;
    printf("Enter the library ID to search: ");
    scanf("%d", &id);
    int found = 0;
    for (int i = 0; i < count; i++)
    {
        if (b[i].lib_id == id)
        {
            found = 1;
            printf("\n\nThe details of the borrower is found:\n");
            printf("Student name: %s\n", b[i].std_name);
            printf("library id number: %d\n", b[i].lib_id);
            printf("Student semester: %s\n", b[i].std_semester);
            printf("Book name: %s\n", b[i].book_name);
            printf("Author name: %s\n", b[i].author_name);
            printf("Book edition: %s\n", b[i].edition);
            printf("Book issued date: %s\n", b[i].issued_date);
            printf("Book return date: %s\n", b[i].return_date);
        }
    }
    if (!found)
    {
        printf("\nThe borrower details are not found.\n");
    }
}

void modify_book()
{
    int id;
    printf("\nEnter the library ID number of borrower to modify the details: ");
    scanf("%d", &id);

    int found = 0;
    for (int i = 0; i < count; i++)
    {
        if (b[i].lib_id == id)
        {
            found = 1;
            printf("OLD DETAILS:\n");
            printf("Student name: %s\n", b[i].std_name);
            printf("library ID number: %d\n", b[i].lib_id);
            printf("Student semester: %s\n", b[i].std_semester);
            printf("Book name: %s\n", b[i].book_name);
            printf("Author name: %s\n", b[i].author_name);
            printf("Book edition: %s\n", b[i].edition);
            printf("Book issued date: %s\n", b[i].issued_date);
            printf("Book return date: %s\n", b[i].return_date);
        
            printf("\nPlease enter the new details:\n");
            printf("Enter the student name: ");
            scanf("%s", b[i].std_name);
            printf("Enter the library ID number: ");
            scanf("%d", &b[i].lib_id);
            printf("Enter the semester of student: ");
            scanf("%s", b[i].std_semester);
            printf("Enter the book name: ");
            scanf("%s", b[i].book_name);
            printf("Enter the author name: ");
            scanf("%s", b[i].author_name);
            printf("Enter the edition of book: ");
            scanf("%s", b[i].edition);
            printf("Enter the book issued date (DD/MM/YYYY): ");
            scanf("%s", b[i].issued_date);
            printf("Enter the book return date (DD/MM/YYYY): ");
            scanf("%s", b[i].return_date);

            printf("\nThe details of the student are updated successfully.\n");
        }
    }
    if (!found)
    {
        printf("\nYou have entered the wrong library ID number. Please enter the valid library ID number.\n");
    }
}

void delete_book()
{
    int id, found = 0;
    printf("\nEnter the library ID number of the student to delete details: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++)
    {
        if (b[i].lib_id == id)
        {
            found = 1;
            for (int j = i; j < count - 1; j++)
            {
                b[j] = b[j + 1];
            }
            count--;
            printf("Student with library ID %d deleted successfully.\n", id);
            break; // Exit the loop after deleting the student
        }
    }

    if (!found)
    {
        printf("Student not found with library ID %d.\n", id);
    }
}

int main()
{
    load_books(); // Load existing book records from file at the start
    int option;
    printf("\n\nWelcome to Library Management System\n\t\t'LMS'\n");
    
    while (1)
    {
        printf("\nChoice 1: Add book\n");
        printf("Choice 2: Search book\n");
        printf("Choice 3: Modify book\n");
        printf("Choice 4: Delete book\n");
        printf("Choice 5: Save and Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &option);

        switch (option)
        {
            case 1:
                add_book();
                break;

            case 2:
                search_book();
                break;

            case 3:
                modify_book();
                break;

            case 4:
                delete_book();
                break;

            case 5:
                save_books(); // Save book records to file before exiting
                printf("\nThe program is exited successfully.\n\tTHANK YOU!!!\n");
                exit(0);

            default:
                printf("\n\n Please enter a valid choice (1 to 5).\n\n");
                break;
        }
    }
    return 0;
}
