#include <iostream>
#include <fstream>
#include "point.h"

using namespace std;

int main()
{
    // int n;
    // cout << "How many points you want to create? ";
    // cin >> n;
    // Point *pts = new Point[n];
    // int x, y;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << "Enter coordinates of point " << i + 1 << ": ";
    //     cin >> x;
    //     cin.ignore();
    //     cin >> y;

    //     pts[i].setCoordinates(x, y);
    // }

    // for (int i = 0; i < n; i++)
    // {
    //     pts[i].displayPoint();
    // }

    // ofstream fout;
    // fout.open("Points.txt");
    // if (!fout)
    // {
    //     cout << "ERROR: File could not be open\n";
    // }
    // else
    // {
    //     fout<<n<<endl;
    //     for (int i = 0; i < n; i++)
    //     {
    //     //    int val1= pts[i].getX();
    //     //    int val2= pts[i].getY();
    //     //    fout<<val1<<" "<<val2<<endl;
    //     pts[i].writeToFile(fout);
    //     }
    //     fout.close();
    // }
    // /*
    // 3
    // (10, 20)
    // (30, 40)
    // (50, 60)
    // */


    // delete[] pts;
    // pts = nullptr;
    ifstream fin;
    fin.open("Points.txt");
    if(!fin)
    {
        cout<<"ERROR!!!"<<endl;
    }
    else{
        int numPoints;
        fin>>numPoints;
        Point* points=new Point[numPoints];
        for (int i = 0; i < numPoints; i++)
        {
            // int x,y;
            // fin>>x>>y;
            // points->setCoordinates(x,y);
            points[i].readFromfile(fin);
        }
        fin.close();
        for (int i = 0; i < numPoints; i++)
        {
            points[i].displayPoint();   
        }
        delete[] points;
        points=nullptr;
    }
    return 0;
}