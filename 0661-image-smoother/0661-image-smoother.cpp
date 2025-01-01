class Solution {
public:
    int dx[3] = {0,1,-1};
    int dy[3] = {0,1,-1};

    bool valid(int i,int j,int n,int m){

        if(i>=0&&i<n and j>=0&&j<m) return 1;
        else return 0;
    }

    int help(int i,int j,vector<vector<int>>& img, int n, int m){
        int sum =0;
        int num = 0;
        for(int s =0;s<3;s++){
            for(int k =0;k<3;k++){
                int x = i + dx[s];
                int y = j+ dy[k];
                if(valid(x,y,n,m)){
                    num++;
                    sum += img[x][y];
                }
            }
        }
        return sum/num;
    }

    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size();
        int m = img[0].size();
        vector<vector<int>> vt(n,vector<int>(m,0));
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                int ans = help(i,j,img,n,m);
                vt[i][j] = ans;
            }
        }
        return vt;
    }
};