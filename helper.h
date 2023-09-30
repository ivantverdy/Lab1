//
// Created by aboba on 9/26/2023.
//

#ifndef LABB1_HELPER_H
#define LABB1_HELPER_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "booksInfo.h"
#include <utility>

using namespace std;

template<typename T>
ostream &operator<<(ostream &out, vector<T> &vectorOut) {
    for (int i = 0; i < vectorOut.size(); i++) {
        out << vectorOut[i] << "; ";
    }
    return out;
}

template<typename T>
ostream &operator<<(ostream &out, vectorList<T> &vectorOut) {
    for (int i = 0; i < vectorOut.getVectorList().size(); i++) {
        out << vectorOut.getVectorList()[i] << "; ";
    }
    return out;
}

ostream &operator<<(ostream &out, character &character1){
    cout <<"Name of character: "<< character1.getCharacterName() << "; Level of participation: " <<character1.getParticipation();
    return out;
}

ostream &operator<<(ostream &out, book &book1) {
    out << "Name of book: " << book1.nameOfBook << "\n";
    out << "Release date: " << book1.releaseDate << "\n";
    out << "Annotation: " << book1.annotation << "\n";
    out << "Number of pages: " << book1.numOfPages << "\n";
    out << "Name of authors: " << book1.authorsName << "\n";
    return out;
}

bool book::operator<(book &book1) {
    return this->getNameOfBook() < book1.getNameOfBook() and this->getReleaseDate() < book1.getReleaseDate()
           and this->getVectorOfAuthorsName().getVectorList() < book1.getVectorOfAuthorsName().getVectorList() and this->getNumOfPages() < book1.getNumOfPages();
}

bool book::operator<=(book &book1) {
    return this->getNameOfBook() <= book1.getNameOfBook() and this->getReleaseDate() <= book1.getReleaseDate()
           and this->getVectorOfAuthorsName().getVectorList() <= book1.getVectorOfAuthorsName().getVectorList() and this->getNumOfPages() <= book1.getNumOfPages();
}

bool book::operator>(book &book1) {
    return this->getNameOfBook() > book1.getNameOfBook() and this->getReleaseDate() > book1.getReleaseDate()
           and this->getVectorOfAuthorsName().getVectorList() > book1.getVectorOfAuthorsName().getVectorList() and this->getNumOfPages() > book1.getNumOfPages();
}

bool book::operator>=(book &book1) {
    return this->getNameOfBook() >= book1.getNameOfBook() and this->getReleaseDate() >= book1.getReleaseDate()
           and this->getVectorOfAuthorsName().getVectorList() >= book1.getVectorOfAuthorsName().getVectorList() and this->getNumOfPages() >= book1.getNumOfPages();
}

bool book::operator==(book &book1) {
    return this->getNameOfBook() == book1.getNameOfBook() and this->getReleaseDate() == book1.getReleaseDate()
           and this->getVectorOfAuthorsName().getVectorList() == book1.getVectorOfAuthorsName().getVectorList() and this->getNumOfPages() == book1.getNumOfPages();
}


#endif //LABB1_HELPER_H
