#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<set>
using namespace std;
const int inf = 0x7fffffff;
int n, t, x, order;
multiset<int>V;
int main(){
    V.insert(-inf);
    V.insert(inf);
    scanf("%d", &n);
    while (n--){
        scanf("%d%d", &t, &x);
        if (t == 1){
            auto it = V.lower_bound(x);
            order = 0;
            for (auto i = V.begin(); i != it; i++, order++);
            printf("%d\n", order);
        }
        else if (t == 2){
            order = -1;
            for (int i : V)
                if (++order == x)
                    printf("%d\n", i);
        }
        else if (t == 3){
            auto it = V.lower_bound(x);
            printf("%d\n", *(--it));
        }
        else if (t == 4){
            printf("%d\n", *V.upper_bound(x));
        }
        else V.insert(x);
        
    }
    return 0;
}
