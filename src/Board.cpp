#include "Board.h"

using std::vector;
using std::string;
using Json = nlohmann::json;

static const string RowDescriptorsFieldName = "row-descriptors";
static const string ColumnDescriptorsFieldName = "column-descriptors";

Board::Board(Json boardJson) {
	Init(boardJson);
}

void Board::Init(Json boardJson){
    delete_board();
	deserialize_board(boardJson);
}

Json Board::Serialize() const {
	Json serializedBoard;
	serializedBoard[RowDescriptorsFieldName] = Json(_rowDescriptors);
	serializedBoard[ColumnDescriptorsFieldName] = Json(_columnDescriptors);
	return serializedBoard;
}


const std::vector<std::vector<PuzzleSquare> > Board::GetSquares() const {
    return _squares;
}


const std::vector<LineDescriptor> Board::GetRowDescriptors() const {
    return _rowDescriptors;
}

const std::vector<LineDescriptor> Board::GetColumnDescriptors() const {
    return _columnDescriptors;
}

void Board::delete_board() {
    _squares.clear();
    _columnDescriptors.clear();
    _rowDescriptors.clear();
}

void Board::deserialize_board(const Json json) {
	_rowDescriptors = deserialize_descriptors(json[RowDescriptorsFieldName]);
	_columnDescriptors = deserialize_descriptors(json[ColumnDescriptorsFieldName]);
	deserialize_squares(json);
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
			throw(std::domain_error("Descriptor element is not a number"));
		}
		resultLineDescriptor.push_back(static_cast<int>(descriptorElement));
	}
	return resultLineDescriptor;
}

void Board::deserialize_squares(const Json squaresJson) {

}

