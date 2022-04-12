/* Rogue
* CS 121 Program 1
* September 26, 2020
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

int readRows();
int readCols();
int** readImage(int**, int, int);
void printImage(int**, int, int);
int** rotateRight(int** image, int rows, int cols);
int** rotateLeft(int** image, int rows, int cols);

int main()
{
	cout << "rogue" << '\n' << "CS 121" << '\n' << "Program 1" << '\n' << "September 26, 2020" << '\n' << endl; //header
	const int rows = readRows();
	const int cols = readCols();
  //test to make sure functions read in correct number of rows/cols
	cout << "Row: " << rows << "  Cols: " << cols << '\n' <<endl; 
	//This creates a dynamic 2d array using the number of rows/cols we read in from the file
  int** image = new int* [rows]; 
	for (int i = 0; i < rows; ++i)
		image[i] = new int[cols];

	readImage(image, rows, cols);
	cout << "     Original Image: " << '\n' << endl;
	printImage(image, rows, cols); //Print the original array read in from the file
	cout << '\n' << '\n' << endl;

	int** right = rotateRight(image, rows, cols); //Rotate original array 90 degrees clockwise, display rotated array, release memory of new array
	cout << "     Rotated Clockwise: " << '\n' << endl;
	printImage(right, rows, cols);
	cout << '\n' << '\n' << endl;
	delete right;

  //Rotate original array 90 degrees counter-clockwise, display rotated array, release memory of new array
	int** left = rotateLeft(image, rows, cols); 
	cout << "     Rotated Counter-Clockwise: " << '\n' << endl;
	printImage(left, rows, cols);
	cout << '\n' << '\n' << endl;
	delete left;
  
  //release memory of original array
	for (int i = 0; i < rows; ++i) { 
		delete[] image[i];
	} 
	delete[] image;
	cout << '\n' << '\n' << "Program Designed by rogue" << endl;
	cout << "September 26, 2020" << '\n' << endl;
	return 0;
}
int readRows() {
	ifstream fIn;
	ifstream get;
	int rows = 0;
	fIn.open("test1.dat", ios::in);
	fIn >> rows;
	return rows;
	fIn.close();
}
int readCols
() {
	ifstream fIn;
	ifstream get;
	int cols = 0;
	int rows = 0;
	fIn.open("test1.dat", ios::in);
  //need to skip the first number of the file and read the second
	fIn >> cols;
	fIn >> rows; 
	return cols;
	fIn.close();
}
int** readImage(int** image, int rows, int cols) {
	ifstream fIn;
	ifstream get;
	int x;
	fIn.open("test1.dat", ios::in);
  
  //skip first two numbers, which will be number of rows/cols, not the image itself
	fIn >> x; 
	fIn >> x;
	while (fIn >> x)
	{
		int n;
		for (int i = 0; i < rows; i++) {
			for (int z = 0; z < cols; z++) {
				fIn >> n;
				image[i][z] = n;
			}
		}
	}
	return image;
	}
void printImage(int** image, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int z = 0; z < cols; z++) {
      //If statements add a space for double digit and a double space for single digit numbers to maintain spacing when displaying array
			cout << image[i][z] << "  ";
			if (image[i][z] <= 9) { 
				cout << "  ";
			}
			if (image[i][z] < 100 && image[i][z] > 9) {
				cout << " ";
			}
		}
		cout << endl;
	}
	cout << endl;
}
int** rotateRight(int** image, int rows, int cols) {

//create a new array that will become the rotated image
	int** imgRight = new int* [rows]; 
	for (int i = 0; i < rows; ++i)
		imgRight[i] = new int[cols];

		for (int i = 0; i < cols; i++) {
			for (int z = 0; z < rows; z++) {
      //copy numbers from the original array into their new position in the new, rotated array
				imgRight[i][z] = image[rows - (1 + z)][i]; 
			}
		}
		return imgRight;
}
int** rotateLeft(int** image, int rows, int cols) {

//create a new array that will become the rotated image
	int** imgLeft = new int* [rows]; 
	for (int i = 0; i < rows; ++i)
		imgLeft[i] = new int[cols];

	for (int i = 0; i < cols; i++) {
		for (int z = 0; z < rows; z++) {
     //copy numbers from the original array into their new position in the new, rotated array
			imgLeft[i][z] = image[z][cols-(1+i)];
		}
	}
	return imgLeft;
} 
