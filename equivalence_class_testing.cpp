#include <iostream>
#include<time.h>
#include<limits>

using namespace std;
// function to check if three sides form a triangle or not
bool checkValidity(int a, int b, int c)
{
    // check condition
    if (a<=100 && a>=1 && b<=100 && b>=1 && c<=100 && c >= 1)
        return true;
    else
        return false;
}
bool IsTriangle(int a, int b, int c)
{
   if(a + b >= c || a + c >= b || b + c >= a) return true;
   else return false;
}
int main()
{
    int a , b, c;
    clock_t start;
    char ch = 'y';
    cout<<"\nEnter the value of Sides: ";
    do{
    start = clock();
    cout<<"\nA: ";
    while ( !( cin >> a ) ) {
    cin.clear();
    cin.ignore( 256, '\n' );
    cout<<"\nPlease input +ve integer [1,100]\nA: ";
    }
    cout<<"B: ";
    while ( !( cin >> b ) ) {
    cin.clear();
    cin.ignore( 256, '\n' );
    cout<<"\nPlease input +ve integer [1,100]\nB: ";
    }
    cout<<"C: ";
    while ( !( cin >> c ) ) {
    cin.clear();
    cin.ignore( 256, '\n' );
    cout<<"\nPlease input +ve integer [1,100]\nC: ";
    }
    if(checkValidity(a,b,c))
    {
        if(IsTriangle(a,b,c))
        {
            if((a==b) && (b==c))
              {
                cout<<"\nThe triangle is Equilateral";
              }
            else if((a==c) || (b==c) || (a==b) )
              {
                cout<<"\nThe triangle is Isosceles";
              }
            else if(a != b && b != c && c!= a)
              {
                cout<<"\nThe triangle is Scalene";
              }
        }
        else
            cout<<"\nNot a Triangle\n";
    }
    else
      cout<<"\n Invalid\n";
    start = clock()-start;
    cout<<"\nTime Taken : "<<(double)start/CLOCKS_PER_SEC<<endl;
    cout<<"Do you want to continue...?[y/n]";
    cin>>ch;
    }while(ch == 'y');
}
