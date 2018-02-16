
// Graph Representations

// edges
// vertices


// DFS --- Stack
// BFS --- Queue
// Dijkstra's --- Priority Queue


/*
Initialize set of reachable vertices and add v-sub-i to a [stack, queue, pqueue];
While [stack, queue, pqueue] is not empty:
    Get and remove [top, first, min] vertex v from [stack, queue, pqueue];
    if vertex v is not reachable, 
        add it to reachable. 
        
        For all neighbhors, v-sub-j, of v, not already in reachable
            add to [stack, queue, pqueue]
            (in case of pqueue, add with cumulative cost).