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

#include "flooditboard.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <omp.h>

const string FlooditBoard::PATH_DEFAULT_INSTANCE = "../instances/exemplo_site_fabiano.txt";

FlooditBoard::FlooditBoard()
{
}


FlooditBoard::~FlooditBoard()
{
	for (int row = 0; row < this->rows_; ++row)
		delete(this->board_[row]);
}


void FlooditBoard::loadDefaultInstance()
{
	this->loadInstance(PATH_DEFAULT_INSTANCE);
}


void FlooditBoard::loadInstance(const string instancePath)
{
	string line;
	ifstream instanceFile;

	this->instance_ = instancePath;
	instanceFile.open(instancePath.c_str());
	
	if (instanceFile.is_open())
	{
		instanceFile >> this->rows_;
		instanceFile >> this->cols_;
		instanceFile >> this->colors_;
		++this->colors_; // There is no color 0
		
		this->board_ = new unsigned int*[this->rows_];
		
		for (int row = 0; row < this->rows_; ++row)
		{
			this->board_[row] = new unsigned int[this->cols_];
			
			for (int col = 0; col < this->cols_; ++col)
			{
				instanceFile >> this->board_[row][col];
			}
		}
	}
	else
	{
		cerr << "*** Failure to open " << this->instance_ 
		     << " ***" << endl;
		exit(EXIT_FAILURE);
	}
	
	instanceFile.close();
}


void FlooditBoard::printInstance()
{
	cout << "----------------------------------" << endl;
	cout << "Instance: " << this->instance_ << endl;
	cout << this->rows_ << " " << this->cols_ 
		 << " " << this->colors_ << endl;
	cout << "----------------------------------" << endl;
	
	for (int row = 0; row < this->rows_; ++row)
	{
		for (int col = 0; col < this->cols_; ++col)
		{
			cout << this->board_[row][col] << " ";
		}
		
		cout << endl;
	}
}


void FlooditBoard::solveInstance(FlooditStrategy* strategy)
{
	color_t paintingColor;
	double init_time;
	
	if (strategy == NULL)
	{
		cerr << "*** Failure: There is no strategy to solve instance" 
		     << " ***" << endl;
		exit(EXIT_FAILURE);
	}
	
	init_time = omp_get_wtime();
	
	while (!this->isInstanceSolved())
	{
		paintingColor = strategy->getPaintingColor(this->board_, this->rows_, this->cols_, this->colors_);
		this->roadmap.push_back(paintingColor);
		this->applyColor(paintingColor);
	}
	
	this->solutionTime_ = (omp_get_wtime() - init_time);
}


bool FlooditBoard::isInstanceSolved()
{
	color_t leftUpperColor = this->board_[0][0];
	
	for (int row = 0; row < this->rows_; ++row)
	{
		for (int col = 0; col < this->cols_; ++col)
		{
			if (this->board_[row][col] != leftUpperColor)
				return false;
		}
	}
	
	return true;
}



void FlooditBoard::applyColor(color_t color)
{
	unsigned int row, col;
	color_t leftUpperColor = this->board_[0][0];
	
	for (row = 0; row < this->rows_; ++row)
	{
		for (col = 0; col < this->cols_; ++col)
		{
			if (this->board_[row][col] != leftUpperColor &&
				this->board_[row][col] != color) break;
			
			this->board_[row][col] = color;
		}
		
		if (col == 0) break;
	}
}


void FlooditBoard::applyColorRoadmap(color_roadmap_t roadmap)
{
	color_roadmap_t::iterator iter;
	color_t color;
	
	for (iter = roadmap.begin(); iter != roadmap.end(); ++iter)
	{
		color = *iter;
		this->applyColor(color);
	}
}


void FlooditBoard::printSolution()
{
	color_roadmap_t::iterator iter;
	
	cout << this->roadmap.size() << endl;
	
	for (iter = roadmap.begin(); iter != roadmap.end(); ++iter)
	{
		cout << *iter << " ";
	}
	
	cout << endl;
}


double FlooditBoard::getSolutionTime()
{
	return this->solutionTime_;
}
