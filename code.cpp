#include <iostream>
#include <cmath>
using namespace std;
float a=0 , b=0 , d=0;
long int c = 3 * pow(10,8);
double epso=8.8542*pow(10,-12);
double muo=4*M_PI*pow(10,-7);
double epsr=0;
double losstang=0;
double segma=0;
double fres (int m, int n,int l)
{
double fres = c*sqrt(pow(m/a,2)+pow(n/b,2)+pow(l/d,2))/(2*sqrt(epsr));
return fres;
}
double Qd (double losstang)
{
double Qd = 1/losstang ;
return Qd;
}
double QcTE10l (double f , float l)
{
double x = l/d;
double We = epsr*epso*0.25*pow(2*f*a*muo,2)*a*b*d;
double Rs = sqrt(M_PI*muo*f/segma);
double Pc = Rs*(pow(a*x,2)*(2*a*b+a*d)+2*b*d+a*d);
double Qc = 2*2*M_PI*f*We/Pc;
return Qc;
}
double QcTE011 (double f )
{
double x = 1/d;
double We = epsr*epso*0.25*pow(2*f*b*muo,2)*a*b*d;
double Rs = sqrt(M_PI*muo*f/segma);
double Pc = Rs*(pow(b*x,2)*(2*a*b+b*d)+2*a*d+b*d);
double Qc = 2*2*M_PI*f*We/Pc;
return Qc;
}
