#include <iostream>
#include<math.h>
#include<conio.h>
using namespace std;

struct diem
{
	float x,y;
};
struct cuaso
{
	float Xmin,Ymin,Xmax,Ymax;
};
struct mang
{
	float M[4];
};

class liang
{
private:
	diem d[2];
	cuaso W;
	mang P,Q,U;
	float T[2];
	diem giao[2];
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
			cout<<"X Y: ";cin>>d[i].x>>d[i].y;
		}
	}
	void tinhPQ()
	{
		P.M[0] = -(d[1].x - d[0].x);
		P.M[1] = - P.M[0];
		P.M[2] = -(d[1].y - d[0].y);
		P.M[3] = - P.M[2];
		Q.M[0] = d[0].x - W.Xmin;
		Q.M[1] = W.Xmax - d[0].x;
		Q.M[2] = d[0].y - W.Ymin;
		Q.M[3] = W.Ymax - d[0].y;
	}
	bool TH1()
	{
		int a=0;
		for(int i=0;i<4;i++)
		{
			if(P.M[i]==0 && Q.M[i]<0)
			{
				cout<<"NAM NGOAI CUA SO "<<'\n';
				a=1;
				break;
			}
		}
		if(a==1)
			return true;
		else
			return false;
	}
	float max(float a,float b)
	{
		return (a>b) ? a : b; 
	}
	float min(float a, float b)
	{
		return (a<b) ? a : b;
	}
	bool TH2()
	{
		for(int i=0;i<4;i++)
		{
			U.M[i] = Q.M[i] / P.M[i];
		}
		T[0] = 0,T[1] = 1;
		for(int i=0;i<4;i++)
		{
			if(P.M[i] < 0)
			{
				T[0] = max(T[0],U.M[i]);
			}
			if(P.M[i] > 0)
			{
				T[1] = min(T[1],U.M[i]);
			}
		}
		if(T[0]==0 && T[1]==1)
		{
			cout<<"NAM HOAN TOAN TRONG CUA SO"<<'\n';
			return true;
		}
		else if(T[0] > T[1])
		{
			cout<<"NAM HOAN TOAN NGOAI CUA SO"<<'\n';
			return true;
		}
		else
		{
			diem temp;
			for(int i=0;i<2;i++)
			{
				temp.x = d[0].x + (d[1].x - d[0].x) * T[i];
				temp.y = d[0].y + (d[1].y - d[0].y) * T[i];
				giao[i] = temp;
			}
			return false;
		}
	}
	void showP()
	{
		cout<<"======P======"<<'\n';
		for(int i=0;i<4;i++)
		{
			cout<<"P["<<i<<"]: "<<P.M[i]<<'\n';	
		}
	}
	void showQ()
	{
		cout<<"======Q======"<<'\n';
		for(int i=0;i<4;i++)
		{
			cout<<"Q["<<i<<"]: "<<Q.M[i]<<'\n';	
		}
	}
	void showU()
	{
		cout<<"======U======"<<'\n';
		for(int i=0;i<4;i++)
		{
			cout<<"U["<<i<<"]: "<<U.M[i]<<'\n';	
		}
	}
	void showT()
	{
		cout<<"======T======"<<'\n';
		for(int i=0;i<2;i++)
		{
			cout<<"T["<<i<<"]: "<<T[i]<<'\n';	
		}
	}
	void showgiao()
	{
		cout<<"======GIAO======"<<'\n';
		for(int i=0;i<2;i++)
		{
			cout<<"D["<<i<<"]: ("<<giao[i].x<<","<<giao[i].y<<")"<<'\n';	
		}
	}	
};
int main()
{
	liang T;bool kt1,kt2;
	T.nhap();T.tinhPQ();cout<<'\n';T.showP();cout<<'\n';T.showQ();cout<<'\n';
	kt1 = T.TH1();
	if(kt1==false)
	{
		kt2 = T.TH2();
		T.showU();cout<<'\n';
		T.showT();cout<<'\n';
		if(kt2 == false)
		{
			T.showgiao();
		}
	}
	getch();
	return 0;
}
