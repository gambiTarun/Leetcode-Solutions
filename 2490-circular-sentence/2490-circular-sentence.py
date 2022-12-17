class Solution:
    def isCircularSentence(self, sentence: str) -> bool:
        
        words = sentence.split(" ")
            
        if len(words)==1:
            return words[0][0]==words[0][-1]
        
        prev = words[0]
        for i in words[1:]:
            if i[0]!=prev[-1]:
                return False
            prev = i
            
        return words[0][0]==words[-1][-1]
            
            