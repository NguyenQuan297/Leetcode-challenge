from collections import deque, defaultdict

class Solution:
    def findCheapestPrice(self, n: int, flights: list[list[int]], src: int, dst: int, k: int) -> int:
        # Build adjacency list
        graph = defaultdict(list)
        for u, v, w in flights:
            graph[u].append((v, w))

        # dist[i] = cheapest cost to reach city i found so far
        dist = [float('inf')] * n
        dist[src] = 0

        # BFS level by level: each level = one more flight (edge)
        # Queue holds (node, cost_to_reach_node)
        queue = deque([(src, 0)])

        for _ in range(k + 1):  # at most k+1 edges = k stops
            # Process only nodes in the current level
            for _ in range(len(queue)):
                node, cost = queue.popleft()
                for neighbor, price in graph[node]:
                    new_cost = cost + price
                    # Only enqueue if we found a cheaper path to neighbor
                    if new_cost < dist[neighbor]:
                        dist[neighbor] = new_cost
                        queue.append((neighbor, new_cost))

        return dist[dst] if dist[dst] != float('inf') else -1