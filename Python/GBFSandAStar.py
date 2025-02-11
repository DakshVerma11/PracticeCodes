from queue import PriorityQueue

def get_graph_input():
    graph = {}
    print("Enter the edges as 'source destination weight' (enter -1 -1 -1 to stop):")
    print("Example: A B 5 (adds an edge from A to B with weight 5)")
    
    while True:
        try:
            source, dest, weight = input().split()
            weight = int(weight)
            
            if source == "-1" and dest == "-1" and weight == -1:
                break
                
            if source not in graph:
                graph[source] = {}
            if dest not in graph:
                graph[dest] = {}
                
            graph[source][dest] = weight
            graph[dest][source] = weight
            
        except ValueError:
            print("Invalid input format. Please use 'source destination weight'")
            continue
            
    return graph

def get_heuristics_input(graph):
    heuristics = {}
    print("\nEnter heuristic values for each node (estimated distance to goal):")
    
    for node in graph.keys():
        while True:
            try:
                print(f"Enter heuristic value for node {node}:")
                value = float(input())
                heuristics[node] = value
                break
            except ValueError:
                print("Please enter a valid number")
    
    return heuristics

def get_search_pairs():
    pairs = []
    print("\nEnter the number of start-goal pairs:")
    num_pairs = int(input())
    
    print("For each pair, enter 'start_node goal_node':")
    for i in range(num_pairs):
        start, goal = input().split()
        pairs.append({'start': start, 'goal': goal})
        
    return pairs

def gbfs(graph, start, goal, heuristics):
    pq = PriorityQueue()
    pq.put((heuristics[start], start, [start], 0))  # (h(n), node, path, cost)
    visited = set()
    expanded_nodes = 0
    
    while not pq.empty():
        h, current, path, cost = pq.get()
        
        if current not in visited:
            expanded_nodes += 1
            visited.add(current)
            
            if current == goal:
                return path, cost, expanded_nodes
            
            for neighbor, edge_cost in graph[current].items():
                if neighbor not in visited:
                    new_path = path + [neighbor]
                    new_cost = cost + edge_cost
                    pq.put((heuristics[neighbor], neighbor, new_path, new_cost))
    
    return None, float('inf'), expanded_nodes

def astar(graph, start, goal, heuristics):
    pq = PriorityQueue()
    pq.put((heuristics[start], start, [start], 0))  # (f(n), node, path, g(n))
    visited = set()
    expanded_nodes = 0
    
    while not pq.empty():
        f, current, path, g = pq.get()
        
        if current not in visited:
            expanded_nodes += 1
            visited.add(current)
            
            if current == goal:
                return path, g, expanded_nodes
            
            for neighbor, edge_cost in graph[current].items():
                if neighbor not in visited:
                    new_path = path + [neighbor]
                    new_g = g + edge_cost
                    new_f = new_g + heuristics[neighbor]
                    pq.put((new_f, neighbor, new_path, new_g))
    
    return None, float('inf'), expanded_nodes

def main():
    print("Welcome to the Path Finding Algorithm Comparator")
    print("============================================")
    
    # Get graph structure
    graph = get_graph_input()
    
    # Get heuristic values
    heuristics = get_heuristics_input(graph)
    
    # Get search pairs
    pairs = get_search_pairs()
    
    # Compare algorithms for each pair
    for pair in pairs:
        start, goal = pair['start'], pair['goal']
        print(f"\nSearching path from {start} to {goal}")
        
        # Run GBFS
        gbfs_path, gbfs_cost, gbfs_expanded = gbfs(graph, start, goal, heuristics)
        print("\nGreedy Best-First Search Results:")
        print(f"Path: {' -> '.join(gbfs_path) if gbfs_path else 'No path found'}")
        print(f"Total Cost: {gbfs_cost}")
        print(f"Nodes Expanded: {gbfs_expanded}")
        
        # Run A*
        astar_path, astar_cost, astar_expanded = astar(graph, start, goal, heuristics)
        print("\nA* Search Results:")
        print(f"Path: {' -> '.join(astar_path) if astar_path else 'No path found'}")
        print(f"Total Cost: {astar_cost}")
        print(f"Nodes Expanded: {astar_expanded}")
        
        # Compare results
        print("\nComparison:")
        print(f"Path Cost: {'GBFS' if gbfs_cost < astar_cost else 'A*'} found a shorter path")
        print(f"Nodes Expanded: {'GBFS' if gbfs_expanded < astar_expanded else 'A*'} expanded fewer nodes")

if __name__ == "__main__":
    main()
