#define ASCII_ART_HEIGHT 11
#define ASCII_ART_WIDTH 22

typedef struct{
    unsigned int disk :1;
    unsigned int fpu :1;
    unsigned int sysmem :2;
    unsigned int vidmode :2;
    unsigned int diskdrives:2;
    unsigned int noDMA:1;
    unsigned int comports :3;
    unsigned int gameport : 1;
    unsigned int modemprinter :1;
    unsigned int printers: 2;
} be_t;

char ascii_art[ASCII_ART_HEIGHT][ASCII_ART_WIDTH] = {
    " ::::   ::::  :::::  ", // [0]
    " ::  : ::  :: ::     ", // [1]
    " ::  : ::  :: :::::  ", // [2]
    " ::  : ::  ::    ::  ", // [3]
    " ::::   ::::  :::::  ", // [4]
    "                     ", // [5]
    " ::::   ::::  :: ::  ", // [6]
    " ::  : ::  :: :: ::  ", // [7]
    " ::::  ::  ::  :::   ", // [8]
    " ::  : ::  :: :: ::  ", // [9]
    " ::::   ::::  :: ::  "  // [10]
};

