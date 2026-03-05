#include <stdio.h>
#include <string.h>

struct Student {
    int studentID;
    char Name[50];
    float marks[3]; //for three exams probably
    char grade;

};

// take student pointer and number of marks as function input
void calculateGrade(struct Student *s, int numMarks) {
    float sum = 0;
    for (int i = 0; i < numMarks; i++) {
        sum += s->marks[i];
    }
    float avg = sum / numMarks;

    if (avg >= 80 && avg <= 100)
        s->grade = 'A';
    else if (avg >= 65)
        s->grade = 'B';
    else if (avg >= 50)
        s->grade = 'C';
    else if (avg >= 30)
        s->grade = 'D';
    else
        s->grade = 'F';
}

int main() {
    struct Student s;
    int numMarks = 3; // You can change this as needed

    printf("Enter student ID: ");
    scanf("%d", &s.studentID);
    getchar(); // clear newline

    //to avoid issues with spaces in name
    printf("Enter student name: ");
    fgets(s.Name, sizeof(s.Name), stdin);
    s.Name[strcspn(s.Name, "\n")] = '\0';

    printf("Enter marks for %d exams:\n", numMarks);
    for (int i = 0; i < numMarks; i++) {
        printf("Exam %d: ", i + 1);
        scanf("%f", &s.marks[i]);
    }

    s.grade = 'F'; // Default grade
    calculateGrade(&s, numMarks);

    printf("\n--- Student Details ---\n");
    printf("ID: %d\n", s.studentID);
    printf("Name: %s\n", s.Name);
    printf("Marks: ");
    for (int i = 0; i < numMarks; i++) {
        printf("%.2f ", s.marks[i]);
    }
    printf("\nGrade: %c\n", s.grade);

    return 0;
}