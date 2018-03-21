#include <iostream>
#include <string>

using namespace std;

struct Node {
  Node* next;
  string value;

  Node(string s) {
    value = s;
    next = nullptr;
  }
};

struct LinkedList {
  Node* head;
};

void appendNode(LinkedList &list, Node &node){
    if (list.head  == nullptr) {
        list.head = &node;
    } else {
        Node* p = list.head;
        while(p->next != nullptr) {
            // loop to the end of the list
            p = p->next;
        }
        p->next = &node;
    }
}

void printList(LinkedList &list){
    Node* p = list.head;
    while(p != nullptr) {
        cout << p->value << " -> ";
        p = p->next;
    }
    cout << endl;
}

void reverseList(LinkedList &list){
   if (list.head == nullptr) return;

   Node* curr = list.head;
   Node* previous;
   Node* next = curr->next;
   curr->next = nullptr;

   while(next != nullptr) {
        previous = curr;
        curr = next;
        next = next->next;
        curr->next = previous;

   }

   list.head = curr;
}

void deleteNodeByValue(LinkedList &list, string s){
   // find and delete
   Node* p = list.head;
   Node* previous = p;
   while(p != nullptr){
        if (p->value == s) {
            // find the node, need to remove current one from the list
            previous->next = p->next;
        }

        previous = p;
        p = p->next;
   }
}

int main()
{
    LinkedList list;
    list.head = nullptr;
    Node a("A");
    appendNode(list, a);
    Node b("B");
    appendNode(list, b);
    Node c("C");
    appendNode(list, c);
    Node d("D");
    appendNode(list, d);
    Node e("E");
    appendNode(list, e);

    printList(list);

    // reverse a list
    reverseList(list);
    printList(list);

    // delete c
    deleteNodeByValue(list, "C");

    printList(list);

    return 0;
}
