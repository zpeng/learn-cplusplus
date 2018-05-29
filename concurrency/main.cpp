#include <iostream>
#include <thread>
using namespace std;

void workingTask(int i) {
    cout << "Within thread of " << i << endl;
}

int main()
{
    thread th(&workingTask, 100);
    th.join();

    cout << "Outside thread!" << endl;
    return 0;
}


int accum = 0;
mutex accum_mutex;
void square(int x) {
    int temp = x * x;
    accum_mutex.lock();
    accum += temp;
    accum_mutex.unlock();
}


#include <atomic>
atomic<int> accum(0);
void square(int x) {
    accum += x * x;
}


