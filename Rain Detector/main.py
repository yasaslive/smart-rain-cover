from sklearn import svm
import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split 
from sklearn.metrics import accuracy_score
import pickle

df = pd.read_csv('weatherAUS.csv', header=0)
df = df.dropna()

X = df[['RainAnalog', 'SolarPW']]
y = df['RainDigital']

X, X_test, y, y_test = train_test_split(X, y, test_size=0.2)

model = svm.SVC(C=1000)
model.fit(X, y)

y_pred = model.predict(X_test)
print(accuracy_score(y_test, y_pred))

file = open('sample.pickle', 'wb')
pickle.dump(model, file)