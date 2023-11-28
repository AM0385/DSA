import matplotlib.pyplot as plt

# Data for the two lines
data_x_values = [50000, 100000, 150000, 200000, 250000, 300000]
y_values_singlyLL = [5.603, 24.196, 55.475, 99.62, 156.005, 225.671]
y_values_circularLL = [5.666, 24.131, 55.926, 99.568, 156.93, 229.467]

# Plotting the lines
plt.plot(data_x_values, y_values_singlyLL, label='Singly Linked List')
plt.plot(data_x_values, y_values_circularLL, label='Circular Linked List')

# Adding labels and title
plt.xlabel('Data Size')
plt.ylabel('Time')
plt.title('Singly Linked List and Circular Linked List Time Comparison')

# Adding a legend
plt.legend()

# Display the plot
plt.show()
