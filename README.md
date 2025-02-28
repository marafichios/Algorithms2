# Algorithms2

## HOMEWORK NO 2, PA

* For this homework I used the lab solutions for the Dijkstra algorithm and the
topo sort. Also, the idea to work with an unordered map for the first problem,
and the dynamic programming hint for the second one were taken from ChatGPT.
(therefore I used AI to get hints and ideas for the first and second problem)

* I tried implementing the solutions in a new way, using the class organization
from the labs, a new thing for me as I haven't used it in the last homework.

### Numarare

* For this problem I first checked whether the edges in the graphs were common,
and I computed the number of edges that "go in" each node. I used dynamic
programming to find the number of paths from one node to another, using a topo
sort which I got from the lab solutions. For each node, the dp vector was
updated depending on the number of paths to the current note.
* Spacial complexity: O(N + M)
* Time complexity: O(N + M)


### Trenuri

* This problem is basically a DFS, as it searches for the longest path with
some dinamyc programming combined. The main part of the solution is the DFS
function, where there is checked if the current city has been visited before,
and if so, it returns the value of the dp vector for that city. If not, it
updates the dp vector for the current city, and then it goes to the next one,
while also updating the maximum distance found, which is in the end, the final
result.
* Spacial complexity: O(N + M)
* Time complexity: O(N + M)


### Drumuri

* The lab solution for the Dijkstra algorithm helped me a lot for this one, as
the solution is mostly based on it, and it also helped me understand it better.
So, for this problem the Dijkstra alg is used to comptue the distance from 2
sources to one destination, using a priority queue that takes into consideration
the node with the smallest cost. Then, I updated the distance for each node if
a smaller cost was found. In the end, all the distances that were part of nodes
that couldn't have been reached were set to -1. The final result is the sum of
the 2 distances.
* Spacial complexity: 2 * O((N + M) * log N)
* Time complexity: O(N + M)

    
