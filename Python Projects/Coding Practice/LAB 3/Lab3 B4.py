basic = input("Insert ur basic salary, mortal:")

Grade_pay = pow(int(basic), 2)
DA = int(basic) * 0.7
HRA = int(basic) * 0.2

Salary = Grade_pay + DA + 200 + HRA

print(f"Your salary is {Salary}")
print("Salary = %2f"% Salary)
