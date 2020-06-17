#include <iostream>
using namespace std;

int main(){
    int array[] = {31,41,59,26,41,58};
    int size = *(&array + 1) - array; 
    for (int i=1; i < size; ++i){
        int key = array[i];
        int j = i-1;
        while (j>-1 && array[j] > key){
            array[j+1] = array [j];
            j--;
        }
        array[j+1] = key;
    }
    
    for (int i=0; i < size; ++i){
        cout << array[i] << ' ';
    }

    return 0;
}



/*
 int  arr[] = {1, 2, 3, 4, 5, 6}; 
    int size = *(&arr + 1) - arr; 
    cout << "Number of elements in arr[] is "
         << size; 
*/
