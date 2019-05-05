#pragma once
#include <iostream>
#include <cstdlib> //for exit
#include <cmath>
#include <array>


using namespace std;

class Polynomial
{
public:
    Polynomial();
   
    Polynomial(int maxPow, double* other);

   
    int getMaxPow();
    double* getCoefficients();
    double getCoefficient(int index);
    void setMaxPow(int num);
    void setCoefficient(int index, double coef);
    double calculateValue(int x);

    const Polynomial operator -(const Polynomial& poly1) ;

    const Polynomial operator +(const Polynomial& poly1) ;

    const Polynomial operator *(const Polynomial& poly1) ;

    const void operator =(const Polynomial& poly1)  ;

	const void operator +=(const Polynomial& poly1) ;
    const void operator -=(const Polynomial& poly1) ;

	const void operator *=(const Polynomial& poly1) ;  


private:
    double* poly = NULL;
    int maxPow;
};

// int main( ){
//     // double pol[3] = {1.0,2.0,3.0} ;
//     // Polynomial pol1 = Polynomial(2, pol);
//     // Polynomial pol2 = Polynomial(2, pol);
//     // Polynomial polS = pol1 + pol2;
//     // cout<<polS.getCoefficient(1)<<endl;

//     return 0;
// }
const Polynomial Polynomial:: operator +(const Polynomial& poly1) {
    int newMaxPow;
    double* newPoly;
    if(poly1.maxPow<maxPow){
        newMaxPow = maxPow;
        newPoly = new double [newMaxPow+1];
        for(int i=0; i<=newMaxPow; i++){
            if(i<=poly1.maxPow){
                newPoly[i] =  poly1.poly[i] + poly[i];
            }
            else{
                newPoly[i] = poly[i];
            }
        }
    }
    else{
        newMaxPow = poly1.maxPow;
        newPoly = new double [newMaxPow+1];
        for(int i=0; i<=newMaxPow; i++){
            if(i<=maxPow){
                newPoly[i] =  poly1.poly[i] + poly[i];
            }
            else{
                newPoly[i] = poly1.poly[i];
            }
        }
    }


    return Polynomial(newMaxPow, newPoly);   ///// [1,2,2,2]
                                            ////// [1,2,2,2]
}
const Polynomial Polynomial:: operator -(const Polynomial& poly1)
{
    int newMaxPow;
    double* newPoly =NULL;
    if(poly1.maxPow<maxPow){
        newMaxPow = maxPow;
        newPoly = new double [newMaxPow+1];
        for(int i=0; i<=newMaxPow; i++){
            if(i<=poly1.maxPow){
                newPoly[i] =  poly1.poly[i] - poly[i];
            }
            else{
                newPoly[i] = -poly[i];
            }
        }
    }
    else{
        newMaxPow = poly1.maxPow;
        newPoly = new double [newMaxPow+1];
        for(int i=0; i<=newMaxPow; i++){
            if(i<=maxPow){
                newPoly[i] =  poly1.poly[i] - poly[i];
            }
            else{
                newPoly[i] = poly1.poly[i];
            }
        }
    }


    return Polynomial(newMaxPow, newPoly);
}
const Polynomial Polynomial:: operator *(const Polynomial& poly1)
{
        int newMaxPow;
        double* newPoly;
		newMaxPow = maxPow + poly1.maxPow - 1;
		newPoly = new double[newMaxPow+1];

		for (int i = 0; i <= maxPow; i++)
			for (int j = 0; j <= poly1.maxPow; j++) 
				newPoly[newMaxPow - (i + j) ] += (poly[maxPow - i ] * poly1.poly[poly1.maxPow  - j ]);

		return Polynomial(newMaxPow, newPoly);
}
const void Polynomial:: operator =(const Polynomial& poly1)
{
		delete poly;
		poly = new double[poly1.maxPow + 1];
		maxPow = poly1.maxPow;
		for (int i = 0; i <= maxPow; i++)
			poly[i] = poly1.poly[i];
	}
const void Polynomial:: operator +=(const Polynomial& poly1)
{
		this-> operator= (this-> operator+ (poly1));
	}    
const void Polynomial:: operator -=(const Polynomial& poly1)
{
		this-> operator= (this-> operator- (poly1));
	}  
    const void Polynomial:: operator *=(const Polynomial& poly1)
{
		this-> operator= (this-> operator* (poly1));
	}  
Polynomial::Polynomial( ){

}

Polynomial::Polynomial(int num, double* other) {
    maxPow = num;
    poly = new double[num+1];
    for(int i=0; i<=maxPow; i++){
        poly[i] = other[i];
    }
    
}

int Polynomial::getMaxPow( ){
    return maxPow;
}

double* Polynomial::getCoefficients() {
    double toReturn [maxPow+1];
    for(int i=0; i<=maxPow; i++){
        toReturn[i] = poly[i];
    }
    return toReturn;
}

double Polynomial::getCoefficient(int index){
    if(index>=0 && index<=maxPow){
        return poly[index];
    }
    else{
        cout<<"invalid index of sides";
        exit(1);
    }
}

void Polynomial::setMaxPow(int num){
    if(num>=0){
        poly = new double[num];
    }
    else{
        cout<<"invalid num of sides";
        return;
    }
}

void Polynomial::setCoefficient(int index, double coef){
    if(index>=0 && index<=maxPow){
        poly[index] = coef;
    }
    else{
        cout<<"invalid index of sides";
        return;
    }
}    

double Polynomial::calculateValue(int x){
    double sum = 0;
    for(int i=0; i<=maxPow; i++){
        sum += pow(x, i)*poly[i];
    }
    return sum;
}  






