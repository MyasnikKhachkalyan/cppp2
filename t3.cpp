#include <iostream>
#include <math.h>
using namespace std;

struct Circle
{
int radius;
double computeCirc(int r){
    return 2*M_PI*r;
}
double computeArea(int r){
    return M_PI*r*r;
}
};
int main( )
{
    Circle c;
    cin >> c.radius;
    cout << c.computeCirc(c.radius) << endl
        << c.computeArea(c.radius);
}    