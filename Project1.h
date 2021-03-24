// Project1.cpp
//

//

#include <string>
#include <iostream>
#include <vector>

using std::string;
using std::vector;

class Location {

public:
    char *ptr;   	//ptr to the beginning of the word
    int  score;  	//score for the word that was found
    bool horizontal;//the word is horizontal(true) or vertical(found)
};


int findMatch(vector<Location *> * locations, char * letters, int size, string word);
//findMatch looks for word in the grid (2-d array)
//locations holds everywhere you find the word
//word is word youre looking for
//right now findMatch is an empty function

