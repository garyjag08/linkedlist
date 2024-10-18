#include "linkedlist.h"
#include<iostream>
#include<map>

using namespace std;

LinkedList::LinkedList(){} // defo

void LinkedList::addHeadNode(int val){
        head = new Node(val);
        head->next = nullptr;
        cur_node = head; 
}
void LinkedList::addNode(int val){
    if(head == nullptr){ // add head node (list is empty)
        addHeadNode(val);
    } else{
        Node* new_node = new Node(val);
        new_node->next = nullptr;
        cur_node->next = new_node;
        cur_node = cur_node->next; 
    } // else
}
    
    
void LinkedList::printList(){
    Node* cur_node = head;
    while(cur_node != nullptr){
        cout << cur_node->id << " ";
        cur_node = cur_node->next;
    } // while loop
        cout << endl; // spacing for output to look cleaner 
} // end void printList

LinkedList::~LinkedList() {}