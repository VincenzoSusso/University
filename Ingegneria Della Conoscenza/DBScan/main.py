import matplotlib.pyplot as plt
from sklearn.datasets import make_moons
from sklearn.cluster import DBSCAN

N_SAMPLES = 100
NOISE = 0.05

x, y = make_moons(n_samples=N_SAMPLES, noise=NOISE)

# Showing graph
plt.scatter(x[:, 0], x[:, 1])
plt.show()

# DBScan is used to classify clusters that are not spherical in shape
# eps should not be too little or too big
# min_samples is usually equals to n_dimension + 1
model = DBSCAN(eps=0.25, min_samples=3)
y_pred = model.fit_predict(x)

# Showing graph
plt.scatter(x[:, 0], x[:, 1], c=y_pred)
plt.show()
