//
// Created by Rabeeta Nasir on 22/05/2021.
//

#pragma once
using namespace std;

// 	NODE Definitions
template <class TYPE>
struct NODE
{
public:
    TYPE    data;
    NODE   *left;
    NODE   *right;
    int     bal;

    bool operator <(const NODE<TYPE>& n) {
        if(data.key < n.data.key) {
            return true;
        }
        return false;
    }
    bool operator >(const NODE<TYPE>& n) {
        if(data.key > n.data.key) {
            return true;
        }
        return false;
    }
    bool operator ==(const NODE<TYPE>& n) {
        if(data.key == n.data.key) {
            return true;
        }
        return false;
    }
} ; // NODE

