#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Patient structure
typedef struct Patient
{
    char name[50];
    int age;
    char date[11];
    char condition[100];
    struct Patient *next;
} Patient;

// Bill structure
typedef struct Bill
{
    int patientID;
    float amount;
    struct Bill *next;
} Bill;

// Function prototypes
void addPatient();
void deletePatient();
void displayPatients();
void searchPatient();
void sortPatients();
void manageBills();

// Global pointers for patient linked list and bill stack
Patient *front = NULL;
Patient *rear = NULL;

Bill *billStack = NULL;

// Main function
int main()
{
    int choice;
    do
    {
        printf("\nPatient Management System\n");
        printf("1. Add Patient\n");
        printf("2. Delete Patient\n");
        printf("3. Display Patients\n");
        printf("4. Search Patient\n");
        printf("5. Sort Patients\n");
        printf("6. Manage Bills\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            addPatient();
            break;
        case 2:
            deletePatient();
            break;
        case 3:
            displayPatients();
            break;
        case 4:
            searchPatient();
            break;
        case 5:
            // sortPatients();
            break;
        case 6:
            manageBills();
            break;
        case 7:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);
    return 0;
}

// Function to add a patient
void addPatient()
{
    Patient *newPatient = (Patient *)malloc(sizeof(Patient));
    printf("Enter patient's name: ");
    scanf(" %s", newPatient->name);
    printf("Enter patient's age: ");
    scanf("%d", &newPatient->age);
    printf("Enter admission date (YYYY-MM-DD): ");
    scanf("%s", newPatient->date);
    printf("Enter patient's condition: ");
    scanf(" %s", newPatient->condition);
    newPatient->next = NULL;
    if (rear == NULL)
    {
        front = rear = newPatient;
    }
    else
    {
        rear->next = newPatient;
        rear = newPatient;
    }
    printf("Patient added successfully.\n");
}

// Function to delete a patient
void deletePatient()
{
    if (front == NULL)
    {
        printf("No patients to delete.\n");
        return;
    }
    Patient *temp = front;
    front = front->next;
    if (front == NULL)
    {
        rear = NULL;
    }
    free(temp);
    printf("Patient deleted successfully.\n");
}

// Function to display patients
void displayPatients()
{
    if (front == NULL)
    {
        printf("No patients to display.\n");
        return;
    }
    printf("Displaying patient details in FIFO order:\n");
    printf("------------------------------------------\n");
    printf("Name\t\tAge\t\tCondition\n");
    printf("------------------------------------------\n");
    Patient *temp = front;
    while (temp != NULL)
    {
        printf("%-15s %-10d %-20s\n", temp->name, temp->age, temp->condition);
        temp = temp->next;
    }
    printf("------------------------------------------\n");
}

// Function to search for a patient
void searchPatient()
{
    if (front == NULL)
    {
        printf("No patients to search.\n");
        return;
    }
    char searchName[50];
    printf("Enter patient's name to search: ");
    scanf(" %s", searchName);
    Patient *temp = front;
    while (temp != NULL)
    {
        if (strcmp(temp->name, searchName) == 0)
        {
            printf("Patient found: Name: %s, Age: %d, Date: %s, Condition: %s\n", temp->name, temp->age, temp->date, temp->condition);
            return;
        }
        temp = temp->next;
    }
    printf("Patient not found.\n");
}

// // Function to sort patients by date and condition using bubble sort
// void sortPatients() {
//     if (front == NULL || front->next == NULL) {
//         printf("Not enough patients to sort.\n");
//         return;
//     }
//     int swapped;
//     Patient* ptr1;
//     Patient* lptr = NULL;
//     do {
//         swapped = 0;
//         ptr1 = front;
//         while (ptr1->next != lptr) {
//             if (strcmp(ptr1->date, ptr1->next->date) > 0 || (strcmp(ptr1->date, ptr1->next->date) == 0 && strcmp(ptr1->condition, ptr1->next->condition) > 0)) {
//                 Patient temp = *ptr1;
//                 *ptr1 = *(ptr1->next);
//                 *(ptr1->next) = temp;
//                 Patient* tmpNext = ptr1->next->next;
//                 ptr1->next->next = ptr1;
//                 ptr1->next = tmpNext;
//                 swapped = 1;
//             }
//             ptr1 = ptr1->next;
//         }
//         lptr = ptr1;
//     } while (swapped);
//     printf("Patients sorted successfully.\n");
// }

// Function to manage bills (add or display)
void manageBills()
{
    int choice;
    printf("\nManage Bills\n");
    printf("1. Add Bill\n");
    printf("2. Display Bills\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        Bill *newBill = (Bill *)malloc(sizeof(Bill));
        int diagnosisChoice;
        float diagnosisPrice = 0.0, totalAmount = 0.0;
        printf("Enter patient ID for the bill: ");
        scanf("%d", &newBill->patientID);
        do
        {
            printf("Select diagnosis type (Enter 0 to finish):\n");
            printf("1. General Checkup (500.00)\n");
            printf("2. X-Ray (1500.00)\n");
            printf("3. MRI (2000.00)\n");
            printf("4. Blood Test (200.00)\n");
            printf("Enter your choice: ");
            scanf("%d", &diagnosisChoice);
            switch (diagnosisChoice)
            {
            case 1:
                diagnosisPrice = 50.00;
                break;
            case 2:
                diagnosisPrice = 150.00;
                break;
            case 3:
                diagnosisPrice = 1000.00;
                break;
            case 4:
                diagnosisPrice = 200.00;
                break;
            case 0:
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                continue;
            }
            totalAmount += diagnosisPrice;

        } while (diagnosisChoice != 0);

        newBill->amount = totalAmount;
        newBill->next = billStack;
        billStack = newBill;
        printf("Total bill amount: $%.2f\n", newBill->amount);
    }

    else if (choice == 2)
    {
        if (billStack == NULL)
        {
            printf("No bills to display.\n");
            return;
        }
        Bill *temp = billStack;
        while (temp != NULL)
        {
            printf("Patient ID: %d, Amount: $%.2f\n", temp->patientID, temp->amount);
            temp = temp->next;
        }
    }

    else
    {
        printf("Invalid choice.\n");
    }
}
