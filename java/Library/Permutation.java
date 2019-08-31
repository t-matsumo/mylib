import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Deque;
import java.util.List;

class Node {
    List<Integer> state;
    List<Integer> candidate;

    Node(List<Integer> state, List<Integer> candidate) {
        this.state = state;
        this.candidate = candidate;
    }
}

// List<Integer> targetの中身の順列をすべて列挙
class Permutation {
    public static void main(String[] args) {

        Deque<Node> deque = new ArrayDeque<>();
        List<Integer> firstState = Collections.emptyList();
        deque.push(new Node(firstState, target));
        while (!deque.isEmpty()) {
            Node node = deque.pop();

            if (node.state.size() == target.size()) {
                System.out.println(node.state);
            }

            for (Integer element : node.candidate) {
                List<Integer> nextState = new ArrayList<>(node.state);
                nextState.add(element);

                List<Integer> candidate = new ArrayList<>(node.candidate);
                candidate.remove(element);

                deque.add(new Node(nextState, candidate));
            }
        }
    }
}
