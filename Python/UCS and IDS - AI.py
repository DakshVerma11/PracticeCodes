from queue import PriorityQueue

def ucs(graph, start, goal):
    pq = PriorityQueue()
    pq.put((0, start, [start]))  # (cost, node, path)
    visited = set()
    explored_nodes = 0
    
    while not pq.empty():
        cost, node, path = pq.get()
        if node not in visited:
            visited.add(node)
            explored_nodes += 1
            
            if node == goal:
                return path, cost, explored_nodes
                
            for neighbor, edge_cost in graph[node].items():
                if neighbor not in visited:
                    pq.put((cost + edge_cost, neighbor, path + [neighbor]))
                    
    return None, float('inf'), explored_nodes

def ids(graph, start, goal):
    def dls(current_node, current_path, current_cost, depth, explored_nodes):
        if current_node == goal:
            return current_path, current_cost, explored_nodes
        if depth <= 0:
            return None, float('inf'), explored_nodes
            
        for neighbor, edge_cost in graph[current_node].items():
            if neighbor not in current_path:
                result, cost, explored_nodes = dls(
                    neighbor, current_path + [neighbor],
                    current_cost + edge_cost, depth - 1,
                    explored_nodes + 1
                )
                if result:
                    return result, cost, explored_nodes
        return None, float('inf'), explored_nodes
        
    depth = 0
    total_explored_nodes = 0
    while True:
        result, cost, explored_nodes = dls(start, [start], 0, depth, 0)
        total_explored_nodes += explored_nodes
        if result:
            return result, cost, total_explored_nodes
        depth += 1

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
                
            # Initialize dictionary entries if they don't exist
            if source not in graph:
                graph[source] = {}
            if dest not in graph:
                graph[dest] = {}
                
            # Add bidirectional edges
            graph[source][dest] = weight
            graph[dest][source] = weight
            
        except ValueError:
            print("Invalid input format. Please use 'source destination weight'")
            continue
            
    return graph

def get_agents_input():
    agents = []
    print("\nEnter the number of agents:")
    num_agents = int(input())
    
    print("For each agent, enter 'start_node goal_node':")
    for i in range(num_agents):
        start, goal = input().split()
        agents.append({'start': start, 'goal': goal})
        
    return agents

def main():
    print("Welcome to the Graph Search Algorithm Comparator")
    print("=============================================")
    
    # Get graph structure
    graph = get_graph_input()
    
    # Get agent details
    agents = get_agents_input()
    
    # Compare algorithms for each agent
    for agent in agents:
        start, goal = agent['start'], agent['goal']
        print(f"\nAgent: {start} -> {goal}")
        
        # UCS
        ucs_path, ucs_cost, ucs_explored = ucs(graph, start, goal)
        print("UCS:")
        print(f" Path: {ucs_path}")
        print(f" Cost: {ucs_cost}")
        print(f" Explored Nodes: {ucs_explored}")
        
        # IDS
        ids_path, ids_cost, ids_explored = ids(graph, start, goal)
        print("IDS:")
        print(f" Path: {ids_path}")
        print(f" Cost: {ids_cost}")
        print(f" Explored Nodes: {ids_explored}")
        

if __name__ == "__main__":
    main()