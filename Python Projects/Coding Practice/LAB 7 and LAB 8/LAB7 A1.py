## SLICING CHECK
user_str = "Python Programming"

##first two character deleted
sub_str1 = user_str[2:]

##first one character deleted and end 4 characters deleted 
sub_str2 = user_str[1:4]

##
sub_str3 = user_str[1::2]

##
sub_str4 = user_str[:-2]

print(f"{sub_str1}\n{sub_str2}\n{sub_str3}\n{sub_str4}")

index = 0
print(f"{user_str[index]}\n{user_str[index + 2]}")


