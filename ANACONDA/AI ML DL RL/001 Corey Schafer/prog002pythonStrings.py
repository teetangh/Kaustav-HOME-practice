message1 = 'Hello World'
print(message1)
print()

message2 = "Bobby's World"
print(message2)
print()

print(len(message1))
print(len(message2))
print()

print(message1[3])
# print(message1[100])  # out of bounds
print()

print(message1[:])
print(message1[:5])
print(message1[3:])
print(message1[3:5])
print()

print(message1.lower())
print(message1.upper())
print()

print(message1.find('World'))
print(message2.find('Universe'))
print()

# Creates a copy of the string and replaces that
message1.replace('World','Universe')
print(message1)

# Assigns the orignal string to the replacement
message1 = message1.replace('World','Universe')
print(message1)