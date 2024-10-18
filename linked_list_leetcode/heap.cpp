#include<iostream>
#include<vector>

using namespace std;

void heapify(int arrs[], int size, int i){
    int lc, rc, smallest;
    lc = 2*i + 1;
    rc = 2*i + 2;
    if(lc >= size || rc >= size) return;
    
    smallest = i;
    
    if(smallest < size && arrs[lc] < arrs[smallest])
        smallest = lc;
    if(smallest < size && arrs[rc] < arrs[smallest])
        smallest = rc;
        
    if(smallest != i){
        int temp = arrs[i];
        arrs[i] = arrs[smallest];
        arrs[smallest] = temp;
        
        // heapify the smallest sub tree
        heapify(arrs, size, smallest);
    }
    
}

int main(){
    int arrs[] = {11,2,9,13,3,25,17,1,90,57};
    //vector<int> arrs = {11,2,9,13,3,25,17,1,90,57};
    
    int size = sizeof(arrs) / sizeof(arrs[0]);
    //int size = arrs.size(); 
    
    cout << "Left child of 13 is: " << (arrs[2*3+1]) << endl;
    cout << "size is: " << size << endl; 
    
    for(int i = size/2; i >= 0; i--){
        heapify(arrs, size, i);
    }
    
    cout << "view the min heap" << endl;
    for(int j = 0; j < size; j++){
        cout << arrs[j] << " ";
    }
    cout << endl;
    
    return 0;
}