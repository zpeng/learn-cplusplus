#include <iostream>

using namespace std;

template<class T>
class SmartPointer {
private:
    T* m_ptr;

public:
    // default constructor
    SmartPointer(T* myObject = nullptr): m_ptr(myObject) {
        cout << "Call SmartPointer default constructor!" << endl;
    }

    ~SmartPointer() {
        delete m_ptr;
    }

    // copy constructor
    SmartPointer(const SmartPointer& sp) {
        cout << "Call SmartPointer copy constructor!" << endl;
        m_ptr = new T;
        *m_ptr = *sp.m_ptr; // do deep copy, not the memory address but the content of the m_ptr
    }

    // copy assignment
    SmartPointer& operator=(const SmartPointer& sp) {
        cout << "Call SmartPointer copy assignment!" << endl;
        // check if ref to itself
        if (&sp == this) {
            return *this;
        }

        // release the resource we holds
        delete m_ptr;

        //deep copy
        m_ptr = new T;
        *m_ptr = *(sp.m_ptr);

        return *this;
    }


    // move constructor
    SmartPointer(SmartPointer&& sp): m_ptr(sp.m_ptr) {
        cout << "Call SmartPointer move constructor!" << endl;
        sp.m_ptr = nullptr;
    }

    // move assignment
    SmartPointer& operator =(SmartPointer&& sp){
        cout << "Call SmartPointer move assignment!" << endl;
        // check if ref to itself
        if (&sp == this) {
            return *this;
        }

        //release resource we are holding
        delete m_ptr;

        // move it
        m_ptr = sp.m_ptr;
        sp.m_ptr = nullptr;

        return *this;
    }

    //operator overloading
    T& operator *() { return *m_ptr; }
    T* operator ->() { return m_ptr; }
};

class MyObject {
public:
    // default constructor
    MyObject() {
        cout << "My Object generated!" << endl;
    }

    // destructor
    ~MyObject() {
        cout << "My Object is destroyed!" << endl;
    }
};

SmartPointer<MyObject> generateSmartPointer() {
	SmartPointer<MyObject> obj(new MyObject);
	return obj; // this return value will invoke the copy constructor
}

int main()
{

    /*
    //just try out some  way to initailize an object and see how the constructor and destructor are called

    {
    MyObject mbj1;
    }

    MyObject* mbj2 = new MyObject();
    delete mbj2;
    */

    // SmartPointer<MyObject> smt_p_default; // call default c'tor

    // SmartPointer<MyObject> smt_p(new MyObject); // call default c'tor

    // SmartPointer<MyObject> smt_p_cpc(smt_p); // call copy constructor

    // smt_p_cpc = smt_p; // call copy assignment

    // SmartPointer<MyObject> smt_p_rvo = generateSmartPointer(); // RVO happens here


    return 0;
}
