/*You are provided a matrix of size N*N with source position at (0,0) and destination at (N- 1,N-1) in a 2D array. Some of the positions in the array are marked as 0 which are blocked cells, rest being marked 1. A path is a connected sequence of elements from (0,0) to (N-1,N-1) which consists of 1. A sequence of 1s in the 2D array is connected if every 1 in the sequence is adjacent (the above or left neighbour) to the next 1 in the sequence.
Code by - Daksh Verma 
Roll No - 231210036*/


#include <stdio.h>

#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"

void inputMatrix(int N, int matrix[N][N]) {
    printf("Enter the maze matrix %dx%d (0 for blocked cell, 1 for unblocked cell):\n", N, N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

int isSafe(int row, int col, int N, int matrix[N][N], int visited[N][N]) {
    return (row >= 0 && row < N && col >= 0 && col < N && matrix[row][col] == 1 && !visited[row][col]);
}

int findPathUtil(int row, int col, int N, int matrix[N][N], int visited[N][N]) {
    if (row == N - 1 && col == N - 1) {
        visited[row][col] = 1;
        return 1;
    }

    if (isSafe(row, col, N, matrix, visited)) {
        visited[row][col] = 1;

        if (findPathUtil(row, col + 1, N, matrix, visited))
            return 1;
        if (findPathUtil(row + 1, col, N, matrix, visited))
            return 1;
        if (findPathUtil(row, col - 1, N, matrix, visited))
            return 1;
        if (findPathUtil(row - 1, col, N, matrix, visited))
            return 1;

        visited[row][col] = 0;
        return 0;
    }
    return 0;
}

int findPath(int N, int matrix[N][N]) {
    int visited[N][N];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            visited[i][j] = 0;
        }
    }

    if (findPathUtil(0, 0, N, matrix, visited) == 0) {
        printf("Path does not exist!\n");
        return 0;
    }

    printf("Path exists! Displaying the path:\n");

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (visited[i][j] == 1) {
                printf(BOLD GREEN "%d " RESET, matrix[i][j]);
            } else {
                printf(RED"%d "RESET, matrix[i][j]);
            }
        }
        printf("\n");
    }
    return 1;
}

int main() {
    int N;
    printf("Enter the size of the maze: ");
    scanf("%d", &N);

    int matrix[N][N];

    inputMatrix(N, matrix);

    findPath(N, matrix);

    return 0;
}

