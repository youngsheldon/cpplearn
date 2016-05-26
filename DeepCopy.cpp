/* 
* @Author: anchen
* @Date:   2016-05-25 22:02:40
* @Last Modified by:   anchen
* @Last Modified time: 2016-05-25 22:48:04
*/

#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

class DeepCopy
{
public:
    DeepCopy(const char*pn);
    DeepCopy(DeepCopy & obj);
    ~DeepCopy();
    void showPname();
    void showSize();
    char* getPname();
    void operator=(DeepCopy &obj);
    char* pname;
    int size;
};

DeepCopy::DeepCopy(const char*pn)
{
    pname = new char[strlen(pn) + 1];
    if(pname != NULL)
        strcpy(pname,pn);
    size = strlen(pn);
    cout<<"DeepCopy()"<<endl;
}

DeepCopy::~DeepCopy()
{
    delete [] pname;
    size = 0;
    pname = NULL;
    cout<<"~DeepCopy()"<<endl;
}

void DeepCopy::showPname()
{
    printf("%s\n",pname);
}

void DeepCopy::showSize()
{
    cout<<size<<endl;
}

char* DeepCopy::getPname()
{
    return pname;
}

DeepCopy::DeepCopy(DeepCopy & obj)
{
    cout<<"DeepCopy::DeepCopy(DeepCopy & obj)"<<endl;
    pname = new char[strlen(obj.getPname() + 1)];
    if(pname != NULL)
        strcpy(pname,obj.getPname());
    size = obj.size;
}

void DeepCopy::operator=(DeepCopy &obj)
{
    cout<<"void DeepCopy::operator=(DeepCopy &obj)"<<endl;

    if(pname != NULL)
    {
        delete [] pname;
        pname = NULL;
        size = 0;
    }
    pname = new char[strlen(obj.getPname() + 1)];
    if(pname != NULL)
        strcpy(pname,obj.getPname());
    size = obj.size;
}


int main(){
    DeepCopy obj("sheldon");
    DeepCopy obj2("young");
    
    obj2.showPname();
    obj2 = obj;

    obj2.showPname();

    return 0;
}