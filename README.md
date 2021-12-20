# IPC_PIPE

Descriptions: Pipe: The Pipe is the oldest method of IPC in the Unix systems.
-> The Pipe is a unidirectional byte stream. Means, the data can travel only in one way through a pipe.
-> It has two ends where two process can be connected to each other.
-> The Writing process has its standard output(fd=1) joined to the write end of the pipe.
-> The reading process has its standard input(fd=0) joined to the read end of the pipe.

============
pipe_size.c
============
The Pipe size will say about the size of total pipe in bytes. Because, The pipe is simply a buffer maintained in karnel memory.
-> fcntl: The fcnt() system call helps to quary or set acess control flags and the close-on-exec flag of any file descriptor..
Ref.: https://www.youtube.com/watch?v=A5vyIcBMPKo

