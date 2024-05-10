#include<bits/stdc++.h>
#include<iostream>
#include<cstring>
#include<cassert>
#include<array>
using namespace std;
struct A {
  char *b;
};
template <typename T,int s>
class Array 
{
public:
 
    T *arr=new T[s];


Array()
{

}

   Array(T arra[])
   {
     arr=arra;
   }
    Array(const T* arra)
   {
     arr=arra;
   }
   Array(int a,int b,int c,int d,int e)
   {
     
   }
   
   
   Array(uint32_t f,int a,int b,int c,int d,int e)
   {
     
   }
   T& operator[](int index)
{
    
    return arr[index];
}
 T& operator =(T index)
{
    arr=index.arr;
    //return arr[index];
    return arr;
}
/*T& operator =(Array index)
{
    for(int i=0;i<s;i++)
       arr[i]=index[i];
       
      return *this;
}*/

int size()
{
     return s;
}

void display()
{
   for(int i=0;i<s;i++)
       cout<<arr[i];
       
       cout<<endl;
  
}
Array<T,s>& operator+=(const Array<T,s>& classObj) {
    
    for(int i=0;i<s;i++)
    {
   	 arr[i]=arr[i]+classObj.arr[i];
    }
  return *this;
}
bool operator==(const Array<T,s>& classObj) {
    
    
 return true;
}
T *operator=(T *rhs)
{
    cout << "THIS\n";
     for(int i=0;i<s;i++)
    {
   	 arr[i]=rhs.arr[i];
    }
    //this->var = rhs->var;
    return this;
}
Array<T,s>& operator=(const T* rhs) 
{
    cout << "THIS\n";
     for(int i=0;i<s;i++)
    {
   	 arr[i]=rhs[i];
    }
    //this->var = rhs->var;
    return *this;
}
Array<T,s>& operator+(const Array<T,s>& classObj) {
    for(int i=0;i<s;i++)
    
   	 arr[i]=arr[i]+classObj.arr[i];
    
    return *this;
}
};
int main() 
{
uint32_t aray[]={1,2,3,4,5};
Array<uint32_t,5> arr1(aray);
Array<uint32_t, 5> arr0 ={1, 2, 3, 4, 5};
//arr0.display();
arr1[0] = 0;

assert(arr1[0] == 0);

uint32_t a[]={6,7,8,9,10};
Array<uint32_t, 5> arr2(a);
arr2.display();
Array<uint32_t, 5> arr3(aray);
arr3+=arr2;
arr3.display();
arr3=arr3+arr1;
arr3.display();
arr3 =arr1+arr2;
arr3=arr2=arr1;
assert(arr3.size() == 5);
assert((arr1 == Array<uint32_t, 5>{0, 2, 3, 4, 5}));
Array<uint32_t, 5> arr4;
arr4 = arr4+arr2 ;
assert((arr4 == Array<uint32_t, 5>{0, 2, 3, 4, 5}));
assert((arr2 == Array<uint32_t, 5>{0, 2, 3, 4, 5}));

return 0;
}






