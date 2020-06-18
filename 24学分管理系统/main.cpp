//
//  main.cpp
//  24学分管理系统
//
//  Created by 陈启蕾 on 2020/5/19.
//  Copyright © 2020 陈启蕾. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "Student1.hpp"
#include "Studentlist.hpp"
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;



int main() {
    Student stu2;
    string Nu,Na,Clas;
    int jc,zy,xx,rw,sj;
    
    int e,f,g,i=0,fh=0,fh2=0;
    
    
    
    
    ifstream instudent("student.txt");
    if(!instudent){
        cout<<"error"<<endl;
        
    }
    Studentlist slist;
    while(instudent>>Nu>>Na>>Clas>>jc>>zy>>xx>>rw>>sj){
        
        Student stu(Nu,Na,Clas,jc,zy,xx,rw,sj);
        slist.studentadd(stu);
      
    }
    
    
    int i1=0,i2;
    while(i1!=-1){
        i1=0,i2=0;
        i=0;
        cout<<"\t\t★☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆★\n";
        cout<<"\t\t☆                                     ☆\n";
        cout<<"\t\t☆          ★☆学分管理系统☆★           ☆\n";
        cout<<"\t\t☆         [1]查询学生学分信息            ☆\n";
        cout<<"\t\t☆         [2]修改学生学分信息            ☆\n";
        cout<<"\t\t☆                                     ☆\n";
        cout<<"\t\t☆                                     ☆\n";
        cout<<"\t\t★☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆★\n\n";
        cout<<"\t\t         请选择（1/2，-1为结束）：          \n";
        
        cin>>i1;
        
        //system("clear");
  
        switch(i1){
            case 1:
                while(i!=-1){
                    fh=0;
                    cout<<"——————————————————分割线————————————————\n";
                    cout<<"         1.按照学号查找学生学分信息         \n";
                    cout<<"         2.按照班级查找学生学分信息         \n";
                    cout<<"         3.按照各科学分查看排序            \n";
                    cout<<"         请选择（1/2，输入-1返回上层结构）   \n";
                    cin>>i;
                    system("clear");
                    switch(i){
                        case 1:
                            while(fh!=-1){
                                cout<<"请输入学号："<<endl;
                                string num1;
                                cin>>num1;
                                Student* stuu=slist.findnum(num1);
                                stuu->heading_display();
                                stuu->Student_display();
                                cout<<"请输入任意数字返回："<<endl;
                                cin>>fh;
                                fh=-1;
                            }break;
                            
                        case 2:
                            while(fh!=-1){
                                cout<<"请输入班级："<<endl;
                                string clas1;
                                cin>>clas1;
                                slist.findclas(clas1);
                                cout<<"请输入任意数字返回："<<endl;
                                cin>>fh;
                                fh=-1;
                                
                            }break;
                            
                        case 3:
                            while(fh!=-1){

                                cout<<"1.基础课 2.专业课 3.选修课 4.人文课 5.实践课"<<endl;
                                cout<<"请输入课程编号:"<<endl;
                                Student* stup=slist.getp();
                                int bian;
                                cin>>bian;
                               
                                switch(bian){
                                    case 1:
                                        slist.sort_jichu(stup);
                                        slist.display();
                                        cout<<"请输入任意数字返回："<<endl;
                                        cin>>fh;
                                        fh=-1;
                                        break;
                                    case 2:
                                        slist.sort_zhuanye(stup);
                                        slist.display();
                                        cout<<"请输入任意数字返回："<<endl;
                                        cin>>fh;
                                        fh=-1;
                                        break;
                                    case 3:
                                        slist.sort_xuanxiu(stup);
                                        slist.display();
                                        cout<<"请输入任意数字返回："<<endl;
                                        cin>>fh;
                                        fh=-1;
                                        break;
                                    case 4:
                                        slist.sort_renwen(stup);
                                        slist.display();
                                        cout<<"请输入任意数字返回："<<endl;
                                        cin>>fh;
                                        fh=-1;
                                        break;
                                    case 5:
                                        slist.sort_shijian(stup);
                                        slist.display();
                                        cout<<"请输入任意数字返回："<<endl;
                                        cin>>fh;
                                        fh=-1;
                                        break;
                                    default:
                                        cerr<<"输入错误！"<<endl;
                                        break;
                                        
                                }
                            }
                            
                    }
                }
                break;
                
                
            case 2:
                while(i2!=-1){
                    fh2=0;
                    cout<<"——————————————分割线————————————————"<<endl;
                    cout<<"        1.通过学号修改学生学分         "<<endl;
                    cout<<"        2.增加学生信息               "<<endl;
                    cout<<"        3.通过学号移除学生信息         "<<endl;
                    cout<<"请选择（1/2/3，输入-1返回上层结构)      "<<endl;
                    cin>>i2;
                    switch(i2){
                            
                        case 1:
                            while(fh2!=-1){
                                cout<<"请输入学号:"<<endl;
                                string num4;
                                cin>>num4;
                                slist.editc(num4);
                                cout<<"请输入任意数字返回："<<endl;
                                cin>>fh2;
                                fh2=-1;
                            }
                            break;
                            
                        case 2:
                            while(fh2!=-1){
                                cout<<"请依次输入学生信息(学号、姓名、班级、基础、专业、选修、人文、实践）:"<<endl;
                                string numm,namee,classs;
                                int j,z,x,r,s;
                                cin>>numm>>namee>>classs>>j>>z>>x>>r>>s;
                                Student newstu(numm,namee,classs,j,z,x,r,s);
                                slist.studentadd(newstu);
                                cout<<"请输入任意数字返回："<<endl;
                                cin>>fh2;
                                fh2=-1;
                            }
                            break;
                            
                        case 3:
                            while(fh2!=-1){
                                cout<<"请输入要移除学生的学号："<<endl;
                                string numm;
                                cin>>numm;
                                slist.studentremove(numm);
                                cout<<"请输入任意数字返回："<<endl;
                                cin>>fh2;
                                fh2=-1;
                            }
                            break;
                    }
                }
                break;
                
            case -1:
                i1=-1;
                break;
                
            default :
                cerr<<"输入错误!"<<endl;
                i1=-1;
                break;
                
                
                
        }

        
        
    }
    
    slist.write();
//    slist.~Studentlist();
    cout<<"谢谢使用！"<<endl;
    return 0;
    
    
    
}
