#ifndef NONOGRAM_SOLVER_BOARD_H
#define NONOGRAM_SOLVER_BOARD_H

#include <vector>
#include <json.h>
#include "PuzzleSquare.h"

typedef std::vector<int> LineDescriptor;

class Board {
public:
    Board(nlohmann::json json);
    void Init(nlohmann::json json);
	nlohmann::json Serialize() const;
    const std::vector<std::vector<PuzzleSquare> > GetSquares() const;
    const std::vector<LineDescriptor> GetRowDescriptors() const;
    const std::vector<LineDescriptor> GetColumnDescriptors() const;

private:
    std::vector<std::vector<PuzzleSquare> > _squares;
    std::vector<LineDescriptor> _rowDescriptors;
    std::vector<LineDescriptor> _columnDescriptors;

    void delete_board();
	void deserialize_board(const nlohmann::json json);
	static std::vector<LineDescriptor> deserialize_descriptors(const nlohmann::json json);
	static LineDescriptor deserialize_descriptor(const nlohmann::json descriptorJson);
	void deserialize_squares(nlohmann::json json);
};


#endif //NONOGRAM_SOLVER_BOARD_H
