#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<bios.h>
#include<dos.h>
#include "dosfetch.h"

int read_art(char* filename){
    FILE *f = fopen(filename, "r");
    if(f == NULL){
        return 0;
    }
    for(int i =0;i < ASCII_ART_HEIGHT; i++){
        if(!feof(f)){
            fgets(ascii_art[i],ASCII_ART_WIDTH,f);
        }
        else{
            ascii_art[i][0] = "                     ";
        }
    }
    return 1;
}

int main(int argc, char* argv[]){
    //Reading what the BIOS has to tell us about the equipment
    be_t equip;
    int biosequipment = biosequip();
    memcpy(&biosequipment, &equip,sizeof(be_t));
    // Loading custom art if something is passed in the cmdline parameters
    if (argc == 2){
        if (!read_art(argv[1])){
            printf("Cannot find %s .\n",argv[1]);
        }
    }
    printf("%sOS:",ascii_art[0]);
    system("ver"); // evil hack due to my incompetence into determining the version of DOS
    printf("%sMEMORY SIZE: %u k\n",ascii_art[1],biosmemory());//this way we are limited to conventional memory
    if(equip.fpu)
        printf("%sFPU: Installed\n",ascii_art[2]);
    else
        printf("%sFPU: Not Installed\n",ascii_art[2]);
    printf("%sDRIVES: %u\n",ascii_art[3],equip.diskdrives+1);
    if(equip.noDMA)
        printf("%sDMA: No\n",ascii_art[4]);
    else
        printf("%sDMA: Yes\n",ascii_art[4]);
    printf("%sCOM PORTS: %u\n",ascii_art[5],equip.comports);
    printf("%sPRINTERS: %u\n",ascii_art[6],equip.printers);
    switch(equip.vidmode){
        case 0x01: printf("%sVIDEO MODE: 40 Columns\n",ascii_art[7]);break;
        case 0x02: printf("%sVIDEO MODE: 80 Columns\n",ascii_art[7]);break;
        case 0x03: printf("%sVIDEO MODE: Monocromatic\n",ascii_art[7]);break;
        default: printf("%sVIDEO MODE: Unknown(%u)\n",ascii_art[7],equip.vidmode);break;
    }
    printf("%s\n%s\n%s\n",ascii_art[8],ascii_art[9],ascii_art[10]);
    return 0;
}
