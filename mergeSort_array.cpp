#include <iostream>
using namespace std;

void merge_sort(int arr[], int start, int end);
void merge(int arr[], int start, int mid, int end);
int main(){
    int array[] = {31,41,59,26,27,41,58};  
    int size = *(&array+1) - array;
    merge_sort(array, 0, size-1);

    for (int i=0; i < size; ++i){
        cout << array[i] << ' ';
    }    
    return 0;
}

void merge_sort(int arr[],int start ,int end){
    int mid = (end+start)/2;
    if(start < end){
        merge_sort(arr, start, mid);
        merge_sort(arr, 1+mid, end);
    }
    merge(arr, start, mid ,end);
}

void merge(int arr[], int start, int mid, int end){
    int n1 = mid - start + 1 ;
    int n2 = end - mid;
    int left[n1+1] = {};
    int right[n2+1] = {};
    cout << start << ' ' << mid <<' ' << end << endl;

    cout << "l " ;
    for (int i = 0; i < n1; ++i){
        left[i] = arr[start+i];
        cout << left[i] << ' ';
    }
    cout << endl;
    cout << "r ";
    for (int i = 0; i < n2; ++i){
        right[i] = arr[mid+i+1];
        cout << right[i] << ' ';
    }
    cout << endl;
    left[n1] = 99999;
    right[n2] = 99999;
    int x=0;
    int y=0;
    for (int a = start; a<end+1; ++a){
        if (left[x] < right[y]){
            arr[a] = left[x];
            ++x;
        }else{
            arr[a] = right[y];
            ++y;
        }
    }

    for (int a = 0; a<6; ++a){
        cout << arr[a] <<' ';
    }
    cout << endl;

}