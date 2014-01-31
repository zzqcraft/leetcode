class Solution {
    string digitToRoman (int num, char large, char mid, char small)
    {
        string result;
        
        switch (num)
        {
        case 1: result.push_back (small); break;
        case 2: result.push_back (small); result.push_back (small); break;
        case 3: result.push_back (small); result.push_back (small); result.push_back (small); break;
        case 4: result.push_back (small); result.push_back (mid); break;
        case 5: result.push_back (mid); break;
        case 6: result.push_back (mid); result.push_back (small); break;
        case 7: result.push_back (mid); result.push_back (small); result.push_back (small); break;
        case 8: result.push_back (mid); result.push_back (small); result.push_back (small); result.push_back (small); break;
        case 9: result.push_back (small); result.push_back (large); break;
        default: break;
        }
        
        return result;
    }
public:
    string intToRoman(int num) {
        
        string result;
        
        if (num / 1000 > 0)
        {
            int temp = num / 1000;
            num = num % 1000;
            
            result += digitToRoman (temp, '?', '?', 'M');
        }
        
        if (num / 100 > 0)
        {
            int temp = num / 100;
            num = num % 100;
            
            result += digitToRoman (temp, 'M', 'D', 'C');
        }
        
        if (num / 10 > 0)
        {
            int temp = num / 10;
            num = num % 10;
            
            result += digitToRoman (temp, 'C', 'L', 'X');
        }
        
        result += digitToRoman (num, 'X', 'V', 'I');
        
        return result;
    }
};
