//
//  Student1.cpp
//  24学分管理系统
//
//  Created by 陈启蕾 on 2020/5/24.
//  Copyright © 2020 陈启蕾. All rights reserved.
//

#include "Student1.hpp"
#include<iomanip>
void Student::heading_display(){
    cout<<setiosflags(ios::left)<<setw(10)<<"学号";
    cout<<setw(10)<<"姓名";
    cout<<setw(10)<<"班级";
    cout<<setw(12)<<"基础课";
    cout<<setw(12)<<"专业课";
    cout<<setw(12)<<"选修课";
    cout<<setw(12)<<"人文课";
    cout<<setw(12)<<"实践课"<<endl;
    cout<<"------------------------------------------------------------"<<endl;
    
}
void Student::Student_display(){
    cout<<setiosflags(ios::left)<<setw(8)<<num<<setw(10)<<name<<setw(8)<<clas<<setw(10)<<jichu<<setw(8)<<zhuanye<<setw(8)<<xuanxiu<<setw(8)<<renwen<<setw(8)<<shijian<<endl;
    
}
void Student::setinformation(){
    cout<<"请输入学生信息"<<endl;
    cout<<"学号 "<<"姓名 "<<"班级 "<<"基础课学分 "<<"专业课学分 "<<"选修课学分 "<<"人文课学分 "<<"实践课学分 "<<endl;
    cin>>num>>name>>clas>>jichu>>zhuanye>>xuanxiu>>renwen>>shijian;
    cout<<"修改成功！"<<endl;
}
