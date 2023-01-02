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

double QcTM110 (double f)
{
double Rs = sqrt(M_PI*1.256637061*pow(10,-6)*f/segma);
long double Wm = 0.0625*1.256637061*pow(10,-6)*a*b*d;
long double Pc = 0.5*Rs*(1/2 * pow(2*M_PI*f,2)*1.112650056 * pow(10,-17)*epsr*a*b +
a*d*M_PI*M_PI/(b*b) + b*d *M_PI*M_PI/(a*a));
double Qc = 2*2*M_PI*f*Wm/Pc;
return Qc;
}
double BW (double Qc ,double Qd)
{
double BW =(1/Qc)+(1/Qd);
return BW;
}
double Qo (double BW)
{
double Qo = 1/BW;
return Qo;
}

int main()
{
cout<<" Please enter the WG cavity resonator dimensions in meters that follow the conidtion
b<a<=d:"<<endl;
cout<<"a=";
cin>>a;
cout<<"b=";
cin>>b;
cout<<"d=";
cin>>d;
if (a>d||b>a)
{
cout <<" Please enter available dimensions " <<endl;
cout<<"a = "; cin>>a;
cout<<"b = "; cin>>b;
cout<<"d = "; cin>>d;
}
cout<<" Please enter the loss tangent , relative permittivity and metal conductivity "<<endl;
cout<<"loss tangent = ";
cin>>losstang;
cout<<"relative permittivity =";
cin>>epsr;
cout<<"metal conductivity =";
cin>>segma;
if (sqrt((1/b)*(1/b) + (1/d)*(1/d)) > sqrt((1/a)*(1/a) + (2/d)*(2/d)))
{
double QD = Qd(losstang);
double freson1 = fres(1,0,1);
double QC1 = QcTE10l(freson1 , 1);
double BWres1 = BW(QC1,QD);
double QO1 = Qo(BWres1);
double freson2 = fres(1,0,2);
double QC2 = QcTE10l(freson2 , 2);
double BWres2 = BW(QC2,QD);
double QO2 = Qo(BWres2);
if(a==d)
cout<<" The first 2 resonance frequencyies are : TE101 & TE102 or TE201 "<<endl;
else
cout<<" The first 2 resonance frequencyies are : TE101 & TE102 "<<endl;
cout<<" The first resonant frequency = "<<freson1<<" Hz"<<endl;
cout<<" The first resonance quality factor = "<<QO1<<endl;
cout<<" The first resonance fractional BandWidth = "<<BWres1<<" = "<<BWres1*100 <<" %"<<endl;
cout<<" The first resonance absolute BandWidth = "<<BWres1*freson1<<" Hz"<<endl;
cout<<" \nThe second resonant frequency = "<<freson2<<" Hz"<<endl;
cout<<" The second resonance quality factor = "<<QO2<<endl;
cout<<" The second resonance fractional Bandwidth = "<<BWres2<<" = "<<BWres2*100<<" %"<<endl;
cout<<" The second resonance absolute BandWidth = "<<BWres2*freson2<<" Hz"<<endl;

}
else if (sqrt((1/b)*(1/b) + (1/d)*(1/d)) < sqrt((1/a)*(1/a) + (2/d)*(2/d)))
{
double QD = Qd(losstang);
double freson1 = fres(1,0,1);
double QC1 = QcTE10l(freson1 , 1);
double BWres1 = BW(QC1,QD);
double QO1 = Qo(BWres1);
double freson2 = fres(0,1,1);
double QC2 = QcTE011(freson2);
double BWres2 = BW(QC2,QD);
double QO2 = Qo(BWres2);
cout<<" The first 2 resonance frequencyies are : TE101 & TE011 "<<endl;
cout<<" The first resonant frequency = "<<freson1<<" Hz"<<endl;
cout<<" The first resonance quality factor = "<<QO1<<endl;
cout<<" The first resonance fractional BandWidth = "<<BWres1<<" = "<<BWres1*100 <<" %"<<endl;
cout<<" The first resonance absolute BandWidth = "<<BWres1*freson1<<" Hz"<<endl;
cout<<" \nThe second resonant frequency = "<<freson2<<" Hz"<<endl;
cout<<" The second resonance quality factor = "<<QO2<<endl;
  cout<<" The second resonance fractional Bandwidth = "<<BWres2<<" = "<<BWres2*100<<" %"<<endl;
cout<<" The second resonance absolute BandWidth = "<<BWres2*freson2<<" Hz"<<endl;
}
else if ((2*b)>d)
{
double QD = Qd(losstang);
double freson1 = fres(1,0,1);
double QC1 = QcTE10l(freson1 , 1);
double BWres1 = BW(QC1,QD);
double QO1 = Qo(BWres1);
double freson2 = fres(1,1,0);
double QC2 = QcTM110(freson2);
double BWres2 = BW(QC2,QD);
double QO2 = Qo(BWres2);
cout<<" The first 2 resonance frequencyies are : TE101 & TM110 "<<endl;
cout<<" The first resonant frequency = "<<freson1<<" Hz"<<endl;
cout<<" The first resonance quality factor = "<<QO1<<endl;
cout<<" The first resonance fractional BandWidth = "<<BWres1<<" = "<<BWres1*100 <<" %"<<endl;
cout<<" The first resonance absolute BandWidth = "<<BWres1*freson1<<" Hz"<<endl;
cout<<" \nThe second resonant frequency = "<<freson2<<" Hz"<<endl;
cout<<" The second resonance quality factor = "<<QO2<<endl;
cout<<" The second resonance fractional Bandwidth = "<<BWres2<<" = "<<BWres2*100<<" %"<<endl;
cout<<" The second resonance absolute BandWidth = "<<BWres2*freson2<<" Hz"<<endl;

}
return 0;
}
