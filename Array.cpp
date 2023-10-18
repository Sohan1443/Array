#include<iostream>
#include<stdio.h>
using namespace std;
class Array{
        int *ptr;
        int capacity;
        int lastIndex;
    public:
        Array();
        Array(Array &);
        Array & operator=(Array &);
        void createArray(int);
        bool isEmpty();
        bool isFull();
        void insert(int,int);
        void append(int);
        int getItem(int);
        void del(int);
        int count();
        int getCapacity();
};
Array::Array(){
    ptr=NULL;
}
Array::Array(Array &arr){
    capacity=arr.capacity;
    lastIndex=arr.lastIndex;
    if(ptr!=NULL)
        delete []ptr;
    ptr=new int[capacity];
    for(int i=0;i<=lastIndex;i++)
            ptr[i]=arr.ptr[i];

}
Array& Array::operator=(Array &arr){
    capacity=arr.capacity;
    lastIndex=arr.lastIndex;
    if(ptr!=NULL)
        delete []ptr;
    ptr=new int[capacity];
    for(int i=0;i<=lastIndex;i++)
        ptr[i]=arr.ptr[i];
    return (*this);

}
void Array::createArray(int size){
    capacity=size;
    lastIndex=-1;
    if(ptr!=NULL)
        delete []ptr;
    ptr=new int[capacity];
}

bool Array:: isEmpty(){
    return lastIndex==-1;
}
bool Array::isFull(){
    return lastIndex==capacity-1;
}
void Array::append(int data){
    if(!isFull()){
        lastIndex++;
        ptr[lastIndex]=data;
    }
    else
        cout<<"\nOverflow: Append is not Performed"<<endl;
}
void Array::insert(int index,int newData){
    try{
        if(index<0||index>lastIndex)
            throw 1;
        if(isFull())
            throw 2;
        for(int i=lastIndex;i>=index;i--)
            ptr[i+1]=ptr[i];
        ptr[index]=newData;
    }
    catch(int e){
        if(e==1)
            cout<<"\nInvalid Index"<<endl;
        if(e==2)
            cout<<"\nOverflow"<<endl;
    }
}
int Array::getItem(int index){
    try{
        if(index<0||index<lastIndex)
            throw 1;
        return ptr[index];
    }
    catch(int e){
        cout<<"\n Invalid Index or Array is Empty"<<endl;
    }
}
void Array:: del(int index){
    try{
        if(index<0||index>lastIndex)
            throw 1;
        for(int i=index;i<lastIndex;i++)
            ptr[i]=ptr[i+1];
        lastIndex--;
    }
    catch(int a){
        cout<<"\nInvalid Index or Array is Empty"<<endl;
    }
}
int Array::getCapacity(){
    return capacity;
}
int Array::count(){
    return lastIndex+1;
}
int main(){

}