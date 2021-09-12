/*
 * main.cpp
 *
 *  Created on: May 17, 2021
 *      Author: Merve Caliskan
 */

#include <iostream>
#include <fstream>
#include "movieLList.h"

using namespace std;

int main(void) {
    MovieLList movies;
    string filename = "movieList.txt";
    string file1 = "sortedByName.txt";
    string file2 = "sortedByRate.txt";
    string file3 = "sortedByYear.txt";

    //load file test
    movies.loadFile(filename);
    cout << endl;

    //add test
    movies.add("LOTR",8.8,2001);
    movies.add("Matrix",8.7,1999);
    movies.add("Interstellar",8.6,2014);
    movies.add("Back to the Future",8.5,1985);

    //print test
    cout << "Sorted by movie names: " << endl; cout << endl;
    movies.printByName();
    cout << endl;
    cout << "Sorted by movie rates: " << endl; cout << endl;
    movies.printByRate();
    cout << endl;
    cout << "Sorted by movie years: " << endl; cout << endl;
    movies.printByYear();
    cout << endl;

    //remove test
    movies.remove("C");
    cout << "After removing movie Interstellar" << endl;
    cout << endl;
    cout << "Sorted by movie names: " << endl; cout << endl;
    movies.printByName();
    cout << endl;
    cout << "Sorted by movie rates: " << endl; cout << endl;
    movies.printByRate();
    cout << endl;
    cout << "Sorted by movie years: " << endl; cout << endl;
    movies.printByYear();
    cout << endl;

    //update test
    movies.update("A",9.9);
    cout << "After updating movie Matrix" << endl;
    cout << endl;
    cout << "Sorted by movie names: " << endl; cout << endl;
    movies.printByName();
    cout << endl;
    cout << "Sorted by movie rates: " << endl; cout << endl;
    movies.printByRate();
    cout << endl;
    cout << "Sorted by movie years: " << endl; cout << endl;
    movies.printByYear();
    cout << endl;

    //save to file test
    cout << "Movie list sorted by name was saved into " << file1 << "!" << endl;
    movies.saveToFileByName(file1);
    cout << "Movie list sorted by name was saved into " << file2 << "!" << endl;
    movies.saveToFileByRate(file2);
    cout << "Movie list sorted by name was saved into " << file3 << "!" << endl;
    movies.saveToFileByYear(file3);
    cout << endl;

    //random pick test
    movies.randomPick();
}
