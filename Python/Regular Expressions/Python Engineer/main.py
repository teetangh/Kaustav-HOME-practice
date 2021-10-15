import re

# Raw Strings
a = "\tHello"
b = r"\tHello"
print(a)  # Hello
print(b)  # \tHello


test_string = "123abc456789abc123ABC"

# finditer(), findall(), match(), search()
pattern = re.compile(r"abc")
matches = pattern.finditer(test_string)

# Shorter but not recommmended
# matches = re.finditer(r"abc", test_string)

for match in matches:
    print(match)

# findall()
matches = pattern.findall(test_string)
for match in matches:
    print(match)

# match()
match = pattern.match(test_string)
print(match)

pattern = re.compile(r"123")
match = pattern.match(test_string)
print(match)

# search()
pattern = re.compile(r"abc")
match = pattern.search(test_string)
print(match)


# group(), start(), end(), span()
pattern = re.compile(r"abc")
matches = pattern.finditer(test_string)

for match in matches:
    print(match.group(), match.span(), match.start(), match.end())


# Meta Characters

def printMatches(raw_string, test_string=test_string, ignore_case=False):
    print("------------------------------------------------")
    if ignore_case is False:
        pattern = re.compile(raw_string)
    else:
        pattern = re.compile(raw_string, re.I)

    matches = pattern.finditer(test_string)
    print("Finding ", pattern, "in test_string ", test_string)

    for match in matches:
        print(match.group(), match.span(), match.start(), match.end())


test_string = "123abc456789abc123ABC"
printMatches(r"^abc")
printMatches(r"abc")
printMatches(r"abc$")

test_string = "hello 123_ heyho hohey"
printMatches(r'\d')
printMatches(r'\D')
printMatches(r'\s')
printMatches(r'\S')
printMatches(r'\w')
printMatches(r'\W')
printMatches(r'\bhello')
printMatches(r'\bhey')  # beginning of a block
printMatches(r'\Bhey')  # not at the beginning of a block


test_string = "helloHELLO 123-_"
printMatches(r"[helo]")
printMatches(r"[a-z]")
printMatches(r"[a-zA-Z]")
printMatches(r"[0-9-]")


test_string = "hello_123"
printMatches(r"\d")
printMatches(r"\d*")
printMatches(r"\d+")
printMatches(r"_\d")
printMatches(r"_?\d")
printMatches(r"\d{2}")
printMatches(r"\d{1,3}")

dates = '''
01.04.2020

2020.04.01

2020-04-01
2020-05-23
2020-06-11
2020-07-11
2020-08-11

2020/04/02

2020_04_04
2020_04_04
'''
printMatches(r"\d\d\d\d.\d\d.\d\d", test_string=dates)
printMatches(r"\d\d\d\d-\d\d-\d\d", test_string=dates)
printMatches(r"\d\d\d\d[-/]\d\d[-/]\d\d", test_string=dates)
printMatches(r"\d\d\d\d[-/]0[56][-/]\d\d", test_string=dates)
printMatches(r"\d\d\d\d[-/]0[5-7][-/]\d\d", test_string=dates)
printMatches(r"\d{4}[-/]0[5-7][-/]\d{2}", test_string=dates)


my_string = """
hello world
1223
2020-05-20
Mr Simpson
Mrs Simpson
Mr. Brown
Ms Smith
Mr. T
"""

printMatches(r"Mr\s\w+", test_string=my_string)
printMatches(r"Mr\.\s\w+", test_string=my_string)
printMatches(r"Mr\.?\s\w+", test_string=my_string)
printMatches(r"(Mr|Ms|Mrs)\.?\s\w+", test_string=my_string)

emails = """
pythonengineer@gmail.com
Python-engineer@gmx.de
python-engineer123@my-domain.org
"""

printMatches(r"[a-zA-Z0-9-]+@[a-zA-Z-]+\.(com|de|org)", test_string=emails)
printMatches(r"[a-zA-Z0-9-]+@[a-zA-Z-]+\.[a-zA-Z]+", test_string=emails)

printMatches(r"([a-zA-Z0-9-]+)@([a-zA-Z-]+)\.([a-zA-Z]+)",
             test_string=emails)  # can access using match.group(0) , match.group(1) ,etc.

test_string = "123abc456789abc123ABC"
pattern = re.compile(r"abc")
splitted = pattern.split(test_string)
print(splitted)

test_string = "hello world, you are the best world"
pattern = re.compile(r"world")
subbed_string = pattern.sub("planet", test_string)
print(subbed_string)


urls = """
hello
2020-05-20
http://python-engineer.com
https://www.python-engineer.org
http://www.pyeng.net
"""

url_template = r"https?://(www\.)?([a-zA-Z-]+)(\.[a-zA-Z]+)"
printMatches(url_template, test_string=urls)

pattern = re.compile(url_template)
subbed_urls = pattern.sub(r"\2\3", urls)
print("subbed_urls is ", subbed_urls)


my_string = "Hello World"
printMatches(r"world", test_string=my_string, ignore_case=True)
