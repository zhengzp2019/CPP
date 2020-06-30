//Node.h
#ifndef NODE_H
#define NODE_H

template <class T>
class Node
{
private:
    Node<T> *next;

public:
    T date;

    Node(const T &date, Node<T> *next = nullptr);
    Node();
    void insertAfter(Node<T> *p);    //在本结点后插入同一类型的结点p
    Node<T> *deleteAfter();          //删除本结点的后继节点，并返回其地址
    Node<T> *nextNode();             //获取后继结点的地址
    const Node<T> *nextNode() const; //获取后继结点的地址
};

//构造函数
template <class T>
Node<T>::Node(const T &date, Node<T> *next /*= nullptr*/) :next(next),date(date) {}

//返回后继结点的指针
template <class T>
Node<T> *Node<T>::nextNode()
{
    return next;
}

//返回后继结点的指针
template <class T>
const Node<T> *Node<T>::nextNode() const
{
    return next;
}

//在当前结点之后插入一个结点p
template <class T>
void Node<T>::insertAfter(Node<T> *p)
{
    p->next = next;
    next = p;
}

//删除当前结点的后继结点，并返回其地址
template <class T>
Node<T> *Node<T>::deleteAfter()
{
    Node<T> tempPtr = next;
    if (next == 0)
        return 0;
    else
    {
        next = tempPtr->next;
    }
    return tempPtr;
}

#endif