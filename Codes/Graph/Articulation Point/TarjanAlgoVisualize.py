from json import dumps
from random import randint
# coding:utf-8
# tarjan algorithm
# https://blog.csdn.net/jeryjeryjery/article/details/52829142?locationNum=4&fps=1
# Find a connected graph starting at any vertex with one and only one and dfn [u] == low [u]
from collections import OrderedDict
matric = [[0, 1, 1, 0, 0, 0], [0, 0, 0, 1, 0, 0], [0, 0, 0, 1, 1, 0],
          [1, 0, 0, 0, 0, 1], [0, 0, 0, 0, 0, 1], [0, 0, 0, 0, 0, 0]]
dfn = OrderedDict()
low = OrderedDict()
flag = dict()
count = 0
n = 6
num = 0

graph = {
    "kind": {"graph": True},
    "nodes": [],
    "edges": []
}


class Stack(object):
    def __init__(self):
        self.items = list()

    def push(self, item):
        self.items.append(item)

    def pop(self):
        return self.items.pop()

    def clear(self):
        del self.items[:]

    def empty(self):
        return self.size() == 0

    def size(self):
        return len(self.items)

    def top(self):
        return self.items[self.size() - 1]


s = Stack()

donetrackx = []
donetracky = []


def tarjan(u):
    global s, num, n, count, flag, stack, dfn, low, matric
    count = count + 1
    dfn[u] = low[u] = count
    s.push(u)
    flag[u] = True
    # print("visiting {0} ...".format(str(u + 1)))
    for i in range(n):
        if matric[u][i] == 0:
            continue
        if flag.get(i, False) is True:
            if (dfn[i] < low[u]):
                # print("Hello")
                # i+1 u+1
                # print("Hello", i+1)
                # print("\n*", u+1)
                # graph["nodes"].append(
                #     {"id": str(u+1), "label": str(u+1), "color": "blue"})
                # graph["edges"].append({"from": str(u+2), "to": str(i+2)})
                # json_graph = dumps(graph)
                donetrackx.append(u+1)
                donetracky.append(i+1)
                low[u] = dfn[i]
        else:
            tarjan(i)
            low[u] = min(low[u], low[i])
    if (dfn[u] == low[u] and s.empty() is False):
        print("******** Connected diagram ********")
        m = s.pop()
        flag[m] = False
        print(m + 1)
        while m != u and s.empty() is False:
            num = num + 1
            m = s.pop()
            flag[m] = False
            print(m+1)
        print("*********************")
# This code is contributed by Neelam Yadav


# [[0,1,1,0,0,0],[0,0,0,1,0,0],[0,0,0,1,1,0],[1,0,0,0,0,1],[0,0,0,0,0,1],[0,0,0,0,0,0]]

tarjan(3)
al = [0, 0, 1, 2, 2, 2, 3, 3, 4, 6]
bl = [1, 2, 3, 3, 4, 5, 0, 5, 5, 6]
for i in range(len(al)):
    src = al[i]
    dst = bl[i]
    graph["nodes"].append(
        {"id": str(src+1), "label": str(src+1)})
    graph["edges"].append({"from": str(src+1), "to": str(dst+1)})
    json_graph = dumps(graph)
    print("i is " + str(i))


for j in range(len(donetrackx)):
    src = donetrackx[j]
    dst = donetracky[j]
    graph["nodes"].append(
        {"id": str(src), "label": str(src)})
    graph["edges"].append({"from": str(src), "to": str(dst), "color": "red"})
    json_graph = dumps(graph)
print("Number of connected graphs ...")
print(num)
