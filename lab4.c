
/*
 * @file lab5.c - Lab 5 Virtual Memory Replacement Simulator
 * @author your name (c) 2019
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "lab4.h"


void process_params(int argc, char **argv);
int  evict(int pid);
int  evict_min(int pid);
int  evict_fifo(int pid);
int  evict_second(int pid);
int  evict_lru(int pid);
int  evict_lfu(int pid);
void reset_refbits();
void dump_ptable(int timestep);



/*
 * process_args - process command-line arguments and process files
 * @param argc - argument count
 * @param argv - array of argumenet strings
 */
void process_params(int argc, char **argv) {
  FILE *plist, *ptrace, *outfp;
  int memsize, pagesize, period;
  int nproc, naccess;
  alloc_t alloc;
  evict_t evict;
  local_t replacement;
  access_t  *trace;
  int pid, msize, addr, count = 0;
  char ch;

  if (argc != 7) {
    fprintf(stderr, "usage: %s [memsize] [pagesize] [alloc] [eviction] [replacement] [period]\n", argv[0]);
    fprintf(stderr, "      memsize  - size of physical memory in bytes\n");
    fprintf(stderr, "      pagesize - size of pages/frames in bytes \n");
    fprintf(stderr, "      alloc:\n");
    fprintf(stderr, "          0 - equal allocation\n");
    fprintf(stderr, "          1 - proportional allocation\n");
    fprintf(stderr, "      eviction:\n");
    fprintf(stderr, "          0 - FIFO page replacement:\n");
    fprintf(stderr, "          1 - second chance replacement:\n");
    fprintf(stderr, "          2 - LRU replacement\n");
    fprintf(stderr, "          3 - LFU replacement\n");
    fprintf(stderr, "      replacement:\n");
    fprintf(stderr, "          0 - global replacement\n");
    fprintf(stderr, "          1 - local replacement\n");
    exit(1);
  }

  // process command-line args
  memsize  = atoi(argv[1]);
  pagesize = atoi(argv[2]);
  period   = atoi(argv[6]);

  // allocation algorithm
  switch(atoi(argv[3])) {
    case 0:
      alloc = AllocEq;
      break;
    case 1:
      alloc = AllocProp;
      break;
    default:
      fprintf(stderr, "allocation algorithm must be 0 (equal) or 1 (proportional)\n");
      exit(1);
      break;
  }

  // eviction algorithm
  switch(atoi(argv[4])) {
    case 0:
      evict = EvictFIFO;
      break;
    case 1:
      evict = EvictSecond;
      break;
    case 2:
      evict = EvictLRU;
      break;
    case 3:
      evict = EvictLFU;
      break;
    default:
      fprintf(stderr, "allocation algorithm must be 0 (equal) or 1 (proportional)\n");
      exit(1);
      break;
  }

  // global vs. local replacement
  switch(atoi(argv[5])) {
    case 0:
      replacement = ReplacementGlobal;
      break;
    case 1:
      replacement = ReplacementLocal;
      break;
    default:
      fprintf(stderr, "allocation algorithm must be 0 (equal) or 1 (proportional)\n");
      exit(1);
      break;
  }

  // read process information
  plist = fopen("plist.txt", "r");
  if (!plist) {
    perror("plist fopen");
    exit(1);
  }

  fscanf(plist, "%d", &nproc);

  for (int i=0; i < nproc; i++) {
    fscanf(plist, "%d %d", &pid, &msize);
    // now have process i's memory size in msize
  }

  fclose(plist);

  ptrace = fopen("ptrace.txt", "r");
  if (!ptrace) {
    perror("ptrace fopen");
    exit(1);
  }


  // count total # of accesses
  while ((ch = fgetc(ptrace)) != EOF) {
    if (ch == '\n') count++;
  }
  naccess = count;

  // now read them into an array
  rewind(ptrace);

  trace = calloc(count, sizeof(access_t));
  if (!trace) {
    perror("trace alloc");
    exit(1);
  }

  for (int cur = 0; cur < count; cur++) {
    fscanf(ptrace, "%d %d", &trace[cur].pid, &trace[cur].addr);
  }

  fclose(ptrace);

  printf("*****************************************************\n");
  printf("memsize   : %13d   pagesize: %12d   period     : %8d  nframes: %d\n",
      memsize, pagesize, period, memsize/pagesize);
  printf("allocation: %13s   eviction: %12s   replacement: %8s\n",
      alloc == AllocEq ? "equal" : "proportional",
      evict == EvictFIFO ? "FIFO"  :
                               (evict == EvictSecond ? "SecondChance" :
                                                           (evict == EvictLRU ? "LRU" : "LFU")),
      replacement == ReplacementGlobal ? "global" : "local");

  printf("trace contains %d memory accesses\n", count);

  if (period == 0) {
    outfp = NULL;
  } else {
    outfp = fopen("ptable.txt", "w");
    if (!outfp) {
      perror("output file");
      exit(1);
    }
  }
}



/*
 * evict - evict the best candidate page from those resident in memory
 * @param pid the process requesting eviction
 * @returns 1 if frame stolen from another process, 0 otherwise
 */
int  evict(int pid) {
  evict_t evict = EvictFIFO; // you need to fix this with your own way to trace eviction scheme

  switch (evict) {
    case EvictFIFO:
      // call FIFO eviction function here
      return 0;
      break;
    case EvictSecond:
      // call 2nd chance eviction function here
      return 0;
      break;
    case EvictLRU:
      // call LRU eviction function here
      return 0;
      break;
    case EvictLFU:
      // call LFU eviction function here
      return 0;
      break;
  }
  return -1;
}



/**
 * main
 */
int main(int argc, char **argv) {
  int nframes, remaining, totalpages = 0, allocated = 0;
  int equal, pid, page;

  process_params(argc, argv);

  // calculate #pages per process

  // allocate frames to each process

  // process memory trace using replacement strategy
  //for (int ts=0; ts < naccess; ts++) {
  //
  //}
}
