class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& b) {
        for(int i=0;i<9;i++){
            unordered_set<char> x;
            for(int j=0;j<9;j++){
                if(b[i][j]=='.') continue;
                if(x.empty() || x.find(b[i][j])==x.end()) x.insert(b[i][j]);
                else if(x.find(b[i][j])!=x.end()) return false;
            }
        }
        for(int i=0;i<9;i++){
            unordered_set<char> x;
            for(int j=0;j<9;j++){
                if(b[j][i]=='.') continue;
                if(x.empty() || x.find(b[j][i])==x.end()) x.insert(b[j][i]);
                else if(x.find(b[j][i])!=x.end()) return false;
            }
        }
        for(int i=0;i<3;i++){
            unordered_set<char> x;
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                if(b[j][k+3*i]=='.') continue;
                if(x.empty() || x.find(b[j][3*i+k])==x.end()) x.insert(b[j][3*i+k]);
                else if(x.find(b[j][3*i+k])!=x.end()) return false;
                }
            }
        }
        
         for(int i=0;i<3;i++){
            unordered_set<char> x;
            for(int j=3;j<6;j++){
                for(int k=0;k<3;k++){
                if(b[j][3*i+k]=='.') continue;
                if(x.empty() || x.find(b[j][3*i+k])==x.end()) x.insert(b[j][3*i+k]);
                else if(x.find(b[j][3*i+k])!=x.end()) return false;
                }
            }
        }

         for(int i=0;i<3;i++){
            unordered_set<char> x;
            for(int j=6;j<9;j++){
                for(int k=0;k<3;k++){
                if(b[j][3*i+k]=='.') continue;
                if(x.empty() || x.find(b[j][3*i+k])==x.end()) x.insert(b[j][3*i+k]);
                else if(x.find(b[j][3*i+k])!=x.end()) return false;
                }
            }
        }

        return true;

    }
};