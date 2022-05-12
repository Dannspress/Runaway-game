#include <stdio.h>
#include <stdlib.h>
#include "map.h"

void findmap(MAP* m, POSITION* p, char c) {
  for (int i = 0; i < m->row; i++) {
    for (int j = 0; j < m->col; j++) {
      if(m->matriz[i][j] == c) {
        p->x = i;
        p->y = j;
        break;
      }
    }
  }
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