// bowling_game.cc

#include "bowling_game.h"

// responsibility: keep track of rolls
void Game::Roll(int pins) {
	rolls_[currentRoll_] = pins;
	currentRoll_++;
}

// responsibility: calculate score
int Game::Score() {
	int score = 0;
	int rollIndex = 0;
	for (int frame = 0; frame < 10; frame++) {
		if (IsStrike(rollIndex)) {
			score += 10 + StrikeBonus(rollIndex);
			rollIndex += 1;
		} else if (IsSpare(rollIndex)) {
			score += 10 + SpareBonus(rollIndex);
			rollIndex += 2;
		} else { // open frame
			score += SumOfBallsInFrame(rollIndex);
			rollIndex += 2;
		}
	}

	return score;
}

// game rules helpers

// check for strike
bool Game::IsStrike(int rollIndex) {
	return rolls_[rollIndex] == 10;
}

// calculate strike bonus
int Game::StrikeBonus(int rollIndex) {
	return rolls_[rollIndex+1] + rolls_[rollIndex+2];
}

// check for spare
bool Game::IsSpare(int rollIndex) {
	return rolls_[rollIndex] + rolls_[rollIndex+1] == 10;
}

// calculate spare bonus
int Game::SpareBonus(int rollIndex) {
	return rolls_[rollIndex+2];
}

// calculate sum of balls in frame
int Game::SumOfBallsInFrame(int rollIndex) {
	return rolls_[rollIndex] + rolls_[rollIndex+1];
}
