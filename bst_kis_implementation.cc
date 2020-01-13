/*
** 	Final exam 
** 	Binary Search Tree implementation with C++14
** 	Nazarova Natalia
**
**	NOT IMPLEMENTED AS IT IS SHOULD BE, I GONNA PUSH ANOTHER VERSION
*/



#include<iostream>
#include <memory> 
#include <chrono>
#include <string>

using namespace std;

template <typename T>
class BST {
// is used to implement the binary search tree class
  // making the data public simplifies building the class functions
  
	struct node {
	T data;

      node* left, *right;
   
	 };
    node* daddy;

/*
**
** --------------------------------                       makeEmpty()                       --------------------------------
**
*/


 node* makeEmpty(node* t) {
if(t == NULL)

return NULL;
        {
makeEmpty(t->left);
makeEmpty(t->right);
delete t;
        }
return NULL;
    }
 
/*
**
** --------------------------------                       INSERT() & TRANSVERSE()                       --------------------------------
**
*/    


    node* insert(T x, node* t)
    {
if(t == NULL)
        {
            t = new node;
            t->data = x;
            t->left = t->right = NULL;
        }
else if(x < t->data)
            t->left = insert(x, t->left);
else if(x > t->data)
            t->right = insert(x, t->right);
return t;
    }


/*
**
** --------------------------------                       BEGIN() & END()                       --------------------------------
**
*/




    node* begin(node* t)   /**/
    {
if(t == NULL)
return NULL;
else if(t->left == NULL)
return t;
else
return begin(t->left);
    }


    node* end(node* t) {
if(t == NULL)
return NULL;
else if(t->right == NULL)
return t;
else
return end(t->right);
    }

/*
**
** --------------------------------                       CLEAR() / REMOVE()                       --------------------------------
**
*/
    node* clear(T x, node* t) {
        node* temp;
if(t == NULL)
return NULL;
else if(x < t->data)
            t->left = clear(x, t->left);
else if(x > t->data)
            t->right = clear(x, t->right);
else if(t->left && t->right)
        {
            temp = begin(t->right);
            t->data = temp->data;
            t->right = clear(t->data, t->right);
        }
else
        {
            temp = t;
if(t->left == NULL)
                t = t->right;
else if(t->right == NULL)
                t = t->left;
delete temp;
        }
return t;
    }

/*
**
** --------------------------------                       INORDER() / DISPLAY()                       --------------------------------
**
*/

void inorder(node* t) {
if(t == NULL)
return;
inorder(t->left);
        cout << t->data << "  ";
inorder(t->right);
    }

/*
**
** --------------------------------                       FIND()                       --------------------------------
**
*/

    node* find(node* t, T x) {
if(t == NULL)
return NULL;
else if(x < t->data)
return find(t->left, x);
else if(x > t->data)
return find(t->right, x);
else
return t;
    }


/*
**
** --------------------------------                       ()                       --------------------------------
**
*/

public:
BST() {
        daddy = NULL;
    }
~BST() {
        daddy = makeEmpty(daddy);
    }

void insert(T x) {
        daddy = insert(x, daddy);
    }
void clear(T x) {
        daddy = clear(x, daddy);
    }

void display() {
inorder(daddy);
        cout << endl;
    }
void search(T x) {
        daddy = find(daddy, x);
    }
};


int main() {
    cout << "Inserted numbers: 8 3 10 1 6 4 1 7 14 13 \n"  << endl;

   cout << "BSTree in transversed order:"  << endl;

  auto t0 = chrono::high_resolution_clock::now(); 

   BST<int> t;
    t.insert(8);
    t.insert(3);
    t.insert(10);
    t.insert(1);
    t.insert(6);
    t.insert(4);
    t.insert(1);
    t.insert(7);
    t.insert(14);
    t.insert(13);
    t.display();


    
  auto t1 = chrono::high_resolution_clock::now();

    cout << "\nTime of biulding and transvering of tree is " <<
        chrono::duration_cast<std::chrono::nanoseconds>(t1-t0).count() << " nanoseconds \n"<< endl;

    cout << "Imput element of tree, which you want to insert to BStree" << endl;

	int xval;
        scanf("%d",  &xval);
        t.insert(xval);
        t.display();



    cout << "Imput element of tree, which you want to remove" << endl;

	scanf("%d",  &xval);
	t.clear(xval);
	t.display();  
	

return 0; 
}
