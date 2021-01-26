
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <chrono> 
#include "util.h"

using namespace chrono;

void BubbleSort(vector<int> &array);
void SelectionSort(vector<int> &array);
void InsertionSort(vector<int> array);
template<typename Iter>
void MergeSort(Iter begin, Iter end);
template<typename Iter>
std::vector<typename Iter::value_type>  Merge(const Iter begin, const Iter mid, const Iter end);

int main() {

    srand(time(0));
    std::vector<int> example(50000);
    std::vector<int> sortStorage(5);

    //only used for storing values in mergesort so far

    std::generate(example.begin(), example.end(), RandomInt);
    //std::copy(std::begin(example), std::end(example), std::begin(sortStorage));

    cout << "Our pre-sorted vector looks like " << endl;
    printVector(example);

    auto start = high_resolution_clock::now(); 

    //BubbleSort(example);
    SelectionSort(example);
    //InsertionSort(example);
    /*MergeSort(std::begin(example),std::end(example));
      cout << "After the sort we are left with \n";
      printVector(example);*/

    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
    cout << "The sort took "  << duration.count() << " microseconds \n"; 


}
//11955515
void BubbleSort(vector<int> &toBeSorted){
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

void SelectionSort(vector<int> &toBeSorted){
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


template<typename I>
void MergeSort(I begin, I end){
    //In order to maintain templatability, I think auto has to be used here
    //cout << "called merge sort successfully \n";
    auto size = std::distance(begin, end);
    if (size < 2)
        return;

    auto mid = std::next(begin, size / 2);
    MergeSort(begin, mid);
    MergeSort(mid, end);

    auto &&v = Merge(begin, mid, end);
    std::move(v.cbegin(), v.cend(), begin);
}
template<typename Iter>
std::vector<typename Iter::value_type> Merge(const Iter begin, const Iter mid, const Iter end){
        //cout << "called merge successfully \n";
        std::vector<typename Iter::value_type> buffer;

        Iter left(begin);
        Iter right(mid);
        const Iter &left_end = mid; //by ref -> no copy
        const Iter &right_end = end;
        
        while (left != left_end && right != right_end) {
            buffer.push_back((*left <= *right) ? std::move(*left++) : std::move(*right++));
        }   

        buffer.insert(buffer.end(), left, left_end);    
        buffer.insert(buffer.end(), right, right_end);
    return buffer;
}