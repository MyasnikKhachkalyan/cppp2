#include "polynomial.h"
int main( ){
    double pol[3] = {1.0,2.0,3.0} ;
    Polynomial pol1 = Polynomial(2, pol);
    double x;
    cin>>x;

    cout<<pol1.calculateValue(x)<<endl;

    return 0;
}