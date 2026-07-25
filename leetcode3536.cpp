class Solution {
public:
    int maxProduct(int n) {
        int largest = -1;
        int slargest = -1;
        while(n > 0){
            int ld = n % 10;
            if(ld >= largest){
                slargest = largest;
                largest = ld;
            }else if(ld < largest && ld > slargest){
                slargest = ld;
            }
            n /= 10;
        }
        int mul = largest * slargest;
        return mul;
    }
};
