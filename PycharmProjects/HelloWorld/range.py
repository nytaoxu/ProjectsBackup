for x in range(5):
    if x == 0 or x == 2:
        for y in range(5):
            print("x", end="")
        print()
    else:
        for y in range(2):
            print("x", end="")
        print()

print()

numbers = [5, 2, 5, 2, 2]
for i in numbers:
    print("x" * i)

print()

for i in numbers:
    s = ""
    j = 0
    while(j < i):
        s += "x"
        j += 1
    print(s)

print()

s = ""
for i in numbers:
    j = 0
    while(j < i):
        s += "x"
        j += 1
    s += "\n"
print(s)

# print("hello world")

for x_count in numbers:
    for j in range(x_count):
        print("x", end="")
    print()