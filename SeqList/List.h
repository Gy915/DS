//
// Created by Gy on 2021/7/4.
//

#ifndef DS_LIST_H
#define DS_LIST_H

#define MaxSize 100
#include<iostream>
#include<string>
using namespace std;
struct List{
    char data[MaxSize];
    int length;
};
/// 创建一个顺序表，其中顺序表的元素来自字符串S
/// \param s ：顺序表元素来源
/// \return 返回创建的顺序表
List ListCreate(string s);

/// 在顺序表L的位置i添加元素e，返回是否添加成功
/// \param L ：顺序表
/// \param i ：位置i
/// \param e ：添加的元素e
/// \return 返回是否插入成功
bool ListInsert(List &L, int i, char e);

/// 删除顺序表L上的位置i的元素，并将它赋予e
/// \param L ：顺序表L
/// \param i ：位置i
/// \param e ：删除结果
/// \return 返回是否删除成功

bool ListDelete(List &L, int i, char &e);

/// 查找顺序表L中第一个元素值等于e的元素，返回其位序
/// \param L ：顺序表L
/// \param e ：元素值为e的元素
/// \return 元素值第一个为e的元素的位序
int LocateElem(List L, char e);

#endif //DS_LIST_H
