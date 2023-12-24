#ifndef TYPES_H
#define TYPES_H

typedef enum {
    CAR_NULL, CAR_X, CAR_A, CAR_B, CAR_C, CAR_D, CAR_E, CAR_F, CAR_G,
    CAR_H, CAR_I, CAR_J, CAR_K, CAR_O, CAR_P, CAR_Q, CAR_R, CAR_NUM
}CarIndex;

typedef struct{
    CarIndex index;
    char letter;
    Color color;
}Car;

const Car carArr[CAR_NUM] = {
    {
        CAR_NULL,
        ' ',
        GREY1
    },{
        CAR_X,
        'X',
        {0xee, 0x21, 0x26, 0xff}
    },{
        CAR_A,
        'A',
        {0x90, 0xcc, 0x86, 0xff}
    },{
        CAR_B,
        'B',
        {0xf6, 0x85, 0x29, 0xff}
    },{
        CAR_C,
        'C',
        {0x24, 0xbb, 0xf0, 0xff}
    },{
        CAR_D,
        'D',
        {0xef, 0x7d, 0xa1, 0xff}
    },{
        CAR_E,
        'E',
        {0x67, 0x63, 0xad, 0xff}
    },{
        CAR_F,
        'F',
        {0x0f, 0x98, 0x6c, 0xff}
    },{
        CAR_G,
        'G',
        {0xd8, 0xd9, 0xdb, 0xff}
    },{
        CAR_H,
        'H',
        {0xfd, 0xe5, 0xc3, 0xff}
    },{
        CAR_I,
        'I',
        {0xfe, 0xf4, 0x54, 0xff}
    },{
        CAR_J,
        'J',
        {0x90, 0x65, 0x55, 0xff}
    },{
        CAR_K,
        'K',
        {0x8a, 0x8d, 0x08, 0xff}
    },{
        CAR_O,
        'O',
        {0xfa, 0xd2, 0x01, 0xff}
    },{
        CAR_P,
        'P',
        {0xa1, 0x7f, 0xbb, 0xff}
    },{
        CAR_Q,
        'Q',
        {0x0d, 0x7e, 0xc2, 0xff}
    },{
        CAR_R,
        'R',
        {0x0c, 0xaf, 0x9c, 0xff}
    }
};

#define BOARDLEN    6
#define SCALEMIN    3

typedef struct{
    Offset off;                         // pixel offset to top left square of board so that board remains centered
    int scale;                          // length in pixles of one board square
    bool carActive[CAR_NUM];            // true if respective car index appears on board
    uint numCars;                       // number of active cars on board
    CarIndex selected;                  // index of selected car or CAR_NULL if none selected
    CarIndex square[CAR_NUM][CAR_NUM];  // car index of each grid square. CAR_NULL if empty
    Coord updatepos;                    // mouse pos where last update occured
}Board;

#endif /* end of include guard: TYPES_H */
