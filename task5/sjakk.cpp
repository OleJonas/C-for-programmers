#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class ChessBoard {
    public:
    string boardstate[8][8];

    ChessBoard() {
        // Initialize the squares stored in 8 columns and 8 rows:
        squares.resize(8);
        for (auto &square_column : squares) square_column.resize(8);
    }

    enum class Color { WHITE,
                        BLACK };

    class Piece {
    public:
        Piece(Color color) : color(color) {}
        virtual ~Piece() {}

        Color color;
        std::string color_string() const {
        if (color == Color::WHITE)
            return "white";
        else
            return "black";
        }

        string short_color_string() const{
            if (color == Color::WHITE) return "w";
            else return "b";
        }

        /// Return color and type of the chess piece
        virtual std::string type() const = 0;
        virtual string notation() const = 0;

        /// Returns true if the given chess piece move is valid
        virtual bool valid_move(int from_x, int from_y, int to_x, int to_y) const = 0;
    };

    class King : public Piece {
        public:

            King(const Color color) : Piece(color){}

            bool valid_move(int from_x, int from_y, int to_x, int to_y) const override{
                bool res = true;

                if(abs(to_x - from_x) > 1 || abs(to_y - from_y) > 1) res = false;
                else if(to_x - from_x == 0 && to_y - from_y == 0) res = false; // Checking if piece is stationary

                return res;
            }

            string type() const override{
                return Piece::color_string() + " king";
            }

            string notation() const override{
                return Piece::short_color_string() + "K ";
            }
    };

    class Knight : public Piece {
        public:

            Knight(Color color) : Piece(color){}

            bool valid_move(int from_x, int from_y, int to_x, int to_y) const override{
                bool res = true;

                if(to_x - from_x == 0 || to_y - from_y == 0) res = false; // Knight has to move at least 1 in each direction
                else if(abs(to_x - from_x) > 2 || abs(to_y - from_y) > 2) res = false; // Max 2 in each direction
                else if(abs(to_x - from_x) == 2 && abs(to_y - from_y) != 1) res = false;
                else if(abs(to_x - from_x) == 1 && abs(to_y - from_y) != 2) res = false;

                return res;
            }

            string type() const override{
                return Piece::color_string() + " knight";
            }

            string notation() const override{
                return Piece::short_color_string() + "Kn";
            }
    };

    /// 8x8 squares occupied by 1 or 0 chess pieces
    vector<vector<unique_ptr<Piece>>> squares;

    /// Move a chess piece if it is a valid move.
    /// Does not test for check or checkmate.
    bool move_piece(const std::string &from, const std::string &to) {
        int from_x = from[0] - 'a';
        int from_y = stoi(string() + from[1]) - 1;
        int to_x = to[0] - 'a';
        int to_y = stoi(string() + to[1]) - 1;

        auto &piece_from = squares[from_x][from_y];
        if (piece_from) {
        if (piece_from->valid_move(from_x, from_y, to_x, to_y)) {
            cout << piece_from->type() << " is moving from " << from << " to " << to << endl;
            auto &piece_to = squares[to_x][to_y];
            if (piece_to) {
            if (piece_from->color != piece_to->color) {
                cout << piece_to->type() << " is being removed from " << to << endl;
                if (auto king = dynamic_cast<King *>(piece_to.get()))
                cout << king->color_string() << " lost the game" << endl;
            } else {
                // piece in the from square has the same color as the piece in the to square
                cout << "can not move " << piece_from->type() << " from " << from << " to " << to << endl;
                return false;
            }
            }
            piece_to = move(piece_from);
            update_boardstate(from_x, from_y, to_x, to_y);
            cout << board_tostring() << endl;

            return true;
        } else {
            cout << "can not move " << piece_from->type() << " from " << from << " to " << to << endl;
            return false;
        }
        } else {
        cout << "no piece at " << from << endl;
        return false;
        }
    }

    void update_boardstate(int from_x, int from_y, int to_x, int to_y){
        boardstate[to_x][to_y] = boardstate[from_x][from_y];
        boardstate[from_x][from_y] = "   ";
    }

    void init_boardstate(){
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                auto &piece = squares[i][j];
                if(piece) boardstate[i][j] = piece->notation();
                else boardstate[i][j] = "   ";
            }
        }
    }

    string board_tostring(){
        string out;
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                out += "|" + boardstate[i][j];
            }
            out += "|\n";
            if(i != 7){
                for(int k = 0; k < 8; k++) out += "____";
            }
            out += "\n"; 
        }
        return out;
    }
};

int main() {
  ChessBoard board;

  board.squares[4][0] = make_unique<ChessBoard::King>(ChessBoard::Color::WHITE);
  board.squares[1][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);
  board.squares[6][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);

  board.squares[4][7] = make_unique<ChessBoard::King>(ChessBoard::Color::BLACK);
  board.squares[1][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);
  board.squares[6][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);

  board.init_boardstate();

  cout << "Invalid moves:" << endl;
  board.move_piece("e3", "e2");
  board.move_piece("e1", "e3");
  board.move_piece("b1", "b2");
  cout << endl;

  cout << "A simulated game:" << endl;
  board.move_piece("e1", "e2");
  board.move_piece("g8", "h6");
  board.move_piece("b1", "c3");
  board.move_piece("h6", "g8");
  board.move_piece("c3", "d5");
  board.move_piece("g8", "h6");
  board.move_piece("d5", "f6");
  board.move_piece("h6", "g8");
  board.move_piece("f6", "e8");
}