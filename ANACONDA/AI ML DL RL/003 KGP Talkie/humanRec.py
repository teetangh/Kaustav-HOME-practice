!pip install tensorflow

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
%matplotlib inline

import tensorflow as tf
from tensorflow.keras import Sequential
from tensorflow.keras.layers import Conv2D,MaxPool2D,
from tensorflow.keras.layers import BatchNormalization,Dropout,Flatten,Dense
from tensorflow.keras.optimizers import Adam

print(tf.__version__)

from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler,LabelEncoder

# pd.read_csv(r'C:\Users\Kaustav\Desktop\WISDM_ar_latest\WISDM_ar_v1.1')
file = open(r"/content/drive/My Drive/Colab Notebooks/Data Folder/WISDM_ar_latest/WISDM_ar_v1.1/WISDM_ar_v1.1_raw.txt")
lines = file.readlines()

processedList = []

for i,line in enumerate(lines):
    try:
        line = line.split(",")
        last = line[5].split(";")[0]
        last = last.strip()
        if last == "":
            break

        temp = [line[0],line[1],line[2],line[3],line[4],last]
        processedList.append(temp)
    except:
        print("Error at line number: ",i)

print(processedList)

columns = ["user" , "activity" ,"time" , 'x' , 'y' , 'z']

data = pd.DataFrame(data = processedList , columns = columns)
data.head()

data.info()
data.describe()

data.isnull().sum()
data["activity"].value_counts()

# Balance the dataset

data['x'] = data['x'].astype("float") 
data['y'] = data['y'].astype("float") 
data['z'] = data['z'].astype("float") 

Fs = 20


activities = data["activity"].value_counts().index


def plot_activity(activity,data):
	fig,(ax0,ax1,ax2) = plt.subplots(nrows=3 , figsize=(15,7) , sharex=True)
	plot_axis(ax0,data["time"],data['x'],"X-Axis")
	plot_axis(ax1,data["time"],data['y'],"Y-Axis") 
	plot_axis(ax2,data["time"],data['z'],"Z-Axis")
	plt.subplots_adjust(hspace=0.2)
	fig.suptitle(activity)
	plt.subplots_adjust(top=0.90) 
	plt.show()

def plot_axis(ax,x,y,title):
	ax.plot(x,y,'g')
	ax.set_title(title)
	ax.xaxis.set_visible(False)
	ax.set_ylim([min(y) - np.std(y) , max(y) + np.std(y)])
	ax.set_xlim([min(x),max(x)])
	ax.grid(True)

for activity in activities:
	data_for_plot = data[(data['activity'] == activity)][:Fs*10]
	plot_activity(activity,data_for_plot)


df = data.drop(["user","time"],axis=1).copy()
df.head()