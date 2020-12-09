#include <vector>
#include <iostream>
#include "util.h"
using namespace std;

void printVector(const vector<int>& v){

    for(int i = 0; i < v.size(); i++){
         cout << v[i] << " ";
    }
    cout << endl;

}
void swapElements(int & a, int & b){
    //cout << "Swapping " << a << " with " << b << endl;
    int t = a;
    a = b;;
    b = t;
}

int RandomInt(){
    return 0 + rand() % (( 100 + 1 ));
}