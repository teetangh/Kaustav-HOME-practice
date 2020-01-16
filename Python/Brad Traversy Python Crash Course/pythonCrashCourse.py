# Single Line Comment

'''
Multiline 
Comment
'''
# Variables and Single Assignment
x = 1  # int
y = 2.5  # float
name = 'John'  # String
is_cool = 'True'

# Multiple Asssignment
x, y, name, is_cool = (2, 4.5, 'Kaustav', False)

print(x, y, name, is_cool)

# Basic Math
a = x + y
print('a', a)

# casting
x = str(x)
y = int(y)
z = float(y)

# printing data Type
print('z', type(y), y)
print('y', type(z), z)

# Strings
name = 'Brad'
age = 37

# Strings Concatenation
# print('Hello,my name is ' + name + ' and I am ' + age) #Wont work in vanilla Python
print('Hello,my name is ' + name + ' and I am ' + str(age))

# String Formatting
print('His name is {name} and he is {age}'.format(name=name, age=age))

# F-Strings (3.6+)
print(f'okay,my name is {name} and I am {age}')

# Strings Methods
s = 'hello world'

# Capitalize
print(s.capitalize())
