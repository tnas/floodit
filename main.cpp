#include <iostream>
#include "core/flooditboard.h"
#include "strategies/flooditstrategy.h"

using namespace std;

int main(int argc, char **argv) {
	
	FlooditBoard flooditBoard;
	FlooditStrategy greedyStrategy;
	
	flooditBoard.loadDefaultInstance();
	flooditBoard.printInstance();
 	flooditBoard.solveInstance(greedyStrategy);
	flooditBoard.printSolution();
	
    return 0;
}
