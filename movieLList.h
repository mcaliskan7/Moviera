/*
 * movieLList.h
 *
 *  Created on: May 17, 2021
 *      Author: Merve Caliskan
 */

#ifndef MOVIE_LINKED_LIST
#define MOVIE_LINKED_LIST

#include <iostream>
#include <string>
using namespace std;

class MovieLLNode {
public:
    MovieLLNode() {
        nnext = 0;
        rnext = 0;
        ynext = 0;
    }

    MovieLLNode(string n, double r, int y,
                MovieLLNode *nptr = 0, MovieLLNode *rptr = 0, MovieLLNode *yptr = 0) {
        name = n; rate = r; year = y;
        nnext = nptr; rnext = rptr; ynext = yptr;
    }

    string name;
    double rate;
    int year;
    MovieLLNode *nnext, *rnext, *ynext;
};

class MovieLList {
public:
    MovieLList() {
        nhead = 0;
        rhead = 0;
        yhead = 0;
    }
    ~MovieLList();

    int isEmpty() {
        return nhead == 0;
    }
    void add(string, double, int); //adds new movies while sorting
    bool remove(string); //removes a movie with its name if it exists
    void update(string, double); //updtates rate of a given movie
    void printByName(); //prints the movies according to name
    void printByRate(); //prints the movies according to rate
    void printByYear(); //prints the movies according to year
    void loadFile(string); //loads a file txt entension
    void saveToFileByName(string); //saves the movies to a txt file according to name
    void saveToFileByRate(string); //saves the movies to a txt file according to rate
    void saveToFileByYear(string); //saves the movies to a txt file according to year
    void randomPick(); //picks a random film from the list

private:
    MovieLLNode *nhead, *rhead, *yhead;
};

#endif