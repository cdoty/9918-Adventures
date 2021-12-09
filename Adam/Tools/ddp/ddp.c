/* Simple DDP tool */

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

unsigned char bootblock[1024];
unsigned char tapebuffer[262144];

int main(int argc, char* argv[])
{
  FILE *dfp, *bfp, *pfp;
  int len=0;
  
  if (argc < 3)
    {
      printf("%s boot.bin program.bin out.ddp\n",argv[0]);
      exit(1);
    }

  // Append boot block to tape buffer
  bfp = fopen(argv[1],"rb");
  if (!bfp)
    {
      perror("open boot");
      exit(1);
    }
  fread(bootblock,sizeof(unsigned char),sizeof(bootblock),bfp);
  fclose(bfp);
  memcpy(&tapebuffer[0],bootblock,sizeof(bootblock));
  
  // Append program to tape buffer
  pfp = fopen(argv[2],"rb");
  if (!pfp)
    {
      perror("open program");
      exit(1);
    }
  fread(&tapebuffer[1024],sizeof(unsigned char),sizeof(tapebuffer)-1024,pfp);
  fclose(pfp);

  // Write out tape buffer
  dfp = fopen(argv[3],"wb");
  if (!dfp)
    {
      perror("open ddp");
      exit(1);
    }
  fwrite(tapebuffer,sizeof(unsigned char),sizeof(tapebuffer),dfp);
  fclose(dfp);

  return 0;
}
