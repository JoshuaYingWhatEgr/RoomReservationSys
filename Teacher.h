//
// Created by JoshuaYingWhat on 2021/1/13.
//

#include "Identity.h"

#ifndef ROOMRESERVATIONSYS_TEACHER_H
#define ROOMRESERVATIONSYS_TEACHER_H


class Teacher : public Identity {
public:

    Teacher();

    Teacher(int id, string name, string password);

    virtual void operMenu();

    //查看所有预约
    void searchAllOrder();

    //审核预约
    void validOrder();

    //职工编号
    int m_id;
};


#endif //ROOMRESERVATIONSYS_TEACHER_H
