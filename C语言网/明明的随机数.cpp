#include<iostream>
#include <set>
#include <cstdio>
using namespace std;
set<int > st;
int main() {
    int n, t;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &t);
        st.insert(t);
    }
    for (set<int >::iterator it = st.begin(); it != st.end(); it++) printf("%d ", *it);
    return 0;
}
