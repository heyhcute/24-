//
//  Studentlist.cpp
//  24学分管理系统
//
//  Created by 陈启蕾 on 2020/5/24.
//  Copyright © 2020 陈启蕾. All rights reserved.
//

#include "Studentlist.hpp"
#include<fstream>
//----------------通过学号查找学生
Student* Studentlist::findnum(string&nu){
    Student*m;
    for(m =p;m;m=m->next){
        if(m->num==nu){
            return m;
        }
    }
    if(m==NULL){
        cerr<<"无法通过学号查找到该学生的信息！"<<endl;
    }
    return 0;
}

//----------------通过学号修改学生学分
void Studentlist::editc(string &nu){
    Student* sp=findnum(nu);
    cout<<"1.修改基础课学分"<<endl;
    cout<<"2.修改专业课学分"<<endl;
    cout<<"3.修改选修课学分"<<endl;
    cout<<"4.修改人文类课程学分"<<endl;
    cout<<"5.修改实践性课课程学分"<<endl;
    cout<<"请选择（输入-1返回上一级）"<<endl;
    int n=0,xin=0;
    
    while(n!=-1){
        cin>>n;
        switch (n) {
            case 1:
                cout<<"请输入新的基础课学分："<<endl;
                cin>>xin;
                sp->jichu=xin;
                cout<<"修改成功！"<<endl;
                cout<<"如果停止修改，请输入-1"<<endl;
                cout<<"如果继续修改，请再次输入1～5"<<endl;
                break;
            case 2:
                cout<<"请输入新的专业课学分："<<endl;
                cin>>xin;
                sp->zhuanye=xin;
                cout<<"修改成功！"<<endl;
                cout<<"如果停止修改，请输入-1"<<endl;
                cout<<"如果继续修改，请再次输入1～5"<<endl;
                break;
            case 3:
                cout<<"请输入新的选修课学分："<<endl;
                cin>>xin;
                sp->xuanxiu=xin;
                cout<<"修改成功！"<<endl;
                cout<<"如果停止修改，请输入-1"<<endl;
                cout<<"如果继续修改，请再次输入1～5"<<endl;
                break;
            case 4:
                cout<<"请输入新的人文类课程学分："<<endl;
                cin>>xin;
                sp->renwen=xin;
                cout<<"修改成功！"<<endl;
                cout<<"如果停止修改，请输入-1"<<endl;
                cout<<"如果继续修改，请再次输入1～5"<<endl;
                break;
            case 5:
                cout<<"请输入新的实践性课程学分："<<endl;
                cin>>xin;
                sp->shijian=xin;
                cout<<"修改成功！"<<endl;
                cout<<"如果停止修改，请输入-1"<<endl;
                cout<<"如果继续修改，请再次输入1～5"<<endl;
                break;
            default:
                break;
        }
    }
    cout<<"修改如你所愿！"<<endl;
}


//----------------通过班级查看该班学生的学分情况
void Studentlist::findclas(string& clas){
    heading_display();
    Student *m;
    int f=0;int uf=0;
    string clla;
    for(m=p;m;m=m->next){
        if(m->clas==clas){
           
            m->Student_display();
            if(m->jichu>=50&&m->zhuanye>=50&&m->xuanxiu>=24&&m->renwen>8&&m->shijian>=20)
                f++;
            else
                uf++;
        }
        break;
    }
    
    if(m==NULL){
        cout<<"无法找到该班级的学生！"<<endl;
    }
    else{
   
         //统计该班级学分完成情况
        cout<<m->clas<<"中有"<<f<<"位同学完成所有学分！！！"<<endl;
        cout<<m->clas<<"中有"<<uf<<"位同学还未完成所有学分！！！"<<endl;
    
    }
    
    
}


//-------------添加新学生信息到链表
void Studentlist::studentadd(Student &stu){
    Student *pn=new Student(stu);
    if(p){
        pn->next=p;
    }
    if(!p){
        pn->next=NULL;
    }
    p=pn;
}

//------------移除学生信息
void Studentlist::studentremove(string nu){
    Student* st;
    for(st=p;st;st=st->next){
        if(st->num==nu){
            st=st->next;
            delete st;
            break;
        }
    }
    if(st==NULL){
        cout<<"无法找到该学生！"<<endl;
    }
    
}

//-----------按照基础课进行学分高低排序
void Studentlist::sort_jichu(Student* &head ){
    /*
    Student* p1= head->next,*pre=NULL;
    Student* r=p1->next;
    p1->next=NULL;
    p1=r;
    while(p1!=NULL){
        r=p1->next;
        pre=head;
        while(pre->next!=NULL&&pre->next->jichu>p1->jichu){
            pre=pre->next;
        }
        p1->next=pre->next;
        pre->next=p1;
        p=r;
    }
    
     */
    for(Student* temp=head->next;temp->next!=NULL;temp=temp->next)
        for(Student* p1=head->next;p1->next!=NULL;p1=p1->next)
            if(p1->jichu<p1->next->jichu){
                int t=p1->jichu;
                p1->jichu=p1->next->jichu;
                p1->next->jichu=t;
            }
}

//-----------按照专业课进行学分高低排序
void Studentlist::sort_zhuanye(Student* &head ){
    for(Student* temp=head->next;temp->next!=NULL;temp=temp->next)
    for(Student* p1=head->next;p1->next!=NULL;p1=p1->next)
        if(p1->zhuanye<p1->next->zhuanye){
            int t=p1->jichu;
            p1->zhuanye=p1->next->zhuanye;
            p1->next->zhuanye=t;
        }
}

//-----------按照选修课进行学分高低排序
void Studentlist::sort_xuanxiu(Student* &head ){
    for(Student* temp=head->next;temp->next!=NULL;temp=temp->next)
    for(Student* p1=head->next;p1->next!=NULL;p1=p1->next)
        if(p1->xuanxiu<p1->next->xuanxiu){
            int t=p1->xuanxiu;
            p1->xuanxiu=p1->next->xuanxiu;
            p1->next->xuanxiu=t;
        }
} 

//-----------按照人文课进行学分高低排序
void Studentlist::sort_renwen(Student* &head ){
    for(Student* temp=head->next;temp->next!=NULL;temp=temp->next)
    for(Student* p1=head->next;p1->next!=NULL;p1=p1->next)
        if(p1->renwen<p1->next->renwen){
            int t=p1->renwen;
            p1->renwen=p1->next->renwen;
            p1->next->renwen=t;
        }
}

//-----------按照实践课进行学分高低排序
void Studentlist::sort_shijian(Student* &head ){
    for(Student* temp=head->next;temp->next!=NULL;temp=temp->next)
    for(Student* p1=head->next;p1->next!=NULL;p1=p1->next)
        if(p1->shijian<p1->next->shijian){
            int t=p1->shijian;
            p1->shijian=p1->next->shijian;
            p1->next->shijian=t;
        }
}


//-----------输出
void Studentlist::display(){
    heading_display();
    for(Student* stu=p;stu;stu=stu->next){
        stu->Student_display();
    }
}

//-----------输到文件里
void Studentlist::write(){
    ofstream output("Student.txt");
    
    for(Student* stu=p;stu!=NULL;stu=stu->next){
        output<<stu->num<<"    "<<stu->name<<"    "<<stu->clas<<"    "<<stu->jichu<<"    "<<stu->zhuanye<<"    "<<stu->xuanxiu<<"    "<<stu->renwen<<"    "<<stu->shijian<<endl;
        
    }
}

//----------析构函数
Studentlist::~Studentlist(){
    for(Student* stu=p;stu;delete stu){
        stu=stu->next;
    }
}
