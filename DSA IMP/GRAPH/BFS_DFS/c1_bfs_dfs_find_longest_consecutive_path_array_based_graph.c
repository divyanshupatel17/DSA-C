#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5  // Maximum size of the matrix
#define QUEUE_SIZE (MAX * MAX)  // Maximum size for the BFS queue

// Directions arrays for the 8 possible moves (up, down, left, right, and diagonals)
int rowDir[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int colDir[] = {-1, 0, 1, -1, 1, -1, 0, 1};
// (-1, -1): Up-Left diagonal
// (-1,  0): Up
// (-1,  1): Up-Right diagonal
// ( 0, -1): Left
// ( 0,  1): Right
// ( 1, -1): Down-Left diagonal
// ( 1,  0): Down
// ( 1,  1): Down-Right diagonal


// Utility function to check if the given coordinates are within matrix bounds
bool isValid(int x, int y, int n, int m) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

// Depth-First Search function to find the longest consecutive path from a given character
int findLongestPathDFS(char mat[MAX][MAX], int x, int y, char start, int n, int m) {
    int maxLen = 1;  // At least the start character itself

    // Explore all 8 possible directions
    for (int i = 0; i < 8; i++) {
        int newX = x + rowDir[i];
        int newY = y + colDir[i];

        // Check if we can move to this new cell and it's the next consecutive character
        if (isValid(newX, newY, n, m) && mat[newX][newY] == start + 1) {
            int pathLen = 1 + findLongestPathDFS(mat, newX, newY, start + 1, n, m);
            if (pathLen > maxLen) {
                maxLen = pathLen;  // Update maximum length found
            }
        }
    }

    return maxLen;  // Return the longest path length found from this position
}

// Function to find the longest path using DFS starting from a given character
int longestPathDFS(char mat[MAX][MAX], int n, int m, char start) {
    int longest = 0;  // Initialize the longest path length

    // Traverse the matrix to find occurrences of the starting character
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == start) {
                // Start DFS from this cell
                int pathLen = findLongestPathDFS(mat, i, j, start, n, m);
                if (pathLen > longest) {
                    longest = pathLen;  // Update the longest path found
                }
            }
        }
    }

    return longest;  // Return the longest path found
}

// Function to find the longest path using BFS starting from a given character
int longestPathBFS(char mat[MAX][MAX], int n, int m, char start) {
    int longest = 0;  // Initialize the longest path length

    // Arrays for BFS
    int queueX[QUEUE_SIZE];  // Queue for x-coordinates
    int queueY[QUEUE_SIZE];  // Queue for y-coordinates
    int queueLength[QUEUE_SIZE];  // Queue for path lengths
    int front, rear;  // Queue pointers

    // Perform BFS for each occurrence of the starting character
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == start) {
                // Initialize the queue
                front = 0;
                rear = 0;

                // Enqueue the starting position
                queueX[rear] = i;  // Row index
                queueY[rear] = j;  // Column index
                queueLength[rear++] = 1;  // Starting length is 1

                // Perform BFS
                while (front < rear) {
                    int currentX = queueX[front];  // Dequeue the front x-coordinate
                    int currentY = queueY[front];  // Dequeue the front y-coordinate
                    int currentLength = queueLength[front++];  // Dequeue the path length

                    // Explore all 8 possible directions
                    for (int d = 0; d < 8; d++) {
                        int newX = currentX + rowDir[d];
                        int newY = currentY + colDir[d];

                        // Check if we can move to this new cell and it's the next consecutive character
                        if (isValid(newX, newY, n, m) && mat[newX][newY] == start + currentLength) {
                            queueX[rear] = newX;  // Enqueue new position x-coordinate
                            queueY[rear] = newY;  // Enqueue new position y-coordinate
                            queueLength[rear++] = currentLength + 1;  // Enqueue new path length

                            // Update the longest length found
                            if (currentLength + 1 > longest) {
                                longest = currentLength + 1;
                            }
                        }
                    }
                }
            }
        }
    }

    return longest;  // Return the longest path found
}

int main() {
    int n, m;
    printf("Enter the dimensions of the matrix (rows and columns): ");
    scanf("%d %d", &n, &m);

    // Ensure that the matrix size does not exceed MAX
    if (n > MAX || m > MAX) {
        printf("Matrix dimensions exceed the maximum allowed size of %d x %d.\n", MAX, MAX);
        return 1;  // Exit if dimensions are invalid
    }

    char mat[MAX][MAX];  // Declare the character matrix
    printf("Enter the character matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %c", &mat[i][j]);  // Read characters into the matrix
        }
    }

    char startChar;
    printf("Enter the starting character: ");
    scanf(" %c", &startChar);

    // Finding the longest path using DFS
    int resultDFS = longestPathDFS(mat, n, m, startChar);
    printf("DFS: The length of the longest path with consecutive characters starting from character '%c' is %d\n", startChar, resultDFS);

    // Finding the longest path using BFS
    int resultBFS = longestPathBFS(mat, n, m, startChar);
    printf("BFS: The length of the longest path with consecutive characters starting from character '%c' is %d\n", startChar, resultBFS);

    return 0;  // Exit the program successfully
}

/*
Sample test cases :
Input 1 :
5
5
d e h x b
a o g p e
d d c f d
e b e a s
c d y e n
c
Output 1 :
The length of the longest path with consecutive characters starting from character c is 6
Input 2 :
5
5
d e h x b
a o g p e
d d c f d
e b e a s
c d y e n
b
Output 2 :
The length of the longest path with consecutive characters starting from character b is 7
*/