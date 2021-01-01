import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.datasets import make_blobs
from sklearn.cluster import KMeans

N_SAMPLES = 500
N_CENTERS = 4

x, y = make_blobs(n_samples=N_SAMPLES, centers=N_CENTERS, cluster_std=.8)

plt.rcParams["figure.figsize"] = (14, 10)
sns.set()
plt.scatter(x[:, 0], x[:, 1])
plt.show()

sse = {}
for k in range(1, 10):
    model = KMeans(init="k-means++", n_clusters=k)
    model.fit(x)
    y_pred = model.predict(x)
    sse[k] = model.inertia_

# Use elbow method: https://en.wikipedia.org/wiki/Elbow_method_(clustering)
plt.figure()
plt.plot(list(sse.keys()), list(sse.values()), marker='o')
plt.xlabel("Number of clusters", fontsize=16)
plt.ylabel("Sum of squared distance", fontsize=16)
plt.show()
