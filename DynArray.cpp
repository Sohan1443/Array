#include<iostream>
using namespace std;
class DynArray{
        int capacity;
        int lastIndex;
        int *ptr;
    public:
        DynArray(){
            ptr=NULL;
        }
        DynArray(DynArray &arr){
            capacity=arr.capacity;
            lastIndex=arr.lastIndex;
            if(ptr!=NULL)
                delete []ptr;
            ptr=new int[capacity];
            for(int i=0;i<=lastIndex;i++)
                ptr[i]=arr.ptr[i];
        }
        DynArray& operator =(DynArray &arr){
            capacity=arr.capacity;
            lastIndex=arr.lastIndex;
            if(ptr!=NULL)
                delete []ptr;
            ptr=new int [capacity];
            for(int i=0;i<=lastIndex;i++)
                ptr[i]=arr.ptr[i];            
        }
        void creatDynArray(int cap){
            capacity=cap;
            lastIndex=-1;
            if(ptr!=NULL)
                delete []ptr;
            ptr=new int [capacity];
        }
        bool isFull(){
            return lastIndex==capacity-1;
        }
        bool isEmpty(){
            return lastIndex=-1;
        }
        void append(int Data){
            if(isFull()){
                doubleArray();
            }
            lastIndex++;
            ptr[lastIndex]=Data;
        }
        void insert(int index,int Data){
            try{
                if(index<0||index>lastIndex)
                    throw 1;
                if(isFull())
                    doubleArray();
                for(int i=lastIndex;i>=index;i--)
                    ptr[i+1]=ptr[i];
                ptr[index]=Data;
            }
            catch(int i){
                cout<<"Invalid Index "<<endl;
            }
        }
        void del(int index ){
            try{
                if(index<0||index>lastIndex)
                    throw 1;
                for(int i=index;i<lastIndex;i++)
                    ptr[i]=ptr[i+1];
                lastIndex--;
                if(capacity>1 && lastIndex+1<=capacity/2)
                    halfArray();
            }
            catch(int c){
                cout<<"Invalid Index"<<endl;
            }
        }
        void edit(int index,int newData){
            try{
                if(index<0||index>lastIndex)
                    throw 1;
                ptr[index]=newData;
            }
            catch(int s){
                cout<<"Invlid Index"<<endl;
            }
        }
        int getcount(){
            return lastIndex+1;
        }
        int getcapacity(){
            return capacity;
        }
        int getItem(int index){
            try{
                if(index<0||index>lastIndex)
                    throw 1;
                return ptr[index];
            }
            catch(int s){
                cout<<"Invalid Index"<<endl;
            }
            return -1;
        }
        void doubleArray(){
            int *temp;
            temp=new int [capacity*2];
            for(int i=0;i<=lastIndex;i++)
                temp[i]=ptr[i];
            delete []ptr;
            ptr=temp;
            capacity*=2;
        }
        void halfArray(){
            int *temp;
            temp=new int[capacity/2];
            for(int i=0;i<=lastIndex;i++)
                temp[i]=ptr[i];
            delete []ptr;
            ptr=temp;
            capacity/=2;
        }

        ~DynArray(){
            delete []ptr;
        }
};

int main(){

}