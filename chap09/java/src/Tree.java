package src;

public class Tree {

    public final Node makeBinaryTree(char data) {
        Node node = new Node(data);
        node.right = null;
        node.left = null;
        return node;
    }

    public final Node addLeftLeaf(Node node, char data) {
        if (node != null) {
            if (node.left == null) {
                node.left = new Node(data);
                return node.left;
            } else {
                System.out.println("Left Leaf already exists");
            }
        }
        System.out.println("Node null");
        return null;
    }

    public final Node addRightLeaf(Node node, char data) {
        if (node != null) {
            if (node.right == null) {
                node.right = new Node(data);
                return node.right;
            } else {
                System.out.println("Left Leaf already exists");
            }
        }
        System.out.println("Node null");
        return null;
    }

    public final void preOrderTraversal(Node node) {
        if (node != null) {
            System.out.print(node.data + " ");
            if (node.left != null) {
                preOrderTraversal(node.left);
            }
            if (node.right != null) {
                preOrderTraversal(node.right);
            }
        }
    }

    public final void inOrderTraversal(Node node) {
        if (node != null) {

            if (node.left != null) {
                inOrderTraversal(node.left);
            }
            System.out.print(node.data + " ");
            if (node.right != null) {
                inOrderTraversal(node.right);
            }
        }
    }

    public final void postOrderTraversal(Node node) {
        if (node != null) {
            if (node.left != null) {
                postOrderTraversal(node.left);
            }
            if (node.right != null) {
                postOrderTraversal(node.right);
            }
            System.out.print(node.data + " ");
        }
    }
}
