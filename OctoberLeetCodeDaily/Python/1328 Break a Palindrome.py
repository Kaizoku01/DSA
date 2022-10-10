class Solution:
    def breakPalindrome(self, palindrome: str) -> str:
        if len(palindrome) == 1:
            return ''
        
        lst = list(palindrome)
        c = collections.Counter(lst)
        
        if c.get('a') == len(lst) or c.get('a') == len(lst)-1:
            lst[-1] = 'b'
            return ''.join(lst)
        
        for i in range(len(lst)):
            if lst[i] == 'a':
                pass
            else:
                lst[i] = 'a'
                return ''.join(lst)
