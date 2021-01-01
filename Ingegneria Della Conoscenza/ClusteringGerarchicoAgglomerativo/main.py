import matplotlib.pyplot as plt
from scipy.cluster.hierarchy import linkage
from scipy.cluster.hierarchy import dendrogram
from sklearn.datasets import make_blobs
from sklearn.cluster import AgglomerativeClustering

N_SAMPLES = 100
CENTERS = 3

x, y = make_blobs(n_samples=N_SAMPLES, centers=CENTERS, cluster_std=0.5)

# Showing graph
plt.scatter(x[:, 0], x[:, 1])
plt.show()

# Building dendogram
dendogram = dendrogram(linkage(x, method="ward"))
plt.ylabel("Distance")
plt.title("Dendrogram")
plt.show()

# Clusters that are further away from others can be ignored through the use of the exact cluster number
model = AgglomerativeClustering(n_clusters=CENTERS)
y_pred = model.fit_predict(x)

plt.scatter(x[:, 0], x[:, 1], c=y_pred)
plt.show()
