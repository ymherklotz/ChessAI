/*
 *
 * author: Yann Herklotz
 * username: ymherklotz
 * email: ymherklotz@gmail.com
 * date created: 15/01/17
 *
 * -----------------------------------------------------------------------------
 *
 * Parser that takes in the board state and outputs it into a format that the
 * Chess Board class can read
 *
 */

#ifndef YMH_BOARD_STATE_PARSER_HPP
#define YMH_BOARD_STATE_PARSER_HPP

#include <string>
#include <vector>
#include <fstream>

namespace ymhChessAI {
class BoardStateParser;

typedef std::vector<std::string> boardStateData;

class BoardStateParser {
public:
	BoardStateParser();
	BoardStateParser(const std::string& boardFileName);
	~BoardStateParser();

	void populateBoardState();

	static unsigned stringToInt(const std::string& str);
	static std::string getStateFromLine(const std::string& str);
protected:
private:
	static const std::size_t BOARD_SIZE = 64;

	boardStateData boardStateVector;
	std::ifstream boardFile;
};
}

#endif
