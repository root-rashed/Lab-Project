#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// GLOBAL VARIABLE
#define MAX_NAME_LENGTH 50


// CREATE NODE
typedef struct Patient {
    char name[MAX_NAME_LENGTH];
    int age;
    char date[11];
    char condition[MAX_NAME_LENGTH];
    struct Patient *next;
} Patient;


// MAIN FUNCTION
int main() {
    int choice;
    char searchName[MAX_NAME_LENGTH];

    //OPTIONS    
    do {
        printf("\nPatient Management System\n");
        printf("1. Add Patient\n");
        printf("2. Display Patients\n");
        printf("3. Search Patient\n");
        printf("4. Sort Patients\n");
        printf("5. Add Bill\n");
        printf("6. Display Bills\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addPatient();
                break;
            case 2:
                displayPatients();
                break;
            case 3:
                printf("Enter name to search: ");
                scanf(" %[^\n]", searchName);
                Patient *searched = searchPatient(searchName);
                if (searched != NULL) {
                    printf("Patient found: Name: %s, Age: %d, Date: %s, Condition: %s\n",
                           searched->name, searched->age, searched->date, searched->condition);
                } else {
                    printf("Patient not found.\n");
                }
                break;
            case 4:
                sortPatients();
                printf("Patients sorted by name.\n");
                break;
            case 5:
                pushBill();
                break;
            case 6:
                displayBills();
                break;
            case 7:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}
