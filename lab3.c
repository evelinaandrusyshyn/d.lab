#include <math.h>
#include <iostream>
using namespace std;
int main() {
double n1=18, f1=1;
for(n1; n1>=1; n1--)
f1*=n1;
double n2=9, f2=1;
for(n2; n2>=1; n2--)
f2*=n2;
double n3=9, f3=1;
for(n3; n3>=1; n3--)
f3*=n3;
double C;
C=(f1/(f2*f3));
double res;
res=C*pow(2,9)*pow(2,9);
cout<<"res="<<res;
}
