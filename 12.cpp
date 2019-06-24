class Solution {
public:
    string intToRoman(int num) {
        string ret = "";
        int m = num/1000;
        if (m)
            for (int i = 0;i < m;i++) ret+='M';
        num -= m*1000;
        if (num>=900){
            ret+="CM";
            num-=900;
        }
        if (num>=500){
            ret+='D';
            num-=500;
        }
        if (num>=400){
            ret+="CD";
            num-=400;
        }
        
        int c = num/100;
        if (c)
            for (int i = 0;i < c;i++) ret+='C';
        num -= c*100;
        if (num>=90){
            ret+="XC";
            num-=90;
        }
        if (num>=50){
            ret+='L';
            num-=50;
        }
        if (num>=40){
            ret+="XL";
            num-=40;
        }
        
        int x = num/10;
        if (x)
            for (int i = 0;i < x;i++) ret+='X';
        num -= x*10;
        if (num>=9){
            ret+="IX";
            num-=9;
        }
        if (num>=5){
            ret+='V';
            num-=5;
        }
        if (num>=4){
            ret+="IV";
            num-=4;
        }
        
        for (int i = 0;i < num;i++) ret+='I';
        
        return ret;
    }
};