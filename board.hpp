class Board {
private:
  int *squares;
public:
  Board();
  //~Board();
  int query(int coord);
  void place(int coord, int piece);
  int checkWin();
  bool checkDraw();
  void print();
};

bool horizontal(int *board, int piece);
bool vertical(int *board, int piece);
bool diagonal(int *board, int piece);
std::string trans(int *board, int coord);
