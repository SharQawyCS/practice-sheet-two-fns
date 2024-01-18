// By sharqawycs
// 23p0360@eng.asu.edu.eg
// Please, if you have another solution, share it because this solution is really complex :(

#include <iostream>
using namespace std;

// Function to perform matrix compression
void compressMatrix(int **&matrix, int &rows, int &cols)
{
  // Arrays to store that the row  and col will be removed or not (boolean)
  bool removed_row[rows];
  bool removed_col[cols];

  // Identify rows and columns containing zeros
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      if (matrix[i][j] == 0)
      {
        removed_row[i] = true;
        removed_col[j] = true;
      }
    }
  }

  // Declare a new compressed matrix
  int new_row = 0;
  int new_col = 0;

  for (int i = 0; i < rows; ++i)
  {
    // Skip removed rows and do not add it
    if (!removed_row[i])
    {
      new_row++; // Do not creat a new row for the removed row
    }
  }

  for (int j = 0; j < cols; ++j)
  {
    // Skip removed columns and do not add it
    if (!removed_col[j])
    {
      new_col++; // Do not creat a new col for the removed row
    }
  }

  // Create a new compressed matrix using dynamic arrays
  int **compressed_matrix = new int *[new_row];
  for (int i = 0; i < new_row; ++i)
  {
    compressed_matrix[i] = new int[new_col]();
  }

  // Fill the compressed matrix with non-removed values
  int newRow = 0;
  int newCol = 0;

  for (int i = 0; i < rows; ++i)
  {
    // Skip rows to be removed
    if (!removed_row[i])
    {
      for (int j = 0; j < cols; ++j)
      {
        // Skip columns to be removed
        if (!removed_col[j])
        {
          compressed_matrix[newRow][newCol++] = matrix[i][j];
        }
      }
      // Move to the next row in the compressed matrix
      newRow++;
      newCol = 0;
    }
  }

  // Free memory for the original matrix
  for (int i = 0; i < rows; ++i)
  {
    delete[] matrix[i];
  }
  delete[] matrix;

  // Update the original matrix pointer with the compressed matrix
  matrix = compressed_matrix;

  // Update the rows and cols variables
  rows = new_row;
  cols = new_col;
}

// Function to print a matrix
void printMatrix(int **matrix, int rows, int cols)
{
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}

int main()
{
  // Input matrix dimensions
  int rows, cols;
  cout << "Enter the number of rows: ";
  cin >> rows;
  cout << "Enter the number of columns: ";
  cin >> cols;

  // Dynamically allocate memory for the matrix
  int **matrix = new int *[rows];
  for (int i = 0; i < rows; ++i)
  {
    matrix[i] = new int[cols];
  }

  // Input matrix elements
  cout << "Enter the matrix elements:" << endl;
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      cin >> matrix[i][j];
    }
  }

  cout << "\nOriginal Matrix:" << endl;
  printMatrix(matrix, rows, cols);

  // Perform matrix compression
  compressMatrix(matrix, rows, cols);

  cout << "\nCompressed Matrix:" << endl;
  printMatrix(matrix, rows, cols);

  // Free memory for the compressed matrix
  for (int i = 0; i < rows; ++i)
  {
    delete[] matrix[i];
  }
  delete[] matrix;

  return 0;
}
