#include <iostream>
using namespace std;

// Create function to tranpose the matrix

int** transpose(int** arr, int row, int col){
    int** trans = new int* [col];
    for (int i = 0; i < col ; i++){
        trans[i] = new int [row];
    }
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++ ){
            trans[j][i] = arr[i][j];
        }
    }
    return trans;
}
// Create function to print matrix 
void printMat(int** arr, int row, int col){
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            cout << arr[i][j] <<" ";
        }
        cout << endl;
    }
}

int main(){
    int row, col;

    cout << "Input row: ";
    cin >> row;
    cout << "Input column: ";
    cin >> col;

    // Create the 2 dimensional dynamic array 
    int** a = new int* [row];
    for (int i = 0; i < row; i++){
        a[i] = new int [col];
    }

    // Input matrix
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++ ){
            cin >> a[i][j];
        }
    }

    cout << "Original Matrix: " << endl;
    printMat(a, row, col);

    // Tranpose the matrix
    int** trans = transpose(a, row, col);
    cout << "Transposed Matrix: " << endl;
    printMat(trans, col, row);

    // Delete the memory we don't use
    for (int i = 0; i < row ; i++){
        delete []trans[i];
    }
    delete []trans;

    for (int i = 0; i < row ; i++){
        delete []a[i];
    }
    delete []a;
    return 0;

}