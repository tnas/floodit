/*
 * Copyright 2018 <Thiago Nascimento> <nascimenthiago@gmail.com>
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * 
 */

#ifndef FLOODITBOARD_H
#define FLOODITBOARD_H

#include "floodit.h"
#include "flooditstrategy.h"
#include <string>


class FlooditBoard
{
	static const string PATH_DEFAULT_INSTANCE;
	
	string instance_;
	unsigned int rows_;
	unsigned int cols_;
	unsigned int colors_;
	board_t board_;
	color_roadmap_t roadmap;
	double solutionTime_;
	
public :
		
	FlooditBoard();
	~FlooditBoard();
	void loadDefaultInstance();
	void loadInstance(const string instancePath);
	void printInstance();
	void solveInstance(FlooditStrategy* strategy);
	bool isInstanceSolved();
	void applyColor(color_t color);
	void applyColorRoadmap(color_roadmap_t roadmap);
	void printSolution();
	double getSolutionTime();
};

#endif // FLOODITBOARD_H
