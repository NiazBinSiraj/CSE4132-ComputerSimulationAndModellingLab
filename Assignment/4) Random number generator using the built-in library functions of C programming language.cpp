///Assignment 4
///Random number generator using the built-in library functions of C programming language
/*
Name : Niaz Bin Siraj
ID: 1711176137
Session: 2016-17
RUCSE
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter total number of random values : ";
    cin>>n;

    freopen("output4.txt", "a", stdout);

    for(int i=0; i<n; i++)
    {
        cout<<rand()<<endl;
    }

    return 0;
}
