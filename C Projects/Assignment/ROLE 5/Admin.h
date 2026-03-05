#ifndef ADMIN_H
#define ADMIN_H

#define MAX_FILENAME 100
#define MAX_LINE 256

//Define a string for filename and the max line length.
char filename[MAX_FILENAME], line[MAX_LINE], temp_filename[MAX_FILENAME];

// Struct for file statistics
typedef struct {
    int lines;
    int words;
    int chars;
    float size_kb;
} FileStats;

// Union for file metadata (for report)
union FileMeta {
    FileStats stats;
    float size_kb;
};

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

#endif