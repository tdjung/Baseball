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

		int strike = 0;
		int ball = 0;
		for (int num = 0; num < 3; num++) {
			for (int num2 = 0; num2 < 3; num2++) {
				if (guessNumber[num] == question[num2]) {
					if (num == num2)
						strike += 1;
					else ball += 1;
				}
			}
		}

		return { false, strike, ball };
	}
	
private:
	string question;

};