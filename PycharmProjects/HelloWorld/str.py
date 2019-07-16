# for i in range(7):
#     for j in range(13):
#         if (i + j) % 2 == 0:
#             print('x', end="")
#     print('\n')
#
# str1 = 'x'
# for i in range(7):
#     print(str1.center(13, " "))
#     str1 += " x"
#
#
# result = ""
# for i in range(7):
#     print(i, end="")
#     for j in range(13):
#         if (i + j >= 6) and (j - i <= 6) and (i + j) % 2 == 0:
#             # print('x', end='')
#             print(f"i = {i}, j = {j}.")
#             result += "x"
#         else:
#             # print(' ', end='')
#             result += " "
#     # print("\n")
#     result += "\n"
#
# print(result)
# print(len(result))
#


# outcome = ""
#
# for i in range(13):
#     for j in range(13):
#         if i > 6:
#             i = 12 - i
#             pass
#         sum = i + j
#         if sum % 2 == 0 and (j >= i and j + i <= 12 or j <= i and j + i >= 12):
#             outcome += str(sum // 2 + 1)
#         else:
#             outcome += " "
#     outcome += "\n"
#
# print(outcome)

# -----

result = ""
for i in range(7):
    result += i * " "
    for j in range(i + 1, 8):
        result += " " + str(j)
    result += i * " " + "\n"
for i in range(5, -1, -1):
    result += i * " "
    for j in range(i + 1, 8):
        result += " " + str(j)
    result += i * " " + "\n"
print(result)

from scipy import integrate

print(integrate.quad(lambda x: x**2, 0, 1))
