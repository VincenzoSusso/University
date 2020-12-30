import os
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import accuracy_score
from sklearn.tree import export_graphviz

TEST_SIZE = 0.3
N_ESTIMATORS = 50
MAX_DEPTH = 6
DIRECTORY_TREES = "./Trees"

titanic = pd.read_csv(os.path.join(os.path.dirname(__file__), "Data/titanic.csv"))
titanic = titanic.drop(labels="Name", axis=1)

titanic = pd.get_dummies(titanic)

print("Titanic record: ")
print(titanic)

print("\nTitanic info: ")
print(titanic.info(verbose=True))

people_info = titanic.drop(labels="Survived", axis=1).values
people_survived = titanic["Survived"].values

people_info_train, people_info_test, people_survived_train, people_survived_test = train_test_split(people_info,
                                                                                                    people_survived,
                                                                                                    test_size=TEST_SIZE)

# With a random forest, usually more trees results in a better model but requires more computing power
model = RandomForestClassifier(n_estimators=N_ESTIMATORS, max_depth=MAX_DEPTH)
model.fit(people_info_train, people_survived_train)

people_survived_train_pred = model.predict(people_info_train)
people_survived_test_pred = model.predict(people_info_test)

print("\nTrain Accuracy: ", accuracy_score(people_survived_train, people_survived_train_pred))
print("\nTest Accuracy: ", accuracy_score(people_survived_test, people_survived_test_pred))

# Used to create the decision trees of the model, to see the content of the folder Trees click on the following link:
# http://webgraphviz.com/

try:
    if not (os.path.exists(DIRECTORY_TREES)):
        os.mkdir(DIRECTORY_TREES)
except OSError:
    print("The creation of the directory " + DIRECTORY_TREES + " has failed")
else:
    i = 0
    for node in model.estimators_:
        dotfile = open(DIRECTORY_TREES + "/Tree" + str(i) + ".dot", mode="w")
        export_graphviz(node, out_file=dotfile, feature_names=titanic.columns.drop("Survived"))
        dotfile.close()
        i += 1
