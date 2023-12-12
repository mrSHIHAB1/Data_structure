 #include <stdio.h>
#include <stdlib.h>
#include <string.h>

////////////////////////////////////////////////////////////////////////////saim
struct Patient {
    int id;
    char name[100];
    int age;
    char address[100];
    char date[100];
    struct Patient* next;
};

struct Patient* patientList = NULL;

void addPatient() {
    system("cls");
    struct Patient* newPatient = (struct Patient*)malloc(sizeof(struct Patient));

    printf("____________________________________________\n");
    printf("|                                           |\n");
    printf("|  Enter the Patient Information for Storage |\n");
    printf("|___________________________________________|\n\n");
    printf("Enter patient ID: ");
    scanf("%d", &newPatient->id);
    printf("Enter patient Name: ");
    scanf(" %[^\n]s", newPatient->name);
    printf("Enter patient Age: ");
    scanf("%d", &newPatient->age);
    printf("Enter patient Address: ");
    scanf(" %[^\n]s", newPatient->address);
    printf("Enter date of visit: ");
    scanf(" %[^\n]s", newPatient->date);

    newPatient->next = patientList;
    patientList = newPatient;

    printf("Patient information added successfully.\n");
    savePatientToFile();
    printf("______________________________________________________________________________________________________________\n");
}

void displayPatients() {
    system("cls");
    printf("              _________________________________\n");
    printf("             |                                 |\n");
    printf("             |       ALL PATIENTS INFORMATION  |\n");
    printf("             |_________________________________|\n\n");

    struct Patient* current = patientList;
    printf("Patient ID  Name                Age  Address                Date of Visit\n");
    printf("__________  ____________________ ___  _____________________  ______________\n");

    while (current != NULL) {
        printf("%-10d  %-20s  %-3d  %-20s  %s\n", current->id, current->name, current->age, current->address, current->date);
        current = current->next;
    }

    printf("____________________________________________________________________________________________________________________\n");
}

/////////////////////////////////////////////////////Emon
void savePatientToFile() {
    FILE* file = fopen("patients.txt", "w");

    struct Patient* current = patientList;

    while (current != NULL) {
        fprintf(file, "Patient ID: %d\n", current->id);
        fprintf(file, "Name: %s\n", current->name);
        fprintf(file, "Age: %d\n", current->age);
        fprintf(file, "Address: %s\n", current->address);
        fprintf(file, "Date of Visit: %s\n\n", current->date);
        current = current->next;
    }

    fclose(file);
    printf("Patient information saved to 'patients.txt'.\n");
}
void loadPatientFromFile() {
    FILE* file = fopen("patients.txt", "r");
    int id;
    char name[100], address[100], date[100];
    int age;

    while (fscanf(file, "Patient ID: %d\nName: %[^\n]\nAge: %d\nAddress: %[^\n]\nDate of Visit: %[^\n]\n\n", &id, name, &age, address, date) == 5) {
        struct Patient* newPatient = (struct Patient*)malloc(sizeof(struct Patient));
        if (newPatient == NULL) {
            printf("Memory allocation failed.\n");
            return;
        }

        newPatient->id = id;
        strcpy(newPatient->name, name);
        newPatient->age = age;
        strcpy(newPatient->address, address);
        strcpy(newPatient->date, date);

        newPatient->next = patientList;
        patientList = newPatient;
    }

    fclose(file);
}



//////////////////////////////////////////////////Shohag

void findPatientByID() {
    system("cls");
    int searchID;
    printf("              ___________________________________________________\n");
    printf("             |                                                    |\n");
    printf("             |   Enter the Patient ID to search in the records    |\n");
    printf("             |____________________________________________________|\n\n\n");

    printf("Enter the Patient ID: ");
    scanf("%d", &searchID);

    printf("\nPatients Matching ID == %d \n\n\n", searchID);

    struct Patient* current = patientList;
    int found = 0;

    while (current != NULL) {
        if (current->id == searchID) {
            printf("Patient ID: %d\nName: %s\nAge: %d\nAddress: %s\nDate of Visit: %s\n\n", current->id, current->name, current->age, current->address, current->date);
            found = 1;
        }
        current = current->next;
    }

    if (!found) {
        printf("Patient with ID '%d' not found in the records.\n", searchID);
    }
    printf("____________________________________________________________________________________________________________________\n");
}

void deletePatient() {
     system("cls");
    int value;
    printf("Enter patient ID\n");
    scanf("%d",&value);
    struct Patient* current = patientList;
    struct Patient* previous = NULL;

    if (current == NULL) {
        printf("List is empty. No patient to delete.\n");
        return;
    }

    if (patientList->id == value) {
        patientList = current->next;
        free(current);
        printf("Patient with ID %d deleted successfully.\n", value);


    }

    while (current != NULL) {
        if (current->id == value) {
            previous->next = current->next;
            free(current);
            printf("Patient with ID %d deleted successfully.\n", value);

        } else {
            previous = current;
            current = current->next;
        }
    }


    savePatientToFile();
}

///////////////////////////////////////////////////////R

struct Appointment {
    char doctorName[100];
    char patientName[100];
    char mobileNumber[20];
    struct Appointment* next;
};

struct Appointment* front = NULL;
struct Appointment* rear = NULL;


void addAppointment() {
    system("cls");
    struct Appointment* newAppointment = (struct Appointment*)malloc(sizeof(struct Appointment));
    if (newAppointment == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("_____________________________________________________\n");
    printf("|                                                    |\n");
    printf("|  Enter the Appointment Information for Storage     |\n");
    printf("|____________________________________________________|\n\n");
    printf("Enter Doctor's Name: ");
    scanf(" %[^\n]s", newAppointment->doctorName);
    printf("Enter Patient's Name: ");
    scanf(" %[^\n]s", newAppointment->patientName);
    printf("Enter Patient's Mobile Number: ");
    scanf("%s", newAppointment->mobileNumber);
    newAppointment->next = NULL;

    if (front == NULL&&rear==NULL) {
        front = newAppointment;
        rear = newAppointment;
    } else {
        rear->next = newAppointment;
        rear = newAppointment;
    }


    printf("Appointment information added successfully.\n");
    saveAppointmentsToFile();
}


void saveAppointmentsToFile() {
    FILE* file = fopen("appointments.txt", "w");
    if (file == NULL) {
        printf("Failed to open the file for writing.\n");
        return;
    }

    struct Appointment* current = front;

    while (current != NULL) {
        fprintf(file, "Doctor Name: %s\n", current->doctorName);
        fprintf(file, "Patient Name: %s\n", current->patientName);
        fprintf(file, "Mobile Number: %s\n\n", current->mobileNumber);
        current = current->next;
    }

    fclose(file);
    printf("Appointments saved to 'appointments.txt'.\n");
}


void findAppointmentsByDoctorName() {
    system("cls");
    printf("_____________________________________________________\n");
    printf("|                                                    |\n");
    printf("|    Searching Appointments by Doctor's Name         |\n");
    printf("|____________________________________________________|\n\n");

    char searchDoctorName[100];
    printf("Enter Doctor's Name to search for appointments: ");
    scanf(" %[^\n]s", searchDoctorName);
    FILE* file = fopen("appointments.txt", "r");
    if (file == NULL) {
        printf("Appointments file not found.\n");
        return;
    }

    char doctorName[100], patientName[100], mobileNumber[20];
    int found = 0;

    printf("\nAppointments with Doctor Name: %s\n\n", searchDoctorName);

    while (fscanf(file, "Doctor Name: %[^\n]\nPatient Name: %[^\n]\nMobile Number: %[^\n]\n\n", doctorName, patientName, mobileNumber) == 3) {
        if (strcmp(doctorName, searchDoctorName) == 0) {
            printf("Patient Name: %s\n", patientName);
            printf("Mobile Number: %s\n\n", mobileNumber);
            found = 1;
        }
    }

    fclose(file);

    if (!found) {
        printf("No appointments found with Doctor Name: %s\n", searchDoctorName);
    }

    printf("____________________________________________________________________________________________________________________\n");
}
//////////////////////////////////////////////////////////////////////////////////Rahat
void displayAvailableDoctors() {
    system("cls");
    FILE *file = fopen("doctor_schedules.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("              ____________________________________________\n");
    printf("             |                                          |\n");
    printf("             |       Available Doctors and Schedule     |\n");
    printf("             |__________________________________________|\n\n");

    printf("Doctor Name            Consultation Time       Days\n");
    printf("_____________________  ____________________  ______________\n");

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char name[100], schedule[100], days[100];
        sscanf(line, "%[^,],%[^,],%[^\n]", name, schedule, days);
        printf("%-21s  %-20s  %s\n", name, schedule, days);
    }

    printf("____________________________________________________________________________________________________________________\n");

    fclose(file);
}

int main() {
    int choice;
    loadPatientFromFile();
    while (1) {
        printf("          ____________________________\n");
        printf("          |                           |\n");
        printf("          |     Hospital Managment    |\n");
        printf("          |___________________________|\n\n");

        printf("          1--> Doctor list\n");
        printf("          2--> Make appointmet\n");
        printf("          3--> See appointmet List\n");
        printf("          4--> Insert a Patient Information\n");
        printf("          5--> Display patients Information\n");
        printf("          6--> Find a patient Information\n");
        printf("          7--> Delete a patient Information\n");
        printf("          0--> Exit\n\n");
        printf("             =>Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayAvailableDoctors();
                break;
            case 2:
                addAppointment();
                break;
            case 3:

    findAppointmentsByDoctorName();

                break;
            case 4:
                addPatient();
                break;

            case 5:
                displayPatients();
                break;

            case 6:
                findPatientByID();
                break;
            case 7:
                deletePatient();
                break;
            case 0:
                exit(0);
                break;

            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }

    return 0;
}
