#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// GLOBAL VARIABLE
#define MAX_NAME_LENGTH 50


// CREATE NODE FOR LINKED LIST
typedef struct{
    char name[MAX_NAME_LENGTH];
    int age;
    char date[11];
    char condition[MAX_NAME_LENGTH];
    struct Patient *next;
} Patient;

Patient patients[50];
int totalPatient=0;

void menu();


void sortByAge()
{
   for(int i=0;i<totalPatient;i++)
   {
       for(int j=0;j<totalPatient-i-1;j++)
       {
           if(patients[j].age>patients[j+1].age)
           {
               Patient temp;
               temp = patients[j];
               patients[j]=patients[j+1];
               patients[j+1]=temp;
           }
       }

   }
    printf("Patients list sorted by age : \n");
    for(int i=0;i<totalPatient;i++)
    {
        printf("Patient : %s Age : %d\n",patients[i].name,patients[i].age);
    }
}
void sortByName()
{
    for(int i=0;i<totalPatient;i++)
    {
        for(int j=0;j<totalPatient-i-1;j++)
        {
            int k=0;
            if(patients[j].name[k]>patients[j+1].name[k])
            {
                Patient temp;
                temp= patients[j];
                patients[j]=patients[j+1];
                patients[j+1]=temp;
            }
            else if(patients[j].name[k]==patients[j+1].name[k])
            {
                if(patients[j].name[k+1]>patients[j+1].name[k+1])
              {
                Patient temp;
                temp= patients[j];
                patients[j]=patients[j+1];
                patients[j+1]=temp;
              }
            }
        }
    }
    for(int i=0;i<totalPatient;i++)
    {
         printf("Patient : %s   Age : %d\n",patients[i].name,patients[i].age);
    }
}
void addPatient()
{
    if(totalPatient<=50)
    {
        Patient newPatient;
        printf("Enter patient name : ");
        scanf("%s",newPatient.name);
        printf("Enter patient age : ");
        scanf("%d",&newPatient.age);
        patients[totalPatient++]=newPatient;
        //...................Baki data input nite hobe
        printf("Go back to menu (y/n) : ");
        char x;
        getchar();
        scanf("%c",&x);
        if(x=='y')
        {
            menu();
        }
        else
        {
            return;
        }

    }
}

void  sortPatients()
{
    printf("1. Sort patients by age.\n");
    printf("2. Sort patients by name.\n");
    printf("\n");
    printf("Choose Options : ");
    int n;
    scanf("%d",&n);
    if(n==1)
    {
        sortByAge();
    }
    else if(n==2)
    {
        sortByName();
    }
}
void displayPatients()
{
    for(int i=0;i<totalPatient;i++)
    {
        printf("Patient : %s Age : %d\n",patients[i].name,patients[i].age);
    }
}
void menu()
{
     int choice;
    char searchName[MAX_NAME_LENGTH];

    //OPTIONS
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
                scanf(" %[^\n]", &searchName);
                if (searchName != NULL) {
                    printf("Patient found: Name: %s, Age: %d, Date: %s, Condition: %s\n");
                } else {
                    printf("Patient not found.\n");
                }
                break;
            case 4:
                sortPatients();
                break;
            case 5:
               // pushBill();
                break;
            case 6:
               // displayBills();
                break;
            case 7:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

}
// MAIN FUNCTION
int main() {

    menu();

    return 0;
}
