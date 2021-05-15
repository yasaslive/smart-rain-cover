# -*- coding: utf-8 -*-
"""
Created on Sat May 15 14:30:32 2021

@author: Yasas
"""
import pickle
model = pickle.load(open('sample.pickle', 'rb'))

prd = model.predict()

print(prd) 