def employee(name, salary = 9000):
    print(f"Employee name = {name}\nSalary = {salary}")

empName = input("Insert Name: ")
pay = input("Insert salary: ")

employee(empName,pay)

employee(empName)