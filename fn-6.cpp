// By sharqawycs
// 23p0360@eng.asu.edu.eg
// Please, if you have another solution, share it with us.

#include <iostream>
using namespace std;

// Function to check if the matrix is a magic square
bool is_magic_square(int **&matrix, int size)
{
  // Calculate the sum of the first row
  int first_row_sum = 0;
  for (int j = 0; j < size; ++j)
  {
    first_row_sum += matrix[0][j];
  }

  // Check the sum of each row
  for (int i = 1; i < size; ++i)
  {
    int row_sum = 0;
    for (int j = 0; j < size; ++j)
    {
      row_sum += matrix[i][j];
    }
    if (row_sum != first_row_sum)
    {
      return false;
    }
  }

  // Check the sum of each column
  for (int j = 0; j < size; ++j)
  {
    int col_sum = 0;
    for (int i = 0; i < size; ++i)
    {
      col_sum += matrix[i][j];
    }
    if (col_sum != first_row_sum)
    {
      return false;
    }
  }

  // Check the sum of the main diagonal
  int main_diag_sum = 0;
  for (int i = 0; i < size; ++i)
  {
    main_diag_sum += matrix[i][i];
  }
  if (main_diag_sum != first_row_sum)
  {
    return false;
  }

  // Check the sum of the secondary diagonal
  int sec_diag_sum = 0;
  for (int i = 0; i < size; ++i)
  {
    sec_diag_sum += matrix[i][size - 1 - i];
  }
  if (sec_diag_sum != first_row_sum)
  {
    return false;
  }

  // If all checks pass, it's a magic square
  return true;
}

// Function to print a matrix
void print_matrix(int **matrix, int size)
{
  for (int i = 0; i < size; ++i)
  {
    for (int j = 0; j < size; ++j)
    {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}

int main()
{
  // Input matrix size
  int size;
  cout << "Enter the size of the square matrix: ";
  cin >> size;

  // Dynamically allocate memory for the matrix
  int **matrix = new int *[size];
  for (int i = 0; i < size; ++i)
  {
    matrix[i] = new int[size];
  }

  // Input matrix elements
  cout << "Enter the square matrix elements row:" << endl;
  for (int i = 0; i < size; ++i)
  {
    for (int j = 0; j < size; ++j)
    {
      cin >> matrix[i][j];
    }
  }

  // Check if it's a magic square
  if (is_magic_square(matrix, size))
  {
    cout << "\nThe matrix is a magic square." << endl;
  }
  else
  {
    cout << "\nThe matrix is not a magic square." << endl;
  }

  // Free memory for the matrix
  for (int i = 0; i < size; ++i)
  {
    delete[] matrix[i];
  }
  delete[] matrix;

  return 0;
}
