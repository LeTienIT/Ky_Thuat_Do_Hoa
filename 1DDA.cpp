#include<iostream>
#include<math.h>
#include<conio.h>
using namespace std;

struct diem
{
	float x,y;
};

class DDA
{
private:
	diem d1;
	diem d2;
	float m;
public:
	void nhap()
	{
		cout<<"DIEM BD: ";cin>>d1.x>>d1.y;
		cout<<"DIEM KT: ";cin>>d2.x>>d2.y;
	}
	void timM()
	{
		m=(d2.y - d1.y) / (d2.x - d1.x);
		m = round(m*100)/100;
	}
	void xuly()
	{
		int i=0;
		cout<<m<<'\n';
		if(m<1)
		{
			cout<<"I"<<"\t"<<"X"<<"\t"<<"Yi"<<"\t"<<"Y"<<'\n';
			while(d1.x <= d2.x)
			{
				cout<<i<<"\t"<<d1.x<<"\t"<<d1.y<<"\t"<<round(d1.y)<<'\n';
				d1.x++;
				d1.y=d1.y+m;
				i++;
			}
		}
		else
		{
			m = 1/m;
			cout<<m<<'\n';
			cout<<"I"<<"\t"<<"Xi"<<"\t"<<"Y"<<"\t"<<"X"<<'\n';
			while(d1.y <= d2.y)
			{
				cout<<i<<"\t"<<d1.x<<"\t"<<d1.y<<"\t"<<round(d1.y)<<'\n';
				d1.y++;
				d1.x=d1.y+m;
				i++;
			}
		}	
	}
}; 

int main()
{
	DDA a1;
	a1.nhap();a1.timM();a1.xuly();
	getch();
	return 0;
}
