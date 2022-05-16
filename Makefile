CC=g++
CFLAGS=-Wall -std=c++14 -o3
BINS=shanonfanon
all: clean programa

programa:
	$(CC) $(CFLAGS) -o shanonfanon shannonFano.c++

clean:
	@echo " [CLN] Removing binary files"
	@rm -f $(BINS)
