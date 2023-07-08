#include <iostream>
#include<math.h>
#include<conio.h>
using namespace std;

string phia[]={"duoi","tren","phai","trai"};
struct diem
{
	float x, y;
};
struct cuaso
{
	float Xmin,Ymin,Xmax,Ymax;
};
struct C
{
	int ma[4];
};

class Tien
{
private:
	diem P[2];
	diem giao[2];
	cuaso W;
	C c[2];
public:
	void nhap()
	{
		cout<<"Nhap toa do goc trai duoi cua cua so: "<<'\n';
		cout<<"X Y: ";cin>>W.Xmin>>W.Ymin;
		cout<<"Nhap toa do goc phai tren cua cua so: "<<'\n';
		cout<<"X Y: ";cin>>W.Xmax>>W.Ymax;
		for(int i=0;i<2;i++)
		{
			cout<<"Nhap toa do cho diem thu "<<i+1<<'\n';
			cout<<"X Y: ";cin>>P[i].x>>P[i].y;
		}	
	}
	void mavung()
	{
		for(int i=0;i<2;i++)
		{
			if(P[i].x < W.Xmin)
			{
				c[i].ma[3]=1;//c[i].ma[2]=0;
			}
			else
			{
				c[i].ma[3]=0;
			}
			if(P[i].x > W.Xmax)
			{
				c[i].ma[2]=1;//c[i].ma[3]=0;
			}
			else
			{
				c[i].ma[2]=0;
			}
			if(P[i].y > W.Ymax)
			{
				c[i].ma[1]=1;//c[i].ma[4]=0;
			}
			else
			{
				c[i].ma[1]=0;
			}
			if(P[i].y < W.Ymin)
			{
				c[i].ma[0]=1;//c[i].ma[1]=0;
			}
			else
			{
				c[i].ma[0]=0;
			}
		}	
	}
	void show()
	{
		cout<<"==========MA VUNG==========="<<'\n';
		for(int i=0;i<2;i++)
		{
			cout<<"C["<<i<<"]: ";
			for(int j=0;j<4;j++)
			{
				cout<<c[i].ma[j];
			}
			cout<<'\n';
		}
	}
	bool xettrong()
	{
		int dem=0;
		for(int j=3;j>=0;j--)//ma[4] 0-1-2-3  3 2 1 0 
		{
			if(c[0].ma[j] == 0 && c[1].ma[j] == 0 )
			{
				dem++;
			}
		}
		if(dem==4)
		{
			cout<<"2 MA = NHAU = 0000"<<'\n';
			cout<<"Hai Diem nam hoan toan trong cua so"<<'\n';
			return true;
		}
		else
		{
			return false;
		}	
	}
	bool xetngoai()
	{
		int b=0; int ten[]={3,2,1,0};
		for(int j=3;j>=0;j--)
		{
			if(c[0].ma[j] == 1 && c[1].ma[j] == 1 )
			{
				cout<<"2 MA VUNG DEU CO C["<<ten[j]<<"]=1"<<'\n';
				cout<<"Hai Diem nam hoan toan ngoai cua so"<<'\n';
				cout<<"Va nam ben "<<phia[j]<<" cua cua so"<<'\n';
				b=1;
				break; 
			}
		}
		if(b==1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	diem bienngang(int bit)
	{
		diem Temp;
		float m=float((P[1].x - P[0].x)/(P[1].y - P[0].y));
		if(bit==1)
		{
			Temp.y = W.Ymax;	
		}
		else if(bit==0)
		{
			Temp.y = W.Ymin;
		}
		Temp.x = P[0].x + (Temp.y - P[0].y) * m;
		return Temp;
	}
	diem biendoc(int bit)
	{
		diem Temp;
		float m=float((P[1].y - P[0].y)/(P[1].x - P[0].x));
		if(bit==3)
		{
			Temp.x = W.Xmin;	
		}
		else if(bit==2)
		{
			Temp.x = W.Xmax;
		}
		Temp.y = P[0].y + (Temp.x - P[0].x) * m;
		return Temp;
	}
	diem timgiao()
	{
		int j=0;diem T;
		while(j<2)
		{
			int dem=10; 
			for(int i=3;i>=0;i--)
			{
				if(c[j].ma[i]==1)
				{
					dem=i;
					break; 
				}
			}
			if(dem >=2 && dem <=3)
			{
				T=biendoc(dem);
			}
			else if(dem <= 1)
			{
				T=bienngang(dem);
			}
			giao[j] = T;
			j++;
		}
	}
	void showgiao()
	{
		cout<<"======GIAO DIEM======"<<'\n';
		for(int i=0;i<2;i++)
		{
			cout<<"DIEM["<<i<<"]: ("<<giao[i].x<<","<<giao[i].y<<")"<<'\n';	
		}
	}
};

int main()
{
	Tien T; bool kt1,kt2;
	while(true)
	{
		system("cls");
		T.nhap();
		T.mavung();
		cout<<"-----------------------------------------"<<'\n';
		T.show();cout<<'\n';
		kt1=T.xettrong();
		if(kt1==false)
		{
			kt2=T.xetngoai();
		}
		if(kt1==false && kt2==false)
		{
			T.timgiao();
			T.showgiao();
		}
		cout<<"Enter de nhap tiep"<<'\n';
		getch();
	}
	return 0;
}
