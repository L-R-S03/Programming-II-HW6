#include "BinaryNode.h"
#ifndef BINARYTREE_H
#define BINARYTREE_H
template <class T>
class BinaryTree {
public:
   BinaryTree();
   BinaryTree(const BinaryTree<T>&); 
   bool empty() const;
   void preorder(void (*visit)(T &));
   void inorder(void (*visit)(T &));
   void postorder(void (*visit)(T &));
   BinaryTree& operator=(const BinaryTree<T>*); 
   int size() const;
   void clear();
   int height() const;
   int leaf() const; 
   ~BinaryTree(); 
   void print() const; // A method to print out the tree using preorder

   //Add the prototypes of the Big-Three below and add their definitions later

protected:
   // Auxiliary functions
   void recursive_preorder(BinaryNode<T>* sub_root, void (*visit)(T&));
   void recursive_inorder(BinaryNode<T>* sub_root, void (*visit)(T&));
   void recursive_postorder(BinaryNode<T>* sub_root, void (*visit)(T&));
   int  recursive_size(BinaryNode<T>* sub_root) const;
   void recursive_clear(BinaryNode<T>* sub_root);
   int recursive_height(BinaryNode<T>* sub_root) const;
   BinaryNode<T>* recursive_copy(BinaryNode<T>* sub_root);
   void recursive_preorder_print_node(BinaryNode<T>* sub_root) const;
   int recursive_leaf(BinaryNode<T>* sub_root) const;
   // Data member
   BinaryNode<T>* root;
};

template <class T>
BinaryTree<T>& BinaryTree<T>::operator=(const BinaryTree<T>* org)
{
   BinaryTree<T>* temp(org);
   temp = recursive_copy(org);
   return *this;
}
 


template <class T>
BinaryTree<T>::BinaryTree()
/*
Post: An empty binary tree has been created.
*/
{
   root = nullptr;
}

template <class T>
BinaryTree<T>::BinaryTree(const BinaryTree<T>& org)
{
   if(org->root!=nullptr)
   {
      root=new BinaryNode<T>((org->root)->data); 
      root->left=recursive_copy(org->left);
      root->right=recursive_copy(org->right);
   }
}

template <class T>
bool BinaryTree<T>::empty() const
/*
Post: A result of true is returned if the binary tree is empty.
      Otherwise, false is returned.
*/
{
   return (root == nullptr);
}

template <class T>
void BinaryTree<T>::preorder(void (*visit)(T&))
/*
Post: The tree has been traversed in inorder sequence.
Uses: The function recursive_inorder
*/
{
   recursive_preorder(root, visit);
}

template <class T>
void BinaryTree<T>::inorder(void (*visit)(T&))
/*
Post: The tree has been traversed in inorder sequence.
Uses: The function recursive_inorder
*/
{
   recursive_inorder(root,visit); 
}

template <class T>
void BinaryTree<T>::postorder(void (*visit)(T &))
/*
Post: The tree has been traversed in inorder sequence.
Uses: The function recursive_inorder
*/
{
   recursive_postorder(root,visit);
}

template <class T>
int BinaryTree<T>::size() const
/* 
Post: The number of entries in the binary tree is returned.
Uses: The function recursive_size
*/
{
   return recursive_size(root);
}

template <class T>
int BinaryTree<T>::leaf() const
/* 
Post: The number of leafs in the binary tree is returned.
*/
{
   return recursive_leaf(root);
}


template <class T>
void BinaryTree<T>::clear()
/* 
Post: Dispose of all the nodes of the binary tree.
Uses: The function recursive_clear.
*/
{
   recursive_clear(root);
   root=nullptr; 
}

template <class T>
int BinaryTree<T>::height() const
/* 
Post: The height of the binary tree is returned.
Uses: The function recursive_height
*/
{
   return recursive_height(root); 
}


template <class T>
void BinaryTree<T>::print() const
{
   cout << endl; 
   cout << "++++++++++++++++++++" << endl;
   if(root==nullptr)
   {
      cout << "EMPTY TREE" << endl; 
   } 
   else
   {
      if(root->left==nullptr && root->right==nullptr)
      {
         cout << root->data << ":  -   -" << endl; 
      }
      recursive_preorder_print_node(root); 
   }
   cout << "++++++++++++++++++++" << endl;
   cout << endl;
}

// Functions

template <class T>
void BinaryTree<T>::recursive_preorder(BinaryNode<T>* sub_root,
                                            void (*visit)(T& ))
/*
Pre:  sub_root is either NULL or points to a subtree of the BinaryTree.
Post: The subtree has been traversed in preorder sequence.
Uses: The function recursive_preorder recursively
*/
{
   //1. base case : no need to call the recursive function, end of the recursion
   if(sub_root != nullptr) {
      visit(sub_root->data);  //V
      recursive_preorder(sub_root->left, visit); //L
      recursive_preorder(sub_root->right, visit); //R
   }
   //2. recursive case 1-3: call the recursive function, recursion continues
   
}

template <class T>
void BinaryTree<T>::recursive_inorder(BinaryNode<T> *sub_root,
                                           void (*visit)(T &))
/*
Pre:  sub_root is either NULL or points to a subtree of the BinaryTree.
Post: The subtree has been traversed in inorder sequence.
Uses: The function recursive_inorder recursively
*/
{
  if(sub_root != nullptr) {
      recursive_inorder(sub_root->left, visit); //L
      visit(sub_root->data);  //V
      recursive_inorder(sub_root->right, visit); //R
   }
}

template <class T>
void BinaryTree<T>::recursive_postorder(BinaryNode<T> *sub_root,
                                             void (*visit)(T &))
/*
Pre:  sub_root is either NULL or points to a subtree of the BinaryTree.
Post: The subtree has been traversed in postorder sequence.
Uses: The function recursive_postorder recursively
*/
{
   if(sub_root != nullptr) {
      recursive_postorder(sub_root->left, visit); //L
      recursive_postorder(sub_root->right, visit); //R
      visit(sub_root->data);  //V
   }
}

template <class T>
int BinaryTree<T>::recursive_size(BinaryNode<T> *sub_root) const
/*
Pre:  sub_root is either NULL or points to a subtree of the BinaryTree.
Post: The number of entries in the subtree is returned.
Uses: The function recursive_size recursively
*/
{
  
   if(sub_root==nullptr)
   {
      return 0;
   }
   return 1+recursive_size(sub_root->left)+recursive_size(sub_root->right); 
}

template <class T>
int BinaryTree<T>::recursive_leaf(BinaryNode<T> *sub_root) const
/*
Pre:  sub_root is either NULL or points to a subtree of the BinaryTree.
Post: The number of entries in the subtree is returned.
Uses: The function recursive_size recursively
*/
{
  
   if(sub_root==nullptr)
   {
      return 0;
   }
   else if(sub_root->left==0 && sub_root->right==0)
   {
      return 1; 
   }
   else 
   {
      return recursive_leaf(sub_root->left)+recursive_leaf(sub_root->right);
   }
}
template <class T>
void BinaryTree<T>::recursive_clear(BinaryNode<T> *sub_root)
/*
Pre:  sub_root is either NULL or points to a subtree of the BinaryTree.
Post: All the nodes in the subtree are disposed of in postorder.
Uses: The function recursive_clear recursively
*/
{
    if(sub_root!=nullptr)
    {
       recursive_clear(sub_root->left); 
       recursive_clear(sub_root->right); 
       delete sub_root; 
       sub_root=nullptr;
    }
    
}

template <class T>
BinaryTree<T>::~BinaryTree()
{
   recursive_clear(root);
}

template <class T>
int BinaryTree<T>::recursive_height(BinaryNode<T> *sub_root) const 
/*
Pre:  sub_root is either NULL or points to a subtree of the BinaryTree.
Post: the height of the subtree is returned.
Uses: The function recursive_height recursively
*/
{
   if(sub_root==nullptr)
   {
      return 0; 
   }
   int l=recursive_height(sub_root->left);
   int r=recursive_height(sub_root->right);
   if(l>r)
   {
      return l+1;
   }
   else 
   {
      return r+1;
   }
}   

template <class T>
BinaryNode<T>* BinaryTree<T>::recursive_copy(BinaryNode<T>* sub_root) 
/*
Pre:  sub_root is either NULL or points to a subtree of the BinaryTree.
Post: returns a pointer to the root of a new binary tree that has exactly the same structure and content as those of the subtree.
Uses: The function recursive_copy recursively
*/
{
   BinaryTree<T>* tempTree = new BinaryTree<T>;
   if(sub_root != nullptr)
   {
      tempTree = sub_root;
      tempTree->left = recursive_copy(sub_root->left);
      tempTree->right = recursive_copy(sub_root->right);
   }
   return tempTree;
   
}


template <class T>
void BinaryTree<T>::recursive_preorder_print_node(BinaryNode<T>* sub_root) const
/*
Pre:  sub_root is either NULL or points to a subtree of the BinaryTree.
Post: The subtree has been traversed in preorder sequence.
Uses: The function recursive_preorder_print_node recursively
*/
{
   if(sub_root!=nullptr)
   {
      if(sub_root->left!=nullptr || sub_root->right!=nullptr)
      {
         cout << sub_root->data << ": "; 
         if(sub_root->left!=nullptr)
         {
            cout << sub_root->left->data<<" "; 
         }
         else 
         {
            cout << "- ";   
         }
         if(sub_root->right!=nullptr)
         {
            cout << sub_root->right->data<<" ";
         }
         else 
         {
            cout << "- ";   
         }
         cout << endl; 
      }
      recursive_preorder_print_node(sub_root->left); 
      recursive_preorder_print_node(sub_root->right);
   }
   
}
#endif

