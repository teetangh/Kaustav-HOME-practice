
from sklearn import datasets, metrics
from sklearn.tree import DecisionTreeClassifier
from sklearn.tree import DecisionTreeRegressor
from sklearn.model_selection import train_test_split
from IPython import get_ipython

import numpy as np
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
get_ipython().run_line_magic('matplotlib', 'inline')


iris = datasets.load_iris()
iris.target_names


iris.feature_names


X = iris.data
y = iris.target

X.shape, y.shape


df = pd.DataFrame(X, columns=iris.feature_names)
df['target'] = y
df.head()


sns.pairplot(df)


X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=1, stratify=y)


clf = DecisionTreeClassifier(criterion='gini', random_state=1)

clf.fit(X_train, y_train)
y_pred = clf.predict(X_test)


print("Accuracy: ", metrics.accuracy_score(y_test, y_pred))


mat = metrics.confusion_matrix(y_test, y_pred)
sns.heatmap(mat, square=True, annot=True, fmt='d', cbar=False,
            xticklabels=iris.target_names, yticklabels=iris.target_names)

plt.xlabel("Predicted Labels")
plt.ylabel("True Labels")
plt.title("Confusion Matrix")
plt.show()


print(mat)


print(metrics.classification_report(y_test, y_pred))
