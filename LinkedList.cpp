#include <iostream>
using namespace std;
struct list
	{
		int data;
		list *address;
	};
class List
	{
	    list *head;
		public:
			List()
				{
				    head=NULL;
				}
			void insert()
				{
					list *p=new list;
					cout<<"Enter the number : ";
					cin>>(*p).data;
					(*p).address=NULL;
					if(head==NULL)
						head=p;
					else
						{
							list *a;
							a=head;
							while(a->address!=NULL)
								{
									a=a->address;
								}
							a->address=p;
						}
					cout<<"Insertion Done!!\n";
					cout<<"--------------------------------------------------------------\n";
				}
			void show()
				{
					if(head==NULL)
						cout<<"List is empty\n";
					else
						{
							list *a;
							a=head;
							cout<<"List is : ";
							for(;;)
								{
									cout<<(*a).data<<" ";
									if((*a).address==NULL)
										break;
									else
										a=(*a).address;
								}
							cout<<"\n";
						}
					cout<<"--------------------------------------------------------------\n";
				}
	};
int main()
	{
		List a;
		int b=1;
		while(b!=5)
			{
		      cout<<"Select your choice by pressing :\n1.Insertion\n2.Deletion(from Start)\n";
			  cout<<"3.Deletion(from End)\n4.View\n";
			  cout<<"5.Exit\nEnter your choice : ";
			  cin>>b;
   			  cout<<"--------------------------------------------------------------\n";
			  if(b==1)
			    a.insert();
			  if(b==4)
			    a.show();
			}
	}
