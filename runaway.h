#define UP 'w'
#define DOWN 's'
#define RIGHT 'd'
#define LEFT 'a'
#define BOMB 'b'

void move(char direction);
int over();
int itsdirection(char direction);
void ghost();
int wayofghost(int actualx, int actualy, int* xgoal, int* ygoal);
void blowupagain(int x, int y, int sumx, int sumy, int qtd);
void blowup();
