# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

import json

def convert_dict(root, d):
    d['val'] = root.val
    d['left'] = None
    d['right'] = None
    if (root.left!=None):
        d['left'] = {}
        convert_dict(root.left, d['left'])
    if (root.right!=None):
        d['right'] = {}
        convert_dict(root.right, d['right'])

def convert_tree(root, d):
    root.val = d['val']
    if d['left']!=None:
        root.left = TreeNode(0)
        convert_tree(root.left, d['left'])
    if d['right']!=None:
        root.right = TreeNode(0)
        convert_tree(root.right, d['right'])

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: Node
        :rtype: str
        """
        d = dict()
        if root!=None:
            convert_dict(root, d)
        return json.dumps(d)

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: Node
        """
        d = json.loads(data)
        if len(d):
            root = TreeNode(0)
            convert_tree(root, d)
            return root
        else:
            return None
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))