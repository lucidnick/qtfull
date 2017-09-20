
#include "myglwidget.h"
#include <QKeyEvent>

#include <GL/gl.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

//=================william test===============
////Define
typedef long Latitude;
typedef long Longitude;
////Constant
//    //Trigonometric function
//const GLfloat Pi = 3.1415926536f;
//const GLfloat R = 100.0f;
//    //Coordinate transfer
const Latitude     iNFLocalX= 250751; // Location, unit:1md
const Longitude    iNFLocalY=1215751;
//
//const int iHeading1 =200;
//const int iHeading2 =400;
//const int iSpeed =10;
////Global Variable
////Windows setting
int iWsizeX=1024;
int iWsizeY=768;
//int iWposX=100;
//int iWposY=50;
////Mouse setting
//int old_rot_x=0;   //剛按下滑鼠時的視窗座標 
//int old_rot_y=0; 
//
//int rot_x=0;      //拖曳後的相對座標，用這決定要旋轉幾度 
//int rot_y=0; 
//
//int record_x=0;      //紀錄上一次旋轉的角度 
//int record_y=0; 
////View setting
int iViewType=0;
////HV FOV    
//    //To do: 橢圓形, 2d coordinate to GPS coordinate
//float fHVfovX=0.0;
//float fHVfovY=0.0;
////HV BSM informatino
////PH_CONCISE_DATA HV_BSM; //interg later....
//Latitude     iHVlat      = iNFLocalX;    //1 Unit=1/10 millidegree
//Longitude    iHVlon      = iNFLocalY;    //1 Unit=1/10 millidegree
//Elevation    iHVele      = 0;    //1 Unit=10 cm
//Speed        iHVspeed    = 0;    //1 Unit=0.02 m/s
//Heading      iHVheading  = 0;    //1 Unit=0.0125 degree
///*
//float fHVposX=0.0;
//float fHVposY=0.0;
//float fHVposZ=0.0;
//float fHVspeed=0.0;
//float fHVheading=0.0;
//*/
//int iHeadingArrowLength=20;
//int iHeadingArrowHigh=8;
//int iHeadingArrowWidth=3;
////RV position
//float fRVposX_1=0.0;
//float fRVposY_1=0.0;
//float fRVposX_2=0.0;
//float fRVposY_2=0.0;
//float fRVposX_3=0.0;
//float fRVposY_3=0.0;
//float fRVposX_4=0.0;
//float fRVposY_4=0.0;
//float fRVposX_5=0.0;
//float fRVposY_5=0.0;
//float fRVposX_6=0.0;
//float fRVposY_6=0.0;
//float fRVposX_7=0.0;
//float fRVposY_7=0.0;
//float fRVposX_8=0.0;
//float fRVposY_8=0.0;
//float fRVposX_9=0.0;
//float fRVposY_9=0.0;
//float fRVposX_10=0.0;
//float fRVposY_10=0.0;
////BSM record
//struct point3f{
//	float val[3];
//};
//
//struct pointGNSS{
//    Latitude NewLat;
//    Longitude NewLon;
//};
//    //HV
//
//HV_BSMData RecordData;
//HV_BSMData RecordData2;
//    //RV
//
////Text 
//int text_x = 0, text_y = 0;
//char text[] = "";
////Time
//struct timeb tPre, tNow, tTemp;

void Draw(void);                             
void Draw_Road(void);                       
//=================william test===============

void Draw_Road(void)
{
    //Draw Road lane (3m/lane, 0.1m/pix)
    glLineWidth(2.0); 
    //Main lane
    glColor3ub(211, 211, 211);
    glBegin(GL_LINES);
    glVertex3f(iNFLocalX+15.0, iNFLocalY+(iWsizeY), 0.0);
    glVertex3f(iNFLocalX+15.0, iNFLocalY-(iWsizeY), 0);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(iNFLocalX-15.0, iNFLocalY+(iWsizeY), 0.0);
    glVertex3f(iNFLocalX-15, iNFLocalY-(iWsizeY), 0);
    glEnd();
    //Right lane
    glBegin(GL_LINES);
    glVertex3f(iNFLocalX+45.0, iNFLocalY+(iWsizeY), 0.0);
    glVertex3f(iNFLocalX+45.0, iNFLocalY-(iWsizeY), 0);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(iNFLocalX+75.0, iNFLocalY+(iWsizeY), 0.0);
    glVertex3f(iNFLocalX+75, iNFLocalY-(iWsizeY), 0);
    glEnd();
    //Left lane
    glBegin(GL_LINES);
    glVertex3f(iNFLocalX-45.0, iNFLocalY+(iWsizeY), 0.0);
    glVertex3f(iNFLocalX-45.0, iNFLocalY-(iWsizeY), 0);
    glEnd();

    //Center line
    glColor3ub(84, 255, 159);
    glBegin(GL_LINES);
    glVertex3f(iNFLocalX-75.0, iNFLocalY+(iWsizeY), 0.0);
    glVertex3f(iNFLocalX-75, iNFLocalY-(iWsizeY), 0);
    glEnd();
    //Opposite lane
    glColor3ub(135, 206, 235);
    glBegin(GL_LINES);
    glVertex3f(iNFLocalX-105.0, iNFLocalY+(iWsizeY), 0.0);
    glVertex3f(iNFLocalX-105.0, iNFLocalY-(iWsizeY), 0);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(iNFLocalX-135.0, iNFLocalY+(iWsizeY), 0.0);
    glVertex3f(iNFLocalX-135, iNFLocalY-(iWsizeY), 0);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(iNFLocalX-165.0, iNFLocalY+(iWsizeY), 0.0);
    glVertex3f(iNFLocalX-165.0, iNFLocalY-(iWsizeY), 0);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(iNFLocalX-195.0, iNFLocalY+(iWsizeY), 0.0);
    glVertex3f(iNFLocalX-195, iNFLocalY-(iWsizeY), 0);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(iNFLocalX-225.0, iNFLocalY+(iWsizeY), 0.0);
    glVertex3f(iNFLocalX-225, iNFLocalY-(iWsizeY), 0);
    glEnd();
    //Cross lane
	glColor3ub(238, 238, 0);
    glBegin(GL_LINES);
    glVertex3f(iNFLocalX+(iWsizeX), iNFLocalY-100, 0.0);
    glVertex3f(iNFLocalX-(iWsizeX), iNFLocalY-100, 0);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(iNFLocalX+(iWsizeX), iNFLocalY-130, 0.0);
    glVertex3f(iNFLocalX-(iWsizeX), iNFLocalY-130, 0);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3f(iNFLocalX+(iWsizeX), iNFLocalY+200, 0.0);
    glVertex3f(iNFLocalX-(iWsizeX), iNFLocalY+200, 0);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(iNFLocalX+(iWsizeX), iNFLocalY+230, 0.0);
    glVertex3f(iNFLocalX-(iWsizeX), iNFLocalY+230, 0);
    glEnd();
}
MyGLWidget::MyGLWidget(QWidget *parent) :  
    QGLWidget(parent)
{  
    fullscreen = false;  
}  

MyGLWidget::~MyGLWidget()  
{  
      
}  

void MyGLWidget::initializeGL()                         //此处开始对OpenGL进行所以设置  
{  
    glClearColor(0.0, 0.0, 0.0, 0.0);                   //黑色背景  
    glShadeModel(GL_SMOOTH);                            //启用阴影平滑  
      
    glClearDepth(1.0);                                  //设置深度缓存  
    glEnable(GL_DEPTH_TEST);                            //启用深度测试  
    glDepthFunc(GL_LEQUAL);                             //所作深度测试的类型  
    //glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  //告诉系统对透视进行修正  
}  

void MyGLWidget::resizeGL(int w, int h)                 //重置OpenGL窗口的大小  
{  
    printf("目前視窗大小為%dX%d\n",w,h);
    glClearColor(0.0, 0.0, 0.0, 0.0);
	glViewport(0, 0, w, h);              //當視窗長寬改變時，畫面也跟著變
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho((iNFLocalX-(iWsizeX)), iNFLocalX+(iWsizeX), iNFLocalY-(iWsizeY), iNFLocalY+(iWsizeY), -1.0, 100.0);  //正交投影: 視野
	//glOrtho((250751-(w)), 250751+(w), 1215751-(h), 1215751+(h), -1.0, 100.0);  //正交投影: 視野
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
    /*
    glViewport(0, 0, (GLint)w, (GLint)h);               //重置当前的视口  
    glMatrixMode(GL_PROJECTION);                        //选择投影矩阵  
    glLoadIdentity();                                   //重置投影矩阵  
    //设置视口的大小
    //https://stackoverflow.com/questions/2417697/gluperspective-was-removed-in-opengl-3-1-any-replacements
    // The following code is a fancy bit of math that is eqivilant to calling:
    // gluPerspective( fieldOfView/2.0f, width/height , 0.1f, 255.0f )
    // We do it this way simply to avoid requiring glu.h
    GLfloat zNear = 0.1f;
    GLfloat zFar = 100.0f;
    GLfloat aspect = float(w)/float(h);
    GLfloat fH = tan( float(45.0f / 360.0f * 3.14159f) ) * zNear;
    GLfloat fW = fH * aspect;
    glFrustum( -fW, fW, -fH, fH, zNear, zFar );

    //gluPerspective(45.0, (GLfloat)w/(GLfloat)h, 0.1, 100.0);// <---samchen marked out.....no glut
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    */
}  

void MyGLWidget::paintGL()                              //从这里开始进行所以的绘制  
{  
    glClearColor(1.0, 1.0, 1.0, 1.0);   //Background with white
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    //switch(iViewType)
    //{
    //    case 0:
    //       glMatrixMode(GL_PROJECTION);
    //       glLoadIdentity();
    //       glOrtho((iNFLocalX-(iWsizeX)), iNFLocalX+(iWsizeX), iNFLocalY-(iWsizeY), iNFLocalY+(iWsizeY), -1.0, 100.0);  //正交投影: 視野
    //       glMatrixMode(GL_MODELVIEW);
    //       glLoadIdentity();
    //    break;
    //    case 1:
    //       glMatrixMode(GL_PROJECTION);
    //       glLoadIdentity();
    //       glOrtho((iHVlat-(iWsizeX)), iHVlat+(iWsizeX), iHVlon-(iWsizeY), iHVlon+(iWsizeY), -1.0, 100.0);  //正交投影: 視野
    //       glMatrixMode(GL_MODELVIEW);
    //       glLoadIdentity();
    //    break;
    //}
    Draw_Road();    //Draw road line
    //Draw_Car();     //Draw cars
    //Draw_Text();    //Draw text for car info.
    //Draw_HV_Path();
    glFlush();

    /*
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //清除屏幕和深度缓存  
    glLoadIdentity();                                   //重置当前的模型观察矩阵 

    glTranslatef(-1.5f, 0.0f, -6.0f);                   //左移1.5单位，并移入屏幕6.0单位  
    glBegin(GL_TRIANGLES);                              //开始绘制三角形  
        glVertex3f(0.0f, 1.0f, 0.0f);                   //上顶点  
        glVertex3f(-1.0f, -1.0f, 0.0f);                 //左下  
        glVertex3f(1.0f, -1.0f, 0.0f);                  //右下  
    glEnd();                                            //三角形绘制结束  
  
    glTranslatef(3.0f, 0.0f, 0.0f);                     //右移3.0单位  
    glBegin(GL_QUADS);                                  //开始绘制四边形  
        glVertex3f(-1.0f, 1.0f, 0.0f);                  //左上  
        glVertex3f(1.0f, 1.0f, 0.0f);                   //右上  
        glVertex3f(1.0f, -1.0f, 0.0f);                  //左下  
        glVertex3f(-1.0f, -1.0f, 0.0f);                 //右下  
    glEnd();                                            //四边形绘制结束   
    */
}  

void MyGLWidget::keyPressEvent(QKeyEvent *event)  
{  
    //Todo: Add system log and file read/write
    //printf("你所按按鍵的碼是%x\t此時視窗內的滑鼠座標是(%d,%d)\n", key, x, y);
    //FILE * pFile;
//Test combo key for QT-Start
    if(event->modifiers()==Qt::ControlModifier && event->key()==Qt::Key_V)
    {
        printf("按下Ctrl+V\n");
    }
//Test combo key for QT-END
    switch (event->key())   
    {     
        //QT Key define: http://doc.qt.io/qt-4.8/qt.html
        case Qt::Key_F1:  
            fullscreen = !fullscreen;  
            if (fullscreen)  
            {  
                showFullScreen();  
            }  
            else  
            {  
                showNormal();  
            }  
            updateGL();  
        break;  
   
   //    case Qt::Key_Q:
   //        if(iHVheading==0)
   //        {
   //            iHVheading=28800-iHeading2;
   //        }else
   //        {
   //             iHVheading=iHVheading-iHeading2;
   //        }
   //        printf("Heading-%d %d\n",iHeading2,iHVheading);
   //       break;
   //    case Qt::Key_A:
   //        if(iHVheading==0)
   //        {
   //            iHVheading=28800-iHeading1;
   //        }else
   //        {
   //             iHVheading=iHVheading-iHeading1;
   //        }
   //        printf("Heading-%d %d\n",iHeading1,iHVheading);
   //       break;
   //case Qt::Key_S:
   //    if(iHVspeed<=0)
   //    {
   //        iHVspeed=0;
   //    }else
   //    {
   //         iHVspeed=iHVspeed-iSpeed;
   //    }
   //    printf("Speed-%d %d\n",iSpeed,iHVspeed);
   //   break;
   //case Qt::Key_D:
   //    if(iHVheading==28800)
   //    {
   //        iHVheading=0+iHeading1;
   //    }else
   //    {
   //         iHVheading=iHVheading+iHeading1;
   //    }
   //    printf("Heading+%d %d\n",iHeading1,iHVheading);
   //   break;
   // case Qt::Key_E:
   //    if(iHVheading==28800)
   //    {
   //        iHVheading=0+iHeading2;
   //    }else
   //    {
   //         iHVheading=iHVheading+iHeading2;
   //    }
   //    printf("Heading+%d %d\n",iHeading2,iHVheading);
   //   break;
   // case Qt::Key_W:
   //     iHVspeed=iHVspeed+iSpeed;
   //     printf("Speed+%d %d\n",iSpeed,iHVspeed);
   //   break;
   // case Qt::Key_F:
   //     printf("Safe HV path file to \n");
   //     //pFile = fopen ("HVPath.txt","w");
   //     //if (pFile!=NULL)
   //     //{
   //     //    for(int i=0;i<MaxRecord;i++)
   //     //        fwrite (&RecordData.bsmdata[i] ,1, sizeof(RecordData.bsmdata[i]), pFile);
   //     //    fclose (pFile);
   //     //}
   //   break;
   // case Qt::Key_G:
   //     printf("Safe HV path file to \n");
   //     //pFile = fopen ("HVPath.txt","r");
   //     //if (pFile!=NULL)
   //     //{
   //     //    for(int i=0;i<MaxRecord;i++)
   //     //        fread (&RecordData2.bsmdata[i] ,1, sizeof(RecordData.bsmdata[i]), pFile);
   //     //    fclose (pFile);
   //     //}
   //   break;

   //case Qt::Key_J:
   //     printf("Left\n");
   //     fRVposX_8=fRVposX_8-1;
   //   break;
   //case Qt::Key_K:
   //     printf("Down\n");
   //     fRVposY_8=fRVposY_8-1;
   //   break;
   //case Qt::Key_L:
   //     printf("Right\n");
   //     fRVposX_8=fRVposX_8+1;
   //   break;
   // case Qt::Key_I:
   //     printf("Up\n");
   //     fRVposY_8=fRVposY_8+1;
   //   break;

       case Qt::Key_1:
     	      if(iViewType==1)
           {
               iViewType=0;
               printf("Return God view\n");
           }else
           {
               iViewType=1;
               printf("Fllow HV God view\n");
           }
          break;
       case Qt::Key_2:
           if(iViewType==2)
           {
               iViewType=0;
               printf("Return God view\n");
           }else
           {
               iViewType=2;
               printf("HV view\n");
           }
          break;
   //case Qt::Key_3:
   //    if(iViewType==3)
   //    {
   //        iViewType=0;
   //        printf("Return God view\n");
   //    }else
   //    {
   //        iViewType=3;
   //        printf("HV driver view\n");
   //    }
   //   break;
        case Qt::Key_Escape:  
            close();  
        break;
        default:
            printf("Unknow key\n");
        break;
   }
   /*if(iHVheading<0||iHVheading>(28800))
   {
       printf("Error: Heading out of range!!!\n");
       iHVheading=0;
   }*/



}  


