//
//  Studentlist.hpp
//  24学分管理系统
//
//  Created by 陈启蕾 on 2020/5/24.
//  Copyright © 2020 陈启蕾. All rights reserved.
//

#ifndef Studentlist_hpp
#define Studentlist_hpp

#include<iostream>
#include<string>
#include"Student1.hpp"

using namespace std;
class Studentlist:public Student{
private:
    int size;
    Student *p;
public:
    Studentlist():p(0),size(0){};
    
    Student *findnum(string &nu);//输入学号查找学生
    
    
    Student* getp (){
        return p;
    }
    void editc(string &nu);//输入学号修改学生学分
    
    void findclas(string &clas);//输入班级显示所有学生学分完成情况
    
    
    
    void studentadd(Student &stu);//添加学生信息
    void studentremove(string nu);//移除学生信息
    
    void sort_jichu(Student* &head);//按照基础课学分排序
    void sort_zhuanye(Student* &head);//按照专业课学分排序
    void sort_xuanxiu(Student* &head);//按照选修课学分排序
    void sort_renwen(Student* &head);//按照人文课程学分排序
    void sort_shijian(Student* &head);//按照时间课程学分排序


    void display();
    void write();
    
    
    
    ~Studentlist();

    
};
#endif /* Studentlist_hpp */
