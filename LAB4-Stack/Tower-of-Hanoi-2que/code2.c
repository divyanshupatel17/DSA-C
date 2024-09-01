Problem Statement

You are delving into the classical Towers of Hanoi problem, a puzzle that involves transferring a set of numbered disks from one peg to another while adhering to specific rules. To simplify the problem, each disk is represented by integers from 1 to n, where n is the total number of disks. The pegs are labeled A, B, and C.

The goal is to devise an iterative solution, utilizing a stack data structure, to efficiently move all disks from peg A to peg C. The Towers of Hanoi rules must be strictly followed:

Only one disk can be moved at a time.
Each move involves taking the top disk from one peg and placing it on top of another peg.
A larger disk cannot be placed on top of a smaller disk.

Write a program that takes the number of disks (n) as input and prints the sequence of moves required to achieve the desired configuration. Implement stack operations for initialization, push, and pop within the program. The iterative function, towerOfHanoiMovesWithStack, should employ the stack to facilitate disk movements, ensuring compliance with the Towers of Hanoi rules.

For example, if the number of disks is 3, the disks can be transferred as follows: The total number of moves made is 7.

Lightbox

Input format :
The input consists of a single integer, representing the number of disks to be moved.

Output format :
The output consists of a series of lines, each representing a move of a disk from one peg to another. Each line follows the format: "Move disk D from Source to Destination", where D is the disk number and Source and Destination are the pegs (A, B, or C).

After all moves are printed, the output includes a line stating the total number of moves made during the Tower of Hanoi operation, formatted as "Total number of moves: N", where N is the total number of moves.

Refer to the sample output for formatting specifications.

Code constraints :
1 ≤ n ≤ 8

Sample test cases :
Input 1 :
3
Output 1 :
Move disk 1 from A to C
Move disk 2 from A to B
Move disk 1 from C to B
Move disk 3 from A to C
Move disk 1 from B to A
Move disk 2 from B to C
Move disk 1 from A to C
Total number of moves: 7
Input 2 :
2
Output 2 :
Move disk 1 from A to B
Move disk 2 from A to C
Move disk 1 from B to C
Total number of moves: 3

    
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void TOH(int n,char src,char aux,char dest,int *move_cnt){
    if(n==1){
        (*move_cnt)++;
        printf("Move disk 1 from %c to %c\n",src,dest);
        return ;
    }
    TOH(n-1,src,dest,aux,move_cnt);
    (*move_cnt)++;
    printf("Move disk %d from %c to %c\n",n , src , dest);
    TOH(n-1,aux,src,dest,move_cnt);
    
}

int main() {
    int n;
    scanf("%d", &n);
    
    int move_cnt = 0;
    
    TOH(n,'A','B','C',&move_cnt);
    printf("Total number of moves: %d\n",move_cnt);
    return 0;
}
