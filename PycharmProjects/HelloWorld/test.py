import pymysql

# db = pymysql.connect("127.0.0.1", "root", "abc123", "corporation")

# connection = pymysql.connect(host='localhost',
#                              user='root',
#                              password='jobs2019',
#                              db='corporation',
#                              charset='utf8mb4',
#                              cursorclass=pymysql.cursors.DictCursor)

connection = pymysql.connect('localhost', 'root', 'jobs2019', 'company')

try:
    print("done")
    cursor = connection.cursor()
    sql = "select * from employees;"
    cursor.execute(sql)
    result = cursor.fetchall()
    print(f"result = {result}.")
    sql2 = "insert into employees values (130, 20170517);"
    cursor.execute(sql2)
    result = cursor.fetchall()
    print(f"result = {result}.")
    cursor.execute(sql)
    result = cursor.fetchall()
    print(f"result = {result}.")

except Exception as e:
    print("Error encountered.")
    print(e)
else:
    print("No errors encountered.")
finally:
    print("All done.")
    connection.close()
print("Program done.")
