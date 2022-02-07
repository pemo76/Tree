public class postorder{

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

    public static void Postorder(Node root){
        if(root==null)
            return;
        System.out.print(root.data+"-");
        Postorder(root.right);
        Postorder(root.left);
    }

    public static void main(String[] args){
        int nodes[] ={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
        binarytree tree = new binarytree();
        Node root =tree.buildtree(nodes);
        Postorder(root);
    }
}