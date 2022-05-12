#include <stdio.h>
#include <stdlib.h>

char** map;
int row;
int col;

void freemap() {
  for (int i = 0; i < row; i++) {
    free(map[i]);
  }
  free(map);
}

void allocmap() {
  map = malloc(sizeof(char*) * row);
  for (int i = 0; i < row; i++) {
    map[i] = malloc(sizeof(char) * (col+1));
  }
}

void readmap() {
  FILE* f;
  f = fopen("map.txt", "r");
  if(f == 0) {
    printf("ERROR on reading map.\n");
    exit(1);
  }

  fscanf(f, "%d %d", &row, &col);

  allocmap();

  for (int i = 0; i < 5; i++) {
    fscanf(f, "%s", map[i]);
  }

  fclose(f);
}


int main() {

  readmap();

  for (int i = 0; i < 5; i++) {
    printf("%s\n", map[i]);
  }
  
  freemap();
}
