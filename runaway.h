#define UP 'w'
#define DOWN 's'
#define RIGHT 'd'
#define LEFT 'a'

void move(char direction);
int over();
int itsdirection(char direction);
void ghost();
int wayofghost(int actualx, int actualy, int* xgoal, int* ygoal);
