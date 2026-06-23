class Solution:
    def minimumAbsDifference(self, arr):

        arr.sort()

        d = min(arr[i] - arr[i-1] for i in range(1, len(arr)))

        return [[arr[i-1], arr[i]]
                for i in range(1, len(arr))
                if arr[i] - arr[i-1] == d]