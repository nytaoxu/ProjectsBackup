# import pymysql
#
# db = pymysql.connect("localhost", "root", "jobs2019", "summitworks")
# cursor = db.cursor()
# cursor.execute("select * from student;")
# print(cursor.fetchall())
# create_table = '''
#     create table xyz(
#         id int primary key
#     );
# '''
# drop_table = '''
#     drop table xyz;
# '''
# columns_of_table = '''
#     show columns from student;
# '''
# cursor.execute(columns_of_table)
# print(cursor.fetchall())
#
# cursor.execute('help "ascii"')
# print(cursor.fetchall())
#
# info = "*"
# result = ''
# for i in range(7):
#     result += ' '.join('*' * (i + 1)).center(55, ' ') + '\n'
#     info += "*"
# print(result)
#
# result = ''
# # n = 1
# for i in range(1, 8):
#     result += ' '.join(str(e) for e in list(range(i, 8))).center(13, ' ') + '\n'
#     # n += 1
# # n = 6
# for i in range(6, 0, -1):
#     result += ' '.join(str(e) for e in list(range(i, 8))).center(13, ' ') + '\n'
#     # n -= 1
# i = 1
# step = 1
# while i > 0:
#     result += ' '.join(str(e) for e in list(range(i, 8))).center(13, ' ') + '\n'
#     if i == 7:
#         step = -step
#     i += step
# print(result)
#
# sql = "show columns from student;"
# print(cursor.execute(sql))
# print(cursor.fetchall())
#
# sql = "select * from student where first_name='tao';"
# print(cursor.execute(sql))
# print(cursor.fetchall())
# list1 = [1, 2, 3]
# list2 = [6, 7, 8]
# # print(list1.append(list2))
# # print(list1)
# list1.extend(list2)
# print(list1)
# print(len(list1))
# # list1.append(1, 2, 3)
# print(list1)
# list1.append([1, 2, 3])
# print(list1)

list1 = [1, 2, 3]
list2 = [6, 7, 8]
list1.extend(list2)
list1.append(list2)
print(list1)
# print([].pop())
l = [1, 2, 3]
print(sorted(l, key=int, reverse=True))


class DivisionEven(Exception):
    pass


try:
    a, b = 7, 2
    c = a / b
    if a % b != 0:
        raise DivisionEven("hello world")
    else:
        print(f"c is {c}.")
except DivisionEven as de:
    print(f"Error found: {de}.")
else:
    print("No error found.")
finally:
    print("Congratulations!")

print("Program done!")

x = [str(i) for i in range(1, 6)]
result = ''
for j in range(len(x)):
    result += ' '.join(x) + '\n'
    e = x.pop()
    x.insert(0, e)
print(result)


def fun():
    return 1, 2


print(fun())
x = set()
x.add(1)
print(x)
# for k, v in enumerate(x):
#     v = 7
#     print(k, v)
# for k, v in enumerate(x):
#     print(k, v)
#
# list1 = [1, 2, 3]
# map1 = map(lambda x: x ** x, list1)
# print(list(map1))
print(x.pop())
print(x)

x = {0, 1}
y = {1, 2}
print(x | y)
print(x & y)
print(x - y)
print(y - x)
print(x ^ y)
print(len(x ^ x))
x = {}
y = dict()
z = set()
print(type(x), type(y), type(z))
print(int('0x11', 16))
