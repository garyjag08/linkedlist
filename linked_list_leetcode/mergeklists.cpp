#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;



struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {} 
};

ListNode* buildList(vector<int>& nums){
    ListNode* head = nullptr;
    ListNode* cur;
    for(auto& num : nums){
        if(head == nullptr){
            head = new ListNode(num);
            cur=head;
        } else{
            ListNode* newNode = new ListNode(num);
            cur->next=newNode;
            cur=cur->next;
        }
    }
    return head; 
}

struct compare{
    bool operator() (ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};


void printList(ListNode* head_node){
    while(head_node){
        cout << head_node->val << " ";
        head_node=head_node->next;
    }
    cout << endl; 
}
void createMinHeap(vector<ListNode*> lists){
    priority_queue<ListNode*, vector<ListNode*>, compare> pq(lists.begin(), lists.end());
    ListNode* head = nullptr;
    ListNode* cur;
    while(!pq.empty()){
        ListNode* min_node = pq.top();
        if(head == nullptr){
            head = pq.top();
            cur=head;
        } else{
            cur->next = pq.top();
            cur=cur->next;
        }
        pq.pop();
        if(min_node->next){
            pq.push(min_node->next);
        }
    }
    
    printList(head);
}


int main(){
    vector<ListNode*> nodes;
    vector<int> l1 = {1,6,9,12};
    vector<int> l2 = {2,3,5};
    vector<int> l3 = {7,10,11,15,19};
    
    
    ListNode* list1 = buildList(l1);
    ListNode* list2 = buildList(l2);
    ListNode* list3 = buildList(l3);
    
    nodes.push_back(list1);
    nodes.push_back(list2);
    nodes.push_back(list3);
    
    createMinHeap(nodes); 

    
    return 0;
}