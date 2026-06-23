class Solution:
    def maxVowels(self, s, k):

        v = set("aeiou")
        cnt = sum(ch in v for ch in s[:k])
        ans = cnt

        for i in range(k, len(s)):
            cnt += (s[i] in v) - (s[i-k] in v)
            ans = max(ans, cnt)

        return ans