#include "linkedlist.h"
#include<iostream>
#include<map>

using namespace std;

LinkedList llist(){
    LinkedList LL;
    for(int i = 0; i < 10; i++){
        LL.addNode(i+1);
    }
    return LL;
}

void deleteMiddleNode(LinkedList list){
    Node* current = list.head;
    Node* runner = list.head;
    while(runner){
        int i = 0;
        while(i<2){
            if(runner){
                runner=runner->next; 
            }
            if(runner == nullptr){
                break; 
            }
            i++;
        }
        if(runner){ // check if runner is not nullptr
            // due to the nested for loop runner could be nullptr
            current = current->next; 
        }
    }
    cout << current->id << endl; 
}

int main(){
    
    // Linked List
    LinkedList linked_list = llist();
    deleteMiddleNode(linked_list);
    return 0;
}