#include <windows.h>
#include <gl/glut.h>
#include <math.h>
void DDA_Line(int x1, int y1, int x2, int y2) {
    float  epsl, dx, dy;
    float x,y,xIncre,yIncre;
    dx = x2 - x1;   dy = y2 - y1;
    x = x1;         y = y1;

    if (abs(dx) >= abs(dy)) {// |k|<=1
        epsl =abs(dx);} 
    else {// |k|>1
        epsl =abs(dy);
    }
	//x,y的增量，这里使用的是课本上的思路，比较巧妙，适应正负斜率和端点互换。
    xIncre=dx/epsl;	
    yIncre=dy/epsl;


    for (int i = 0; i <= epsl; i++) {// |k|<=1
        glPointSize(5.0);
        glBegin(GL_POINTS);
        glVertex2f(x, int(y + 0.5));
        glEnd();
        x+=xIncre;
        y+=yIncre;
    
    }
}
void display(void) {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glViewport(0, 0, 500, 500);
    //直线起点终点坐标
	 glColor3f(0.0, 0.0, 1.0);//蓝线
     DDA_Line(0,500, 250,0);
     glColor3f(1.0, 0.0, 0.0);//红线
	 DDA_Line(0,0,500,250);
   
	glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RED);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("DDA_line");
    glutDisplayFunc(display);

    //glColor3f(0.0, 0.0, 0.0);//颜色
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);

    glutMainLoop();
    return 0;
}
