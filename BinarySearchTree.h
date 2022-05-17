#ifndef BINARYSEARCHTREE_H 
#define BINARYSEARCHTREE_H 
#include "enum.h"
#include "BinaryNode.h"
#include "BinaryTree.h"

template <class T>
class BinarySearchTree: public BinaryTree<T> {
public:
   Error_code insert(const T&);
   Error_code remove(const T&);

protected:
   // Auxiliary recursive functions
   Error_code search_and_insert(BinaryNode<T>*& sub_root, const T& new_data);
   Error_code search_and_delete(BinaryNode<T>*& sub_root, const T& target);
};

template <class T>
Error_code BinarySearchTree<T>::insert(const T& d)
{
   return search_and_insert(this->root, d); 
}

template <class T>
Error_code BinarySearchTree<T>::search_and_insert(BinaryNode<T>*& sub_root, const T& d)
{
   Error_code result=success; 
   if(sub_root==nullptr)
   {
      sub_root=new BinaryNode<T>(d);
   }
   else if(sub_root->data==d)
   {
      result=duplicate_error; 
   }
   else if(sub_root->data < d)
   {
      result=search_and_insert(sub_root->right, d); 
   }
   else 
   {
      result=search_and_insert(sub_root->left, d); 
   }
   return result; 
}

template <class T>
Error_code BinarySearchTree<T>::remove(const T& target)
{
   return search_and_delete(this->root,target); 
}
template <class T>
Error_code BinarySearchTree<T>::search_and_delete(BinaryNode<T>*& sub_root, const T& target)
{
   Error_code result=success; 
   if(sub_root==nullptr)
   {
      result=not_present; 
   }
   else if(sub_root->data==target)
   {
      if(sub_root->left==nullptr && sub_root->right==nullptr)
      {
         delete sub_root; 
         sub_root=nullptr; 
      }
      else if(sub_root->left==nullptr)
      {
         BinaryNode<T>* temp=sub_root; 
         sub_root=sub_root->right; 
         delete temp; 

      }
      else if(sub_root->right==nullptr)
      {
         BinaryNode<T>* temp=sub_root; 
         sub_root=sub_root->left; 
         delete temp; 
      }
      else 
      {
         BinaryNode<T>* Successor;
         Successor=sub_root->right; 
         while(Successor->left!=nullptr)
         {
            Successor=Successor->left; 
         } 
         sub_root->data=Successor->data; 
         result= search_and_delete(sub_root->right, sub_root->data); 
      }
   }
   else if(sub_root->data<target)
   {
      result=search_and_delete(sub_root->right, target); 
   }
   else 
   {
      result=search_and_delete(sub_root->left,target); 
   }
   return result; 
}
#endif



