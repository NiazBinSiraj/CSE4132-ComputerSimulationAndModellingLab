///Assignment 2
///Simulation of a chemical reactor
/*
Name : Niaz Bin Siraj
ID: 1711176137
Session: 2016-17
RUCSE
*/


#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;
#define ck(XX) cout<<XX<<endl;
#define X 631 //window width
#define Y 467 //window height

#define gx 500.0 //Graph width
#define gy 350.0 //Graph height


void PrintOutput(vector<double> A, vector<double> B, vector<double> C, double T, double dt);
double FindMax(vector<double> A, vector<double> B, vector<double> C, int N);
void PlotData(vector<double> A, vector<double> B, vector<double> C, double T, double dt);
void DrawAxisScale(double sx, double sy);
void DrawAxis();
void LabelGraph();
void DrawRightArrow();
void DrawUpArrow();

int main()
{
    freopen("input2.txt", "r", stdin);

    double k1,k2,T,dt;
    int N;
    vector <double> A,B,C;
    double temp;


    //cout<<"Enter k1 : ";
    cin>>k1;
    //cout<<"Enter k2 : ";
    cin>>k2;
    //cout<<"Enter a(0) : ";
    cin>>temp;
    A.push_back(temp);
    //cout<<"Enter b(0) : ";
    cin>>temp;
    B.push_back(temp);
    C.push_back(0);
    //cout<<"Enter T : ";
    cin>>T;
    //cout<<"Enter dt : ";
    cin>>dt;

    N = T/dt;

    for(int i=1; i<= N+1; i++)
    {
        A.push_back(A[i-1]+((k2*C[i-1] - (k1*A[i-1]*B[i-1]))*dt));

        B.push_back(B[i-1]+((k2*C[i-1] - (k1*A[i-1]*B[i-1]))*dt));
        C.push_back(C[i-1]+(((2*k1*A[i-1]*B[i-1]) - 2*k2*C[i-1])*dt));
    }


    PrintOutput(A,B,C,T,dt);


    //Plotting

    int gd = DETECT;
    int gm = DETECT;
    initgraph(&gd, &gm, "");
    setviewport(100,Y-100,X,1000, 0);

    DrawAxis();
    LabelGraph();
    PlotData(A,B,C,T,dt);

    getch();
    return 0;
}

void PrintOutput(vector<double> A, vector<double> B, vector<double> C, double T, double dt)
{
    printf("------------------------------------------------------------------\n");
    printf(" |\tTIME\t    A(I)\t    B(I)\t    C(I)\t|\n");
    printf("------------------------------------------------------------------\n");

    int N = T/dt;
    double j = 0;
    for(int i=0; i<=N+1; i++, j+=dt)
    {
        printf(" |\t%.2f\t    %.2f\t    %.2f\t    %.2f\t|\n", j, A[i], B[i], C[i]);
    }

    printf("------------------------------------------------------------------\n");
}

void DrawAxis()
{
    setcolor(WHITE);
    line(0,100,0,-Y);
    line(-100,0,X,0);
    return;
}

void LabelGraph()
{
    setcolor(RED);
    setfillstyle(SOLID_FILL, RED);
    rectangle(30, 70, 40, 80);
    floodfill(35,75,RED);

    settextstyle(2, HORIZ_DIR, 5);
    setcolor(WHITE);
    outtextxy(50,70, "A");

    setcolor(GREEN);
    setfillstyle(SOLID_FILL, GREEN);
    rectangle(200, 70, 210, 80);
    floodfill(205,75,GREEN);

    setcolor(WHITE);
    outtextxy(220,70, "B");

    setcolor(BLUE);
    setfillstyle(SOLID_FILL, BLUE);
    rectangle(370, 70, 380, 80);
    floodfill(375,75,BLUE);

    setcolor(WHITE);
    outtextxy(390,70, "C");

    DrawRightArrow();
    outtextxy(260,28, "Time (T)");
    DrawUpArrow();
    outtextxy(-75,-220, "Quantities");

    setcolor(WHITE);
    outtextxy(5,5,"0");
    outtextxy(-10,-17,"0");

    line(500,5,500,-5);
    line(5,-350,-5,-350);
}

void DrawRightArrow()
{
    setcolor(WHITE);
    line(210,35, 250, 35);
    line(250,35, 240,30);
    line(250,35, 240,40);
}

void DrawUpArrow()
{
    setcolor(WHITE);
    line(-50, -160, -50, -200);
    line(-50, -200, -55, -190);
    line(-50, -200, -45, -190);
}

void PlotData(vector<double> A, vector<double> B, vector<double> C, double T, double dt)
{
    int N = T/dt;
    double sx = gx/N; //Scaling factor for x
    double mx = FindMax(A,B,C,N);
    double sy = -(gy/mx); //Scaling factor for y

    setcolor(WHITE);
    char str[10];
    sprintf(str, "%.1f", T);
    outtextxy(493,7,str);
    sprintf(str, "%.2f", mx);
    outtextxy(-40,-355, str);

    DrawAxisScale((gx/T), sy);

    for(int i=1; i<= N; i++)
    {
        setcolor(RED);
        line((i-1)*sx,A[i-1]*sy,i*sx,A[i]*sy);
        setcolor(GREEN);
        line((i-1)*sx,B[i-1]*sy,i*sx,B[i]*sy);
        setcolor(BLUE);
        line((i-1)*sx,C[i-1]*sy,i*sx,C[i]*sy);

        delay(100);
    }
    return;
}

double FindMax(vector<double> A, vector<double> B, vector<double> C, int N)
{
    double mx = 0;
    for(int i=0; i<=N; i++)
    {
        mx = max(mx,A[i]);
        mx = max(mx,B[i]);
        mx = max(mx,C[i]);
    }

    return mx;
}

void DrawAxisScale(double sx, double sy)
{
    setcolor(WHITE);
    char str[10];
    for(int i=50; i<(int)gx; i+=50)
    {
        line(i,5,i,-5);
        sprintf(str, "%.2f", (i/sx));
        outtextxy(i-10,7,str);
    }

    for(int i=50; i<(int)gy; i+=50)
    {
        line(5,-i,-5,-i);
        sprintf(str, "%.2f", -(i/sy));
        outtextxy(-40,-i, str);
    }
}
