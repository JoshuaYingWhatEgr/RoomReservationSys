//
// Created by JoshuaYingWhat on 2021/1/13.
//

#include "Student.h"

Student::Student() {

}

Student::Student(int id, string name, string password) {

    this->m_id = id;

    this->m_Name = name;

    this->m_psd = password;

}

void Student::operMenu() {

    cout << "欢迎学生: " << this->m_Name << "登录!" << endl;

    cout << "\t\t --------------------------------------\n";
    cout << "\t\t|                                     |\n";
    cout << "\t\t|             1.申请预约              |\n";
    cout << "\t\t|                                     |\n";
    cout << "\t\t|             2.查看自身预约              |\n";
    cout << "\t\t|                                     |\n";
    cout << "\t\t|             3.查看所有人预约              |\n";
    cout << "\t\t|                                     |\n";
    cout << "\t\t|             4.取消预约              |\n";
    cout << "\t\t|                                    |\n";
    cout << "\t\t|             0.注销登录              |\n";
    cout << "\t\t --------------------------------------\n";
    cout << "输入您的选择: ";

}

//申请预约
void Student::applyOrder() {

}

//查看自身预约
void Student::searchMyOrder() {

}

//显示所有人的预约
void Student::searchAllOrder() {

}

//取消预约
void Student::cancelOrder() {

}