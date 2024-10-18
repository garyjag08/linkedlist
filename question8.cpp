#include "linkedlist.h"
#include<iostream>

using namespace std;

LinkedList list(){
    LinkedList LL:
    
    
}

bool hasCycle(LinkedList list){
    Node* slow = list.head;
    Node* runner = list.head;
    
    while(fast != nullptr && fast->next != nullptr){
        fast=fast->next->next;
        slow=slow->next;
        if(slow == fast){
            return true;
        }
    }
    
    return false;
}

int main(){
    
    return 0;
}