import os
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error
from sklearn.metrics import r2_score
import matplotlib.pyplot as plt

TEST_SIZE = 0.3

homes = pd.read_csv(os.path.join(os.path.dirname(__file__), "Data/housing.data"), sep="\\s+", usecols=[5, 13],
                    names=["numRooms", "homeValue"])

print("First 10 records:")
print(homes.head(n=10))  # Reading the first 10 record of the dataframe from the top

# Saving the columns of the dataframe into two array
numRooms = homes["numRooms"].values
homeValues = homes["homeValue"].values

# Change shape of the array without changing the elements (in this case a 2D array is created because of the function
# fit)
numRooms = numRooms.reshape(-1, 1)

# Split randomly the data into two set called trainingSet and testSet
numRoomsTrain, numRoomsTest, homeValuesTrain, homeValuesTest = train_test_split(numRooms, homeValues,
                                                                                test_size=TEST_SIZE)

# Building the linear model
linearRegression = LinearRegression()
linearRegression.fit(numRoomsTrain, homeValuesTrain)
homeValuesPredict = linearRegression.predict(numRoomsTest)

print("\nMean squared error: ", mean_squared_error(homeValuesTest, homeValuesPredict))  # The less the better

print("\nRegression score function:", r2_score(homeValuesTest, homeValuesPredict))  # The nearest to 1 the better

# Building the plot
plt.scatter(numRoomsTrain, homeValuesTrain, c="green", edgecolors="white", label="TrainSet")
plt.scatter(numRoomsTest, homeValuesTest, c="blue", edgecolors="white", label="TestSet")
plt.xlabel("Number of rooms")
plt.ylabel("Home value")
plt.legend(loc="upper left")
plt.plot(numRoomsTest, homeValuesPredict, color="red", linewidth="3")
plt.show()
