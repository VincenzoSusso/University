import os
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.preprocessing import StandardScaler
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error
from sklearn.metrics import r2_score

TEST_SIZE = 0.3

homes = pd.read_csv(os.path.join(os.path.dirname(__file__), "Data/housing.data"), sep="\\s+",
                    names=["crimeRate", "percentageResidentialZone", "percentageNonRetailBusiness", "charlesRiver",
                           "concentrationNitrogenOxide", "roomsNumber", "percentageOccupiedHouseAfter1940PerCity",
                           "distanceTop5EmploymentCenters", "freewayAccessibilityIndexPerCity", "propertyTaxRate10000",
                           "studentTeacherRatio", "percentageBlackResidentPerCity", "percentagePoorPopulation",
                           "medianValueHouses"])

print("\nRecords: ")
print(homes)

print("\nInfo of the columns: ")
print(homes.info())

# When the value tends to 0 the correlation is null,
# When the value tends to 1 the correlation is direct,
# When the value tends to -1 the correlation is inverse
print("\nCorrelations between columns: ")
print(homes.corr())

# Showing the correlation with a graph
sns.heatmap(homes.corr(), xticklabels=homes.columns, yticklabels=homes.columns, annot=True)
plt.show()

homesInfo = homes.drop(labels="medianValueHouses", axis=1).values
homesValues = homes["medianValueHouses"].values

# Standardizing the dataset
homesInfo = StandardScaler().fit_transform(homesInfo)

homesInfoTrain, homesInfoTest, homesValuesTrain, homesValuesTest = train_test_split(homesInfo, homesValues,
                                                                                    test_size=TEST_SIZE)

linearRegressionModel = LinearRegression()
linearRegressionModel.fit(homesInfoTrain, homesValuesTrain)
homesValuesPredict = linearRegressionModel.predict(homesInfoTest)

print("\nMean squared error: ", mean_squared_error(homesValuesTest, homesValuesPredict))
print("\nRegression score: ", r2_score(homesValuesTest, homesValuesPredict))
