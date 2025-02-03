#include <iostream>
#include <vector>
#include <iomanip> // For std::setprecision
#include <limits>  // For input validation
#include<bits/stdc++.h>
using namespace std;

// Function to compute the cost for one destination node with two intermediate nodes
float hop_2_dest_1_route_2(vector<float> &p) {
    float x = 0.00;
    x = (1 - 1 /p[0] - 1 /p[1] + 1/(p[0] * p[1])
        +((1 - 1/p[0]) * (1/p[1]) *(1 + p[3]))
        +((1/p[0]) * (1 - 1/p[1]) * (1 + p[2]))
        +((1/p[0]) * (1/p[1]) * (1 + min(p[2],p[3]))))/(1 /p[0] + 1/p[1] - 1/(p[0] * p[1]));
    //cout << x << endl;
    return x;
}

float dest2(vector<float> &p){                       
    float x = 0.00;
    x = (1 - 1 /p[0] - 1 /p[1] + 1/(p[0] * p[1])
        +((1 - 1/p[0]) * (1/p[1]) * (1 + p[0]))
        +((1/p[0]) * (1 - 1/p[1]) * (1 + p[1]))
        +((1/p[0]) * (1/p[1]) * (1))) / (1 /p[0] + 1/p[1] - 1/(p[0] * p[1]));
    //cout << x << endl;
    return x;
}
/*
    For Map 
               1 --- 4
              |     |    
             0 --- 2
              \     \
               3 --- 5

*/
float dest2_MidNode3(vector<vector<float>> &m){
    float x = 0.0;

    vector<float> cost0_4 = {m[0][1],m[0][2],m[1][4],m[2][4]};
    vector<float> cost0_5 = {m[0][2],m[0][3],m[2][5],m[3][5]};
    vector<float> cost2_45 = {{m[2][4],m[2][5]}};
    x = (1 - 1 / m[0][3] - 1 / m[0][2] + 1 / ( m[0][2] * m[0][3]) - 1 / m[0][1] + 1 / (m[0][1] * m[0][3]) + 1 / (m[0][1] * m[0][2]) - 1 / (m[0][1] * m[0][2] * m[0][3])
        +((1 - 1/m[0][1]) * (1 - 1/m[0][2]) * (1/m[0][3]) * (1 + m[3][5] + hop_2_dest_1_route_2(cost0_4)))
        +((1 - 1/m[0][1]) * (1/m[0][2]) * (1 - 1/m[0][3]) * (1 + m[3][5] + dest2(cost2_45)))
        +((1/m[0][1])  * (1 - 1/m[0][2]) * (1 - 1/m[0][3]) * (1 + m[1][4] + hop_2_dest_1_route_2(cost0_5)))
        +((1 - 1/m[0][1]) * (1/m[0][2]) * (1/m[0][3]) * (1+min(dest2(cost2_45),min(m[2][4],hop_2_dest_1_route_2(cost0_4) + min(m[2][5],m[3][5])))))
        +((1/m[0][1]) * (1/m[0][2]) * (1 - 1/m[0][3]) * (1+min(dest2(cost2_45),min(m[2][5],hop_2_dest_1_route_2(cost0_5) + min(m[1][4],m[2][4])))))
        +((1/m[0][1]) * (1 - 1/m[0][2]) * (1/m[0][3]) * (1 + min(m[1][4],hop_2_dest_1_route_2(cost0_4)) + min(m[3][5],hop_2_dest_1_route_2(cost0_5))))
        +((1/m[0][1]) * (1/m[0][2]) * (1/m[0][3]) * (1 + min(min(m[1][4] + m[3][5],min(m[1][4]+m[2][5],m[2][4] + m[3][5])), (dest2(cost2_45)))))) 
        / (1 / m[0][3] + 1 / m[0][2] - 1/(m[0][3]* m[0][2]) + 1 / m[0][1] - 1 /(m[0][1] * m[0][3]) - 1 /(m[0][1] * m[0][2]) + 1/(m[0][1] * m[0][2] * m[0][3]));
        return x;
}


int main() {
    int n;

    // Prompt the user for the number of nodes
    std::cout << "Enter number of nodes: ";
    std::cin >> n;

    // Exit the program if the number of nodes is less than 1
    if (n < 1) {
        std::cout << "Invalid number of nodes.\n";
        return 0;
    }

    // Declare and initialize the adjacency matrix using a 2D vector
    std::vector<std::vector<float>> mtx(n, std::vector<float>(n, 0));

    // Loop to input edges and their weights (ETX values)
    while (true) {
        int from, to;
        float etx;
        // Input the starting node of the edge
        std::cout << "Enter the nodes to connect (0 to " << n - 1 << ") or (-1 to exit):\n";
        std::cout << "From node: ";
        std::cin >> from;

        // Exit if the user enters -1
        if (from == -1) break;

        // Input the ending node of the edge
        std::cout << "To node: ";
        std::cin >> to;
        if (to == -1) break;

        // Validate the node numbers
        if (from >= n || to >= n || from < 0 || to < 0) {
            std::cout << "Invalid node numbers. Try again.\n";
            continue;
        }

        // Input the ETX value
        std::cout << "Enter the ETX value (> 0): ";
        std::cin >> etx;

        // Validate the ETX value
        if (etx <= 0) {
            std::cout << "Invalid ETX value. Must be greater than 0.\n";
            continue;
        }

        // Assign the ETX value to the adjacency matrix
        mtx[from][to] = etx;
        mtx[to][from] = etx;
    }
    // Print the adjacency matrix
    std::cout << "\nAdjacency Matrix:\n";
    for (const auto& row : mtx) {
        for (const auto& value : row) {
            if (value == 0)
                std::cout << std::setw(6) << "0.00"; // Print zero values
            else
                std::cout << std::setw(6) << std::fixed << std::setprecision(2) << value;
        }
        std::cout << '\n';
    }
    
    float minCost = dest2_MidNode3(mtx);

    cout<<"The Min Cost For 2 Destination Nodes and 3 Intermediate Nodes is: "<<minCost<<endl;
    vector<float> cost0_4 = {mtx[0][1],mtx[0][2],mtx[1][4],mtx[2][4]};
    vector<float> cost0_5 = {mtx[0][2],mtx[0][3],mtx[2][5],mtx[3][5]};
    vector<float> cost2_45 = {{mtx[2][4],mtx[2][5]}};
    cout << "The min cost from 0 to 4 = " << hop_2_dest_1_route_2(cost0_4)<<endl;
    cout<< "The min cost from 0 to 5 = " << hop_2_dest_1_route_2(cost0_5)<<endl;
    cout << "The min cost from 2->4,5 = "<< dest2(cost2_45) <<endl;
    return 0;
}
