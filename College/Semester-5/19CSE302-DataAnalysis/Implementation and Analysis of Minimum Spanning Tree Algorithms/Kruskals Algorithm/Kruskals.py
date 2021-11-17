import numpy as np
class Set:
    #A class called set is created, here the separrte sets are created for each nodes
    Master_Set={}
    def Create_Different_Set(self,N):
        #Here we create N disjoint sets
        for i in range(N):
            self.Master_Set[i]=i

    def Find(self,e):
        #finding the root node
        if self.Master_Set[e]==e:
            return e
        return self.Find(self.Master_Set[e])

    def Union(self,x,y):
        #Unioning the sets
        a=self.Find(x)
        b=self.Find(y)
        self.Master_Set[a]=b


def Kruskals_algorithm(edge,N):
    #create list called MST this will be our minimum spanning tree after doing kruskls algo
    MST=[]
    #Initializing the class Set
    s=Set()
    #Calling create_different_set method for creating set for each vertex
    s.Create_Different_Set(N)
    ind=0
    # sort edges by increasing weight
    edge.sort(key=lambda x:x[2])
    while len(MST)!= N-1:
        (u,v,w)=edge[ind]
        ind+=1
        #finding the root of the sets where the next edge belong 
        x=s.Find(u)
        y=s.Find(v)
        # if both have different Master set then union them and add to list MST
        if x != y:
            MST.append((u,v,w))
            s.Union(x,y)
    return MST


if __name__=='__main__':
    #Creating graph with edge list called edge
    arr =np.genfromtxt("D:\College\Semester 5\Design and Analysis of Algorithms\Minimum Spanning Tree Algorithms\Boruvka Algorithm\Example.txt",delimiter=',')
    int_array = arr.astype(int)

    edge=int_array.tolist()
    
    
    print("The graph Original: \n",edge)
    #N be the total number of nodes u be the starting node and v be the ending node and w be the weights
    N=5
    #Calling The method Kruskals_algorithm and storing it in the var min_span_tree 
    min_span_tree=Kruskals_algorithm(edge,N)
    print("The Minimum Spanning Tree :\n",min_span_tree)