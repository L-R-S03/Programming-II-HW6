#ifndef BINARYNODE_H
#define BINARYNODE_H 

template <typename T>
struct BinaryNode 
{
    T data; 
    BinaryNode<T>* left;
    BinaryNode<T>* right;

    BinaryNode(); 
    BinaryNode(T); 
}; 

template <typename T> 
BinaryNode<T>::BinaryNode() 
{
    left=nullptr; 
    right=nullptr; 
}

template <typename T> 
BinaryNode<T>::BinaryNode(T d)
{
    data=d;
    left=nullptr; 
    right=nullptr; 
}


#endif