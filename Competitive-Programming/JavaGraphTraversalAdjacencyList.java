
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Set;

class vertex<T> {

    public T value;
    public ArrayList<vertex<T>> neighbors;

    public vertex(T value) {
        this.value = value;
        this.neighbors = new ArrayList<>();
    }
}

class graph<T> {

    public HashMap<T, vertex<T>> nodes;

    public graph() {
        nodes = new HashMap<>();
    }

    public void addNode(T node) {
        nodes.put(node, new vertex<>(node));
    }

    public void bfs(T start) {
        Set<T> visited = new HashSet<>();

        Deque<vertex<T>> queue = new ArrayDeque<>();
        queue.addLast(nodes.get(start));

        System.out.print("BFS: ");

        while (!queue.isEmpty()) {
            vertex<T> current_node = queue.removeFirst();

            if (!visited.contains(current_node.value)) {
                System.out.print(current_node.value);
                System.out.print(' ');

                visited.add(current_node.value);

                for (vertex<T> neighbor : current_node.neighbors) {
                    queue.addLast(neighbor);
                }
            }
        }

        System.out.println();
    }

    public void dfs(T start) {
        Set<T> visited = new HashSet<>();

        Deque<vertex<T>> stack = new ArrayDeque<>();
        stack.push(nodes.get(start));

        System.out.print("DFS: ");

        while (!stack.isEmpty()) {
            vertex<T> current_node = stack.pop();

            if (!visited.contains(current_node.value)) {
                System.out.print(current_node.value);
                System.out.print(' ');

                visited.add(current_node.value);

                // this is just to retain the order of neighbors per level.
                for (int i = 0; i < current_node.neighbors.size(); i++) {
                    stack.push(current_node.neighbors.get(current_node.neighbors.size() - 1 - i));
                }

                // but the code below is also correct, it will just give
                // a different level order of neighbors
                // for (vertex<T> neighbor : current_node.neighbors) {
                //     stack.push(neighbor);
                // }
            }
        }

        System.out.println();
    }
}

public class JavaGraphTraversalAdjacencyList {

    public static void main(String[] args) {
        graph<Integer> graph = new graph<>();

        graph.addNode(1);
        graph.addNode(8);
        graph.addNode(3);
        graph.addNode(5);
        graph.addNode(7);
        graph.addNode(4);
        graph.addNode(6);

        graph.nodes.get(1).neighbors.add(graph.nodes.get(8));

        graph.nodes.get(8).neighbors.add(graph.nodes.get(1));
        graph.nodes.get(8).neighbors.add(graph.nodes.get(3));
        graph.nodes.get(8).neighbors.add(graph.nodes.get(5));
        graph.nodes.get(8).neighbors.add(graph.nodes.get(7));

        graph.nodes.get(3).neighbors.add(graph.nodes.get(8));
        graph.nodes.get(3).neighbors.add(graph.nodes.get(4));

        graph.nodes.get(5).neighbors.add(graph.nodes.get(6));

        graph.nodes.get(6).neighbors.add(graph.nodes.get(1));
        graph.nodes.get(6).neighbors.add(graph.nodes.get(5));

        graph.bfs(1);
        graph.dfs(1);
    }
}
