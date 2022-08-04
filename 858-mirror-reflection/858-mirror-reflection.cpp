class Solution {
public:
    int mirrorReflection(int p, int q) {
        int e = p;
        int r = q;
        int gcd = __gcd(e,r);
        
        e/=gcd;
        r/=gcd;
        
        if(e%2!=0 && r%2!=0) return 1;
        if(e%2==0 && r%2!=0) return 2;
    if(e%2!=0 && r%2==0) return 0;
        
        return -1;
    }
};