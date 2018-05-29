#include <iostream>
#include <string>

using namespace std;

class Member {
public:
    Member() {
        cout << "Call Member C'tor" << endl;
    };

    ~Member() {
        cout << "Call Member D'tor" << endl;
    }
};

class MyObject {
public:
    MyObject() {
        cout << "begin of MyObject  C'tor" << endl;

        string s = "OMG";
        throw s;
        cout << "end of MyObject  C'tor" << endl;
    };

    ~MyObject() {
        cout << "Call D'tor" << endl;
    }

};

int main()
{
    try{
        MyObject obj;
    } catch (string exp){
        cout << "catch " << exp <<  endl;
    } catch (...) {
        cout << "Catch exception" << endl;
    }

    return 0;
}
