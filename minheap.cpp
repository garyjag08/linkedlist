#include<iostream>

using namespace std;

void heap_and_child(int arr1[]){
    int lc, rc, sz;
    sz = sizeof(arr1);
    for(int i = 0; i < 15; i++){
        cout << arr1[i] << " left child: ";
        if((2*arr1[i])+1 <= 14){
            lc = (2*i) + 1;
            cout << arr1[lc] <<  " ";
        } else{
            cout << "no left child";
        }
        cout << " right child: ";
        if((2*i)+2 <= 14){
            rc = (2*i) + 2;
            cout << arr1[rc] << " ";
        } else{
            cout << "no right child";
        }
        cout << endl; 
    }
    
    
}


void min_heapify(int arr[]){
    
}
int main(){
    int heap[15] = {};
    for(int i = 0; i < 15; i++){
        heap[i] = i + 1;
    }

    
    heap_and_child(heap);
    
    return 0;
}