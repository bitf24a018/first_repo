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
bool isfull(){
    if(currSize==maxSize)return true;
    return false;
}
bool isEmpty(){
    if (currSize==0){return true;}
    return false;
}
bool insert(int val){
    if(isfull()) return false;
arr[currSize]=val;
currSize++;
return true;
}
void display(){
    if(isEmpty()){
        cout<<"List is Empty"<<endl;
    }
    else{
        for(int i=0;i<currSize-1;i++){
            cout<<arr[i]<<" ";
        }
    }
}

bool remove1(int index){//order is perserved
    if(index>=0&&index<=currSize){
        for(int i=index;i<currSize;i++){
            arr[i]=arr[i+1];
        }currSize--;
        return true;
    }
    else return false;
}
bool remove2(int index){ //order is not preserved
     if(index>=0&&index<=currSize){
        arr[index]=arr[currSize-1];
        currSize--;
        return true;
}else return false;
}
friend bool operator==(const unsorted& a, const unsorted& b);

int removeAll1(int val) {
    int occurrences = 0;

    for (int i = 0; i < currSize; i++) {
        if (arr[i] == val) {
            // shift left
            for (int j = i; j < currSize - 1; j++) {
                arr[j] = arr[j + 1];
            }
            currSize--;
            occurrences++;
            i--; // re-check current index
        }
    }
    return occurrences;
}

int removeAll2(int val) {
    int occurrences = 0;

    for (int i = 0; i < currSize; i++) {
        if (arr[i] == val) {
           arr[i]=arr[currSize-1]; 
            currSize--;
            occurrences++;
            i--;
        }
    }
    return occurrences;
}
int removeAll3(int val) {
    int write = 0;
    int occurrences = 0;

    for (int read = 0; read < currSize; read++) {
        if (arr[read] != val) {//not vale write it
            arr[write] = arr[read];
            write++;//move forward in write
        } else {
            occurrences++;//skip if value find not even remove it
        }
    }

    currSize = write;//fix size
    return occurrences;
}

};

bool operator==(const unsorted& a, const unsorted& b) {
    if (a.currSize != b.currSize)
        return false;

    for (int i = 0; i < a.currSize; i++) {
        if (a.arr[i] != b.arr[i])
            return false;
    }

    return true;
}
