Problem Statement

You are working as a software developer and need to calculate the number of moves required to solve the Tower of Hanoi puzzle for a given number of disks. The Tower of Hanoi puzzle involves moving disks from one rod to another with the constraints that only one disk can be moved at a time, and a larger disk cannot be placed on top of a smaller disk. 

Implement a program that takes an integer input n representing the number of disks and outputs the minimum number of moves required to solve the puzzle.

Input format :
The input consists of an integer denoting the number of disks n.

Output format :
The output displays the minimum number of moves required to solve the Tower of Hanoi problem for n disks.

Refer to the sample output for formatting specifications.

Code constraints :
1 ≤ n ≤ 8

Sample test cases :
Input 1 :
2
Output 1 :
3
Input 2 :
4
Output 2 :
15

#include <stdio.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);

    int moves = pow(2, n) - 1;
    printf("%d\n", moves);

    return 0;
}
