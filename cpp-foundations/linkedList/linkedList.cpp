#include <iostream>

using namespace std;

template <typename AbstractNode>
class Node {
    public: 
        AbstractNode data;
        Node<AbstractNode>* next;

        
        Node(AbstractNode data) : data(data), next(nullptr) {}

        Node<AbstractNode>* getNextNode() const { return next; }

        void createNextNode(Node<AbstractNode>* data){
            next = data;
        }

        AbstractNode getNode() const { return data; }
};

template <typename AbstractLinkedList>
class LinkedList {
   
    Node<AbstractLinkedList>* head;
    public:
        LinkedList() : head(nullptr) {}

        void pushHead(AbstractLinkedList data){
            Node<AbstractLinkedList>* newNode = new Node<AbstractLinkedList>(data);

            newNode->createNextNode(head);
            head = newNode;
        }

        void getNodes() const {
            Node<AbstractLinkedList>* currentNode = head;

            while(currentNode != nullptr){
                cout << currentNode->getNode() << endl;
                currentNode = currentNode->getNextNode();
            }

            cout << endl;
        }

        void deleteHeadNode(){
            if (head != nullptr){
                Node<AbstractLinkedList>* temp = head;
                head = head->getNextNode();
                delete temp;
            }
        }

        void updateHeadNode(AbstractLinkedList oldNodeData, AbstractLinkedList newNodeData){

            if (head == nullptr){
                return;
            }
            Node<AbstractLinkedList>* currentNode = head;

            while(currentNode != nullptr){
                if (currentNode->getNode() == oldNodeData){
                    currentNode->data = newNodeData;
                    return;
                }
                // currentNode = currentNode->getNextNode();
            }
           
        }
    
};