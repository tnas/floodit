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

#ifndef FLOODITSTRATEGY__GREEDY_H
#define FLOODITSTRATEGY_GREEDY_H

#include "../core/flooditstrategy.h"

class GreedyFlooditStrategy : public FlooditStrategy
{
	
public :
	
	color_t  getPaintingColor(const board_t board, const unsigned int rows, const unsigned int cols, const unsigned int ncolors);
};

#endif // FLOODITSTRATEGY_GREEDY_H