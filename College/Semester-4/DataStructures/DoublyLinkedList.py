class DLList:
    class node:
        def __init__(self,data):
            self.element = data
            self.next = None
            self.prev = None
           
          
    def __init__(self):
        self.head = self.node(None)
        self.tail = self.head
        self.sz = 0

    def getHead(self):
        #@start-editable@

        return self.head	
	    #@end-editable@
        
    
    def getLastNode(self):
        #@start-editable@

        return self.tail
	    #@end-editable@
        
     
    def insertLast(self,u):
        #@start-editable@

        myNode=self.node(u)
        if(self.isEmpty()):
            self.head=myNode
        else:
            self.tail.next=myNode
            myNode.prev=self.tail
        self.tail=myNode
        self.sz+=1
	    #@end-editable@
        

    def insertFirst(self,u):
        #@start-editable@

        myNode=self.node(u)
        if(self.isEmpty()):
            self.tail=myNode
        else:
            self.head.prev=myNode
            myNode.next=self.head
        self.head=myNode
        self.sz+=1
	    #@end-editable@
        
        
         
    #insert a node with value u after the node containing value v
    # error message: Node to insert after not found
    def insertAfter(self,u,v):
        #@start-editable@

        if(self.isEmpty()):
            print("Node to insert after not found")
        elif(self.tail.element==v):
            self.insertLast(u)
        else:
            myNode=self.node(u)
            myTemp=self.tail.prev
            while(myTemp!=None):
                if(myTemp.element==v):
                    myTemp.next.prev=myNode
                    myNode.next=myTemp.next
                    myTemp.next=myNode
                    myNode.prev=myTemp
                    self.sz+=1
                    return
                myTemp=myTemp.prev
            print("Node to insert after not found")
	    #@end-editable@
        


    #insert a node with value u before the node containing value v
    # error message: Node to insert before not found
    def insertBefore(self,u,v):
        #@start-editable@

        if(self.isEmpty()):
            print("Node to insert before not found")
        elif(self.head.element==v):
            self.insertFirst(u)
        else:
            myNode=self.node(u)
            myTemp=self.head.next
            while(myTemp!=None):
                if(myTemp.element==v):
                    myTemp.prev.next=myNode
                    myNode.prev=myTemp.prev
                    myTemp.prev=myNode
                    myNode.next=myTemp
                    self.sz+=1
                    return
                myTemp=myTemp.next
            print("Node to insert before not found")
	    #@end-editable@
        

    def deleteFirst(self):
        #@start-editable@

        if(self.isEmpty()):
            return
        elif(self.head==self.tail):
            self.head=self.node(None)
            self.tail=self.node(None)
        else:
            myTemp=self.head
            self.head=self.head.next
            self.head.prev=None
            del myTemp
        self.sz-=1
	    #@end-editable@
        

    def deleteLast(self):
        #@start-editable@

        if(self.isEmpty()):
            return
        elif(self.head==self.tail):
            self.head=self.node(None)
            self.tail=self.node(None)
        else:
            myTemp=self.tail
            self.tail=self.tail.prev
            self.tail.next=None
            del myTemp
        self.sz-=1
	    #@end-editable@
          

    #delete the node after the node containting value u
    # error message: Node to delete after not found
    def deleteAfter(self,u):
        #@start-editable@

        if (self.isEmpty()):
            print("Node to delete after not found")
        elif(self.sz==1 and self.tail.element!= u):
            print("Node to delete after not found")
        elif(self.tail.prev.element == u):
            self.deleteLast()
        else:
            myTemp = self.tail.prev.prev
            while(myTemp!=None):
                if(myTemp.element==u):
                    myTemp.next=myTemp.next.next
                    myTemp.next.prev=myTemp
                    self.sz -= 1
                    return
                myTemp=myTemp.prev
            print("Node to delete after not found")	
	    #@end-editable@
        

    #delete the node before the node containting value u
    # error message: Node to delete before not found
    def deleteBefore(self,u):
        #@start-editable@

        if(self.isEmpty()):
            print("Node to delete after not found")
        elif((self.sz==1) and (self.tail.element!= u)):
            print("Node to delete after not found")
        elif(self.head.element==u):
            return
        elif(self.head.next.element== u):
            self.deleteFirst()
        else:
            myTemp = self.head.next.next
            while(myTemp!=None):
                if(myTemp.element==u):
                    myTemp.prev=myTemp.prev.prev
                    myTemp.prev.next=myTemp
                    self.sz-= 1
                    return
                myTemp =myTemp.next
            print("Node to delete after not found")
	    #@end-editable@
        

    def findNode(self, val):
        #@start-editable@

        if(self.isEmpty()):
            print("ListEmpty")
            return
        else:
            curNode=self.head
            while(curNode!=None):
                if(curNode.element==val):
                    return curNode
                curNode=curNode.next          
	    #@end-editable@
        

    #swap the nodes containing u and v
    def swap(self,u,v):
        #@start-editable@

        if(self.isEmpty()):
            print("ListEmpty")
            return
        else:
            myTemp=self.head
            while(myTemp!=None):
                if(myTemp.element==u):
                    break
                myTemp=myTemp.next
            if(not myTemp):
                return
            myAnoTemp=self.tail
            while(myAnoTemp!=None):
                if(myAnoTemp.element==v):
                    break
                myAnoTemp=myAnoTemp.prev
            if(not myAnoTemp):
                return
            myTemp.element,myAnoTEmp.element=myAnoTemp.element,myTemp.element    
	    #@end-editable@
        
 
    def isEmpty(self):
        #@start-editable@


	    #@end-editable@
        return (self.sz==0)

    def size(self):
        #@start-editable@


	    #@end-editable@
        return self.sz

    def printList(self):
        if (self.isEmpty()):
            print ("Linked List Empty Exception")
        else:
            tnode = self.head
            while tnode!= None:
                print(tnode.element,end="->")
                tnode = tnode.next
            print(" ")
            tnode = self.tail
            while tnode!= None:
                print(tnode.element,end="->")
                tnode = tnode.prev
            print(" ")
        return
    
def testDLL():
    dll = DLList()
    inputs=int(input())
    while inputs>0:
        command=input()
        operation=command.split()
        if(operation[0]=="S"):
            print(dll.size())
        elif(operation[0]=="I"):
            print(dll.isEmpty())
        elif(operation[0]=="IF"):
            dll.insertFirst(int(operation[1]))
            dll.printList()
        elif(operation[0]=="IL"):
            dll.insertLast(int(operation[1]))
            dll.printList()
        elif(operation[0]=="DF"):
            dll.deleteFirst()
            dll.printList()
        elif(operation[0]=="DL"):
            dll.deleteLast()
            dll.printList()
        elif(operation[0]=="IA"):
            dll.insertAfter(int(operation[1]),int(operation[2]))
            dll.printList()
        elif(operation[0]=="IB"):
            dll.insertBefore(int(operation[1]),int(operation[2]))
            dll.printList()
        elif(operation[0]=="DA"):
            dll.deleteAfter(int(operation[1]))
            dll.printList()
        elif(operation[0]=="DB"):
            dll.deleteBefore(int(operation[1]))
            dll.printList()   
        elif(operation[0]=="F"):
            print(dll.getHead().element)
        elif(operation[0]=='L'):
            print(dll.getLastNode().element)
        elif(operation[0]=='FIND'):
            temp = dll.findNode(int(operation[1]))
            if (temp!=None):
                print(temp.element)
            else:
                print("NULL")
        elif(operation[0]=='SW'):
            dll.swap(int(operation[1]),int(operation[2]))
            dll.printList()
        inputs-=1


def main():
    testDLL()

if __name__ == '__main__':
    main()
