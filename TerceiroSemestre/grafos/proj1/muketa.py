class Graph:


    def __init__(self, n_vert):

        self.v = n_vert
        self.colors = [-1] * n_vert
        self.adj_list = []
        for i in range(n_vert):
            self.adj_list.append([])


    def addEdge(self, a, b):

        if (a >= 0 and a < self.v and b >= 0 and b < self.v):
            if (b not in self.adj_list[a]):
                self.adj_list[a].append(b)
            if (a not in self.adj_list[b]):
                self.adj_list[b].append(a)


def main():

    temp = input()
    quantidade = int(temp.split()[1])
    graph = Graph(quantidade)
    
    # Leitura do vertice
    temp = input()

    for i in range(0, quantidade - 1):
        temp = input()
        a = int(temp.split()[0])
        b = int(temp.split()[1])

        graph.addEdge(a, b)
            

    vertexGroup = [1,2,4,8,9,10,12,13,14]
    for i in vertexGroup:

        vertexGroup = [1,2,4,8,9,10,12,13,14]

        graphCopy = graph

        equalColor = True
        vertexGroupCopy = vertexGroup
        vertexGroupCopy.remove(i)
        for j in range(len(vertexGroupCopy)):
            for k in range(j + 1, len(vertexGroupCopy)):
                if vertexGroupCopy[j] in graphCopy.adj_list[vertexGroupCopy[k]]:
                    equalColor = False
                    break

        if equalColor:
            print(i)
            exit()



if __name__ == '__main__':
    main()