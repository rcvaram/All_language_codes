//Super small example of a super simple BST on dart

main(List<String> args) {
  print("Creating BST");
  var bst = BinarySearchTree();
  print("Inserting 4: yields " + (bst.insert(4)? "true" : "false"));
  print("Inserting 1: yields " + (bst.insert(1)? "true" : "false"));
  print("Inserting 2: yields " + (bst.insert(2)? "true" : "false"));
  print("Inserting 5: yields " + (bst.insert(5)? "true" : "false"));
  print("Inserting 2: yields " + (bst.insert(2)? "true" : "false"));

  print("Inorder: " + bst.inorder);
}

class BinarySearchTree<T extends Comparable> {
  Node<T> root;

  BinarySearchTree();

  insert(T val) {
    if (root == null) {
      root = Node(val: val);
      return true;
    }

    return root.insert(val);
  }

 String get inorder => _inorder(StringBuffer(), root).toString();

 StringBuffer _inorder(StringBuffer sb, Node<T> node) {
   if (node == null) {
     return sb;
   }

   _inorder(sb, node.left);
   sb.writeAll([node.val, " "]);
   _inorder(sb, node.right);

   return sb;
 }
}

class Node<T extends Comparable> {
  Node left, right;
  T val;

  Node({this.left, this.right, this.val});

  /// Inserts the value in the tree and if the value already exists it won't be inserted
  bool insert(T val) {
    int comparison = this.val.compareTo(val);
    if (comparison == 1) {
      if (this.left != null) {
        return this.left.insert(val);
      }

      this.left = Node(val: val);
    } else if (comparison == -1) {
      if (this.right != null) {
        return this.right.insert(val);
      }
      this.right = Node(val: val);
    }

    //If the comparison yield into a 0 it means the value exists therefore we return a false
    //otherwise we just added the value and return true
    return comparison != 0;
  }
}
