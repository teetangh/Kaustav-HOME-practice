!pip install -q kaggle

# !pip uninstall -y kaggle
# !pip install --upgrade pip
# !pip install kaggle==1.5.6
# !kaggle -v

!mkdir -p ~/.kaggle

!cp "/content/drive/My Drive/Colab Notebooks/KGP Talkie DL/kaggle.json" ~/.kaggle/

!chmod 600 /root/.kaggle/kaggle.json

import kaggle

!kaggle datasets download -d chirag19/air-passengers



######################################################################


import numpy as np
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
%matplotlib inline

from sklearn import datasets,metrics
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.feature_selection import VarianceThreshold


import tensorflow as tf
from tensorflow import keras
from tensorflow.keras import Sequential
from tensorflow.keras.layers import Flatten,Dense,Dropout,BatchNormalization
from tensorflow.keras.layers import Conv2D,MaxPool2D,ZeroPadding2D
from tensorflow.keras.preprocessing.image import ImageDataGenerator

from tensorflow.keras.optimizers import SGD
from tensorflow.keras.optimizers import Adam

print(tf.__version__)

model.compile(optimizer=Adam(lr=0.00001), loss = "binary_crossentropy" , metrics=["accuracy"])

history = model.fit(X_train,y_train,epochs=epochs,validation_data=(X_test,y_test),verbose = 1)


opt = SGD(learning_rate = 0.01, momentum = 0.9)
model.compile(optimizer=opt,loss="binary_crossentropy",metrics=["accuracy"])

history = model.fit_generator(generator=train_generator,steps_per_epoch=len(train_generator),epochs=5,validation_data=validation_generator,validation_steps=len(validation_generator),verbose=1)

X_train,X_test,y_train,y_test = train_test_split(X,y,test_size = 0.2 , random_state =0 , stratify = y )
X_train.shape,X_test.shape,y_train.shape,y_test.shape

scaler = StandardScaler()
X_train = scaler.fit_transform(X_train)
X_test = scaler.fit_transform(X_test)
X_train.shape,X_test.shape

y_train = y_train.to_numpy()
y_test = y_test.to_numpy()
y_train.shape,y_test.shape

def plot_learningCurve(history,epochs):
  # Plot the training and validation accuracy valeus
  epoch_range = range(1,epochs+1)
  plt.plot(epoch_range,history.history['accuracy'])
  plt.plot(epoch_range,history.history['val_accuracy'])
  plt.title("Model Accuracy")
  plt.xlabel("Epoch")
  plt.ylabel("Accuracy")
  plt.legend(["Train","Val"],loc = "upper left")
  plt.show()
  # Plot the training and validation accuracy valeus
  epoch_range = range(1,epochs+1)
  plt.plot(epoch_range,history.history['loss'])
  plt.plot(epoch_range,history.history['val_loss'])
  plt.title("Model loss")
  plt.xlabel("Epoch")
  plt.ylabel("loss")
  plt.legend(["Train","Val"],loc = "upper left")
  plt.show()

plot_learningCurve(history,epochs=epochs)  # We are underfitting here