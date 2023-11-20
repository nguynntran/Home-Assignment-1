/*Task 3
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance 

You may return the answer in any order.

In the first line number of points N and k are given from the keyboard, after that goes N lines of points with x and y coordinate divided by a space
*/


#include <iostream>
#include <cmath>
using namespace std;

void swap(int& x, int& y){
    const int t = x;
    x = y;
    y = t;
}
// Create the function bubbleSort
void bubbleSort(float arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
 
        // If no two elements were swapped
        if (swapped == false)
            break;
    }
}
// Function to print result
void Euclid(int arr[][2], int n, int k){
    float ans[n];
    for (int i = 0; i < n; i++){
        ans[i] = sqrt(pow((arr[i][0]),2) + pow((arr[i][1]),2));
    }
    float temp[n];
    for (int i = 0; i < n; i++){
        temp[i] = ans[i];
    }
    bubbleSort(temp, n);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < k; j++){
            if (ans[i] == temp[j]){
                cout << arr[i][0] <<" "<< arr[i][1];
            }
        }
        cout << endl;
    }
}
int main(){
    int n,k;
    cout << "The number of points input: "<< endl;
    cin >> n;
    cout << "The number of points you want return: "<< endl;
    cin >> k;
    int arr[n][2];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 2; j++){
            cin >> arr[i][j];
        }
    }
    cout << "The " << k <<" point(s) near the origin: " << endl;
    Euclid(arr, n, k);
    return 0;

}