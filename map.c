#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"

void copymap(MAP* goal, MAP* origin) {
  goal->row = origin->row;
  goal->col = origin->col;

  allocmap(goal);
  for (int i = 0; i < origin->row; i++) {
    for (int j = 0; j < origin->col; j++) {
      strcpy(goal->matriz[i], origin->matriz[i]);
    } 
  }
}

void walkinmap(MAP* m, int xorigin, int yorigin, int xgoal, int ygoal) {
  char character = m->matriz[xorigin][yorigin];
  m->matriz[xgoal][ygoal] = character;
  m->matriz[xorigin][yorigin] = EMPTY;
}

int itsvalid(MAP* m, int x, int y) {
  if(x >= m->row)
    return 0;
  
  if(y >= m->col)
    return 0;

  return 1;
}

int itsempty(MAP* m, int x, int y) {
  return m->matriz[x][y] != EMPTY;
}

int findmap(MAP* m, POSITION* p, char c) {
  for (int i = 0; i < m->row; i++) {
    for (int j = 0; j < m->col; j++) {
      if(m->matriz[i][j] == c) {
        p->x = i;
        p->y = j;
        return 1;
      }
    }
  }
  return 0;
}

int itswall(MAP* m, int x, int y) {
  return m->matriz[x][y] == WALL_V || m->matriz[x][y] == WALL_H;
}

int itscharacter(MAP* m, char character, int x, int y) {
  return m->matriz[x][y] == character;
}

int canwalk(MAP* m, char character, int x, int y) {
  return
    itsvalid(m, x, y) && itswall(m, x, y) && !itscharacter(m, character, x, y);
}

void freemap(MAP* m) {
  for (int i = 0; i < m->row; i++) {
    free(m->matriz[i]);
  }
  free(m->matriz);
}

void allocmap(MAP* m) {
  m->matriz = malloc(sizeof(char*) * m->row);
  for (int i = 0; i < m->row; i++) {
    m->matriz[i] = malloc(sizeof(char) * (m->col+1));
  }
}

void readmap(MAP* m) {
  FILE* f;
  f = fopen("map.txt", "r");
  if(f == 0) {
    printf("ERROR on reading map.\n");
    exit(1);
  }

  fscanf(f, "%d %d", &(m->row), &(m->col));

  allocmap(m);

  for (int i = 0; i < 5; i++) {
    fscanf(f, "%s", m->matriz[i]);
  }

  fclose(f);
}

void printmap(MAP* m) {
  for (int i = 0; i < 5; i++) {
    printf("%s\n", m->matriz[i]);
  }
}