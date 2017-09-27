package learn_datastructure.graph;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * Created by alexkun on 17/9/6.
 */
public class Dijeska {

    public static void findLowestCost(GraphNode start, GraphNode end) {
        if (null == start || null == start.next || start.next.isEmpty()) {
            return;
        }

        List<GraphNode> nodeList = new ArrayList<GraphNode>();
        Map<GraphNode, Integer> costMap = new HashMap<GraphNode, Integer>(); // 起点到达各节点花费列表
        Map<GraphNode, GraphNode> parentsMap = new HashMap<GraphNode, GraphNode>(); // 节点先后关系，类似二叉树

        int index = 0;
        nodeList.add(start);
        while (index < nodeList.size()) {
            ArrayList<GraphNode> list = (ArrayList) nodeList.get(index).next;
            for (GraphNode oneNode : list) {
                if (!nodeList.contains(oneNode)) {
                    nodeList.add(oneNode);
                }
            }
            index++;
        }

        List<GraphNode> fNodeNext = start.next;
        List<Integer> fNodeCost = start.cost;
        if (fNodeNext.size() != fNodeCost.size()) {
            System.err.println("Init costMap: size of next is not equal to that of cost. " + start.toString());
        }
        index = 0;
        for (GraphNode theNode : nodeList) {
            if (fNodeNext.contains(theNode)) {
                index = fNodeNext.indexOf(theNode);
                costMap.put(theNode, fNodeCost.get(index));  // 添加起点到该节点的花费
            } else {
                costMap.put(theNode, Integer.MAX_VALUE);  // 起点不能直接到该节点，花费为无穷大

            }
        }

        for (GraphNode theNode : nodeList) {
            List<GraphNode> tmpNext = theNode.next;
            for (GraphNode tmpNode : tmpNext) {
                if (true);
            }
        }
    }
}
