import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.datasets import load_digits
from sklearn.preprocessing import MinMaxScaler
from sklearn.preprocessing import LabelEncoder
from sklearn.model_selection import train_test_split
from sklearn.multiclass import OneVsRestClassifier
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import log_loss
from sklearn.metrics import accuracy_score
from sklearn.metrics import confusion_matrix

TEST_SIZE = 0.3

digits = load_digits()

digits_features = digits.data
digits_target = digits.target

digits_features = MinMaxScaler().fit_transform(digits_features)
digits_target = LabelEncoder().fit_transform(digits_target)

digits_features_train, digits_features_test, digits_target_train, digits_target_test = train_test_split(digits_features,
                                                                                                        digits_target,
                                                                                                        test_size=TEST_SIZE)

model = OneVsRestClassifier(LogisticRegression())
model.fit(digits_features_train, digits_target_train)

digits_target_train_pred = model.predict(digits_features_train)
digits_target_train_prob = model.predict_proba(digits_features_train)

digits_target_test_pred = model.predict(digits_features_test)
digits_target_test_prob = model.predict_proba(digits_features_test)

print("Train info: ")
print("Accuracy score: ", accuracy_score(digits_target_train, digits_target_train_pred))
print("Log loss: ", log_loss(digits_target_train, digits_target_train_prob))

print("Test info: ")
print("Accuracy score: ", accuracy_score(digits_target_test, digits_target_test_pred))
print("Log loss: ", log_loss(digits_target_test, digits_target_test_prob))

# Train heatmap
plt.figure(figsize=(9, 9))
sns.heatmap(confusion_matrix(digits_target_train, digits_target_train_pred), annot=True, square=True, cmap="Blues",
            fmt="d")
plt.title("Train info")
plt.xlabel("Predicted class")
plt.ylabel("Correct class")
plt.show()

# Test heatmap
plt.figure(figsize=(9, 9))
sns.heatmap(confusion_matrix(digits_target_test, digits_target_test_pred), annot=True, square=True, cmap="Blues",
            fmt="d")
plt.title("Test info")
plt.xlabel("Predicted class")
plt.ylabel("Correct class")
plt.show()
