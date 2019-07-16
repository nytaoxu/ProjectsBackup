dictionary = {
    0: "zero",
    1: "one",
    2: "two",
    3: "three",
    4: "four",
    5: "five",
    6: "six",
    7: "seven",
    8: "eight",
    9: "nine",
    10: "ten",
    11: "eleven",
    12: "twelve",
    13: "thirteen",
    14: "fourteen",
    15: "fifteen",
    16: "sixteen",
    17: "seventeen",
    18: "eighteen",
    19: "nineteen",
    20: "twenty",
    30: "thirty",
    40: "forty",
    50: "fifty",
    60: "sixty",
    70: "seventy",
    80: "eighty",
    90: "ninety"
}


def digit_count(n):
    if n == 0:
        return 0
    digit = 0
    while n > 0:
        n = int(n / 10)
        digit += 1
    return digit


def find_digit(n, i):
    while i > 0:
        n = int(n / 10)
        i -= 1
    return n % 10


def letter_count(n):
    if n < 0:
        n = -n
    if n in dictionary.keys():
        return len(dictionary[n])
    digits = digit_count(n)
    leading_digit = 0
    if digits == 4:
        return 11  # One thousand
    elif digits == 3:
        leading_digit = find_digit(n, 2)
        return len(dictionary[leading_digit]) + 10 + letter_count(n - leading_digit * 100)
    elif digits == 2:
        # if n in dictionary.keys():
        #     return len(dictionary[n])
        leading_digit = find_digit(n, 1)
        return len(dictionary[leading_digit * 10]) + letter_count(n - leading_digit * 10)
    elif digits == 1:
        return len(dictionary[n])
    elif digits == 0:  # 0
        return 4
    else:
        pass


# print(find_digit(1234, 4))
# print(letter_count(14))
# print(letter_count(117))


def main():
    total = 0
    for i in range(1, 1001):
        total += letter_count(i)
    print(f"The total number of letters of all the numbers from 1 to 1000 (inclusive) would be {total}.")


main()
