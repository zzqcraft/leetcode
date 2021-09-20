class Solution:
    def maximumTime(self, time: str) -> str:
        arr = time.split(":")
        result = ""
        
        if arr[0][0] == '?':
            if arr[0][1] != '?' and int(arr[0][1]) >= 4:
                result += '1'
            else:
                result += '2'
        else:
            result += arr[0][0]
        if arr[0][1] == '?':
            if arr[0][0] == '2' or arr[0][0] == '?':
                result += '3'
            else:
                result += '9'
        else:
            result += arr[0][1]
        result += ":"
        if arr[1][0] == '?':
            result += '5'
        else:
            result += arr[1][0]
        
        if arr[1][1] == '?':
            result += '9'
        else:
            result += arr[1][1]
        
        return result
