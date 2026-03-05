import datetime

student_records = {}

# Function to load student tuition records from text file
def load_tuition_records(filename):
    try:
        with open(filename, 'r') as file:
            for row in filename:
                student_id = row['student_id']
                student_records[student_id] = {
                    "name": row['name'],
                    "tuition_fee": float(row['tuition_fee']),
                    "paid_amount": float(row['paid_amount']),
                    "payment_history": eval(row['payment_history'])
                }
    except FileNotFoundError:
        print(f"File {filename} not found. Starting with an empty tuition record.")

# Function to save student tuition records to text file
def save_tuition_records(filename):
    with open(filename,'w', newline='') as file:
        filename.write(file, fieldnames=['student_id', 'name', 'tuition_fee', 'paid_amount', 'payment_history'])
        filename.writeheader()
        for student_id, data in student_records.items():
            filename.writerow({
                "student_id": student_id,
                "name": data["name"],
                "tuition_fee": data["tuition_fee"],
                "paid_amount": data["paid_amount"],
                "payment_history": data["payment_history"]
            })

# Function to record tuition fees
def record_tuition(student_id, name, tuition_fee):
    student_records[student_id] = {
        "name": name,
        "tuition_fee": tuition_fee,
        "paid_amount": 0,
        "payment_history": []
    }
    print(f"Tuition fees recorded for {name} (ID: {student_id}).")

# Function to view outstanding fees
def view_outstanding_fees(student_id):
    if student_id in student_records:
        record = student_records[student_id]
        outstanding = record["tuition_fee"] - record["paid_amount"]
        print(f"Outstanding Fees for {record['name']} (ID: {student_id}): {outstanding}")
    else:
        print(f"No record found for Student ID: {student_id}.")

# Function to update payment records
def update_payment(student_id, amount):
    if student_id in student_records:
        record = student_records[student_id]
        record["paid_amount"] += amount
        record["payment_history"].append({
            "date": datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S"),
            "amount": amount
        })
        print(f"Payment of {amount} recorded for {record['name']} (ID: {student_id}).")
    else:
        print(f"No record found for Student ID: {student_id}.")

# Function to issue fee receipts
def issue_receipt(student_id):
    with open ('text.txt', 'r') as file: 
        filecontent = file.readlines()
        print(filecontent)
        if student_id in student_records:
            record = student_records[student_id]
            print("\n--- Fee Receipt ---")
            print(f"Student ID: {student_id}")
            print(f"Name: {record['name']}")
            print(f"Total Tuition Fee: {record['tuition_fee']}")
            print(f"Paid Amount: {record['paid_amount']}")
            print(f"Outstanding: {record['tuition_fee'] - record['paid_amount']}")
            print("-------------------\n")
        else:
            print(f"No record found for Student ID: {student_id}.")

# Function to view financial summary
def view_financial_summary():
    print("\n--- Financial Summary ---")
    for student_id, record in student_records.items():
        print(f"Student ID: {student_id}")
        print(f"Name: {record['name']}")
        print(f"Total Tuition Fee: {record['tuition_fee']}")
        print(f"Paid Amount: {record['paid_amount']}")
        print(f"Outstanding: {record['tuition_fee'] - record['paid_amount']}")
        print("-------------------------")
    print()

def load_users(filename):
    users = {}
    admins = []
    try:
        with open(filename,'r') as file:
            for row in filename:
                users[row['username']] = row['password']
                if row.get('role') == 'admin':
                    admins.append(row['username'])
    except FileNotFoundError:
        print(f"File {filename} not found. Starting with an empty user database.")
    return users, admins

def save_users(users, admins, filename):
    with open(filename,'w', newline='') as file:
        filename.write(file, fieldnames=['username', 'password', 'role'])
        filename.writeheader()
        for username, password in users.items():
            role = 'admin' if username in admins else 'user'
            filename.writerow({'username': username, 'password': password, 'role': role})

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
    while True:
        admenu = input("""
        -Administration Section-
    Welcome to the Administration Section!
        
        1. Add New Course
        2. Add/Remove Students
        3. Manage Lecturers
        4. Generate Report
        5. View All Data
        6. Back
                       
        Choose an option: """).strip()
    
def staff():
    while True:
        stamenu = input("""
        -Staff Portal-
    Welcome to the Staff Portal!
        
        1. View Assigned Modules
        2. Record Grades
        3. View Student List
        4. Track Attendance
        5. View Student Grades
        6. Back

        Choose an option: """).strip()

def registrar():
    while True:
        regmenu = input("""
        -Registrar Office-
    Welcome to the Registrar Office!
        
        1. Register New Students
        2. Update Student Records
        3. Manage Enrolments
        4. Issue Transcripts
        5. View Student Information
        6. Back

        Choose an option: """).strip()

# Bursary Office Menu
def bursary():
    tuition_file = "tuitionRec.txt"
    load_tuition_records(tuition_file)  # Load tuition records from CSV

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
            record_tuition(student_id, name, tuition_fee)

        elif burmenu == '2':
            student_id = input("Enter Student ID: ").strip()
            view_outstanding_fees(student_id)

        elif burmenu == '3':
            student_id = input("Enter Student ID: ").strip()
            amount = float(input("Enter Payment Amount: ").strip())
            update_payment(student_id, amount)

        elif burmenu == '4':
            student_id = input("Enter Student ID: ").strip()
            issue_receipt(student_id)

        elif burmenu == '5':
            view_financial_summary()

        elif burmenu == '6':
            save_tuition_records(tuition_file)  # Save tuition records before exiting
            print("Returning to the main menu...")
            break

        else:
            print("Invalid choice. Please try again.")

def student():
    while True:
        stumenu = input("""
        -Students Portal-
    Welcome to the Students Portal!
        
        1. View Available Modules
        2. Enrol in Module
        3. View Grades
        4. Access Attendance Record
        5. Unenroll from Module
        6. Back

        Choose an option: """).strip()

# Main Execution
filename = 'tuitionRec.txt'
users, admins = load_users(filename)


while True:
    current_user = logreq(users)  # Ensure login first
    menu(users, admins, current_user, filename)  # Show main menu after login