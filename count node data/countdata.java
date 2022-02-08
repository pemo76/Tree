public class countdata {

    static class Node{
        int data;
        Node left;
        Node right;
        Node(int data){
            this.data=data;
            this.left=null;
            this.right=null;
        }
    }

    static class binarytree{
        static int idx=-1;
        public static Node buildbinartree(int nodes[]){
            idx++;
            if(nodes[idx]==-1)
                return null;
            Node newNode = new Node(nodes[idx]);
            newNode.left=buildbinartree(nodes);
            newNode.right=buildbinartree(nodes);
            return newNode;
        }
    }

    public static  int countData(Node root){
        if(root==null){
            return 0;
        }
        int leftdata=countData(root.left);
        int rightdata=countData(root.right);
        return leftdata+rightdata+root.data;
    }
    public static void main(String[] args){
    int nodes[] = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    binarytree tree = new binarytree();
    Node root=tree.buildbinartree(nodes);
    System.out.println(countData(root));
 }   
}
