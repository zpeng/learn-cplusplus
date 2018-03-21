#include <iostream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

struct LinkedListNode {
    int value;
    LinkedListNode* next;

    LinkedListNode(int nodeValue){
        value = nodeValue;
        next = 0;
    }
};

LinkedListNode* appendNode(LinkedListNode *head, int value){
    LinkedListNode *node = new LinkedListNode(value);

    if (head == nullptr) {
        head = node;
    }else{
        LinkedListNode* current;
        current = head;
        while(current->next != nullptr){
            current = current->next;
        }
        current->next = node;
    }

    return head;
}

void findMostOccured(LinkedListNode *head){
    std::map<int, int> maxMap;

    LinkedListNode *p = head;
    while(p != nullptr){
        maxMap[p->value] +=  1;
        p = p->next;
    }

    p = head;
    int r_v = 0;
    int r_c = 0;
    while(p != nullptr){
        // reads count from the map
        if (maxMap[p->value] > r_c) {
            // here always keep in a such state that count is a max and value is closest to the head
            r_c = maxMap[p->value];
            r_v = p->value;
        }

        p = p-> next;
    }

    cout << "Element " << r_v << " occurs " << r_c << " time(s)";
}

void printLinkedList(LinkedListNode *head){
    LinkedListNode *current = head;
    while(current != nullptr) {
        cout << current->value << " ";
        current = current->next;
    }
}


int main()
{
    LinkedListNode *head = nullptr;

    string line;
    std::getline(std::cin, line);
    std::istringstream os(line);

    int i;
    while(os >> i) {
        // lets append list
        cout << "-->" << i << endl;
        head = appendNode(head, i);
    }

    //printLinkedList(head);

    findMostOccured(head);
    return 0;
}
