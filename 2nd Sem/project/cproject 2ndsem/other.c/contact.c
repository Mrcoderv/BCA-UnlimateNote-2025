 #include <stdio.h> 
 #include <stdlib.h> 
 #include <string.h> 
 #define MAX_CONTACTS 100 
 #define MAX_NAME_LENGTH 50 
 #define MAX_PHONE_LENGTH 15 
 #define MAX_EMAIL_LENGTH 30 
 #define MAX_ADDRESS_LENGTH 40 
 #define FILE_NAME "contact.txt" 
 typedef struct 
 { 
 char name[MAX_NAME_LENGTH]; 
 char phone[MAX_PHONE_LENGTH]; 
 char email[MAX_EMAIL_LENGTH]; 
 char address[MAX_ADDRESS_LENGTH]; 
 } Contact; 
 Contact contacts[MAX_CONTACTS]; 
 int numContacts = 0; 
 void addContact(void) 
 { 
 printf("Enter name: "); 
 scanf(" %[^\n]s", contacts[numContacts].name); 
 printf("Enter phone: "); 
 scanf(" %[^\n]s", contacts[numContacts].phone); 
 printf("Enter email: "); 
 scanf(" %[^\n]s", contacts[numContacts].email); 
 printf("Enter address: "); 
 scanf(" %[^\n]s", contacts[numContacts].address); 
 num contacts++; 
 FILE *file = fopen(FILE_NAME, "wb"); 
 if (file == NULL) 
 { 
 printf("Failed to open file\n"); 
 return; 
 } 
 fwrite(contacts, sizeof(Contact), numContacts, file); 
 fclose(file); 
 printf("Contact added successfully.\n"); 
 } 
 void editContact(void) 
 { 
 if (numContacts == 0) 
 { 
 23 
printf("No contacts found.\n"); 
return; 
} 
printf("Enter name of contact to edit: "); 
char name[MAX_NAME_LENGTH]; 
scanf(" %[^\n]s", name); 
int contactFound = 0; 
for (int i = 0; i < numContacts; i++) 
{ 
if (strcmp(contacts[i].name, name) == 0) 
{ 
printf("Enter new name (or press enter to skip): "); 
char newName[MAX_NAME_LENGTH]; 
scanf(" %[^\n]s", newName); 
if (strlen(newName) > 0) 
{ 
strcpy(contacts[i].name, newName); 
} 
printf("Enter new phone (or press enter to skip): "); 
char newPhone[MAX_PHONE_LENGTH]; 
scanf(" %[^\n]s", newPhone); 
if (strlen(newPhone) > 0) 
{ 
strcpy(contacts[i].phone, newPhone); 
} 
printf("Enter new email (or press enter to skip): "); 
char newEmail[MAX_EMAIL_LENGTH]; 
scanf(" %[^\n]s", newEmail); 
if (strlen(newEmail) > 0) 
{ 
strcpy(contacts[i].email, newEmail); 
} 
printf("Enter new address (or press enter to skip): "); 
char newAddress[MAX_ADDRESS_LENGTH]; 
scanf(" %[^\n]s", newAddress); 
if (strlen(newAddress) > 0) 
{ 
strcpy(contacts[i].address, newAddress); 
} 
FILE *file = fopen(FILE_NAME, "wb"); 
if (file == NULL) 
{ 
printf("Failed to open file\n"); 
return; 
} 
fwrite(contacts, sizeof(Contact), numContacts, file); 
fclose(file); 
24 
 printf("Contact edited successfully.\n"); 
 contactFound = 1; 
 break; 
 } 
 } 
 if (!contactFound) 
 { 
 printf("Contact not found.\n"); 
 } 
 } 
 void deleteContact(void) 
 { 
 if (numContacts == 0) 
 { 
 printf("No contacts found.\n"); 
 return; 
 } 
 printf("Enter name of contact to delete: "); 
 char name[MAX_NAME_LENGTH]; 
 scanf(" %[^\n]s", name); 
 int contactFound = 0; 
 for (int i = 0; i < numContacts; i++) 
 { 
 if (strcmp(contacts[i].name, name) == 0) 
 { 
 contacts[i] = contacts[numContacts - 1]; 
 numContacts--; 
 FILE *file = fopen(FILE_NAME, "wb"); 
 if (file == NULL) 
 { 
 printf("Failed to open file.\n"); 
 return; 
 } 
 fwrite(contacts, sizeof(Contact), numContacts, file); 
 fclose(file); 
 printf("Contact deleted successfully.\n"); 
 contactFound = 1; 
 break; 
 } 
 } 
 if (!contactFound) 
 { 
 printf("Contact not found.\n");  } 
 } 
 void searchContact(void) 
 { 
 if (numContacts == 0) 
 25 
{ 
printf("No contacts found.\n"); 
return; 
} 
printf("Enter name of contact to search: "); 
char name[MAX_NAME_LENGTH]; 
scanf("%[^\n]s", name); 
int contactFound = 0; 
for (int i = 0; i < numContacts; i++) 
{ 
if (strcmp(contacts[i].name, name) == 0) 
{ 
printf("-------------------------------------------------------------------------------------------------------- ------------\n"); 
printf("| %-20s | %-15s | %-30s | %-40s |\n", "Name", "Phone", "Email", "Address"); 
printf("-------------------------------------------------------------------------------------------------------- ------------\n"); 
printf("| %-20s | %-15s | %-30s | %-40s |\n", contacts[i].name, contacts[i].phone, 
contacts[i].email, contacts[i].address); 
printf("-------------------------------------------------------------------------------------------------------- ------------\n"); 
contactFound = 1; 
break; 
} 
} 
if (!contactFound) 
{ 
printf("Contact not found.\n"); 
} 
} 
void displayContacts(void) 
{ 
if (numContacts == 0) 
{ 
printf("No contacts found.\n"); 
return; 
} 
printf("-------------------------------------------------------------------------------------------------------- ------------\n"); 
printf("| %-20s | %-15s | %-30s | %-40s |\n", "Name", "Phone", "Email", "Address"); 
printf("-------------------------------------------------------------------------------------------------------- ------------\n"); 
for (int i = 0; i < numContacts; i++) 
26 
 { 
 printf("| %-20s | %-15s | %-30s | %-40s |\n", contacts[i].name, contacts[i].phone, 
 contacts[i].email, contacts[i].address); 
 } 
 printf("-------------------------------------------------------------------------------------------------------- 
 ------------\n"); 
 } 
 void saveContactsToFile(void) 
 { 
 FILE *file = fopen(FILE_NAME, "wb"); 
 if (file == NULL) 
 { 
 printf("Failed to open file\n"); 
 return; 
 } 
 fwrite(contacts, sizeof(Contact), numContacts, file); 
 fclose(file); 
 } 
 void loadContactsFromFile(void) 
 { 
 FILE *file = fopen(FILE_NAME, "rb"); 
 if (file == NULL) 
 { 
 file = fopen(FILE_NAME, "wb"); 
 if (file == NULL) 
 { 
 printf("Failed to create file.\n"); 
 return; 
 } 
 fclose(file); } 
 else 
 { 
 numContacts = fread(contacts, sizeof(Contact), MAX_CONTACTS, file); 
 fclose(file); 
 } 
 } 
 void exitProgram(void) 
 { 
 saveContactsToFile(); 
 printf("Thank you for using the Contact Management System  Goodbye!\n"); 
 exit(0);} 
 void deleteAllContacts(void) 
 { 
 if (numContacts == 0) 
 { 
 printf("No contacts found.\n"); 
 27 
 return; 
 } 
 printf("Deleting all contacts...\n"); 
 numContacts = 0; 
 printf("All contacts have been deleted.\n"); 
 } 
 void searchContacts(void) 
 { 
 if (numContacts == 0) 
 { 
 printf("No contacts found.\n"); 
 return; 
 } 
 char searchTerm[MAX_NAME_LENGTH]; 
 printf("Enter search term (Name or Phone or Email or Address): "); 
 scanf(" %[^\n]s", searchTerm); 
 int contactFound = 0; 
 printf("-------------------------------------------------------------------------------------------------------- 
 ------------\n"); 
 printf("| %-20s | %-15s | %-30s | %-40s |\n", "Name", "Phone", "Email", "Address"); 
 printf("-------------------------------------------------------------------------------------------------------- 
 ------------\n"); 
 for (int i = 0; i < numContacts; i++) 
 { 
 if (strstr(contacts[i].name, searchTerm) != NULL || 
 strstr(contacts[i].phone, searchTerm) != NULL || 
 strstr(contacts[i].email, searchTerm) != NULL || 
 strstr(contacts[i].address, searchTerm) != NULL) 
 { 
 printf("| %-20s | %-15s | %-30s | %-40s |\n", contacts[i].name, contacts[i].phone, 
 contacts[i].email, contacts[i].address); 
 contactFound = 1; 
 } 
 } 
 printf("-------------------------------------------------------------------------------------------------------- 
 ------------\n"); 
 if (!contactFound)
  {
 printf("No contacts found with the search term '%s'.\n", searchTerm); 
 } 
 } 
 int main(void) 
 { 
 loadContactsFromFile(); 
 int choice; 
 28 
 while (1) 
 { 
 printf("\n\t**** Welcome to Contact Management System ****"); 
 printf("\n\n\n\t\t\tMAIN MENU\n\t\t\t=====================\n\t\t"); 
 printf("\n\t\t\tContact Management System\n"); 
 printf("\t\t\t[1] Add New Contact\n"); 
 printf("\t\t\t[2] View All Contacts\n"); 
 printf("\t\t\t[3] Search Contacts\n"); 
 printf("\t\t\t[4] Edit Contact\n"); 
 printf("\t\t\t[5] Delete Contact\n"); 
 printf("\t\t\t[6] Delete All Contacts\n"); 
 printf("\t\t\t[7] Exit\n"); 
 printf("\t\t\t====================\n\t\t"); 
 printf("\tEnter your choice: "); 
 scanf("%d", &choice); 
 switch (choice) 
 { 
 case 1: 
 addContact(); 
 break; 
 case 2: 
 displayContacts(); 
 break; 
 case 3: 
 searchContacts(); 
 break; 
 case 4: 
 editContact(); 
 break; 
 case 5: 
 deleteContact(); 
 break; 
 case 6: 
 deleteAllContacts(); 
 break; 
 case 7: 
 exitProgram(); 
 break; 
 default: 
 printf("Invalid choice Please try again.\n"); 
 break; 
 } 
 } 
 return 0; 
 }