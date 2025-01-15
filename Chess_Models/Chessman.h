 #ifndef CHESS_CHESSMAN_H
#define CHESS_CHESSMAN_H
#include <string>
#include <cmath>
#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>
enum class ChessmanColor {BLACK, WHITE};

enum class ChessmanIsMakeMove {TRUE, FALSE, NON};

enum class ChessmanType {PAWN, ROOK, BISHOP, KNIGHT, QUEEN, KING};

class Chessman
{
public:
    explicit Chessman(ChessmanColor Color): color(Color), move(ChessmanIsMakeMove::NON){}
    virtual ChessmanType GetType() = 0;
    ChessmanColor GetColor();
    ChessmanIsMakeMove GetMove();
    ChessmanIsMakeMove SetMove(ChessmanIsMakeMove move);
    bool IsMoveLegal(int start_posX,int start_posY, int end_posX, int end_posY, Chessman* board[8][8]);
    virtual bool AreCastleLegal(int start_posX,int start_posY, int end_posX, int end_posY, Chessman* board[8][8]) = 0;
    ~Chessman() = default;
private:
    virtual bool AreFieldLegal(int start_posX,int start_posY, int end_posX, int end_posY, Chessman* board[8][8]) = 0;
    ChessmanColor color;
protected:
    ChessmanIsMakeMove move;
};


#endif //CHESS_CHESSMAN_H
