//
// Created by aboba on 9/27/2023.
//

#ifndef LABB1_BOOKSINFO_H
#define LABB1_BOOKSINFO_H

#include <iostream>
#include <string>
#include "helper.h"

using namespace std;

class characters;


class book {
private:
    string nameOfBook{}, releaseDate{}, annotation{};
    vector<string> authorsName{};
    int numOfPages{};
public:

    book() = default;

    book(const string &nameOfBook1, const string &releaseDate1, const string &annotation1,
         const vector<string> &authorsName1, const int numOfPages1) {
        nameOfBook = nameOfBook1;
        releaseDate = releaseDate1;
        annotation = annotation1;
        authorsName = authorsName1;
        numOfPages = numOfPages1;
    }

    void sortAuthorsName() {
        sort(authorsName.begin(), authorsName.end());
    }

    string getNameOfBook() { return nameOfBook; }

    string getReleaseDate() { return releaseDate; }

    string getAnnotation() { return annotation; }

    vector<string> getAuthorsName() { return authorsName; }

    int getNumOfPages() { return numOfPages; }

    friend class characters;

    friend ostream &operator<<(ostream &out, vector<string> &nameOfBook1);

    friend ostream &operator<<(ostream &out, book &book1);

    bool operator<(book &book1);

    bool operator<=(book &book1);

    bool operator>(book &book1);
};


class characters {
private:
    vector<string> nameOfTheCharacters;
    vector<string> inWhichBooksMentioned;
    string participation; // main, secondary, etc
public:

    vector<string> getNameOfTheCharacters() { return nameOfTheCharacters; }

    vector<string> getInWhichBooksMentioned() { return inWhichBooksMentioned; }

    string getParticipation() { return participation; }

};

class series {
private:
    string seriesOfBooks;
public:

    void checkIfOneSeries(book &book1, book &book2) {

    }
};

#endif //LABB1_BOOKSINFO_H
