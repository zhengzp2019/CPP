#include <iostream>
#include "LinkList.cpp"
using namespace std;

int main()
{
    LinkList<int> L;

    //输入10个整数依次向表头插入
    for (int i = 1; i <= 10; i++)
    {
        int item;
        cin >> item;
        L.insertFront(item);
    }

    //输出链表
    cout << "L: ";
    L.resert();

    //输出各节点的值直到链表尾
    while (!L.endOfList())
    {
        cout << L.data() << " ";
        L.next();
    }
    cout << "链表元素个数尾： " << L.getSize() << endl;

    // 输入需要查找的整数
    int key;
    cout << "请输入需要查找的整数:";
    cin >> key;

    //查找结点,若输出结点位置
    L.resert();
    while (!L.endOfList())
    {
        if (L.data() == key)
        {
            cout << L.currentPosition() << endl;
        }
        L.next();
    }

    //输出链表
    cout << "L: ";
    L.resert();

    //输出各节点的值直到链表尾
    while (!L.endOfList())
    {
        cout << L.data() << " ";
        L.next();
    }
    cout << "链表元素个数尾： " << L.getSize() << endl;
    L.clear();

    return 0;
}