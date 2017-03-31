#include <GL/glut.h>
#include <windows.h>
#include <stdio.h>
#include "math.h"
#include <stdlib.h>

class wcPt2D			//SIMPLE CLASS FOR STORING POINT DATA
{
   public:
      GLfloat x, y;
};

inline GLint round (const GLfloat a)  { return GLint (a + 0.5); }		//FOR MIDPOINTS THAT ARE NOT INTEGER, RETURN ROUNDED UP INT

/*  Define a four-bit code for each of the outside regions of a
 *  rectangular clipping window.
 */
const GLint winLeftBitCode = 0x1;
const GLint winRightBitCode = 0x2;
const GLint winBottomBitCode = 0x4;
const GLint winTopBitCode = 0x8;

inline GLint inside (GLint code) { return GLint (!code); }				//RETURNS 1111 IF AN INSIDE CODE IS GIVEN

inline GLint reject (GLint code1, GLint code2)							//BITWISE AND FOR CHECKING IF LINE IS OUTSIDE
                        { return GLint (code1 & code2); }

inline GLint accept (GLint code1, GLint code2)							//BITWISE OR FOR CHECKING IF LINE IS INSIDE
                        { return GLint (!(code1 | code2)); }



GLubyte encode (wcPt2D pt, wcPt2D winMin, wcPt2D winMax)				//CALCULATE REGION CODE FOR GIVEN LINE
{
  GLubyte code = 0x00;

  if (pt.x < winMin.x)
    code = code | winLeftBitCode;
  if (pt.x > winMax.x)
    code = code | winRightBitCode;
  if (pt.y < winMin.y)
    code = code | winBottomBitCode;
  if (pt.y > winMax.y)
    code = code | winTopBitCode;
  return (code);
}

void swapPts (wcPt2D * p1, wcPt2D * p2)									//SIMPLE SWAP METHODS
{
  wcPt2D tmp;

  tmp = *p1; *p1 = *p2; *p2 = tmp;

}

void swapCodes (GLubyte * c1, GLubyte * c2)
{
  GLubyte tmp;

  tmp = *c1; *c1 = *c2; *c2 = tmp;
}

void lineClipCohSuth (wcPt2D winMin, wcPt2D winMax, wcPt2D p1, wcPt2D p2)
{
  GLubyte code1, code2;
  GLint done = false;
  GLint plotLine = false;

  GLfloat m;

  printf("Input p1x: %f\n", p1.x);								//PRINT INPUT LINE DATA (FOR TESTING)
  printf("Input p1y: %f\n", p1.y);
  printf("Input p2x: %f\n", p2.x);
  printf("Input p2y: %f\n\n", p2.y);

  while (!done) {
    code1 = encode (p1, winMin, winMax);		//ENCODE LINES
    code2 = encode (p2, winMin, winMax);
    if (accept (code1, code2)) {				//IF BOTH POINTS ARE IN CLIPPING WINDOW, DONE - PLOT THE LINE
      done = true;
      plotLine = true;
    }
    else
      if (reject (code1, code2))
        done = true;							//IF BOTH POINTS ARE OUTSIDE, DONE - DO NOT PLOT THE LINE
      else {									//NOW WE KNOW THE LINE AT LEAST PASSES THROUGH THE CLIPPING WINDOW
        /*  Label the endpoint outside the display window as p1. */
        if (inside (code1)) {					//SWAP CODES IF P1 IS INSIDE, FOR CONSISTENCY
          swapPts (&p1, &p2);
          swapCodes (&code1, &code2);
        }
        /*  Use slope m to find line-clipEdge intersection.  */
        if (p2.x != p1.x)
          m = (p2.y - p1.y) / (p2.x - p1.x);		//CALCULATE SLOPE
        if (code1 & winLeftBitCode) {				//IF POINT 1 CODE CONTAINS _ _ _ 1, CLIP THE PORTION TO THE LEFT OF THE LEFT BOUNDARY (WINMIN.X)
          p1.y += (winMin.x - p1.x) * m;
          p1.x = winMin.x;
        }
        else
          if (code1 & winRightBitCode) {			//IF POINT 1 CODE CONTAINS _ _ 1 _, CLIP THE PORTION TO THE RIGHT OF THE RIGHT BOUNDARY (WINMAX.X)
            p1.y += (winMax.x - p1.x) * m;
            p1.x = winMax.x;
          }
          else
            if (code1 & winBottomBitCode) {			//IF POINT 1 CODE CONTAINS _ 1 _ _, CLIP THE PORTION BELOW THE BOTTOM BOUNDARY (WINMIN.Y)
              /*  Need to update p1.x for nonvertical lines only.  */
              if (p2.x != p1.x)
                p1.x += (winMin.y - p1.y) / m;
              p1.y = winMin.y;
            }
            else
              if (code1 & winTopBitCode) {			//IF POINT 1 CODE CONTAINS 1 _ _ _, CLIP THE PORTION ABOVE THE UPPER BOUNDARY (WINMAX.Y)
                if (p2.x != p1.x)
                  p1.x += (winMax.y - p1.y) / m;
                p1.y = winMax.y;
              }
      }
  }
 if (plotLine)
 {
    //lineBres (round (p1.x), round (p1.y), round (p2.x), round (p2.y));
	  printf("Plot p1x: %f\n", p1.x);				//PRINT THE COORDINATES OF THE PLOTTED LINE
	  printf("Plot p1y: %f\n", p1.y);
	  printf("Plot p2x: %f\n", p2.x);
	  printf("Plot p2y: %f\n", p2.y);
 }

 else
 {
	 printf("Do not plot\n");
 }

 printf("\n\n----------\n\n");

}

int main(int argc, char** argv)
{
	wcPt2D wMin = {0.0, 0.0};			//CLIPPING WINDOW (0,0) -> (100,100)
	wcPt2D wMax = {100.0, 100.0};

	wcPt2D test1 = {-10.0,-10.0};		//LINE ONE (-10,10) , (-10,-50)   OUTSIDE
	wcPt2D test2 = {-10.0,-50.0};

	wcPt2D test3 = {20.0, 20.0};		//LINE TWO (20,20) , (30,30)    INSIDE
	wcPt2D test4 = {30.0, 30.0};

	wcPt2D test5 = {20.0, 20.0};		//LINE THREE (20,20) , (120, 20)    PASSES THROUGH RIGHT BOUNDARY
	wcPt2D test6 = {120.0, 20.0};

	lineClipCohSuth(wMin, wMax, test1, test2);

	lineClipCohSuth(wMin, wMax, test3, test4);

	lineClipCohSuth(wMin, wMax, test5, test6);

	return 0;
}
