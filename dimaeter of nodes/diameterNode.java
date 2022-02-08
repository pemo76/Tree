import java.util.*;

public class diameterNode {

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
            if(nodes[idx]==-1){
                return null;
            }
            Node newNode =new Node(nodes[idx]);
            newNode.left=buildtree(nodes);
            newNode.right=buildtree(nodes);
            return newNode;
        }
    }

    public static int hight(Node root){
        if(root==null){
            return 0;
        }
        int left1=hight(root.left);
        int right1=hight(root.right);
        return 1+Math.max(left1,right1);
    }

    public static int countdiameter(Node root){
        if(root==null){
            return 0;
        }
        int dia1=hight(root.left)+hight(root.right)+1;
        int dia2=countdiameter(root.left);
        int dia3=countdiameter(root.right);
        return Math.max(dia1,Math.max(dia2,dia3));
    }

    public static void main(String[] args){
        int nodes[] = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
        binarytree tree = new binarytree();
        Node root = tree.buildtree(nodes);
        System.out.print(countdiameter(root));
    }
}
