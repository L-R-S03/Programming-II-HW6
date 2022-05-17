a: main.o 
	g++ -g main.o -o a

main.o: main.cpp BinaryNode.h BinarySearchTree.h BinaryTree.h enum.h
	g++ $(CFLAGS) -c -o main.o main.cpp

clean: 
	rm *.o

