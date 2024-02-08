//Tower of Hanoi
/*
1. Place n-1 disks from-> spare (call function)
2. Place the 1 remaining disk from->to (statement, no function call)
3. Place the n-1 disks spare->to by calling function
*/
// from = A || to = C || spare  = B

# include <iostream>

using namespace std;

void tower_h(int n, char from, char to, char spare)
{
    if(n==1)
    {
        cout<<"Move disk "<<n <<" from "<<from<<" to "<<to<<endl;
    }

    else
   { tower_h(n-1,from,spare,to); //step 1  from->spare
    cout<<"Move disk"<<n<< " from "<<from << " to "<< to <<endl; //step 2   from->to
    tower_h(n-1,spare,to,from); // step 3   spare-> to
   }
}

int main()
{
    int n;
    char from,to,spare;
    cout<<"Enter the number of disks to be moved"<<endl;
    cin>>n;
    cout<<"Enter the name of pillars from, to and spare respectively"<<endl;
    cin>>from>>to>>spare;

    tower_h(n,from,to,spare);
}