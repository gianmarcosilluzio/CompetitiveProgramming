#include <iostream>
#include <algorithm>
using namespace std;

int block;

struct Query{
    int L, R;
};

bool compare(Query x, Query y){
    if (x.L/block != y.L/block)
        return x.L/block < y.L/block;

    return x.R < y.R;
}

void queryResults(int a[], int n, Query q[], int m){
    block = (int)sqrt(n);

    sort(q, q + m, compare);

    int currL = 0, currR = 0;
    int currSum = 0;
    int freq[1000000] = {};

    for (int i=0; i<m; i++){
        int L = q[i].L, R = q[i].R;

        while (currL < L){
            int elem = a[currL-1];
            currSum -= freq[elem]*freq[elem]*elem;
            if(freq[elem]!=0)freq[elem]--;
            currSum += freq[elem]*freq[elem]*elem;
            currL++;
        }

        while (currL > L){
            int elem = a[currL];
            currSum -= freq[elem]*freq[elem]*elem;
            freq[elem]++;
            currSum += freq[elem]*freq[elem]*elem;
            currL--;
        }
        while (currR < R){
            int elem = a[currR];
            currSum -= freq[elem]*freq[elem]*elem;
            freq[elem]++;
            currSum += freq[elem]*freq[elem]*elem;
            currR++;
        }

        while (currR > R+1){
            int elem = a[currR-1];
            currSum += freq[elem]*freq[elem]*elem;
            if(freq[elem]!=0)freq[elem]--;
            currSum -= freq[elem]*freq[elem]*elem;
            currR--;
        }

        cout << currSum << endl;
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    int a[n] = {};
    Query q[m] = {};

    for(int i = 0; i < n; i++){
        int elem;
        cin >> elem;
        a[i] = elem;
    }

    for(int j = 0; j < m; j++){
        int l, r;
        cin >> l >> r;
        q[j] = {l,r};
    }

    queryResults(a, n, q, m);
    return 0;
}
