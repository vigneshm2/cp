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
const double eps = 1e-6;

#define F(i,a,n) for(int i=(a);i<(n);i++)

template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){
    for(int i=0;i<(t).size();i++)s<<t[i]<<((i<(t).size()-1)?" ":"");return s; }
template<typename T> ostream& operator<<(ostream &s,set<T> t){for(T x:t) s<<x<<" ";return s; }
template<typename T> istream& operator>>(istream &s,vector<T> &t){
    for(int _i=0;_i<t.size();_i++) s>>t[_i];return s; }

#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()

typedef pair<double, double> point;
typedef pair<point, point> point_p;

double distance(point p1, point p2){
    return sqrt((p1.first-p2.first)*(p1.first-p2.first)+(p1.second-p2.second)*(p1.second-p2.second));
}
// find centres of circle given 2 points and radius
point_p find_centre(point p1, point p2, double radius){
    double mid_dist = distance(p1,p2)/2;
    if(mid_dist > radius) return mp(p1,p1);
    double cen_dist = sqrt(radius*radius - mid_dist*mid_dist);
    // cout<<mid_dist<<"\n";
    // cout<<cen_dist<<"\n";
    
    point midp = point((p1.first+p2.first)/2, (p1.second+p2.second)/2);
    if(abs(cen_dist) < eps) return mp(midp, midp);
    // cout<<midp<<"\n";
    point perp = point(p1.second-p2.second, p1.first-p2.first);
    double perp_mod = distance(perp, point(0.0,0.0));
    // cout<<perp<<"\n";
    // cout<<perp_mod<<"\n";
    perp_mod = cen_dist/perp_mod;
    
    point centre1 = point(midp.first + perp_mod*perp.first, midp.second + perp_mod*perp.second);
    point centre2 = point(midp.first - perp_mod*perp.first, midp.second - perp_mod*perp.second);
    return mp(centre1, centre2);
}

// returns centre of circle, count with given radius which encloses max number of points
pair<point, int> max_circle(double radius, const vector<point> &pts){
    int n= pts.size();
    point max_centre;
    int max_pts=-1;
    // choose two points on circle
    for(int pt1=0; pt1<n; pt1++){
        for(int pt2=pt1+1; pt2<n; pt2++){
            point p1 = pts[pt1], p2=pts[pt2];
            if(p1==p2) continue;
            point_p centres = find_centre(p1, p2, radius);
            
            point centre = centres.first;
            int n_in = 0;
            for(int i=0; i<n; i++){
                if(distance(centre, pts[i]) <= radius) n_in++;
            }
            if(n_in>max_pts){
                max_pts = n_in;
                max_centre = centre;
            }
            centre = centres.second;
            n_in = 0;
            for(int i=0; i<n; i++){
                if(distance(centre, pts[i]) <= radius) n_in++;
            }
            if(n_in>max_pts){
                max_pts = n_in;
                max_centre = centre;
            }
        }
    }
    return mp(max_centre, max_pts);
}

int check(double radius, vector<point> &pts, int m){
    return max_circle(radius, pts).second >= m;
}
int main(int argc, const char * argv[]) {
    #ifdef LOCAL_TEST
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    
    int m,n;
    cin>>n>>m;
    vector<point> pts(n);
    F(i,0,n){
        double a,b;
        cin>>a>>b;
        pts[i] = point(a,b);
    }
    if(m==1) cout<<"0.00001\n";
    else {
    double l=0.0,r=10000.0;
    while(abs(r-l)>eps){
        double mid=(l+r)/2.0;
        // printf("%.7f : %d\n",mid,check(mid, pts, m));
        if(check(mid, pts, m)) r=mid;
        else  l=mid+eps;
    }
    printf("%.7f\n", l+eps);
    }
}


