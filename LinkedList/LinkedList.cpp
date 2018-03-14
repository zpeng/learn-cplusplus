// LinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

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

void printList(Node* node){
  cout << node->value << " -> ";
  if (node->next != nullptr) printList(node->next); 
}

Node* deleteNode(Node* head, Node* nodeToDelete){
  if (head == nodeToDelete) {
    return head->next;
  }

  if (head->next == nullptr) {
    return head->next;
  }

  if (head->next == nodeToDelete) {
    head->next = head->next->next;
  }

  // keep looking recursively
  return deleteNode(head->next, nodeToDelete);
}

Node* reverseList(Node* node){
  Node* current = node->next;
  node->next = nullptr;

  Node* next = current->next;
  current->next = node;

  Node* previous;

  while(next != nullptr) {
    previous = current;
    current = next;
    next = next->next;
    current->next = previous;
  }

  return current;

}


int _tmain(int argc, _TCHAR* argv[])
{
  Node nodeA("A");
  Node nodeB("B");
  Node nodeC("C");
  Node nodeD("D");
  Node nodeE("E");
  nodeA.next = &nodeB;
  nodeB.next = &nodeC;
  nodeC.next = &nodeD;
  nodeD.next = &nodeE;
  nodeE.next = nullptr;

  LinkedList linkedList;
  linkedList.head = &nodeA;

  printList(linkedList.head);
  cout << endl;

  deleteNode(linkedList.head, &nodeC);
  
  printList(linkedList.head);
  cout << endl;

  linkedList.head = reverseList(linkedList.head);

  printList(linkedList.head);
  cout << endl;

  int i = 0;
  cin >> i;
	return 0;
}

