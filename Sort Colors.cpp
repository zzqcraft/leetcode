class Solution {
    void swap (int A[], int x, int y)
    {
        if (x != y)
        {
            int temp = A[x];
            A[x] = A[y];
            A[y] = temp;
        }
    }
public:
    void sortColors(int A[], int n) {
        
        int posNext0 = 0;
        int posNext1 = 0;
        int posNext2 = n - 1;
        
        while (posNext2 >= posNext1)
        {
            if (A[posNext1] == 0)
            {
                swap (A, posNext0, posNext1);
                
                posNext0++;
                posNext1++;
            }
            else if (A[posNext1] == 1)
            {
                posNext1++;
            }
            else
            {
                swap (A, posNext1, posNext2);
                
                posNext2--;
            }
        }
    }
};
