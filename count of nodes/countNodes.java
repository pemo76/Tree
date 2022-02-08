import javax.print.attribute.standard.NumberOfInterveningJobs;

public class countNodes {

    static class Node{
        int data;
        Node right;
        Node left;
        Node(int data){
            this.data=data;
            this.left=null;
            this.right=null;
        }
    }

    static class binarytree{
        static int idx=-1;
        public static Node buildtree(int nodes[]){
            idx++;
            if(nodes[idx]==-1)
               return null;
            Node newNode = new Node(nodes[idx]);
            newNode.left=buildtree(nodes);
            newNode.right=buildtree(nodes);
            return newNode;
        }
    }

    public static int countnode(Node root){
        if(root==null)
            return 0;
        int leftNode=countnode(root.left);
        int rightNode=countnode(root.right);

        return leftNode+rightNode+1;
    }

    public static void main(String[] args){
        int nodes[] = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
        binarytree tree = new binarytree();
        Node root = tree.buildtree(nodes);
        System.out.println(countnode(root));
    }
}
