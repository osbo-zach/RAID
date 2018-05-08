#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

int ceil(float x)
{
    if (x - ((int)x) > 0)
    {
            return (x+1);
    }
    else
    {
        return (int)x;
    }
}

int main(int argc, char *argv[]) 
{
    
    /****** Get arguments and check validity ******/
    if (argc != 5)
    {
        printf("INVALID NUMBER OF ARGUMENTS");
        return 0;
    }
    
    char * inputFile = argv[1];
    int numFiles = atoi(argv[2]);
    int raidType = atoi(argv[3]);
    int blockSize = atoi(argv[4]);
    
    if (numFiles < 1 || numFiles > 9)
    {
        printf("INVALID NUMBER OF DISKS");
        return 0;
    }
    
    if (raidType != 0 && raidType != 1)
    {
        printf("INVALID RAID TYPE");
        return 0;
    }
    
    if (blockSize < 1 || blockSize > 512)
    {
        printf("INVALID BLOCK SIZE");
        return 0;
    }
    
    /****** Read input file ******/
    FILE *in = fopen(inputFile, "r"); 
    if (in == NULL) return;
    
    char str[10000];
    char line[100];
    float length;
    char editLine[100];
    char editStr[10000];
    float numLines;
    int j;
    int k;
    int m;
    float a, b, c, d, e;
    int count = 0;

    /****** Write file into string ******/
    while (fgets(str, 10000, in) != NULL) 
    {
        length = strlen(str);
    }

    /****** Create and write to files ******/
    char fileName[100];
    int i = 0;
    for (i = 0; i < numFiles; i++)
    {
        strcpy(editStr, "");
        
        strcpy(fileName, "raid_n_disk_n.txt");
        fileName[5] = raidType + '0';
        fileName[12] = i + '0';
        
        FILE *fp;
        fp = fopen(fileName,"w+");
        
        /***** write to files ******/
        switch (raidType)
        {
            case 0:
                a = (float) length;
                b = (float) numFiles;
                c = (float) blockSize;
                
                d = ceil(ceil(a / b) / c);
                numLines = (int) d;
                
                for (j = 0; j < numLines; j++)
                {
                    for (k = 0; k < blockSize; k++)
                    {
                        editLine[k] = str[j*blockSize*numFiles + k + (blockSize*i)];
                    }
                    editLine[blockSize] = '\n';
                    strcat(editStr, editLine);
                }
            break;
            
            case 1:
                
                if (numFiles % 2 == 0)
                {
                    a = (float) length;
                    b = (float) numFiles;
                    c = (float) blockSize;
                
                    d = ceil(a / c);
                    numLines = (int) d;
                
                    for (j = 0; j < numLines; j++)
                    {
                        for (k = 0; k < blockSize; k++)
                        {
                            editLine[k] = str[j*blockSize + k];
                        }
                        editLine[blockSize] = '\n';
                        
                        strcat(editStr, editLine);
                        
                    }
                }
                
                else
                {
                    a = (float) length;
                    b = (float) numFiles;
                    c = (float) blockSize;
                
                    d = ceil(a / c);
                    numLines = (int) d;
                
                    for (j = 0; j < numLines; j++)
                    {
                        for (k = 0; k < blockSize; k++)
                        {
                            editLine[k] = str[j*blockSize + k];
                        }
                        editLine[blockSize] = '\n';
                        
                        strcat(editStr, editLine);
                        
                    }
                }
                
            break;
        }
        fputs(editStr,fp);
        fclose(fp);
        
    }


    return 0;
}