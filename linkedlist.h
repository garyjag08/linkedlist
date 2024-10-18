#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class Node{
    public:
        Node* next;
        int id;
        Node(int v){
            id = v; 
        }
};

class LinkedList {
public:
    Node* head = nullptr;
    Node* cur_node = nullptr;
    int num_nodes = 0; 
    LinkedList(); // contructor 
    ~LinkedList(); // destructor 
    void addHeadNode(int val);
    void addNode(int val);
    void printList();
};

#endif // LINKEDLIST_H
