
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
void SelectionSort(vector<int> array);
void InsertionSort(vector<int> array);

int main() {

    srand(time(0));
    std::vector<int> example(200);

    std::generate(example.begin(), example.end(), RandomInt);
    cout << "Our pre-sorted vector looks like " << endl;

    printVector(example);
    auto start = high_resolution_clock::now(); 
    //BubbleSort(example);
    //SelectionSort(example);
    InsertionSort(example);
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 

    cout << "The sort took "  << duration.count() << " microseconds" << endl; 

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

void SelectionSort(vector<int> toBeSorted){
    int min,j;

    for( int i = 0; i < toBeSorted.size(); i++){
        min = i;
        for(j = i + 1; j < toBeSorted.size(); j++){
            if(toBeSorted[j] < toBeSorted[min]){
                min = j;
            }
        }
        if(min != i){
            swapElements(toBeSorted[i],toBeSorted[min]);
        }
    }
    cout << " After selection sorting we are left with " << endl;
    printVector(toBeSorted);
}

void InsertionSort(vector<int> toBeSorted){
    int j;

    for (int i = 1; i < toBeSorted.size(); i++){
        j = i;
       while(j > 0){
           if(toBeSorted[j-1] > toBeSorted[j]){
               swapElements(toBeSorted[j-1], toBeSorted[j]);
           }
           j--;
       }

    }
    cout << " After insertion sorting we are left with " << endl;
    printVector(toBeSorted);

}




