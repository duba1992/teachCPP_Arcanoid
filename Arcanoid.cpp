#include<iostream>
#include"Arcanoid.h"
#include<Windows.h>
#include"Console.h"
#include"Keyboard.h"
#include<time.h>
using namespace std;
void fillArray(int array[25][50], int column, int line) {
	
	for (int x = 0;x < column;x++) {
		for (int y = 0;y < line;y++) {  
			if (x == 0) {
				array[x][y] = 1;  // init roof
			}
			else if (y == 0 || y == 49) { // init bottom
				array[x][y] = 2;

			}
			else if (x == 24 && y > 19 && y < 26) { // init Player
				array[x][y] = 3;                        
			}
			else {
				array[x][y] = 0; // init field
			}
		}
	}

}
void showArray(int array[25][50], int column, int line) {
	
	for (int x = 0;x < column;x++) {
		for (int y = 0;y < line;y++) {
			if (array[x][y] == 1) {
				cout << char(219);
			}
			else if (array[x][y] == 2) {
				cout << char(219);
			}
			else if (array[x][y]==0) {
				cout << " ";
			}
			else {
				cout << array[x][y];
			}
			
		}
		cout << endl;
	}
}
void movePlayer(int array[25][50]) {

	bool game = true;
	const int x = 24;
	int y_1 = 20;
	int y_2 = 25;
	while (game) {
		unsigned short k = KeyPressed();
		
		if (k == VK_RIGHT || k == 77) {  // move right Player
			if (array[24][48] == 3) {
				continue;
			}
			array[x][y_1] = 0;
			gotoxy(y_1, x);
			cout << ' ';
			y_1++;
			y_2++;
			array[x][y_2] = 3;
			gotoxy(y_2, x);
			cout << char(219);
		
		}

		if (k == VK_LEFT || k == 75) {  // move left Player
			if (array[24][1] == 3) {
				continue;
			}
			array[x][y_2] = 0;
			gotoxy(y_2, x);
			cout << ' ';
			y_1--;
			y_2--;
			array[x][y_1] = 3;
			gotoxy(y_1, x);
			cout << char(219);
		

		}
		if (GetAsyncKeyState(VK_ESCAPE)) {
		                            // Exit in game
		}
	
	}
	gotoxy(80, 40);

}
void InitBall(int array[25][50],int &rx, int &ry) {   // Init Ball on the center field
	 rx = 12;
	 ry = 1 + rand() % 48;
	array[rx][ry] = 4;                              //number ball
	gotoxy(ry, rx);
	cout << 'O'; 

}
void MovingBall(int array[25][50],int &x, int &y, bool &up,bool &down, bool &left,bool &right, int &rx, int &ry) {
	array[x][y] = 0;
	x +=rx;
	y +=ry;
	array[x][y] = 4;
	gotoxy(y, x);
	cout << 'O';
	if (array[x][y] == 0 && down) {
		rx = -1;
		ry = 1;
		x += rx;
		y += ry;
		gotoxy(y, x);
		cout << 'O';

	}
	if (array[x][y] == 1 && up  && right) { // kick up and right on the roof
		up = false;
		right = false;
		down = true;
		left = true;
		rx = -1;
		ry = -1;
		x += rx;
		y += ry;
		gotoxy(y, x);
		cout << 'O';
	}
	if (array[x][y] == 1 && up  && left) {  // kick up and left on the roof
		up = false;
		right = true;
		down = true;
		left = false;
		rx = -1;
		ry = 1;
		x += rx;
		y += ry;
		gotoxy(y, x);
		cout << 'O';
	}
	if (array[x][y] == 2 && up && right) {      //kick up and right on the bottom
		up = true;
		right = false;
		down = false;
		left = true;
		rx = 1;
		ry = -1;
		x += rx;
		y += ry;
		gotoxy(y, x);
		cout << 'O';

	}
	if (array[x][y] == 2 && up && left) {   //kick up and left on the bottom
		up = true;
		right = true;
		down = false;
		left = false;
		rx = 1;
		ry = 1;
		x += rx;
		y += ry;
		gotoxy(y, x);
		cout << 'O';

	}
	if (array[x][y] == 3 && down && left) { // kick down on the Player
		up = true;
		right = true;
		down = false;
		left = false;
		rx = 1;
		ry = 1;
		x += rx;
		y += ry;
		gotoxy(y, x);
		cout << 'O';
	}
	if (array[x][y] == 3 && down && right) { // kick down on the Player
		up = true;
		right = false;
		down = false;
		left = true;
		rx = 1;
		ry = -1;
		x += rx;
		y += ry;
		gotoxy(y, x);
		cout << 'O';
	}
	if (array[x][y] == 2 && up && left) {   //kick down and left on the bottom
		up = false;
		right = true;
		down = true;
		left = false;
		rx = -1;
		ry = 1;
		x += rx;
		y += ry;
		gotoxy(y, x);
		cout << 'O';
	}
	if (array[x][y] == 2 && up && right) {   //kick down and right on the bottom
		up = false;
		right = false;
		down = true;
		left = true;
		rx = -1;
		ry = -1;
		x += rx;
		y += ry;
		gotoxy(y, x);
		cout << 'O';
	}


}