import numpy as np
class Set:
    #A class called set is created, here the separate sets are created for each nodes
    Master_Set={}
    def Create_Different_Set(self,N):
        #Here we create N disjoint sets
        for i in range(N):
            self.Master_Set[i]=i

    def Find(self,parent,e):
        #finding the root node
        if parent[e]==e:
            return e
        return self.Find(parent,parent[e])

    def Union(self,parent,rank,x,y):
        #Unioning the sets
        a=self.Find(parent,x)
        b=self.Find(parent,y)

        if rank[a] < rank[b]:
            parent[a]=b
        elif rank[a] > rank[b]:
            parent[b]=a
        else:
            parent[b]=a
            rank[a] +=1    



def Boruvkas_algorithm(edge,N):
    #create list called MST this will be our minimum spanning tree after doing kruskls algo
    MST=[]
    #Initializing the class Set
    s=Set()
    #Calling create_different_set method for creating set for each vertex
    s.Create_Different_Set(N)

    parent = []
    rank = []
    cheapest =[]

    ind=0
    
    # Create N subsets with single elements
    for node in range(N):
        parent.append(node)
        rank.append(0)
        cheapest =[-1] * N
    edge.sort(key=lambda x:x[2])
    
    for i in range(len(edge)):
        u,v,w = edge[i]
        
        x = s.Find(parent, u)
        y = s.Find(parent ,v)
        
        if x!=y:
            if cheapest[x]==-1 or cheapest[x][2]>w:
                cheapest[x]=[u,v,w]
                
            if cheapest[y]==-1 or cheapest[y][2]>w:
                cheapest[y]=[u,v,w]
                

        for node in range(N):
            if cheapest[node] !=-1:
                u,v,w=cheapest[node]
                x=s.Find(parent, u)
                y=s.Find(parent, v)

                if x!=y:
                    ind +=w
                    s.Union(parent,rank,x,y)
                    MST.append((u,v,w))
                    
    return MST




if __name__=='__main__':
    #Creating graph with edge list called edge
    arr =np.genfromtxt("D:\College\Semester 5\Design and Analysis of Algorithms\Minimum Spanning Tree Algorithms\Boruvka Algorithm\Example.txt",delimiter=',')
    int_array = arr.astype(int)

    edge=int_array.tolist()
    
    
    print("The graph Original: \n",edge)
    
    #N be the total number of nodes u be the starting node and v be the ending node and w be the weights
    N=5
    #Calling The Boruvkas_algorithm and storing it in the var min_span_tree 
    min_span_tree=Boruvkas_algorithm(edge,N)
    print("The Minimum Spanning Tree :\n",min_span_tree)