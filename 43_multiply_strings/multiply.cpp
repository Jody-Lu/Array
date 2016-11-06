class Solution {
public:
    string multiply(string num1, string num2) {
        string res = "";
        string count = "";
        string num;
        
        if(num1 == "0" || num2 == "0") { return "0"; }
        
        for(int i = num2.size() - 1; i >= 0; i--) {
            num = multiplyHelper(num1, num2[i]);
            num += count;
            res = addStrings(res, num);
            count += "0";
        }
        return res;
    }
private:
    string multiplyHelper(string num1, char num2) {
        // num2 should be single digit 
        string res = "";
        int num = 0;
        for(int i = num1.size() - 1; i >= 0; i--) {
            num /= 10;
            num += (num1[i] - '0') * (num2 - '0');
            res.append(to_string(num % 10));
        }
        
        if(num >= 10) {
            res.append(to_string(num / 10));
        }
        
        reverse(res.begin(), res.end());
        return res;
    }

    string addStrings(string num1, string num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int sum = 0;
        string res = "";
        
        while(i >= 0 || j >= 0 || sum >= 10) {
            sum /= 10;
            
            if(i >= 0) {
                sum += (num1[i] - '0');
                i--;
            }
            
            if(j >= 0) {
                sum += (num2[j] - '0');
                j--;
            }
            
            res.append(to_string(sum % 10));
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};