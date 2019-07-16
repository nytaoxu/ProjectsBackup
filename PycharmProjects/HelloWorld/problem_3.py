
def calculate_score(word):
    dictionary = {
        1: 'aeilnorstu',
        2: 'dg',
        3: 'bcmp',
        4: 'fhvwy',
        5: 'k',
        8: 'jx',
        10: 'qz'
    }
    score = 0
    for i in word:
        # print(f"i = {i}")
        for k, v in dictionary.items():
            if i.lower() in [e.lower() for e in v]:
                score += k
    return score


# print(calculate_score('abc'))


def scrabble_game():
    # sum = 0
    # for i in dictionary.values():
    #     sum += len(i)
    # print(sum)
    while True:
        user_input = input("Enter a word: ")
        if user_input.strip() == "":
            break
        print(f"Output: {calculate_score(user_input)}")


scrabble_game()
