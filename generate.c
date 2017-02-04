#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>

int gen_image(int fd, int x_dimen, int y_dimen) {

  srand(time(NULL));
  
  char * write_buf = (char *) malloc(50);
  
  // write header
  sprintf(write_buf, "P3 %d %d 255\n", x_dimen, y_dimen);
  write(fd, write_buf, strlen(write_buf));

  // pixel data
  int r, g, b;
  
  // write pixelS
  int i, j;
  for ( i = 0; i < x_dimen; i++ ) {
    for ( j = 0; j < y_dimen; j++ ) {
      // generate RGB values
      r = ( i + (rand() % 50) ) % 256;
      g = ( j + (rand() % 50) ) % 256;
      b = ( abs(r - g) / 2 + (rand() % 50) ) % 256;

      
      // write
      sprintf(write_buf, "%d %d %d\n", r, g, b);
      write(fd, write_buf, strlen(write_buf));      
    }
  }
  free(write_buf);
  return 0;
}

int main() {

  int XDIMENSION = 500;
  int YDIMENSION = 500;

  // open file
  int fd = open("image.ppm", O_CREAT | O_TRUNC | O_WRONLY, 0644);

  // write file
  gen_image(fd, XDIMENSION, YDIMENSION);
  
  // close file
  close(fd);
  
  return 0;
}
