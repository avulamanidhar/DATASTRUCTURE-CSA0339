#include <stdio.h>
#include <stdlib.h>

void LOOK(int queue[], int head, int size) {
    int total_moves = 0;
    int direction = 1; // 1 for moving towards higher track numbers, -1 for moving towards lower track numbers

    // Sort the queue in ascending order
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (queue[i] > queue[j]) {
                int temp = queue[i];
                queue[i] = queue[j];
                queue[j] = temp;
            }
        }
    }

    int current_track = head;
    int index;

    // Find the index of the current head position in the sorted queue
    for (index = 0; index < size; index++) {
        if (queue[index] == head) {
            break;
        }
    }

    printf("Disk head movement sequence:\n%d", head);

    // Traverse the sorted queue based on the direction
    if (direction == 1) {
        for (int i = index + 1; i < size; i++) {
            printf(" -> %d", queue[i]);
            total_moves += abs(queue[i] - current_track);
            current_track = queue[i];
        }
        for (int i = index - 1; i >= 0; i--) {
            printf(" -> %d", queue[i]);
            total_moves += abs(queue[i] - current_track);
            current_track = queue[i];
        }
    } else {
        for (int i = index - 1; i >= 0; i--) {
            printf(" -> %d", queue[i]);
            total_moves += abs(queue[i] - current_track);
            current_track = queue[i];
        }
        for (int i = index + 1; i < size; i++) {
            printf(" -> %d", queue[i]);
            total_moves += abs(queue[i] - current_track);
            current_track = queue[i];
        }
    }

    printf("\nTotal head movement: %d\n", total_moves);
}

int main() {
    int queue[] = {98, 183, 37, 122, 14, 124, 65, 67};
    int size = sizeof(queue) / sizeof(queue[0]);
    int head = 53;

    LOOK(queue, head, size);

    return 0;
}
