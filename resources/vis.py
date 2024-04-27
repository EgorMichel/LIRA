import networkx as nx
import numpy as np
import matplotlib.pyplot as plt
import csv
matrix = []
weights=[]
with open('12x12_1.csv', newline='') as csvfile:
    reader = csv.reader(csvfile)
    for line in reader:
        matrix.append([int(i) for i in line])
with open('w_1.csv', newline='') as weights_file:
    reader = csv.reader(weights_file)
    for line in reader:
        weights = [float(i) for i in line]

options = {
    'node_color': 'yellow',     # color of node
    'node_size': 3500,          # size of node
    'width': 1,                 # line width of edges
    'arrowstyle': '-|>',        # array style for directed graph
    'arrowsize': 18,            # size of arrow
    'edge_color':'blue',        # edge color
}

G = nx.DiGraph(np.matrix(matrix))

pos = nx.circular_layout(G)

for node, weight in zip(G.nodes, weights):
    G.nodes[node]['weight'] = weight

labels = {n: str(n) + ': ' + str(G.nodes[n]['weight']) for n in G.nodes}


nx.draw(G, pos, with_labels=True, arrows=True, labels=labels, **options)
# nx.draw_networkx_labels(G, pos, labels=G.nodes)
plt.show()
