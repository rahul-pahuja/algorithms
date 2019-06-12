#include<iostream>
using namespace std;
int main()
	{
		int a[10][10]={0},x,y,z=1,m,r,c;
		cout<<"Enter position : ";
		cin>>x>>y;
		x-=1;
		y-=1;

		for(m=0;m<10;m++)
			{
				for(r=x-z;r<=x+z;r++)
					{
						if(r<0)
							continue;
						if(r>9)
							break;
						for(c=y-z;c<=y+z;c++)
							{
								if(c<0)
									continue;
								if(c>9)
									break;
								if(r==x-z||r==x+z)
									a[r][c]+=z;
								else
									if(c==y-z||c==y+z)
										a[r][c]+=z;
							}
					}
				z++;
			}
		cout<<"Matrix become : \n";
		for(r=0;r<10;r++)
			{
				for(c=0;c<10;c++)
					cout<<a[r][c]<<" ";
				cout<<endl;
			}
	}
