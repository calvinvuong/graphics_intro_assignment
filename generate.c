#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int gen_image(int fd, int x_dimen, int y_dimen) {
  char * write_buff = (char *) malloc(x_dimen+5);
  
  // write header
  snprintf(fd, sizeof(write_buff), "P3 %d %d 255\n", x_dimen, y_dimen);
  write(fd, write_buf, sizeof(write_buf));

  // pixel data
  int r, g, b;
  
  // write pixels
  int i, j;
  for ( i = 0; i < x_dimen; i++ ) {
    for ( j = 0; j < y_dimen; j++ ) {
      r = i % 256;
      g = j % 256;
      b = (i+j) % 256;
      
      
    }
  }


}

int main() {
  int XDIMENSION = 75;
  int YDIMENSION = 75;
  // open file
  int fd = open("image.ppm", O_CREAT | O_TRUNC | O_WRONLY, 0644);

  // write file
  gen_image(fd, XDIMENSION, YDIMENSTION);
  
  // close file
  close(fd);
  
  return 0;
}
