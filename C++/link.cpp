#include <iostream>
//#include <conio.h>
using namespace std;
/////////////////////////////////////////////////////////////
//////////////// Node Creation //////////////////////////////
struct node
{
int data;
node *link;
} *start;

/////////////////////////////////////////////////////////////
/////////////////////Node Deletion///////////////////////////
void readfile()
{
	
	node *next,*temp;
	FILE *fp;
	fp = fopen ( "link.dat", "rb" ) ;
	if ( fp == NULL )
	{
	puts ( "Cannot open file" ) ;
	exit(0) ;
	}
	if(start==NULL)
	{
		start=new node;
		next=start;
		while(fread ( &next, sizeof ( node), 1, fp ) == 1 )
		{
			temp=new node;
			
			next=next->link;
			next=temp;
		}
			
		
	}
}
void del(void)
{
int i;
cout<<"Enter the value to delete";
cin>>i;
node *next,*cur;
next=start;
if(next->data==i)
	{
	   start=next->link;
   	delete next;
   }
else
	{
   cur=next;
   while(next!=NULL)
   	{
      if(next->data==i)
      	{
      	   cur->link=next->link;
         	delete next;
         	return;
         }
      cur=next;
      next=next->link;
      }
   cout<<"No such data";
   }
};
///////////////////////////////////////////////////////////////////////
////////////////////////////Link List Linear Traversal/////////////////
void show(void)
{
node *next;
next=start;
while(next!=NULL)
	{
	cout<<next->data<<endl;
   next=next->link;
   }

}
/////////////////////////////////////////////////////////////
///////////////////Add Node /////////////////////////////////
void addnode(int a)
{
	node *next,*temp;
	if(start==NULL)
	{
	//first node
 	start=new node;
	start->data=a;
	start->link=NULL;
	}// end if  only execute for first node
	else
	{
 	next=start;
   while(next->link!=NULL)
 		next=next->link;
 	temp=new node;
 	temp->data=a;
 	temp->link=NULL;
 	next->link=temp;
	} // end else execute after first node

} // end addnode function
//////////////////////////////////////////////////////////////
///////////////////////Main Function//////////////////////////
void insertbeg(int a)
{
node *temp;
temp=new node;
temp->data=a;
temp->link=start;
start=temp;
}
void search(int a)
{
node *next;
int i=1,found=0;
next=start;
while(next!=NULL)
	{
      if(next->data==a)
      {
      	cout<<"Item found at location"<<i<<"\n";
         i++;found++;
         next=next->link;
      }
      else
      {
      	next=next->link;
         i++;

      }
   }
if(found==0)
   	cout<<"Item not found\n";
else
		cout<<"Total occurences of Item are"<<found<<"times\n";
}
void insertbef(int a,int b)
{
node *next,*rev;
next=start;
if(next->data==a)
	{
   node *temp;
   temp=new node;
   temp->data=b;
   temp->link=next;
   start=temp;
   }
else
	{
   rev=next;
   while(next!=NULL)
   	{
      if(next->data==a)
      {
      	node *temp;
         temp=new node;
         temp->data=b;
         temp->link=next;
         while(rev->link!=next)
         	rev=rev->link;
         rev->link=temp;
         return;
         }

     next=next->link;
   }
   }

}
void insertaft(int a,int b)
{
node *next;
next=start;
while(next!=NULL)
	{
   if(next->data==a)
   	{
      node *temp;
      temp->data=b;
      temp->link=next->link;
      next->link=temp;
      break;
      }
   else
   	next=next->link;
   }
}


void shiftr()
{
node *temp,*next;
temp=new node;
temp->data=start->data;
temp->link=NULL;
start=start->link;
next=start;
while(next->link!=NULL)
	next=next->link;
next->link=temp;
}
void write()
{
FILE *fp;
node *next;
next=start;
fp = fopen ("link.dat","wb");

while(next!=NULL)
{
	
fwrite ( next, sizeof ( node ), 1, fp ) ;
next=next->link;
	
	
}
	
}
int main()
{
int i;
int ch;
do
	{
	cout<<"To Enter node Enter Integer 1\n";
	cout<<"To Show List Enter Integer 2\n";
	cout<<"To Delete Node Enter Integer 3\n";
	cout<<"To Search List Enter Integer 4\n";
	cout<<"To Insert Node at begining Enter Integer 5\n";
	cout<<"To Insert Node before node value Enter Integer 6\n";
	cout<<"To Insert Node before node value Enter Integer 7\n";
   cout<<"To Shift Right Enter Integer 8\n";
   cout<<"To quit Enter Integer other than 1 to 8\n";
   cout<<"enter 9 to write on disk\n";
   	cin>>ch;
	switch(ch)
		{
		case 0:
   		readfile();
      	break;
		case 1:
   		cout<<"Enter Integer value to node";
      	cin>>i;
      	addnode(i);
      	break;
   	case 2:
  			show();
      	break;
   	case 3:
  			del();
      	break;
   	case 4:
  			cout<<"Enter Integer value to search the list";
         cin>>i;
  			search(i);
      	break;
   	case 5:
      	cout<<"Enter Integer value to insert at beginning";
         cin>>i;
  			insertbeg(i);
      	break;
   	case 6:
      	cout<<"Enter the node before which insert";
         cin>>i;
         cout<<"Enter the value to be inserted";
         int val;
         cin>>val;
  			insertbef(i,val);
      	break;
   	case 7:
      	cout<<"Enter the node after which insert";
         cin>>i;
         cout<<"Enter the value to be inserted";
         //int val;
         cin>>val;
  			insertaft(i,val);
      	break;
   	case 8:
  			shiftr();
      	break;
	case 9:
  			write();
      	break;

   	default:
  		break;
		}    // end switch
	}while(ch==1||ch==2||ch==3||ch==5||ch==4||ch==7||ch==6||ch==8); // end do while
return 0;
}