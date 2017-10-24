class Solution {
public:

    string convert(int r, char base, char side, char next) {
        string ans = "";

        switch(r) {
            case 0 : return ans;
            case 1 : return ans+side;
            case 2 : return side+ans+side;
            case 3 : return side+ans+side+ans+side;
            case 4 : return side+ans+base;
            case 5 : return ans+base;
            case 6 : return base+ans+side;
            case 7 : return base+ans+side+ans+side;
            case 8 : return base+ans+side+ans+side+ans+side;
            case 9 : return side+ans+next;
        }
    }

    string intToRoman(int num) {
        string ans = "";

        int c=1;
        while(num) {
            int r = num%10;
            num /= 10;
            // cout << r << endl;
            switch(c) {
                case 1 : ans = convert(r, 'V', 'I', 'X') + ans; break;
                case 2 : ans = convert(r, 'L', 'X', 'C') + ans; break;
                case 3 : ans = convert(r, 'D', 'C', 'M') + ans; break;
                case 4 : ans = convert(r, '*', 'M', '%') + ans; break;
            }
            c++;
        }
        return ans;
    }
};