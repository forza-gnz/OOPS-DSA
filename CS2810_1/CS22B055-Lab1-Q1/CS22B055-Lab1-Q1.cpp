// Roll Number: CS22B055
// Name: Neeraj Bandhey
// CS2810 Lab Number: 1
// Date: 23 Jan, 2024, 2pm
// Question No. 1 (2, etc. as appropriate)
// This submission is based entirely on my efforts. I realize that
// any form of academic dishonesty with respect to the Lab assignment
// will result in
// corrective action imposed by the IIT Madras Senate.

#include<bits/stdc++.h>
using namespace std;

class ComplexNum{
    private:
    double real;
    double imag;

    public:
    
    ComplexNum(){ //constructors
        real = 0;
        imag = 0;
    }

    ComplexNum(double a){ //construct
        real = a;
        imag = 0;
    }

    ComplexNum(double a, double b){ //construct
        real = a;
        imag = b;
    }

    ComplexNum(const ComplexNum& C1){ //consturct
        real = C1.real;
        imag = C1.imag;
    }

    ComplexNum operator+ (ComplexNum C2){
        ComplexNum C3;
        C3.real = real + C2.real;
        C3.imag = imag + C2.imag;

        return C3;
    }

    ComplexNum operator- (ComplexNum C2){
        ComplexNum C3;
        C3.real = real - C2.real;
        C3.imag = imag - C2.imag;

        return C3;
    }

    ComplexNum operator*(ComplexNum C2){
        ComplexNum C3;
        C3.real = real*(C2.real) - imag*(C2.imag);
        C3.imag = C2.imag*real + C2.real*imag;

        return C3;
    }

    ComplexNum operator/ (ComplexNum C2){
        double a1 = real;
        double b1 = imag;
        double a2 = C2.real;
        double b2 = C2.imag;
        
        if(C2.real == 0 && C2.imag == 0){
            ComplexNum C3(1,1);
            return C3;
        }

        else{
            ComplexNum C3;
            C3.real = ((a1*a2 + b1*b2)/(a2*a2 + b2*b2));
            C3.imag = ((b1*a2 - a1*b2)/(a2*a2 + b2*b2));
            return C3;
        }
    }

    int rreal(){ // to get the floor value 
        return real;
    }
    int rimag(){ // to get the floor value
        return imag;
    }

    friend ostream& operator<< ( ostream& os, const ComplexNum C1){
       os << C1.real << std:: showpos << C1.imag;
       return os;
    }
    // standrad Code
};

int main(){
   vector<ComplexNum> List; 
   int n;
   cin>>n;

   for(int i=0;i<n;i++){
     int a,b;
     cin>>a>>b;
     ComplexNum C(a,b);
     List.push_back(C);
   }

   int q;
   cin>>q;
   for(int x=0;x<q;x++){
    string s;
    cin>>s;

    if(s=="a"){
        int i,j,k;
        cin>>i>>j>>k;
        List[k] = List[i].operator+(List[j]);
    }
    if(s=="s"){
        int i,j,k;
        cin>>i>>j>>k;

        List[k] = List[i].operator-(List[j]);
    }

    if(s=="m"){
        int i,j,k;
        cin>>i>>j>>k;

        List[k] = List[i].operator*(List[j]);
    }

    if(s=="d"){
        int i,j,k;
        cin>>i>>j>>k;

        List[k] = List[i].operator/(List[j]);
    }
    if(s=="p"){
        int i;
        cin>>i;

        cout<<int(List[i].rreal())<<" "<<(List[i].rimag())<<endl;
    }
  }
}