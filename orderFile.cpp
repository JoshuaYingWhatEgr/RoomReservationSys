//
// Created by JoshuaYingWhat on 2021/1/24.
//

#include "orderFile.h"

#include <fstream>

#include "globalFile.h"

orderFile::orderFile() {

    //打开预约文件
    ifstream ifs;

    ifs.open(ORDER_FILE, ios::in);

    string data;//日期

    string interval;//预约时间段

    string stu_id;//学生id号

    string stu_name;//学生姓名

    string room_id;//预约机房号

    string status;//状态信息

    if (!ifs.is_open()) {

        cout << "预约文件不存在" << endl;
        return;
    }

    while (ifs >> data && ifs >> interval && ifs >> stu_id && ifs >> stu_name
           && ifs >> room_id && ifs >> status) {

        string key, value;

        map<string, string> m;

        int pos = data.find(":");

        if (pos != -1) {

            key = data.substr(0, pos);

            value = data.substr(pos + 1, data.size() - pos);

            m.insert(make_pair(key, value));
        }

        pos = interval.find(":");

        if (pos != -1) {

            key = interval.substr(0, pos);

            value = interval.substr(pos + 1, interval.size() - pos);

            m.insert(make_pair(key, value));
        }

        pos = stu_id.find(":");

        if (pos != -1) {

            key = stu_id.substr(0, pos);

            value = stu_id.substr(pos + 1, stu_id.size() - pos);

            m.insert(make_pair(key, value));
        }

        pos = stu_name.find(":");

        if (pos != -1) {

            key = stu_name.substr(0, pos);

            value = stu_name.substr(pos + 1, stu_name.size() - pos);

            m.insert(make_pair(key, value));
        }

        pos = room_id.find(":");

        if (pos != -1) {

            key = room_id.substr(0, pos);

            value = room_id.substr(pos + 1, room_id.size() - pos);

            m.insert(make_pair(key, value));
        }

        pos = status.find(":");

        if (pos != -1) {

            key = status.substr(0, pos);

            value = status.substr(pos + 1, status.size() - pos);

            m.insert(make_pair(key, value));
        }

        m_orderData.insert(make_pair(order_size, m));

        this->order_size++;
    }

}

//更新预约记录
void orderFile::updateOrder() {

    if (order_size == 0) {

        //还没有预约的数据
        return;
    }

    ofstream ofs(ORDER_FILE, ios::out | ios::trunc);

    for (int i = 0; i < this->order_size; i++) {


        ofs << "data:" << this->m_orderData[i]["data"] << " ";
        ofs << "interval:" << this->m_orderData[i]["interval"] << " ";
        ofs << "stuId:" << this->m_orderData[i]["stuId"] << " ";
        ofs << "stuName:" << this->m_orderData[i]["stuName"] << " ";
        ofs << "roomId:" << this->m_orderData[i]["roomId"] << " ";
        ofs << "status:" << this->m_orderData[i]["status"] << endl;
    }
    
    ofs.close();
}