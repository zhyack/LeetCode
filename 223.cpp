class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long long h1=D-B, h2=H-F, h3=0;
        if (D<F || H<B) h3=h1+h2;
        else h3=max(D,H)-min(B,F);
        if (E<A)
            if (G<=A)
                return h1*(C-A)+h2*(G-E);
            else if (G<=C)
                return h2*(A-E)+h3*(G-A)+h1*(C-G);
            else
                return h2*(A-E+G-C)+h3*(C-A);
        else if (E<C)
            if (G<=C)
                return h1*(E-A+C-G)+h3*(G-E);
            else
                return h1*(E-A)+h3*(C-E)+h2*(G-C);
        else
            return h1*(C-A)+h2*(G-E);
                
    }
};