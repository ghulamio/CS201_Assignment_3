#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//--------------------------------------------------------------------
#include "MovieRentalSystem.h"
//--------------------------------------------------------------------
// rented movie remove warning test

TEST(readingInput, readingInput1) {
    string inputFile = BASE;
    inputFile += "/output11.txt";
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
	MRS.rentMovie( 1000, 4321 );
	cout << endl;
	MRS.removeMovie( 4321 );
	
//--------------------------------------------------------------------

    string testOutput = ss.str();
    EXPECT_EQ( testOutput, expectedOutput );
    cout.rdbuf( buffer );
}

int main( int argc, char** argv ) {
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}
