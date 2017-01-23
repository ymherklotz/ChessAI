/*
 *
 * author: Yann Herklotz
 * username: ymherklotz
 * email: ymherklotz@gmail.com
 * date created: 15/01/17
 *
 * -----------------------------------------------------------------------------
 *
 * Implementation of the Board state class
 *
 */

#include "board_state_parser.hpp"
#include "chess_constats.hpp"

using namespace ymhChessAI;


BoardStateParser::BoardStateParser() : boardFile("res/default.board", std::ifstream::in) {
}

BoardStateParser::BoardStateParser(const std::string& boardFileName) : boardFile(boardFileName.c_str()) {
}

BoardStateParser::~BoardStateParser() {
	boardFile.close();
}

void BoardStateParser::populateBoardState() {
	std::string currentLine;

	boardStateVector.reserve(ChessConstants::BOARD_SIZE);

	if(!boardFile.is_open())
		throw "Error: Can't open file";

	while(getline(boardFile, currentLine))
		boardStateVector[stringToInt(currentLine)] = getStateFromLine(currentLine);
}

unsigned BoardStateParser::stringToInt(const std::string& str) {
	unsigned finalInt = 0;
	bool foundWhiteSpace = false;

	for(char character : str)
		if(character == ' ')
			foundWhiteSpace = true;
		else if(!foundWhiteSpace && character >= '0' && character <= '9')
			finalInt = finalInt * 10 + character - '0';

	return finalInt;
}

std::string BoardStateParser::getStateFromLine(const std::string& str) {
	std::string state;

	state = str.substr(2, str.length() - 2);

	return state;
}
