#include "linkedlist.h"
#include<iostream>
#include<vector>
using namespace std;

class Intersection{
    public:
        Intersection(){}
        int length(Node* node){
            int _count = 0;
            while(node){
                _count++;
                node=node->next; 
            }
            return _count;
        }
        
        Node* lastNode(Node* node){
            while(node->next){
                node=node->next;
            }
            return node;
        }
        
        Node* advancePointer(Node* node, int position_toAdvance){
            while(position_toAdvance > 0){
                node=node->next;
                position_toAdvance--;
            }
            return node; 
        }
};

LinkedList list(vector<int>& vec){
    LinkedList LL;
    int count = 0;
    for(const auto& element : vec){
        LL.addNode(element);
        count++;
    }
    LL.num_nodes = count; 
    return LL;
}

void intersection(LinkedList& l1, LinkedList& l2, LinkedList& l3){
    //new instance of Intersection class
    Intersection I;
    
    // heads of l1 and l2
    Node* headL1 = l1.head;
    Node* headL2 = l2.head;
    
    // merge ends of l1 and l2 to the head of l3
    Node* end_l1 = I.lastNode(headL1);
    Node* end_l2 = I.lastNode(headL2);
    end_l1->next = l3.head;
    end_l2->next = l3.head;
    
    // advance pointer, but first which list is longer
    int l1_numNodes = l1.num_nodes;
    int l2_numNodes = l2.num_nodes;
    
    // get the difference
    int _numPositions = abs(l1_numNodes - l2_numNodes);
    
    //advance pointer
    if(l1_numNodes > l2_numNodes)
        headL1 = I.advancePointer(l1.head, _numPositions);
    else
        headL2 = I.advancePointer(l2.head, _numPositions); 
    
    // compare
    while(headL1 != headL2){
        headL1=headL1->next;
        headL2=headL2->next;
    }
    
    if(headL1 != nullptr)
        cout << headL1->id << " is the node where they intersect" << endl;
    else
        cout << "The nullptr is where they intersect" << endl; 
}

int main(){
    
    vector<int> list1 = {5,6,7};
    vector<int> list2 = {1,2,3,4};
    vector<int> list3 = {8,9,10,11};
    
    // need three lists
    LinkedList l1 = list(list1);
    LinkedList l2 = list(list2);
    LinkedList l3 = list(list3);
    
    // intersection function
    intersection(l1,l2,l3);
    
    return 0;
}