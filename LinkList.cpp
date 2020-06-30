//LinkList.cpp
#include "LinkList.h"

//生成新节点，数据域为item,指针域为ptrNext
template <class T>
Node<T> *LinkList<T>::newNode(const T &item, Node<T> *ptrNext /*=nullptr*/)
{
    Node<T> *p = new Node<T>(item);
    p->insertAfter(ptrNext);
    return p;
}

//构造函数
template <class T>
LinkList<T>::LinkList()
{

    front = newNode(0);
    front->insertAfter(nullptr);
    rear = front;
    prevPtr = front;
    currPtr = prevPtr->nextNode();
    size = 0;
    position = 0;
}

//将链表L复制到当前表
//被复制构造函数和“operator=”调用
template <class T>
void LinkList<T>::copy(const LinkList<T> &L)
{
    front = newNode(0);
    front->next = nullptr;
    rear = front;
    prevPtr = front;
    currPtr = prevPtr->next;
    size = 0;
    position = 0;
    L.prevPtr = L.front;
    L.currPtr = L.front->next;
    while (L.currPtr)
    {
        currPtr = newNode(L.currPtr->data);
        prevPtr->next = currPtr;
        rear = currPtr;
        prevPtr = currPtr;
        currPtr = prevPtr->next;
        position++;
        size++;
    }
}

//复制构造函数
template <class T>
LinkList<T>::LinkList(const LinkList<T> &L)
{
    copy(L);
}

//析构函数
template <class T>
LinkList<T>::~LinkList()
{
    Node<T> *p = front, *t;
    while (p != rear)
    {
        t = p;
        p = p->nextNode();
        delete t;
    }
    t = rear;
    delete t;
}

//重载赋值运算符
template <class T>
LinkList<T> &LinkList<T>::operator=(const LinkList<T> &L)
{
    this->copy(L);
    return *this;
}

//返回链表中的元素个数
template <class T>
int LinkList<T>::getSize() const
{
    return size;
}

//链表是否为空
template <class T>
bool LinkList<T>::isEmpty() const
{
    if (front == rear)
        return true;
    else
        return false;
}

//初始化游标位置
template <class T>
void LinkList<T>::resert(int pos /*=0*/)
{
    position = pos;
    if (pos == 0)
    {
        prevPtr = nullptr;
        currPtr = front;
        return;
    }
    int cnt = 1; //当前结点的位置
    prevPtr = front;
    currPtr = prevPtr->nextNode();
    while (cnt != position)
    {
        cnt++;
        prevPtr = currPtr;
        currPtr = currPtr->nextNode();
    }
}

//使游标移动到下一个结点
template <class T>
void LinkList<T>::next()
{
    position++;
    prevPtr = currPtr;
    currPtr = currPtr->nextNode();
}

//游标是否移动到了链尾
template <class T>
bool LinkList<T>::endOfList() const
{
    if (currPtr == nullptr)
        return true;
    else
        return false;
}

//返回游标当前位置
template <class T>
int LinkList<T>::currentPosition(void) const
{
    return position;
}

//在表头插入结点
template <class T>
void LinkList<T>::insertFront(const T &item)
{
    Node<T> *p = new Node<T>();
    p->date = item;
    if (this->isEmpty())
    {
        rear = p;
    }
    p->insertAfter(front->nextNode());
    front->insertAfter(p);
}

//在表尾添加结点
template <class T>
void LinkList<T>::insertRear(const T &item)
{
    Node<T> *p = new Node<T>;
    p->date = item;
    p->next = rear->next;
    rear->next = p;
    rear = p;
}

//在当前结点之前插入结点
template <class T>
void LinkList<T>::insertAt(const T &item)
{
    Node<T> *p = new Node<T>;
    p->date = item;
    p->next = currPtr;
    prevPtr->next = p;
}

//在当前结点之后插入结点
template <class T>
void LinkList<T>::insertAfter(const T &item)
{
    Node<T> *p = new Node<T>;
    p->date = item;
    p->next = currPtr->next;
    currPtr->next = p;
}

//清空链表
template <class T>
void LinkList<T>::clear()
{
    this->~LinkList();
}

//返回对当前结点成员数据的引用
template <class T>
T &LinkList<T>::data()
{
    return currPtr->date;
}

//返回对当前结点成员数据的常引用
template <class T>
const T &LinkList<T>::data() const
{
    return currPtr->date;
}