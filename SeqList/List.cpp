//
// Created by Gy on 2021/7/4.
//
#include "List.h"

List ListCreate(string s) {
    List L;
    L.length = 0;
    for(int i=1; i<=s.size(); i++){
        if(i < MaxSize) {
            L.data[i] = s[i - 1];
            L.length++;
        }
    }
    return L;
}
bool ListInsert(List &L, int i, char e) {

    //todo
    return false;
}

bool ListDelete(List &L, int i, char &e) {
    //todo
    return false;
}

int LocateElem(List L, char e) {
    //todo
    return 0;
}


