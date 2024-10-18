#include "linkedlist.h"
#include<iostream>
#include<map>
#include<vector>
using namespace std;

class Palindrome{
    public:
    Palindrome(){}
    LinkedList halfList(Node* node){
        LinkedList LL;
        while(node){
            LL.addNode(node->id);
            node=node->next; 
        }
        return LL;
    }
    
    LinkedList reverse(LinkedList list){
        // reverse linked list
        Node* prev = nullptr;
        Node* current = list.head;
        while(current){
            Node* next = current->next;
            current->next = prev;
            prev = current;
            if(next == nullptr){
                list.head = current;
            }
            current = next; 
        }
        return list; 
    }
    
    Node* middleNode(Node* head) {
        if (head == nullptr || head->next == nullptr) {
            cout << "head is a nullptr" << endl;
            return head;
        }
    
        Node* slow = head;
        Node* fast = head;
    
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    Node* lastNode(Node* element){
        if(element->next != nullptr)
            return lastNode(element->next);
        return element;
    }
    
    void printValues(Node* element){
        while(element){
            cout << element->id << " ";
            element = element->next;
        }
        cout << endl;
    }
    
    bool oddNumberNodes(LinkedList list, Node* middle){
        Node* _1_cur = list.head;
        Node* _2_cur = middle->next;
        while(_1_cur != middle){
            if(_1_cur->id != _2_cur->id)
                return false;
            _1_cur=_1_cur->next;
            _2_cur=_2_cur->next; 
        }
        return true;
    }
    
    bool evenNumberNodes(LinkedList list, Node* middle){
        Node* start = list.head;
        Node* _start = middle->next;
        while(start != middle->next){
            if(start->id != _start->id)
                return false;
            start = start->next;
            _start=_start->next; 
        }
        return true; 
    }
    
};


LinkedList list(){
    LinkedList LL;
    vector<int> v = {1,2,3,2,1,4};
    int _count = 0;
    for(const auto& element : v){
        LL.addNode(element);
        _count++;
    }
    LL.num_nodes = _count; 
    cout << "there are: " << LL.num_nodes << " nodes in the linked list" << endl; 
    return LL;
}


bool isPalindrome(LinkedList list){
    // new instance of Palindrone class
    Palindrome P;
    
    // middle of the list
    Node* middle = P.middleNode(list.head); // middle node of the list
    
    // create a linked list for the second half of the linked list
    LinkedList _half_reversed = P.halfList(middle->next); // linked list that is half of the original
    
    // reverse the second half of the linked list
    _half_reversed = P.reverse(_half_reversed);
    
    
    // link the two linked list
    middle->next = _half_reversed.head;
    
    
    if(list.num_nodes %2 == 0)
        return P.evenNumberNodes(list, middle); 
    else
        return P.oddNumberNodes(list, middle); 

}

int main(){
    // Make  a linkedlist
    LinkedList l_list = list();
    //LinkedList reversed_list = reverse(l_list);
    //Node* head = reversed_list.head;
    //printValues(head); // print reverse of the linked list 
    bool p = isPalindrome(l_list); 
    if(p)
        cout << "is a palindrome" << endl;
    else
        cout << "not a palindrome" << endl; 
    return 0; 
}