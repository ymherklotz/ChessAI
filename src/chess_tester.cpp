#include "chess_tester.hpp"

using namespace ymhChessAI;

chess_tester::chess_tester() : ts_begin(false) {
	srand(time(NULL));

	test_id = rand() % 0xffffffff;
	test_id_test = test_id;
}

void chess_tester::chess_begin_test_suite() {
	if(ts_begin)
		fprintf(stderr, "Error: already started test suite\n");
	exit(1);

	ts_begin = true;
}

int chess_tester::chess_begin_test(std::string test_name) {
	if(!ts_begin) {
		fprintf(stderr, "Error: the test suite hasn't been started yet\n");
		exit(1);
	}

	if(!is_in_arr(test_name)) {
		fprintf(stderr, "Error: the test name does not exist\n");
		exit(1);
	}

	current_test = test_name;

	test_id = rand() % 0xffffffff;
	test_id_test = test_id;

	return test_id;
}

void chess_tester::chess_end_test(int test_id, bool passed) {
	if(test_id != test_id_test) {
		fprintf(stderr, "Error: the test from before has not been ended\n");
		exit(1);
	}

	tested_pieces tmp;
	tmp.piece_name = current_test;

	if(passed) {
		tmp.num_passed = 1;
		tmp.num_failed = 0;
	} else {
		tmp.num_passed = 0;
		tmp.num_failed = 1;
	}

	if(test_piece.empty() || !is_in_vec(tmp)) {
		test_piece.push_back(tmp);
	} else {
		for(unsigned i = 0; i < test_piece.size(); ++i) {
			if(test_piece[i] == tmp) {
				if(passed)
					test_piece[i].num_passed++;
				else
					test_piece[i].num_failed++;
			}
		}
	}
}

void chess_tester::chess_end_test_suite() {
	std::sort(test_piece.begin(), test_piece.end());

	int pieces_passed = 0;
	int pieces_partial = 0;
	int pieces_fail = 0;

	fprintf(stderr, "+-%10s-+-%5s-+-%6s-+-%8s-+\n", "----------", "-----",
			"------", "--------");
	fprintf(stderr, "| %10s | %5s | %6s | %8s |\n", "Piece  ", "Total", "Passed",
			"Passed %");
	fprintf(stderr, "+-%10s-+-%5s-+-%6s-+-%8s-+\n", "----------", "-----",
			"------", "--------");
	for(unsigned i = 0; i < test_piece.size(); ++i) {
		fprintf(stderr, "| %10s | %5d | %6d | %7.3f%% |\n",
				test_piece[i].piece_name.c_str(), test_piece[i].num_passed +
				test_piece[i].num_failed, test_piece[i].num_passed,
				100.0 * (double)test_piece[i].num_passed /
				(double)(test_piece[i].num_passed + test_piece[i].num_failed));

		if(test_piece[i].num_passed == 0)
			pieces_fail++;
		else if(test_piece[i].num_failed == 0)
			pieces_passed++;
		else
			pieces_partial++;
	}
	fprintf(stderr, "+-%10s-+-%5s-+-%6s-+-%8s-+\n", "----------", "-----",
			"------", "--------");

	fprintf(stderr, "\nTotal pieces tested: %lu\n", test_piece.size());
	fprintf(stderr, "Passed: %d\n", pieces_passed);
	fprintf(stderr, "Partially working: %d\n", pieces_partial);
	fprintf(stderr, "Failed: %d\n", pieces_fail);
}

bool chess_tester::is_in_arr(const std::string& test_piece) const {
	for(unsigned i = 0; i < CHESS_TEST_SIZE; ++i)
		if(chess_test_pieces[i] == test_piece)
			return true;

	return false;
}

bool chess_tester::is_in_vec(const tested_pieces& piece) const {
	for(unsigned i = 0; i < test_piece.size(); ++i)
		if(test_piece[i] == piece)
			return true;
	return false;
}
