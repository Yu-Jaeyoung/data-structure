package src;

public class Main {
    public static void main(String[] args) {
        Tree tree = new Tree();
        Node NodeNum0 = tree.makeBinaryTree('A');
        Node NodeNum1 = tree.addLeftLeaf(NodeNum0,'B');
        Node NodeNum2 = tree.addRightLeaf(NodeNum0,'C');
        tree.addLeftLeaf(NodeNum1,'D');
        tree.addRightLeaf(NodeNum1,'E');
        tree.addLeftLeaf(NodeNum2,'F');
        tree.addRightLeaf(NodeNum2,'G');

        tree.preOrderTraversal(NodeNum0);
        System.out.println();
        tree.inOrderTraversal(NodeNum0);
        System.out.println();
        tree.postOrderTraversal(NodeNum0);
    }
}
