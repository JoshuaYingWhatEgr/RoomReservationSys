//
// Created by JoshuaYingWhat on 2021/1/13.
//

#include <vector>
#include "Identity.h"
#include "Student.h"
#include "Teacher.h"

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

    //初始化容器
    void initVector();

    //学生容器
    vector<Student> vStu;

    //教师容器
    vector<Teacher> vTea;

    //检测是否有重复
    bool checkRepeat(int id, int type); // true表示有重复 false反之
};


#endif //ROOMRESERVATIONSYS_MANAGER_H
