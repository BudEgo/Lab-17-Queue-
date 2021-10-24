#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include "Source.cpp"
int main()
{
    using namespace std;

    Queue<Point> Q1;
    Point p1(15, 344, 457);
    Point p2(8, 5, 4);
    Point p3(88, 5, 4);
    Q1.enque(p2);
    Q1.enque(p1);
    Q1.enque(p3);
    cout << "Queue " << Q1.getsize() << " slots: " << Q1 << "\n";
    cout << "Dequeing: " << Q1.deque() << "\n";
    Queue<char> Q2;
    Q2.enque('a');
    Q2.enque('l');
    Q2.enque('i');
    Q2.enque('n');
    Q2.enque('a');
    
    cout << Q2 << "\n";
    Q2.deque();
    cout << Q2 << "\n";
    Q2.enque('m');
    cout << Q2 << "\n";
    return 0;
    
}