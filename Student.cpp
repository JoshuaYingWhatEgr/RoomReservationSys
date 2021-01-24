//
// Created by JoshuaYingWhat on 2021/1/13.
//

#include "Student.h"


#include <fstream>

#include "globalFile.h"

#include "orderFile.h"

Student::Student() {

}

Student::Student(int id, string name, string password) {

    this->m_id = id;

    this->m_Name = name;

    this->m_psd = password;

    //初始化机房信息
    ifstream ifs;

    ifs.open(COMPUTER_ROOM_FILE, ios::in);

    if (!ifs.is_open()) {

        cout << "机房文件不存在" << endl;

        return;
    }

    ComputerRoom com;

    while (ifs >> com.m_cid && ifs >> com.m_Max) {

        //将读取到的机房信息放入容器中
        vCom.push_back(com);
    }

    ifs.close();
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

    cout << "机房开放时间为周一到周五!" << endl;

    cout << "请输入申请预约的时间:" << endl;

    cout << "1.周一" << endl;
    cout << "2.周二" << endl;
    cout << "3.周三" << endl;
    cout << "4.周四" << endl;
    cout << "5.周五" << endl;

    int date = 0;//时间段

    int interval = 0;//间隔日期

    int room = 0;//机房编号

    while (true) {

        cin >> date;

        if (date >= 1 && date <= 5) {


            break;
        }

        cout << "您的输入有误,请重新输入" << endl;
    }

    cout << "请输入申请预约的时间段" << endl;

    cout << "1.上午" << endl;

    cout << "2.下午" << endl;

    while (true) {

        cin >> interval;

        if (interval >= 1 && interval <= 2) {

            break;
        }
        cout << "您的输入有误,请重新输入" << endl;
    }

    cout << "请选择机房" << endl;

    for (int i = 0; i < vCom.size(); i++) {

        cout << vCom[i].m_cid << "号机房的容量为:" << vCom[i].m_Max << endl;
    }

    while (true) {

        cin >> room;

        if (room >= 1 && room <= vCom.size()) {

            break;
        }
        cout << "您的输入有误,请重新输入" << endl;
    }

    cout << "预约成功!审核中" << endl;

    //将预约信息写入文件中
    ofstream ofs;

    ofs.open(ORDER_FILE, ios::app);

    ofs << "data:" << date << " ";

    ofs << "interval:" << interval << " ";

    ofs << "stuId:" << m_id << " ";

    ofs << "stuName:" << m_name << " ";


    ofs << "roomId:" << room << " ";

    ofs << "status:" << 1 << endl;

    ofs.close();
}


//查看自身预约
void Student::searchMyOrder() {

    cout << "请输入学号:" << endl;

    //获取预约数据
    orderFile order;

    int id;

//    while (true) {
//
//        cin >> id;
//
//        for (map<int, map<string, string>>::iterator it = order.m_orderData.begin())
//
//    }

}

//显示所有人的预约
void Student::searchAllOrder() {

}

//取消预约
void Student::cancelOrder() {

}