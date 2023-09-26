//
// Created by aboba on 9/26/2023.
//

#ifndef LABB1_HELPER_H
#define LABB1_HELPER_H
#include <iostream>
#include <vector>

using namespace std;

template<typename T>
ostream &operator<<(ostream &out, vector<T> vectorOut) {
    for (int i = 0; i < vectorOut.size(); i++) {
        out << vectorOut[i] << "; ";
    }
    return out;
}



#endif //LABB1_HELPER_H
