#include "Board.h"
#include "Common.h"

using std::vector;
using std::string;
using Json = nlohmann::json;

static const string RowDescriptorsFieldName = "row-descriptors";
static const string ColumnDescriptorsFieldName = "column-descriptors";
static const string MainBoardFieldName = "main-board";

Board::Board(Json boardJson) {
	Init(boardJson);
}

void Board::Init(Json boardJson){
    delete_board();
	try {
		deserialize_board(boardJson);
	}
	catch (std::domain_error exception){
		Common::ExitOnError(exception, "Could not deserialize board");
	}
}

Json Board::Serialize() const {
	Json serializedBoard;
	serializedBoard[RowDescriptorsFieldName] = Json(_rowDescriptors);
	serializedBoard[ColumnDescriptorsFieldName] = Json(_columnDescriptors);
	serializedBoard[MainBoardFieldName] = Json(_mainBoard);
	return serializedBoard;
}


const std::vector<std::vector<PuzzleSquare> > Board::GetSquares() const {
    return _mainBoard;
}


const std::vector<LineDescriptor> Board::GetRowDescriptors() const {
    return _rowDescriptors;
}

const std::vector<LineDescriptor> Board::GetColumnDescriptors() const {
    return _columnDescriptors;
}

void Board::delete_board() {
    _mainBoard.clear();
    _columnDescriptors.clear();
    _rowDescriptors.clear();
}

void Board::deserialize_board(const Json json) {
	_rowDescriptors = deserialize_descriptors(json[RowDescriptorsFieldName]);
	_columnDescriptors = deserialize_descriptors(json[ColumnDescriptorsFieldName]);
	_mainBoard = deserialize_main_board(json[MainBoardFieldName]);
}

vector<LineDescriptor> Board::deserialize_descriptors(const Json lineDescriptorsJson) {
	vector<LineDescriptor> resultLineDescriptors;
	for(const auto descriptor : lineDescriptorsJson){
		if(!descriptor.is_array()){
			throw(std::domain_error("LineDescriptor is not an array"));
		}
		resultLineDescriptors.push_back(deserialize_descriptor(descriptor));
	}
	return resultLineDescriptors;
}

LineDescriptor Board::deserialize_descriptor(const Json descriptorJson){
	LineDescriptor resultLineDescriptor;
	for(const auto descriptorElement : descriptorJson){
		if(!descriptorElement.is_number_integer()){
			throw(std::domain_error("Board::deserialize_descriptor - Descriptor element is not a number"));
		}
		resultLineDescriptor.push_back(static_cast<int>(descriptorElement));
	}
	return resultLineDescriptor;
}

vector<vector<PuzzleSquare> > Board::deserialize_main_board(const Json squaresJson) {
	vector<vector<PuzzleSquare> > resultSquares;
	for(const auto squaresRow : squaresJson){
		std::vector<PuzzleSquare> resultSquaresRow;
		for(const auto square : squaresRow){
			if(!square.is_number_integer()){
				throw(std::domain_error("Board::deserialize_main_board - Descriptor element is not a number"));
			}
			resultSquaresRow.push_back(PuzzleSquare(static_cast<PuzzleSquare::State>((int)square)));
		}
		resultSquares.push_back(resultSquaresRow);
	}
	return resultSquares;
}