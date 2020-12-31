import matplotlib.pyplot as plt
from sklearn.datasets import make_circles
from sklearn.model_selection import train_test_split
from sklearn.svm import SVC
from sklearn.metrics import accuracy_score

NOISE = 0.2
FACTOR = 0.5

X, y = make_circles(noise=NOISE, factor=FACTOR)  # Building dataset

plt.title("Dataset")
plt.scatter(X[:, 0], X[:, 1], c=y)  # Showing the distribution of the points
plt.show()

X_train, X_test, y_train, y_test = train_test_split(X, y)

# Radial basis function kernel: https://en.wikipedia.org/wiki/Radial_basis_function_kernel
model_rbf = SVC(kernel="rbf")  # The most used kernel
model_rbf.fit(X_train, y_train)

y_train_pred = model_rbf.predict(X_train)
y_test_pred = model_rbf.predict(X_test)
print("Rbf model accuracy train: ", accuracy_score(y_train, y_train_pred))
print("Rbf model accuracy test: ", accuracy_score(y_test, y_test_pred))

# Linear function kernel
model_linear = SVC(kernel="linear")  # LinearSVC
model_linear.fit(X_train, y_train)

y_train_pred = model_linear.predict(X_train)
y_test_pred = model_linear.predict(X_test)
print("\nLinear model accuracy train: ", accuracy_score(y_train, y_train_pred))
print("Linear model accuracy test: ", accuracy_score(y_test, y_test_pred))

# Polynomial kernel: https://en.wikipedia.org/wiki/Polynomial_kernel
model_polynomial = SVC(kernel="poly")
model_polynomial.fit(X_train, y_train)

y_train_pred = model_polynomial.predict(X_train)
y_test_pred = model_polynomial.predict(X_test)
print("\nPolynomial model accuracy train: ", accuracy_score(y_train, y_train_pred))
print("Polynomial model accuracy test: ", accuracy_score(y_test, y_test_pred))

# Sigmoid kernel
model_sigmoid = SVC(kernel="sigmoid")
model_sigmoid.fit(X_train, y_train)

y_train_pred = model_sigmoid.predict(X_train)
y_test_pred = model_sigmoid.predict(X_test)
print("\nSigmoid model accuracy train: ", accuracy_score(y_train, y_train_pred))
print("Sigmoid model accuracy test: ", accuracy_score(y_test, y_test_pred))
