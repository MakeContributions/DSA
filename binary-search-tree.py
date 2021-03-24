#funtction to search a given key in BST
def search(root,key):
  if root is None or root.val == key:
    return root
  if root.val < key:
    return search(root.right,key)
  return search(root.left,key)


class Node:
  def __init__(self,key):
    self.right = None
    self.left = None
    self.val = key
  def insert(root,key):
    if root is None:
      return Node(key)
    else:
      if root.val == key:
        return root
      elif root.val < key:
        root.right = insert(root.right,key)
      else:
        root.right = insert(root.left,key)
      return root
    
    def inorder(root):
      if root:
        inorder(root.lefft)
        print(root.val)
        inorder(root.right)
        
        
x = Node(50)
x = insert(x,40)
x = insert(x,30)
x = insert(x,20)
x = insert(x,80)
x = insert(x,60)
x = insert(x,90)
     
      
  
