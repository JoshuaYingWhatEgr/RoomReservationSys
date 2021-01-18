//
// Created by JoshuaYingWhat on 2021/1/13.
//

#include "Manager.h"

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