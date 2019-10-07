#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;


bool comp(ll a, ll b)
{
    return a > b;
}

// Complete the lilysHomework function below.
ll lilysHomework(vector<ll> arr) {


    unordered_map<ll, ll> ht;
    for(ll i = 0; i < arr.size(); ++i) ht[arr[i]] = i;

    vector<ll> sorted_arr = arr;
    sort(sorted_arr.begin(), sorted_arr.end());

    ll count = 0;
    for(ll i = 0; i < arr.size(); ++i)
    {
        if(sorted_arr[i] == arr[i]) continue;
        else
        {
            ht[arr[i]] = ht[sorted_arr[i]];
            ht[sorted_arr[i]] = i;
            swap(arr[i], arr[ht[arr[i]]]); 
            count++;
        }
    }
    return count;
}

int main()
{
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(ll i = 0; i < n; ++i) cin >> arr[i];
    int val1 = lilysHomework(arr);
    reverse(arr.begin(), arr.end());
    int val2 = lilysHomework(arr);
    cout << min(val1, val2) << endl;
}