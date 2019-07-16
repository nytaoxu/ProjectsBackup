try:
    age = int(input("Age: "))
    income = 100000
    print(f"Your age is {age}.")
    print(f"The ratio is {income / age}.")
except ValueError:
    print("The age you entered is invalid.")
except ZeroDivisionError:
    print("age cannot be 0.")
