
// BINARY SEARCH TREE IMPLEMENTATION
//

class BSTNode {
    constructor(value) {
        this.value = value;
        this.left = null;
        this.right = null;
    }
}

class BST {
    #size;

    constructor() {
        this.root = null;
        this.#size = 0;
    }



    // return number of nodes in the tree
    get Size() {
        return this.#size;
    }



    // search for a value
    Search(data, root = this.root) {
        let cur = root;
        if (cur === null) {
            return false;
        }
        else if (cur.value === data) {
            return true;
        }
        else if (data < cur.value) {
            return this.Search(data, cur.left);
        }
        else {
            return this.Search(data, cur.right);
        }
    }



    // insert value in tree
    Insert(data, root = this.root) {
        if (this.#size === 0) {
            this.root = new BSTNode(data);
        }
        else if (root === null) {
            root = new BSTNode(data);
        }
        else if (data <= root.value) {
            root.left = this.Insert(data, root.left);
        }
        else if (data > root.value) {
            root.right = this.Insert(data, root.right);
        }
        this.#size++;
        return root;
    }

    

    // find inorder predecessor of a value; used in Delete()
    FindInorderPredecessor(node) {
        if (node.right) {
            node = FindInorderPredecessor(node.right);
        }
        return node;
    }



    // delete value
    Delete(data, root = this.root) {
        // root is null or data isn't in the tree
        if (!this.root || !this.Search(data)) {
            return null;
        }

        // data is in the left side of tree
        else if (data < root.value) {
            root.left = this.Delete(data, root.left);
            return root;
        }

        // data is in the right side of tree
        else if (data > root.value) {
            root.right = this.Delete(data, root.right);
            return root;
        }

        else {
            // node is a leaf
            if (!root.left && !root.right) {
                root = null;
            }
            // node has 1 child on the right
            else if (!root.left && root.right) {
                let tmp = root.right;
                root = tmo;
            }
            // node has 1 child on the left
            else if (root.left && !root.right) {
                let tmp = root.left;
                root = tmp;
            }
            // node has 2 children
            else {
                let tmp = this.FindInorderPredecessor(root.left);
                this.Delete(tmp.value);
                root.value = tmp.value;
            }
            this.#size--;
            return root;
        }
    }



    Invert(root = this.root) {
        [root.left, root.right] = [root.right, root.left];
        Invert(root.left);
        Invert(root.right);
    }


    PreOrderDisplay(root = this.root) {
        if (root) {
            console.log(root.value);
            this.PreOrder(root.left);
            this.PreOrder(root.right);
        }
    }


    InOrderDisplay(root = this.root) {
        if (root) {
            this.InOrder(root.left);
            console.log(root.value);
            this.InOrder(root.right);
        }
    }


    PostOrderDisplay(root = this.root) {
        if (root) {
            this.PostOrder(root.left);
            this.PostOrder(root.right);
            console.log(root.value);
        }
    }
}


let tree = new BST();

tree.Insert(10);
tree.Insert(5);
tree.Insert(2);
tree.Insert(15);
tree.Insert(20);

tree.InOrderDisplay();