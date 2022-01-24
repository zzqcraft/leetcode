class Solution:
    def compress(self, chars: List[str]) -> int:
        insert_pos = 0
        start_pos = 0
        
        for i in range(1, len(chars)):
            if chars[i] != chars[start_pos]:
                if start_pos + 1 == i:
                    chars[insert_pos] = chars[start_pos]
                    insert_pos += 1
                else:
                    chars[insert_pos] = chars[start_pos]
                    insert_pos += 1
                    num = str(i - start_pos)
                    for c in num:
                        chars[insert_pos] = c
                        insert_pos += 1
                start_pos = i
        if start_pos + 1 == len(chars):
            chars[insert_pos] = chars[start_pos]
            insert_pos += 1
        else:
            chars[insert_pos] = chars[start_pos]
            insert_pos += 1
            num = str(len(chars) - start_pos)
            for c in num:
                chars[insert_pos] = c
                insert_pos += 1
        return insert_pos
        
