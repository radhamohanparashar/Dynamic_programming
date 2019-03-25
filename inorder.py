class Node:

    def __init__(self, data):

        self.left = None
        self.right = None
        self.data = data
# Insert Node
    def insert(self, data):

        if self.data:
            if data < self.data:
                if self.left is None:
                    self.left = Node(data)
                else:
                    self.left.insert(data)
            elif data > self.data:
                if self.right is None:
                    self.right = Node(data)
                else:
                    self.right.insert(data)
        else:
            self.data = data

    def findLeftMostElement(self,root):
        if root.left == None:
           return root.data
        else:
           return self.findLeftMostElement(root.left)
            
# Print the Tree
    def PrintTree(self):
        if self.left:
            self.left.PrintTree()
        print( self.data),
        if self.right:
            self.right.PrintTree()

# Inorder traversal
# Left -> Root -> Right
    def inorderTraversal(self, root, data, flag):
        global Not_found
        res = 0
        if  Not_found == 0:
           if root is None:
              return res,flag
           if root and root.data == data and root.right != None:
              data = self.findLeftMostElement(root.right)
              return data,1
           elif root and root.data == data:
              return 1,1
           if root:
               res,flag = self.inorderTraversal(root.left, data, flag)
               if res == 1:
                   return root.data,1;
               if flag == 0:
                  res,flag = self.inorderTraversal(root.right,data, flag)
                  if res == 1:
                   if self.left.data == root.data:
                     return self.data,1;
                   else:
                     if  Not_found == 0:
                        print "data not found"
                        Not_found = 1
        return res,flag

global  Not_found
Not_found = 0

def main():
    global Not_found
    root = Node(27)
    root.insert(14)
    root.insert(35)
    root.insert(10)
    root.insert(19)
    root.insert(31)
    root.insert(42)
    num = input("Enter a number")
    data = root.inorderTraversal(root,num, 0)
    if Not_found == 0: 
      if type(data) is tuple: 
         data = str(data)
         data = data.replace('(','')
         print data.split(',')[0]
      else:
         print data

main()
