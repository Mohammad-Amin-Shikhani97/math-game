#include <iostream> 
#include <cstdlib> 
#include <string> 
using namespace std;

enum enLevels { Easy = 1, Medium = 2, Hard = 3, Mix = 4 };
enum enOperations { Add = 1, Sub = 2, Mul = 3, Div = 4 };
struct stQuiz {
    enLevels level;
    enOperations  operation;
    short question;
    bool Right = false;
};

struct stQuistion {
    int num1;
    int num2;
    int answer;
    int result;
};

short RandomNumber(short from, short to) {
    short randNumber = rand() % (to - from + 1) + from;
    return randNumber;
}

short ReadNumber(short from, short to, string message) {
    int number = 0;
    do {
        cout << message;
        cin >> number;
    } while (number > to || number < from);
    return number;
}

stQuiz getGameSettings() {
    stQuiz settings;
    settings.question = ReadNumber(1, 10, "How Many Questions do you want to answer (1 to 10 ) ? ");
    settings.level = (enLevels)ReadNumber(1, 4, "Enter Questions Level [1] Easy, [2] Med, [3] Hard, [4] Mix ? ");
    settings.operation = (enOperations)ReadNumber(1, 4, "Enter Operations type [1] Add, [2] Sub, [3] Mul, [4] div ? ");
    return settings;
}

int generateNumber(stQuiz settings) {
    switch (settings.level) {
    case Easy:
        return RandomNumber(1, 10);
        break;
    case Medium:
        return RandomNumber(11, 50);
        break;
    case Hard:
        return RandomNumber(51, 100);
        break;
    case Mix:
        return RandomNumber(1, 100);
        break;
    }
}

string getOpTypeSymbol(stQuiz settings) {
    string arr[4] = { "+", "-", "*", "/" };
    return arr[settings.operation - 1];
}
string getLevelName(stQuiz settings) {
    string arr[4] = { "Easy", "Medium", "Hard", "Mix" };
    return arr[settings.level - 1];
}

int rightResult(stQuistion Quis, stQuiz settings) {
    switch (settings.operation) {
    case Add:
        return Quis.num1 + Quis.num2;
        break;
    case Sub:
        return Quis.num1 - Quis.num2;
        break;
    case Mul:
        return Quis.num1 * Quis.num2;
        break;
    case Div:
        return Quis.num1 / Quis.num2;
        break;
    }
}

void PrintQuestion(int Questioncounter, stQuiz settings, stQuistion Quis) {
    cout << "\nQuestion [" << Questioncounter << "/" << settings.question << "]\n\n";
    cout << Quis.num1 << endl;
    cout << Quis.num2 << " " << getOpTypeSymbol(settings) << endl;
    cout << "_________\n";
}

void changeColors(bool right) {
    if (right) {
        system("color AF");
    }
    else {
        system("color 4F");
    }
}

void showRightResult(stQuiz settings, int result) {
    if (settings.Right)
        cout << "Right Answer :-)\n";
    else
        cout << "\aWrong Answer :-(\nThe right Answer is: " << result;

}

int rightAnswerCounter(stQuiz settings) {
    int counter = 0;

    if (settings.Right)
        counter++;

    return counter;
}

void isPassOrFaill(bool pass) {
    cout << "\n________________________________________\n\n";
    if (pass) {
        cout << " Final Resluts is PASS :-)\n";
    }
    else {
        cout << " Final Resluts is FAIL :-)\n";
    }
    cout << "________________________________________\n\n";
}

void printFinalResult(stQuiz settings, int counter) {

    cout << "Numbers of Questions: " << settings.question << "\n";
    cout << "Questions Level     : " << getLevelName(settings) << "\n";
    cout << "OpType              : " << getOpTypeSymbol(settings) << "\n";
    cout << "Number of Right Answers: " << counter << "\n";
    cout << "Number of Wrong Answers: " << settings.question - counter << "\n";
    cout << "_______________________________________\n";
}

void resetScreen() {
    system("color 07");
    system("CLS");
}

bool isRight(int answer, int result) {
    return answer == result;
}

void Play() {

    int counter = 0;
    stQuiz settings = getGameSettings();
    stQuistion Quis;

    for (short i = 1; i <= settings.question; i++) {

        Quis.num1 = generateNumber(settings);
        Quis.num2 = generateNumber(settings);
        Quis.result = rightResult(Quis, settings);

        PrintQuestion(i, settings, Quis);

        cin >> Quis.answer;

        settings.Right = isRight(Quis.answer, Quis.result);

        changeColors(settings.Right);
        showRightResult(settings, Quis.result);
        counter += rightAnswerCounter(settings);
    }

    changeColors(settings.question - counter < counter);
    isPassOrFaill(settings.question - counter < counter);
    printFinalResult(settings, counter);
}

void StartGame() {
    char playAgain = 'y';
    while (playAgain == 'y' || playAgain == 'Y') {
        resetScreen();
        Play();
        cout << "\nDo you want to play again (Y/N)?";
        cin >> playAgain;
    }
}

int main() {
    srand((unsigned)time(NULL));

    StartGame();
    return 0;
}