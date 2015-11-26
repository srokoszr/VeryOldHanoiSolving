#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;


int licznik=0;


void czekaj ( float liczba_sekund )
{
    clock_t a;
    a = clock () + liczba_sekund * CLOCKS_PER_SEC ;
    while (clock() < a) 
    {
        
    }
}

void czyszczenie (int tab [][3], int n)
{
	for (int i=0;i<n;i++)
	{
		tab[i][0]=0;
		tab[i][1]=0;
		tab[i][2]=0;
	}
}

void wpisanie (int tab [][3], int n)
{
	int j=n;
	for (int i=0;i<n;i++)
	{
		tab[i][0]=j;
		j--;
	}
}

void wypisz (int tab [][3], int n)
{
	system ("cls");
	cout<<"kolumna1: "<<"kolumna2: "<<"kolumna3: "<<endl<<endl;
	for (int i=n-1;i>=0;i--)
	{
		if (tab[i][0]!=0)
		{
			cout<<tab[i][0]<<"         "; 
		}
		else
		{
			cout<<"          ";
		}
		if (tab[i][1]!=0)
		{
			cout<<tab[i][1]<<"         "; 
		}
		else
		{
			cout<<"          ";
		}
		if (tab[i][2]!=0)
		{
			cout<<tab[i][2]<<"         "; 
		}
		else
		{
			cout<<"          ";
		}
		cout<<endl;	
	}
	cout<<endl<<endl<<endl<<"krok numer:"<<licznik<<endl;
}

int ostatnie_zajete (int tab [][3], int m, int j)
{
	for (int i=0;i<m;i++)
	{
		if (tab[i][j]==0)
		{
			return i-1;	
		}
	}
	return m-1;
}

int pierwsze_wolne (int tab [][3], int m, int j)
{
	for (int i=0;i<m;i++)
	{
		if (tab[i][j]==0)
		{
			return i;	
		}
	}
	return m;
}

void Hanoi (int tab[][3], int n, int m, int a, int b, int c)
{
	int x,y;
	if(n==1)
	{
	x=ostatnie_zajete(tab,m,a);
	y=pierwsze_wolne(tab,m,c);
	tab[y][c]=tab[x][a];
	tab[x][a]=0;
	licznik++;
	wypisz (tab, m);
	cout<<a+1<<"("<<x+1<<")"<<"->"<<c+1<<"("<<y+1<<")"<<endl;
	czekaj(1);		
	}
	else
	{
		Hanoi (tab, n-1, m, a, c, b);
		x=ostatnie_zajete(tab,m,a);
		y=pierwsze_wolne(tab,m,c);
		tab[y][c]=tab[x][a];
		tab[x][a]=0;
		licznik++;
		wypisz (tab, m);
		cout<<a+1<<"("<<x+1<<")"<<"->"<<c+1<<"("<<y+1<<")"<<endl;
		czekaj(1);
		Hanoi (tab, n-1, m, b, a, c);
	}
	
}


int main ()
{
	int n;
	cout<<"n=";
	cin>>n;
	const int m=n;
	int tab[n][3];
	czyszczenie (tab, n);
	wpisanie (tab, m);
	wypisz (tab, m);
	czekaj(1);
	Hanoi (tab, n, m, 0, 1, 2);
	return 0;
}