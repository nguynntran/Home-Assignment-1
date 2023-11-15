#include <iostream>
using namespace std;

void Spiralmatrix(int n){
    int res[n][n];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            res[i][j] = 0;
        }
    }
    int left = 0, right = n - 1;
    int top = 0, bottom = n - 1;
    int val = 1;
    while ((left <= right) && (top <=bottom)){

        for (int c = left; c <= right ; c++){
            res[top][c] = val;
            val += 1;
        }
        top += 1;

        for (int r = top; r <= bottom; r++){
            res[r][right] = val;
            val += 1;
        }
        right -= 1;

        for (int c = right; c >= left; c--){
            res[bottom][c] = val;
            val += 1;
        }
        bottom -= 1;

        for (int r = bottom; r >= top; r--){
            res[r][left] = val;
            val += 1;
        }
        left += 1;
    }
    
     for (int i = 0; i < n; i++){
        cout << "[";
        for (int j = 0; j < n; j++){
            cout <<  res[i][j] <<" " ;
        }
        cout << "]" << endl;
    }
}
int main(){
    int n;
    cout << "The size of square matrix n x n: ";
    cin >> n;
    cout << "The result spiral matrix: "<<endl;
    Spiralmatrix(n);
    return 0;
}