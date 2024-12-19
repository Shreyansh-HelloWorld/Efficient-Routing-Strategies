#include <stdio.h>
#include <stdlib.h>
#include <float.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

// Function to compute the cost for one destination node with two intermediate nodes
float desNode1_MidNode2(float p[2][2]) {
    return (1 + (p[0][0] * (1 - p[1][0]) * (1 / p[0][1])) +
            ((1 - p[0][0]) * p[1][0] * (1 / p[1][1])) +
            (p[0][0] * p[1][0] * MIN(1 / p[0][1], 1 / p[1][1]))) /
           (1 - (1 - p[0][0]) * (1 - p[1][0]));
}

// Function to calculate the cost for a specific node pair
float cost_of_2_Node_path(int node1, int node2, float mtx[6][6]) {
    float probMat[2][2];
    if (node1 == 1 && node2 == 2) {
        probMat[0][0] = mtx[0][1];
        probMat[0][1] = mtx[1][4];
        probMat[1][0] = mtx[0][3];
        probMat[1][1] = mtx[3][5];
    } else if (node1 == 2 && node2 == 3) {
        probMat[0][0] = mtx[0][2];
        probMat[0][1] = mtx[2][5];
        probMat[1][0] = mtx[0][3];
        probMat[1][1] = mtx[3][5];
    }
    return desNode1_MidNode2(probMat);
}

// Function to calculate the cost of routing with intermediate nodes
float dest2_MidNode3(float mtx[6][6]) {
    float x =  ((1 - 1 / mtx[0][1]) * (1 - 1 / mtx[0][2]) * (1 - 1 / mtx[0][3]) * (1 + x)
              + ((1 - 1 / mtx[0][1]) * (1 - 1 / mtx[0][2]) * (1 / mtx[0][3])) * (1 + mtx[3][4] + cost_of_2_Node_path(1, 2, mtx))
              + ((1 - 1 / mtx[0][1]) * (1 / mtx[0][2]) * (1 - 1 / mtx[0][3])) * (1 + mtx[2][4] + MIN(mtx[2][5], mtx[3][5]))
              + ((1 / mtx[0][1]) * (1 - 1 / mtx[0][2]) * (1 - 1 / mtx[0][3])) * (1 + mtx[1][4] + cost_of_2_Node_path(2, 3, mtx))
              + ((1 / mtx[0][1]) * (1 - 1 / mtx[0][2]) * (1 / mtx[0][3])) * (1 + mtx[1][4] + mtx[3][5])
              + ((1 / mtx[0][1]) * (1 / mtx[0][2]) * (1 - 1 / mtx[0][3])) * (1 + mtx[2][5] + MIN(mtx[1][4], mtx[2][4]))
              + ((1 / mtx[0][1]) * (1 / mtx[0][2]) * (1 / mtx[0][3])) * (1 + MIN(mtx[1][4], mtx[2][4]) + MIN(mtx[2][5], mtx[3][5])));

    return x;
}

int main() {
    int n = 6; // As per the provided diagram, we have 6 nodes

    // Define the adjacency matrix for the network (nodes 0-5)
    float mtx[6][6] = {
        {0, 1.0, 2.0, 3.0, 0, 0},
        {1.0, 0, 0, 4.0, 5.0, 0},
        {2.0, 0, 0, 0, 6.0, 7.0},
        {3.0, 4.0, 0, 0, 0, 8.0},
        {0, 5.0, 6.0, 0, 0, 9.0},
        {0, 0, 7.0, 8.0, 9.0, 0}
    };

    // Print the adjacency matrix
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            printf("%.2f ", mtx[i][j]);
        }
        printf("\n");
    }

    // Calculate the minimum cost for destinations 4 and 5 with intermediate nodes
    float minCost = dest2_MidNode3(mtx);

    // Display the result
    printf("\nThe minimum cost for destinations 4 and 5 is: %.2f\n", minCost);

    return 0;
}
