#include<iostream>
#include<math.h>
#include<conio.h>
using namespace std;

struct diem
{
	float x,y;
};
class Midpoint 
{
private:
	diem d;
	float R,P;
public:
	void nhap()
	{
		cout<<"TAM DG TRON: MAC DINH(0,0)"<<'\n';//cin>>d.x>>d.y; mac dinh ve tu I(o,o)
		cout<<"R: ";cin>>R;
		d.x=0.0;d.y=R;
	}
	void tinhP()
	{
		P= (5.0/4.0) - R;
	}
	void xuly()
	{
		int i=0; 
		cout<<"i"<<"\t"<<"Xi"<<"\t"<<"Yi"<<"\t"<<"Pi"<<'\n';
		while(d.x <= d.y)
		{
			cout<<i<<"\t"<<d.x<<"\t"<<d.y<<"\t"<<P<<'\n'; 
			if(P<0)
			{
				P=P+2*d.x+3;
			}
			else
			{
				P=P+(2*d.x)-(2*d.y)+5;
				d.y--;
			}
			i++; 
			d.x++;
		}
	}
};
int main()
{
	Midpoint T;
	T.nhap();T.tinhP();T.xuly();
	getch();
	return 0; 
 } 
