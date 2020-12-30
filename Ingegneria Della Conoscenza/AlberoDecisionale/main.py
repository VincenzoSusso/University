import os
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier
from sklearn.metrics import accuracy_score
from sklearn.tree import export_graphviz

TEST_SIZE = 0.3
MAX_DEPTH = 6

titanic = pd.read_csv(os.path.join(os.path.dirname(__file__), "Data/titanic.csv"))
titanic = titanic.drop(labels="Name", axis=1)

titanic = pd.get_dummies(titanic)  # OneHotEncoding

print("Titanic record: ")
print(titanic)

print("\nTitanic info: ")
print(titanic.info(verbose=True))

people_info = titanic.drop(labels="Survived", axis=1).values
people_survived = titanic["Survived"].values

people_info_train, people_info_test, people_survived_train, people_survived_test = train_test_split(people_info,
                                                                                                    people_survived,
                                                                                                    test_size=TEST_SIZE)

# One advantage of decision trees is that they don't require the data to be on the same scale, so we can go right ahead
# and create our model.

# The criterion can be "gini" or "entropy", but usually gini has less computational complexity
# Max_depth is a parameter to optimize, if max_depth is too high an overfitting may occur
model = DecisionTreeClassifier(criterion="gini", max_depth=MAX_DEPTH)
model.fit(people_info_train, people_survived_train)

people_survived_train_pred = model.predict(people_info_train)
people_survived_test_pred = model.predict(people_info_test)

print("\nTrain Accuracy: ", accuracy_score(people_survived_train, people_survived_train_pred))
print("\nTest Accuracy: ", accuracy_score(people_survived_test, people_survived_test_pred))

# Used to create the decision tree of the model, to see the content of the file Tree.dot click on the following link:
# http://webgraphviz.com/
dotfile = open("Tree.dot", mode="w")
export_graphviz(model, out_file=dotfile, feature_names=titanic.columns.drop("Survived"))
dotfile.close()
