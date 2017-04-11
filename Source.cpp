#include<iostream>
#include"Arcanoid.h"
#include"Console.h"
using namespace std;


int main() {
	bool game = true;
	bool start = true;
	bool down = true;
	bool up = false;
	bool left = false;
	bool right = true;
	int x = 0, y = 0, rx = 0, ry = 0;
	const int column = 25;
	const int line = 50;
	system("mode con cols=120 lines=40");
	int array[column][line];
	fillArray(array, column, line);
	showArray(array, column, line);
	InitBall(array, rx, ry);
	
	while (game) {
		movePlayer(array);

		
		

	}




}