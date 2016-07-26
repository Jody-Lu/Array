class TrieNode(object):
    def __init__(self):
        """
        :type isKey: bool
        :type children dict[key] = TrieNode
        :key: str
        """
        self.isKey = False
        self.children = {}

class WordDictionary(object):
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = TrieNode()

    def addWord(self, word):
        """
        Add a word into the data structure.
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

        prev_node.children[word[-1]].isKey = True

    def search(self, word):
        """
        Returns if the word is in the data structure. A word could
        contain the dot character '.' to represent any one letter.
        :type word: str
        :rtype: bool
        """
        res = False
        def dfs(word, node):
            #print word
            if len(word) == 0: 
                if node.isKey:
                    #print node
                    return True
                else:
                    return False

            i = 0

            while i < len(word):
                if word[i] == '.':
                    if not node.children: 
                        return False
                    for child in node.children.values():
                        #print "hey", word[i + 1:]
                        return dfs(word[i + 1:], child)
                    #i += 1
                    #break
                elif word[i] in node.children:
                    node = node.children[word[i]]
                    i += 1
                else:
                    return False
            
            print "gap", i, word
            if i == len(word) and node.isKey:
                return True
            else:
                #print word, i
                return False

        return dfs(word, self.root)

wordDictionary = WordDictionary()
wordDictionary.addWord("at")
wordDictionary.addWord("and") 
wordDictionary.addWord("an") 
wordDictionary.addWord("add") 
#print wordDictionary.search("a")
#print wordDictionary.search(".at")
wordDictionary.addWord("bat")
print wordDictionary.search(".at")

"""
wordDictionary.addWord("wo")
print wordDictionary.root.children
print wordDictionary.search(".o")
"""
