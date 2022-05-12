struct map {
  char** matriz;
  int row;
  int col;
};

typedef struct map MAP;

struct position {
  int x;
  int y;
};

typedef struct position POSITION;

void freemap(MAP* m);
void allocmap(MAP* m);
void readmap(MAP* m);
void printmap(MAP* m);
void findmap(MAP* m, POSITION* p, char c);