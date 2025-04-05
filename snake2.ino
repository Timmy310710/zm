#include<GameBoy.h>

GameBoy Xs;


int snakeX[10];
int snakeY[10];

int up = 0;
int right = 1;
int bottom = 2;
int left = 3;
int direction = right;

int lenSnake = 5;

int x = 1, y = 0;
int dirX, dirY;

void setup() {
  snakeX[0] = 4;
  snakeY[0] = 7;
  Xs.begin(8);

}

void loop() {
  makeMove();
  move();

  Xs.clearDisplay();
  
  drawSnake();
  delay(300);

}
void makeMove() {
  if (Xs.getKey() == 4) {
    // x = -1;
    //y = 0;
    direction = left;
  }

  else if (Xs.getKey() == 5) {
    //x = 1;
    //y = 0;
    direction = right;
  }

  else if (Xs.getKey() == 6) {
    //x = 0;
    //y = 1;
    direction = bottom;
  }

  else if (Xs.getKey() == 3) {
    //x = 0;
    //y = -1;
    direction = up;
  }

}


void move() {
  for (int i = lenSnake - 1; i > 0 ; i--) {
    snakeX[i] = snakeX[i - 1];
    snakeY[i] = snakeY[i - 1];
  }
  if (direction == up) {
    if (snakeY[0] == 0) {
      snakeY[0] = 15;
    } else {
      snakeY[0]--;
    }
  }
  else if (direction == bottom) {
    if (snakeY[0] == 15) {
      snakeY[0] = 0;
    } else {
      snakeY[0]++;
    }
  }

  else if (direction == left) {
    if (snakeX[0] == 0) {
      snakeX[0] = 7;
    } else {
      snakeX[0]--;
    }
  }

  else if (direction == right) {
    if (snakeX[0] == 7) {
      snakeX[0] = 0;
    } else {
      snakeX[0]++;
    }
  }
}

void drawSnake() {
  for (int i = 0; i < lenSnake; i ++) {
    Xs.drawPoint(snakeX[i], snakeY[i]);
  }
}
