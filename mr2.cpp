#include<iostream>
using namespace std;
struct node
	{
		int name,color;
		node *addr=NULL;
	};
int p[10];
int count=0;
int main()
	{
		void do1(node*,int,node*);
		int n,i,no=1,nob=0,now=0,x,y;
		cout<<"Total no. of nodes : ";
		cin>>n;
		node a[n];
		cout<<"Enter the color according to node sequence : ";
		for(i=0;i<n;i++)
			{
				cin>>a[i].color;
				a[i].name=no;
				no++;
				if(a[i].color==1)
					nob++;
				else
					now++;
			}
		cout<<"Enter the "<<n-1<<" edges(vertex wise) : \n";
		for(i=0;i<n-1;i++)
			{
				cin>>x>>y;
				node **f=NULL;
				node *r=new node();
				r->name=y;
				r->color=a[y-1].color;
				node *m=new node();
				m->name=x;
				m->color=a[x-1].color;
				if(a[x-1].addr==NULL)
					a[x-1].addr=r;
				else
					{
						f=&(a[x-1].addr);
						while(*f!=NULL)
							{
								f=&((*f)->addr);
							}
						*f=r;
					}
				if(a[y-1].addr==NULL)
					a[y-1].addr=m;
				else
					{
						f=&(a[y-1].addr);
						while(*f!=NULL)
							{
								f=&((*f)->addr);
							}
						*f=m;
					}
			}
		node *d;
		int qa;
		if(nob>now)
			qa=1;
		else
			qa=0;
		i=0;
		while(1)
			{
				d=&(a[i]);
				if(d->color==qa)
					break;
				i++;
			}
		do1(a,qa,d);
		for(int i=0;i<count;i++)
			cout<<p[i]<<" ";
		cout<<endl;
	}
void do1(node *a,int color,node* d)
	{
		int check(int);
		p[count]=d->name;
		count++;
		while(1)
			{
				d=d->addr;
				if(d==NULL)
					break;
				if(d->color==color)
					if(check(d->name))
						do1(a,color,&(a[d->name-1]));
				else
					{
						node *f=&(a[d->name-1]);
						f=f->addr;
						while(f!=NULL)
							{
								if(f->color==color)
									if(check(f->name))
										{
											do1(a,color,&(a[d->name-1]));
											break;
										}
								f=f->addr;
							}
					}
			}
	}
int check(int i)
	{
		for(int j=0;j<count;j++)
			{
				if(p[j]==i)
					return(0);
			}
		return(1);
	}
