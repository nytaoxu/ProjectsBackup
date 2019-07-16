import random


def generate_random_number(a, b, n):
    result = []
    while len(result) < n:
        x = random.randint(a, b)
        if x not in result:
            result.append(x)
    return result


# print(generate_random_number(1, 15, 5))


def generate_bingo_number_list():
    keys = 'bingo'
    game = {}
    x = 1
    for i in keys:
        game[i.upper()] = generate_random_number(x, x + 14, 5)
        x += 15
    return game
    # bingo_game = dict()
    # bingo_game['B'] = generate_random_number(1, 15, 5)
    # bingo_game['I'] = generate_random_number(16, 30, 5)
    # bingo_game['N'] = generate_random_number(31, 45, 5)
    # bingo_game['G'] = generate_random_number(46, 60, 5)
    # bingo_game['O'] = generate_random_number(61, 75, 5)
    # return bingo_game


def display_bingo_game():
    bingo_game = generate_bingo_number_list()
    result = ""
    for i in bingo_game.keys():
        result += i.center(7, " ")
    result += "\n"
    for i in range(5):
        for j in bingo_game.keys():
            result += str(bingo_game[j][i]).center(7, " ")
        result += "\n"
    print(result)


display_bingo_game()
