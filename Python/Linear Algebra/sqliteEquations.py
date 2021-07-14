import sqlite3 as lite
import sys
con = lite.connect('test.db')


def create_db():
    print ('Enter a new equtaion')
    print ('')
    firstequation = input('Enter first equation: ')
    secondequation = input('Enter second equation: ')
    with con:
        cur = con.cursor()
        cur.execute("DROP TABLE IF EXISTS MATHSEQUATIONS")
        cur.execute("CREATE TABLE MATHSEQUATIONS (Equation TEXT);")
        cur.execute("INSERT INTO MATHSEQUATIONS VALUES (?);", (firstequation,))
        cur.execute("INSERT INTO MATHSEQUATIONS VALUES (?);",
                    (secondequation,))

        # call commit on the connection...
        con.commit()


def fetch_data():
    with con:
        cur = con.cursor()

        print("Connected to SQLite")

        sqlite_select_query = """SELECT * from MATHSEQUATIONS"""
        cur.execute(sqlite_select_query)
        records = cur.fetchall()
        print("Total rows are:  ", len(records))
        print("Printing each row")
        print (records)
        for row in records:
            print("Equation: ", row[0])
            print("\n")
            print (row[0].lsplit("+"))
            print (row[0].rsplit("+"))

        cur.close()


createnewdb = input('Enter 1 to create new db: ')
if createnewdb == "1":
    create_db()
    fetch_data()
else:
    sys.exit(0)
