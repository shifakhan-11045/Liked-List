#include<iostream>
#include<malloc.h>
using namespace std;
struct node
{
	int data;
	struct node*add;
}*start=NULL,*temp,*prev,*ptr;

void ins_beg();
void ins_end();
void ins_spe();
void del_beg();
void del_end();
void del_spe();
void display();
int main()
{
	int ch;
	cout<<"Shifa Khan\n0832CS221187\n";
	do
	{
		cout<<"\nMAIN MENU";
		cout<<"\nPress 1 for insertion at the beginning : ";
		cout<<"\nPress 2 for insertion at the end : ";
		cout<<"\nPress 3 for insertion at the specified position : ";
		cout<<"\nPress 4 for deletion at the beginning : ";
		cout<<"\nPress 5 for deletion at the end : ";
		cout<<"\nPress 6 for deletion at the specified position : ";
		cout<<"\npress 7 for display : ";
		cout<<"\nPress 8 for exit ";
		cout<<"\nEnter your choice : ";
		cin>>ch;
		
		switch(ch)
		{
			case 1 :ins_beg();break;
			case 2 :ins_end();break;
			case 3 :ins_spe();break;
			case 4 :del_beg();break;
			case 5 :del_end();break;
			case 6 :del_spe();break;
			case 7 :display();break;
			case 8 :break; 
		}

		
	}
	while(ch!=8);
	
}
void ins_beg()
{
	ptr=(struct node*)malloc(sizeof(struct node));
	if(ptr==NULL)
	cout<<"\nLINKED LIST IS FULL ";
	else
	{
		int n;
		cout<<"\nEnter the number : ";
		cin>>n;
		ptr->data=n;
		ptr->add=start;
		start=ptr;
	}
}
void ins_end()
{
	ptr=(struct node*)malloc(sizeof(struct node));
	if(ptr==NULL)
	cout<<"\nLINKED LIST IS FULL";
	else
	{
		int n;
		cout<<"\nEnter the number : ";
		cin>>n;
		ptr->data =n;
		ptr->add=NULL;
		temp=start;
		while(temp->add!=NULL)
		{
			temp=temp->add;
		}
	    temp->add=ptr;
	}
}
void ins_spe()
{
	ptr=(struct node*)malloc(sizeof(struct node));
	if(ptr==NULL)
	cout<<"\nLINKED LIST IS FULL ";
	else
	{
		int n,pos,i;
		cout<<"\nEnter the number : ";
		cin>>n;
		ptr->data=n;
		cout<<"\nEnter the position : ";
		cin>>pos;
		temp=start;
		for(i=1;i<pos;i++)
		{
			prev=temp;
			temp=temp->add;
			
		}
		ptr->add=temp;
		prev->add=ptr;
	}
}
void del_beg()
{
	if(start==NULL)
	cout<<"\nLINKED LIST IS EMPTY ";
	else
	{
		cout<<"\nDELETED ELEMENT IS : "<<start->data;
		temp=start;
		start=start->add;
		free(temp);
	}
}
void del_end()
{
	if(start==NULL)
	cout<<"\nLINKED LIST IS EMPTY ";
	else
	{   temp=start;
		while(temp->add!=NULL)
		{
			prev=temp;
			temp=temp->add;
		}
		prev->add=NULL;
		cout<<"\nDELETED ELEMENT IS : "<<temp->data;
		free(temp);
	}
}
void del_spe()
{
	if(start==NULL)
	cout<<"\nLINKED LIST IS EMPTY ";
	else
	{
		int pos;
		cout<<"\nEnter the position : ";
		cin>>pos;
		temp=start;
		for(int i=1;i<pos;i++)
		{
			prev=temp;
			temp=temp->add;
		}
		prev->add=temp->add;
		cout<<"\nDELTED ELEMENT IS : "<<temp->data;
		free(temp);
	}
}
void display()
{
	if(start==NULL)
	cout<<"\nLINKED LIST IS EMPTY";
	else
	{
		temp=start;
		while(temp!=NULL)
		{
			cout<<temp->data<<endl;
			temp=temp->add;
		}
		cout<<endl;
	}
}
