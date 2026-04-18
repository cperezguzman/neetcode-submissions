class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        map1 = {}
        map2 = {}

        for character in s:
            map1[character] = map1.get(character, 0) + 1
        
        for character in t:
            map2[character] = map2.get(character, 0) + 1

        if map1 == map2:
            return True
        
        return False