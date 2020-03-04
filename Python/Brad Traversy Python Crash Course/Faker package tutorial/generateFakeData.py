# Python GENERATE FAKE DATA

# from faker import Factory
# fake_data = Faker()

# OR

from faker import Faker
fake_data = Faker()

# create fake name
name = fake_data.name()
print(name + '\n')


# create fake address
address = fake_data.address()
print(address + '\n')

# create fake email
email = fake_data.email()
print(email)

# create fake profile
profile = fake_data.simple_profile()
for k, v in profile.items():
    print('{}: {}'.format(k, v))
