Pandas Documentation
====================

Installation
------------

On Ananconda Distributions, Pandas can be installed using the following command:

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
conda install pandas
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Pandas can also be installed from the command line using pip using

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
pip install pandas
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Series and DataFrames
---------------------

Pandas Series is a labelled 1d array capable of holding data of any type
(int,str,float,objects,etc.) The axis labels are collectively called as index

Pandas DataFrames is a 2d array that is able to store heterogeneous data items
which can input in the form of a dictionary

![](media/742347fa61eb5a43942503d544f94d4d.png)

### Accessing Elements from a Pandas Series/DataFrame

Elements can from a pandas dataframe just like a dictionary

[./media/image2.png](./media/image2.png)
----------------------------------------

Reading CSV Files and inserting them, constructing Pandas Data Frames and viewing the data
------------------------------------------------------------------------------------------

Path can be a chosen as a raw string and feed into pandas via the read_csv(),
read_tsv() or read_table() command as illustrated below:

The path variable must a reference to a tabular datasheet in the user’s local
machine

Once the DataFrame has been created, the top 5 rows can be viewed using the
head() command

![](media/6e029c1925562e403fd7754da7eef1c0.png)

Moreover, the bottom rows can also be viewed using the tail command (). Also, a
desirable number of rows can be passed into the bracket.

![](media/f588f7614cb7762144e3a7c6dc4247d7.png)

Setting a Different Index
-------------------------

Pandas gives the user an option of setting indices to other data columns using
the index_col parameter in the read_csv command

![](media/d0ebc02c99e76a63c7ec29da045bedc2.png)

Getting Useful Insights into the data
-------------------------------------

The user can get description of Column names, nullability and data types of the
columns using the info() command

![](media/ed4e4defcaac431e24865862d6376656.png)

Further, detailed statistics can constructed from the data using the describe()
command.

![](media/346074fe8d529606f9865e891d560c44.png)

The shape of the Data-Frame can be checked using shape command

![](media/d403c9ce245c0138085814e04cbc3e0e.png)

**Checking for Duplicates**

The Data-Frames might contain duplicates and this can be checked using
duplicated () cmd.

![](media/2ec7c822315d8c2f0baf67acbd93fb1f.png)

**The columns can be viewed using df.columns**

![](media/368f311f89ec69af79bb7a5e3893f0e3.png)

**The columns can also be manipulated using df.columns**

[./media/image11.png](./media/image11.png)
------------------------------------------

**The columns can also be manipulated using df.columns**

![](media/870891e1f0fda407c1a8c602c26aa215.png)

Checking for NULL values in the dataset
---------------------------------------

1.  To check for NULL values in the dataset use the isnull() or isna() cmd

2.  To perform sum use the isnull().sum() cmd.

![](media/0a5449be9dec9a94873e7105b98aa52a.png)

**Gathering Valuable insights into the dataset**

1.  To get the total counts of each category use the value_counts () cmd

2.  To check check for uniqueness in the data use the unique (). This would
    return the number of unique values in a particular Pandas Series.

![](media/413186ab8c69aae6873956877be13c9d.png)

**The Correlation Matrix**

The correlation matrix shows the relationship between various features and can
be implemented using the corr () method.

![](media/c40be401e929ca34998887a7e9721592.png)

Bibliography
------------

1.  TakenMind Course [Udemy]

2.  Google

3.  Stack Overflow

4.  Wikipedia
