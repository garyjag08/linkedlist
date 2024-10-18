#include "linkedlist.h"
#include<iostream>
#include<vector>
using namespace std;

LinkedList list(vector<int>values){
    LinkedList LL;
    for(const auto& element : values){
        cout << "Adding: " << element << " ";
        LL.addNode(element);
    }
    cout << endl;
    return LL;
}

void sumList_reverseOrder(LinkedList l1, LinkedList l2){
    Node* l1_cur = l1.head;
    Node* l2_cur = l2.head;
    LinkedList sum;
    bool isCarry = false;
    while(l1_cur && l2_cur){
        int _sum = l1_cur->id + l2_cur->id;
        if(isCarry)
            _sum += 1;
        sum.addNode(_sum % 10);
        if(_sum >= 10)
            isCarry = true; // for next round add 1
        else
            isCarry = false; // don't add 1 
    
        // next pointer
        l1_cur = l1_cur->next; // L1 
        l2_cur = l2_cur->next; // L2
    }
    
    // print the list
    sum.printList(); 
    
}

void sumList_forwaredOrder(LinkedList l1, LinkedList l2){
    Node* l1_cur = l1.head;
    Node* l2_cur = l2.head;
    LinkedList sum;
    while(l1_cur && l2_cur){
        int _carry = 0; 
        int _sum = l1_cur->id + l2_cur->id;
        if(l1_cur->next != nullptr && l2_cur->next != nullptr)
            _carry = l1_cur->next->id + l2_cur->next->id;
        if(_carry >= 10)
            _sum += 1;
        if(l1_cur == l1.head){
            sum.addNode(_sum);
        } else{
            sum.addNode(_sum % 10);
        }
        l1_cur = l1_cur->next;
        l2_cur = l2_cur->next;
    }
    
    // view new list
    sum.printList();
}

int main(){
    
    vector<int> val1 = {7,1,6};
    vector<int> val2 = {5,9,2};
    
    vector<int> val1_1 = {6,1,7};
    vector<int> val2_2 = {2,9,5};
    
    // reverse order
    cout << "Reverse order" << endl; 
    LinkedList _l1 = list(val1);
    LinkedList _l2 = list(val2); 
    sumList_reverseOrder(_l1,_l2);
    
    // forwared order
    cout << "Forward Order " << endl;
    LinkedList _l1_1 = list(val1_1);
    LinkedList _l2_2 = list(val2_2);
    sumList_forwaredOrder(_l1_1, _l2_2);
    
    cout << "end program" << endl; 
    return 0;
}