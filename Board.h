#ifndef BOARD_H
#define BOARD_H

void boardRescale(Board *board)
{
    const Length winlen = getWindowLen();
    board->scale = imax(coordMin(winlen) / BOARDLEN, 1);
    board->off = coordDivi(coordAddi(winlen, board->scale * -BOARDLEN), 2);
}

void boardDraw(Board *board)
{
    setColor(GREY2);
    fillSquareCoord(board->off, board->scale * BOARDLEN);
    const int gridSpaceLen = -imax(board->scale/8, 4);
    for(uint x = 0; x < BOARDLEN; x++){
        for(uint y = 0; y < BOARDLEN; y++){
            const Coord winpos = coordAdd(coordMuli((Coord){.x=x,.y=y}, board->scale), board->off);
            setColor(GREY1);
            fillBorderCoordSquare(winpos, board->scale, gridSpaceLen);
            if(board->square[x][y] > CAR_NULL){
                setColor(board->selected != CAR_NULL && board->selected == board->square[x][y] ? WHITE : BLACK);
                fillSquareCoordResize(winpos, board->scale, gridSpaceLen/4);
                setColor(carArr[board->square[x][y]].color);
                fillSquareCoordResize(winpos, board->scale, gridSpaceLen/2);
                if(x > 0 && board->square[x][y] == board->square[x-1][y]){
                    setColor(board->selected != CAR_NULL && board->selected == board->square[x][y] ? WHITE : BLACK);
                    fillSquareCoordResize(coordShift(winpos, DIR_L, board->scale/2), board->scale, gridSpaceLen/2);
                    setColor(carArr[board->square[x][y]].color);
                    fillSquareCoordResize(coordShift(winpos, DIR_L, board->scale/2), board->scale, gridSpaceLen);
                }
                if(y > 0 && board->square[x][y] == board->square[x][y-1]){
                    setColor(board->selected != CAR_NULL && board->selected == board->square[x][y] ? WHITE : BLACK);
                    fillSquareCoordResize(coordShift(winpos, DIR_U, board->scale/2), board->scale, gridSpaceLen/2);
                    setColor(carArr[board->square[x][y]].color);
                    fillSquareCoordResize(coordShift(winpos, DIR_U, board->scale/2), board->scale, gridSpaceLen);
                }
            }
        }
    }
}

Coord boardPos(Board *board, const Coord winpos)
{
    return coordDivi(coordSub(winpos, board->off), board->scale);
}

#endif /* end of include guard: BOARD_H */
