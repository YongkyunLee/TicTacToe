class Board {
private:
  int squares[10];
public:
  Board();
  int query(int coord);
  void place(int coord, int piece);
  int checkWin();
  bool checkDraw();
  void print();
};

bool horizontal(int board[10], int piece);
bool vertical(int board[10], int piece);
bool diagonal(int board[10], int piece);
std::string trans(int board[10], int coord);
