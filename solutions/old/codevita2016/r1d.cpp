//  Created by Vignesh Manoharan

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <numeric>
#include <sstream>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int INF = 1000000000;
const ll LINF = 1e17;
const double PI =3.141592653589793238;
const int mod=1000000007;
const double eps = 0.000001;

#define F(i,a,n) for(int i=(a);i<(n);i++)

template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){
    for(int i=0;i<(t).size();i++)s<<t[i]<<((i<(t).size()-1)?" ":"");return s; }
template<typename T> istream& operator>>(istream &s,vector<T> &t){
    for(int _i=0;_i<t.size();_i++) s>>t[_i];return s; }

#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()

void parse_fen(char board[8][8], string fen){
    int start=0,end=0;
    F(i,0,8){
        end = fen.find('/', start);
        if(end==(int)string::npos) end=fen.size();
        int j=0;
        F(ci,start,end){
            int c=fen[ci];
            if(c>='0' && c<='9'){
                F(k,j,j+c-'0') board[i][k]=' ';
                j+=c-'0';
            } else {
                board[i][j]=c;
                j++;
            }
        }
        start=end+1;
    }
}
string movename(int x,int y,int nx,int ny){
    stringstream ss;
    ss<<(char)('a'+y)<<8-x<<(char)('a'+ny)<<8-nx;
    return ss.str();
}
vector<string> bishop_moves(char board[8][8], int x, int y, char player){
    vii squares;
    int dx[]={1,-1,1,-1};
    int dy[]={1,1,-1,-1};
    F(dd,0,4){
        int nx=x+dx[dd], ny=y+dy[dd];
        while(nx>=0 && ny>=0 && nx<8 && ny<8){
            if(board[nx][ny]==' '){
                squares.pb(mp(nx,ny));
                nx=nx+dx[dd],ny=ny+dy[dd];
            } else {
                if(player=='w' && islower(board[nx][ny])) squares.pb(mp(nx,ny));
                if(player=='b' && isupper(board[nx][ny])) squares.pb(mp(nx,ny));
                break;
            }
        }
    }
    sort(all(squares));
    vector<string> moves;
    F(i,0,(int)squares.size()){
        ii p=squares[i];
        moves.pb(movename(x,y,p.first,p.second));
    }
    return moves;
}
int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    char board[8][8];
    F(i,0,8) F(j,0,8) board[i][j]='-';
    string fen;char player;
    cin>>fen>>player;
    // cout<<fen<<player<<"\n";
    parse_fen(board, fen);
    // F(i,0,8) {F(j,0,8) cout<<board[i][j]; cout<<"\n";}
    vector<string> squares;
    F(i,0,8) F(j,0,8){
        if(player=='w' && board[i][j]=='B'){
            vector<string> c_sqs = bishop_moves(board, i, j, 'w');
            squares.insert(squares.end(),all(c_sqs));
        }
        if(player=='b' && board[i][j]=='b'){
            vector<string> c_sqs = bishop_moves(board, i, j, 'b');
            squares.insert(squares.end(),all(c_sqs));
        }
    }
    cout<<'[';
    F(i,0,(int)squares.size()-1) cout<<squares[i]<<", ";
    cout<<squares[squares.size()-1]<<']';
}


