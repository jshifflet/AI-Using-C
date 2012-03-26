#include <stdio.h>
#include <string.h>
#define MAX 100

struct FL {
  char from[20];
  char to[20];
  int distance;
  char skip;
};

struct FL flight[MAX];

int f_pos = 0;
int find_pos=0;

void assert_flight(char*, char*, int);

void setup()
{
  assert_flight("New York", "Chicago", 1000);
  assert_flight("Chicago", "Denver", 1000);
  assert_flight("New York", "Toronto", 800); 
  assert_flight("New York", "Denver", 1900);
  assert_flight("Toronto", "Calgary", 1500);
  assert_flight("Toronto", "Los Angelas", 1800);
  assert_flight("Toronto", "Chicago", 500);
  assert_flight("Denver", "Urbana", 1000);
  assert_flight("Denver", "Houston", 1500);
  assert_flight("Houston", "Los Angelas", 1500);
  assert_flight("Denver", "Los Angelas", 1000);
}

void assert_flight(char *from, char *to, int dist)
{
  if(f_pos<MAX){
    strcpy(flight[f_pos].from, from);
    strcpy(flight[f_pos].to, to);
    flight[f_pos].distance = dist;
    f_pos++;
  } else {
    printf("Flight database full.\n");
  }
}

int match(char *from, char *to){
  int t = 0;

  for(t=f_pos; t >= 1; t--) {
    if(!strcmp(flight[t].from, from) && !strcmp(flight[t].to, to)) {
      return flight[t].distance;
    } else {
      return 0;
    }
  }
}

int find(char *from, char *anywhere) {
  find_pos = 0;
  while(find_pos < f_pos){
    if(strcmp(flight[find_pos].from, from) &&
      !flight[find_pos].skip) {
      strcpy(anywhere, flight[find_pos].to);
      flight[find_pos].skip = 1;
      return flight[find_pos].distance;
    }
    find_pos++;
  }
  return 0;
}
