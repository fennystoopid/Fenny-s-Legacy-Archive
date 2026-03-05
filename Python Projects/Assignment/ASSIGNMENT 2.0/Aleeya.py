from pathlib import Path

# Function to find the file path of a text file
def find_file_path(filename):
    cwd = Path.cwd()
    mod_path = Path(__file__).parent
    src_path = (mod_path / filename).resolve()
    return src_path

# Function to create a text file if it does not exist
def create_text_file(filename, content=""):
    try:
        with open(filename, "x") as file:
            file.write(content)
        print(f"{filename} created successfully.")
    except FileExistsError:
        print(f"{filename} already exists.")

# Function to append data to a text file
def append_to_text_file(filename, data):
    try:
        with open(filename, "a") as file:
            file.write(data + "\n")
        print("Data appended successfully.")
    except FileNotFoundError:
        print(f"{filename} not found.")

# Function to read content from a text file
def read_text_file(filename):
    try:
        with open(filename, "r") as file:
            content = file.readlines()
        return content
    except FileNotFoundError:
        print(f"{filename} not found.")
        return []

# Function to display the assigned modules
def view_assigned_modules():
    modules = read_text_file("assigned_modules.txt")
    if modules:
        print("\nAssigned Modules:")
        for idx, module in enumerate(modules, 1):
            print(f"{idx}. {module.strip()}")
    else:
        print("No assigned modules found.")

# Function to record student grades
def record_grades():
    module_name = input("Enter module name (IDB/CS/MM): ")
    student_name = input("Enter student name: ")

    # Check if student exists in the student list of the module
    if not student_exists_in_module(module_name, student_name):
        print(f"Student {student_name} is not enrolled in {module_name}.")
        add_student = input("Do you want to add this student to the module? (yes/no): ").strip().lower()
        if add_student == 'yes':
            append_to_text_file(f"{module_name}_students.txt", student_name)
            print(f"{student_name} added to {module_name}.")
        else:
            print("Grade not recorded.")
            return

    grade = input("Enter grade: ")

    # Validate grade input
    if not grade.isdigit():
        print("Invalid grade. Please enter a numeric value.")
        return

    # Append grade to the corresponding file
    grade_entry = f"{module_name} - {student_name} - {grade}"
    append_to_text_file(f"{module_name}_grades.txt", grade_entry)
    print(f"Grade for {student_name} in {module_name} recorded successfully.")

# Function to view the student list in a module
def view_student_list():
    module_name = input("Enter module name (IDB/CS/MM): ")
    students = read_text_file(f"{module_name}_students.txt")
    if students:
        print(f"\nStudent List for {module_name}:")
        for idx, student in enumerate(students, 1):
            print(f"{idx}. {student.strip()}")
    else:
        print(f"No students found for {module_name}.")

# Function to track student attendance
def track_attendance():
    module_name = input("Enter module name (IDB/CS/MM): ")
    student_name = input("Enter student name: ")

    # Check if student exists in the student list of the module
    if not student_exists_in_module(module_name, student_name):
        print(f"Student {student_name} is not enrolled in {module_name}.")
        add_student = input("Do you want to add this student to the module? (yes/no): ").strip().lower()
        if add_student == 'yes':
            append_to_text_file(f"{module_name}_students.txt", student_name)
            print(f"{student_name} added to {module_name}.")
        else:
            print("Attendance not recorded.")
            return

    status = input("Enter attendance status (Present/Absent): ").strip().lower()

    if status not in ["present", "absent"]:
        print("Invalid attendance status. Please enter 'Present' or 'Absent'.")
        return

    # Append attendance to the corresponding file
    attendance_entry = f"{module_name} - {student_name} - {status}"
    append_to_text_file(f"{module_name}_attendance.txt", attendance_entry)
    print(f"Attendance for {student_name} in {module_name} updated to {status.capitalize()}.")

# Function to view student grades in a module
def view_student_grades():
    module_name = input("Enter module name (IDB/CS/MM): ")
    grades = read_text_file(f"{module_name}_grades.txt")
    if grades:
        print(f"\nGrades for {module_name}:")
        for grade_entry in grades:
            print(grade_entry.strip())
    else:
        print(f"No grades found for {module_name}.")

# Function to display the main menu and handle actions
def display_lecturer_menu():
    while True:
        print("\nLecturer Menu:")
        print(" 1. View Assigned Modules")
        print(" 2. Record Grades")
        print(" 3. View Student List")
        print(" 4. Track Attendance")
        print(" 5. View Student Grades")
        print(" 6. Exit")

        select = input("\nChoose an option (1-6): ")

        if select == '1':
            view_assigned_modules()
        elif select == '2':
            record_grades()
        elif select == '3':
            view_student_list()
        elif select == '4':
            track_attendance()
        elif select == '5':
            view_student_grades()
        elif select == '6':
            print("Exiting the system....")
            break
        else:
            print("Invalid choice. Please try again.")

        continue_choice = input("\nDo you want to perform another action? (yes/no): ").strip().lower()
        if continue_choice != 'yes':
            print("Exiting program...")
            break

# Helper function to check if student exists in the module's student list
def student_exists_in_module(module_name, student_name):
    students = read_text_file(f"{module_name}_students.txt")
    return any(student.strip().lower() == student_name.lower() for student in students)

# Initialize data files if they do not exist
def initialize_files():
    # Create files for assigned modules, sample students, and grades
    create_text_file("assigned_modules.txt", "Introduction to Databases (IDB)\nComputer Science (CS)\nMathematics (MM)")
    
    # Student names
    create_text_file("IDB_students.txt", "Ahmad Zain\nNur Irdiena\nSiti Aisyah\n")
    create_text_file("CS_students.txt", "Mohd Faizal\nSharifah Alya\nNurul Aini\n")
    create_text_file("MM_students.txt", "Rashidah\nNurul Faiqah\nAli Hassan\n")
    
    create_text_file("IDB_grades.txt")
    create_text_file("CS_grades.txt")
    create_text_file("MM_grades.txt")
    create_text_file("IDB_attendance.txt")
    create_text_file("CS_attendance.txt")
    create_text_file("MM_attendance.txt")

if __name__ == "_main_":
    # Initialize data files if they do not exist
    initialize_files()

    # Start the lecturer menu
    display_lecturer_menu()