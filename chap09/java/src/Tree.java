package src;

public class Tree {

    Node root;

    public void preOrderTraversal(Node node) {
        preOrderTraversal(node.right);
        System.out.println(node.data);
        preOrderTraversal(node.left);
    }
}
