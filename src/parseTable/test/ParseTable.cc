#include "ParseTable.h"
#include <utility>

const Production PRODUCTIONS[] = {
	std::make_pair(S, {BOF, expr, EOF}),
	std::make_pair(expr, {term}),
	std::make_pair(expr, {expr, -, term}),
	std::make_pair(term, {id}),
	std::make_pair(term, {(, expr, )}),
};

int stateShift(int currState, int symbol)
{
	switch(currState) {
		case 0:
			switch(symbol) {
				case BOF: return 6;
			}
			break;
		case 1:
			switch(symbol) {
				case (: return 3;
				case id: return 2;
				case term: return 8;
			}
			break;
		case 3:
			switch(symbol) {
				case (: return 3;
				case expr: return 7;
				case id: return 2;
				case term: return 4;
			}
			break;
		case 6:
			switch(symbol) {
				case (: return 3;
				case expr: return 10;
				case id: return 2;
				case term: return 4;
			}
			break;
		case 7:
			switch(symbol) {
				case ): return 9;
				case -: return 1;
			}
			break;
		case 10:
			switch(symbol) {
				case -: return 1;
				case EOF: return 5;
			}
			break;
	}
	return -1;
}

int stateReduce(int currState, int symbol)
{
	switch(currState) {
		case 2:
			switch(symbol) {
				case ): return 3;
				case -: return 3;
				case EOF: return 3;
			}
			break;
		case 4:
			switch(symbol) {
				case ): return 1;
				case -: return 1;
				case EOF: return 1;
			}
			break;
		case 8:
			switch(symbol) {
				case ): return 2;
				case -: return 2;
				case EOF: return 2;
			}
			break;
		case 9:
			switch(symbol) {
				case ): return 4;
				case -: return 4;
				case EOF: return 4;
			}
			break;
	}
	return -1;
}
