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


// Class Declaration
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
// finish line





