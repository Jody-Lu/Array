class TrieNode(object):
    def __init__(self):
        """
        Initialize your data structure here.
        :type children: dict{key:TrieNode}
        :typr key: str
        :type count: int (# word)
        """
        self.isKey = False
        self.children = {}

class Trie(object):
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        """
        Insert a word into a trie.
        :type word: str
        :rtype: void
        """
        prev_node = None
        node = self.root
        i = 0
        while i < len(word) and word[i] in node.children:
            prev_node = node
            node = node.children[word[i]]
            i += 1

        while i < len(word):
            node.children[word[i]] = TrieNode()
            prev_node = node
            node = node.children[word[i]]
            i += 1
        # True if this Node is the end of somestring
        prev_node.children[word[-1]].isKey = True


    def search(self, word):
        """
        Return if the word is in the trie.
        A word in a Trie must the the leaf of the tree
        :type word: str
        :rtype: bool
        """
        node = self.root
        i = 0
        while i < len(word) and word[i] in node.children:
            node = node.children[word[i]]
            i += 1
        if i == len(word) and node.isKey:
            return True
        else:
            return False

    def startsWith(self, prefix):
        """
        Return if there is any word in the trie
        that starts with the given prefix.
        :type prefix: str
        :rtype: bool
        """
        node = self.root
        i = 0
        while i < len(prefix) and prefix[i] in node.children:
            node = node.children[prefix[i]]
            i += 1
        return True if i == len(prefix) else False

trie = Trie()
trie.insert("abc")
print trie.search("abc")
print trie.search("ab")
trie.insert("ab")
print trie.search("ab")
trie.insert("ab")
print trie.search("ab")
