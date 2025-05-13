#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 100
#define MAX_PHONE 15

typedef struct Contact {
    char name[MAX_NAME];
    char phone[MAX_PHONE];
    struct Contact* next;
} Contact;

Contact* head = NULL;

// Function to create a new contact node
Contact* createContact(char name[], char phone[]) {
    Contact* newContact = (Contact*)malloc(sizeof(Contact));
    strcpy(newContact->name, name);
    strcpy(newContact->phone, phone);
    newContact->next = NULL;
    return newContact;
}

// Add contact to the list
void addContact() {
    char name[MAX_NAME], phone[MAX_PHONE];
    printf("Enter name: ");
    scanf(" %[^\n]", name);
    printf("Enter phone: ");
    scanf(" %[^\n]", phone);

    Contact* newContact = createContact(name, phone);
    newContact->next = head;
    head = newContact;
    printf("Contact added successfully!\n");
}

// Display all contacts
void displayContacts() {
    Contact* temp = head;
    if (!temp) {
        printf("Phonebook is empty!\n");
        return;
    }

    printf("\n--- Contact List ---\n");
    while (temp) {
        printf("Name: %s\nPhone: %s\n\n", temp->name, temp->phone);
        temp = temp->next;
    }
}

// Delete contact by name
void deleteContact() {
    char name[MAX_NAME];
    printf("Enter name to delete: ");
    scanf(" %[^\n]", name);

    Contact *temp = head, *prev = NULL;

    while (temp && strcmp(temp->name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) {
        printf("Contact not found.\n");
        return;
    }

    if (!prev)
        head = temp->next;
    else
        prev->next = temp->next;

    free(temp);
    printf("Contact deleted.\n");
}

int main() {
    int choice;
    do {
        printf("\n--- PHONEBOOK MENU ---\n");
        printf("1. Add Contact\n2. View Contacts\n3. Delete Contact\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addContact(); break;
            case 2: displayContacts(); break;
            case 3: deleteContact(); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}
