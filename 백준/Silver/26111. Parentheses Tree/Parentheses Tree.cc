#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    stack<char> st;
    long long sum = 0;

    string s;
    cin >> s;

    st.push(s[0]);

    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == ')')
        {
            st.pop();
            if (s[i - 1] == '(')
                sum += st.size();
        }
        else
            st.push(s[i]);
    }

    cout << sum << "\n";
    return 0;
}