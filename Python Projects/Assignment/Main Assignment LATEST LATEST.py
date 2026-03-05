import datetime
import os
## Pathlib library, modern way for file handling python 3 and up.
from pathlib import Path
#import admin_func (THIS is previously used for admin.. i can explain later) 
 
# Identification of the file names
MODULES_FILE = "modules.txt"
STUDENTS_FILE = "students.txt"
ENROLLMENTS_FILE = "enrollments.txt"
GRADES_FILE = "grades.txt"
ATTENDANCE_FILE = "attds.csv"
TRANSCRIPT_FILE = "transcripts.txt"
FEEDBACK_FILE = "feedback.txt"
TUITION_FILE = "tuitionRec.txt"
USER_FILE = "userfile.txt"

student_records = {}

#-------- Global Functions ----------
## Relative path file system
def FindFilePath(filename):
    ## Get the current working directory
    cwd = Path.cwd()

    ## Get the directory of the executing script
    mod_path = Path(__file__).parent  

    ## Define your relative path
    relative_path_1 = filename

    # Outputs an absolute path to the target directory
    src_path_1 = (mod_path / relative_path_1).resolve()
    return src_path_1


# ------ Admin Functions ---------
#create new text file
def create_file(file):
    textfile = open(file, "x")
    textfile.close()

#append existing text file/editing text file without overwriting it, just adding more.
def append_file(file, data):
    textfile = open(file , "a")
    textfile.write(data)
    textfile.close()

#delete existing file.
#def delete_file(file, data):
 #   textfile = open(file , "a")
  #  textfile.write(data)
   # textfile.close()###

## First Time startup, since no text file is created during your first time :3
def FirstTimeStart():
    try:
        #Create Course Text File
        create_file(FindFilePath('modules.txt'))
        #Create Student Text file
        create_file(FindFilePath('students.txt'))
        #Create Lecturer file
        create_file(FindFilePath('lecturer.txt'))
        print("First time startup complete!")
    except FileExistsError:
        print("File exist! Continuing program..")

## COURSES ##
def course_mainmenu():
    try:
        choice = int(input("""\n
        Do you like to add a new course or remove existing courses?
        [1] Add
        [2] Remove
        [3] Update
        [0] Back to main menu
        
        Please input option:
        """))
        if choice == 1:
            add_course()
        elif choice == 2:
            remove_course()
        elif choice == 3:
            update_course()
        elif choice == 0:
            return
        else:
            ValueError
    except ValueError:
        print("Invalid input. Try again..")
        course_mainmenu()
    except:
        print("An error have occurred..")


## Add Course function
def add_course():
    try:
        #Determine the amount of courses based on number of lines
        with open(FindFilePath('modules.txt')) as f:
            Courses_count = sum(1 for _ in f if _.rstrip('\n'))

        course_code, course_name, course_credit = input("""
                                                        
        Please insert course code, name and credit respectively.
        Must be seperated by spaces : 
        """).split()

        #Putting those bullet point number thingmagiggy
        if Courses_count == 0:
            append_file(FindFilePath('modules.txt'), f"{course_code},{course_name},{course_credit}")
        else:
            append_file(FindFilePath('modules.txt'), f"{course_code},{course_name},{course_credit}")


    #If value put is invalid
    except ValueError:
        print("\t\tInvalid input format. Please put spaces and try again.")
        add_course()

    #any error occurred another than ValueError
    except:
        print("An error occured.. Please try again.")
        add_course()

#remove courses
def remove_course():
    try:
        course_removal = input("""
                               
        Please input the course ID you want to remove: 
        """)
        with open(FindFilePath('modules.txt'),"r+") as f:
            new_f = f.readlines()
            f.seek(0)
            for line in new_f:
                if course_removal not in line:
                    f.write(line)
            f.truncate()
            

    #If value put is invalid
    except ValueError:
        print("\t\tInvalid input. Please try again.")
        remove_course()

    #any error occurred another than ValueError
    except:
        print("An error occured.. Please try again.")
        remove_course()

def update_course():
    try:
        course_query = input("""    
        Please input the course info you want to update.
        Include name, code and credit seperated by spaces: 
        """)
        course_code, course_name, course_credit= input("""
        Please insert the new student info respectively to replace.
        Must be seperated by spaces, okay!:
        """).split()
        with open(FindFilePath('modules.txt'),"r+") as f:
            new_f = f.read()
            f.seek(0)
            f.truncate()
            f.write(new_f.replace(course_query,f'{course_code},{course_name},{course_credit}'))

    #If value put is invalid
    except ValueError:
        print("\t\tInvalid input. Please try again.")
        update_course()

    #any error occurred another than ValueError
    except:
        print("An error occured.. Please try again.")
        update_course()

## STUDENTS ##
def student_mainmenu():
    try:
        choice = int(input("""\n
        Do you like to add a new student or remove existing students?
        [1] Add
        [2] Remove
        [3] Update
        [0] Back to main menu
        
        Please input option:
        """))
        if choice == 1:
            add_student()
        elif choice == 2:
            remove_student()
        elif choice == 3:
            update_student()
        elif choice == 0:
            return
        else:
            ValueError
    except ValueError:
        print("Invalid input. Try again..")
        student_mainmenu()
    except:
        print("An error have occurred..")

## Add Students function
def add_student():
    try:
        #Determine the amount of students based on number of lines
        with open(FindFilePath('students.txt')) as f:
            Stud_count = sum(1 for _ in f if _.rstrip('\n'))

        #Input data
        student_id, name, student_class, department = input("""
                                                            
        Please insert student ID, student name, student class and department 
        respectively.
        Must be seperated by spaces :
        """).split()

        #Putting those bullet point number thingmagiggy
        if Stud_count == 1:
            append_file(FindFilePath('students.txt'), f"{student_id}, {name}, {student_class}, {department}")
        else:
            append_file(FindFilePath('students.txt'), f"{student_id}, {name}, {student_class}, {department}")

    except ValueError:
        print("\t\tInvalid input format. Please put spaces and try again.")
        add_student()

    except:
        print("An error occured.. Please try again.")
        add_student()

##Remove Student
def remove_student():
    try:
        student_removal = input("""
                                
        Please input the student ID you want to remove: 
        """)
        with open(FindFilePath('students.txt'),"r+") as f:
            new_f = f.readlines()
            f.seek(0)
            for line in new_f:
                if student_removal not in line:
                    f.write(line)
            f.truncate()

    #If value put is invalid
    except ValueError:
        print("\t\tInvalid input. Please try again.")
        remove_student()

    #any error occurred another than ValueError
    except:
        print("An error occured.. Please try again.")
        remove_student()

def update_student():
    try:
        student_query = input("""    
        Please input the student info you want to update.
        Include name, department, etc seperated by spaces: 
        """)
        student_id, name, student_class, department = input("""
        Please insert the new student info respectively to replace.
        Must be seperated by spaces, okay!:
        """).split()
        with open(FindFilePath('students.txt'),"r+") as f:
            new_f = f.read()
            f.seek(0)
            f.truncate()
            f.write(new_f.replace(student_query,f'{student_id}, {name}, {student_class}, {department}'))

    #If value put is invalid
    except ValueError:
        print("\t\tInvalid input. Please try again.")
        update_student()

    #any error occurred another than ValueError
    except:
        print("An error occured.. Please try again.")
        update_student()

## LECTURERS ##
def lecturer_mainmenu():
    try:
        choice = int(input("""\n
        Do you like to add a new lecturer or remove existing lecturers??
        [1] Add
        [2] Remove
        [3] Update
        [0] Back to main menu
        
        Please input option:
        """))
        if choice == 1:
            add_lecturer()
        elif choice == 2:
            remove_lecturer()
        elif choice == 3:
            update_lecturer()
        elif choice == 0:
            return
        else:
            ValueError
    except ValueError:
        print("Invalid input. Try again..")
        lecturer_mainmenu()
    except:
        print("An error have occurred..")

## Add lecturer function
def add_lecturer():
    try:
        #Determine the amount of lecturers based on number of lines
        with open(FindFilePath('lecturer.txt')) as f:
            Lec_count = sum(1 for _ in f if _.rstrip('\n'))

        lec_id, modulecode = input("""
                                     
        Please insert lecturer id and module code respectively.
        Must be seperated by spaces :
        """).split()

        #Putting those bullet point number thingmagiggy
        if Lec_count == 0:
            append_file(FindFilePath('lecturer.txt'), f"{lec_id},{modulecode}")
        else:
            append_file(FindFilePath('lecturer.txt'), f"{lec_id},{modulecode}")

    except ValueError:
        print("\t\tInvalid input format. Please put spaces and try again.")
        add_lecturer()

    except:
        print("An error occured.. Please try again.")
        add_lecturer()    

##Remove Lecturer
def remove_lecturer():
    try:
        lecturer_removal = input("""    
        Please input the lecturer ID you want to remove: 
        """)
        with open(FindFilePath('lecturer.txt'),"r+") as f:
            new_f = f.readlines()
            f.seek(0)
            for line in new_f:
                if lecturer_removal not in line:
                    f.write(line)
            f.truncate()

    #If value put is invalid
    except ValueError:
        print("\t\tInvalid input. Please try again.")
        remove_lecturer()

    #any error occurred another than ValueError
    except:
        print("An error occured.. Please try again.")
        remove_lecturer()

def update_lecturer():
    try:
        lecturer_query = input("""    
        Please input the lecturer info you want to update.
        Include ID and module code, seperated by spaces: 
        """)
        id, modulecode = input("""
        Please insert the new lecturer info respectively to replace.
        Must be seperated by spaces:
        """).split()
        with open(FindFilePath('lecturer.txt'),"r+") as f:
            new_f = f.read()
            f.seek(0)
            f.truncate()
            f.write(new_f.replace(lecturer_query,f'{id},{modulecode}'))

    #If value put is invalid
    except ValueError:
        print("\t\tInvalid input. Please try again.")
        update_lecturer()

    #any error occurred another than ValueError
    except:
        print("An error occured.. Please try again.")
        update_lecturer()

## REPORT ##
## producing a simple report
def report():
    #Total Students 
    with open(FindFilePath('students.txt')) as f:
        Stud_count = sum(1 for _ in f if _.rstrip('\n'))

    #Active Courses
    with open(FindFilePath('modules.txt')) as f:
        Courses_count = sum(1 for _ in f if _.rstrip('\n'))

    #Faculty
    with open(FindFilePath('lecturer.txt')) as f:
        Lec_count = sum(1 for _ in f if _.rstrip('\n'))

        print(f"""
        [REPORT]
        Total student = {Stud_count}
        Active courses = {Courses_count}
        Faculty = {Lec_count}
        """)

##View ALL DATA##
def viewalldata():
    #Total Students 
    with open(FindFilePath('students.txt'), 'r') as f:
        #Read the lines of the file
        f_l = f.readlines()
        Bil = 0

        print("\nSTUDENTS")
        #print each lines
        for line in f_l:
            Bil = Bil + 1
            print(f"{Bil}. {line.strip()}")

    #Active Courses
    with open(FindFilePath('modules.txt'), 'r') as f:
        #Read the lines of the file
        f_l = f.readlines()
        Bil = 0

        print("\nCOURSES")
        #print each lines
        for line in f_l:
            Bil = Bil + 1
            print(f"{Bil}. {line.strip()}")

    #Faculty
    with open(FindFilePath('lecturer.txt'), 'r') as f:
        #Read the lines of the file
        f_l = f.readlines()
        Bil = 0

        if f_l:
            print("\nLECTURERS")
            #print each lines
            for line in f_l:
                Bil = Bil + 1
                print(f"{Bil}. {line.strip()}")
# ------ End Of Admin Functions ---------

# ------ Lecturer Functions ---------
#View the modules assigned to each lecturer
def viewmodlect():
    #while True:
        try:
            filename = "Lecturer.txt"
            with open(FindFilePath(filename),'r') as lectview:
                display = lectview.readlines()

                for line in display:
                    print(line)
            #break

        except:
            print("Error occurred somewhere. Please make sure you entered the correct input :)")

#Add or update student grades for a specific module
def recordgrades():
    #while True:
        try:
            data = [['StudentID', 'Module Code', 'Grade']]
            filename = 'grades.txt'
            with open(FindFilePath(filename), 'r') as file:
                lists =[]
                for line in file:
                    line = line.strip().split(',')
                    lists.append(line)
                print("Please enter the StudentID(eg: TP123456)")
                student_idinput = input('>')
                print("Please enter the module code")
                moduleinput = input(">")
                print("Please enter the grade")
                gradeinput = input(">")
                header = lists[0]
                studentdata = lists[1:]

                student_existed = False
                for i in range(len(studentdata)):
                    if studentdata[i][0] == student_idinput and studentdata[i][1] == moduleinput:
                        studentdata[i][2] = gradeinput
                        student_existed = True

                if student_existed == False:
                    new_data = [student_idinput, moduleinput, gradeinput]
                    lists.append(new_data)


            with open(FindFilePath(filename), 'w') as file:
                for i in lists:
                    file.write(','.join(i) + '\n')

            #break
        except:
            print("Please check with the administrator what went wrong.")



#Display the list of students enrolled in each assigned module
def viewstudent():
    #while True:
        try:
            filename = 'enrollments.txt'
            with open(FindFilePath(filename),'r') as lectview:
                display = lectview.readlines()
                for line in display:
                    print(line.strip())
            #break
        except:
            print("Error occurred somewhere. Please make sure you entered the correct input :)")

#Mark attendance for students
def attendance():
    #while True:
        try:
            print("Enter the StudentID")
            student_id = input(">")
            print("Enter the module code")
            module = input(">")
            print("What is the date today?(YYYY-MM-DD)")
            tarikh = input(">")
            print("Is the student present or absent? Enter 1 if present and 0 if absent")
            confirmation=int(input(">"))
            filename = 'attds.csv'
            if confirmation==1:
                status = 'Present'
                new_data = [[student_id, module, tarikh, status]]
                with open(FindFilePath(filename),'a') as file:
                    for line in new_data:
                        file.write(', '.join(line) + '\n')
                    print("You have successfully entered the attendance. :)")
                #break

            elif confirmation==0:
                status = 'Absent'
                new_data = [[student_id, module, tarikh, status]]
                with open(FindFilePath(filename),'a') as file:
                    for line in new_data:
                        file.write(', '.join(line) + '\n')
                    print("You have successfully entered the attendance. Someone skipped their class :|")
                #break

            else:
                print("That is cap. You didn't follow what I said, so prepare to get bongus\n")

        except ValueError:
            print("You didn't enter the correct value\n")

#Counting attendance percentage
def attdspercentage(): #this is for calculating the percentage of the student's attendance
    filename = 'attds.csv'
    acount=0
    mcount=0
    print("Please enter StudentID")
    tpnumber = input('>')
    #while True:
    try:
        with open(FindFilePath(filename),'r') as file:
            perc = file.readlines()
            statuscheck = []
            for line in perc:
                line = line.strip().split(', ')
                statuscheck.append(line)
                for i in range(len(statuscheck)):
                    tpnumbercheck = statuscheck[i][0]
                    status = statuscheck[i][3]
                    if tpnumbercheck == tpnumber:
                        mcount += 1
                        if status == 'Present': #to get the total modules the student should have attended
                            acount += 1

        if mcount > 0:
            studpercentage = acount/mcount * 100
            print(f"Your attendance percentage is {studpercentage}%")
        else:
            print("No records ever been recorded '-'")

    except:
            print("Your data doesn't exist. Please check your input again.")
            

#Access grades for students in each of the lecturer's modules.
def viewgradelect():
    #while True:
        try:
            filename = 'grades.txt'
            with open(FindFilePath(filename),'r') as lectview:
                display = lectview.readlines()
                for line in display:
                    print(line.strip())
            #break

        except:
            print("Error occurred somewhere. Please make sure you entered the correct input :)")

# ------ End Of Lecturer Functions ---------

# ------ Registrar Functions ---------
def read_file(file_path):
    try:
        with open(FindFilePath(file_path), "r") as file:
            return [line.strip() for line in file]
    except FileNotFoundError:
        return []

def write_file(file_path, data):
    with open(FindFilePath(file_path), "w") as file:
        file.write("\n".join(data) + "\n")

def append_file(file_path, line):
    with open(FindFilePath(file_path), "a") as file:
        file.write(line + "\n")

def get_record(file_path, key):
    records = read_file(file_path)
    for record in records:
        if record.startswith(key):
            return record
    return None

def validate_student_id(student_id):
    while len(student_id) != 8:
        print("Student ID must be exactly 8 characters long.")
        student_id = input("Enter student ID (8 characters): ")
    return student_id

def register_student():
    student_id = validate_student_id(input("Enter student ID (8 characters): "))
    if get_record(STUDENTS_FILE, student_id):
        print("Student already exists.")
    else:
        name = input("Enter student name: ")
        classz = input("Enter class: ")
        program = input("Enter program: ")
        append_file(STUDENTS_FILE, f"{student_id}, {name}, {classz}, {program}")
        print("Student registered.")

def update_student():
    student_id = validate_student_id(input("Enter student ID to update: "))
    students = read_file(STUDENTS_FILE)
    updated = []
    for student in students:
        if student.startswith(student_id):
            name = input("New name (leave blank to keep current): ")
            classz = input("New class (leave blank to keep current): ")
            program = input("New program (leave blank to keep current): ")
            parts = student.split(",")
            updated.append(f"{student_id}, {name or parts[1]}, {classz or parts[2]}, {program or parts[3]}")
        else:
            updated.append(student)
    write_file(STUDENTS_FILE, updated)
    print("Student record updated.")

def manage_enrollment():
    student_id = validate_student_id(input("Enter student ID: "))
    module = input("Enter module: ")
    enrollments = read_file(ENROLLMENTS_FILE)
    if f"{student_id}, {module}" in enrollments:
        print("Student already enrolled.")
    else:
        append_file(ENROLLMENTS_FILE, f"{student_id}, {module}")
        print("Enrollment updated.")

def issue_transcript():
    student_id = validate_student_id(input("Enter student ID: "))
    student = get_record(STUDENTS_FILE, student_id)
    if not student:
        print("Student not found.")
        return
    enrollments = [line.split(",")[1] for line in read_file(ENROLLMENTS_FILE) if line.startswith(student_id)]
    transcript = f"Transcript for {student.split(',')[1]}:\n" + "\n".join(enrollments)
    print(transcript)
    #append_file(TRANSCRIPT_FILE, transcript)

def record_feedback():
    student_id = validate_student_id(input("Enter student ID: "))
    feedback = input("Enter feedback: ")
    append_file(FEEDBACK_FILE, f"{student_id},{feedback}")
    print("Feedback recorded.")

def view_feedback():
    student_id = validate_student_id(input("Enter student ID: "))
    feedbacks = [line.split(",", 1)[1] for line in read_file(FEEDBACK_FILE) if line.startswith(student_id)]
    if feedbacks:
        print("\n".join(feedbacks))
    else:
        print("No feedback found.")

def view_student_information():
    student_id = validate_student_id(input("Enter student ID to view: "))
    student = get_record(STUDENTS_FILE, student_id)
    if student:
        parts = student.split(",")
        print(f"Student ID: {parts[0]}\nName: {parts[1]}\nProgram: {parts[2]}")
    else:
        print("Student not found.")

def view_module_students():
    module = input("Enter module name: ")
    enrollments = read_file(ENROLLMENTS_FILE)
    if not any(module in line for line in enrollments):
        print("Module does not exist or has no enrollments.")
        return
    students = [line.split(",")[0] for line in enrollments if line.split(",")[1] == module]
    if students:
        print(f"Students enrolled in {module}:")
        for student_id in students:
            student = get_record(STUDENTS_FILE, student_id)
            if student:
                print(f"- {student.split(',')[1]} (ID: {student_id})")
    else:
        print("No students found for this module.")
# ------ End Of Registrar Functions ---------

# ------ Bursary Functions ---------
# Function to load student tuition records from text file
def load_tuition_records(tuition_file):
    student_records = {}
    try:
        with open(FindFilePath(tuition_file), 'r') as file:
            for line in file:
                # Skip header or blank lines
                if line.strip().startswith("Student ID") or not line.strip():
                    continue

                # Split the line into parts assuming comma separation
                parts = line.strip().split(',')

                # Validate the line has the required fields
                if len(parts) == 5:
                    student_id = parts[0]
                    name = parts[1].replace("_", " ")  # Replace underscores with spaces
                    tuition_fee = float(parts[2])
                    paid_amount = float(parts[3])
                    payment_history = eval(parts[4]) if parts[4].startswith("[") else []

                    # Add the student record to the dictionary
                    student_records[student_id] = {
                        "name": name,
                        "tuition_fee": tuition_fee,
                        "paid_amount": paid_amount,
                        "payment_history": payment_history,
                    }
                else:
                    print(f"Skipping invalid record: {line}")
    except FileNotFoundError:
        print(f"File {tuition_file} not found. Starting with an empty tuition record.")
    except Exception as e:
        print(f"An error occurred while loading tuition records: {e}")
    return student_records

# Function to save student tuition records to text file
def save_tuition_records(tuition_file, student_records):
    try:
        with open(FindFilePath(tuition_file), 'a') as file:
            # Write the header row
            #file.write("Student ID,Name,Tuition Fee,Paid Amount,Payment History\n")
            
            # Write each student's record
            for student_id, record in student_records.items():
                line = f"{student_id},{record['name']},{record['tuition_fee']:.2f},{record['paid_amount']:.2f},{record['payment_history']}\n"
                file.write(line)
        print(f"Tuition records successfully saved to {tuition_file}.")
    except Exception as e:
        print(f"An error occurred while saving tuition records: {e}")

# Function to record tuition fees
def record_tuition(student_id, name, tuition_fee, student_records):
    student_records[student_id] = {
        "name": name,
        "tuition_fee": tuition_fee,
        "paid_amount": 0,
        "payment_history": []
    }
    print(f"Tuition fees recorded for {name} (ID: {student_id}).")

# Function to view outstanding fees
def view_outstanding_fees(tuition_file, student_id):
    try:
        with open(FindFilePath(tuition_file), 'r') as file:
            for line in file:
                parts = line.strip().split(',', maxsplit=4)
                if len(parts) == 5 and parts[0] == student_id:
                    name = parts[1]
                    tuition_fee = float(parts[2])
                    paid_amount = float(parts[3])
                    outstanding = tuition_fee - paid_amount
                    print(f"Outstanding Fees for {name} (ID: {student_id}): {outstanding:.2f}")
                    return

        print(f"No record found for Student ID: {student_id}.")
    except Exception as e:
        print(f"An error occurred while viewing outstanding fees: {e}")

# Function to update payment records
def update_payment(tuition_file, student_id, amount):
    updated = False
    try:
        with open(FindFilePath(tuition_file), 'r') as file:
            lines = file.readlines()

        with open(FindFilePath(tuition_file), 'w') as file:
            for line in lines:
                parts = line.strip().split(',', maxsplit=4)
                if len(parts) == 5 and parts[0] == student_id:
                    name = parts[1]
                    tuition_fee = float(parts[2])
                    paid_amount = float(parts[3]) + amount  # Update paid amount
                    payment_history = eval(parts[4]) if parts[4].startswith("[") else []
                    
                    # Add new payment entry to history
                    payment_entry = {"date": datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S"), "amount": amount}
                    payment_history.append(payment_entry)

                    # Write the updated record to file
                    file.write(f"{student_id},{name},{tuition_fee:.2f},{paid_amount:.2f},{payment_history}\n")
                    updated = True
                else:
                    file.write(line)

        if updated:
            print(f"Payment of {amount:.2f} recorded for {student_id}.")
        else:
            print(f"Student ID {student_id} not found.")
    except Exception as e:
        print(f"An error occurred while updating payment: {e}")

# Function to issue fee receipts
def issue_receipt(tuition_file, student_id):
    try:
        with open(FindFilePath(tuition_file), 'r') as file:
            for line in file:
                parts = line.strip().split(',', maxsplit=4)
                if len(parts) == 5 and parts[0] == student_id:
                    name = parts[1]
                    tuition_fee = float(parts[2])
                    paid_amount = float(parts[3])
                    outstanding = tuition_fee - paid_amount

                    receipt = f"""
                    -------------------------------
                    Tuition Fee Receipt
                    -------------------------------
                    Student ID: {student_id}
                    Name: {name}
                    Total Tuition Fee: {tuition_fee:.2f}
                    Paid Amount: {paid_amount:.2f}
                    Outstanding Amount: {outstanding:.2f}
                    Date: {datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")}
                    -------------------------------
                    """

                    # Save the receipt to a file
                    with open(FindFilePath("fee_receipts.txt"), "a") as receipt_file:
                        receipt_file.write(receipt + "\n")

                    print(f"Receipt for Student ID {student_id} has been issued and saved.")
                    return

        print(f"No record found for Student ID: {student_id}.")
    except Exception as e:
        print(f"An error occurred while issuing the receipt: {e}")

# Function to view financial summary
def view_financial_summary(tuition_file):
    try:
        with open(FindFilePath(tuition_file), 'r') as file:
            print("\n--- Financial Summary ---")
            for line in file:
                parts = line.strip().split(',', maxsplit=4)
                if len(parts) == 5:
                    student_id = parts[0]
                    name = parts[1]
                    tuition_fee = float(parts[2])
                    paid_amount = float(parts[3])
                    outstanding = tuition_fee - paid_amount
                    print(f"Student ID: {student_id}")
                    print(f"Name: {name}")
                    print(f"Total Tuition Fee: {tuition_fee:.2f}")
                    print(f"Paid Amount: {paid_amount:.2f}")
                    print(f"Outstanding Amount: {outstanding:.2f}")
                    print("-------------------------")
    except Exception as e:
        print(f"An error occurred while viewing financial summary: {e}")

# ------ End Of Bursary Functions ---------

# ------ Student Functions ---------
def load_modules(mode):
    try:
        if mode == "full":
            with open(FindFilePath(MODULES_FILE), "r") as file:
                return [line.strip() for line in file if line.startswith("CS")]  #Ensure no empty lines
        elif mode == "seperate":
            with open(FindFilePath(MODULES_FILE), "r") as file:
                f_read = file.read()
                return f_read.replace(',',' ').split()

    except FileNotFoundError:
        print("The MODULES_FILE does not exist.")
        return []

#Load enrollments for a specific student.
def load_enrollment(student_id):
    try:
        with open(FindFilePath(ENROLLMENTS_FILE), "r") as file:
            return [line.strip() for line in file if line.startswith(student_id)]
    except FileNotFoundError:
        print("The ENROLLMENTS_FILE does not exist.")
        return []

#Get the student's name based on their ID.
def get_student_name(student_id):
    try:
        with open(FindFilePath(STUDENTS_FILE), "r") as file:
            for line in file:
                stored_id, name , classs , department = line.strip().split(",")
                if stored_id == student_id:
                    return name
    except FileNotFoundError:
        print("The STUDENT_FILE does not exist.")
    return None

#Enroll students in their desired module.
def enroll_in_module(student_id, module):
    try:
        available_modules = load_modules("seperate")
        if module not in available_modules:
            print(f"The module '{module}' is non-existent. Please make sure the module you entered is right :3!")
            return

        with open(FindFilePath(ENROLLMENTS_FILE), "a") as file:
            student_name = get_student_name(student_id)
            if student_name:
                file.write(f"{student_id}, {module}\n")  # Store student ID, name, and module
                print(f"You have successfully registered for {module}. Have fun and good luck studying!")
            else:
                print("Student ID not found. You are not able to be enrolled. Please try again\n.")
    except FileNotFoundError:
        print("The ENROLLMENTS_FILE does not exist.")

#Unenroll students from the selected module.
def unenroll_from_module(student_id, module):
    try:
        enrollments = load_enrollment(student_id)
        updated_enrollments = [enrollment for enrollment in enrollments if enrollment.split(",")[1].strip() != module]
        print(updated_enrollments)

        with open(FindFilePath(ENROLLMENTS_FILE), "a") as file:
            for enrollment in updated_enrollments:
                file.write(enrollment + "\n")
        print(f"You have successfully unregistered from {module}. Hope you had fun studying {module}! Good luck on your journey\n")
    except FileNotFoundError:
        print("The enrollments.txt file does not exist.")

#View students' grades.
def view_grades(student_id):
    try:
        with open(FindFilePath(GRADES_FILE), "r") as file:
            found = False
            student_name = get_student_name(student_id)
            print(f"Grades for Student ID: {student_id} ({student_name})")
            for line in file:
                _, module_code, grade = line.strip().split(",")
                if student_id in line:
                    print(f"{module_code}, {grade}")
                    found = True
            if not found:
                print("No grades were found for this student.")
    except FileNotFoundError:
        print("Grades file does not exist.")

#Access students attendance records.
def access_attendance_records(student_id):
    try:
        with open(FindFilePath(ATTENDANCE_FILE), "r") as file:
            found = False
            student_name = get_student_name(student_id)
            print(f"\nAttendance records for Student ID: {student_id} ({student_name})")
            for line in file:
                if line.startswith(student_id):
                    print(line.strip())
                    found = True
            if not found:
                print(f"No attendance records found for student ID: {student_id}")
    except FileNotFoundError:
        print("Attendance record does not exist.")

#View all modules a student is currently enrolled in.
def view_enrollments(student_id):
    enrollments = load_enrollment(student_id)
    if enrollments:
        print(f"Modules enrolled by Student ID: {student_id} ({get_student_name(student_id)})")
        for enrollment in enrollments:
            _,module = enrollment.split(",")
            print(module.strip())
    else:
        print(f"No enrollments found for Student ID: {student_id}.")
# ------ End Of Student Functions ---------

# ------ Main Menu Functions ---------
def load_users(USER_FILE):
    users = {}
    admins = []
    try:
        with open(FindFilePath(USER_FILE), 'r') as file:
            # Read each line in the file
            for line in file:
                # Skip empty lines
                if line.strip():
                    # Split the line into parts
                    parts = line.strip().split(',')
                    if len(parts) == 3:  # Ensure the line has all required fields
                        username, password, role = parts
                        users[username] = password
                        if role == 'admin':
                            admins.append(username)
                    else:
                        print(f"Skipping invalid user record: {line}")
    except FileNotFoundError:
        print(f"File {USER_FILE} not found. Starting with an empty user database.")
    except Exception as e:
        print(f"An error occurred while loading users: {e}")
    return users, admins

def save_users(users, admins, filename):
    try:
        with open(FindFilePath(filename), 'w') as file:
            # Write the header line manually
            file.write("username,password,role\n")
            
            # Write each user entry to the file
            for username, password in users.items():
                role = 'admin' if username in admins else 'user'
                file.write(f"{username},{password},{role}\n")
    except Exception as e:
        print(f"An error occurred while saving users: {e}")

def logreq(users):
    while True:
        choice = input("""
        Welcome to MyUniSpace!
        Please log in or register to continue:
        
        1. Register
        2. Login
        3. Exit

        Choose an option: """).strip()

        if choice == '1':
            register(users)
        elif choice == '2':
            username = login(users)
            if username:
                return username  # Login successful
        elif choice == '3':
            print("Exiting.....")
            exit()
        else:
            print("Invalid choice. Please try again.")

def menu(users, admins, current_user, filename):
    while True:
        try:
            print(f"\nWelcome, {current_user}!")
            menu_choice = int(input("""
            Main Menu:
            1. Administration
            2. Staff Portal
            3. Registrar Office
            4. Bursary Office
            5. Students Portal
            6. Log Out
            7. Exit

            Enter your choice: """))
        except ValueError:
            print("Error occurred. Please input a valid number.")
            continue

        match menu_choice:
            case 1:
                if current_user in admins:
                    admin()
                else:
                    print("Access denied. You are not authorized to access the Administration menu.")
            case 2:
                staff()
            case 3:
                registrar()
            case 4:
                bursary()
            case 5:
                student()
            case 6:
                print("Logging out...")
                return  # Return to the login menu
            case 7:
                save_users(users, admins, filename)
                print("Exiting......")
                exit()
            case default:
                print("Invalid choice. Please try again.")

def register(users):
    print("\n -Register- ")
    username = input("Enter a username: ").strip()
    if username in users:
        print("Username already exists. Please try another one.")
        return
    password = input("Enter a password: ").strip()
    role = input("Enter role (admin/user): ").strip().lower()

    if role == 'admin':
        admins.append(username)

    users[username] = password
    print("Registration completed successfully!")

def login(users):
    print("\n -Login- ")
    username = input("Enter your username: ").strip()
    password = input("Enter your password: ").strip()
    if users.get(username) == password:
        print(f"Welcome, {username}! You are now logged in.")
        return username
    else:
        print("Invalid username or password. Please try again.")
        return None

def admin():
    #Admin File Startup, making sure the text file exist, else create
    FirstTimeStart()

    while True:
     #main menu
        print("""
        -[UMS ADMINISTRATOR MENU]-
            [1]Add/Remove Courses
            [2]Add/Remove Students
            [3]Add/Remove Lecturers
            [4]Generate Report
            [5]View All Data
            [6]Terminate/Exit
            """)
        num = int(input("Please input option: "))

        if num == 1:
            course_mainmenu()
        elif num == 2:
            student_mainmenu()
        elif num == 3:
            lecturer_mainmenu()
        elif num == 4:
            report()
        elif num == 5:
            viewalldata()
        elif num == 6:
            print("Thank you and have a nice day.")
            break
        else:
            print("Invalid option")

    
def staff():
    while True:
        stamenu = input("""
        -Staff Portal-
    Welcome to the Staff Portal!
        
        1. View Student List For Each Assigned Module
        2. Record Grades
        3. Mark Attendace
        4. View Attendance Percentage
        5. View Student Grades
        6. Back

        Choose an option: """).strip()

        if stamenu == "1":
           viewstudent()
        elif stamenu == "2":
            recordgrades()
        elif stamenu == "3":
            attendance()
        elif stamenu == "4":
            attdspercentage()
        elif stamenu == "5":
            viewgradelect()
        elif stamenu == "6":
            break
        else:
            print("Invalid option.")

def registrar():
    while True:
        choice = input("""
        -Registrar Office-
    Welcome to the Registrar Office!
        
        1. Register New Students
        2. Update Student Records
        3. Manage Enrolments
        4. Issue Transcripts
        5. Record Feedback
        6. View Feedback               
        7. View Student Information
        8. View Students Module
        9. Back

        Choose an option: """).strip()

        if choice == "1":
            register_student()
        elif choice == "2":
            update_student()
        elif choice == "3":
            manage_enrollment()
        elif choice == "4":
            issue_transcript()
        elif choice == "5":
            record_feedback()
        elif choice == "6":
            view_feedback()
        elif choice == "7":
            view_student_information()
        elif choice == "8":
            view_module_students()
        elif choice == "9":
            break
        else:
            print("Invalid option.")

# Bursary Office Menu
def bursary():
    TUITION_FILE = "tuitionRec.txt"
    load_tuition_records(TUITION_FILE)  # Load tuition records from text file

    while True:
        burmenu = input("""
        -Bursary Office-
    Welcome to the Bursary Office!
        
        1. Record Tuition Fees
        2. View Outstanding Fees
        3. Update Payment Records
        4. Issue Fee Receipts
        5. View Financial Summary
        6. Back

        Choose an option: """).strip()

        if burmenu == '1':
            student_id = input("Enter Student ID: ").strip()
            name = input("Enter Student Name: ").strip()
            tuition_fee = float(input("Enter Tuition Fee: ").strip())
            record_tuition(student_id, name, tuition_fee, student_records)

        elif burmenu == '2':
            student_id = input("Enter Student ID: ").strip()
            view_outstanding_fees(TUITION_FILE, student_id)

        elif burmenu == '3':
            student_id = input("Enter Student ID: ").strip()
            amount = float(input("Enter Payment Amount: ").strip())
            update_payment(TUITION_FILE, student_id, amount)

        elif burmenu == '4':
            student_id = input("Enter Student ID: ").strip()
            issue_receipt(TUITION_FILE, student_id)

        elif burmenu == '5':
            view_financial_summary(TUITION_FILE)

        elif burmenu == '6':
            save_tuition_records(TUITION_FILE, student_records)  # Save tuition records before exiting
            print("Returning to the main menu...")
            break

        else:
            print("Invalid choice. Please try again.")


def student():
    student_id = input("Enter your Student ID: ")
    while len(student_id) < 8:
        print("Invalid input. Student ID must be 8 characters long. Please try again.... ")
        student_id = input("Please enter your Student ID again: ")
    print(f"Student ID accepted: {student_id}")

    while True:
        try:
            choice = int(input("""
1. View Available Modules
2. Enroll in Module
3. View Grades
4. Access Attendance Record
5. Unenroll from Module
6. View Enrollments
7. Exit
                     ~~~~~~~~~~PLEASE SELECT YOUR CHOICE OF MENU~~~~~~~~~~
Enter your desired menu number: """))

            if choice == 1:
                modules = load_modules("full")
                print("\nAvailable Modules:")
                if modules:
                    for module in modules:
                        print(module)
                else:
                    print("No modules available.")

            elif choice == 2:
                module = input("Enter the module codeyou desire to enroll in: ")
                enroll_in_module(student_id, module)

            elif choice == 3:
                print("\nYour Grades are:")
                view_grades(student_id)

            elif choice == 4:
                print("\nYour Attendance Records are:")
                access_attendance_records(student_id)

            elif choice == 5:
                module = input("Enter the module you would like to unenroll from: ")
                unenroll_from_module(student_id, module)

            elif choice == 6:
                view_enrollments(student_id)

            elif choice == 7:
                print("You have decided to exit. Exiting the program..... \nThank you!")
                break

        except TypeError:
            print("Invalid input! Please enter a number.")

# Main Execution
users, admins = load_users(USER_FILE)
while True:
    current_user = logreq(users)  # Ensure login first
    menu(users, admins, current_user, USER_FILE)  # Show main menu after login

