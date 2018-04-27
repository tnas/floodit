#include <iostream>
#include "core/flooditboard.h"
#include "strategies/flooditstrategy.h"
#include "strategies/flooditstrategy_greedy.h"

using namespace std;

int main(int argc, char **argv) {
	
	FlooditBoard flooditBoard;
	GreedyFlooditStrategy greedyStrategy;
	
	flooditBoard.loadDefaultInstance();
	flooditBoard.printInstance();
 	flooditBoard.solveInstance(greedyStrategy);
	flooditBoard.printSolution();
	
    return 0;
}
