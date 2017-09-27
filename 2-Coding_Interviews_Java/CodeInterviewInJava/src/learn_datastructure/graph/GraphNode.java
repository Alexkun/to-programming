package learn_datastructure.graph;

import java.util.ArrayList;
import java.util.List;

/**
 * DAG Graph node
 * Created by alexkun on 17/9/6.
 */
public class GraphNode {
    public List<Integer> cost;
    public List<GraphNode> next;

    public GraphNode() {
        cost = new ArrayList<Integer>();
        next = new ArrayList<GraphNode>();
    }
}
