#include <iostream>

using namespace std;

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

                break;
            case 2:

                break;
            case 3:

                break;
            case 0:
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
