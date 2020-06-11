#include <iostream>
using namespace std;
class Employee
{
private:
    string name;
    string add;
    string city;
    string postcode;

public:
    Employee(string name, string add, string city, string pc) : name(name), add(add), city(city), postcode(pc)
    {
    }
    ~Employee()
    {

    }
    void setName(string nm)
    {
        name = nm;
    }
    void display()
    {
        cout << "姓名：" << name << "   地址：" << add
             << "   城市：" << city << "    邮编：" << postcode << endl;
    }
};

int main()
{
    string name, add, city, postcode;
    cout << "请输入职工姓名、地址、城市、邮编\n";
    cin >> name >> add >> city >> postcode;
    Employee e(name, add, city, postcode);
    e.display();
    cout << "请输入职工修改后的姓名：";
    cin >> name;
    e.setName(name);
    cout << "修改后信息如下：" << endl;
    e.display();
}