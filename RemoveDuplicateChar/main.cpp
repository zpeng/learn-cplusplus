#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;


void removeDuplicateChar(string &in){
    string temp;
    std::set<char> uniqueSet;
    for(char &c: in) {
        uniqueSet.insert(c);
    }

    for(char &c: in){
        if (uniqueSet.count(c) > 0) {
            //find this char
            temp += c;
            uniqueSet.erase(c);
        }
    }
    in = temp;
    cout << in << endl;
}

int main()
{
    string _in;
    getline(cin, _in);

    removeDuplicateChar(_in);

    cout << _in << endl;
    return 0;
}
