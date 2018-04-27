#include <iostream>
#include "core/flooditboard.h"

using namespace std;

int main(int argc, char **argv) {
	
	FlooditBoard flooditBoard;
	
	flooditBoard.loadDefaultInstance();
	flooditBoard.print();
	
    return 0;
}
