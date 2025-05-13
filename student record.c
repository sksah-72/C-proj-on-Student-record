#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

void addStudent() {
    FILE *fp = fopen("students.dat", "ab");
    struct Student s;

    printf("Enter Roll No: ");
    scanf("%d", &s.roll);
    printf("Enter Name: ");
    scanf(" %[^\n]", s.name); // for reading string with spaces
    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);
    printf("Student record added successfully!\n\n");
}

void viewStudents() {
    FILE *fp = fopen("students.dat", "rb");
    struct Student s;

    printf("\n--- All Students ---\n");

    while (fread(&s, sizeof(s), 1, fp)) {
        printf("Roll No: %d\n", s.roll);
        printf("Name   : %s\n", s.name);
        printf("Marks  : %.2f\n\n", s.marks);
    }

    fclose(fp);
}

void searchStudent() {
    FILE *fp = fopen("students.dat", "rb");
    struct Student s;
    int targetRoll, found = 0;

    printf("Enter roll number to search: ");
    scanf("%d", &targetRoll);

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.roll == targetRoll) {
            printf("Student Found:\n");
            printf("Name  : %s\n", s.name);
            printf("Marks : %.2f\n", s.marks);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Student with Roll No %d not found.\n", targetRoll);

    fclose(fp);
}

int main() {
    int choice;

    do {
        printf("\n--- Student Record System ---\n");
        printf("1. Add Student\n");
        printf("2. View All Students\n");
        printf("3. Search Student by Roll No\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: searchStudent(); break;
            case 4: printf("Exiting program.\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}