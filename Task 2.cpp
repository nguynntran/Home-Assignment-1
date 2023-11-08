#include <iostream>
using namespace std;

void rectangleoverlap(int rec1[], int rec2[]){
    if ((rec2[0] >= rec1[2]) || (rec2[1] >= rec1[3]) || (rec1[0] >= rec2[2]) || (rec1[1] >= rec2[3])){
        cout <<"False";
    }
    else{
        cout <<"True";
}
}

int main(){
    int rec1[4], rec2[4];

    cout <<"Enter the coordinates of rectangle 1: "<< endl;
    for (int i = 0; i < 4; i++){
        cin >> rec1[i];
    }

    cout <<"Enter the coordinates of rectangle 2: "<< endl;
    for (int i = 0; i < 4; i++){
        cin >> rec2[i];
    }
    cout << "Two rectangles overlaps: ";
    rectangleoverlap(rec1, rec2);
    return 0;
}