# include <iostream>
# include <cstdlib>
using namespace std;

// Node Declaration
struct node
{
    int info;
    struct node *left;
    struct node *right;
}*root;


// Class Declaration by
// changes made by Ashish
class BST
{
    public:
        void find(int, node **, node **);
        void insert(node *,node *) ;
        void del(int);
        void case_a(node *,node *);
        void case_b(node *,node *);
        void case_c(node *,node *);
        void preorder(node *);
        void inorder(node *);
        void postorder(node *);
        void display(node *, int);
        BST()
        {
            root = NULL;
        }
};

// Main Contains Menu
int main()
{
    int choice, num;
    BST bst;
    node *temp;
    while (1)
    {
        cout<<"-----------------"<<endl;
        cout<<"Operations on BST"<<endl;
        cout<<"-----------------"<<endl;
        cout<<"1.Insert Element "<<endl;
        cout<<"2.Delete Element "<<endl;
        cout<<"3.Inorder Traversal"<<endl;
        cout<<"4.Preorder Traversal"<<endl;
        cout<<"5.Postorder Traversal"<<endl;
        cout<<"6.Display"<<endl;
        cout<<"7.Quit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                temp = new node;
                cout<<"Enter the number to be inserted : ";
                cin>>temp->info;
                bst.insert(root, temp);
            case 2:
                if (root == NULL)
                {
                    cout<<"Tree is empty, nothing to delete"<<endl;
                    continue;
                }
                cout<<"Enter the number to be deleted : ";
                cin>>num;
                bst.del(num);
                break;
            case 3:
                cout<<"Inorder Traversal of BST:"<<endl;
                bst.inorder(root);
                cout<<endl;
                break;
            case 4:
                cout<<"Preorder Traversal of BST:"<<endl;
                bst.preorder(root);
                cout<<endl;
                break;
            case 5:
                cout<<"Postorder Traversal of BST:"<<endl;
                bst.postorder(root);
                cout<<endl;
                break;
            case 6:
                cout<<"Display BST:"<<endl;
                bst.display(root,1);
                cout<<endl;
                break;
            case 7:
                exit(1);
            default:
                cout<<"Wrong choice"<<endl;
        }
    }
}


// Find Element in the Tree
void BST::find(int item, node **par, node **loc)
{
    node *ptr, *ptrsave;
    if (root == NULL)
    {
        *loc = NULL;
        *par = NULL;
        return;
    }
    if (item == root->info)
    {
        *loc = root;
        *par = NULL;
        return;
    }
    if (item < root->info)
        ptr = root->left;
    else
        ptr = root->right;
    ptrsave = root;
    while (ptr != NULL)
    {
        if (item == ptr->info)
        {
            *loc = ptr;
            *par = ptrsave;
            return;
        }
        ptrsave = ptr;
        if (item < ptr->info)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }
    *loc = NULL;
    *par = ptrsave;
}


// Inserting Element into the Tree
void BST::insert(node *tree, node *newnode)
{
    if (root == NULL)
    {
        root = new node;
        root->info = newnode->info;
        root->left = NULL;
        root->right = NULL;
        cout<<"Root Node is Added"<<endl;
        return;
    }
    if (tree->info == newnode->info)
    {
        cout<<"Element already in the tree"<<endl;
        return;
    }
    if (tree->info > newnode->info)
    {
        if (tree->left != NULL)
        {
            insert(tree->left, newnode);
        }
        else
        {
            tree->left = newnode;
            (tree->left)->left = NULL;
            (tree->left)->right = NULL;
            cout<<"Node Added To Left"<<endl;
            return;
        }
    }
    else
    {
        if (tree->right != NULL)
        {
            insert(tree->right, newnode);
        }
        else
        {
            tree->right = newnode;
            (tree->right)->left = NULL;
            (tree->right)->right = NULL;
            cout<<"Node Added To Right"<<endl;
            return;
        }
    }
}


// Delete Element from the tree
void BST::del(int item)
{
    node *parent, *location;
    if (root == NULL)
    {
        cout<<"Tree empty"<<endl;
        return;
    }
    find(item, &parent, &location);
    if (location == NULL)
    {
        cout<<"Item not present in tree"<<endl;
        return;
    }
    if (location->left == NULL && location->right == NULL)
        case_a(parent, location);
    if (location->left != NULL && location->right == NULL)
        case_b(parent, location);
    if (location->left == NULL && location->right != NULL)
        case_b(parent, location);
    if (location->left != NULL && location->right != NULL)
        case_c(parent, location);
    free(location);
}


// * Case A
void BST::case_a(node *par, node *loc )
{
    if (par == NULL)
    {
        root = NULL;
    }
    else
    {
        if (loc == par->left)
            par->left = NULL;
        else
            par->right = NULL;
    }
}


// * Case B
void BST::case_b(node *par, node *loc)
{
    node *child;
    if (loc->left != NULL)
        child = loc->left;
    else
        child = loc->right;
    if (par == NULL)
    {
        root = child;
    }
    else
    {
        if (loc == par->left)
            par->left = child;
        else
            par->right = child;
    }
}


// * Case C
void BST::case_c(node *par, node *loc)
{
    node *ptr, *ptrsave, *suc, *parsuc;
    ptrsave = loc;
    ptr = loc->right;
    while (ptr->left != NULL)
    {
        ptrsave = ptr;
        ptr = ptr->left;
    }
    suc = ptr;
    parsuc = ptrsave;
    if (suc->left == NULL && suc->right == NULL)
        case_a(parsuc, suc);
    else
        case_b(parsuc, suc);
    if (par == NULL)
    {
        root = suc;
    }
    else
    {
        if (loc == par->left)
            par->left = suc;
        else
            par->right = suc;
    }
    suc->left = loc->left;
    suc->right = loc->right;
}


// Pre Order Traversal
void BST::preorder(node *ptr)
{
    if (root == NULL)
    {
        cout<<"Tree is empty"<<endl;
        return;
    }
    if (ptr != NULL)
    {
        cout<<ptr->info<<"  ";
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

// In Order Traversal
void BST::inorder(node *ptr)
{
    if (root == NULL)
    {
        cout<<"Tree is empty"<<endl;
        return;
    }
    if (ptr != NULL)
    {
        inorder(ptr->left);
        cout<<ptr->info<<"  ";
        inorder(ptr->right);
    }
}


// Postorder Traversal
void BST::postorder(node *ptr)
{
    if (root == NULL)
    {
        cout<<"Tree is empty"<<endl;
        return;
    }
    if (ptr != NULL)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        cout<<ptr->info<<"  ";
    }
}


// Display Tree Structure
void BST::display(node *ptr, int level)
{
    int i;
    if (ptr != NULL)
    {
        display(ptr->right, level+1);
        cout<<endl;
        if (ptr == root)
            cout<<"Root->:  ";
        else
        {
            for (i = 0;i < level;i++)
                cout<<"       ";
        }
        cout<<ptr->info;
        display(ptr->left, level+1);
    }
}

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
