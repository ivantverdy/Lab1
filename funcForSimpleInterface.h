//
// Created by aboba on 10/1/2023.
//

#ifndef LABB1_FUNCFORSIMPLEINTERFACE_H
#define LABB1_FUNCFORSIMPLEINTERFACE_H

database writeBook(database &Library) {
    string nameOfBook, releaseDate, annotation;
    vectorList<string> authorsName;
    int numOfPages, numOfCharacters, numOfAuthors;
    vectorList<character> characters;

    cout << "What`s the name of the book? " << endl;
    getline(cin >> ws, nameOfBook);

    cout << "When the book was released? " << endl;
    getline(cin >> ws, releaseDate);

    cout << "What`s the book's annotation? " << endl;
    getline(cin >> ws, annotation);

    cout << "What`s the pages count of book? " << endl;
    cin >> numOfPages;

    cout << "What`s count of authors in this book and count of characters? " << endl;
    cin >> numOfAuthors >> numOfCharacters;

    cout << "Write authors 1 by 1(Wrote first, use enter, second, use enter and so on)" << endl;
    for (int i = 0; i < numOfAuthors; i++) {
        cout << i + 1 << "st author: ";
        string nameOfAuthorIter;
        getline(cin >> ws, nameOfAuthorIter);
        authorsName.add(nameOfAuthorIter);
    }
    cout
            << "Write characters 1 by 1(Wrote first`s data (1st name, use enter, than participation), use enter, second, use enter and so on)"
            << endl;
    for (int i = 0; i < numOfCharacters; i++) {
        cout << i + 1 << "st character name: ";
        character characterIter;
        string nameOfCharacterIter, participation;
        getline(cin >> ws, nameOfCharacterIter);
        cout << i + 1 << "st character participation: ";
        getline(cin >> ws, participation);
        characterIter.setCharacterName(nameOfCharacterIter);
        characterIter.setParticipation(participation);
        characters.add(characterIter);
    }

    book newBook;
    newBook.setNameOfBook(nameOfBook);
    newBook.setReleaseDate(releaseDate);
    newBook.setAnnotation(annotation);
    newBook.setNumOfPages(numOfPages);
    newBook.setAuthorsName(authorsName);
    newBook.setCharacters(characters);

    Library.addBook(newBook);
    return Library;
}

database readBook(database &library, const string &fileName) {
    ifstream reading(fileName);
    if (reading) {
        int numOfBooksInFile;
        reading >> numOfBooksInFile;
        reading.ignore(); // consume newline

        for (int i = 0; i < numOfBooksInFile; i++) {
            string nameOfBook, releaseDate, annotation;
            int numOfPages, numOfCharacters, numOfAuthors;

            getline(reading >> ws, nameOfBook);
            getline(reading >> ws, releaseDate);
            getline(reading >> ws, annotation);

            reading >> numOfPages >> numOfAuthors;


            vectorList<string> authorsName;
            for (int j = 0; j < numOfAuthors; j++) {
                string nameOfAuthorIter;
                getline(reading >> ws, nameOfAuthorIter);
                authorsName.add(nameOfAuthorIter);
            }

            reading  >> numOfCharacters;

            vectorList<character> characters;
            for (int j = 0; j < numOfCharacters; j++) {
                character characterIter;
                string nameOfCharacterIter, participation;
                getline(reading >> ws, nameOfCharacterIter);
                getline(reading >> ws, participation);
                characterIter.setCharacterName(nameOfCharacterIter);
                characterIter.setParticipation(participation);
                characters.add(characterIter);
            }

            book newBook;
            newBook.setNameOfBook(nameOfBook);
            newBook.setReleaseDate(releaseDate);
            newBook.setAnnotation(annotation);
            newBook.setNumOfPages(numOfPages);
            newBook.setAuthorsName(authorsName);
            newBook.setCharacters(characters);

            library.addBook(newBook);
        }
    }
    return library;
}


#endif //LABB1_FUNCFORSIMPLEINTERFACE_H
