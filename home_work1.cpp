#include <iostream>
using namespace std;
class unsorted{
private:
int *arr;
int maxSize,currSize;
public:
unsorted(int n){
    maxSize=n;
    arr=new int[n];
    currSize=0;}

    unsorted(const unsorted &other){
        if(arr!=other.arr){
            maxSize=other.maxSize;
            arr=new int[maxSize];
            currSize=other.currSize;
            for(int i=0;i<maxSize;i++){
                arr[i]=other.arr[i];
            }
        }
}

unsorted operator=(const unsorted &other){
    if(arr!=other.arr){
        delete[]arr;
        maxSize=other.maxSize;
        currSize=other.currSize;
          for(int i=0;i<maxSize;i++){
                arr[i]=other.arr[i];
            }
    }
    return *this;
}
~unsorted(){
    if (arr!=nullptr){
        delete []arr;
        arr=nullptr;
    }
}
};