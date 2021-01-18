using namespace std;
//
// Created by JoshuaYingWhat on 2021/1/11.

//
#ifndef ROOMRESERVATIONSYS_IDENTITY_H

#define ROOMRESERVATIONSYS_IDENTITY_H

#include <iostream>

class Identity {

public:
    //操作菜单
    virtual void operMenu() = 0;

    string m_Name; //姓名

    string m_Psd;  //密码

};

#endif //ROOMRESERVATIONSYS_IDENTITY_H
