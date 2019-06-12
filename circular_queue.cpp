#include <iostream>
using namespace std;
class queue
    {
        int n,f,r,cf,cr;
        public:
        queue()
          {
            int b;
            f=0;
            r=0;
            cf=0;
            cr=0;
            cout<<"Enter the number of elements : ";
            cin>>n;
            int *a=new int[n];
            do
              {
                cout<<"Select your choice by pressing :\n1.Insertion\n2.Deletion\n3.View\n4.Exit\nEnter your choice : ";
                cin>>b;
                cout<<"---------------------------------------------\n";
                if(b==1)
                  insertion(a);
                if(b==2)
                  deletion();
                if(b==3)
                  view(a);
              } while(b!=4);
            delete[] a;
          }
        void insertion(int *p)
          {
            if((cr-cf)==n)
              cout<<"Sorry, Space not available.\n---------------------------------------------\n";
            else
              {
                int number;
                cout<<"Enter the number you want to insert : ";
                cin>>number;
                p[r]=number;
                r=(r+1)%n;
                cr++;
                cout<<"Insertion done\n---------------------------------------------\n";
              }
          }
        void deletion()
          {
            if((cr-cf)==0)
              cout<<"No Number found\n---------------------------------------------\n";
            else
              {
                f=(f+1)%n;
                cf++;
                cout<<"Deletion done\n---------------------------------------------\n";
              }
          }
        void view(int *p)
          {
            int i,j=0;
            if((cr-cf)==0)
              {
                cout<<"No Element Found\n---------------------------------------------\n";
                return;
              }
            cout<<"Elements in the list are : ";
            for(i=f;;i=(i+1)%n,j++)
              {
                if(j==(cr-cf))
                  break;
                cout<<p[i]<<" ";
              }
            cout<<endl;
            cout<<"---------------------------------------------\n";
          }
    };
int main() 
    {
      queue x;
    }
