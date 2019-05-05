#include <iostream>
#include <string.h>
#include <string>
#include <cmath>
using namespace std;

int main( )
{   
    string datas[3];
    for(int i=0; i<3; i++){
        getline(std::cin, datas[i]);
    }
    double fares[3];
    double kilometers;
    cin>>kilometers;
    string::size_type loc;
    for(int i=0; i<3; i++){
       loc =  datas[i].find( " ", 0 );

       
       if(datas[i].substr(loc+1,loc+1).compare("NONE")==0){
           fares[i] = kilometers*stod(datas[i].substr(0,loc));
       }
       else if(datas[i].substr(loc+1,loc+1).compare("TIP")==1){
           fares[i] = kilometers*stod(datas[i].substr(0,loc)) + stod(datas[i].substr(loc+5));
       }
    }
    double minFare = fares[0];
    int index = 1;
    for(int i=1; i<3; i++){
        if(minFare>fares[i]){
            minFare = fares[i];
            index = i+1;
        }
    }
    cout<<minFare << " " << index << endl;
}    