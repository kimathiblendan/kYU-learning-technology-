#include <stdio.h>

int main() {
    // ------------------ 1D ARRAY: Weekly Revenue Tracker ------------------
    float revenue[7], totalRevenue = 0, averageRevenue;
    const char *days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

    printf("=== WEEKLY REVENUE TRACKER ===\n");
for (int i = 0; i < 7; i++); {
        printf("Enter revenue for %s: ", days[i]);
        scanf("%f", &revenue[i]);
        totalRevenue += revenue[i];
    }

    averageRevenue = totalRevenue / 7.0;

    printf("\n--- Weekly Revenue Report ---\n");
    for (int i = 0; i < 7; i++) {
        printf("%s: %.2f\n", days[i], revenue[i]);
    }
    printf("Total Weekly Revenue: %.2f\n", totalRevenue);
    printf("Average Daily Revenue: %.2f\n\n", averageRevenue);

    // ------------------ 2D ARRAY: Room Occupancy (One Branch) ------------------
    int occupancy[5][10];
    int occupied, vacant;

    printf("=== ROOM OCCUPANCY (ONE BRANCH) ===\n");

    // Simulate or input occupancy data
    printf("Enter room occupancy data (1 = occupied, 0 = vacant):\n");
    for (int i = 0; i < 5; i++) {
        printf("\nFloor %d:\n", i + 1);
        for (int j = 0; j < 10; j++) {
            printf("Room %d: ", j + 1);
            scanf("%d", &occupancy[i][j]);
        }
    }

    printf("\n--- Occupancy Report per Floor ---\n");
    for (int i = 0; i < 5; i++) {
        occupied = vacant = 0;
        for (int j = 0; j < 10; j++) {
            if (occupancy[i][j] == 1)
                occupied++;
            else
                vacant++;
        }
        printf("Floor %d - Occupied: %d, Vacant: %d\n", i + 1, occupied, vacant);
    }

    // ------------------ 3D ARRAY: Multiple Branches ------------------
    int chain[3][5][10];
    int totalOccupied = 0, totalVacant = 0;

    printf("\n=== MULTI-BRANCH OCCUPANCY SIMULATION ===\n");

    // Simulate occupancy for simplicity (random or manual input)
    for (int b = 0; b < 3; b++) {
        printf("\n--- Branch %d ---\n", b + 1);
        for (int f = 0; f < 5; f++) {
            for (int r = 0; r < 10; r++) {
                printf("Branch %d, Floor %d, Room %d (1=occupied, 0=vacant): ", b + 1, f + 1, r + 1);
                scanf("%d", &chain[b][f][r]);
            }
        }
    }

    printf("\n--- Total Occupancy Report for All Branches ---\n");
    for (int b = 0; b < 3; b++) {
        totalOccupied = totalVacant = 0;
        for (int f = 0; f < 5; f++) {
            for (int r = 0; r < 10; r++) {
                if (chain[b][f][r] == 1)
                    totalOccupied++;
                else
                    totalVacant++;
            }
        }
        printf("Branch %d - Occupied Rooms: %d, Vacant Rooms: %d\n", b + 1, totalOccupied, totalVacant);
    }

    printf("\n=== END OF HOTEL MANAGEMENT REPORT ===\n");
    return 0;
}