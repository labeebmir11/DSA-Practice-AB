# include <iostream>

using namespace std;

class Array
{   
 private:   
    int *A;
    int length;
    int size;

public:
    Array()  // non parameterized constructor
    {
        size = 10;
        length = 0;
        A = new int[size];   
    }
    Array(int sz)   //parameterised constructor
    {
        size = sz;
        length = 0;
        A = new int[size];
    }
    ~Array()
    {
        delete[] A;
    }
    void Display();
    void Append(int x);
    int Insert(int x, int index);
    int Delete(int index);
    int LinearSearch(int key);
    int BinarySearch(int key);
    int RecursiveBinarySearch(int l, int h, int key);
    int Get(int index);
    void Set(int x, int index);
    int Max();
    int Min();
    int Sum();
    int rSum(int n);
    float Avg();
    void Reverse();
    void Reverse2();
    void InsertSort(int x);
    int isSorted();
    void Rearrange();
    Array* Merge(Array a2);
    Array* Union(Array a2);
    Array* Difference(Array a2);
    Array* Intersection(Array a2);
    void swap(int*x, int*y);
    
};

void Array:: Display()
{
    cout<<"Elements are"<<endl;
    for(int i= 0; i < length; i++)
        cout<<A[i]<<"  ";
}
void Array:: Append(int x)
{
    if(length < size)
    {
         A[length] = x;
         length++;
    }
}

int Array:: Insert(int x, int index)
{
    int i;
    if(index>=0 && index <=length)
    {
        for(i=length;i>index;i--)
            A[i]=A[i-1];
    A[index]=x;
    length++;

 }
}

int Array :: Delete(int index)
{
    int x=0;
 int i;

 if(index>=0 && index<length)
 {
    x=A[index];
    for(i=index;i<length-1;i++)
        A[i]=A[i+1];
    length--;
    return x;
 }
}
int Array::LinearSearch(int key)
{
 int i;
 for(i=0;i<length;i++)
 {
 if(key==A[i])
 {
 swap(&A[i],&A[0]);
 return i;
 }
 }
 return -1;
}
int Array::BinarySearch(int key)
{
 int l,mid,h;
 l=0;
 h=length-1;

 while(l<=h)
 {
    mid=(l+h)/2;
    if(key==A[mid])
        return mid;
    else if(key<A[mid])
       h=mid-1;
    else
        l=mid+1;
 }
 return -1;
}

int Array :: RecursiveBinarySearch(int l, int h, int key)
{
    if(l<=h)
    {
        int mid = (l + h)/2;
        if(key == A[mid]) return mid;

        else if(key < A[mid])
            return RecursiveBinarySearch(l, mid - 1, key);
        else if(key > A[mid])
            return RecursiveBinarySearch(mid+1,h,key);    
    }
    return -1;
}

int Array::Get(int index)
{
 if(index>=0 && index<length)
 return A[index];
 return -1;
}
void Array::Set(int index,int x)
{
 if(index>=0 && index< length)
 A[index]=x;
}
int Array::Max()
{
 int max=A[0];
 int i;
 for(i=1;i<length;i++)
 {
 if(A[i]>max)
 max=A[i];
 }
 return max;
}
int Array::Min()
{
 int min=A[0];
 int i;
 for(i=1;i<length;i++)
 {
 if(A[i]<min)
 min=A[i];
 }
 return min;
}
int Array::Sum()
{
 int s=0;
 int i;
 for(i=0;i<length;i++)
 s+=A[i];

 return s;
}

int Array :: rSum(int i)
{
    if(i < 0)
        return 0;
    else
        return A[i]+ rSum(i -1);    

}

void Array::Reverse()
{
 int *B;
 int i,j;

 B=new int[length];
 for(i=length-1,j=0;i>=0;i--,j++)
 B[j]=A[i];
 for(i=0;i<length;i++)
 A[i]=B[i];

}

void Array::Reverse2()
{
 int i,j;
 for(i=0,j= length-1;i<j;i++,j--)
 {
 swap(& A[i],& A[j]);
 }
}

void Array :: InsertSort(int x)
{
    int i = length - 1;
    if(length == size)
        return;
    while(i > 0 && A[i] > x) 
    {
        A[i+1] = A[i];
        i--;
    }   
    A[i+1] = x;
    length++;
}

int Array :: isSorted()
{
    int i;
    for(i=0;i<length-1;i++)
     {
        if(A[i]>A[i+1])
            return 0; // not sorted
    }
    return 1; //sorted
}
void Array :: Rearrange()
{   
    int i = 0;
    int j = length - 1;
    while(i < j)
    {
        while(A[i]< 0)i++;
        while(A[j]> 0)j--;

        if(i < j)
            swap(&A[i], &A[j]);

    }
}

Array* Array:: Merge(Array a2)
{
    int i = 0, j = 0,k = 0;
    Array *a3;
    a3 = new Array(length + a2.length);
    while(i < length && j < a2.length)
    {
        if(A[i] < a2.A[j])
            a3->A[k++] = A[i++];
        else if(a2.A[j] < A[i]) 
            a3->A[k++] = a2.A[j++];
    }
    for(  ;i < length; i++)
        a3->A[k++] = A[i];
    for(  ;j < a2.length; j++)
        a3->A[k++] = A[j]; 
    return a3;       
}
Array* Array:: Union(Array a2)
{
    int i = 0, j = 0,k = 0;
    Array *a3;
    a3 = new Array(length + a2.length);
    while(i < length && j < a2.length)
    {
        if(A[i] < a2.A[j])
            a3->A[k++] = A[i++];
        else if(a2.A[j] < A[i]) 
            a3->A[k++] = a2.A[j++];
        else if(A[i] == a2.A[j])
        {
            a3->A[k++] = A[i++];
            j++;
        }    
    }
    for(  ;i < length; i++)
        a3->A[k++] = A[i];
    for(  ;j < a2.length; j++)
        a3->A[k++] = A[j]; 
        a3->length = k;
    return a3;       
}
Array* Array:: Difference(Array a2)
{
    int i = 0, j = 0,k = 0;
    Array *a3;
    a3 = new Array(length + a2.length);
    while(i < length && j < a2.length)
    {
        if(A[i] < a2.A[j])
            a3->A[k++] = A[i++];
        else if(a2.A[j] < A[i]) 
            j++;
        else if(A[i] == a2.A[j])
        {
            i++;
            j++;
        }   
    }
    for(  ;i < length; i++)
        a3->A[k++] = A[i];
    a3->length = k;
    return a3;       
}
Array* Array:: Intersection(Array a2)
{
    int i = 0, j = 0,k = 0;
    Array *a3;
    a3 = new Array(length + a2.length);
    while(i < length && j < a2.length)
    {
        if(A[i] < a2.A[j])
           i++;
        else if(a2.A[j] < A[i]) 
            j++;
        else if(A[i] == a2.A[j])
        {
            a3->A[k++] = A[i++];
            j++;
            
        }   
    }
    
    a3->length = k;
    return a3;       
}





int main()
{
    Array *a1;
    int sz,ch, x,index;
    cout<<"Enter size of array"<<endl;
    cin>>sz;
    a1 = new Array(sz);

    do
 {
        cout<<"\n\nMenu\n";
        cout<<"1. Insert\n";
        cout<<"2. Delete\n";
        cout<<"3. Search\n";
        cout<<"4. Sum\n";
        cout<<"5. Display\n";
        cout<<"6.Exit\n";

        cout<<"enter you choice ";
        cin>>ch;

      switch(ch)
      {
        case 1: cout<<"Enter element you want to insert and index"<<endl;
                cin>>x>>index;
                a1->Insert(x,index);
                break;
        case 2: cout<<"Enter index"<<endl;
                cin>>index;
                a1->Delete(index);   
                cout<<"Deleted element is "<<x<<endl;
                break;
        case 3: cout<<"Enter key"<<endl;
                cin>>x;
                index = a1->LinearSearch(x);
                cout<<"Element index is "<<index<<endl;
                break;
        case 4: x = a1->Sum();
                cout<<"Sum is "<<x<<endl; 
                break;
        case 5: a1->Display();               

      }  
 }while(ch < 6);
 return 0;

}