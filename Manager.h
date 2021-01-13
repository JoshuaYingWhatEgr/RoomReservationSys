//
// Created by JoshuaYingWhat on 2021/1/13.
//

#include "Identity.h"

#ifndef ROOMRESERVATIONSYS_MANAGER_H
#define ROOMRESERVATIONSYS_MANAGER_H


class Manager : public Identity {

public:

    Manager();

    Manager(string name, string password);

    virtual void operMenu();

    //添加账号
    void addAccount();

    //查看账号
    void searchAccout();

    //查看机房信息
    void searchComputerRoom();

    //清空预约记录
    void clearOrder();
};


#endif //ROOMRESERVATIONSYS_MANAGER_H
