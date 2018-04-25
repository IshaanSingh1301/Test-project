#include<iostream>
#include<new>
#include<cstdlib>
using namespace std ;
 struct node
{
    int k;
    struct node* next;
}*nptr,*st,*ptr,*r;

node* cnn(int ); //for new node
void insb (node*);//insertion in the beginning for stack
void inse (node*);//insertion in the end for queue
void disp (node*);//for displaying the list
void dele ();//for deletion at the beginning

int main()
{ int inf,kp; char ch='y';
   st==NULL; nptr=NULL;
  cout<<"ENTER CHOICE 1. STACK, 2. QUEUE"<<endl; cin>>kp; 

if (kp==1)
 { while (ch=='y')
   {    cout<<"enter info of new node"<<endl; cin>>inf;
       nptr= cnn(inf);
      if (nptr==NULL){ return -1; }
      insb (nptr);
      cout<<"inserted at the beginning"<<endl;
      cout<<"do you want to continue, enter y for yes"<<endl; cin>>ch;
   }
  do
   {cout<<"do you want to perform deletion at the beginning,enter y for yes"<<endl; cin>>ch;
   if (ch=='y')
    dele (); }while (ch=='y'); }

else if (kp==2)
{   while (ch=='y')
   {   cout<<"enter info of new node"<<endl; cin>>inf;
       nptr= cnn(inf);
       if(nptr==NULL)
       {
           cout<<"no space available"<<endl; exit(1);
       }
      inse (nptr);
      cout<<"inserted at the end"<<endl;
      cout<<" do you want to continue, enter y for yes"<<endl; cin>>ch;
   }
   do
  {cout<<"do you want to perform deletion at the beginning,enter y for yes"<<endl; cin>>ch;
   if (ch=='y')
    dele ();}while(ch=='y'); }

 cout<<"here is your list"<<endl;
 disp(st);
delete st,nptr,r;
return 0;
}

node* cnn (int n)
{ try
{ptr=new node;}
catch (bad_alloc xa)
{ cout <<"Allocation Failure"<<endl; return NULL ;} //checks if there is any space in heap memory
     ptr->k=n;
     ptr->next=NULL;
return ptr;
}

void insb ( node* np)
{  if (st==NULL)
    st=np;
   else
   { ptr=st;
     st=np;
     np->next=ptr;
   }
}

void inse (node* np)
{  if (st==NULL)
    st=r=np;
   else
   { r->next=np;
     r=np;
   }
}

void disp (struct node* np)
{   while (np)
     { cout<<np->k<<endl;
       np=np->next;
      }

}

void dele ()
{ ptr=NULL;
  if (st==NULL)
  {
      cout<<"underflow,start again"<<endl; exit (1);
  }
  ptr=st;
  st=st->next;
  delete ptr;
return ;}


