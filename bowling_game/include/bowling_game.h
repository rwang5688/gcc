// bowling_game.h
#ifndef BOWLING_GAME_H_
#define BOWLING_GAME_H_

class Game {
private:
	int rolls_[21];
	int currentRoll_ = 0;

public:
	void Roll(int pins);
	int Score();

protected:
	bool IsStrike(int rollIndex);
	int StrikeBonus(int rollIndex);
	bool IsSpare(int rollIndex);
	int SpareBonus(int rollIndex);
	int SumOfBallsInFrame(int rollIndex);
};

#endif  // BOWLING_GAME_H_