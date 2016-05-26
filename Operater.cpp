/* 
* @Author: anchen
* @Date:   2016-05-26 10:04:29
* @Last Modified by:   anchen
* @Last Modified time: 2016-05-26 10:28:58
*/

#include <iostream>

using namespace std;

class Oper
{
public:
    Oper(int a = 0,int b = 0)
    {
        this->a = a;
        this->b = b;
    }
    ~Oper(){}
    //+操作符重载
    Oper operator +(Oper &obj)
    {
        Oper tmp;
        tmp.a = a + obj.a;
        tmp.b = b + obj.b;
        return tmp;
    }
    //前置++
    Oper operator ++()
    {
        a++;
        b++;
        return *this;
    }
    //后置++
    Oper operator ++(int)
    {
        Oper temp = *this;
        a++;
        b++;
        return temp;
    }
    void show()
    {
        cout<<"a = "<<a<<endl;
        cout<<"b = "<<b<<endl;
    }
    private:
    int a;
    int b;
};

int main(){
    Oper obj;
    obj.show();
    Oper obj1(1,2);
    Oper obj2(3,4);
    obj = obj1 + obj2;
    obj.show();
    ++obj;
    obj.show();
    obj++;
    obj.show();
    return 0;
}