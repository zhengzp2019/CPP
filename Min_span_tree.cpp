#include <iostream>
#include <vector>
#define INF 32767 //权值为无穷大
using namespace std;

typedef struct TNode //树节点
{
    struct TNode *next; //相邻的结点
    int name;           //结点名
    int weight;         //边的权重
} TNode;

typedef struct Arc //弧以及连接弧的两结点
{
    int first;
    int rear;
    int weight;
} Arc;

void Input(vector<vector<int>> &G, int length);                          //输入图的信息
int Min_span_tree(vector<vector<int>> &G, vector<TNode> &T, int length); //最小生成树算法,输入为图和树的存储空间，返回树的权重之和
int Min(vector<Arc> &Min_dis, int length);                               //求树节点集合到非树结点集合距离的最小值,输入为图和两集和距离信息，输出为到树最小值的结点

void Input(vector<vector<int>> &G, int length)
{
    cout << "请输入图的权值信息，" << length << "x" << length << "的矩阵" << endl;
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            cin >> G[i][j];
        }
    }
}

//最小生成树算法,输入为图和树的存储空间，返回树的权重之和
int Min_span_tree(vector<vector<int>> &G, vector<TNode> &T, int length)
{
    int boot;                    //根节点
    int min_node;                //距离最小的结点
    int num = length;            //记录非树结点数目
    vector<Arc> Min_dis(length); //树节点集合到非树结点集合的最小值
    cout << "请输入最小生成树的根节点" << endl;
    cin >> boot;
    num--;
    T[boot].next = NULL;
    T[boot].name = boot;
    T[boot].weight = 0;
    for (int i = 0; i < length; i++)
    {
        Min_dis[i].weight = G[boot][i];
        Min_dis[i].first = boot;
        Min_dis[i].rear = i;
    }
    int sum = 0;     //最小生成树的权重之和
    int rear, first; //每次找到两集和间距离最小值的边的两结点
    do
    {
        min_node = Min(Min_dis, length); //找到距离树节点集合最小的非树结点
        first = Min_dis[min_node].first;
        rear = Min_dis[min_node].rear;
        //将该结点挂到树上
        TNode *p, *q;
        p = &T[first];
        q = p->next;
        while (q != NULL)
        {
            p = q;
            q = q->next;
        }
        q = new TNode;
        q->next = NULL;
        q->name = rear;
        q->weight = Min_dis[min_node].weight;
        p->next = q;
        p = &T[rear];
        q = p->next;
        while (q != NULL)
        {
            p = q;
            q = q->next;
        }
        q = new TNode;
        q->next = NULL;
        q->name = first;
        q->weight = Min_dis[min_node].weight;
        p->next = q;

        sum += Min_dis[min_node].weight;
        Min_dis[min_node].weight = INF + 5; //将该节点进入树节点集合
        //更新两集合间的最短距离
        for (int i = 0; i < length; i++)
        {
            if (G[min_node][i] < Min_dis[i].weight && Min_dis[i].weight != 0)
            {
                Min_dis[i].weight = G[min_node][i];
                Min_dis[i].first = min_node;
            }
        }
    } while (--num);
    return sum;
}

//求树节点集合到非树结点集合距离的最小值,输入为，图和两集和距离信息,输出为到树距离最小值的结点
int Min(vector<Arc> &Min_dis, int length)
{
    int k = 0;     //最小值下标
    int min = INF; //最小值
    for (int i = 0; i < length; i++)
    {
        if (Min_dis[i].weight < min && Min_dis[i].weight != 0)
        {
            k = i;
            min = Min_dis[i].weight;
        }
    }
    return k;
}

int main()
{
    int length; //结点长度
    cout << "请输入图结点数目" << endl;
    cin >> length;
    vector<vector<int>> G(length, vector<int>(length)); //存储图的权值
    vector<TNode> T(length);                            //存储树
    //初始化T
    for (int i = 0; i < length; i++)
    {
        T[i].name = i;
        T[i].next = NULL;
        T[i].weight = 0;
    }
    Input(G, length);
    int sum = Min_span_tree(G, T, length);
    cout << "最小生成树的权值之和为：" << sum << endl;
    return 0;
}