//
// Created by JoshuaYingWhat on 2021/1/24.
//

#ifndef ROOMRESERVATIONSYS_ORDERFILE_H
#define ROOMRESERVATIONSYS_ORDERFILE_H

#include <string>

#include <map>

#include <iostream>

using namespace std;

class orderFile {

public:

    orderFile();

    //更新预约记录
    void updateOrder();

    map<int, map<string, string>> m_orderData;

    //记录预约个数
    int order_size;
};


#endif //ROOMRESERVATIONSYS_ORDERFILE_H
