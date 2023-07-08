#include<iostream>
#include<math.h>
#include<conio.h>
using namespace std;

struct diem
{
	float x,y;
};

class BRESENHAM
{
private:
	diem d1;
	diem d2;
	float m,const1,const2,p;
public:
	void nhap()
	{
		cout<<"DIEM BD: ";cin>>d1.x>>d1.y;
		cout<<"DIEM KT: ";cin>>d2.x>>d2.y;
	}
	void timMP()
	{
		m=(d2.y - d1.y) / (d2.x - d1.x);
		m = round(m*100)/100; 
		//p=2*(d2.y - d1.y) - (d2.x - d1.x);
	}
	void xuly()
	{
		int i=0;
		cout<<"M: "<<m<<'\n';
		if(m>0&&m<=1)
		{
			const1=2*(d2.y - d1.y);
			const2=2*( (d2.y - d1.y)-(d2.x - d1.x) );
			p=2*(d2.y - d1.y) - (d2.x - d1.x);
			cout<<"P: "<<p<<'\n';
			cout<<"I"<<"\t"<<"X"<<"\t"<<"Yi"<<"\t"<<"P"<<'\n';
			while(d1.x <= d2.x)
			{
				cout<<i<<"\t"<<d1.x<<"\t"<<d1.y<<"\t"<<p<<'\n';
				if(p>=0)
				{
					p= p + const2;
					d1.y++;
				}
				else
				{
					p=p+const1;
				}
				d1.x++;
				i++;
			}
		}
		else if(m>1)
		{
			const1=2*(d2.x - d1.x);
			const2=2*( (d2.x - d1.x)-(d2.y - d1.y) );
			p=2*(d2.x - d1.x) - (d2.y - d1.y);
			cout<<"P : "<<p<<'\n';
			cout<<"I"<<"\t"<<"X"<<"\t"<<"Y"<<"\t"<<"P"<<'\n';
			while(d1.y <= d2.y)
			{
				cout<<i<<"\t"<<d1.x<<"\t"<<d1.y<<"\t"<<p<<'\n';
				if(p>=0)
				{
					p= p + const2;
					d1.x++;
				}
				else
				{
					p=p+const1;
				}
				d1.y++;
				i++;
			}	
		}
		else if(m>=-1&&m<0)
		{
			const1=2*(d2.y - d1.y);
			const2=2*( (d2.y - d1.y)+(d2.x - d1.x) );
			p=2*(d2.y - d1.y) + (d2.x - d1.x);
			cout<<"P : "<<p<<'\n';
			cout<<"I"<<"\t"<<"X"<<"\t"<<"Y"<<"\t"<<"P"<<'\n';
			while(d1.x <= d2.x)
			{
				cout<<i<<"\t"<<d1.x<<"\t"<<d1.y<<"\t"<<p<<'\n';
				if(p<0)
				{
					p= p + const2;
					d1.y--;
				}
				else
				{
					p=p+const1;
				}
				d1.x++;
				i++;
			}
		}
		else if(m < -1 && d1.x > d2.x && d1.y < d2.y)
		{
			cout<<"M<-1, Xa>Xb,Ya<Yb"<<'\n';
			const1=2*(d2.x - d1.x);
			const2=2*( (d2.x - d1.x)+(d2.y - d1.y) );
			p=2*(d2.x - d1.x) + (d2.y - d1.y);
			cout<<"P : "<<p<<'\n';
			cout<<"I"<<"\t"<<"X"<<"\t"<<"Y"<<"\t"<<"P"<<'\n';
			while(d1.x >= d2.x)
			{
				cout<<i<<"\t"<<d1.x<<"\t"<<d1.y<<"\t"<<p<<'\n';
				if(p>=0)
				{
					p= p + const1;
					d1.x--;
				}
				else
				{
					p=p+const2;
				}
				d1.y++;
				i++;
			}
		}
		else
		{
			cout<<"Xa < Xb, Ya > Yb"<<'\n';
			cout<<"TRUONG HOP X1 < X2 && m < 0 VD(15,25) (20,15)"<<'\n';
			cout<<"m= (15-25)/(20-15) = -10/5 = -2"<<'\n';
			cout<<"TAI HA CHUA BIET GIAI QUYET."<<'\n';
			
			const1=2*(d2.x - d1.x);
			const2=2*( (d2.x - d1.x)+(d2.y - d1.y) );
			p=2*(d2.x - d1.x) + (d2.y - d1.y);
			cout<<"P : "<<p<<'\n';
			cout<<"I"<<"\t"<<"X"<<"\t"<<"Y"<<"\t"<<"P"<<'\n';
			while(d1.y >= d2.y)
			{
				cout<<i<<"\t"<<d1.x<<"\t"<<d1.y<<"\t"<<p<<'\n';
				if(p>=0)
				{
					p= p + const2;
					d1.x++;
				}
				else
				{
					p=p+const1;	
				}
				d1.y--;
				i++;
			}
		}	
	}
}; 
int main()
{
	BRESENHAM a1;
	a1.nhap();a1.timMP();a1.xuly();
	getch();
	return 0;
}
