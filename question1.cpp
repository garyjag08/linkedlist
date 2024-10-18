#include "linkedlist.h"
#include<iostream>
#include<map>

using namespace std; 

LinkedList llist(){
    LinkedList LL;
    LL.addNode(1);
    LL.addNode(100);
    LL.addNode(50);
    LL.addNode(55);
    LL.addNode(3);
    LL.addNode(100);
    LL.addNode(3);
    LL.addNode(67);
    
    return LL;
    
}


void removeDuplicates(LinkedList list){
    map<int, bool> nodeVals;
    Node* current = list.head; // start at the head 
    Node* prev = nullptr; // store previous pointer in case deletion is needed 
    while(current){
        if(nodeVals.find(current->id) == nodeVals.end()){ // doesn't exist in the map (will be true for head node)
            nodeVals[current->id] = true;
            prev = current;
        } else{
            // exists in the map, delete node
            prev->next = current->next;
            delete current;
        }
        current = prev->next; 
    }
    
    list.printList(); 
    
}

void removeDuplicates_noBuffer(LinkedList list){
    Node* current = list.head;
    //Node* runner = current;
    while(current){
        Node* runner = current;
        while(runner->next){
            if(runner->next->id == current->id){
                Node* duplicate = runner->next;
                runner->next = runner->next->next;
                delete duplicate;
            } else{
                runner = runner->next; 
            }
        }
        current = current->next;
    }
    
    list.printList(); 
}


int main(){
    cout << "Hello program \n";
    LinkedList list = llist();
    removeDuplicates(list); // can use a temp buffer
    removeDuplicates_noBuffer(list); // remove duplicates function 
    
    return 0;
}