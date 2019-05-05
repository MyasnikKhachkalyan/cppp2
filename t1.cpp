#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void calculate(double x, int maxPow, double* poly){
    string xS;
    double sum = 0;
    for(int i=0; i<=maxPow; i++){
        sum += pow(x, i)*poly[i];
    }
    cout<<sum<<endl;
    getline(cin, xS);
    if(!xS.empty()){
        double x = stod(xS);
        calculate(x, maxPow, poly);
    }
}

int main( )
{   
    int maxPow;
    
    cout<< "write MaxPow of polynomial"<<endl;
    cin>>maxPow;
    double* poly = new double[maxPow+1];
    for (int j = 0; j <= maxPow; j++){

		cin >> poly[j];

    }
    string xS;
    getline(std::cin, xS);
    getline(std::cin, xS);
    if(!xS.empty()){
        double x = stod(xS);
        calculate(x, maxPow, poly);
    }
    else{
        for (int j = 0; j <= maxPow; j++){

		cout << poly[j]<<endl;

    }
        cout<<xS;
    }

}    