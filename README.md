# C-_array_rotate
Reads in an array and rotates it

I wrote this a ways back, pretty early on in my coding journey (you can tell if you read the code). It was super cool to get it working though. I'll include here my write up so you can see some of my thought process at the time.

Rogue
CS 121
Program 1
September 26, 2020

**Program Design**
1. A function will open the file, read in the number of rows and return this number to main.
2. A function will open the file, read in the number of columns and return this number to main.
3. In main, create a dynamically allocated 2d array using the number of columns and rows read in from the file.
4. Pass this array into a function that will skip the first line and then read in the the array (image) into the
function, then return this function to main.
5. A function will then display this array (printImage function), using two for loops to iterate through rows and
columns.
6. Pass the array into a new function, this function creates a new array of the same size, and then copies the
numbers from the original array into the new array, but transforming as it does so that the new array is rotated
clockwise 90 degrees. Return the new array to main, display this new array using printImage function, then
release memory of rotated array.
7. Pass the array into a new function, this function creates a new array of the same size, and then copies the
numbers from the original array into the new array, but transforming as it does so that the new array is rotated
counter-clockwise 90 degrees. Return the new array to main, display this new array using printImage function,
then release memory of rotated array
8. Release memory of original array, display signature, and exit the program
