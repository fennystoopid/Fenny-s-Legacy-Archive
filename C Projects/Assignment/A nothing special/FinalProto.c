#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

//you can create, open, read and write to files by declaring a file pointer of type and using fopen()
//modes: w, r, a, w+, r+, a+
//w: open for writing, if the file exists, it is truncated to zero length
//r: open for reading, if the file does not exist, it returns NULL
//a: open for appending, if the file does not exist, it is created
//w+: open for reading and writing, if the file exists, it is truncated to zero length
//r+: open for reading and writing, if the file does not exist, it returns NULL
//a+: open for reading and writing, if the file does not exist, it is created

//Define the maximum filename and line length
#define MAX_FILENAME 100
#define MAX_LINE 256

//Define a string for filename and the max line length.
char filename[MAX_FILENAME], line[MAX_LINE], temp_filename[MAX_FILENAME];

//define a union for file metadata (report)
union FileMeta {
    int lines;
    float size_kb;
};
union FileMeta meta;

//define file handling functions
int file_exists(const char *filename); //file existence check
void create_file(); //creating a new text file
void read_file(); //reading a text file
void append_data(); //appending data to text files
void delete_data(); //deleting data from text files
void update_data(); //updating data in text files

//define advanced features functions
void print_report();
void file_list();

int main() 
{
    int choice;
    do {
        printf("\n==================================\n");
        printf("--Administration Management Menu--");
        printf("\n==================================\n");
        printf("1. Create a new Text File\n");
        printf("2. Read a Text File\n");
        printf("3. Add/Append Data into Text File\n");
        printf("4. Delete data from Text File\n");
        printf("5. Update data in Text File\n");
        printf("6. Print a Report\n");
        printf("7. View all Text File in a Folder\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: create_file(); break;
            case 2: read_file(); break;
            case 3: append_data(); break;
            case 4: delete_data(); break;
            case 5: update_data(); break;
            case 6: print_report(); break;
            case 7: file_list(); break;
            case 0: printf("Exiting program.\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 0);

    return 0;
}

//Check if file exists
int file_exists(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp) {
        fclose(fp);
        return 1;
    }
    return 0;
}

//Creating Files
void create_file() {
    printf("Please enter the new file name: ");
    scanf("%s", filename);

    snprintf(filename, sizeof(filename), "%s.txt", filename);

    if (file_exists(filename)) {
        printf("File already exists. Please use a another name or try again.\n");
        return;
    }

    FILE *fp = fopen(filename, "w");
    if (!fp) {
        printf("An error has occured during file creation.\n");
        return;
    }

    printf("Input the text content into the file (type END on a new line to finish):\n");
    getchar(); // clear newline
    while (1) {
        fgets(line, MAX_LINE, stdin);
        if (strcmp(line, "END\n") == 0 || strcmp(line, "END\r\n") == 0)
            break;
        fputs(line, fp);
    }
    fclose(fp);
    printf("\nFile created successfully.\n");
}

//Reading Files
void read_file() {
    printf("Please enter the file name to read: ");
    scanf("%s", filename);

    snprintf(filename, sizeof(filename), "%s.txt", filename);

    FILE *fp = fopen(filename, "r");
    // if file pointer not found, print an error message
    if (!fp) {
        printf("File not found.\n");
        return;
    }

    // declare line count to zero, counts ++1 for each line read
    int line_count = 0;
    printf("\n--- File Content ---\n");
    while (fgets(line, MAX_LINE, fp)) {
        printf("%3d: %s", ++line_count, line);
    }
    if (line_count == 0) {
        printf("[File is empty]\n");
    }
    printf("\nTotal lines: %d\n", line_count);
    fclose(fp);
}

//adding/appending data to text files
void append_data() {

    printf("Enter file name to add data into: ");
    scanf("%s", filename);

    snprintf(filename, sizeof(filename), "%s.txt", filename);

    FILE *fp = fopen(filename, "a");
    if (!fp) {
        printf("File does not exist.\n");
        return;
    }

    printf("Enter data content to add (type END on a new line to finish):\n");
    getchar(); // clear newline
    while (1) {
        fgets(line, MAX_LINE, stdin);
        if (strcmp(line, "END\n") == 0 || strcmp(line, "END\r\n") == 0)
            break;
        // Ensure the line ends with a newline
        size_t len = strlen(line);
        if (len == 0 || line[len - 1] != '\n') {
            line[len] = '\n';
            line[len + 1] = '\0';
        }
        fputs(line, fp);
    }
        
    fclose(fp);
    printf("Data content added successfully.\n");
}

//Updating data in text files
void update_data() {

    char search_str[MAX_LINE], replace_str[MAX_LINE];

    printf("Enter file name to update data in: ");
    scanf("%s", filename);
    snprintf(filename, sizeof(filename), "%s.txt", filename);

    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("File not found.\n");
        return;
    }

    // Show file contents for reference
    printf("\n--- File Content ---\n");
    int line_count = 0;
    while (fgets(line, MAX_LINE, fp)) {
        printf("%3d: %s", ++line_count, line);
    }
    if (line_count == 0) {
        printf("[File is empty]\n");
        fclose(fp);
        return;
    }
    printf("\n");
    rewind(fp); // Go back to the start for actual deletion

    printf("Enter the exact data to update: ");
    getchar(); // clear newline
    fgets(search_str, MAX_LINE, stdin);
    search_str[strcspn(search_str, "\n")] = '\0'; // remove newline

    printf("Enter the new data: ");
    fgets(replace_str, MAX_LINE, stdin);
    replace_str[strcspn(replace_str, "\n")] = '\0'; // remove newline

    snprintf(temp_filename, sizeof(temp_filename), "temp_%s", filename);
    FILE *temp_fp = fopen(temp_filename, "w");
    if (!temp_fp) {
        printf("Could not create temporary file.\n");
        fclose(fp);
        return;
    }

    int updated = 0;
    int total_matches = 0;
    while (fgets(line, MAX_LINE, fp)) {
        char *pos = NULL;
        char buffer[MAX_LINE * 2]; // To handle replacement
        char *src = line;
        buffer[0] = '\0';

        int matches_in_line = 0;
        while ((pos = strstr(src, search_str)) != NULL) {
            strncat(buffer, src, pos - src); // Copy up to match
            strcat(buffer, replace_str);     // Add replacement
            src = pos + strlen(search_str);  // Move past match
            updated = 1;
            matches_in_line++;
        }
        strcat(buffer, src); // Copy the rest of the line

        if (matches_in_line > 0) {
            total_matches += matches_in_line;
            fputs(buffer, temp_fp);
        } else {
            fputs(line, temp_fp);
        }
    }

    fclose(fp);
    fclose(temp_fp);

    // Replace original file with temp file
    if (remove(filename) == 0 && rename(temp_filename, filename) == 0) {
        printf("Update completed.\n");
        if (total_matches > 1) {
            printf("Warning: %d identical data matches were found and replaced.\n", total_matches);
        } else if (total_matches == 1) {
            printf("One match was found and replaced.\n");
        } else {
            printf("No matches found for \"%s\".\n", search_str);
        }
    } else {
        printf("Error occurred while updating data. Please try again.\n");
    }
}

//Deleting data from text files
void delete_data() {

    char del_data[MAX_LINE];

    printf("Enter file name to delete data from: ");
    scanf("%s", filename);
    snprintf(filename, sizeof(filename), "%s.txt", filename);

    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("File not found.\n");
        return;
    }

    // Show file contents for reference
    printf("\n--- File Content ---\n");
    int line_count = 0;
    while (fgets(line, MAX_LINE, fp)) {
        printf("%3d: %s", ++line_count, line);
    }
    if (line_count == 0) {
        printf("[File is empty]\n");
        fclose(fp);
        return;
    }
    printf("\n");
    rewind(fp); // Go back to the start for actual deletion

    printf("Enter the any data content or identifier to delete: ");
    getchar(); // clear newline
    fgets(del_data, MAX_LINE, stdin);
    del_data[strcspn(del_data, "\n")] = '\0'; // remove newline

    snprintf(temp_filename, sizeof(temp_filename), "temp_%s", filename);
    FILE *temp_fp = fopen(temp_filename, "w");
    if (!temp_fp) {
        printf("Could not create temporary file.\n");
        fclose(fp);
        return;
    }

    int removed = 0;
    while (fgets(line, MAX_LINE, fp)) {
        // If del_data is found anywhere in the line, skip writing it
        if (strstr(line, del_data) == NULL) {
            fputs(line, temp_fp);
        } else {
            removed = 1;
        }
    }

    fclose(fp);
    fclose(temp_fp);

    // Replace original file with temp file
    if (remove(filename) == 0 && rename(temp_filename, filename) == 0) {
        if (removed)
            printf("Line(s) containing \"%s\" data deleted successfully.\n", del_data);
        else
            printf("No lines containing \"%s\" data were found.\n", del_data);
    } else {
        printf("Error occurred while deleting data. Please try again.\n");
    }

}

//Printing Report
void print_report() {
    printf("Enter file name for report creation: ");
    scanf("%s", filename);

    snprintf(filename, sizeof(filename), "%s.txt", filename);

    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("File not found.\n");
        return;
    }

    // Get current date and time
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    int lines = 0, words = 0, chars = 0;

    printf("\n========================================\n");
    printf("           BUSINESS FILE REPORT         \n");
    printf("========================================\n");
    printf("File Name : %s\n", filename);
    printf("Date      : %02d-%02d-%04d %02d:%02d:%02d\n",
           t->tm_mday, t->tm_mon + 1, t->tm_year + 1900,
           t->tm_hour, t->tm_min, t->tm_sec);
    printf("----------------------------------------\n");
    printf("Content:\n");

    // Print file content with line numbers
    int line_count = 0;
    while (fgets(line, MAX_LINE, fp)) {
        printf("%3d | %s", ++line_count, line);
        lines++;
        for (int i = 0; line[i]; i++) {
            chars++;
            if ((i == 0 && line[i] != ' ' && line[i] != '\n') ||
                (line[i] != ' ' && line[i] != '\n' && line[i-1] == ' '))
                words++;
        }
    }
    if (lines == 0) {
        printf("[File is empty]\n");
    }

    // Use union for metadata
    
    meta.lines = lines;

    // Get file size in KB using stat
    FILE *size_fp = fopen(filename, "rb");
    fseek(size_fp, 0, SEEK_END);
    long size_bytes = ftell(size_fp);
    fclose(size_fp);
    meta.size_kb = (float)size_bytes / 1024.0f;

    printf("\n----------------------------------------\n");
    printf("Summary:\n");
    printf("Total Lines     : %d\n", lines);
    printf("File Size (KB)  : %.2f\n", meta.size_kb);
    printf("========================================\n");

    fclose(fp);
}

void file_list() {

    char folder[MAX_FILENAME];
    char search_path[MAX_FILENAME * 2];

    printf("Enter folder name in system to generate list of (use . for current folder): ");
    scanf("%s", folder);

    // Build the search path: e.g., "folder\\*.txt"
    snprintf(search_path, sizeof(search_path), "%s\\*.txt", folder);

    WIN32_FIND_DATA findFileData;
    HANDLE hFind = FindFirstFileA(search_path, &findFileData);

    if (hFind == INVALID_HANDLE_VALUE) {
        printf("\nNo files found in this folder.\n");
    } else {
        printf("\n---List of files in this folder---\n");
        int count = 1;
        do {
            if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
                continue; // Skip directories
            }
            printf("%2d %s\n", count++, findFileData.cFileName);
        } while (FindNextFile(hFind, &findFileData) != 0);
        FindClose(hFind);
        printf("\nTotal files: %d\n", count - 1);
    }
}

