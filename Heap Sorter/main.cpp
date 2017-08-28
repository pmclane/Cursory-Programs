#include "Heap.cpp"
#include <iostream>
#include <random>
#include <ctime>
using namespace std;

int main()
{
    Heap testHeap;
    srand(time(NULL));
    for (int i = 0; i < 50; i++)
    {
       int choice = rand() % 160;
       testHeap.AddMember(choice);
    }

    cout << "UNSORTED HEAP" << endl;
    testHeap.ListAllMembers();
    system("pause");
    cout << endl << "ORDERED HEAP" << endl;
    testHeap.OrderMembers();
    testHeap.ListAllMembers();
    system("pause");
    cout << endl << "SORTED HEAP" << endl;
    testHeap.SortHeap();
    testHeap.ListAllMembers();
    system("pause");

    return 0;
}
