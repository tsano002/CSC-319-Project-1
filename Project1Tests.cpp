
#include <cassert>

#include "Project1.h"

using std::cin;
using std::cout;
using std::endl;



void genericTests()
{
    vector<Location *> locations;

    char letters1[4][4] = { { 'a', 'c', 'g', 't' },
                            { 'a', 'c', 't', 'g' },
                            { 'a', 'c', 'g', 't' },
                            { 'a', 'c', 't', 'g' } };

    int score = findMatch( &locations, &letters1[0][0], 4, "not");

    assert( score == 0);
    assert( locations.size() == 0);
    cout << "test #1 completed" << endl;

/*	locations.clear();
	score = findMatch( &locations, &letters1[0][0], 4, "aa");
	assert( score == 300);
	assert( locations.size() == 3);
	assert( locations[0]->ptr == &letters1[0][0]);
	assert( locations[0]->score == 100);
	assert( !locations[0]->horizontal);
	assert( locations[1]->ptr == &letters1[1][0]);
	assert( locations[1]->score == 100);
	assert( !locations[1]->horizontal);
	assert( locations[2]->ptr == &letters1[2][0]);
	assert( locations[2]->score == 100);
	assert( !locations[2]->horizontal);
	cout << "test #2 completed" << endl;

	locations.clear();
	score = findMatch(&locations, &letters1[0][0], 4, "aaa");
	assert( score == 200);
	assert( locations.size() == 2);
	assert( locations[0]->ptr == &letters1[0][0]);
	assert( locations[0]->score == 100);
	assert( !locations[0]->horizontal);
	assert( locations[1]->ptr == &letters1[1][0]);
	assert( locations[1]->score == 100);
	assert( !locations[1]->horizontal);
	cout << "test #3 completed" << endl;

	locations.clear();
	score = findMatch(&locations, &letters1[0][0], 4, "aaaa");
	assert( score == 100);
	assert( locations.size() == 1);
	assert( locations[0]->ptr == &letters1[0][0]);
	assert( locations[0]->score == 100);
	assert( !locations[0]->horizontal);
	cout << "test #4 completed" << endl; 	*/

    locations.clear();
    score = findMatch(&locations, &letters1[0][0], 4, "acgt");
    assert( score == 200);
    assert( locations.size() == 2);
    assert( locations[0]->ptr == &letters1[0][0]);
    assert( locations[0]->score == 100);
    assert( locations[0]->horizontal);
    assert( locations[1]->ptr == &letters1[2][0]);
    assert( locations[1]->score == 100);
    assert( locations[1]->horizontal);
    cout << "test #5 completed" << endl;

    locations.clear();
    score = findMatch(&locations, &letters1[0][0], 4, "aCgT");
    assert( score == 150);
    assert( locations.size() == 2);
    assert( locations[0]->ptr == &letters1[0][0]);
    assert( locations[0]->score == 75);
    assert( locations[0]->horizontal);
    assert( locations[1]->ptr == &letters1[2][0]);
    assert( locations[1]->score == 75);
    assert( locations[1]->horizontal);
    cout << "test #6 completed" << endl;

    locations.clear();
    score = findMatch(&locations, &letters1[0][0], 4, "cgt");
    assert( score == 200);
    assert( locations.size() == 2);
    assert( locations[0]->ptr == &letters1[0][1]);
    assert( locations[0]->score == 100);
    assert( locations[0]->horizontal);
    assert( locations[1]->ptr == &letters1[2][1]);
    assert( locations[1]->score == 100);
    assert( locations[1]->horizontal);
    cout << "test #7 completed" << endl;

    locations.clear();
    score = findMatch(&locations, &letters1[0][0], 4, "CgZ");
    assert( score == 0);
    assert( locations.size() == 0);
    cout << "test #8 completed" << endl;

    locations.clear();
    score = findMatch(&locations, &letters1[0][0], 4, "tgt");
    assert( score == 200);
    assert( locations.size() == 2);
    assert( locations[0]->ptr == &letters1[0][3]);
    assert( locations[0]->score == 100);
    assert( !locations[0]->horizontal);
    assert( locations[1]->ptr == &letters1[1][2]);
    assert( locations[1]->score == 100);
    assert( !locations[1]->horizontal);
    cout << "test #9 completed" << endl;

    locations.clear();
    score = findMatch(&locations, &letters1[0][0], 4, "tgT");
    //assert( score == 200);
    assert( locations.size() == 2);
    assert( locations[0]->ptr == &letters1[0][3]);
    assert( locations[0]->score > 82);
    assert( !locations[0]->horizontal);
    assert( locations[1]->ptr == &letters1[1][2]);
    assert( locations[1]->score > 82);
    assert( !locations[1]->horizontal);
    cout << "test #10 completed" << endl;

}

void yourTests()		//you write 4 tests of your own
{
    vector<Location *> locations;

    char letters1[4][4] = { { 'a', 'c', 'g', 't' },
                            { 'a', 'c', 't', 'g' },
                            { 'a', 'c', 'g', 't' },
                            { 'a', 'c', 't', 'g' } };

    locations.clear();
    int score = findMatch(&locations, &letters1[0][0], 4, "aaaaa");
    assert( score == -1);
    assert( locations.size() == 0);
    cout << "additional letter test completed" << endl;

    locations.clear();
    score = findMatch(&locations, &letters1[0][0], 4, "AAAA");
    assert( score == 50);
    assert( locations.size() == 1);
    assert( locations[0]->ptr == &letters1[0][0]);
    assert( locations[0]->score == 50);
    assert( !locations[0]->horizontal);
    cout << "Captial test completed" << endl;

    locations.clear();
    score = findMatch( &locations, &letters1[0][0], 4, "1234");
    assert( score == -1);
    assert( locations.size() == 0);
    cout << "Number test completed" << endl;

    locations.clear();
    score = findMatch( &locations, &letters1[0][0], 4, "@aa");
    assert( score == -1);
    assert( locations.size() == 0);
    cout << "Number test completed" << endl;

}

int main()
{
    genericTests();		//do tests

    yourTests();		//your custom tests

    return 1;
}
