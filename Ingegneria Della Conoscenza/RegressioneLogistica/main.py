import os
import pandas as pd
from sklearn.preprocessing import StandardScaler
from sklearn.preprocessing import LabelEncoder
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import log_loss
from sklearn.metrics import accuracy_score

TEST_SIZE = 0.3

dataset = pd.read_csv(os.path.join(os.path.dirname(__file__), "Data/wdbc.data"), names=["id", "diagnosis",
                                                                                        "radius_mean", "texture_mean",
                                                                                        "perimeter_mean", "area_mean",
                                                                                        "smoothness_mean",
                                                                                        "compactness_mean",
                                                                                        "concavity_mean",
                                                                                        "concave points_mean",
                                                                                        "symmetry_mean",
                                                                                        "fractal_dimension_mean",
                                                                                        "radius_se", "texture_se",
                                                                                        "perimeter_se", "area_se",
                                                                                        "smoothness_se",
                                                                                        "compactness_se",
                                                                                        "concavity_se",
                                                                                        "concave points_se",
                                                                                        "symmetry_se",
                                                                                        "fractal_dimension_se",
                                                                                        "radius_worst", "texture_worst",
                                                                                        "perimeter_worst", "area_worst",
                                                                                        "smoothness_worst",
                                                                                        "compactness_worst",
                                                                                        "concavity_worst",
                                                                                        "concave points_worst",
                                                                                        "symmetry_worst",
                                                                                        "fractal_dimension_worst"])

print("Record: ")
print(dataset)

print("\nInfo: ")
print(dataset.info())

cancer_info = dataset.drop(labels=["id", "diagnosis"], axis=1).values
cancer_diagnosis = dataset["diagnosis"].values

cancer_info = StandardScaler().fit_transform(cancer_info)
cancer_diagnosis = LabelEncoder().fit_transform(cancer_diagnosis)  # Used to convert labels into numerical values

cancer_info_train, cancer_info_test, cancer_diagnosis_train, cancer_diagnosis_test = train_test_split(cancer_info,
                                                                                                      cancer_diagnosis,
                                                                                                      test_size=TEST_SIZE)

model = LogisticRegression()
model.fit(cancer_info_train, cancer_diagnosis_train)

cancer_diagnosis_train_pred = model.predict(cancer_info_train)
cancer_diagnosis_train_prob = model.predict_proba(cancer_info_train)

cancer_diagnosis_test_pred = model.predict(cancer_info_test)
cancer_diagnosis_test_prob = model.predict_proba(cancer_info_test)

# If the difference between the accuracy of the prediction of the train and the accuracy of the prediction of the test
# is high, then overfitting is likely to occur.
print("\nTrain info: ")
print("Accuracy Score: ", accuracy_score(cancer_diagnosis_train, cancer_diagnosis_train_pred))  # The nearest to 1 the better
print("Log loss: ", log_loss(cancer_diagnosis_train, cancer_diagnosis_train_prob))  # The less the better

print("\nTest info: ")
print("Accuracy Score: ", accuracy_score(cancer_diagnosis_test, cancer_diagnosis_test_pred))
print("Log loss: ", log_loss(cancer_diagnosis_test, cancer_diagnosis_test_prob))
