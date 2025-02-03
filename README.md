#Efficient Routing Strategies

This project implements efficient strategies for message routing in a network. It focuses on calculating costs for routing to multiple destinations and optimizing routes using intermediate nodes.

#Features

1.Cost calculation for routing to multiple destination nodes.

2.Optimization using intermediate nodes to minimize cost.

3.Modular structure for scalability and reusability.

#Project Structure

1. multi_destination_cost.c

Purpose: Computes the costs for routing to multiple destination nodes from a source node.

Functionality:

Accepts an adjacency matrix representing the network.

Calculates the direct routing costs for each destination node.

Outputs the total cost for routing to multiple destinations.

2. min_cost_combinations.c

Purpose: Finds the minimum-cost combinations of routes using intermediate nodes.

Functionality:

Utilizes dynamic programming to determine the cost-effective paths.

Iterates through all possible intermediate nodes to compute optimized paths.

Outputs the best combination of routes with minimum costs.

3. cost_with_intermediate_nodes.cpp

Purpose: Provides an optimized implementation for advanced routing strategies.

Functionality:

Focuses on using specific intermediate nodes to reduce costs.

Implements algorithms for cost minimization considering node probabilities.

Outputs the minimum cost for routing to a destination node.

#How to Build and Run

Compilation

Compile the C and C++ files using the following commands:

1. gcc -o multi_destination_cost multi_destination_cost.c
2. gcc -o min_cost_combinations min_cost_combinations.c
3. gcc -o cost_with_intermediate_nodes cost_with_intermediate_nodes.cpp

Execution

Run the compiled binaries with the following commands:
 ./multi_destination_cost
./min_cost_combinations
./cost_with_intermediate_nodes

#Diagram of Network Nodes

The routing strategies in this project work on a network of nodes that can be represented as follows:

```text
       [0]
    /   |   \
  /     |     \
/       |       \
[1]    [2]     [3]
 \      |      /
  \     |     /
   \    |    /
     [4] [5]
```

Explanation:

The numbers in square brackets represent the nodes in the network.

The edges between the nodes represent possible paths for routing messages.

The cost_with_intermediate_nodes.c file focuses on finding the minimum cost for routing to a destination node, using intermediate nodes (like node 2 or node 4 in the diagram).

#Code Explanation

1. multi_destination_cost.c

Input: Adjacency matrix, source node, destination nodes.

Process:

Reads the number of nodes and the adjacency matrix.

Calculates direct costs from the source node to each destination.

Output: Total routing cost.

2. min_cost_combinations.c

Input: Adjacency matrix, source node, destination nodes.

Process:

Iterates through all nodes to find intermediate paths.

Uses a dynamic programming approach to minimize costs.

Output: Optimal routing costs with intermediate nodes.

3. cost_with_intermediate_nodes.cpp

Input: Adjacency matrix, source node, destination nodes, intermediate nodes.

Process:

Computes costs by iterating over intermediate nodes.

Uses weighted probabilities to refine cost estimates.

Output: Final minimum routing cost.

#Authors

Shreyansh Singh
