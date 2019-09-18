#include <cstdio>
using namespace std;

/*
* io improver By BQSGWYS (reading and writing Positive Intergers and Characters)
* Copy from https://dsa.cs.tsinghua.edu.cn/oj/course.shtml?courseid=1
* It's the RANK 3 CODE of Collection #1 Task 5
* This Code make a A+B Problem for n Times 
* Where a and n are no larger than 1e8 and n less than 1.5e6
*/
namespace io {
const int IBUFSZ = 30000000;//input buffer size (of Byte)
const int OBUFSZ = 10000000;//output buffer size (of Byte)
char ibuf[IBUFSZ];
char obuf[OBUFSZ];
char *it = ibuf, *ot = obuf;
char outbuf[21];
char *outnow = outbuf;
inline void getbuf();
inline void putbuf();
inline void get(int &x);
inline void get(long long &x);
inline void get(char &x);
inline void put(int x);
inline void put(long long x);
inline void put(char x);

inline void getbuf(FILE *inStream) { fread(ibuf, 1, IBUFSZ, inStream); }
inline void putbuf(FILE *outStream) {
  fwrite(obuf, sizeof(char), ot - obuf, outStream);
}
inline void get(int &x) {
  x = 0;
  for (; *it < '0' || *it > '9'; ++it)
    ;
  for (; *it >= '0' && *it <= '9'; x = (x << 1) + (x << 3) + (*(it++) ^ 48))
    ;
  return;
}
inline void get(long long &x) {
  x = 0;
  for (; *it < '0' || *it > '9'; ++it)
    ;
  for (; *it >= '0' && *it <= '9'; x = (x << 1) + (x << 3) + (*(it++) ^ 48))
    ;
  return;
}
inline void get(char &x) { x = *(it++); }
inline void put(int x) {
  while (x) {
    *(outnow++) = x % 10 + '0';
    x /= 10;
  }
  while (outnow > outbuf) *(ot++) = *(--outnow);
}
inline void put(char x) { *(ot++) = x; }
inline void put(long long x) {
  while (x) {
    *(outnow++) = x % 10 + '0';
    x /= 10;
  }
  while (outnow > outbuf) *(ot++) = *(--outnow);
}
}  // namespace io
using namespace io;
int main() {
  int a, n, b;
  getbuf(stdin);
  get(n);
  get(a);
  get(b);
  put(a + b);
  while (--n) {
    put('\n');
    get(a);
    get(b);
    put(a + b);
  }
  putbuf(stdout);
  return 0;
}
