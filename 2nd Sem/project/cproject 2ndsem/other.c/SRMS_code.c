#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//structure to store the student's information...........

struct stdinfo {
	int std_id;
    char first_name[20];
	char last_name[20];
    char std_address[50];
    char std_parentname[50];
    char std_semester[20];
    char std_contact[20];
} s[100];


int count = 0;	//to count the number of students.......


//function prototype...............
void add_std();
void search_std();
void modify_std();
void delete_std();
void load_data();
void save_data();


// Function to load data from file
void load_data() {
    FILE *file = fopen("SRMS.txt", "r");
    if (file) {
                while (fscanf(file, "%d, %19[^,], %19[^,], %49[^,], %49[^,], %19[^,], %19[^\n]\n", 
                      &s[count].std_id, s[count].first_name, s[count].last_name,
                      s[count].std_address, s[count].std_parentname,
                      s[count].std_semester, s[count].std_contact) == 7) {

            count++;
        }
        fclose(file);
    }
}

// Function to save data to file
void save_data() {
    FILE *file = fopen("SRMS.txt", "w");
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d,%s,%s,%s,%s,%s,%s\n", s[i].std_id, s[i].first_name, s[i].last_name,
                s[i].std_address, s[i].std_parentname, s[i].std_semester, s[i].std_contact);
    }
    fclose(file);
}


//user defined function without return type and without argument........
// funtion definition to add student details.......
void add_std()
{
	if(count >= 100)
	{
		printf("Sorry, Can't add more students.");
		return;
	}
	else
	{
		printf("\n\nAdd the Student's Details\n \n");
		printf("Enter the first name of the student: ");
		scanf("%19s", s[count].first_name);
		printf("Enter the last name of the student: ");
		scanf("%19s", s[count].last_name);
		printf("Enter the student id: ");
		scanf("%d", &s[count].std_id);
		while(getchar() != '\n');		//to remove newline character if present.........
		printf("Enter the address of the student: ");
		fgets(s[count].std_address, sizeof(s[count].std_address), stdin);
		printf("Enter the parent's name: ");
		fgets(s[count].std_parentname, sizeof(s[count].std_parentname), stdin);
		printf("Enter the semester in which the student is enrolled: ");
		scanf("%19s", s[count].std_semester);
		printf("Enter the contact number of the student: ");
		scanf("%19s", s[count].std_contact);

		count++;
		save_data();
		printf("\n \t\tCongrats\nThe student details added successfully.\n");
	}
	
}

// funtion definition to search students details....
void search_std()
{
	int roll;
	printf("Enter the student ID to search: ");
	scanf("%d", &roll);

	int found = 0;

	for(int i = 0; i < count; i++)
	{
		if(s[i].std_id == roll)
		{
			found = 1;
			printf("\n\nThe details of the student is found: \n");
			printf("First Name: %s\n", s[i].first_name);
			printf("Last Name: %s\n", s[i].last_name);
			printf("Student ID: %d\n", s[i].std_id);
			printf("Address: %s\n", s[i].std_address);
			printf("Parent's Name: %s\n", s[i].std_parentname);
			printf("Semester: %s\n", s[i].std_semester);
			printf("Contact No.: %s\n", s[i].std_contact);
		}
	}
	
	if(found != 1)
	{
		printf("\nThe student with student ID %d is not found....\n", roll);
	}
}

// funtion definition to modify students details....
void modify_std()
{
	int roll;
	printf("\nEnter the student ID of the student to modify the details: ");
	scanf("%d", &roll);

    int found = 0;
    for (int i = 0; i < count; i++)
	{
		if(s[i].std_id == roll)
		{
			found = 1;
			printf("OLD DETAILS:\n");
			printf("First Name: %s\n", s[i].first_name);
			printf("Last Name: %s\n", s[i].last_name);
			printf("Student ID: %d\n", s[i].std_id);
			printf("Address: %s\n", s[i].std_address);
			printf("Parent's Name: %s\n", s[i].std_parentname);
			printf("Semester: %s\n", s[i].std_semester);
			printf("Contact No.: %s\n", s[i].std_contact);

			printf("\nPlease enter the new details\n \n");
			printf("Enter the first name of the student: ");
			scanf("%19s", s[i].first_name);
			printf("Enter the last name of the student: ");
			scanf("%19s", s[i].last_name);
			printf("Enter the new student id: ");
			scanf("%d", &s[i].std_id);
			printf("Enter the new address of the student: ");
			while(getchar() != '\n');
			fgets(s[i].std_address, sizeof(s[i].std_address), stdin);
			printf("Enter the parent's name: ");
			fgets(s[i].std_parentname, sizeof(s[i].std_parentname), stdin);
			printf("Enter the new semester in which the student is enrolled: ");
			scanf("%19s", s[i].std_semester);
			printf("Enter the new contact number of the student: ");
			scanf("%19s", s[i].std_contact);
			count++;
			save_data();
			printf("\nTHE DETAILS OF THE STUDENT ARE UPDATED SUCCESSFULLY\n");
		}
	}
	if(!found)
	{
		printf("\nThe student ID isn't found to modify.\nPlease enter the valid student ID.\n");
	}
}

// funtion definition to delete students details....
void delete_std()
{
	int roll, found = 0;
	printf("\nEnter the student ID of the student to delete details: ");
	scanf("%d", &roll);

	for(int i = 0; i < count; i++)
	{
		if(s[i].std_id == roll)
		{
			found = 1;
			for (int j = i; j < count - 1; j++)
			{
                s[j] = s[j + 1];
            }
            count--; // Decrease the count of students
            save_data();
			printf("\nStudent with ID %d deleted successfully.\n", roll);
			break;
		}
	}
		if(!found)
		{
			printf("\nThe student details with ID %d is not found to delete.", roll);
		}
}


int main()
{
	int option;
	load_data();
		printf("\n \n Welcome to Student Record Management System\n \t \t'SRMS'");
	while(1)
	{
		printf("\n\nMAIN MENU\n====================\n");
		printf("\nChoice 1: Add Student\n");
		printf("Choice 2: Search Student\n");
		printf("Choice 3: Modify Student\n");
		printf("Choice 4: Delete Student\n");
		printf("Choice 5: Exit\n====================\n");
		printf("\nEnter your Choice: ");
		scanf(" %d", &option);


		switch(option)
		{
			case 1:
			add_std();    //function call
			break;

			case 2:
			search_std();    //function call
			break;

			case 3:
			modify_std();    //function call
			break;

			case 4:
			delete_std();    //function call
			break;

			case 5:
			printf("\n \nThe program is exited successfully.\n\tTHANK YOU!!!\n");
			exit(0);
			break;

			default:
			printf("\n \n Please enter the valid choice (1 to 5)\n \n");
			break;
		}
	}
	return 0;
}
