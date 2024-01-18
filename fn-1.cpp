// By sharqawycs
// 23p0360@eng.asu.edu.eg
// Find the saddle point in a matrix. A saddle point is an element that is both the minimum in its column and maximum in its row.
#include <iostream>
using namespace std;

void findSaddlePoint(int **matrix, int rows, int cols, int &saddle_row, int &saddle_col, int &saddle_element)
{
  saddle_row = -1;
  saddle_col = -1;
  saddle_element = 0; // Any value, Do not care :)

  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      // Find the samllest element in the column
      int min_in_col = matrix[0][j];
      for (int k = 1; k < rows; ++k)
      {
        min_in_col = min(min_in_col, matrix[k][j]);
      }

      // Find the largest element in the current row
      int min_in_row = matrix[i][0];
      for (int k = 1; k < cols; ++k)
      {
        min_in_row = max(min_in_row, matrix[i][k]);
      }

      // Check if the smallest in column is equal to largest in row or Not
      if (matrix[i][j] == min_in_col && matrix[i][j] == min_in_row)
      {
        saddle_row = i;                // Store the row index
        saddle_col = j;                // Store the column index
        saddle_element = matrix[i][j]; // Store the value of the saddle point
        return;                        // To exit the loop and the entire function
      }
    }
  }
}

int main()
{
  int rows, cols;
  cout << "Enter rows: ";
  cin >> rows;
  cout << "Enter columns: ";
  cin >> cols;

  // Dynamic array declaration
  int **matrix = new int *[rows];
  for (int i = 0; i < rows; ++i)
  {
    matrix[i] = new int[cols];
  }

  cout << "Enter matrix elements:\n";
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      cin >> matrix[i][j];
    }
  }

  int saddle_row, saddle_col, saddle_element;
  findSaddlePoint(matrix, rows, cols, saddle_row, saddle_col, saddle_element);

  if (saddle_row != -1) // if saddle_row = -1 (The intlization value in the function),
                        // that means that the value of saddle_row have not changed
                        // so, there is no Saddle point found
  {
    cout << "The Saddle point is: \"" << saddle_element << "\" found it at: (" << saddle_row << ", " << saddle_col << ") \n";
  }
  else
  {
    cout << "No saddle point found :(.\n";
  }

  // Delete the dynamic array (Memory Deallocation)
  for (int i = 0; i < rows; ++i)
  {
    delete[] matrix[i];
  }
  delete[] matrix;

  return 0;
}
