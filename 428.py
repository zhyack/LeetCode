"""
# Definition for a Node.
class Node(object):
    def __init__(self, val, children):
        self.val = val
        self.children = children
"""
import json

def convert_dict(root, d):
    d['val'] = root.val
    d['child'] = []
    for c in root.children:
        d['child'].append({})
        convert_dict(c, d['child'][-1])

def convert_tree(root, d):
    root.val = d['val']
    for c in d['child']:
        root.children.append(Node(0,[]))
        convert_tree(root.children[-1], c)

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
            root = Node(0, [])
            convert_tree(root, d)
            return root
        else:
            return None

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))