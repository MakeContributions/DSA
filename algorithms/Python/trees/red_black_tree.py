#Contributor: Anirudh Makhana (https://github.com/anirudhmakhana)
#source: https://a.co/d/7oRsCT2
#To learn more about R-B Tree: https://www.youtube.com/watch?v=qvZGUFHWChY

from collections import deque

BLACK = True
RED = False

class Node:
    def __init__(self, key):
        self.key = key
        self.p = None # parent
        self.color = RED
        self.left = None
        self.right = None

    def print_color(self):
        if self.color == BLACK:
            return '(b)'
        return '(r)'


class RedBlackTree:
    def __init__(self):
        self.NIL = Node(99999) # arbitrary value
        self.NIL.color = BLACK
        self.NIL.left = None
        self.NIL.right = None
        self.root = self.NIL

    # O(1)
    def left_rotate(self, x):
        y = x.right
        x.right = y.left 

        if y.left != self.NIL:
            y.left.p = x
        
        y.p = x.p 

        if x.p is None:
            self.root = y
        elif x == x.p.left:
            x.p.left = y
        else:
            x.p.right = y 

        y.left = x 
        x.p = y

    # O(1)
    def right_rotate(self, x):
        y = x.left 
        x.left = y.right 

        if y.right != self.NIL:
            y.right.p = x

        y.p = x.p 

        if x.p is None:
            self.root = y 
        elif x == x.p.right:
            x.p.right = y 
        else:
            x.p.left = y 

        y.right = x 
        x.p = y

    # O(logn) total
    def insert(self, key):
        z = Node(key)
        z.left = self.NIL
        z.right = self.NIL

        y = None 
        x = self.root
        
        while x != self.NIL:
            y = x
            if z.key < x.key:
                x = x.left 
            else:
                x = x.right 
        
        z.p = y 
        if y == None:
            self.root = z 
        elif z.key < y.key: 
            y.left = z 
        else:
            y.right = z

        self.insert_fixup(z)

    # O(logn)
    def insert_fixup(self, z):
        while z.p and z.p.color == RED:
            if z.p == z.p.p.left:
                y = z.p.p.right 
                if y.color == RED:
                    z.p.color = BLACK
                    y.color = BLACK 
                    z.p.p.color = RED
                    z = z.p.p
                else:
                    if z == z.p.right:
                        z = z.p 
                        self.left_rotate(z)
                    z.p.color = BLACK
                    z.p.p.color = RED 
                    self.right_rotate(z.p.p)
            else:
                y = z.p.p.left 
                if y.color == RED:
                    z.p.color = BLACK
                    y.color = BLACK
                    z.p.p.color = RED
                    z = z.p.p
                else:
                    if z == z.p.left:
                        z = z.p 
                        self.right_rotate(z)
                    z.p.color = BLACK
                    z.p.p.color = RED 
                    self.left_rotate(z.p.p)
            if z == self.root:
                break
        self.root.color = BLACK

    # O(logn) total
    def delete(self, k):
        z = self.search(k)

        if z == self.NIL:
            return "Key not found!"

        y = z
        y_orig_color = y.color 
        
        # case 1
        if z.left == self.NIL:
            x = z.right 
            self.transplant(z, z.right)
        # case 2
        elif z.right == self.NIL:
            x = z.left
            self.transplant(z, z.left)
        # case 3
        else:
            y = self.minimum(z.right)
            y_orig_color = y.color
            x = y.right 
            
            if y.p == z:
                x.p = y
            else:
                self.transplant(y, y.right)
                y.right = z.right
                y.right.p = y
            
            self.transplant(z, y)
            y.left = z.left 
            y.left.p = y 
            y.color = z.color 
        
        if y_orig_color == BLACK:
            self.delete_fixup(x)

    # O(logn)
    def delete_fixup(self, x):
        while x != self.root and x.color == BLACK:
            if x == x.p.left:
                w = x.p.right
                # type 1
                if w.color == RED:
                    w.color = BLACK
                    x.p.color = RED
                    self.left_rotate(x.p)
                    w = x.p.right
                # type 2
                if w.left.color == BLACK and w.right.color == BLACK:
                    w.color = RED 
                    x = x.p 
                else:
                    # type 3
                    if w.right.color == BLACK:
                        w.left.color = BLACK
                        w.color = RED
                        self.right_rotate(w)
                        w = x.p.right
                    # type 4
                    w.color = x.p.color 
                    x.p.color = BLACK 
                    w.right.color = BLACK 
                    self.left_rotate(x.p)
                    x = self.root
            else:
                w = x.p.left
                # type 1
                if w.color == RED:
                    w.color = BLACK
                    x.p.color = RED
                    self.right_rotate(x.p)
                    w = x.p.left
                # type 2
                if w.right.color == BLACK and w.left.color == BLACK:
                    w.color = RED 
                    x = x.p 
                else:
                    # type 3
                    if w.left.color == BLACK:
                        w.right.color = BLACK
                        w.color = RED
                        self.left_rotate(w)
                        w = x.p.left
                    # type 4
                    w.color = x.p.color 
                    x.p.color = BLACK 
                    w.left.color = BLACK 
                    self.right_rotate(x.p)
                    x = self.root
        x.color = BLACK

    # O(1)
    def transplant(self, u, v):
        if u.p == None:
            self.root = v
        elif u == u.p.left:
            u.p.left = v 
        else:
            u.p.right = v
        v.p = u.p 

    # O(h) = O(logn) for RB trees
    def minimum(self, x):
        while x.left != self.NIL:
            x = x.left
        return x

    # O(h) = O(logn) for RB trees
    def search(self, k):
        x = self.root
        while x != self.NIL and k != x.key:
            if k < x.key:
                x = x.left
            else:
                x = x.right
        return x

    # simple level-order tree traversal
    def print_tree(self, print_color=False):
        queue = deque()
        queue.append(self.root)

        while(queue):
            node = queue.popleft()

            if print_color:
                print(f'{node.key}{node.print_color()}', end=' ')
            else:
                print(node.key, end=' ')

            # don't add NIL nodes
            if node.left != self.NIL:
                queue.append(node.left)
            if node.right != self.NIL:
                queue.append(node.right)


def make_larger_tree():
    RB = RedBlackTree()
    RB.insert(8)
    RB.insert(5)
    RB.insert(15)
    RB.insert(12)
    RB.insert(19)
    RB.insert(9)
    RB.insert(13)
    RB.insert(23)
    return RB


# ignoring color, just demonstrating rotation
def rotations():    
    print('\n-- ROTATIONS --')
    RB = RedBlackTree()
    RB.insert(5)
    RB.insert(2)
    RB.insert(10)
    RB.insert(8)
    RB.insert(12)
    RB.insert(6)
    RB.insert(9)
    RB.print_tree()

    print('\n\n-- After left rotation --')
    five = RB.search(5)
    RB.left_rotate(five)
    RB.print_tree()

    print('\n\n-- After right rotation --')
    ten = RB.search(10)
    RB.right_rotate(ten)
    RB.print_tree()


def insertions():
    RB = RedBlackTree()

    print('\n\n-- INSERTIONS, after case 0 --')
    RB.insert(15)
    RB.print_tree(True)

    print('\n\n-- Insert 5 --')
    RB.insert(5)
    RB.print_tree(True)

    print('\n\n-- Insert 1 (case 3) --')
    RB.insert(1)
    RB.print_tree(True)

    print('\n\n-- Move to larger tree --')
    RB = make_larger_tree()
    RB.print_tree(True)

    print('\n\n-- Insert 10 (case 1, 2, and 3) --')
    RB.insert(10)
    RB.print_tree(True)


def deletions():
    print('\n\n-- DELETIONS --')
    RB = make_larger_tree()
    RB.insert(10)
    RB.print_tree(True)

    print('\n\n-- Delete 19 (case 1) --')
    RB.delete(19)
    RB.print_tree(True)

    print('\n\n-- Insert 1 --')
    RB.insert(1)
    RB.print_tree(True)

    print('\n\n-- Delete 5 (case 2) --')
    RB.delete(5)
    RB.print_tree(True)

    print('\n\n-- Delete 12 (case 3) --')
    RB.delete(12)
    RB.print_tree(True)

if __name__ == '__main__':
    # https://youtu.be/95s3ndZRGbk
    rotations()

    # https://youtu.be/A3JZinzkMpk
    insertions()

    #https://www.youtube.com/watch?v=lU99loSvD8s
    deletions()
