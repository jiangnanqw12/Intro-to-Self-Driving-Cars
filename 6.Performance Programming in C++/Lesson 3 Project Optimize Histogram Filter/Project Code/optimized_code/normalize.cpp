#include "headers/normalize.h"
using namespace std;

// OPTIMIZATION: Pass variable by reference
vector< vector<float> > normalize(vector< vector <float> > &grid) {

  	// OPTIMIZATION: Avoid declaring and defining 				// intermediate variables that are not needed.
	float total = 0.0;
	int i;
	int j;
	
	
	for (i = 0; i < grid.size(); i++)
	{
		
		for (j=0; j< grid[0].size(); j++)
		{
			
			total += grid[i][j];
		}
	}

	vector< vector<float> > newGrid;

	for (i = 0; i < grid.size(); i++) {
		vector<float> row = grid[i];
		//newRow.clear();
		for (j=0; j< grid[0].size(); j++) {
			//float oldProb = row[j];
			//float newProb = oldProb / total;
			grid[i][j]=(grid[i][j]/total);
		}
		
	}

	return grid;
}
