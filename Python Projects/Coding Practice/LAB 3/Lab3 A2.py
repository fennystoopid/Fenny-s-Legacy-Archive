name, age = input("enter name and age: ").split()

print(f"Hi, {name}\nHow are u")

if int(age) <= 17:
    print("oh shit mb, u minor not old enough for alcohol")
else:
    print("okay u legal")
