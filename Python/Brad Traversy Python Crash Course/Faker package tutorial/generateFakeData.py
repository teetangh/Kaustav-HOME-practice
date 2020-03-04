# To add a new cell, type '# %%'
# To add a new markdown cell, type '# %% [markdown]'
# %%
# Python GENERATE FAKE DATA

# from faker import Factory
# fake_data = Faker()

# OR


# %%
from faker import Faker
fake_data = Faker()


# %%
# create fake name
name = fake_data.name()
print(name + '\n')


# %%
# create fake address
address = fake_data.address()
print(address + '\n')


# %%
# create fake email
email = fake_data.email()
print(email)


# %%
# create fake profile
profile = fake_data.simple_profile()
for k, v in profile.items():
    print('{}: {}'.format(k, v))
print()


# %%
# display name,address,email
print('Name: {},Address: {},Email: {}'.format(name, address, email))
print()


# %%
# generate a large set of fake data
for _ in range(0, 2):
    print(' NAME= ' + fake_data.name() + ' EMAIL= ' +
          fake_data.email() + ' ADDRESS= ' + fake_data.address()+' \n ')


# %%

# Function to fill a list with data
# change .name() to another data type for other data options
def create_names_list(how_many):
    names = []
    for _ in range(0, how_many):
        names.append(fake_data.name())
    return names


# %%
print(create_names_list(20))


# %%
# create person objects with name,address,etc.
class Customers:
    def __init__(self,name,address,email):
        self.name=name
        self.address=address
        self.email=email
    # special method __repr() to display data associated with the object
    def __repr__(self):
        return 'NAME: {},ADDRESS: {},EMAIL: {}'.format(self.name,self.address,self.email)

# Instance of customers class using fake data
customer1 = Customers(fake_data.name(),fake_data.address(),fake_data.email())
print(customer1)

