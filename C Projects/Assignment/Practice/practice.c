#include <stdio.h>
int main() {
// data type (set of values and operations on those values)

    // two categories of data types in C:

    //built-in data types
    int integerVar = 10; //int 16 bits
    unsigned int unsignedIntVar = 20; //unsigned integer 16 bits
    short shortVar = 5; //short integer 8 bits
    unsigned short unsignedShortVar = 15; //unsigned short integer 8 bits
    long int longVar = 100000L; //long integer 32 bits
    unsigned long int unsignedLongVar = 200000UL; //unsigned long integer 32 bits
    float floatVar = 5.5f; //float 32 bits
    double doubleVar = 3.14159; //double 64 bits
    long double longDoubleVar = 2.718281828459045L; //long double 80 bits
    char charVar = 'A'; //character 8 bits
    unsigned char unsignedCharVar = 'B'; //unsigned character 8 bits

    //programmer-defined data types
    typedef struct {
        int id;
        char name[50];
    } Student; // structure type
    char Name[100]; //array of characters (string)

// keywords (reserved words in C)

    // case sensitive keywords, must be typed in lowercase, appear in the
    // correct location, and cannot be used as identifiers.

    // auto, break, case, char, const, continue, default, do, double,
    // else, enum, extern, float, for, goto, if, int, long, register,
    // return, short, signed, sizeof, static, struct, switch, typedef,
    // union, unsigned, void, volatile, while

//functions

    // Modular programming is a concept to divide a large code into sub tasks
    // or program (able to work independently)

    // Why? 
    // The complexity of the programming problems increases, and becomes
    // more difficult to provide a solution to solve the problems.
    // Solution: Divide em. Each of them becomes a module.

    // Benefit?
    // Easy to understand
    // Reusable code in other program (THE CTRL C CTRL V MOVE)
    // Elimination of redundancy
    // Efficiency of maintenance

    // Modules in C known as function, programmer defined and pre-packaged 
    // (available in standard library)

    // [STANDARD C LIBRARY]
    // stdio.h (for input/output), math.h (mathematical operation)
    // stdlib.h (general functions, memory, random number, conversion)
    
    // [PROGRAMMER DEFINED FUNCTIONS]

    // [Function prototypes] 
    // Are listed at the beginning of the source file.
    // After the pre-processor directives.
    // Might be placed in a user-defined header file.

    // [Function definition]
    // Written before or after the main function.

    // [Function call]
    // Written within the main function.

    // [FUNCTION PROTOTYPE]
    // return_data_type function_name(parameter_list/arguments);
    // Example: 
    int add(int a, int b);
    // you can use float, char, double, etc. as return data type.

    // [HEADER FILES]
    #include <stdio.h> // standard input/output header file
    // #include "filename.h" // custom header file

    // [RECURSION]
    // A function that calls itself is called a recursive function, directly or indirectly.

    // [STORAGE CLASSES]
    // Auto, extern, static, register

    // [auto]
    // Default storage class for local variables. Most common.
    // Variables declared inside a function are auto by default.

    // [extern]
    // Used to declare a global variable or function that is defined in another file.
    // It allows the variable or function to be accessed from other files.

    // [register]
    // Used to declare a variable that should be stored in a CPU register instead of RAM.
    // This can improve performance for frequently accessed variables.
    // Note: The compiler decides whether to use a register or not, based on optimization.

    // [static]
    // Used to declare a variable that retains its value between function calls.
    // It is initialized only once and retains its value throughout the program's execution.

    // [SCOPE FOR AN IDENTIFIER]
    // Function scope, block scope, file scope, and function-prototype scope.

    // Function scope: Identifiers declared within a function are only accessible within that function.
    // Block scope: Identifiers declared within a block (enclosed by curly braces) are 
    // only accessible within that block.
    // File scope: Identifiers declared outside any function are accessible throughout the file.
    // Function-prototype scope: Identifiers declared in a function prototype are accessible

// [[CONTROL STRUCTURE - SELECTION & ITERATION]]

    // control structure [SELECTION] 
    int grade = 60;

    // Three types of selection structures

    // if statement
    if (grade == 'A'){
        printf("Passed");
    };

    // if-else statement
    if (grade >= 60)
        printf ("Passed");
    else
        printf("Failed");

    // switch statement
    char class;
    scanf("%c",&class); 
    switch (class) {
        case 'B':
        case 'b': 
            printf ("Battleship\n");
            break;
        case 'C':
        case 'c': 
            printf ("Cruiser\n");	             			
            break;
        case 'D':
        case 'd': 
            printf ("Destroyer\n");
            break;     
        case 'F':
        case 'f': 
            printf ("Frigate\n");
            break;
        default : 
            printf ("Unknown ship class %c\n",  class);
    }
 
    //ADDITIONAL STUFF
    
    // Logical AND (&&)
    if (grade <= 61 && grade > 70) { 
        printf("Grade is B");
    }

    // Logical OR ()
    if (grade <= 61 || grade > 70) { 
        printf("Grade is B");
    }

    // control structure [ITERATIVE] 

    // Two kinds of control within a iterative construct or loop.

    // [Counter-controller/definite loop] 
    // Number of iterations is known in advance, used if wanna to execute
    // a specific number of times.

    // [Sentinel-controlller/indefinite loop]
    // Continues looping until certain condition (sentinel) is met. It could be
    // user input, a certain value from data or any trigger.
    // Used when number of iterations is not known in advance or u want user to
    // finish it off.

    // Iterative constructs

    // Three primary loop contructs (INFINITE LOOPS FOREVER AND MUST BE AVOIDED)
    
    // while

        // [COUNTER]
        int count_star = 1, sum = 0;
        while (count_star < 10){
            sum += 1;
            count_star++; 
        }

        // [SENTINEL]
        int sentinel = -1, sum = 0, numbers = 0;
        while (numbers != sentinel){
            sum += 1;
        }

    // do while

        // [COUNTER]
        int count = 1;
        do {
            printf("%d", count);
        } while (count++ <= 10);

        // [SENTINEL]
        char letter;
        do {
            printf("Enter a letter A thru E");
            scanf("%c", &letter);
        } while (letter < 'A' || letter > 'E');

    // for (primary used for counter-controlled loops)

        // [COUNTER]
        int number;
        float value, total;
        printf("Enter number: ");
        scanf("%d", &number);
        for(int i = 1; i <= number; i++) {
            printf("Enter value: ");
            scanf("%f", &value);
            total += value;
        }
        printf("Average = %.2f", total/number);

        // [SENTINEL]
        int i;
        float value, total;
        printf("Enter positive value only: ");
        scanf("%f", &value);
        for(i = 1; value > 0; i++) {
            total += value;
            printf("Enter positive value only: ");
            scanf("%f", &value);
        }
        printf("Average = %.2f", total/(i-1));

    // Nested Loops, basically putting loop inside a loop (such as while loop in while loop)
    // Break statement in while, do-while or for causes immediate exit from structure.
    // Continue statement skips the remaining statements in body, to next iteration.


//pointers

    // A pointer is a variable that stores the memory address of another variable.
    // It allows direct access to memory locations and manipulation of data.

    // Pointers are declared using the asterisk (*) symbol.
    // The unary & is used to get the address of a variable
    // and the unary * is used to dereference a pointer.
    int num = 10;
    int *ptr = &num; // ptr points to the address of num
    printf("Value of num: %d\n", *ptr); // dereferencing ptr to get value of num
    *ptr = 20; // changing value of num through pointer
    printf("New value of num: %d\n", num); // prints 20

    // why?
    // it is the only way to access memory directly and express some computations.
    // Makes a compact and efficient code.
    // very powerful, but also dangerous if not used carefully.

    // used explicitly in C, on arrays, structures and functions.

    // [POINTERS & ARRAYS]
    // Arrays are closely related to pointers in C.
    // An array name acts as a pointer to the first element of the array.
    int arr[] = {1, 2, 3, 4, 5};
    int *arrPtr = arr; // arrPtr points to the first element of arr 
    printf("First element of arr: %d\n", *arrPtr); // prints 1
    // You can use pointer arithmetic to access other elements of the array.
    for (int i = 0; i < 5; i++) {
        printf("Element %d: %d\n", i, *(arrPtr + i)); // prints elements of arr
    }

    // [POINTERS & FUNCTIONS]
    // Two ways to pass arguments to functions in C: by value and by reference.
    // All function calls in C are by value.

    // Call by value:
    // When you pass a variable to a function, a copy of the variable is made.
    // Changes made to the parameter inside the function do not affect the original
    // variable.
    // void modifyValueByValue(int value) {
    //    value = 20; // changing value of the local copy
    //}

    // Call by reference:
    // When you pass a pointer to a function, the function can modify the original
    // variable by dereferencing the pointer.
    // void modifyValue(int *ptr) {
    //   *ptr = 30; // changing value of the variable pointed by ptr
    //}

    // Functions returning pointers:
    // A function can also return back a pointer to the caller
    // Example:
    // int * check (int x)
    // the function check, receives an integer as a parameter
    // and returns a pointer to an integer.


//dynamic memory

// Dynamic memory allocation is the process of allocating memory at runtime
// using functions like malloc(), calloc(), realloc(), and free().
// Used in data structures like linked lists, trees, graphs and queues.
// They are data structures that grow and shrink dynamically as needed.

    // [malloc()]
    // Allocates a specified number of bytes in memory and returns a pointer to the allocated memory.
    // Example: int *arr = (int *)malloc(5 * sizeof(int)); // allocates memory for 5 integers

    // [calloc()]
    // Allocates memory for an array of elements, initializes them to zero, and returns a pointer to the allocated memory.
    // Example: int *arr = (int *)calloc(5, sizeof(int)); // allocates memory for 5 integers initialized to 0

    // [realloc()]
    // Resizes previously allocated memory block to a new size and returns a pointer to the reallocated memory.
    // Example: arr = (int *)realloc(arr, 10 * sizeof(int)); // resizes arr to hold 10 integers

    // [free()]
    // Deallocates previously allocated memory block to prevent memory leaks.
    // Example: free(arr); // deallocates memory allocated for arr


//file operations/handling

    // [FILES]
    // Data hierarchy:
    // Bit -> Byte -> Field -> Record -> File -> Database
    
    // [TEXT FILE FUNCTIONs]
    // fopen() - Opens a text file
    // fclose() - Closes a text file
    // fwrite() - writes a block of data to a file.
    // feof() - Detects end-of-file marker in a file
    // fprintf() - Prints formatted output to a file
    // fscanf() - Reads formatted output from a file.
    // fputs() - Prints a string to a file
    // fgets() - Reads a string from a file
    // fputc() - Prints a character to a file
    // fgetc() - Reads a character from a file 

    // [OPEN FILE MODES]
    // 	r              Open a text file for Reading
	//	w	     Create a text file for Writing
	//	a	     Append to a text File
	//	r+	     Open a text file for read/write
	//	w+	     Create a text file for read/write   
	//	a+	     Append/Create a text file for r/w       

    // EOF, End of File Marker
    // It is a special character that indicates the end of a file.
    // It is returned by read commands like fgetc() or fscanf() when 
    // they try to read beyond the end of the file.
    // Example:
    // char ch;		       
	//	ch=fgetc(fp);
    //		while(ch !=EOF) 
	//	{ 
	//		putchar(ch);
	//		ch=fgetc(fp); 
	//	}  

    // Use of getchar() and fputc()
    // getchar() reads a character from the standard input (keyboard).
    // fputc() writes a character to a file.

    // Use of fgets() and fputs()
    // fgets() reads a string from a file until a newline character or EOF is encountered.
    // fputs() writes a string to a file.

    // Use of gets() and fputs()
    // gets() reads a string from the standard input (keyboard) until a newline character is encountered.
    // fputs() writes a string to a file.

//operators

    // Operators are symbols that perform operations on variables and values.
    // C has several types of operators, including arithmetic, relational, logical,
    // bitwise, assignment, and conditional operators.

    // [ARITHMETIC OPERATORS]
    // () (Parentheses), * (multiplication), / (division), % (modulus), + (addition), - (subtraction)

    // [RELATIONAL OPERATORS]
    // == (equal to), != (not equal to), > (greater than), < (less than),
    // >= (greater than or equal to), <= (less than or equal to)

    // [LOGICAL OPERATORS]
    // && (logical AND), || (logical OR), ! (logical NOT)

    // [UNARY OPERATORS]
    // ++ (increment), -- (decrement), & (address of), * (dereference)

    // [BINARY OPERATORS]
    // + (addition), - (subtraction), * (multiplication), / (division), % (modulus),

    // [TERNARY OPERATORS]
    // ? (conditional operator), c =  (a > b) ? a : b;

//Types of errors

    // Errors in C programming can be broadly classified into three categories:
    // 1. Syntax errors
    // 2. Runtime errors
    // 3. Logical errors

// Syntax errors are mistakes in the code that violate the rules of the C language.
// List of common syntax errors in C:

    // Missing semicolon at the end of a statement
    // Example: int x = 10 // missing semicolon

    // Mismatched parentheses, brackets, or braces
    // Example: if (x > 0 { printf("Positive"); } // missing closing parenthesis

    // Incorrect variable declaration or initialization
    // Example: int 1number = 5; // variable name cannot start with a digit

    // Using undeclared variables
    // Example: printf("%d", undeclaredVar); // undeclared variable

    // Incorrect function calls or definitions
    // Example: void myFunction(int x) { return x; } // function cannot return a value if declared as void

// Logical errors are mistakes that made unexpected results. Can go unnoticed.

// Runtime errors occurs when attempting to execute an illegal operation. Zero division.

//coding fundamentals

    // Coding fundamentals in C programming include understanding data types, control structures,
    // functions, pointers, dynamic memory allocation, file handling, operators, and error handling.
    // These concepts form the foundation of C programming and are essential for writing efficient
    // and maintainable code.

    return 0; // Return 0 to indicate successful execution

}