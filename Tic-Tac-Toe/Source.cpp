#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

char player = 'X';
char cpu = 'O';
char one = '1', two = '2', three = '3', four = '4', five = '5', six = '6', seven = '7', eight = '8', nine = '9';
bool onePos, twoPos, threePos, fourPos, fivePos, sixPos, sevenPos, eightPos, ninePos, cpuTurn;

void printTable() {

	std::cout << " " << one << " " << "|" << " " << two << " " << "|" << " " << three << " " << std::endl;
	std::cout << "---" << "|" << "---" << "|" << "---" << std::endl;
	std::cout << " " << four << " " << "|" << " " << five << " " << "|" << " " << six << " " << std::endl;
	std::cout << "---" << "|" << "---" << "|" << "---" << std::endl;
	std::cout << " " << seven << " " << "|" << " " << eight << " " << "|" << " " << nine << " " << std::endl;

}

void aiCheck(int i) {
	switch (i) {
	case 1:
		if (onePos == true) {
			aiCheck(rand() % 9 + 1);
		}
		else {
			one = cpu;
			onePos = true;
			cpuTurn = false;
		}
		break;
	case 2:
		if (twoPos == true) {
			aiCheck(rand() % 9 + 1);
		}
		else {
			two = cpu;
			twoPos = true;
			cpuTurn = false;
		}
		break;
	case 3:
		if (threePos == true) {
			aiCheck(rand() % 9 + 1);
		}
		else {
			three = cpu;
			threePos = true;
			cpuTurn = false;
		}
		break;
	case 4:
		if (fourPos == true) {
			aiCheck(rand() % 9 + 1);
		}
		else {
			four = cpu;
			fourPos = true;
			cpuTurn = false;
		}
		break;
	case 5:
		if (fivePos == true) {
			aiCheck(rand() % 9 + 1);
		}
		else {
			five = cpu;
			fivePos = true;
			cpuTurn = false;
		}
		break;
	case 6:
		if (sixPos == true) {
			aiCheck(rand() % 9 + 1);
		}
		else {
			six = cpu;
			sixPos = true;
			cpuTurn = false;
		}
		break;
	case 7:
		if (sevenPos == true) {
			aiCheck(rand() % 9 + 1);
		}
		else {
			seven = cpu;
			sevenPos = true;
			cpuTurn = false;
		}
		break;
	case 8:
		if (eightPos == true) {
			aiCheck(rand() % 9 + 1);
		}
		else {
			eight = cpu;
			eightPos = true;
			cpuTurn = false;
		}
		break;
	case 9:
		if (ninePos == true) {
			aiCheck(rand() % 9 + 1);
		}
		else {
			nine = cpu;
			ninePos = true;
			cpuTurn = false;
		}
		break;
	}
}

void caseCheck(int i) {
	switch (i) {
	case 1:
		if (onePos == true) {
			std::cout << "position taken, try again\n";
		}
		else {
			one = player;
			onePos = true;
			cpuTurn = true;
		}
		break;
	case 2:
		if (twoPos == true) {
			std::cout << "position taken, try again\n";
		}
		else {
			two = player;
			twoPos = true;
			cpuTurn = true;
		}
		break;
	case 3:
		if (threePos == true) {
			std::cout << "position taken, try again\n";
		}
		else {
			three = player;
			threePos = true;
			cpuTurn = true;
		}
		break;
	case 4:
		if (fourPos == true) {
			std::cout << "position taken, try again\n";
		}
		else {
			four = player;
			fourPos = true;
			cpuTurn = true;
		}
		break;
	case 5:
		if (fivePos == true) {
			std::cout << "position taken, try again\n";
		}
		else {
			five = player;
			fivePos = true;
			cpuTurn = true;
		}
		break;
	case 6:
		if (sixPos == true) {
			std::cout << "position taken, try again\n";
		}
		else {
			six = player;
			sixPos = true;
			cpuTurn = true;
		}
		break;
	case 7:
		if (sevenPos == true) {
			std::cout << "position taken, try again\n";
		}
		else {
			seven = player;
			sevenPos = true;
			cpuTurn = true;
		}
		break;
	case 8:
		if (eightPos == true) {
			std::cout << "position taken, try again\n";
		}
		else {
			eight = player;
			eightPos = true;
			cpuTurn = true;
		}
		break;
	case 9:
		if (ninePos == true) {
			std::cout << "position taken, try again\n";
		}
		else {
			nine = player;
			ninePos = true;
			cpuTurn = true;
		}
		break;
	}
}

bool checkWin(char symbol) {
	// Check rows
	if ((one == symbol && two == symbol && three == symbol) ||
		(four == symbol && five == symbol && six == symbol) ||
		(seven == symbol && eight == symbol && nine == symbol)) {
		return true;
	}
	// Check columns
	if ((one == symbol && four == symbol && seven == symbol) ||
		(two == symbol && five == symbol && eight == symbol) ||
		(three == symbol && six == symbol && nine == symbol)) {
		return true;
	}
	// Check diagonals
	if ((one == symbol && five == symbol && nine == symbol) ||
		(three == symbol && five == symbol && seven == symbol)) {
		return true;
	}
	return false;
}

bool checkDraw() {
	return (onePos && twoPos && threePos && fourPos && fivePos && sixPos && sevenPos && eightPos && ninePos);
}

int main() {
	srand(time(0));
	bool running = true;
	int input;

	while (running) {
		printTable();
		std::cout << "Please enter a number between 1 - 9\n";
		std::cin >> input;
		if (input > 0 && input <= 9) {
			caseCheck(input);
			if (cpuTurn && !checkDraw() && !checkWin(player)) {
				aiCheck(rand() % 9 + 1);
			}
			if (checkWin(player)) {
				printTable();
				std::cout << "You win!\n";
				running = false;
			}
			else if (checkWin(cpu)) {
				printTable();
				std::cout << "Computer wins!\n";
				running = false;
			}
			else if (checkDraw()) {
				printTable();
				std::cout << "It's a draw!\n";
				running = false;
			}
		}
		else {
			std::cout << "Invalid input, try again\n";
		}
	}

	return 0;
}

