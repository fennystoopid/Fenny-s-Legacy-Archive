#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME 100
#define MAX_LINE 256

// Utility: Check if file exists
int file_exists(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp) {
        fclose(fp);
        return 1;
    }
    return 0;
}

// Problem 1: Creating Files
void create_file() {
    char filename[MAX_FILENAME], line[MAX_LINE];
    printf("Enter new file name: ");
    scanf("%s", filename);

    if (file_exists(filename)) {
        printf("File already exists. Creation aborted to prevent overwriting.\n");
        return;
    }

    FILE *fp = fopen(filename, "w");
    if (!fp) {
        printf("Error creating file.\n");
        return;
    }

    printf("Enter content (type END on a new line to finish):\n");
    getchar(); // clear newline
    while (1) {
        fgets(line, MAX_LINE, stdin);
        if (strcmp(line, "END\n") == 0 || strcmp(line, "END\r\n") == 0)
            break;
        fputs(line, fp);
    }
    fclose(fp);
    printf("File created successfully.\n");
}

// Problem 2: Reading Files
void read_file() {
    char filename[MAX_FILENAME], line[MAX_LINE];
    printf("Enter file name to read: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("File not found.\n");
        return;
    }

    int line_count = 0;
    printf("\n--- File Content ---\n");
    while (fgets(line, MAX_LINE, fp)) {
        printf("%3d: %s", ++line_count, line);
    }
    if (line_count == 0)
        printf("[File is empty]\n");
    printf("\nTotal lines: %d\n", line_count);
    fclose(fp);
}

// Problem 3: Writing to Files
void write_file() {
    char filename[MAX_FILENAME], line[MAX_LINE];
    printf("Enter file name to overwrite: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "w");
    if (!fp) {
        printf("Error opening file for writing.\n");
        return;
    }

    printf("Enter new content (type END on a new line to finish):\n");
    getchar(); // clear newline
    while (1) {
        fgets(line, MAX_LINE, stdin);
        if (strcmp(line, "END\n") == 0 || strcmp(line, "END\r\n") == 0)
            break;
        fputs(line, fp);
    }
    fclose(fp);
    printf("File overwritten successfully.\n");
}

// Problem 4: Updating Files
void append_file() {
    char filename[MAX_FILENAME], line[MAX_LINE];
    printf("Enter file name to append: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "a");
    if (!fp) {
        printf("File does not exist. Creating new file.\n");
        fp = fopen(filename, "w");
        if (!fp) {
            printf("Error creating file.\n");
            return;
        }
    }

    printf("Enter content to append (type END on a new line to finish):\n");
    getchar(); // clear newline
    while (1) {
        fgets(line, MAX_LINE, stdin);
        if (strcmp(line, "END\n") == 0 || strcmp(line, "END\r\n") == 0)
            break;
        fputs(line, fp);
    }
    fclose(fp);
    printf("Content appended successfully.\n");
}

// Problem 5: Printing with Statistics
void print_stats() {
    char filename[MAX_FILENAME], line[MAX_LINE];
    printf("Enter file name for statistics: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("File not found.\n");
        return;
    }

    int lines = 0, words = 0, chars = 0;
    printf("\n--- File Content ---\n");
    while (fgets(line, MAX_LINE, fp)) {
        printf("%s", line);
        lines++;
        for (int i = 0; line[i]; i++) {
            chars++;
            if ((i == 0 && line[i] != ' ' && line[i] != '\n') ||
                (line[i] != ' ' && line[i] != '\n' && line[i-1] == ' '))
                words++;
        }
    }
    printf("\nLines: %d\nWords: %d\nCharacters: %d\n", lines, words, chars);
    fclose(fp);
}

int main() {
    int choice;
    do {
        printf("\n--- Text File Operations Menu ---\n");
        printf("1. Create File\n");
        printf("2. Read File\n");
        printf("3. Overwrite File\n");
        printf("4. Append to File\n");
        printf("5. Print File with Statistics\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: create_file(); break;
            case 2: read_file(); break;
            case 3: write_file(); break;
            case 4: append_file(); break;
            case 5: print_stats(); break;
            case 0: printf("Exiting program.\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 0);

    return 0;
}
