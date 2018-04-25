#include<iostream>
using namespace std ;
int sea(int*,int,int);
void ins (int*,int);
void del (int*,int);
void sorti (int*,int);
void display (int*,int);

int main ()
{
    int a[10],s,c,i,k;
    cout<<"enter size of the array, where size<=10"<<endl; cin>>s;
    cout<<"enter the array"<<endl;
    for (i=0;i<s;i++)
        cin>>a[i];
    cout<<"ARRAY FUNCTION MENU-> 1.SEARCH 2.INSERTION 3.DELETION 4.SORTING(ASC)"<<endl;
    cout<<" ENTER CHOICE"<<endl; cin>>c;
    switch (c)
    {    case 1 :  cout<<"enter search item"<<endl; cin>>k;
                  int p=sea(&a[0],s,k);
                  if (p==0)
                  cout<<"no such element present"<<endl;
                  else
                  cout<<"position of the element is "<<endl<<p<<endl;
                  break;
        case 2 : ins (a,s);
                 break;
        case 3 : del (&a[0],s);
                 break;
        case 4 : sorti (&a[0],s);
                  break;
        default: cout<<"invalid choice"<<endl;
    }
return 0;
}

int sea (int *a,int s,int k)
{   int i,o=0;
    for (i=0;i<s;i++)
    {     if (*a==k)
          {  o=i+1;
             break;
          }
        a++;
    }
return o;
}

void ins (int *a,int s)
{    int pos=0,i,k,*l;
    l=a;
    if (s>=10)
    { cout<<"no space"<<endl; return; }
    cout<<"enter the element and its position to be inserted"<<endl; cin>>k>>pos;
    if (pos<1&&pos>10)
    { cout<<"invalid position"<<endl; return; }
    for (i=s;i>(pos-1);i--)
    {
      *(a+i)=*((a+i)-1);
    }
    *(a+(pos-1))=k; s++;
 display (l,s);
}

void del (int *a,int s)
{  int i,k,p,*l;
    l=a;
    if (s<=0)
    { cout<<"nothing to delete"<<endl; return;}
   cout<<"enter item to be deleted"<<endl cin>>k;
   p=sea (a,s,k);
    if (p==0)
    {cout<<"no such element present"<<endl; return;}
   for (i=(p-1);i<(s-1);i++)
     {*(a+i)=*((a+i)+1);}
    s--;
    display(l,s);
}

void sorti (int *a,int s)
{
    int i,j,*l,t;
    l=a;
    for (i=0;i<s;i++)
    {  a=l;
        for (j=0;j<(s-i);j++)
        {  if (*a>*(a+1))
             { t=*a; *a=*(a+1); *(a+1)=t;}
           a++;
        }
    }
display (l,s);
}

void display (int *a,int s)
{  cout<< "array is"<<endl;
    int i;
   for (i=0;i<=(s-1);i++)
   { cout<<*a<<endl;
       a++;}
}
