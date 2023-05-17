class Location {
	int _row;
	int _col;

public:
	Location(int row, int col);
	Location operator=(Location loc);
	void setRow(int row);
	void setCol(int col);
	int getRow();
	int getCol();
};