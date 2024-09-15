#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a student node
struct Student {
    char name[100];
    int age;
    int marks;
    struct Student* next; // Pointer to the next node (circular link)
};

// Function to create a new student node
struct Student* createStudent(char name[], int age, int marks) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    strcpy(newStudent->name, name);
    newStudent->age = age;
    newStudent->marks = marks;
    newStudent->next = NULL;
    return newStudent;
}

// Function to insert a student at the end of the circular linked list
void insertStudent(struct Student** head, char name[], int age, int marks) {
    struct Student* newStudent = createStudent(name, age, marks);
    
    if (*head == NULL) {
        *head = newStudent;
        newStudent->next = *head;  // Circular link
    } else {
        struct Student* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newStudent;
        newStudent->next = *head;  // Circular link
    }
}

// Function to display students whose marks are less than 100
void display(struct Student* head) {
    if (head == NULL) {
        printf("No students in the list.\n");
        return;
    }

    struct Student* temp = head;
    do {
        if (temp->marks < 100) {
            printf("Name: %s, Age: %d, Marks: %d\n", temp->name, temp->age, temp->marks);
        }
        temp = temp->next;
    } while (temp != head);
}

// Main function
int main() {
    struct Student* head = NULL;  // Initialize an empty list

    // Insert students into the circular linked list
    insertStudent(&head, "Alice", 20, 95);
    insertStudent(&head, "Bob", 21, 85);
    insertStudent(&head, "Charlie", 19, 105);
    insertStudent(&head, "David", 22, 98);

    // Display students with marks less than 100
    printf("Students with marks less than 100:\n");
    display(head);

    return 0;
}

