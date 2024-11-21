#include <stdio.h>

void hanoi(int n, char from, char to, char aux) {
    int totalMoves = (1 << n) - 1; // Total moves = 2^n - 1
    for (int i = 1; i <= totalMoves; i++) {
        char moveFrom, moveTo;
        
        // Determine the source and destination pegs for the current move
        if (i % 3 == 1) {
            moveFrom = from; 
            moveTo = to;
        } else if (i % 3 == 2) {
            moveFrom = from; 
            moveTo = aux;
        } else {
            moveFrom = aux; 
            moveTo = to;
        }

        // If n is even, swap the destination pegs for the first two moves
        if (n % 2 == 0) {
            char temp = moveTo;
            moveTo = moveFrom;
            moveFrom = temp;
        }

        printf("Move %d: Move Disk from %c to %c\n", i, moveFrom, moveTo);
    }
}

int main() {
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);
    hanoi(n, 'A', 'C', 'B'); // A = source, C = destination, B = auxiliary
    return 0;
}
