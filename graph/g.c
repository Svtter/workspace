#include <GL/glut.h>

static GLsizei iMode=1;
static GLfloat xRot=0.0f;
static GLfloat yRot=0.0f;
GLUquadricObj*obj;

void Initial(void)
{
    glClearColor(1.0f,1.0f,1.0f,1.0f);  //设置背景颜色
    glColor3f(0.0f,0.0f,0.0f);  // 设置绘画颜色
    obj=gluNewQuadric();    //激活二次曲面绘画器
    gluQuadricDrawStyle(obj,GLU_LINE);    //以线框的方式绘制二次去面对象
}

void ChangSize(int w,int h)
{
    glViewport(0,0,w,h);//指定窗口显示区域
    glMatrixMode(GL_PROJECTION);   //制定设置投影参数
    glLoadIdentity();   //调用单位矩阵，去掉以前的投影参数设置
    gluOrtho2D(-1.5f,1.5f,-1.5f,1.5f);   //设置投影参数
}


void Display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);  //用当前背景色填充窗口
    glMatrixMode(GL_MODELVIEW);  //制定设置模型视图变换参数
    glLoadIdentity();   //消除以前的变换
    glRotatef(xRot,1.0f,0.0f,0.0f);   //绕X轴旋转图形
    glRotatef(yRot,0.0f,1.0f,0.0f);  //绕y轴旋转图形
    switch(iMode)
    {
        case 1:
            glutWireTetrahedron();break;   //绘制线框正四面体
        case 2:
            glutSolidTetrahedron();break;  //绘制实体正四面体

        case 3:
            glutWireOctahedron();break; //绘制线框正八面体
        case 4:
            glutSolidOctahedron();break;//绘制实体正八面体

        case 5:
            glutWireSphere(1.0f,15,15);break;  //绘制线框球
        case 6:
            glutSolidSphere(1.0f,15,15);break;//绘制实体球

        case 7:
            glutWireTeapot(1.0f);break;   //绘制线框茶壶
        case 8:
            glutSolidTeapot(1.0f);break;//绘制实体茶壶

        case 9:
            gluSphere(obj,1.0f,15,15);break;  //绘制二次曲面（球）

        case 10:
            gluCylinder(obj,1.0f,0.0f,1.0f,15,15);break;//绘制二次曲面（圆锥）

        case 11:
            gluPartialDisk(obj,0.3f,0.8f,15,15,30.0f,260.0f);break;  //绘制二次曲面（圆环）

        default: 
            break;
    }

}


//处理菜单响应
void ProcessMenu(int value)
{
    iMode=value;
    glutPostRedisplay();
}

void SpecialKeys(int key,int x,int y)
{
    //光标键控制图形旋转
    if(key==GLUT_KEY_UP) xRot-=5.0f;
    if(key==GLUT_KEY_DOWN) xRot+=5.0f;
    if(key==GLUT_KEY_LEFT) yRot-=5.0f;
    if(key==GLUT_KEY_RIGHT) yRot+=5.0f;

    if(xRot>356.0f) xRot=0.0f;
    if(xRot<-1.0f) xRot=355.0f;
    if(yRot>356.0f)  yRot=0.0f;
    if(yRot<-1.0f)   yRot=355.0f;
    glutPostRedisplay();
}

int main(int argc,char *argv[])
{
    glutInit(&argc, argv);    //对GLUT库的初始化
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);  //窗口使用ＲＧＢ和单缓存
    glutInitWindowSize(400,400);
    glutInitWindowPosition(100,100);
    glutCreateWindow("OpenGL模型绘制函数示例");
    //创建菜单并定义菜单回调函数
    int nGlutPolyMenu=glutCreateMenu(ProcessMenu); 
    glutAddMenuEntry("线框正四面体",1);    //创建GLUT多面体绘制菜单
    glutAddMenuEntry("实体正四面体",2);
    glutAddMenuEntry("线框正八面体",3);
    glutAddMenuEntry("实体正八面体",4);

    int nGlutCurveMenu=glutCreateMenu(ProcessMenu);  //创建GIUT曲面绘制菜单
    glutAddMenuEntry("线框球面",5);
    glutAddMenuEntry("实体球面",6);
    glutAddMenuEntry("线框茶壶",7);
    glutAddMenuEntry("实体茶壶",8);

    int nGluCurveMenu=glutCreateMenu(ProcessMenu);   //创建GIU曲面绘制菜单
    glutAddMenuEntry("线框球面",9);
    glutAddMenuEntry("线框圆锥体",10);
    glutAddMenuEntry("线框圆环面",11);

    int nMainMenu=glutCreateMenu(ProcessMenu);//创建主菜单
    glutAddSubMenu("GLUT多面体",nGlutPolyMenu);
    glutAddSubMenu("GLUT曲面",nGlutCurveMenu);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutDisplayFunc(Display);
    glutReshapeFunc(ChangSize);
    glutSpecialFunc(SpecialKeys);
    Initial();
    glutMainLoop();
    return 0;
}
