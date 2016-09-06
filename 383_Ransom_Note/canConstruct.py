class Solution(object):
    def canConstruct(self, ransomNote, magazine):
        counts = {c:ransomNote.count(c) for c in ransomNote}

        for key in counts:
            if magazine.count(key) < counts[key]:
                return False
        return True
