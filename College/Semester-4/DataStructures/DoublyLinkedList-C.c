#include <iostream>
#include<string>
#include <sstream>
using namespace std;

template<class T>
class DLList {
public:
	class Node {
	public:
		T element;
		Node *next;
		Node *prev;
		Node(T x) {
		    //@start-editable@

			prev = NULL;
			next = NULL;
			element = x;
			
			//@end-editable@
		}
	};
	Node *head;
	Node *tail;
	int n;
public:
	DLList() {
		n = 0;
		head = tail = NULL;
	}

	bool isEmpty(){
		//@start-editable@

		return n == 0;
		
		
		//@end-editable@
	}

	int size() {
	    //@start-editable@

	    return n;
	    
	    
	    //@end-editable@
	}

	bool insertLast(T x) {
	    //@start-editable@

		
		if(isEmpty()){
			insertFirst(x);
		}
		else{
			Node *newNode = new Node(x);
			newNode->prev = tail;
			tail->next = newNode;
			tail = newNode;
			n++;
		}
		
		
		//@end-editable@
		return true;
	}

	T insertFirst(T x) {
	    //@start-editable@

		
		Node *newNode = new Node(x);
		if(isEmpty()){
			head = newNode;
			tail = head;
			n++;
		}
		
		else{
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
			n++;
		}
		
		
		//@end-editable@
		return x;
	}

	T deleteLast() {
	    //@start-editable@

		
		if(isEmpty()){
	    	cout<<"List Empty"<<endl;
	    	return -1;
		}
	    else if(n == 1){
			T x = head->element;
			delete head;
			tail = head = NULL;
			n--;
			return x;
		}
		T x = tail->element;
		Node *temp = tail;
		tail = tail->prev;
		tail->next = NULL;
		n--;
		delete temp;
		
		
		
		//@end-editable@
		return x;
		
		
	}

	T deleteFirst() {
	    //@start-editable@

		if(isEmpty()){
			cout<<"List Empty"<<endl;
			return -1;
		}
		else if(n == 1){
			T x = head->element;
			delete head;
			tail = head = NULL;
			n--;
			return x;
		}
		T x = head->element;
		Node *temp = head;
		head = head->next;
		head->prev = NULL;
		delete temp;
		n--;
		
		
		
		
		
		//@end-editable@
		return x;
	}

	//insert a node with value u after the node containing value v
    T insertAfter(T u,T v){
    	//@start-editable@

		
		Node *temp = tail;
    	if(isEmpty()){
    		return -1;
		}
		else if (temp->element == v){
			insertLast(u);
			return -1;
		}
		else{
			Node *newNode = new Node(u);
			temp = temp->prev;
			while(temp != NULL){
				if(temp->element == v){
					newNode->next = temp->next;
					newNode->prev = temp;
					temp->next = newNode;
					newNode->next->prev = newNode;
					n++;
					return u;
				}
				temp = temp->prev;
			}
		}
    	
		cout<<"Node to insert after not found"<<endl;
		return u;
		
		
		//@end-editable@
    	return true;
    }
    

    //insert a node with value u before the node containing value v

    T insertBefore(T u,T v){
    	//@start-editable@

		Node *newNode = new Node(u);
    	Node *temp = head;
    	
    	if(isEmpty()){
    		return -1;
		}
    	else if(temp->element == v){
    		insertFirst(u);
    		return -1;
		}
		else{
			temp = temp->next;
			while(temp != NULL){
				if(temp->element == v){
					newNode->prev = temp->prev;
					newNode->next = temp;
					temp->prev = newNode;
					newNode->prev->next = newNode;
					n++; 
					return u;
				}
				temp = temp->next;
			}
		}
    	
 		
		cout<<"Node to insert before not found"<<endl;
		return u;
		
		
		
		//@end-editable@
    	return true;
    }

    //delete the node after the node containting value u
    T deleteAfter(T u){
    	//@start-editable@

		
		if(isEmpty() || tail->element == u){
			return -1;
		}
		else if(size() == 1){
			cout<<"Node to delete after not found"<<endl;
			return -1;
		}
		else if(tail->prev->element == u){
			deleteLast();
			return -1;
		}
		Node *fNode = head;
		Node *lNode = tail;
		while(fNode != NULL && lNode != NULL){
			if(fNode->element == u){
				fNode->next = fNode->next->next;
				fNode->next->prev = fNode;
				n--;
				return u;
			}
			else if(lNode->element == u){
				lNode->next = lNode->next->next;
				lNode->next->prev = lNode;
				n--;
				return u;
			}
			else{
				fNode = fNode->next;
				lNode = lNode->prev;
			}
		}
		cout<<"Node to delete after not found"<<endl;
		return u;
		
		
		//@end-editable@

    }
    
	//delete the node before the node containting value u
    T deleteBefore(T u){
    	//@start-editable@

		
		if(isEmpty() || head->element == u){
			return -1;
		}
		else if(size() == 1){
			cout<<"Node to delete before not found";
			return -1;
		}
		Node *fNode = head;
		Node *lNode = tail;
		if(head->next->element == u){
			deleteFirst();
			return -1;
		}
		while(fNode != NULL && lNode != NULL){
			if(fNode->element == u){
				fNode->prev = fNode->prev->prev;
				fNode->prev->next = fNode;
				n--;
				return u;
			}
			else if(lNode->element == u){
				lNode->prev = lNode->prev->prev;
				lNode->prev->next = lNode;
				n--;
				return u;
			}
			else{
				fNode = fNode->next;
				lNode = lNode->prev;
			}
		}
		cout<<"Node to delete before not found"<<endl;
		return u;
		
		
		//@end-editable@

    }

    T getHead() {
    	//@start-editable@

		
		return head->element;
		
		
		
		//@end-editable@

    }

    T getTail() {
    	//@start-editable@

		
		return tail->element;
		
		
		
		//@end-editable@

    }

    Node* findNode(T val){
    	//@start-editable@

		Node *temp = NULL;
		Node *fNode = head;
		Node *lNode = tail;
		while(fNode != NULL && lNode != NULL){
			if(fNode->element == val){
				return fNode;
			}
			else if(lNode->element == val){
				return lNode;
			}
			else{
				fNode = fNode->next;
				lNode = lNode->prev;
			}
		}
    	
		
		
		
		//@end-editable@
    	return temp;
    }

    //swap the nodes containing u and v
    void swap(T u,T v){
    	//@start-editable@

		Node *temp1 = head;
		Node *temp2 = tail;
		while(temp1 != NULL){
			if(temp1->element == u)
				break;
			temp1 = temp1->next;
		}
		
		while(temp2 != NULL){
			if(temp2->element == v)
				break;
			temp2 = temp2->prev;
		}
		
		if(temp1 == NULL || temp2 == NULL)
			return;	
		T ele1 = temp1->element;
		
		temp1->element = temp2->element;
		temp2->element = ele1;
		
		
		
		
		//@end-editable@

    	
    }
     
	//Prints the list
	void printlist(){
		if (!isEmpty()) {
			Node *temp = head;
			while (temp != NULL) {
				cout << temp->element << "->";
				temp = temp->next;
			}
			cout << endl;
			temp = tail;
			while (temp != NULL) {
				cout << temp->element << "->";
				temp = temp->prev;
			}
			cout << endl;
			return;
		}
		cout << ("Linked List Empty Exception")<<endl;
	}

};

int getValue(string s, int pos) {
    istringstream iss(s);
    string temp;
    iss>>temp;
    iss>>temp;
    if(pos==1) {
        return stoi(temp);
    }
    else {
        iss>>temp;
        return stoi(temp);
    }
}
//Driver Code
int main(){
	DLList<int> dlist1;
 	string noOfInputs,str;
 	getline(cin, noOfInputs);
 	for(int i=0;i<stoi(noOfInputs);i++){
 	    getline(cin, str); 
 	    
 	    if (str.substr(0, 2) == "IF"){
 	        int value = getValue(str, 1);
 	        dlist1.insertFirst(value);
 	        dlist1.printlist();
 	    }
 	    else if (str.substr(0, 2) == "IL"){
 	        int value = getValue(str, 1);
 	        dlist1.insertLast(value);
 	        dlist1.printlist();
 	    }
 	    else if (str.substr(0, 2) == "DF"){
 	        dlist1.deleteFirst();
 	        dlist1.printlist();
 	    }
 	    else if (str.substr(0, 2) == "DL"){
 	        dlist1.deleteLast();
 	        dlist1.printlist();
 	    }
 	    else if (str.substr(0, 2) == "IA"){
 	        int value1 = getValue(str, 1);
 	        int value2 = getValue(str, 2);
 	        dlist1.insertAfter(value1,value2);
 	        dlist1.printlist();
 	    }
 	    else if (str.substr(0, 2) == "IB"){
 	        int value1 = getValue(str, 1);
 	        int value2 = getValue(str, 2);
 	        dlist1.insertBefore(value1,value2);
 	        dlist1.printlist();
 	    }
		else if (str.substr(0, 2) == "DA"){
 	        int value = getValue(str, 1);
 	        dlist1.deleteAfter(value);
 	        dlist1.printlist();
 	    }
 	    else if (str.substr(0, 2) == "DB"){
 	        int value = getValue(str, 1);
 	        dlist1.deleteBefore(value);
 	        dlist1.printlist();
 	    }
 	    else if (str.substr(0, 1) == "L"){
 	       cout<< dlist1.getTail()<<endl;
 	    }
 	    else if (str.substr(0, 4) == "FIND"){
 	       int value1 = getValue(str, 1);
 	       DLList<int> :: Node *temp = dlist1.findNode(value1);
 	       if (temp!=NULL){
 	       	cout<<temp->element<<endl;
 	       }
 	       else{
 	       	cout<<"NULL"<<endl;
 	       }
 	    }
 	    else if (str.substr(0, 1) == "F"){
 	       cout<< dlist1.getHead()<<endl;
 	    }
 	    else if (str.substr(0, 2) == "SW"){
 	       int value1 = getValue(str, 1);
 	       int value2 = getValue(str, 2);
 	       dlist1.swap(value1,value2);
 	       dlist1.printlist();
 	    }
 	    else if (str.substr(0, 1) == "S"){
 	       cout<< dlist1.size()<<endl;
 	    }
 	    else if (str.substr(0,1) == "I"){
 	        //cout<<slist1.isEmpty()<<endl;
 	        if(dlist1.isEmpty()){
 	            cout<<"True"<<endl;
 	        }
 	        else{
 	            cout<<"False"<<endl;
 	        }
 	    }
 	}
}
