print("hello world")
print(__name__)

import pymysql;
db = pymysql.connect("localhost", "root", "jobs2019", "summitworks")
cursor = db.cursor()
sql = '''
show databases;
use summitworks;
show tables;
'''
cursor.execute(sql)
print(cursor.fetchall())
