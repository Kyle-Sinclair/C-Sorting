
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <chrono> 
#include "util.h"

using namespace std;
using namespace chrono;

void BubbleSort(vector<int> array);

int main() {


    std::vector<int> example(200);

    std::generate(example.begin(), example.end(), RandomInt);
    cout << "Our pre-sorted vector looks like " << endl;

    printVector(example);
    auto start = high_resolution_clock::now(); 
    BubbleSort(example);
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 

    cout << "Bubble sort took "  << duration.count() << " microseconds" << endl; 

}



void BubbleSort(vector<int> toBeSorted){
    int indexOfLastUnsorted = toBeSorted.size();
    bool swapped = false;
    do{
        swapped = false;
        for(int i = 1; i < indexOfLastUnsorted; i++){
            if(toBeSorted[i - 1] > toBeSorted[i]){
                //cout << "calling swap with " << toBeSorted[i-1] << " and " << toBeSorted[i] << endl; 
                swapElements(toBeSorted[i-1],toBeSorted[i]);
                swapped = true;
            }
        }
        indexOfLastUnsorted--;
    }
    while(swapped);
    cout << " After sorting we are left with " << endl;
    printVector(toBeSorted);
}




