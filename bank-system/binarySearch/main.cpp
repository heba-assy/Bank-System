#include <iostream>

using namespace std;

int biSearch(int arr[], int size, int targetValue){
    int x=0,y=size-1;
    while(x<=y){
        int z=(x+y)/2;

        if(arr[z]==targetValue){
            return z;
        }
        else if(arr[z]<targetValue){
            return x=z+1;
        }
        else{
            y=z-1;
        }
    }
    return -1;
}
bool binarySearchRec(vector<int>items,int value,int start,int end){
        if(start>end){
            return false;
        }
        int mid = (start+end)/2;
        if(items[mid]==value)return true;
        if(value>items[mid]){
            start = mid+1;
        }else{
            end = mid-1;
        }
        return binarySearchRec(items,value,start,end);
}
//===========Bubble Sorting==========
void sort(vector<int>arr){
    for(int i=0; i<arr.size()-1; i++) {
        bool x = false;
        for (int j=0; j<arr.size()-i-1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j],arr[j + 1]);
                x=true;
            }
        }
        if (!x) break;
    }
}
//========Insertion Sorting=========
void insertionSort(vector<int>& arr) {
    for (int i=1; i<arr.size(); i++) {
         int nextValue=arr[i];
         int j=i-1;

        while(arr[j]>nextValue) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = nextValue;
    }
}
int main()
{
    int arr[]={5,3,8,7,6,9,2,10};
    int targetValue = 35;

    return 0;
}
