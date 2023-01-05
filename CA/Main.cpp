#include <iostream> 
#include <ctime>
#include <vector>
#include <array>

void DisplayCellsRow(const std::vector<bool>& cells)
{
	// display a row of cells to the console 
	for (auto cell : cells)
	{
		if (cell == true)
		{
			std::cout << "x ";
		}
		else
		{
			std::cout << "- ";
		}
	}
	// go to the next line after displaying the row 
	std::cout << "\n";
}

std::vector<bool> ProcessCells(const std::vector<bool>& cells, const std::array<bool, 8>& rule)
{
	// create cells that will store the cell states after being processed 
	std::vector<bool> processed(cells.size());

	for (int i = 0; i < processed.size(); i++)
	{
		// get the current and neighboring cell states using (i)ndex 
		int left = i - 1;
		if (left < 0) left = cells.size() - 1;
		int center = i;
		int right = (i + 1) % cells.size();

		bool states[3];
		states[0] = cells[left];
		states[1] = cells[center];
		states[2] = cells[right];

		bool state = false;

		// current pattern 111 110 101 100 011 010 001 000 
		// rule    0   1   2   3   4   5   6   7 
		if (states[0] && states[1] && states[2]) state = rule[0];
		// Rule 1 = 110
		else if (states[0] && states[1] && !states[2]) state = rule[1];
		// Rule 2 = 101
		else if (states[0] && !states[1] && states[2]) state = rule[2];
		// Rule 3 = 100
		else if (states[0] && !states[1] && !states[2]) state = rule[3];
		// Rule 4 = 011
		else if (!states[0] && states[1] && states[2]) state = rule[4];
		// Rule 5 = 010
		else if (!states[0] && states[1] && !states[2]) state = rule[5];
		// Rule 6 = 001
		else if (!states[0] && !states[1] && states[2]) state = rule[6];
		// Rule 7 = 000
		else if (!states[0] && !states[1] && !states[2]) state = rule[7];

			
		processed[i] = state;
	}

	return processed;
}

int main() 
{
	srand((unsigned int)time(nullptr));
	
	int numCells = 50;
		
	int iterations = 40;

	std::vector<bool> cells(numCells, false);
	cells[numCells / 2] = true;

	system("Color 0A");

	// display each iteration 
	for (int i = 0; i < iterations; i++)
	{
		DisplayCellsRow(cells);
	}

	// rules 
	std::array<bool, 8> rule30 = { 0,0,0,1,1,1,1,0 };
	std::array<bool, 8> rule90 = { 0,1,0,1,1,0,1,0 };
	std::array<bool, 8> rule110 = { 0,1,1,0,1,1,1,0 };
	std::array<bool, 8> rule188 = { 1,0,1,1,1,1,0,0 };


	// display each iteration 
	for (int i = 0; i < iterations; i++)
	{
		DisplayCellsRow(cells);
		cells = ProcessCells(cells, rule188);
	}
}

