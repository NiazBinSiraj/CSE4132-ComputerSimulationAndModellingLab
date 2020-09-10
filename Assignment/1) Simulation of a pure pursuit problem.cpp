///Assignment 1
///Simulation of a pure pursuit problem
/*
Name : Niaz Bin Siraj
ID: 1711176137
Session: 2016-17
RUCSE
*/

#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

#define X 631 //window width
#define Y 467 //window height
#define ck(XX) cout<<XX<<endl

struct Point{
    int x;
    int y;
};

void DrawAxis();
double CalculateDistance(Point p1, Point p2);
void DrawBomberPath(Point p1, Point p2);
Point DrawFighterPath(Point fighterPosition, Point bomberPosition, int fighterSpeed, double dist);

int main()
{
    //Taking Input From Screen
    int fighter_speed;
    cout<<"Enter Fighter Speed in kms/minute : ";
    cin>>fighter_speed;


    //Taking Input From File
    freopen("input1.txt", "r", stdin);

    int total_time;
    cin>>total_time;

    Point bomber_position[total_time+5];
    Point fighter_position;
    for(int i=0; i<total_time; i++) cin>>bomber_position[i].x>>bomber_position[i].y;
    cin>> fighter_position.x >> fighter_position.y;


    int gd = DETECT;
    int gm = DETECT;
    initgraph(&gd, &gm, "");
    setviewport(100,Y-100,X,1000, 0);

    DrawAxis();

    for(int i=0; i<total_time-1; i++)
    {
        //Checking if fighter can catch Bomber
        double dist = CalculateDistance(fighter_position, bomber_position[i]);

        if(dist <= 10.0)
        {
            cout<<"Time : "<<i<<endl;
            cout<<"Distance : "<<dist<<endl;
            break;
        }

        //Drawing Bomber Path
        setcolor(RED);
        DrawBomberPath(bomber_position[i], bomber_position[i+1]);

        //Drawing Fighter Path
        setcolor(BLUE);
        fighter_position = DrawFighterPath(fighter_position, bomber_position[i], fighter_speed, dist);

        delay(1000);

        //Checking if Bomber can escape
        if(i==11)
        {
            cout<<"Target Escaped"<<endl;
            break;
        }
    }

    getch();
    return 0;
}

void DrawAxis()
{
    line(0,100,0,-Y);
    line(-100,0,X,0);
    return;
}

double CalculateDistance(Point p1, Point p2)
{
    return sqrt((double)((p1.y - p2.y)*(p1.y - p2.y)) + (double)((p1.x - p2.x)*(p1.x - p2.x)));
}

void DrawBomberPath(Point p1, Point p2)
{
    line(p1.x, p1.y*(-1), p2.x, p2.y*(-1));
    return;
}

Point DrawFighterPath(Point fighterPosition, Point bomberPosition, int fighterSpeed, double dist)
{
    double sinTheta = (bomberPosition.y - fighterPosition.y)/dist;
    double cosTheta = (bomberPosition.x - fighterPosition.x)/dist;

    Point fighterDestination;
    fighterDestination.x = fighterPosition.x + fighterSpeed*cosTheta;
    fighterDestination.y = fighterPosition.y + fighterSpeed*sinTheta;

    line(fighterPosition.x, fighterPosition.y*(-1), fighterDestination.x, fighterDestination.y*(-1));


    return fighterDestination;
}
