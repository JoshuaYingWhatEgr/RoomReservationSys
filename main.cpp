#include <iostream>
#include <fstream>

#include "Identity.h"

#include "globalFile.h"

#include "Student.h"

#include "Teacher.h"

#include "Manager.h"

using namespace std;

//进入管理员子菜单界面
void managerMenu(Identity *manager) {

    while (true) {

        //调用管理员的子菜单
        manager->operMenu();

        Manager *man = (Manager *) manager;

        //接收用户的选择
        int select = 0;

        cin >> select;

        if (select == 1) { //添加账号

            man->addAccount();
        } else if (select == 2) { //查看账号

            man->searchAccout();
        } else if (select == 3) { //查看机房信息

            man->searchComputerRoom();
        } else if (select == 4) { //清空预约

            man->clearOrder();
        } else { //注销账号
            cout << "注销成功!" << endl;

            delete manager;
        }
    }
}

void studentMenu(Identity *student) {

    while (true) {

        //调用学生的子菜单
        student->operMenu();

        Student *std = (Student *) student;

        //接收用户的选择
        int select = 0;

        cin >> select;


        if (select == 1) { //申请预约

            std->applyOrder();//申请预约
        } else if (select == 2) {//查看自身预约

            std->searchMyOrder();
        } else if (select == 3) {//查看所有预约

            std->searchAllOrder();
        } else if (select == 4) {//取消预约

            std->cancelOrder();
        } else if (select == 0) {//取消预约

            cout << "注销成功!" << endl;

            delete student;
        }
    }

}

void teacherMenu(Identity *teacher) {


    teacher->operMenu();

    Teacher *tech = (Teacher *) teacher;

    int select = 0;

    cin >> select;

    if (select == 1) {

        tech->searchAllOrder();
    } else if (select == 2) {

        tech->validOrder();
    } else {

        cout << "退出成功" << endl;

        delete teacher;
    }
}


void loginIn(string fileName, int type) {

    Identity *person = NULL;

    //验证文件是否存在
    ifstream ifs;

    ifs.open(fileName, ios::in);

    if (!ifs.is_open()) {

        cout << "文件不存在" << endl;

        return;
    }

    int id; //id号

    string name, password; //姓名 密码


    if (type == 1) { // 学生登录

        cout << "请输入您的学号:";

        cin >> id;

    } else if (type == 2) { //老师登录

        cout << "请输入您的职工编号:";

        cin >> id;

    }

    cout << "请输入您的用户名:";

    cin >> name;

    cout << "请输入您的密码:";

    cin >> password;


    //输入完成之后进行验证
    if (type == 1) { //验证学生的信息

        int stdId;

        string stdName;

        string stdPassword;


        while (ifs >> stdId && ifs >> stdName && ifs >> stdPassword) {

            if (stdId == id && stdName == name && stdPassword == password) {


                cout << "登录成功" << endl;

                person = new Student(id, name, password);

                studentMenu(person);
                return;
            }

        }


    } else if (type == 2) { // 验证老师的信息

        int techId;

        string techName;

        string techPassword;

        while (ifs >> techId && ifs >> techName && ifs >> techPassword) {

            if (techId == id && techName == name && techPassword == password) {


                cout << "登录成功" << endl;

                person = new Teacher(id, name, password);

                teacherMenu(person);
                return;
            }

        }

    } else if (type == 3) { // 验证管理员的信息

        string manName;

        string manPassword;

        while (ifs >> manName && ifs >> manPassword) {

            if (manName == name && manPassword == password) {


                cout << "登录成功" << endl;

                person = new Manager(name, password);

                managerMenu(person);

                return;
            }

        }

    }

    cout << "您的信息输入有误,登录失败!" << endl;

    return;
}

int main() {

    int select = 0;

    while (true) {


        cout << "============================ 欢迎来到机房预约系统 ============================" << endl;

        cout << "请输入你的身份:" << endl;

        cout << "\t\t --------------------------------------\n";
        cout << "\t\t|                                     |\n";
        cout << "\t\t|             1.学 生代表              |\n";
        cout << "\t\t|                                     |\n";
        cout << "\t\t|             2.老     师              |\n";
        cout << "\t\t|                                     |\n";
        cout << "\t\t|             3.管  理 员              |\n";
        cout << "\t\t|                                     |\n";
        cout << "\t\t|             0.退     出              |\n";
        cout << "\t\t --------------------------------------\n";
        cout << "输入您的选择: ";

        cin >> select; //接收用户选择的角色

        switch (select) {

            case 1:

                loginIn(STUDENT_FILE, 1);

                break;
            case 2:

                loginIn(TEACHER_FILE, 2);

                break;
            case 3:

                loginIn(ADMIN_FILE, 3);

                break;
            case 0: //退出系统
                cout << "欢迎您下次使用!" << endl;

                return 0;
                break;
            default:

                cout << "您的输入有误,请重新输入!" << endl;
                break;
        }

    }

    return 0;
}
