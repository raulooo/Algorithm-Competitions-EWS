#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define pr(a) cerr << #a << ": " << a << endl;
#define prv(b) cerr << #b << ":\n"; for(int countvec = 0; countvec < b.size(); countvec++) {cerr << b[countvec] << "    ";} cerr << endl;
#define pra(b) cerr << #b << ":\n"; for(int countvec = 0; countvec < sizeof(b)/sizeof(int); countvec++) {cerr << b[countvec] << "    ";} cerr << endl;
#define prm(c) cerr << #c << ":\n"; for(int countmat = 0; countmat < c.size(); countmat++) {for(int countbb = 0; countbb < c[countmat].size(); countbb++) { cerr << c[countmat][countbb] << "    "; } cerr << endl; }
#define fill(a , value) memset(a , value , sizeof(a))
#define FOREACH(i,c) for (typeof((c).end()) i = (c).begin(); i != (c).end(); ++i)
string tos(int a) {ostringstream os(""); os << a; return os.str();}


// BEGIN CUT HERE
vector<string> split( const string& s, const string& delim =" " ) {
    vector<string> res;
    string t;
    for ( int i = 0 ; i != s.size() ; i++ ) {
        if ( delim.find( s[i] ) != string::npos ) {
            if ( !t.empty() ) {
                res.push_back( t );
                t = "";
            }
        } else {
            t += s[i];
        }
    }
    if ( !t.empty() ) {
        res.push_back(t);
    }
    return res;
}

vector<int> splitInt( const string& s, const string& delim =" " ) {
    vector<string> tok = split( s, delim );
    vector<int> res;
    for ( int i = 0 ; i != tok.size(); i++ )
        res.push_back( atoi( tok[i].c_str() ) );
    return res;
}
// END CUT HERE

// BEGIN CUT HERE
#define ARRSIZE(x) (sizeof(x)/sizeof(x[0]))

template<typename T> void print( T a ) {
    cerr << a;
}
static void print( long long a ) {
    cerr << a << "L";
}
static void print( string a ) {
    cerr << '"' << a << '"';
}
template<typename T> void print( vector<T> a ) {
    cerr << "{";
    for ( int i = 0 ; i != a.size() ; i++ ) {
        if ( i != 0 ) cerr << ", ";
        print( a[i] );
    }
    cerr << "}" << endl;
}
template<typename T> void eq( int n, T have, T need ) {
    if ( have == need ) {
        cerr << "Case " << n << " passed." << endl;
    } else {
        cerr << "Case " << n << " failed: expected ";
        print( need );
        cerr << " received ";
        print( have );
        cerr << "." << endl;
    }
}
template<typename T> void eq( int n, vector<T> have, vector<T> need ) {
    if( have.size() != need.size() ) {
        cerr << "Case " << n << " failed: returned " << have.size() << " elements; expected " << need.size() << " elements.";
        print( have );
        print( need );
        return;
    }
    for( int i= 0; i < have.size(); i++ ) {
        if( have[i] != need[i] ) {
            cerr << "Case " << n << " failed. Expected and returned array differ in position " << i << ".";
            print( have );
            print( need );
            return;
        }
    }
    cerr << "Case " << n << " passed." << endl;
}
static void eq( int n, string have, string need ) {
    if ( have == need ) {
        cerr << "Case " << n << " passed." << endl;
    } else {
        cerr << "Case " << n << " failed: expected ";
        print( need );
        cerr << " received ";
        print( have );
        cerr << "." << endl;
    }
}
// END CUT HERE
int isPrime(int n){
    if(n<=2)return 1;
    for (int i = 2; i*i <=n; ++i)
    {
        if(n%i==0)
            return 0;
    }
    return 1;
}
int dp[1001];
int go(int n){
    if(isPrime(n)){
        return 1;
    }
    int win=0;
    if(dp[n]==-1){
        for(int i = 2; i*i <=n;i++)
        {
            if(n%i==0) {
                win|=go(n-i);
                win|=go(n-(n/i));
            }
        }
        dp[n]=!win;
    }
    return dp[n];
}
class TheNumberGameDivTwo {
public:
    string find(int n) {
        fill(dp,-1);
        return !go(n)?"John":"Brus";
    }
};

// BEGIN CUT HERE
int main( int argc, char* argv[] ) {

    {
        TheNumberGameDivTwo theObject;
        eq(3, theObject.find(6),"John");
    }
    // if(1)return 1;
    {
        TheNumberGameDivTwo theObject;
        eq(1, theObject.find(2),"Brus");
    }
        {
        TheNumberGameDivTwo theObject;
        eq(3, theObject.find(3),"Brus");
    }
    {
        TheNumberGameDivTwo theObject;
        eq(3, theObject.find(4),"John");
    }
    {
        TheNumberGameDivTwo theObject;
        eq(2, theObject.find(9),"Brus");
    }
    {
        TheNumberGameDivTwo theObject;
        eq(2, theObject.find(8),"Brus");
    }
    {
        TheNumberGameDivTwo theObject;
        eq(2, theObject.find(16),"John");
    }
    {
        TheNumberGameDivTwo theObject;
        eq(2, theObject.find(747),"Brus");
    }
    {
        TheNumberGameDivTwo theObject;
        eq(3, theObject.find(128),"Brus");
    }
}
// END CUT HERE
