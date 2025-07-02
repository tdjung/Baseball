#include <stdexcept>

using namespace std;

struct GuessResult {
	bool solved;
	int strikes;
	int balls;
};


class Baseball {
public:
	explicit Baseball(const string& question)
		: question(question){
	}

	bool isDuplicateNumber(const std::string& guessNumber){
		return guessNumber[0] == guessNumber[1]
			|| guessNumber[0] == guessNumber[2]
			|| guessNumber[1] == guessNumber[2];
	}

	void assertIllegalArgument(const std::string& guessNumber) {
		if (guessNumber.length() != 3) {
			throw length_error("Must be three letters.");
		}

		for (char ch : guessNumber) {
			if (ch >= '0' && ch <= '9') continue;
			throw invalid_argument("Mus be number");
		}

		if (isDuplicateNumber(guessNumber)) {
			throw invalid_argument("Must not have the same number");
		}
	}

	GuessResult guess(const string& guessNumber) {
		assertIllegalArgument(guessNumber);
		if (guessNumber == question) {
			return { true, 3, 0 };
		}

		int strike = 0, ball = 0;
		for (int guessIdx = 0; guessIdx < 3; guessIdx++) {
			for (int answerIdx = 0; answerIdx < 3; answerIdx++) {
				if (guessNumber[guessIdx] == question[answerIdx]) {
					if (guessIdx == answerIdx) strike += 1;
					else ball += 1;
					break;
				}
			}
		}

		return { false, strike, ball };
	}
	
private:
	string question;

};