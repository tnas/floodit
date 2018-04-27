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

#include "flooditstrategy_greedy.h"
#include <string.h>

color_t FlooditStrategy::getPaintingColor(const board_t board, const unsigned int rows, const unsigned int cols, const unsigned int ncolors)
{
	unsigned int colorsFrequency[ncolors];
	color_t paintingColor, leftUpperColor;
	unsigned int row, col, moreFrequentColor, maxFrequency;
	
	leftUpperColor = board[0][0];
	memset(colorsFrequency, 0, sizeof(colorsFrequency));
	
	for (row = 0; row < rows; ++row)
	{
		for (col = 0; col < cols && leftUpperColor == board[row][col]; ++col);
		
		if (col < cols) ++colorsFrequency[board[row][col]];
	}
	
	maxFrequency = 0;
	
	for (int color = 0; color < ncolors; ++color)
	{
		if (colorsFrequency[color] > maxFrequency) 
		{
			maxFrequency = colorsFrequency[color];
			moreFrequentColor = color;
		}
	}
	
	return moreFrequentColor;
}