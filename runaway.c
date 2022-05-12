#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "runaway.h"
#include "map.h"

MAP m;
POSITION hero;

int wayofghost(int actualx, int actualy, int* xgoal, int* ygoal) {
  int options[4][2] =  {
    {actualx, actualy+1},
    {actualx+1, actualy},
    {actualx, actualy-1},
    {actualx-1, actualy}
  };

  srand(time(0));
  for (int i = 0; i < 10; i++) {
    int position = rand() % 4;

    if(canwalk(&m, GHOST, options[position][0], options[position][1])) {
      *xgoal = options[position][0];
      *ygoal = options[position][0];

      return 1;
    }
  }
  return 0;
}

void ghost() {
  MAP copy;

  copymap(&copy, &m);

  for (int i = 0; i < m.row; i++) {
    for (int j = 0; j < m.col; j++) {
      if(m.matriz[i][j] == GHOST) {

        int xgoal;
        int ygoal;

        int found = wayofghost(i, j, &xgoal, &ygoal);

        if(found) {
          walkinmap(&m, i, j, xgoal, ygoal);
        }

        if(itsvalid(&m, i, j+1) && itsempty(&m, i, j+1)) {
          walkinmap(&m, i, j, i, j+1);
        }
      }
    }
  }
  freemap(&copy);
}

int over() {
  POSITION pos;
  int runawayonmap = findmap(&m, &pos, HERO);
  return !runawayonmap;
}

int itsdirection(char direction) {
  return direction != LEFT || direction != UP || direction != DOWN || direction != RIGHT;
}

void move(char direction) {

  if(!itsdirection(direction))
    return;

  int nextx = hero.x;
  int nexty = hero.y;

  switch (direction)
  {
    case LEFT:
      nexty--;
      break;
    case UP:
      nextx--;
      break;
    case DOWN:
      nextx++;
      break;
    case RIGHT:
      nexty++;
      break;
  }

  if(!canwalk(&m, HERO, nextx, nexty))
    return;

  walkinmap(&m, hero.x, hero.y, nextx, nexty);
  hero.x = nextx;
  hero.y = nexty;
  
}

int main() {

  readmap(&m);
  findmap(&m, &hero, HERO);

  do {
    printmap(&m);

    char command;
    scanf(" %c", &command);
    move(command);
    ghost();
  } while(!over());
  
  freemap(&m);
}
