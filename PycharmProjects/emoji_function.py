def emoji_converter(message):
    emoji_mapping = {
        ":)": "🙂",
        ":(": "\x1F600"
    }
    result = ""
    for i in emotion.split(" "):
        result += emoji_mapping.get(i, i) + " "
    return result[0:-1]


emotion = input("> ")
print(emoji_converter(emotion))
