//
// Created by JoshuaYingWhat on 2021/1/13.
//

#include <fstream>
#include "Manager.h"

#include "globalFile.h"
#include "ComputerRoom.h"

Manager::Manager() {

}

Manager::Manager(string name, string password) {

    //初始化管理员的用户名和密码
    this->m_Name = name;

    this->m_Psd = password;

    //初始化容器
    this->initVector();

    ifstream ifs;

    ifs.open(COMPUTER_ROOM_FILE, ios::in);

    if (!ifs.is_open()) {

        cout << "机房文件不存在" << endl;
        return;
    }

    ComputerRoom c;

    while (ifs >> c.m_cid && ifs >> c.m_Max) {

        vCRoom.push_back(c);
    }

    ifs.close();

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

    //错误提示
    string err_tips;

    ofstream ofs;

    int select = 0;

    cin >> select;

    if (select == 1) {

        file_name = STUDENT_FILE;

        tips = "请输入学号:  ";

        err_tips = "学号重复,请重新输入";
    } else if (select == 2) {

        file_name = TEACHER_FILE;

        tips = "请输入职工号：  ";

        err_tips = "职工号重复,请重新输入";
    }

    //打开文件
    ofs.open(file_name, ios::out | ios::app);

    int id;

    string name;

    string pwd;

    cout << tips << endl;

    //检查添加账号是否重复
    while (true) {

        cin >> id;

        bool ret = this->checkRepeat(id, select);

        if (ret) {
            cout << err_tips << endl;
        } else {
            break;
        }
    }


    cout << "请输入姓名:  " << endl;

    cin >> name;

    cout << "请输入密码:  " << endl;

    cin >> pwd;

    ofs << id << " " << name << " " << pwd << " " << endl;

    cout << "添加成功" << endl;

    ofs.close();

    //将新的账号添加到容器中 解决检测重复账号问题
    initVector();
}

//查看账号
void Manager::searchAccout() {

    cout << "请选择您需要查看的内容" << endl;

    cout << "1.学生信息" << endl;

    cout << "2.老师信息" << endl;

    int select = 0;

    cin >> select;

    ifstream ifs;

    if (select == 1) { //查看学生信息

        ifs.open(STUDENT_FILE, ios::in);

        if (!ifs.is_open()) {

            cout << "学生文件不存在" << endl;
            return;
        }

        for (vector<Student>::iterator it = vStu.begin();
             it != vStu.end(); it++) {

            cout << "学号:" << it->m_id << "姓名:" << it->m_Name << "密码:" << it->m_Psd << endl;

        }
    } else {

        ifs.open(TEACHER_FILE, ios::in);

        if (!ifs.is_open()) {

            cout << "教师文件不存在" << endl;
            return;
        }

        for (vector<Teacher>::iterator it = vTea.begin();
             it != vTea.end(); it++) {

            cout << "职工号:" << it->m_id << "姓名:" << it->m_Name << "密码:" << it->m_Psd << endl;

        }
    }
}

//查看机房信息
void Manager::searchComputerRoom() {

    cout << "机房信息如下" << endl;

    for (vector<ComputerRoom>::iterator it = vCRoom.begin();
         it != vCRoom.end(); it++) {

        cout << "机房编号:" << it->m_cid << "机器数量:" << it->m_Max << endl;
    }
}

//清空预约记录
void Manager::clearOrder() {

}

//初始化容器
void Manager::initVector() {

    //读取学生信息
    ifstream ifs;

    ifs.open(STUDENT_FILE, ios::in);

    if (!ifs.is_open()) {

        cout << "学生文件不存在" << endl;
        return;
    }

    //清空容器
    vStu.clear();

    vTea.clear();

    Student s;

    while (ifs >> s.m_id && ifs >> s.m_Name && ifs >> s.m_Psd) {

        vStu.push_back(s);

    }

    cout << "学生数量为:" << vStu.size() << endl;

    ifs.close();

    //读取老师的文件xinxi

    ifs.open(TEACHER_FILE, ios::in);

    if (!ifs.is_open()) {

        cout << "老师文件信息不存在" << endl;
        return;
    }

    Teacher t;

    while (ifs >> t.m_id && ifs >> t.m_Name && ifs >> t.m_Psd) {

        vTea.push_back(t);
    }

    cout << "老师数量:" << vTea.size() << endl;

    ifs.close();
}

//检查是否有重复
bool Manager::checkRepeat(int id, int type) {

    if (type == 1) { //检查学生 文件是否有重复

        for (vector<Student>::iterator it = vStu.begin();
             it != vStu.end(); it++) {


            if (id == it->m_id) {
                return true;
            }
        }

    } else if (type == 2) {

        for (vector<Teacher>::iterator it = vTea.begin();
             it != vTea.end(); it++) {


            if (id == it->m_id) {
                return true;
            }
        }
    }

    return false;
}