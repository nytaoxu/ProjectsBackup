class Point:
    def draw(self):
        print("draw")

    def move(self):
        print("move")

    def __init__(self, x, y):
        self.x = x
        self.y = y


p = Point(x=5, y=7)
p.draw()
p.move()
print(p.x, p.y)


class Person:
    def __init__(self, name):
        self.name = name

    def talk(self):
        print(f"{self.name} is talking...")


q = Person("Tao")
# q.talk()


class Engineer(Person):
    pass


t = Engineer("Tao")
t.talk()
