#include "stdafx.h"
#include <string>
#include <stack>
#include <vector>
#include <iostream>
#include <vector>
#include <assert.h>

typedef std::vector<std::string> lab_t;

bool isAst(int x, int y, lab_t & lab) {
	return lab[x][y] == '*';	// "" - opisuje string; '' - opisuje litera³
};

enum class Dir {
	n, s, w, e
};

struct Coord {
	int x;
	int y;
	Dir step;
};

typedef std::vector<Coord> coord_t;


bool stepOk(int& x_, int& y_, Dir step, lab_t & lab, coord_t trace) {
	int x = x_;
	int y = y_;
	switch (step) {
	case Dir::n:
		x = x - 1;
		break;
	case Dir::s:
		x = x + 1;
		break;
	case Dir::e:
		y = y + 1;
		break;
	case Dir::w:
		y = y - 1;
		break;
	};
	if (x < 0 || y < 0 || x >= lab.size() || y >= lab[0].size()) return false;
	if (isAst(x, y, lab)) {

		for (auto it : trace) {
			if (x == it.x && y == it.y)
				return false;
		}

		x_ = x;
		y_ = y;
		return true;
	};
	return false;
};

bool isEnd(int x, int y, lab_t & lab) {
	return (x == lab.size() - 1 && y == lab[0].size() - 1);
};

Dir moveFirst() {
	return Dir::n;
};

bool moveNext(Dir& step) {
	switch (step) {
	case Dir::n:
		step = Dir::s;
		break;
	case Dir::s:
		step = Dir::w;
		break;
	case Dir::w:
		step = Dir::e;
		break;
	case Dir::e:
		return false;
		break;
	};
	return true;
};


void search(int x, int y, lab_t& lab) {
	coord_t moves{};				// stack = stos; generalnie stos jest jak uproszczony wektor;
	Coord where;
	where.x = x;
	where.y = y;
	where.step = moveFirst();
	moves.push_back(where);

	while (true)
	{
		if (stepOk(where.x, where.y, where.step, lab,moves))
		{
			if (isEnd(where.x, where.y, lab)) {
				std::cout << "Bingo!!!" << std::endl;
				return;
			}
			std::cout << "x: " << where.x << " y: " << where.y << std::endl;
			moves.push_back(where);
			where.step = moveFirst();
		}
		else {
			while (!moveNext(where.step)) {
				if (moves.size() == 0) {
					std::cout << "Dupa!!!" << std::endl;
					return;
				}
				moves.pop_back();
				where = moves[moves.size()-1];
			};
		};
	};
};

int main()
{
	lab_t lab{
		{ "***  " },
		{ "* *  " },
		{ "*****" },
		{ "*  * " },
		{ "   **" }
	};

	//	auto c = lab[0][1];		//zerowy (czyli pierwszy) string, pierwszy (czyli drugi) element

	//	assert(stepOk(0, 0, Dir::e, lab));		// sprawdzamy, czy funkcja dzia³a, tak jak oczekiwaliœmy; nawias za assertem zawiera wyra¿enie true, z ! zawiera false; jeœli jest inaczej (czyli wyra¿enie jest niespe³nione) przy odpaleniu programu daje b³¹d (chocia¿ siê kompiluje) 
	//	assert(!stepOk(0, 0, Dir::w, lab));
	//	assert(!stepOk(4, 4, Dir::s, lab));
	//	assert(!stepOk(2, 1, Dir::s, lab));

	assert(!isEnd(0, 0, lab));
	assert(isEnd(4, 4, lab));

	search(0, 0, lab);

	return 0;
}