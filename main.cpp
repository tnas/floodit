#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "core/flooditboard.h"
#include "core/flooditstrategy.h"
#include "strategies/flooditstrategy_greedy.h"

using namespace std;

int main(int argc, char **argv) {
	
	int opt, num_threads;
	string instance;
	double elapsed_time;
	
	instance    = "";
	num_threads = 1;
	
	while ((opt = getopt(argc, argv, "t:i:")) != -1)
	{
		switch (opt)
		{
			case 'i' :
				instance = optarg;
				break;		
				
			case 't':
				num_threads = atoi(optarg);
				break;
		}
	}
	
	FlooditBoard flooditBoard;
	FlooditStrategy* strategy = new GreedyFlooditStrategy();
	
	if (instance.empty())
	{
		flooditBoard.loadDefaultInstance();
	}
	else
	{
		flooditBoard.loadInstance(instance.c_str());
	}
	
	flooditBoard.printInstance();
 	flooditBoard.solveInstance(strategy);
	flooditBoard.printSolution();
	
	printf("Solution time: %.6lf secs", flooditBoard.getSolutionTime());
	
	delete(strategy);
	
    return 0;
}
