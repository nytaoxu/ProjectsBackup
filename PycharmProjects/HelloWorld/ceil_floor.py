def my_floor(x):
    return int(x)


def my_ceil(x):
    y = int(x)
    if x - y > 0:
        return y + 1
    else:
        return y


print(int(my_ceil(1.0)))
print(int(my_floor(1.0)))

if .1 + .2 - .3 > 0:
    print("strange")

x, y = 5, 7
x, y = y, x
print(f"x = {x}, y = {y}")

name = input("Please enter your name: ")
if name == "Tao":
    print("That is a nice name")
elif name == "John Cleese" or name == "Michael Palin":
    print("You are lucky.")
else:
    print("You have a nice name.")

# output = (name == "Tao" ? "That is a nice name." : ((name == "John Cleese" or name == "Michael Palin") ? "You are lucky." : "You have a nice name."))

# name == "Tao" ? print("That is a nice name.") :
#         name == "John Cleese" or name == "Michael Palin" ? print("You are lucky.") :
#         print("You have a nice name.")

prices = [4.95, 9.95, 14.95, 19.95, 24.95]
for price in prices:
    print(f"The original price is {price}, the discount amount is {'{0:.2f}'.format(price * .6)}, and the new price is {'{0:.2f}'.format(price * .4)}.")


for i in range(1, 6):
    result = 1
    for j in range(i + 1):
        result *= i
    print(f"{i} {i + 1} {result}")


import random

secret_str = ""
secret_number = 0
for i in range(3):
    x = random.randint(0, 9)
    secret_str += str(x)
    secret_number = secret_number * 10 + x

number_str = input("Please enter your lottery number: ")
number = int(number_str)

award = 0

if secret_number == number:
    award = 10000
else:
    all_digit_match = True
    one_digit_match = False
    for i in number_str:
        c = secret_str.count(i)
        if c > 0:
            one_digit_match = True
        if number_str.count(i) != c:
            all_digit_match = False
        if all_digit_match == False and one_digit_match == True:
            break
    if all_digit_match:
        award = 3000
    else:
        if one_digit_match:
            award = 1000

print(f"The secret number is {secret_number}, and the guess is {number}.")

print(f"The award is {award}.")

# ----- problem 8

number_list = []
max_number = 0
max_number_occurrence = 0

while True:
    number = int(input("Please enter a number (enter 0 to finish): "))
    if number == 0:
        break
    if len(number_list) == 0:
        max_number = number
        max_number_occurrence = 1
    else:
        if max_number < number:
            max_number = number
            max_number_occurrence = 1
        elif max_number == number:
            max_number_occurrence += 1
    number_list.append(number)

print(f"The largest number is {max_number}")
print(f"The occurrence count of the largest number is {max_number_occurrence}")

# ----- problem 9

outcome = ""
for i in range(9):
    for j in range(9):
        if i + j >= 4 and j - i <= 4:
            outcome += "*"
        else:
            outcome += " "
    outcome += "\n"
print(outcome)
