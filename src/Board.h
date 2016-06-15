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
    std::vector<std::vector<PuzzleSquare> > _mainBoard;
    std::vector<LineDescriptor> _rowDescriptors;
    std::vector<LineDescriptor> _columnDescriptors;

    void delete_board();
	void deserialize_board(const nlohmann::json json);
	static std::vector<LineDescriptor> deserialize_descriptors(const nlohmann::json json);
	static LineDescriptor deserialize_descriptor(const nlohmann::json descriptorJson);
	static std::vector<std::vector<PuzzleSquare> > deserialize_main_board(nlohmann::json json);

	static const nlohmann::json serialize_main_board(std::vector<std::vector<PuzzleSquare>> squares);
};


#endif //NONOGRAM_SOLVER_BOARD_H
