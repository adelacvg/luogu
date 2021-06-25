#include<bits/stdc++.h>
using namespace std;
int n,m,x;
int v[2000010];
#define MAXSIZE (1 << 25)
#define isdigit(x) (x >= '0' && x <= '9')
char buf[MAXSIZE];
char pbuf[MAXSIZE];
char *p1=buf;
char *pp=pbuf;
char *p2 = buf + fread(buf, 1, MAXSIZE, stdin);
inline char gc() {
return *p1++;
}
inline bool blank(char ch) {
return ch == ' ';
}
template <class T>
inline void read(T &x) {
x = 0;
char ch = gc();
while(!isdigit(ch)) ch=gc();
for (; isdigit(ch); ch = gc()) x = x * 10 + (ch - '0');
}
inline void read(char *s) {
static char ch = gc();
for (; blank(ch); ch = gc())
    ;
for (; !blank(ch); ch = gc()) *s++ = ch;
*s = 0;
}
inline void read(char &c) {
for (c = gc(); blank(c); c = gc())
    ;
}
inline void push(const char &c) {
if (pp - pbuf == MAXSIZE) fwrite(pbuf, 1, MAXSIZE, stdout), pp = pbuf;
*pp++ = c;
}
template <class T>
inline void write(T x) {
static T sta[35];
T top = 0;
do {
    sta[top++] = x % 10, x /= 10;
} while (x);
while (top) push(sta[--top] + '0');
}
template <class T>
inline void write(T x, char lastChar) {
write(x), push(lastChar);
}

int main()
{
    read(n);
    read(m);
    int i=1;
    while(i<=n)
    {
        read(v[i]);
        ++i;
    }
    while(m--)
    {
        read(x);
        write(v[x],'\n');
    }
    fwrite(pbuf, 1, pp - pbuf, stdout);
}