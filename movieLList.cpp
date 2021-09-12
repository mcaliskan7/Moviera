/*
 * movieLList.cpp
 *
 *  Created on: May 17, 2021
 *      Author: Merve Caliskan
 */


#include "movieLList.h"
#include <fstream>
#include <sstream>

using namespace std;

MovieLList::~MovieLList() {

}

void MovieLList::add(string name, double rate, int year) {
    MovieLLNode *newNode = new MovieLLNode(name, rate, year, nhead, rhead, yhead);

    //adding a movie according to name
    if (nhead == 0)
        nhead = newNode;
    else {
        MovieLLNode *ntmp = nhead;
        MovieLLNode *nprev = 0;

        while (ntmp != 0 && ntmp->name < newNode->name) {
            if (ntmp->name < newNode->name) {
                nprev = ntmp;
                ntmp = ntmp->nnext;
            }
            else
                break;
        }

        if (nprev == 0) {
            newNode->nnext = ntmp;
            nhead = newNode;
        }
        else {
            newNode->nnext = nprev->nnext;
            nprev->nnext = newNode;
        }
    }

    //adding a movie according to rate
    if (rhead == 0)
        rhead = newNode;
    else {
        MovieLLNode *rtmp = rhead;
        MovieLLNode *rprev = 0;

        while (rtmp != 0 && rtmp->rate < newNode->rate) {
            if (rtmp->rate < newNode->rate) {
                rprev = rtmp;
                rtmp = rtmp->rnext;
            }
            else
                break;
        }

        if (rprev == 0) {
            newNode->rnext = rtmp;
            rhead = newNode;
        }
        else {
            newNode->rnext = rprev->rnext;
            rprev->rnext = newNode;
        }
    }

    //adding a movie according to year
    if (yhead == 0)
        yhead = newNode;
    else {
        MovieLLNode *ytmp = yhead;
        MovieLLNode *yprev = 0;

        while (ytmp != 0 && ytmp->year < newNode->year) {
            if (ytmp->year < newNode->year) {
                yprev = ytmp;
                ytmp = ytmp->ynext;
            }
            else
                break;
        }

        if (yprev == 0) {
            newNode->ynext = ytmp;
            yhead = newNode;
        }
        else {
            newNode->ynext = yprev->ynext;
            yprev->ynext = newNode;
        }
    }
}

bool MovieLList::remove(string name) {

    MovieLLNode *ntmp = nhead, *rtmp = rhead, *ytmp = yhead;
    MovieLLNode *nprev = 0, *rprev = 0, *yprev = 0;

    //removing movie from name list
    while (ntmp != 0) {
        if (ntmp->name == name)
            break;
        else {
            nprev = ntmp;
            ntmp = ntmp->nnext;
        }

        if (ntmp == 0)
            return false;
    }

    if (nprev == 0)
        nhead = nhead->nnext;
    else
        nprev->nnext = ntmp->nnext;
    
    //removing movie from rate list
    while (rtmp != 0) {
        if (rtmp->name == name)
            break;
        else {
            rprev = rtmp;
            rtmp = rtmp->rnext;
        }
    }

    if (rprev == 0)
        rhead = rhead->rnext;
    else
        rprev->rnext = rtmp->rnext;
    
    //removing movie from year list
    while (ytmp != 0) {
        if (ytmp->name == name)
            break;
        else {
            yprev = ytmp;
            ytmp = ytmp->ynext;
        }
    }

    if (yprev == 0)
        yhead = yhead->ynext;
    else
        yprev->ynext = ytmp->ynext;

    return true;
}

void MovieLList::update(string name, double rate) {

    MovieLLNode *ntmp = nhead, *rtmp = rhead, *ytmp = yhead;

    //updating movie rate in name list
    while (ntmp != 0) {
        if (ntmp->name == name) {
            ntmp->rate = rate;
            break;
        }
        else {
            ntmp = ntmp->nnext;
        }
    }

    //updating movie rate in rate list
    while (rtmp != 0) {
        if (rtmp->name == name) {
            rtmp->rate = rate;
            break;
        }
        else {
            rtmp = rtmp->rnext;
        }
    }

    //updating movie rate in year list
    while (ytmp != 0) {
        if (ytmp->name == name) {
            ytmp->rate = rate;
            break;
        }
        else {
            ytmp = ytmp->ynext;
        }
    }
}

void MovieLList::printByName() {
    for (MovieLLNode *ntmp = nhead; ntmp != 0; ntmp = ntmp->nnext)
        cout << "\"" << ntmp->name << "\"" << " " <<
            ntmp->rate << " " << ntmp->year << endl;
}

void MovieLList::printByRate() {
    for (MovieLLNode *rtmp = rhead; rtmp != 0; rtmp = rtmp->rnext)
        cout << "\"" << rtmp->name << "\"" << " " <<
            rtmp->rate << " " << rtmp->year << endl;
}

void MovieLList::printByYear() {
    for (MovieLLNode *ytmp = yhead; ytmp != 0; ytmp = ytmp->ynext)
        cout << "\"" << ytmp->name << "\"" << " " <<
            ytmp->rate << " " << ytmp->year << endl;
}

void MovieLList::loadFile(string filename) {
    fstream file;
    file.open(filename, ios::in);

    if (!file.is_open()) {
        cout << "Error! File couldn't be opened." << endl;
        exit(1);
    }
    else {
        cout << "File is being processed... : " << filename << endl;

        string info;
        while(getline(file,info)) {
          string name, rate, year;
          stringstream line_stream(info);

          getline(line_stream,name,'\"');
          getline(line_stream,name,'\"');
          getline(line_stream,rate,' ');
          getline(line_stream,rate,' ');
          getline(line_stream,year,' ');

          add(name,stod(rate),stoi(year));
        }

        file.close();
    }
}

void MovieLList::saveToFileByName(string filename) {
    fstream file;
    file.open(filename, ios::out);

    if (!file)
        cout << "Error! File couldn't be created!" << endl;
    else {
        for (MovieLLNode *ntmp = nhead; ntmp != 0; ntmp = ntmp->nnext)
            file << "\"" << ntmp->name << "\"" << " " <<
                ntmp->rate << " " << ntmp->year << endl;
    }

    file.close();
}

void MovieLList::saveToFileByRate(string filename) {
    fstream file;
    file.open(filename, ios::out);

    if (!file)
        cout << "Error! File couldn't be ceated!" << endl;
    else {
        for (MovieLLNode *rtmp = rhead; rtmp != 0; rtmp = rtmp->rnext)
            file << "\"" << rtmp->name << "\"" << " " <<
                rtmp->rate << " " << rtmp->year << endl;
    }

    file.close();
}

void MovieLList::saveToFileByYear(string filename) {
    fstream file;
    file.open(filename, ios::out);

    if (!file.is_open())
        cout << "Error! File couldn't be created!" << endl;
    else {
        for (MovieLLNode *ytmp = yhead; ytmp != 0; ytmp = ytmp->ynext)
            file << "\"" << ytmp->name << "\"" << " " <<
                ytmp->rate << " " << ytmp->year << endl;
    }

    file.close();
}

void MovieLList::randomPick() {
  if (nhead == NULL)
    return;
  
  srand(time(NULL));

  string randfilm = nhead->name;

  MovieLLNode *temp = nhead;
  for (int n = 2; temp != NULL; n++) {
    if(rand() % n == 0)
      randfilm = temp->name;
    
    temp = temp->nnext;
  }

  cout << "Randomly selected film: " << randfilm << endl;
  cout << "Have a good time!" << endl;
}