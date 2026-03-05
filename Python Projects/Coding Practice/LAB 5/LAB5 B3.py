import random

winnum = random.randrange(1,11,1)
attempt = 5
win = False

"""def WIN():
    print(f"\nYou successfully guessed the number in {5 - attempt} attempts!\nThe number is {winnum}!\nThanks for Playing!\n")

def LOSE():
    print(f"\nYou failed to guess the number and wasted all your attempts!\nThe number is {winnum}!\nThanks for Playing!\n")"""


print(f"--Number Guessing Game!--\nYou only have {attempt} attempts!")

"""while attempt != 0 and win == False:
    guess = int(input("\nGuess the number: "))
    attempt -= 1
    if guess == winnum:
        WIN()
        win = True
    elif guess < winnum:
        print(f"Too low! {attempt} attempts left!")
    elif guess > winnum:
        print(f"Too high! {attempt} attempts left!")
    
if attempt == 0:
    LOSE()"""

for i in range(1, attempt+1):
    try:
        guess = int(input(f"\nAttempt {i}, guess the number (1-10): "))
        if guess < 1 or guess > 10:
            print("Out of range!")
            continue
        elif guess < winnum:
            print(f"Too low! {i} attempts left!")
        elif guess > winnum:
            print(f"Too high! {i} attempts left!")
        else:
            print(f"\nYou successfully guessed the number in {i} attempts!\nThe number is {winnum}!\nThanks for Playing!\n")
            break
    except:
        print(f"\nYou failed to guess the number and wasted all your attempts!\nThe number is {winnum}!\nThanks for Playing!\n")
