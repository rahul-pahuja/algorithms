#include<iostream>
using namespace std;
struct list
	{
		list *left;
		int data;
		list *right;
	};
class bst
	{
		list *head,*A,*B,*C,*Parent;
		int l,a;
		public:
		bst()
			{
				head=A=B=C=Parent=NULL;
				l=0;
				int a,data;
				while(1)
					{
						cout<<"Available Operations on Tree :- \n1. Insertion\n2. Transversal\n3. Exit\n";
						cout<<"Enter your choice : ";
						cin>>a;
						cout<<"------------------------------------------------------------\n";
						if(a==1)
							{
								cout<<"Enter the number : ";
								cin>>data;
								insert(&head,data);
								BalanceFactor(data);
								Rotation();l=0;
								cout<<"Insertion Done\n";
							    cout<<"--------------------------------------------------------\n";
							}
						if(a==2)
							{
								if(head==NULL)
									cout<<"Sorry, tree does not contain any element";
								else
									{
										cout<<"Tree element in postorder transversal : ";
										transverse(head);
									}
							cout<<"\n----------------------------------------------------------\n";
							}
						if(a==3)
							break;
					}
			}
		void insert(list **root,int data)
			{
				if(*root==NULL)
					{
						list *p=new list;
						p->left=p->right=NULL;
						p->data=data;
						*root=p;
						return;
					}
				if((*root)->data>data)
					insert(&((*root)->left),data);
				else
					insert(&((*root)->right),data);
			}
		int height(list *node)
			{
				if(node==NULL)
					return 0;
				else
					{
						int a=height(node->left);
						int b=height(node->right);
						if(a>b)
							return(a+1);
						else
							return(b+1);
					}
			}
		void transverse(list *temp)
			{
				if(temp==NULL)
					return;
				transverse(temp->left);
				transverse(temp->right);
				cout<<temp->data<<" ";
			}
		void BalanceFactor(int d)
			{
				list *node=head;
				while(node->data!=d)
					{
						if(((height(node->left)-height(node->right))>=2)||((height(node->left)-height(node->right))<=-2))
								A=node;
						if(node->data>d)
							node=node->left;
						else
							node=node->right;
					}
				if(A==NULL)
					return;
				if(A->data>d)
					{ B=A->left; l+=1; }
				else
					{ B=A->right; l+=2; }
				if(B->data>d)
					{ C=B->left; l+=3; }
				else
					{ C=B->right;  l+=5; }
			}
		void Rotation()
			{
				if(A==NULL)
					return;
				list *temp=head,*q=NULL;
				while(temp!=A)
					{
						Parent=temp;
						if(temp->data>A->data)
							temp=temp->left,a=1;
						else
							temp=temp->right,a=0;
					}
				switch (l)
					{
						case 4 :
							A->left=NULL;
							if(B->right)
								q=B->right;
							B->right=A;
							if(q)
								insert(&head,q->data);
							delete q;
							SetParent(B);
							break;
						case 7 :
							A->right=NULL;
							if(B->left)
								q=B->left;
							B->left=A;
							if(q)
								insert(&head,q->data);
							delete q;
							SetParent(B);
							break;
						case 6 :
							A->left=B->right=NULL;
							if(C->left)
								q=C->left;
							else
								q=C->right;
							C->left=B;
							C->right=A;
							if(q)
								insert(&head,q->data);
							delete q;
							SetParent(C);
							break;
						case 5:
							A->right=B->left=NULL;
							C->left=A;
							C->right=B;
							if(C->left)
								q=C->left;
							else
								q=C->right;
							if(q)
								insert(&head,q->data);
							delete q;
							SetParent(C);
							break;
					}
				A=B=C=Parent=NULL;
			}
		void SetParent(list *A)
			{
				if(!Parent)
					{
						head=A;
						return;
					}
				if(a==1)
					Parent->left=A;
				else
					Parent->right=A;
			}
	};
int main()
	{
		bst b;
	}
