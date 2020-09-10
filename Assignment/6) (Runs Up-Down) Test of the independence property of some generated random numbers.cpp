///Assignment 6
///(Runs Up-Down) Test of the independence property of some generated random numbers
/*
Name : Niaz Bin Siraj
ID: 1711176137
Session: 2016-17
RUCSE
*/



#include <bits/stdc++.h>
using namespace std;
#define MS(XX,YY) memset(XX,YY, sizeof(XX))

void LCMRand(int n, int m);
void Rand(int n, int m);
bool RunUpAndDownTest(int n);

int main()
{
    remove("randomNumbers.txt");
    remove("result.txt");

    int n; //Total number of random values
    int r; //range [0 <= r <= 999]
    int opt=0; //1 for LCM 2 for built in rand()

    cout<<"Enter total number of random values : ";
    cin>>n;
    cout<<"Enter upper range of random values : ";
    cin>>r;

    while(opt != 1 && opt != 2)
    {
        cout<<"Enter 1 for LCM or 2 for built in Rand() : ";
        cin>>opt;
    }

    if(opt == 1) LCMRand(n, r+1);
    else if(opt == 2) Rand(n, r+1);

    if(RunUpAndDownTest(n) == true) cout<<"ACCEPTED"<<endl;
    else cout<<"NOT ACCEPTED"<<endl;

    return 0;
}

void LCMRand(int n, int m)
{
    int seed, a,c;
    cout<<"Enter seed (X0) : ";
    cin>>seed;
    cout<<"Enter Constant Multiplier (a) : ";
    cin>>a;
    cout<<"Enter Increment (c) : ";
    cin>>c;

    freopen("randomNumbers.txt", "a", stdout);

    int randNum = seed;
    cout<<randNum<<" ";

    for(int i=1; i<n; i++)
    {
        randNum = ((a*randNum)+c)%m;
        cout<<randNum<<" ";
    }
    return;
}

void Rand(int n, int m)
{
    freopen("randomNumbers.txt", "a", stdout);

    for(int i=0; i<n; i++)
    {
        cout<<rand()%m<<" ";
    }
    return;
}

bool RunUpAndDownTest(int n)
{
    freopen("randomNumbers.txt", "r", stdin);
    freopen("result.txt", "a", stdout);

    double mean;
    double variance;
    int a = 0; //total number of run
    double zo;
    string seq = "";
    char prev_sign = '*';
    char cur_sign = '*';
    int num1, num2;

    cin>>num1;
    for(int i=1; i<n; i++)
    {
        cin>>num2;

        if(num1<=num2) {seq+="+"; cur_sign = '+';}
        else {seq+="-"; cur_sign = '-';}

        if(prev_sign != cur_sign && prev_sign != '*') a++;

        num1 = num2;
        prev_sign = cur_sign;
    }

    mean = ((2*n)-1)/3.0;
    variance = ((16*n)-29)/90.0;
    zo = (a-mean)/variance;

    cout<<"Run Sequence\t:\t"<<seq<<endl;
    cout<<"Total run\t:\t"<<a<<endl;
    cout<<"Mean\t\t:\t"<<mean<<endl;
    cout<<"Variance\t:\t"<<variance<<endl;
    cout<<"Zo\t\t:\t"<<zo<<endl;

    if(-1.96 <= zo && zo <= 1.96) return true;
    else return false;
}

