#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int arr[] = {1,2,3,8,6,5,1};
    sort(arr, arr + 7);
    for (int i = 0; i < 7; i++){
        cout << arr[i];
    }
}