#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//--------------------------------------------------------------------
#include "MovieRentalSystem.h"
//--------------------------------------------------------------------
// remove subscriber test

TEST(readingInput, readingInput1) {
    string inputFile = BASE;
    inputFile += "/output10.txt";
    ifstream file( inputFile );
    string expectedOutput = "";
    string line;
    while ( getline( file, line ) ) {
        expectedOutput = expectedOutput + line + "\n";
    }
    stringstream ss;
    auto buffer = cout.rdbuf( ss.rdbuf() );

//--------------------------------------------------------------------
    string base = BASE;
    MovieRentalSystem MRS( base + "/movies_mid.txt", base + "/subscribers_mid.txt" );
    cout << endl;
	MRS.showAllSubscribers();
	cout << endl;
	MRS.removeSubscriber( 2000 );
	cout << endl;
	MRS.showAllSubscribers();
	cout << endl;
	MRS.removeSubscriber( 1000 );
	cout << endl;
	MRS.showAllSubscribers();
	cout << endl;
	MRS.removeSubscriber( 9000 );
	cout << endl;
	MRS.showAllSubscribers();
	cout << endl;
	MRS.removeSubscriber( 2000 );
	cout << endl;
	MRS.showAllSubscribers();
	
	
//--------------------------------------------------------------------

    string testOutput = ss.str();
    EXPECT_EQ( testOutput, expectedOutput );
    cout.rdbuf( buffer );
}

int main( int argc, char** argv ) {
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}