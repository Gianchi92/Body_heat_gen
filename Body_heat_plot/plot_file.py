# -*- coding: utf-8 -*-
"""
Created on Fri Oct 13 16:44:49 2023

@author: Gianc
"""
import matplotlib.pyplot as plt
import pandas as pd

# Read the CSV file into a DataFrame
df = pd.read_csv('Gianni.csv')

# Extract the 'Temperature' column
temperatures = df['Temperature']

# Create a bar plot
plt.bar(df['Index'], temperatures, color='blue')

# Add labels and title
plt.xlabel('Index')
plt.ylabel('Temperature (°C)')
plt.title('Temperature Evolution')

# Set y-axis limits
plt.ylim(36, 38)

# Show the plot
plt.show()
