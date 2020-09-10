///Assignment 5
///Test of the uniformity property of some generated random numbers
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
bool chiSquareTest(int n, int total);

int main()
{
    remove("randomNumbers.txt");
    remove("result.txt");

    int n; //Total number of random values
    int r; //range [0 <= r <= 999]
    int opt=0; //1 for LCM 2 for built in rand()
    int v=9; //degrees of freedom
    int k = v+1; //number of non overlapping classes

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

    if(chiSquareTest(r, n) == true) cout<<"ACCEPTED"<<endl;
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

bool chiSquareTest(int n, int total)
{
    freopen("randomNumbers.txt", "r", stdin);
    freopen("result.txt", "a", stdout);

    int v = 9;
    int k = v+1;

    int ei = total/k;
    int fifthColumn;
    double sixthCoulmn;
    double chi = 0.0;
    int oi[k+5];
    int num;

    MS(oi,0);
    for(int i=1; i<=total; i++)
    {
        cin>>num;
        oi[(int)ceil((k*(num+1))/(double)n)]++;
    }

    cout<<"i\tRange\t\tOi\tEi\t(Oi-Ei)^2\t(Oi-Ei)^2/Ei\n";
    cout<<"--------------------------------------------------------------------\n";

    for(int i=1; i<=k; i++)
    {
        fifthColumn = ((oi[i]-ei)*(oi[i]-ei));
        sixthCoulmn = (fifthColumn/(double)ei);
        chi += sixthCoulmn;

        printf("%d\t%d-%d\t\t%d\t%d\t%d\t\t%.2f\n", i, ((n*i)/k)-(n/k), ((n*i)/k)-1, oi[i], ei, fifthColumn, sixthCoulmn);
    }
    cout<<"--------------------------------------------------------------------\n";
    cout<<"Chi-Square value = "<<chi<<endl;
    if(chi>=1.73 && chi<= 23.6) return true;
    else return false;
}

