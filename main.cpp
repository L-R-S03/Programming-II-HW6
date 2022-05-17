#include <iostream>
#include <string>
#include "BinarySearchTree.h"

using namespace std;

void menu();
void insert_msg();
void delete_msg();
template <typename T> void display(T&); 
int main()
{
   string input = "";
   bool exit_now = false;
   BinarySearchTree<int> stree;
   BinaryTree<int> a;
   while (!exit_now)
   {
      menu();
      getline(cin, input);
      if (input == "i")
      {
         insert_msg();
         getline(cin, input);
         while (input != "q")
         {
            stree.insert(stoi(input));
            stree.print();
            getline(cin, input);
         }
      }
      else if (input == "d")
      {
         delete_msg();
         getline(cin, input);
         while (input != "q")
         {
            stree.remove(stoi(input));
            stree.print();
            getline(cin, input);
         }
      }
      else if (input == "c")
         a.clear();
      else if (input == "p")
         stree.print();
      else if (input == "h")
         cout << "\nThe height of the binary tree is " << stree.height() << endl;
      else if (input == "s")
         cout << "\nThe size (node count) of the binary tree is " << stree.size() << endl;
      else if (input == "m") // pre-order
         stree.preorder(display);
      else if (input == "x")
         exit_now = true;
      else if (input == "n") 
         stree.inorder(display);
      else if (input == "o") 
         stree.postorder(display);
      else if (input == "l") 
         cout << "\nThe leaf count of the binary tree is " << stree.leaf() << endl;
      else if (input == "e")
      {
         a=stree;  
         a.print();  
      }
   }
}

void menu()
{
   cout << "\n";
   cout << "***********************\n";
   cout << "Menu:\n";
   cout << "i. Incremental Insert\n";
   cout << "d. Incremental Delete\n";
   cout << "c. Clear tree\n";
   cout << "p. Print tree\n";
   cout << "h. Print tree height\n";
   cout << "s. Print tree size\n";
   cout << "m. Pre-order traversal\n";
   cout << "n. In-order traversal\n";
   cout << "o. Post-order traversal\n";
   cout << "l. Leaf count\n";
   cout << "e. Operator=()\n";
   cout << "x. Exit\n";
   cout << "***********************\n";
}

void insert_msg()
{
   cout << "\nEnter new integer keys to insert.  Enter \"q<Enter>\" to quit.\n\n";
}

void delete_msg()
{
   cout << "\nEnter integer keys to delete.  Enter \"q<Enter>\" to quit.\n\n";
}

template <typename T> void display(T& data) {
   cout << data << endl;
}
