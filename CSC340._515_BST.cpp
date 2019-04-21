using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSC340._515_BST
{
    class Program
    {
        static void Main(string[] args)
        {
            BST myTree = new BST();
            //Console.WriteLine(myTree.IsEmpty());
            //myTree.Insert(14);
            //myTree.Insert(21);
            //myTree.Insert(7);
            //myTree.Insert(11);
            //myTree.Insert(14);
            //myTree.Insert(6);

            myTree.Insert(4);
            myTree.Insert(81);
            myTree.Insert(40);
            myTree.Insert(12);
            myTree.Insert(1);
            myTree.Insert(2);

            //myTree.Preorder();
            //myTree.Inorder();
            myTree.Postorder();

            Console.WriteLine("Max = {0}, Min = {1}", myTree.GetMax(), myTree.GetMin());
        }
    }

    public class Node
    {
        //data
        public int value;
        public Node left;
        public Node right;
        //methods

        //constructor
        public Node(int newValue)
        {
            value = newValue;
            left = null;
            right = null;
        }
    }

    public class BST
    {
        //data
        Node root;

        //methods
        public bool IsEmpty()
        {
            return root == null;
        }

        public int GetMin()
        {
            if (IsEmpty())
                throw new InvalidOperationException("the tree is empty ... it has no min");
            else
            {
                Node curr = root;
                while (curr.left != null)   //as long as curr has a left child (not null) ...
                    curr = curr.left;       //move left
                //at the end of this loop curr points to the left-most node
                return curr.value;
            }
        }
        public bool Contains(int searchedValue)
        {
            if(IsEmpty())
            {
                return false;
            }
            else
            {
                Node curr = root;
                while (curr!=null)
                {
                    if (curr.value == searchedValue)
                        return true;
                    else if (searchedValue < curr.value)
                        curr = curr.left;//moves left
                    else
                        curr = curr.right;
                }

                //if you get here it means curr is null
                return false;
            }

        }

        public void Insert(int newVal)
        {
            //create a new node
            Node newNode = new Node(newVal);

            if (IsEmpty())
            {
                root = newNode;
            }
            else 
            {
                Node curr = root;
                while (curr!=null)
                {
                    if (newVal <= curr.value)
                    {
                        if (curr.left != null)
                            curr = curr.left;
                        else
                        {
                            curr.left = newNode;
                            break;
                        }
                    }
                    else
                    {
                        if(curr.right!=null)
                            curr = curr.right;
                        else
                        {
                            curr.right = newNode;
                            break;
                        }
                    }
                }
            }

        }
        public int GetMax()
        {
            if (IsEmpty())
                throw new InvalidOperationException("can't find max ... the tree is empty");
            else
            {
                Node curr = root;
                while (curr.right != null)//checks if it has a right child
                    curr = curr.right; //moves right
                //this is outside of the while loop
                //when you get here you're on the right most node
                return curr.value;
            }
        }

        public void Preorder()
        {
            PreorderHelper(root);
        }

        public void PreorderHelper(Node curr)//NLR
        {
            if(curr!=null)
            {
                Console.WriteLine(curr.value);//display the current Node's value
                PreorderHelper(curr.left); //recursively call this method on left subtree
                PreorderHelper(curr.right); //recursively call this method on left subtree
            }
        }

        public void Inorder()
        {
            InorderHelper(root);
        }

        public void InorderHelper(Node curr)//LNR
        {
            if (curr != null)
            {
                InorderHelper(curr.left); //recursively call this method on left subtree
                Console.WriteLine(curr.value);//display the current Node's value
                InorderHelper(curr.right); //recursively call this method on left subtree
            }
        }

        public void Postorder()
        {
            PostorderHelper(root);
        }

        public void PostorderHelper(Node curr)//LRN
        {
            if (curr != null)
            {
                PostorderHelper(curr.left); //recursively call this method on left subtree
                PostorderHelper(curr.right); //recursively call this method on left subtree
                Console.WriteLine(curr.value);//display the current Node's value
            }
        }
        //constructor
        public BST()
        {
            root = null;
        }
    }
}
