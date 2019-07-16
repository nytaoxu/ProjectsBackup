phone = input("Phone: ")
dictionary = {
    "1": "One",
    "2": "Two",
    "3": "Three",
    "4": "Four",
    "5": "Five",
    "6": "Six",
    "7": "Seven",
    "8": "Eight",
    "9": "Nine"
}
str = ""
for i in phone:
    str += dictionary.get(i, "None") + " "
str = str[:-1]
print(str)
