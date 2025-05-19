#include <bits/stdc++.h>
using namespace std;

// Function to print a matrix
void printMatrix(const vector<vector<int>> &matrix, const string &label)
{
	cout << label << " =>" << endl;
	for (const auto &row : matrix)
	{
		for (const auto &val : row)
			cout << setw(10) << val;
		cout << endl;
	}
	cout << endl;
}

// Function to add two matrices and return the result
vector<vector<int>> addMatrix(const vector<vector<int>> &A, const vector<vector<int>> &B)
{
	int n = A.size();
	vector<vector<int>> result(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			result[i][j] = A[i][j] + B[i][j];
	return result;
}

// Function to split a matrix into quadrants
void splitMatrix(const vector<vector<int>> &matrix,
				 vector<vector<int>> &topLeft,
				 vector<vector<int>> &topRight,
				 vector<vector<int>> &bottomLeft,
				 vector<vector<int>> &bottomRight)
{
	int n = matrix.size();
	int mid = n / 2;
	for (int i = 0; i < mid; i++)
	{
		vector<int> rowLeft, rowRight;
		vector<int> rowLeftBottom, rowRightBottom;
		for (int j = 0; j < mid; j++)
		{
			rowLeft.push_back(matrix[i][j]);
			rowRight.push_back(matrix[i][j + mid]);
			rowLeftBottom.push_back(matrix[i + mid][j]);
			rowRightBottom.push_back(matrix[i + mid][j + mid]);
		}
		topLeft.push_back(rowLeft);
		topRight.push_back(rowRight);
		bottomLeft.push_back(rowLeftBottom);
		bottomRight.push_back(rowRightBottom);
	}
}

// Function to combine four quadrants into a single matrix
vector<vector<int>> combineMatrix(const vector<vector<int>> &topLeft,
								  const vector<vector<int>> &topRight,
								  const vector<vector<int>> &bottomLeft,
								  const vector<vector<int>> &bottomRight)
{
	int mid = topLeft.size();
	int n = mid * 2;
	vector<vector<int>> result(n, vector<int>(n, 0));
	for (int i = 0; i < mid; i++)
	{
		for (int j = 0; j < mid; j++)
		{
			result[i][j] = topLeft[i][j];
			result[i][j + mid] = topRight[i][j];
			result[i + mid][j] = bottomLeft[i][j];
			result[i + mid][j + mid] = bottomRight[i][j];
		}
	}
	return result;
}

// Recursive function to multiply two matrices using divide and conquer
vector<vector<int>> recursiveMultiply(const vector<vector<int>> &A, const vector<vector<int>> &B)
{
	int n = A.size();

	// Base case: 1x1 matrix multiplication
	if (n == 1)
	{
		return {{A[0][0] * B[0][0]}};
	}

	// Split matrices into quadrants
	vector<vector<int>> a00, a01, a10, a11;
	vector<vector<int>> b00, b01, b10, b11;

	splitMatrix(A, a00, a01, a10, a11);
	splitMatrix(B, b00, b01, b10, b11);

	// Recursively calculate submatrices of the result
	vector<vector<int>> c00 = addMatrix(recursiveMultiply(a00, b00), recursiveMultiply(a01, b10));
	vector<vector<int>> c01 = addMatrix(recursiveMultiply(a00, b01), recursiveMultiply(a01, b11));
	vector<vector<int>> c10 = addMatrix(recursiveMultiply(a10, b00), recursiveMultiply(a11, b10));
	vector<vector<int>> c11 = addMatrix(recursiveMultiply(a10, b01), recursiveMultiply(a11, b11));

	// Combine the results into a single matrix
	return combineMatrix(c00, c01, c10, c11);
}

int main()
{
	vector<vector<int>> matrixA = {
		{1, 1, 1, 1},
		{2, 2, 2, 2},
		{3, 3, 3, 3},
		{2, 2, 2, 2}};

	vector<vector<int>> matrixB = {
		{1, 1, 1, 1},
		{2, 2, 2, 2},
		{3, 3, 3, 3},
		{2, 2, 2, 2}};

	printMatrix(matrixA, "Matrix A");
	printMatrix(matrixB, "Matrix B");

	vector<vector<int>> result = recursiveMultiply(matrixA, matrixB);

	printMatrix(result, "Result Matrix");

	return 0;
}
