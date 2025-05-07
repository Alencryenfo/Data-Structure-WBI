#include <iostream>
using namespace std;
void sort(int low ,int high){
    int mid;
    if (low<high)  {
        mid =(low+high)/2;
        sort(low,mid);
        sort(mid+1,high);
        merge(low,high);
    }
}
void merge(int low, int high){
    int mid =(low+high)/2;
    int i=low;
    int j=mid+1;
    int k=0;
    int temp[high-low+1];
    while (i<=mid && j<=high) {
        if (a[i]<a[j]) {
            temp[k++]=a[i++];
        } else {
            temp[k++]=a[j++];
        }
    }
    while (i<=mid) {
        temp[k++]=a[i++];
    }
    while (j<=high) {
        temp[k++]=a[j++];
    }
    for (int i=0; i<k; i++) {
        a[low+i]=temp[i];
    }
}