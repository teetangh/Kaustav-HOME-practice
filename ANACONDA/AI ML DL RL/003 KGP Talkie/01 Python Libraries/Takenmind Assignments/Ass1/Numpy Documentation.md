Numpy Documentation
===================

Installation
------------

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
pip install numpy
conda install numpy
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Import
------

Numpy Python library can be imported using the following command

![](media/e41457a352f29994539afd081302d5b3.png)

**Converting Lists into Numpy Arrays**

Use the np.array cmd which can take in a parameter of a list, to convert a
regular python list into a Numpy Array

![](media/0b4e830a9709de2c46c9e9e523ff6268.png)

**NOTE: Elements cannot be appended into Numpy Arrays since memory has already
been allocated**

The append cmd can be used to append elements into lists. However, this command
doesn’t work with numpy arrays

![](media/e9baf1109dadb7624b18beb3154721c1.png)

**Creating Multi-dimensional Numpy Arrays**

Similarly, when nested lists are passed into the np.array() cmd, the list is
converted into a 2d array

![](media/f94d569021e430c7269a3a4db29e2c0c.png)

The Data-type can also be checked using the dtype cmd

![](media/8cd18b232c47a819362cc9b018afcc79.png)

When converting the list into a numpy array, the data-type of the elements can
be modified using the dtype parameter

![](media/1bf9b101661e4045b07970ae156f5561.png)

The astype () cmd can be used to cast a particular object into the desired dtype

Using the inplace=False parameter doesn’t modify the original data

![](media/fc20153aafb8a05544e92604c5996743.png)

**Converting Numpy array back to list**

The original list can retrieved by using the tolist() cmd

![](media/dce99d6f893a9a59814defa65cda9e90.png)

**Gathering Useful information regarding the Numpy array**

The statistics regarding unidimensional or multidimensional data can be found
using the shape, dtype, size and dimension keywords

![](media/975b4f66ee3b90401ff402bd72c0c7f1.png)

**Printing the contents of the Numpy Array**

The contents of the numpy array can be revealed simply using the print () cmd.

![](media/3b270759f7965f6c5cd09956e0e8d1fd.png)

**Accessing elements of the Array**

The elements in the array can be accessed simply using the indices in square
brackets succeeding the numpy array name as illustrated below

![](media/407cf763eb37d24a06daf32ef124b0f6.png)

Further desired conditions can be applied according to the user and the same can
be passed into the indices of the numpy array to retrieve the elements matching
the particular condition.

![](media/b68cba0f6e277e5b5d15c8e553d59bec.png)

**Reversing rows, columns or both**

The Numpy rows, columns or both can reversed by passing in -1 while slicing the
numpy array as illustrated below.

![](media/f740ff84a5ab612e0130115cad52c199.png)

**Numpy also supports NULL and INFINITE values**

This can be implemented using np.nan and np.inf respectively

![](media/c2c4dc8da4cff49c1305c762ad123650.png)

**Checking for NULL and INFINITE values in the Numpy Arrays**

The null and infinite values in the numpy arrays can be checked using the
isnan() and isinf () cmd.

![](media/9ab44d61d854cc9e6098f91723862217.png)

The missing nan and inf values can replaced by accessing the numpy as
illustrated before

![](media/9483fe76a29bc59d302bcacef9573d57.png)

**Statistical Operations**

Statistical Operations can be performed on the numpy array using the mean (),
std (), max (), min (), etc. cmds.

![](media/87c6e46acc54f3feb935830f74495851.png)

The array can be squeezed using the squeeze command

![](media/fe4280fc58b47dd67987a1fc7af6c63f.png)

The cumulative sum of the array can be evaluated using the cumsum () command

![](media/db17274ba72d6d1f8917ebc8fbddbad5.png)

**Reshape, Flatten and Ravel**

The array can be reshaped, flattened (converted into a 1d array) and raveled
(also converted into a 1d array and in-place)

![](media/50979dc06c375d40a97b8e532d36ac47.png)

Sequences, Repetitions and Random Numbers
=========================================

A sequence of real numbers can be generated within a range using the arrange
command and also passing the desired dtype parameter.

![](media/0a77622ad75fe1c33a1a9d60fe626ee1.png)

A sequence of linearly or logarithmically spaced real numbers can be inserted
between 2 limits using the linspace cmd() or logspace() cmd

![](media/626d6065496a9212fd3f925f3d7d812f.png)
