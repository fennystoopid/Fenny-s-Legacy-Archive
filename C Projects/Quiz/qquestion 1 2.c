#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 50

void InputData(char name[][50], float marks[][3], int numofStuds);
float CalculateAverage(float marks[]);
void printreport(char name[][50], float marks[][3], float avgs[], char status[][20], int num);

int main() {
    int numofStuds, i;
    char name[MAX_STUDENTS][50]; // Array to hold names of students
    float marks[MAX_STUDENTS][3]; // Array to hold marks for 3 subjects
    float avgs[MAX_STUDENTS]; // Array to hold average marks for each student
    char status[MAX_STUDENTS][20]; // Array to hold scholarship eligibility status

    printf("Enter total number of students: ");
    scanf("%d", &numofStuds);

    if (numofStuds < 1 || numofStuds > MAX_STUDENTS) {
        printf("Invalid number of students. Please enter a number between 1 and %d.\n", MAX_STUDENTS);
        return 1; // Exit if the number of students is invalid
    }

    // Input student data
    InputData(name, marks, numofStuds);

    for (i = 0; i < numofStuds; i++) {
        avgs[i] = CalculateAverage(marks[i]); // Calculate average for each student
        if (avgs[i] >= 75.0) {
            strcpy(status[i], "Eligible");
        } else {
            strcpy(status[i], "Not Eligible");
        }
    }

    printreport(name, marks, avgs, status, numofStuds);

    return 0;
}



void InputData(char name[][50], float marks[][3], int numofStuds) {

    for (int i = 0; i < numofStuds; i++) {

            printf("Enter student %d name: ", i + 1);
            getchar(); // Clear newline character from previous input
            fgets(name[i], sizeof(name[i]), stdin);
            name[i][strcspn(name[i], "\n")] = '\0'; // Remove newline character

            printf("---Enter marks for exams---\n");
                for (int j = 0; j < 3; j++) {
                    do {
                        printf("Subject %d: ", j + 1);
                        scanf("%f", &marks[i][j]);
                        if (marks[i][j] < 0 || marks[i][j] > 100) {
                            printf("Invalid marks. Please enter a value between 0 and 100.\n");
                        }
                    } while (marks[i][j] < 0 || marks[i][j] > 100); // Ensure marks are between 0 and 100
                }   
        }
}

float CalculateAverage(float marks[]) {
    float sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += marks[i];
    }
    return sum / 3.0; // Average across all students and subjects
}

void printreport(char name[][50], float marks[][3], float avgs[], char status[][20], int num) {

    printf("\n--- Student Scholarship Eligibility Report ---\n");
    printf("%-20s %-20s %-20s %-20s %-20s %-20s\n", "Name", "Score1", "Score2", "Score3", "Average", "Status");

    for (int i = 0; i < num; i++) {
        printf("%-20s %-20.2f %-20.2f %-20.2f %-20.2f %-20s\n",
        name[i], 
        marks[i][0], 
        marks[i][1], 
        marks[i][2], 
        avgs[i], 
        status[i]);
    }
}
