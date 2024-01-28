#include <cstdlib> 
#include <iostream> 
using namespace std;

int main()
{
    //no limit any random no
    int no = rand();
    cout << no<<endl;
  
    // generate no between range of 0 to N-1

    int n=100;
    for(int i=0;i<5;i++)
        cout << (rand()%n)+1 << endl << endl;

    // a value from Upper_Bound to Lower_Bound.

    int lb = 20,ub=100;
    for(int i=0;i<5;i++)
        cout <<  (rand() % (ub-lb+1)) + lb << endl;

    return 0;
    

}