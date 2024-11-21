#include <stdio.h>

// Recursive function to solve Tower of Hanoi
void hanoi(int n, char from, char to, char aux) {
    // Base case: If there is only one disk, move it directly
    if (n == 1) {
        printf("Move Disk from %c to %c\n", from, to);
        return;
    }
    
    // Move top n-1 disks from 'from' to 'aux', using 'to' as auxiliary
    hanoi(n - 1, from, aux, to);
    
    // Move the nth disk from 'from' to 'to'
    printf("Move Disk from %c to %c\n", from, to);
    
    // Move the n-1 disks from 'aux' to 'to', using 'from' as auxiliary
    hanoi(n - 1, aux, to, from);
}

int main() {
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);
    
    // Start the Tower of Hanoi process
    hanoi(n, 'A', 'C', 'B'); // A = source, C = destination, B = auxiliary
    
    return 0;
}