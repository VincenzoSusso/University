import os
import pandas as pd
from sklearn.preprocessing import StandardScaler
from sklearn.preprocessing import LabelEncoder
from sklearn.model_selection import train_test_split
from sklearn.svm import LinearSVC
from sklearn.metrics import accuracy_score

TEST_SIZE = 0.3

dataset = pd.read_csv(os.path.join(os.path.dirname(__file__), "Data/iris.data"),
                      names=["sepalLength", "sepalWidth", "petalLength", "petalWidth", "class"])

print("Iris record: ")
print(dataset)

print("\nIris info: ")
print(dataset.info(verbose=True))

flowers_info = dataset.drop(labels="class", axis=1).values
flowers_class = dataset["class"].values

flowers_info = StandardScaler().fit_transform(flowers_info)
flowers_class = LabelEncoder().fit_transform(flowers_class)

flowers_info_train, flowers_info_test, flowers_class_train, flowers_class_test = train_test_split(flowers_info,
                                                                                                  flowers_class,
                                                                                                  test_size=TEST_SIZE)

model = LinearSVC()
model.fit(flowers_info_train, flowers_class_train)

flowers_class_train_pred = model.predict(flowers_info_train)
flowers_class_test_pred = model.predict(flowers_info_test)

print("\nTrain accuracy score: ", accuracy_score(flowers_class_train, flowers_class_train_pred))
print("\nTest accuracy score: ", accuracy_score(flowers_class_test, flowers_class_test_pred))
