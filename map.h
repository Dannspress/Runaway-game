#define HERO '@'
#define GHOST '&'
#define EMPTY '.'
#define WALL_V '|'
#define WALL_H '-'

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
int findmap(MAP* m, POSITION* p, char c);
int itsvalid(MAP* m, int x, int y);
int itsempty(MAP* m, int x, int y);
void walkinmap(MAP* m, int xorigin, int yorigin, int xgoal, int ygoal);
void copymap(MAP* goal, MAP* origin);
int canwalk(MAP* m, char character, int x, int y);
int itscharacter(MAP* m, char character, int x, int y);
int itswall(MAP* m, int x, int y);