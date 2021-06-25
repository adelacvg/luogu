#include<bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin >> T;
    if (T == 1) {
        cout << "I love Luogu!";
    } else if (T == 2) {
        cout << 2 + 4 << " " << 10 - 2 - 4;
    } else if (T == 3) {
        cout<<14/4<<"\n"<<14-14%4<<"\n"<<14%4<<endl;
    } else if (T == 4) {
        cout<<setprecision(3)<<fixed<<500.0/3<<endl;
    } else if (T == 5) {
        cout<<15<<endl;
    } else if (T == 6) {
        cout<<sqrt(36+81)<<endl;
    } else if (T == 7) {
        cout<<110<<endl;
        cout<<90<<endl;
        cout<<0<<endl;
    } else if (T == 8) {
        auto pi=3.141593;
        cout<<pi*2*5<<endl;
        cout<<pi*25<<endl;
        cout<<4.0/3*pi*125<<endl;
    } else if (T == 9) {
        cout<<22<<endl;
    } else if (T == 10) {
        cout<<9<<endl;
    } else if (T == 11) {
        cout<<100.0/3<<endl;
    } else if (T == 12) {
        cout<<(int)'M'-'A'+1<<endl;
        cout<<(char)('A'+17)<<endl;
    } else if (T == 13) {
        auto pi=3.141593;
        cout<<floor(pow(4.0/3*pi*4*4*4+4.0/3*pi*10*10*10,1.0/3))<<endl;
    } else if (T == 14) {
        cout<<50<<endl;
    }
    return 0;
}