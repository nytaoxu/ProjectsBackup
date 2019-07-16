import sqlite3

connection = sqlite3.connect("~/abc.db")
cursor = connection.cursor()
sql_string = '''
    create database summitworks;
'''
cursor.execute(sql_string)
