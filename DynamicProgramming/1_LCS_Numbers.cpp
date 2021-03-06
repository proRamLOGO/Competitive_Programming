#include<iostream>
using namespace std ;

int32_t main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin) ;
    freopen("output.txt","w", stdout) ;
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr) ;

    int n,m;
    cin >> n >> m ;
    int *x, *y ;
    x = new int[n] ;
    y = new int[m] ;
    
    for ( int *i = x ; i!=x+n ; ++i ) {
        cin >> *i ;
    }
    for ( int *i = y ; i!=y+m ; ++i ) {
        cin >> *i ;
    }

    int dp[101][101] = {0} ;
    for ( int i = 1 ; i <= n ; ++i )
        for ( int j = 1 ; j <= m ; ++j ) {
            dp[i][j] = (x[i-1]==y[j-1]) ? dp[i-1][j-1] + 1 : max(dp[i-1][j],dp[i][j-1]) ;
        }

    cout << dp[n][m] << endl  ;

}