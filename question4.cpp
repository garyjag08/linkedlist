#include "linkedlist.h"
#include<iostream>
#include<map>
#include<vector>
using namespace std;

LinkedList llist(){
    vector<int> v = {3,5,8,5,10,2,1};
    LinkedList LL;
    
    for (const auto& element : v) {
        cout << "adding: " << element << " ";
        LL.addNode(element);
    }
    cout << "done building linked list:" << endl; 
    return LL;
}

void printList(Node* list){
    cout << "Printing the freaking list: " << endl; 
    while(list){
        cout << list->id << " -> ";
        list = list->next;
    }
    cout << "nullptr" << endl; // extra line for spacing
}

void partitionList(LinkedList list, int partition_value){
    Node* before = nullptr;
    Node* after = nullptr;
    Node* beforeEnd = nullptr;
    Node* afterEnd = nullptr;
    Node* current = list.head; 
    
    while(current){
        Node* next = current->next;
        if(current->id < partition_value){
            if(before == nullptr){
                before = current;
                before->next = nullptr;
                beforeEnd = before;
            } else{
                beforeEnd->next = current;
                beforeEnd = beforeEnd->next;
                beforeEnd->next = nullptr; 
            }
        } // end if for values < partition_value
        else{
            if(after == nullptr){
                after = current;
                afterEnd = after;
            } else{
                afterEnd->next = current;
                afterEnd = afterEnd->next;
                afterEnd->next = nullptr;
            }
        } // end else (for values >= partition_value)
        current = next;  // end
    }
    
    beforeEnd->next = after; // append the before and after lists
    list.head = before;  // set current list head to new linked list
    printList(list.head);  // print list to view nodes 
}

int main(){
    LinkedList list = llist();
    partitionList(list,5);
    
    return 0; 
}