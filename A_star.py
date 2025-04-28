# A* on a simple 2D grid (no obstacles)
from queue import PriorityQueue

# Heuristic function: Manhattan Distance
def heuristic(a, b):
    return abs(a[0] - b[0]) + abs(a[1] - b[1])

# A* algorithm implementation
def a_star(start, goal):
    # Priority Queue to explore the nodes with lowest f_score first
    open_set = PriorityQueue()
    open_set.put((0, start))  # (f_score, node) 
    came_from = {}  # Dictionary to track the parent of each node
    g_score = {start: 0}  # Dictionary to store the cost to reach each node

    while not open_set.empty():
        current = open_set.get()[1]  # Get the node with the lowest f_score
        if current == goal:
            print("Path found!")  # Goal reached
            return  # Return after finding the path
        
        # Neighbors (Up, Right, Down, Left)
        neighbors = [(0,1),(1,0),(0,-1),(-1,0)]
        
        # Explore each neighbor
        for dx, dy in neighbors:
            neighbor = (current[0] + dx, current[1] + dy)
            
            # Ensure the neighbor is within bounds
            if 0 <= neighbor[0] < 5 and 0 <= neighbor[1] < 5:
                temp_g = g_score[current] + 1  # Calculate tentative g_score

                # If the neighbor has not been explored or the new path is shorter
                if neighbor not in g_score or temp_g < g_score[neighbor]:
                    g_score[neighbor] = temp_g  # Update the g_score
                    f_score = temp_g + heuristic(neighbor, goal)  # Calculate f_score
                    open_set.put((f_score, neighbor))  # Add neighbor to priority queue
                    came_from[neighbor] = current  # Track the parent node
    
    print("Path not found!")  # No path found

# Taking user input for start and goal positions
start_x = int(input("Enter the starting X coordinate (0-4): "))
start_y = int(input("Enter the starting Y coordinate (0-4): "))
goal_x = int(input("Enter the goal X coordinate (0-4): "))
goal_y = int(input("Enter the goal Y coordinate (0-4): "))

start = (start_x, start_y)
goal = (goal_x, goal_y)

a_star(start, goal)

'''
............................................................................................
'''
# A* maze solver


import heapq

# Directions: Up, Down, Left, Right
directions = [(-1,0), (1,0), (0,-1), (0,1)]

# Heuristic function: Manhattan Distance
def heuristic(a, b):
    return abs(a[0] - b[0]) + abs(a[1] - b[1])

# A* maze solver implementation
def astar(maze, start, end):
    # Priority queue to explore the node with lowest f_score
    heap = []
    heapq.heappush(heap, (0 + heuristic(start, end), 0, start, [start]))  # (f_score, g_score, node, path)
    visited = set()  # Set to track visited nodes

    while heap:
        est_total, cost, current, path = heapq.heappop(heap)  # Pop node with lowest f_score

        # If goal is reached, return the path
        if current == end:
            return path

        # Skip already visited nodes
        if current in visited:
            continue
        visited.add(current)

        # Explore neighbors (Up, Down, Left, Right)
        for dx, dy in directions:
            neighbor = (current[0] + dx, current[1] + dy)
            
            # Check if the neighbor is within bounds and not an obstacle
            if (0 <= neighbor[0] < len(maze) and
                0 <= neighbor[1] < len(maze[0]) and
                maze[neighbor[0]][neighbor[1]] == 0):  # 0 indicates an open cell
                # Push the neighbor into the heap with updated g_score and f_score
                heapq.heappush(heap, (
                    cost + 1 + heuristic(neighbor, end),  # f_score
                    cost + 1,  # g_score
                    neighbor,
                    path + [neighbor]  # Add neighbor to the current path
                ))

    return None  # No path found

# Taking user input for the start and end positions
start_x = int(input("Enter the starting X coordinate (0-4): "))
start_y = int(input("Enter the starting Y coordinate (0-4): "))
end_x = int(input("Enter the goal X coordinate (0-4): "))
end_y = int(input("Enter the goal Y coordinate (0-4): "))

start = (start_x, start_y)
end = (end_x, end_y)

# Example maze
maze = [
    [0, 1, 0, 0, 0],
    [0, 1, 0, 1, 0],
    [0, 0, 0, 1, 0],
    [1, 1, 0, 1, 0],
    [0, 0, 0, 0, 0]
]

path = astar(maze, start, end)
if path:
    print("Path found:", path)  # Print the path if found
else:
    print("No path found.")  # No valid path exists
