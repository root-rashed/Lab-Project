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
void manageBills();
void notifyDues();
void paymentReceipt();

// Global pointers for patient queue and bill stack
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
        printf("5. Manage Bills\n");
        printf("6. Exit\n");
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
            manageBills();
            break;
        case 6:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
    return 0;
}



// Function to add a patient
void addPatient()
{
    Patient *newPatient = (Patient *)malloc(sizeof(Patient));
    printf("Enter patient's name: ");
    scanf(" %49s", newPatient->name);
    printf("Enter patient's age: ");
    scanf("%d", &newPatient->age);
    printf("Enter admission date (YYYY-MM-DD): ");
    scanf(" %10s", newPatient->date);
    printf("Enter patient's condition: ");
    scanf(" %99s", newPatient->condition);
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
    printf("-------------------------------------------------------------\n");
    printf("S.No\tName\t\tAge\tDate of Admit\tCondition\n");
    printf("-------------------------------------------------------------\n");

    Patient *temp = front;
    int serialNumber = 1;
    while (temp != NULL)
    {
        printf("%-5d %-15s %-10d %-15s %-20s\n", serialNumber++, temp->name, temp->age, temp->date, temp->condition);
        temp = temp->next;
    }
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
    scanf(" %49s", searchName);
    Patient *temp = front;
    while (temp != NULL)
    {
        if (strcmp(temp->name, searchName) == 0)
        {
            printf("Patient found: Name: %s, Age: %d, Date: %s, Condition: %s\n",
                   temp->name, temp->age, temp->date, temp->condition);
            return;
        }
        temp = temp->next;
    }
    printf("Patient not found.\n");
}




// Function to manage bills (add, notify dues, generate receipt)
void manageBills()
{
    int choice;
    printf("\nManage Bills\n");
    printf("1. Add Bill\n");
    printf("2. Notify Dues\n");
    printf("3. Generate Payment Receipt\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    static int paidStatus[1000] = {0};
    static float discounts[1000] = {0.0};

    if (choice == 1)
    {
        Bill *newBill = (Bill *)malloc(sizeof(Bill));
        int diagnosisChoice;
        float diagnosisPrice = 0.0, totalAmount = 0.0;
        printf("Enter patient ID for the bill: ");
        scanf("%d", &newBill->patientID);

        Patient *temp = front;
        while (temp != NULL)
        {
            if (temp->age > 50)
            {
                discounts[newBill->patientID] = 0.25;
                break;
            }
            temp = temp->next;
        }

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
                diagnosisPrice = 500.00;
                break;
            case 2:
                diagnosisPrice = 1500.00;
                break;
            case 3:
                diagnosisPrice = 2000.00;
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

        if (discounts[newBill->patientID] > 0)
        {
            totalAmount -= totalAmount * discounts[newBill->patientID];
            printf("%.1f%% discount applied.\n", discounts[newBill->patientID] * 100);
        }

        newBill->amount = totalAmount;
        newBill->next = billStack;
        billStack = newBill;
        printf("Total bill amount: $%.2f\n", newBill->amount);
    }
    else if (choice == 2)
    {
        if (billStack == NULL)
        {
            printf("No dues to notify.\n");
            return;
        }
        Bill *temp = billStack;
        while (temp != NULL)
        {
            if (paidStatus[temp->patientID] == 0)
            {
                printf("Patient ID: %d, Due Amount: $%.2f\n", temp->patientID, temp->amount);
            }
            temp = temp->next;
        }
    }
    else if (choice == 3)
    {
        paymentReceipt();
    }
    else
    {
        printf("Invalid choice.\n");
    }
}




// Function to generate payment receipt
void paymentReceipt()
{
    int patientID;
    printf("Enter patient ID to generate receipt: ");
    scanf("%d", &patientID);
    Bill *temp = billStack;
    while (temp != NULL)
    {
        if (temp->patientID == patientID)
        {
            printf("Payment Receipt\n");
            printf("----------------\n");
            printf("Patient ID: %d\n", temp->patientID);
            printf("Total Amount: $%.2f\n", temp->amount);
            printf("Payment Status: Paid\n");
            return;
        }
        temp = temp->next;
    }
    printf("No bill found for the given patient ID.\n");
}


        
