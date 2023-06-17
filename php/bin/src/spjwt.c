#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned long p(char* s) {
	char*r=s;
	while(*s&&(*s^'.'))s++;
	return ((long)s)-((long)r);
}

extern unsigned int bswap32(unsigned int d);

// buffer must be at least 3 bytes larger than output
unsigned long b64d(unsigned char*d,unsigned char*s,long l) {
	char*b64="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-_";
	unsigned long o = 0;
	while(l > 0) {
		unsigned int v = 0;
		for(int i = 0; i < 4; i++) {
			int c = 0;
			if(l > 3 || i < l) {
				for(;b64[c] != s[i];c++) if(!b64[c]) goto r;
				o++;
			}
			v = (v << 6) | c;
		}
		v = bswap32(v) >> 8;
		*((int*)d)=v;
		l-=4;
		s+=4;
		d+=3;
	}
r:	return ((o*3) >> 2);
}

int main(int argc, char** argv) {
	if(argc < 2) exit(1);
	
	long z=strlen(argv[1])+1;
	char s[z+sizeof(int)];
	memcpy(s,argv[1],z);
	*((int*)(s+z))=0;
	
	unsigned long hz = p(s);
	unsigned long pz = p(s+hz+1);
	unsigned long gz = p(s+hz+pz+2);
	
	char* hs = s;
	char* ps = s+hz+1;
	char* gs = s+hz+pz+2;	

	char hb[((hz*3)/4)+4];
	char pb[((pz*3)/4)+4];
	char gb[((gz*3)/4)+4];

	memset(hb, 0, ((hz*3)/4)+4);
	memset(pb, 0, ((pz*3)/4)+4);
	memset(gb, 0, ((gz*3)/4)+4);

	b64d(hb,hs,hz);
	b64d(pb,ps,pz);
	b64d(gb,gs,gz);

	printf(
		"{\"header\":%s,\n" 
		"\"payload\":%s,\n" 
		"\"signature\":\"%s\"\n}\n",
		hb,pb,gs
	);
}
