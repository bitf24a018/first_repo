#include <iostream>
using namespace std;
class unsorted{
private:
int *arr;
int maxSize,currSize;
public:
unsorted(int n){
    if(n>0){
    maxSize=n;
    arr=new int[n];
    currSize=0;
}
}

    unsorted(const unsorted &other){
            maxSize=other.maxSize;
            arr=new int[maxSize];
            currSize=other.currSize;
            for(int i=0;i<currSize;i++){
                arr[i]=other.arr[i];
        }
}

unsorted& operator=(const unsorted &other){
    if(this!=&other){
        delete[]arr;
        maxSize=other.maxSize;
        currSize=other.currSize;
            arr=new int[maxSize];
          for(int i=0;i<currSize;i++){
                arr[i]=other.arr[i];
            }
    }
    return *this;
}
~unsorted(){

        delete []arr;
        arr=nullptr;
}
};