/*Task 5
You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.

Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).

Note: You cannot rotate an envelope.
*/

#include <iostream>
using namespace std;

void swap(int& a, int& b){
    int t = a;
    a = b;
    b = t;
}

void Change(int** arr, int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (arr[j][0] > arr[j + 1][0]){
                for (int k = 0; k < 2; k++){
                    swap(arr[j][k], arr[j + 1][k]);
                }
            }
        }
    }
}

int Russiandoll(int** arr, int n){
    if (n == 0){
        return 0;
    }

    Change(arr,n);

    int res = 1;
    int maxHeight = arr[0][1];    

    for (int i = 0; i < n; i++){
        if (arr[i][1] > maxHeight){
            res++;
            maxHeight = arr[i][1];
        }
    }

    return res;
}

int main(){
    int n;
    cout <<"The number of input: "<< endl;
    cin >> n;
    int** arr = new int* [n];
    for (int i = 0; i < n; i++){
        arr[i] = new int [2];
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 2; j++ ){
            cin >> arr[i][j];
        }
    }
    int result = Russiandoll(arr, n);

    cout << "Maximum number of envelopes that can be Russian doll: " << result;

    for (int i = 0; i < n ; i++){
        delete []arr[i];
    }
    delete []arr;
    return 0;    
}