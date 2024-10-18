#include "linkedlist.h"
#include<iostream>
#include<map>

using namespace std; 

LinkedList linked_list(){
    LinkedList LL;
    for(int i=0; i < 10; i++){
        LL.addNode(i+1); 
    }
    return LL;
}

Node* returnKthLast(LinkedList list, int k){
    Node* current = list.head;
    Node* runner = list.head;
    
    // move runner k elements ahead
    int move_runner = 0;
    while(move_runner < k){
        move_runner++;
        runner = runner->next;
    } 
    // runner is now set to k elements ahead 
    
    // iterate over to get the kth to last element
    while(runner){
        runner = runner->next;
        if(runner != nullptr)
            current = current->next;
    }
    
    // print value of the kth to last element
    return current;
    
}

int main(){
    LinkedList list = linked_list();
    Node* nke = returnKthLast(list, 3);
    cout << "Value of the node is: " << nke->id << endl; 
    
    return 0;
}