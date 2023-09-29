//
// Created by aboba on 9/27/2023.
//

#ifndef LABB1_BOOKSINFO_H
#define LABB1_BOOKSINFO_H

#include <iostream>
#include <string>
#include "helper.h"

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

    bool checkIfBookInSeries(book &book1, book &book2) {
        for (auto &i: book1.getCharacters()) {
            for (auto &j: book2.getCharacters()) {
                if (i.getNameOfTheCharacters() == j.getNameOfTheCharacters() and
                    (i.getParticipation() == "main" or i.getParticipation() == "secondary")
                    and (j.getParticipation() == "main" or j.getParticipation() == "secondary")) {
                    return true;
                }
            }
        }
        return false;
    }

    bool checkIfBookInSeriesAlready(vector<book> &series) {
        for (int i = 0; i < series.size(); i++) {
            for (int j = 0; j < series.size() + 1; j++) {
                if (checkIfBookInSeries(series[i], series[j])) {
                    return true;
                }
            }
        }
        return false;
    }

public:

    void show(){
        cout << "SERIESOFBOOK SIZE " << seriesOfBooks.size() << endl;
        for(auto & seriesOfBook : seriesOfBooks) {
            cout << seriesOfBook;
        }
    }

    void addBookToSeries(book &book1) {
        if (checkIfBookInSeriesAlready(seriesOfBooks)) {
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


#endif //LABB1_BOOKSINFO_H
