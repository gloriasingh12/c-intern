/* =================================================================
PROJECT: Snake Game (Terminal Edition)
DESCRIPTION: Visual game loop, dynamic difficulty, and input simulation.
DELIVERABLE: A C++ program demonstrating graphic logic and game mechanics.
=================================================================
*/

#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <conio.h> // for _kbhit() and _getch()

using namespace std;

// Game State Enum
enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
Direction dir;

// Global Game Variables
bool gameOver;
const int width = 20;
const int height = 15;
int x, y, fruitX, fruitY, score;
vector<int> tailX, tailY;
int nTail;

// Function to Initialize Game
void Setup() {
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
    nTail = 0;
    tailX.clear();
    tailY.clear();
}

// Function to Draw Game Board (Simulation of Graphic Rendering)
void Draw() {
    system("cls"); // Clear the terminal
    
    // Top border
    for (int i = 0; i < width + 2; i++) cout << "#";
    cout << endl;

    // Game field
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0) cout << "#"; // Left border

            if (i == y && j == x) cout << "O"; // Snake Head
            else if (i == fruitY && j == fruitX) cout << "F"; // Fruit
            else {
                bool print = false;
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        cout << "o"; // Snake Tail
                        print = true;
                    }
                }
                if (!print) cout << " ";
            }

            if (j == width - 1) cout << "#"; // Right border
        }
        cout << endl;
    }

    // Bottom border
    for (int i = 0; i < width + 2; i++) cout << "#";
    cout << endl;

    // Game stats
    cout << "Score: " << score << endl;
    cout << "Press [WASD] to move, [X] to Exit." << endl;
}

// Function to Handle Input
void Input() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'a': dir = LEFT; break;
            case 'd': dir = RIGHT; break;
            case 'w': dir = UP; break;
            case 's': dir = DOWN; break;
            case 'x': gameOver = true; break;
        }
    }
}

// Function to Update Game Logic (Movement, Collision, Difficulty)
void Logic() {
    // Tail movement logic
    int prevX = tailX.empty() ? x : tailX[0];
    int prevY = tailY.empty() ? y : tailY[0];
    int prev2X, prev2Y;
    if (!tailX.empty())
