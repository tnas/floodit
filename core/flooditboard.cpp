/*
 * Copyright 2018 <copyright holder> <email>
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
		cerr << "Failure to open " << this->instance_ << endl;
		exit(EXIT_FAILURE);
	}
	
	instanceFile.close();
}


void FlooditBoard::print()
{
	cout << "Instance: " << this->instance_ << endl;
	cout << this->rows_ << " " << this->cols_ 
		 << " " << this->colors_ << endl;
	
	for (int row = 0; row < this->rows_; ++row)
	{
		for (int col = 0; col < this->cols_; ++col)
		{
			cout << this->board_[row][col] << " ";
		}
		
		cout << endl;
	}
}
