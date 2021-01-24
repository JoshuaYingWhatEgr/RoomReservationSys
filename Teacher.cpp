//
// Created by JoshuaYingWhat on 2021/1/13.
//

#include "Teacher.h"

#include "orderFile.h"

using namespace std;

Teacher::Teacher() {

}

Teacher::Teacher(int id, string name, string password) {

    this->m_id = id;

    this->m_Name = name;

    this->m_Psd = password;
}

void Teacher::operMenu() {

    cout << "------------------ 欢迎教师:" << m_Name << "登录 ------------------" << endl;

    cout << "1.查看所有预约" << endl;
    cout << "2.审核预约" << endl;

    cout << "0.退出" << endl;

}

//查看所有预约
void Teacher::searchAllOrder() {

    //获取所有预约数据
    orderFile of;

    if (of.order_size == 0) {

        cout << "当前没有预约数据" << endl;
        return;
    }

    for (int i = 0; i < of.order_size; i++) {

        cout << "预约日期: 周" << of.m_orderData[i]["data"] << endl;

        cout << "时间段: " << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午") << endl;

        cout << "学生ID号: " << of.m_orderData[i]["stuId"] << endl;

        cout << "学生姓名: " << of.m_orderData[i]["stuName"] << endl;

        cout << "机房: " << of.m_orderData[i]["roomId"] << endl;

        string status = "状态: "; //0 取消预约 1 审核中 2 已预约 -1 预约失败

        if (of.m_orderData[i]["status"] == "1") {

            status += "审核中";
        } else if (of.m_orderData[i]["status"] == "2") {

            status += "已预约";
        } else if (of.m_orderData[i]["status"] == "0") {

            status += "取消预约";
        } else {

            status += "预约失败";
        }

        cout << "预约状态: " << of.m_orderData[i]["status"] << endl;
    }

}

//审核预约
void Teacher::validOrder() {

    orderFile of;

    if (of.order_size == 0) {

        cout << "当前还没有预约的数据" << endl;
        return;
    }

    for (int i = 0; i < of.order_size; i++) {

        if (of.m_orderData[i]["status"] == "1") {//审核中 更改为已预约

            of.m_orderData[i]["status"] = "2";

            of.updateOrder();
        }
    }

    cout << "审核完成" << endl;
}