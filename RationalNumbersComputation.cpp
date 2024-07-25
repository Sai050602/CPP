#include<bits/stdc++.h>
using namespace std;
class Rational
{
  int numerator;
  int denominator;
  
  public:
    Rational(int n=0, int d=1)
    {
        numerator=n;
        denominator=d;
    }
    friend Rational operator+(Rational rk1, Rational rk2);//friend operator overloading
    friend ostream & operator<<(ostream &out, Rational &rk);
    
};
Rational operator+(Rational rk1, Rational rk2)
{
    Rational temp;
    if (rk1.denominator == rk2.denominator)
    {
        temp.numerator = rk1.numerator+rk2.numerator;
        temp.denominator=rk1.denominator;
    }
    else
    {
        int max;
        
        if(rk1.denominator>rk2.denominator)
            max = rk1.denominator;
        else
            max = rk2.denominator;
        
        int arr[max]={0}; 
        int j=0;
        int length=0;
        for(int i=2;i<=max;i++)
        {
            if(rk1.denominator%i==0 && rk2.denominator%i==0)
            {
                arr[j]=i;
                j++;
            }
            
        }
        for(auto hk:arr)
        {
            if(hk>0)
                length+=1;
        }
        
        int factor1 = rk1.denominator/arr[length-1]; //arr[length-1] will give the highest common factor
        int factor2 = rk2.denominator/arr[length-1];
        
        temp.numerator = (rk1.numerator*factor2)+(rk2.numerator*factor1);
        temp.denominator = arr[length-1]*factor1*factor2;
        
    }
    return temp;
}
//insertion operator overloading
ostream & operator<<(ostream &out, Rational &rk)    
{
    out<<rk.numerator<<"/"<<rk.denominator;
    return out;
}
int main()
{
    Rational rk1(4,248), rk2(3,24), rk3;
    rk3 = rk1+rk2;
    cout<<"The sum of "<<rk1; //insertion operator can only take 2 arguments (cout, rk)
    cout<<" and "<<rk2;
    cout<<" is "<<rk3;
    return 0;
}
