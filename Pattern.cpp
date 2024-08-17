#include <iostream>
using namespace std;
int main()
{
    int n,k=1;
    cout<<"Enter number:";
    cin>>n;
    int res=n/2;
   for(int i=0;i<n;i++)
   {
       if(i<=res)
       {
           for(int j=0;j<=i;j++)
           {
               cout<<"*";
           }           
       }
         
       else
       {
           for(int j=res-k;j>=0;j--)
           {
               cout<<"*";
           }
           k++;
       }
     
       cout<<endl;
   }
    return 0;
}
