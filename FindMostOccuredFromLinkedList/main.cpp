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
    std::vector<int> countArr = {0,0,0,0,0,0,0,0,0,0};


    LinkedListNode *p = head;
    while(p != nullptr){
        countArr[p->value] += 1;
        p = p->next;
    }

    std::map<int, int> maxMap;
    int max_v = 0;
    int max_p = 0;
    for(auto i: countArr){
        if (i == max_v) {
            // just add to the map
            maxMap.insert(std::make_pair(max_p, i));
        } else if (i > max_v){
             max_v = i;
             maxMap.clear();
             maxMap.insert(std::make_pair(max_p, i));
        }
        ++max_p;
    }

    p = head;
    int r_v = 0;
    int r_c = 0;
    while(p != nullptr){
        if(maxMap.count(p->value)) {
            r_v = p->value;
            r_c = maxMap[p->value];
            break;
        }
        p = p->next;
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
