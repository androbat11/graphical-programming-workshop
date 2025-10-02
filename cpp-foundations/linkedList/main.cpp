#include <cstdlib>
#include "linkedList.cpp"


int main(){

    
    Node<int>* head = new Node(2);

    head->createNextNode(new Node(3));
    head->createNextNode(new Node(4));

    LinkedList<int> list;

    list.pushHead(2);
    list.pushHead(3);

    list.updateHeadNode(3, 4);
    list.getNodes();
    

    return EXIT_SUCCESS;
}