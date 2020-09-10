///Assignment 3
///Random number generator using LCM
/*
Name : Niaz Bin Siraj
ID: 1711176137
Session: 2016-17
RUCSE
*/


#include <bits/stdc++.h>
using namespace std;

vector<int> random_numbers;

void PrintOutput(int m);
void GenerateRandomNumbers(int n, int seed, int a, int c, int m);

int main()
{
    int n, seed, a, c, m;

    cout<<"Enter Total number of random numbers : ";
    cin>>n;
    cout<<"Enter seed (X0) : ";
    cin>>seed;
    cout<<"Enter Constant Multiplier (a) : ";
    cin>>a;
    cout<<"Enter Increment (c) : ";
    cin>>c;
    cout<<"Enter Modulus (m) : ";
    cin>>m;

    freopen("output3.txt", "a", stdout);

    GenerateRandomNumbers(n, seed, a, c, m);

    PrintOutput(m);

    return 0;
}

void GenerateRandomNumbers(int n, int seed, int a, int c, int m)
{
    random_numbers.push_back(seed);
    int rand;

    for(int i=1; i<n; i++)
    {
        rand = ((a*random_numbers[i-1])+c)%m;
        random_numbers.push_back(rand);
    }
    return;
}

void PrintOutput(int m)
{
    for(int i=0; i<random_numbers.size(); i++)
    {
        cout<<(double)random_numbers[i]/(double)m<<" ";
    }
}
