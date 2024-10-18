#include<iostream>
#include<queue>

using namespace std;
// for integer min heap
void show_pq(priority_queue<int, vector<int>, greater<int>> g){
    while(!g.empty()){
        cout << g.top() << " ";
        g.pop();
    }
}

void show_array(int* arr, int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl; 
}



int main(){
    int arr[] = {11,2,9,13,3,25,17,1,90,57};
    int size = 10;
    priority_queue<int, vector<int>, greater<int> > gquiz(arr, arr + size);
    
    show_pq(gquiz); 
    
    // show array
    show_array(arr, size);
    
    return 0;
}