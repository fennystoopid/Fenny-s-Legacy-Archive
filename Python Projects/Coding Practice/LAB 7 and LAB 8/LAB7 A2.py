s = "I had a cat named amanda when I was little shit"
count = 0
i = 0

'''for i in s:
    if i == "a":
        count += 1'''

print(len(s))
while i < len(s):
    if s[i] == "a":
        count += 1
    i = i + 1

print(count)