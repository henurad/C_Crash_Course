#include <stdlib.h>

#define NULL 0
#define EOF -1
#define BUFSIZE 1024
#define OPEN_MAX 20 /* max #files open at once */


enum _flags {
	_READ = 01, /* file open for reading */
	_WRITE = 02, /* file open for writing */
	_UNBUF = 04, /* file is unbuffered */
	_EOF = 010, /* EOF has occured on this file */
	_ERR = 020 /* error occured on this file */
};

typedef struct _iobuf {
	int cnt;
	char *ptr;
	char *base;
	int flag;
	int fd;
} FILE;
extern FILE _iob[OPEN_MAX];

FILE _iob[OPEN_MAX] = {
	{0, (char *) 0, (char *) 0, _READ, 0},
	{0, (char *) 0, (char *) 0, _WRITE, 1},
	{0, (char *) 0, (char *) 0, _WRITE | _UNBUF, 2}
};

#define stdin (&_iob[0])
#define stdout (&_iob[1])
#define stderr (&_iob[2])

int _fillbuf(FILE *);
int _flushbuf(int, FILE *);

#define feof(p) ((p)->flag & _EOF != 0)
#define ferror(p) ((p)->flag & _ERR != 0)
#define fileno(p) ((p)->fd)

#define getc(p) (--(p)->cnt >= 0 ? (unsigned char) *(p)->ptr++ : _fillbuf(p))
#define getchar() getc(stdin)

#define putc(x,p) (--(p)->cnt >= 0 ? *(p)->ptr++ = (x) : _flushbuf((x), p))
#define putchar(x) putc((x), stdout)

#define PERMS 0666

#include <fcntl.h>

FILE *fopen(char *name, char *mode){
	FILE *fp;
	int fd;

	if(*mode != 'w' && *mode != 'a' && *mode != 'r') return NULL;

	for(fp = _iob; fp < _iob + OPEN_MAX; fp++){
		if(fp->flag & (_READ | _WRITE) == 0) // free slot found
			break;
	}
	if(fp >= _iob + OPEN_MAX) return NULL; // no free slot found

	if(*mode == 'w'){
		fd = creat(name, PERMS);
	}else if(*mode == 'a'){
		if((fd = open(name, O_WRONLY, 0)) == -1)
			fd = creat(name, PERMS);
		lseek(fd, 0L, 2);
	} else { // *mode == 'r'
		fd = open(name, O_RDONLY, 0);
	}

	if(fd == -1) return NULL;

	fp->fd = fd;
	fp->cnt = 0;
	fp->base = fp->ptr =  NULL;
	fp->flag = (*mode == 'r') ? _READ : _WRITE;
	return fp;
}

int _fillbuf(FILE *fp){
	int bufsize;

	if((fp->flag & (_READ | _ERR | _EOF)) != _READ) return EOF;
	bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZE;
	if(fp->base == NULL){
		if((fp->base = (char *) malloc(bufsize)) == NULL)
			return EOF; /* can't get buffer */
	}
	fp->ptr = fp->base;
	fp->cnt = fread(fp->fd, fp->ptr, bufsize);
	if(--fp->cnt < 0){
		if(fp->cnt == -1)
			fp->flag |= _EOF;
		else 
			fp->flag |= _ERR;
		fp->cnt = 0;
		return EOF;
	}

	return (unsigned char) *fp->ptr++;	
}





