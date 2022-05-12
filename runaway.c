#include <stdio.h>
#include <stdlib.h>
#include "runaway.h"
#include "map.h"

MAP m;
POSITION hero;

int over() {
  return 0;
}

void move(char direction) {
  int x;
  int y;

  m.matriz[hero.x][hero.y] = '.';

  switch (direction)
  {
  case 'a':
    m.matriz[hero.x][hero.y-1] = '@';
    hero.y--;
    break;
  case 'w':
    m.matriz[hero.x-1][hero.y] = '@';
    hero.x--;
    break;
  case 's':
    m.matriz[hero.x+1][hero.y] = '@';
    hero.x++;
    break;
  case 'd':
    m.matriz[hero.x][hero.y+1] = '@';
    hero.y++;
    break;
  }
  
}

int main() {

  readmap(&m);
  findmap(&m, &hero, '@');

  do {
    printmap(&m);

    char command;
    scanf(" %c", &command);
    move(command);
  } while(!over());
  
  freemap(&m);
}
