from mnist import load_mnist
from sklearn.preprocessing import MinMaxScaler
from sklearn.preprocessing import LabelEncoder
from sklearn.neural_network import MLPClassifier
from sklearn.metrics import accuracy_score

NODES = 100

image_train, image_test, number_train, number_test = load_mnist(path="Data/")

print("Number of training data: ", image_train.shape[0])
print("Number of test data: ", image_test.shape[0])

scaler = MinMaxScaler()
image_train = scaler.fit_transform(image_train)
image_test = scaler.transform(image_test)

labelEncoder = LabelEncoder()
number_train = labelEncoder.fit_transform(number_train)
number_test = labelEncoder.transform(number_test)

# Hidden_layer_sizes is a parameter to optimize
model = MLPClassifier(hidden_layer_sizes=(NODES, ))
model.fit(image_train, number_train)

number_train_pred = model.predict(image_train)
number_test_pred = model.predict(image_test)

print("Train accuracy score: ", accuracy_score(number_train, number_train_pred))
print("Test accuracy score: ", accuracy_score(number_test, number_test_pred))
