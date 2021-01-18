//
// Created by JoshuaYingWhat on 2021/1/13.
//

#include <fstream>
#include "Manager.h"

#include "globalFile.h"

Manager::Manager() {

}

Manager::Manager(string name, string password) {

    //初始化管理员的用户名和密码
    this->m_Name = name;

    this->m_Psd = password;

}

void Manager::operMenu() {

    cout << "欢迎管理员: " << this->m_Name << "登录!" << endl;

    cout << "\t\t --------------------------------------\n";
    cout << "\t\t|                                     |\n";
    cout << "\t\t|             1.添加账户              |\n";
    cout << "\t\t|                                     |\n";
    cout << "\t\t|             2.查看账户              |\n";
    cout << "\t\t|                                     |\n";
    cout << "\t\t|             3.查看机房              |\n";
    cout << "\t\t|                                     |\n";
    cout << "\t\t|             4.清空预约              |\n";
    cout << "\t\t|                                    |\n";
    cout << "\t\t|             0.注销登录              |\n";
    cout << "\t\t --------------------------------------\n";
    cout << "输入您的选择: ";

}

//添加账号
void Manager::addAccount() {

    cout << "请输入添加账号的类型" << endl;

    cout << "1.学生账号" << endl;

    cout << "2.老师账号" << endl;

    string file_name;

    string tips;

    ofstream ofs;

    int select = 0;

    cin >> select;

    if (select == 1) {

        file_name = STUDENT_FILE;

        tips = "请输入学号:  ";

    } else if (select == 2) {

        file_name = TEACHER_FILE;

        tips = "请输入职工号：  ";
    }

    //打开文件
    ofs.open(file_name, ios::out | ios::app);

    int id;

    string name;

    string pwd;

    cout << tips << endl;

    cin >> id;

    cout << "请输入姓名:  " << endl;

    cin >> name;

    cout << "请输入密码:  " << endl;

    cin >> pwd;

    ofs << id << " " << name << " " << pwd << " " << endl;

    cout << "添加成功" << endl;

    ofs.close();
}

//查看账号
void Manager::searchAccout() {

}

//查看机房信息
void Manager::searchComputerRoom() {

}

//清空预约记录
void Manager::clearOrder() {

}