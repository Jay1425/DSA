#include <stdio.h>
#include <stdlib.h>

#define SIZE 50

struct Student {
    int Stu_no;
    char Stu_name[SIZE];
    float Stu_cpi;
};

void insert_data(struct Student[], int);
void display_data();
void compare_data();
void Sort_data();
void Remove_Duplicate_data();

int main() {
    struct Student *s1;
    int n, choice;

    printf("\nHow many students records do you want to enter: ");
    scanf("%d", &n);

    s1 = (struct Student *)malloc(n * sizeof(struct Student));
    if (s1 == NULL) {
        printf("Memory allocation failed!");
        return 1;
    }

    while (1) {
        printf("\nMENU:\n1. INSERT THE STUDENTS RECORDS\n2. DISPLAY THE STUDENTS RECORDS\n3. DISPLAY THE STUDENTS RECORDS WHO HAS CPI > 6.05\n4. SORT THE STUDENT RECORDS\n5. REMOVE THE DUPLICATED STUDENTS RECORDS\n6. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert_data(s1, n);
                break;
            case 2:
                display_data();
                break;
            case 3:
                compare_data();
                break;
            case 4:
                Sort_data();
                break;
            case 5:
                Remove_Duplicate_data();
                break;
            case 6:
                free(s1);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void insert_data(struct Student s1[], int n) {
    int i;
    FILE *f;

    f = fopen("students_data.txt", "a");
    if (f == NULL) {
        perror("Error opening file");
        return;
    }

    for (i = 0; i < n; i++) {
        printf("\nEnter the Student Roll No: ");
        scanf("%d", &s1[i].Stu_no);

        printf("Enter the Student Name: ");
        scanf("%s", s1[i].Stu_name);

        printf("Enter the Student CPI: ");
        scanf("%f", &s1[i].Stu_cpi);

        fprintf(f, "%d\t%s\t%.2f\n", s1[i].Stu_no, s1[i].Stu_name, s1[i].Stu_cpi);
    }

    fclose(f);
}

void compare_data()
{
    FILE *f;
    int stu_no;
    char stu_name[SIZE];
    float stu_cpi;
    int count = 0;

    // Open file in read mode
    f = fopen("students_data.txt", "r");
    if (f == NULL) {
        printf("Error opening file");
        return;
    }

    // Count the number of records in the file
    while (fscanf(f, "%d %s %f", &stu_no, stu_name, &stu_cpi) == 3) {
        count++;
    }
    fclose(f); // Close the file after counting

    // Reopen the file to read data from the beginning
    f = fopen("students_data.txt", "r");
    if (f == NULL) {
        printf("Error opening file");
        return;
    }

    // Allocate memory based on the number of records
    int *stu_nos = (int *)malloc(count * sizeof(int));
    char (*stu_names)[SIZE] = (char (*)[SIZE])malloc(count * SIZE * sizeof(char));
    float *stu_cpis = (float *)malloc(count * sizeof(float));

    if (stu_nos == NULL || stu_names == NULL || stu_cpis == NULL) {
        printf("Memory allocation failed!");
        fclose(f);
        return;
    }

    // Read the data again and store it in the arrays
    int i = 0;
    while (fscanf(f, "%d %s %f", &stu_no, stu_name, &stu_cpi) == 3) {
        stu_nos[i] = stu_no;

        // Copy student name without using strcpy
        int j = 0;
        while (stu_name[j] != '\0') {
            stu_names[i][j] = stu_name[j];
            j++;
        }
        stu_names[i][j] = '\0'; // Null-terminate the string

        stu_cpis[i] = stu_cpi;
        i++;
    }

    fclose(f); // Close the file

    // Display the student records who has cpi>6.5
    printf("\nStudent Records:\n");
    for (i = 0; i < count; i++) {
        if (stu_cpis[i]>6.5)
        {
            printf("%d \t%s \t%.2f\n", stu_nos[i], stu_names[i], stu_cpis[i]);
        }
    }

    // Free the allocated memory
    free(stu_nos);
    free(stu_names);
    free(stu_cpis);
}

void Sort_data()
{
    FILE *f;
    int stu_no;
    char stu_name[SIZE];
    float stu_cpi;
    int count = 0;
    // Open file in read mode
    f = fopen("students_data.txt", "r");
    if (f == NULL) {
        printf("Error opening file");
        return;
    }

    // Count the number of records in the file
    while (fscanf(f, "%d %s %f", &stu_no, stu_name, &stu_cpi) == 3) {
        count++;
    }
    fclose(f); // Close the file after counting

    // Reopen the file to read data from the beginning
    f = fopen("students_data.txt", "r");
    if (f == NULL) {
        printf("Error opening file");
        return;
    }

    // Allocate memory based on the number of records
    int *stu_nos = (int *)malloc(count * sizeof(int));
    char (*stu_names)[SIZE] = (char (*)[SIZE])malloc(count * SIZE * sizeof(char));
    float *stu_cpis = (float *)malloc(count * sizeof(float));

    if (stu_nos == NULL || stu_names == NULL || stu_cpis == NULL) {
        printf("Memory allocation failed!");
        fclose(f);
        return;
    }

    // Read the data again and store it in the arrays
    int i = 0;
    while (fscanf(f, "%d %s %f", &stu_no, stu_name, &stu_cpi) == 3) {
        stu_nos[i] = stu_no;

        // Copy student name without using strcpy
        int j = 0;
        while (stu_name[j] != '\0') {
            stu_names[i][j] = stu_name[j];
            j++;
        }
        stu_names[i][j] = '\0'; // Null-terminate the string

        stu_cpis[i] = stu_cpi;
        i++;
    }

    fclose(f); // Close the file

    // Display the student records
    printf("\nStudent Records:\n");
    for (i = 0; i < count; i++) {
        printf("%d \t%s \t%.2f\n", stu_nos[i], stu_names[i], stu_cpis[i]);
    }

    // Free the allocated memory
    free(stu_nos);
    free(stu_names);
    free(stu_cpis);
}

void Remove_Duplicate_data()
{

}

void display_data() {
    FILE *f;
    int stu_no;
    char stu_name[SIZE];
    float stu_cpi;
    int count = 0;

    // Open file in read mode
    f = fopen("students_data.txt", "r");
    if (f == NULL) {
        printf("Error opening file");
        return;
    }

    // Count the number of records in the file
    while (fscanf(f, "%d %s %f", &stu_no, stu_name, &stu_cpi) == 3) {
        count++;
    }
    fclose(f); // Close the file after counting

    // Reopen the file to read data from the beginning
    f = fopen("students_data.txt", "r");
    if (f == NULL) {
        printf("Error opening file");
        return;
    }

    // Allocate memory based on the number of records
    int *stu_nos = (int *)malloc(count * sizeof(int));
    char (*stu_names)[SIZE] = (char (*)[SIZE])malloc(count * SIZE * sizeof(char));
    float *stu_cpis = (float *)malloc(count * sizeof(float));

    if (stu_nos == NULL || stu_names == NULL || stu_cpis == NULL) {
        printf("Memory allocation failed!");
        fclose(f);
        return;
    }

    // Read the data again and store it in the arrays
    int i = 0;
    while (fscanf(f, "%d %s %f", &stu_no, stu_name, &stu_cpi) == 3) {
        stu_nos[i] = stu_no;

        // Copy student name without using strcpy
        int j = 0;
        while (stu_name[j] != '\0') {
            stu_names[i][j] = stu_name[j];
            j++;
        }
        stu_names[i][j] = '\0'; // Null-terminate the string

        stu_cpis[i] = stu_cpi;
        i++;
    }

    fclose(f); // Close the file

    // Display the student records
    printf("\nStudent Records:\n");
    for (i = 0; i < count; i++) {
        printf("%d \t%s \t%.2f\n", stu_nos[i], stu_names[i], stu_cpis[i]);
    }

    // Free the allocated memory
    free(stu_nos);
    free(stu_names);
    free(stu_cpis);
}
