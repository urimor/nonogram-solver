#ifndef NONOGRAM_SOLVER_PUZZLESQUARE_H
#define NONOGRAM_SOLVER_PUZZLESQUARE_H


#include <vector>

class PuzzleSquare {
public:
    enum State {Unknown, Empty, Full, Test};
    PuzzleSquare(State state = Unknown):_state(state){}
	operator int() const { return (int)_state;}
	int GetState() const {return (int)_state;}
protected:
    State _state;
};


#endif //NONOGRAM_SOLVER_PUZZLESQUARE_H
