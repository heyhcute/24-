//
//  Student1.hpp
//  24学分管理系统
//
//  Created by 陈启蕾 on 2020/5/24.
//  Copyright © 2020 陈启蕾. All rights reserved.
//

#ifndef Student1_hpp
#define Student1_hpp
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
class Student{
public:
    string num;//学号
    string name;//姓名
    string clas;//班级
    int jichu;//基础课学分
    int zhuanye;//专业课学分
    int xuanxiu;//选修课学分
    int renwen;//人文课学分
    int shijian;//实践课学分
    
    
    Student(string nu):num(nu){};

    Student(string num1="null",string nam1="null",string clas1="null",int ji1=0,int zhuan1=0,int xuan1=0,int ren1=0,int shi1=0):num(num1),name(nam1),clas(clas1),jichu(ji1),zhuanye(zhuan1),xuanxiu(xuan1),renwen(ren1),shijian(shi1){}//构造函数初始化
    Student *next;
    Student *getnext()const{
        return next;
    }
    string getnum()const{return num;}//获取学号
    string getname()const{return name;}//获取姓名
    string getclas()const{return clas;}//获取班级
    int getjichu()const{return jichu;}//获取基础课学分
    int getzhuanye()const{return zhuanye;}//获取专业课学分
    int getxuanxiu()const{return xuanxiu;}//获取选修课学分
    int getrenwen()const{return renwen;}//获取人文课学分
    int getshijian()const{return shijian;}//获取实践课学分
    
    void setinformation();//
    
    void heading_display();//
    void Student_display();//
    
    bool operator ==(const Student &stu){return(num==stu.num);}//
};

#endif /* Student1_hpp */
