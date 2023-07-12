class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        while(x || y){
            if((x & 0x1) != (y & 0x1)){
                count += 1;
            }
            x >>= 1;
            y >>= 1;
        }
        return count;
    }
};
