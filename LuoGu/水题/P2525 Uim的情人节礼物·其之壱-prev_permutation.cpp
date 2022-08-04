#include <iostream>
#include <algorithm>
using namespace std;
int n, *arr;
int main(){
    cin >> n;
    arr = new int[n];
    for(int i = 0; i < n; i++)  
        cin >> arr[i];
    if(prev_permutation(arr, arr + n)) 
        for(int i = 0;i < n; i++)
            cout << arr[i] << " ";
    else cout << "ERROR";  
    cout << endl;
    return 0;
}
