//
// Created by JoshuaYingWhat on 2021/1/13.
//

using namespace std;

#include "Identity.h"

#include <iostream>

#ifndef ROOMRESERVATIONSYS_STUDENT_H
#define ROOMRESERVATIONSYS_STUDENT_H


class Student : public Identity {

public :

    Student();

    Student(int id, string name, string password);

    virtual void operMenu();

    //申请预约
    void applyOrder();

    //查看自身预约
    void searchMyOrder();

    //显示所有人的预约
    void searchAllOrder();

    //取消预约
    void cancelOrder();

    //学生学号
    int m_id;

    //姓名
    string m_name;

    //密码
    string m_psd;
};


#endif //ROOMRESERVATIONSYS_STUDENT_H
