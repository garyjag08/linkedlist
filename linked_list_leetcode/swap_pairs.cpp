#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* buildList(vector<int>& nums){
    ListNode* head = nullptr;
    ListNode* cur;
    for(auto& n : nums){
        if(head == nullptr){
            head = new ListNode(n);
            cur = head;
        } else{
            ListNode* new_node = new ListNode(n);
            cur->next = new_node;
            cur=cur->next;
        }
    } // for
    return head; 
}

void printList(ListNode* node){
    while(node){
        cout << node->val << " ";
        node=node->next;
    }
    cout << endl;
}

ListNode* swapPairs(ListNode* head) {
   if (!head || !head->next) return head;

    // Dummy node to handle the edge case for head swap
    ListNode dummy(0);
    dummy.next = head;
    ListNode* prev = &dummy;

    while (prev->next && prev->next->next) {
        ListNode* first = prev->next;
        ListNode* second = first->next;
        
        // Swapping nodes
        first->next = second->next;
        second->next = first;
        prev->next = second;
        
        // Move prev to next pair
        prev = first;
    }

    return dummy.next;
}
    
int main(){
    vector<int> nums = {1,2,3,4};
    
    // build list
    ListNode* nOde = buildList(nums);
    
    nOde = swapPairs(nOde);
    printList(nOde);
    return 0;
}