///Assignment 7
///(Runs Above-Below) Test of the independence property of some generated random numbers
/*
Name : Niaz Bin Siraj
ID: 1711176137
Session: 2016-17
RUCSE
*/



#include <bits/stdc++.h>
using namespace std;
#define MS(XX,YY) memset(XX,YY, sizeof(XX))

double LCMRand(int n, int m);
double Rand(int n, int m);
bool RunAboveAndBellowTest(int n, double avg);

int main()
{
    remove("randomNumbers.txt");
    remove("result.txt");

    int n; //Total number of random values
    int r; //range [0 <= r <= 999]
    int opt=0; //1 for LCM 2 for built in rand()
    double avg;

    cout<<"Enter total number of random values : ";
    cin>>n;
    cout<<"Enter upper range of random values : ";
    cin>>r;

    while(opt != 1 && opt != 2)
    {
        cout<<"Enter 1 for LCM or 2 for built in Rand() : ";
        cin>>opt;
    }

    if(opt == 1) avg = LCMRand(n, r+1);
    else if(opt == 2) avg = Rand(n, r+1);

    if(RunAboveAndBellowTest(n, avg) == true) cout<<"ACCEPTED"<<endl;
    else cout<<"NOT ACCEPTED"<<endl;

    return 0;
}

double LCMRand(int n, int m)
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
    int sum = 0;
    cout<<randNum<<" ";

    for(int i=1; i<n; i++)
    {
        randNum = ((a*randNum)+c)%m;
        cout<<randNum<<" ";
        sum+=randNum;
    }
    return (double)sum/n;
}

double Rand(int n, int m)
{
    freopen("randomNumbers.txt", "a", stdout);

    int sum = 0;
    int num;

    for(int i=0; i<n; i++)
    {
        num = rand()%m;
        cout<<num<<" ";

        sum+=num;
    }
    return (double)sum/n;
}

bool RunAboveAndBellowTest(int n, double avg)
{
    freopen("randomNumbers.txt", "r", stdin);
    freopen("result.txt", "a", stdout);

    double mean;
    double variance;
    int b = 0; //total number of run
    double zo;
    string seq = "";
    char prev_sign = '*';
    char cur_sign = '*';
    int num;
    int n1 = 0;
    int n2 = 0;

    for(int i=0; i<n; i++)
    {
        cin>>num;

        if(num>=avg) {seq+="+"; cur_sign = '+'; n1++;}
        else {seq+="-"; cur_sign = '-'; n2++;}

        if(prev_sign != cur_sign && prev_sign != '*') b++;

        prev_sign = cur_sign;
    }

    mean = ((2.0*n1*n2)/n) + 0.5;
    variance = ((2.0*n1*n2)*((2.0*n1*n2)-n))/(n*n*(n-1.0));
    zo = (b-mean)/variance;

    cout<<"Run Sequence\t:\t"<<seq<<endl;
    cout<<"Average\t:\t"<<avg<<endl;
    cout<<"Total run\t:\t"<<b<<endl;
    cout<<"Above Avg.\t:\t"<<n1<<endl;
    cout<<"Bellow Avg.\t:\t"<<n2<<endl;
    cout<<"Mean\t\t:\t"<<mean<<endl;
    cout<<"Variance\t:\t"<<variance<<endl;
    cout<<"Zo\t\t:\t"<<zo<<endl;

    if(-1.96 <= zo && zo <= 1.96) return true;
    else return false;
}

