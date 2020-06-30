//LinkList.h
#ifndef LINKLIST_H
#define LINKLIST_H

#include "Node.h"
template <class T>
class LinkList
{
private:
    Node<T> *front, *rear;      //表头和表尾指针
    Node<T> *prevPtr, *currPtr; //记录表当前遍历位置的指针，由插入和删除操作更新
    int size;                   //表中的元素个数
    int position;               //当前元素在表中的位置序号，有函数resert使用

    //函数成员
    //生成新的结点
    Node<T> *newNode(const T &item, Node<T> *ptrNext = nullptr);

    //释放结点
    void freeNode(Node<T> *p);

    //将链表L复制到当前表
    //被复制构造函数和“operator=”调用
    void copy(const LinkList<T> &L);

public:
    LinkList();                                   //构造函数
    LinkList(const LinkList<T> &L);               //复制构造函数
    LinkList<T> &operator=(const LinkList<T> &L); //重载赋值运算符
    ~LinkList();                                  //析构函数

    int getSize() const;  //返回链表中元素个数
    bool isEmpty() const; //链表是否为空

    void resert(int pos = 0);        //初始化游标位置
    void next();                     //使游标移动到下一个结点
    bool endOfList() const;          //游标是否到了结尾
    int currentPosition(void) const; //返回游标当前位置

    void insertFront(const T &item); //在表头插入结点
    void insertRear(const T &item);  //在表尾插入结点
    void insertAt(const T &item);    //在当前结点之前插入结点
    void insertAfter(const T &item); //在当前结点之后插入结点

    T deleteFront();       //删除头结点
    void deleteCurrent();  //删除当前结点
    T &data();             //返回对当前结点成员数据的引用
    const T &data() const; //返回对当前结点成员函数的常引用

    //清空链表：释放所有结点的内存空间，被析构函数和“operator=”调用
    void clear();
};

#endif