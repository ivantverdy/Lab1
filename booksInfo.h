//
// Created by aboba on 9/27/2023.
//

#ifndef LABB1_BOOKSINFO_H
#define LABB1_BOOKSINFO_H

#include <iostream>
#include <string>
#include "helper.h"
#include "vectorList.h"

using namespace std;


class series;
class character;


class book {
private:
    string nameOfBook{}, releaseDate{}, annotation{};
    vector<string> authorsName{};
    int numOfPages{};
    vector<character> characters;
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

    void setCharacters(vector<character> &characters1) {
        characters = characters1;
    }

    vector<character> getCharacters() {
        return characters;
    }

    void addCharacter(character &newCharacter) {
        characters.push_back(newCharacter);
    }

    string getNameOfBook() { return nameOfBook; }

    string getReleaseDate() { return releaseDate; }

    string getAnnotation() { return annotation; }

    vector<string> getAuthorsName() { return authorsName; }

    int getNumOfPages() { return numOfPages; }

    friend ostream &operator<<(ostream &out, vector<string> &nameOfBook1);

    friend ostream &operator<<(ostream &out, book &book1);

    bool operator<(book &book1);

    bool operator<=(book &book1);

    bool operator>(book &book1);

    bool operator>=(book &book1);

    bool operator==(book &book1);
};


class character {
private:
    string nameOfTheCharacter;
    string participation; // main, secondary, etc
public:
    character(const string &nameOfTheCharacter1, const string &participation1) {
        nameOfTheCharacter = nameOfTheCharacter1;
        participation = participation1;
    }

    string getNameOfTheCharacters() { return nameOfTheCharacter; }

    string getParticipation() { return participation; }

};

//дві книги належать до однієї серії, якщо у них є спільний головний чи другорядний персонаж

class series {
private:
    vector<book> seriesOfBooks{};

    bool checkToAddBook(book &book1) {
        for (auto &seriesIter: seriesOfBooks) {
            for (auto &i: seriesIter.getCharacters()) {
                for (auto &j: book1.getCharacters()) {
                    if (i.getNameOfTheCharacters() == j.getNameOfTheCharacters() and
                        ((i.getParticipation() == "main" or i.getParticipation() == "secondary") and
                         (j.getParticipation() == "main" or j.getParticipation() == "secondary"))) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    bool checkIfBookInSeriesAlready(book &book1) {
        for (auto &seriesOfBook: seriesOfBooks) {
            {
                if (seriesOfBook == book1)
                    return true;
            }
        }
        return checkToAddBook(book1);
    }

public:

    void show() {
        cout << "SERIESOFBOOK SIZE " << seriesOfBooks.size() << endl;
        for (auto &seriesOfBook: seriesOfBooks) {
            cout << seriesOfBook;
        }
    }

    void addBookToSeries(book &book1) {
        if (seriesOfBooks.size()<1) { seriesOfBooks.push_back(book1); }

        else if (checkIfBookInSeriesAlready(book1)) {
            cout << book1.getNameOfBook() << ": this book is already in series! " << endl;
        } else {
            seriesOfBooks.push_back(book1);
        }
    }

    void sortByReleaseDate() {
        sort(this->seriesOfBooks.begin(), this->seriesOfBooks.end(), comparatorToSortByReleaseDate);
    }

    static bool comparatorToSortByReleaseDate(book &book1, book &book2) {
        return book1.getReleaseDate() < book2.getReleaseDate();
    }

    template<typename T>
    friend ostream &operator<<(ostream &out, vector<T> &vectorOut);

    friend ostream &operator<<(ostream &out, book &book1);
};

class library : public book, public series{
private:
    vectorList<book> library;
    vectorList<book> series;
public:

};


#endif //LABB1_BOOKSINFO_H
