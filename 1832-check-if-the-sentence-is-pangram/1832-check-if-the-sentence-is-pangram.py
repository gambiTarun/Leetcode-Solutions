class Solution:
    def checkIfPangram(self, sentence: str) -> bool:
        
        return len(Counter(''.join(s for s in sentence if s.isalpha()))) == 26
        