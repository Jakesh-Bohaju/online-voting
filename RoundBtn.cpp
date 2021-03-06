
  /************************************************************************
  *************************************************************************
  *****************************  RoundBtn.cpp  ****************************
  *************************************************************************
  ************************************************************************/

  /*************************************************************************

	  By :
		Muhammad Tahir Shahzad  [ MTS ]
		B.C.S Honours  [ 2000-04 ]
		Government College University Lahore
		Pakistan

      E-mail :  mtshome@wol.net.pk

    Web-Site :  www.mts-home.cjb.net  [ www.wol.net.pk/mtshome ]
		www.mtshome.cjb.net   [ www.geocities.com/mtahirshahzad ]

  *************************************************************************/

 /*************************************************************************/
 /*************************************************************************/
 //--------------------------  Header Files  -----------------------------//
 /*************************************************************************/
 /*************************************************************************/

 /*************************************************************************/
 //---------------------------  User Defined  ----------------------------//
 /*************************************************************************/

 # include   "Gui.h"
 # include "Mouse.h"

 /*************************************************************************/
 /*************************************************************************/
 //----------------------  Class Function Definitions  -------------------//
 /*************************************************************************/
 /*************************************************************************/

 /*************************************************************************
  *************************************************************************
  ****************************  RoundButton  ******************************
  *************************************************************************
  ************************************************************************/

 /*************************************************************************/
 //-------------------------  RoundButton( )  ----------------------------//
 /*************************************************************************/

 RoundButton::RoundButton( )
    {
       x_1=0;
       y_1=0;
       x_2=0;
       y_2=0;
       mid_x=0;
       mid_y=0;
       radius=0;
       text_color=0;
       button_color=7;
       red_char_position=0;
       rounded_side=BOTH_SIDES;

       strset(Label,NULL);
    }

 /************************************************************************/
 //-----------------------------  Init( )  ------------------------------//
 /************************************************************************/

 void RoundButton::Init(const int x,const int y,const char* Text,
				const int round_side,const int width,
				      const int height,const int bcolor,
					const int tcolor,const int red_char)
    {
       x_1=x;
       y_1=y;
       text_color=tcolor;
       button_color=bcolor;
       rounded_side=round_side;

       int count=0;

       while(Text[count]==' ')
	  count++;

       red_char_position=count;

       if(red_char!=0)
	  red_char_position=red_char;

       if(strlen(Text)<=25)
	  strcpy(Label,Text);

       else
	  {
	     strncpy(Label,Text,23);
	     strcat(Label,"..");
	  }

       settextstyle(0,0,1);

       x_2=(textwidth(Label)+14+width+x_1);
       y_2=(textheight(Label)+12+height+y_1);

       int y2_y1=(y_2-y_1);

       if((y2_y1%2)==0)
	  {
	     y2_y1-=1;
	     y_2-=1;
	  }

       radius=(y2_y1/2);

       mid_x=(((x_1+x_2)/2)-(textwidth(Label)/2)+1);
       mid_y=(((y_1+y_2)/2)-(textheight(Label)/2)+1);
    }

 /*************************************************************************/
 //------------------------------  Show( )  ------------------------------//
 /*************************************************************************/

 void RoundButton::Show( )
    {
       HideMouse( );
       GetCurrentSettings( );

       setcolor(button_color);
       setfillstyle(1,button_color);
	 bar(x_1,y_1,x_2,y_2);

       if(rounded_side==BOTH_SIDES || rounded_side==LEFT_SIDE)
	  pieslice(x_1,(y_1+radius),0,360,radius);

       if(rounded_side==BOTH_SIDES || rounded_side==RIGHT_SIDE)
	  pieslice(x_2,(y_1+radius),0,360,radius);

       setcolor(15);
	 line(x_1,y_1,x_2,y_1);

       if(rounded_side==BOTH_SIDES || rounded_side==LEFT_SIDE)
	  arc(x_1,(y_1+radius),90,270,radius);

       else
	  line(x_1,y_1,x_1,y_2);

       setcolor(8);
	 line((x_1+1),(y_2-1),x_2,(y_2-1));

       if(rounded_side==BOTH_SIDES || rounded_side==RIGHT_SIDE)
	  arc((x_2-1),(y_1+radius),270,90,radius);

       else
	  line((x_2-1),y_2,(x_2-1),(y_1+1));

       setcolor(0);
	 line(x_1,y_2,x_2,y_2);

       if(rounded_side==BOTH_SIDES || rounded_side==RIGHT_SIDE)
	  arc(x_2,(y_1+radius),270,90,radius);

       else
	 line(x_2,y_2,x_2,y_1);

       int label_size=strlen(Label);

       char Title[35]={NULL};

       if(red_char_position)
	  {
	     for(int count_1=0;count_1<red_char_position;count_1++)
		strcat(Title," ");

	     strrev(Title);
	  }

       char Red_char[5]={NULL};

       Red_char[0]=Label[red_char_position];

       if(red_char_position)
	 strcat(Title,Red_char);

       else
	  Title[0]=Label[0];

       int size=(label_size-1-red_char_position);

       for(int count_2=0;count_2<size;count_2++)
	  strcat(Title," ");

       settextstyle(0,0,1);
	 setcolor(button_color);
	   outtextxy((mid_x+1),(mid_y+1),Label);

       if(button_color==0 && text_color==0)
	  setcolor(15);

       else
	  setcolor(text_color);

       outtextxy(mid_x,mid_y,Label);

       if(button_color==4)
	  setcolor(0);

       else
	  setcolor(4);

       if(red_char_position!=-1)
	  outtextxy(mid_x,mid_y,Title);

       RestorePreviousSettings( );
       ShowMouse( );
    }

 /************************************************************************/
 //-----------------------------  Press( )  -----------------------------//
 /************************************************************************/

 void RoundButton::Press( )
    {
       HideMouse( );
       GetCurrentSettings( );

       setcolor(button_color);
	 line(x_1,y_1,x_2,y_1);
	 line((x_1+1),(y_2-1),x_2,(y_2-1));
	 line(x_1,y_2,x_2,y_2);

       if(rounded_side==BOTH_SIDES || rounded_side==LEFT_SIDE)
	  arc(x_1,(y_1+radius),90,270,radius);

       else
	  line(x_1,y_1,x_1,y_2);

       if(rounded_side==BOTH_SIDES || rounded_side==RIGHT_SIDE)
	  arc((x_2-1),(y_1+radius),270,90,radius);

       else
	  line((x_2-1),y_2,(x_2-1),(y_1+1));

       if(rounded_side==BOTH_SIDES || rounded_side==RIGHT_SIDE)
	  arc(x_2,(y_1+radius),270,90,radius);

       else
	  line(x_2,y_2,x_2,y_1);

       setcolor(15);
	 line(x_1,y_2,x_2,y_2);

       if(rounded_side==BOTH_SIDES || rounded_side==RIGHT_SIDE)
	  arc(x_2,(y_1+radius),270,90,radius);

       else
	  line(x_2,y_2,x_2,y_1);

       setcolor(0);
	 line(x_1,y_1,x_2,y_1);

       if(rounded_side==BOTH_SIDES || rounded_side==LEFT_SIDE)
	  arc(x_1,(y_1+radius),90,270,radius);

       else
	  line(x_1,y_1,x_1,y_2);

       setcolor(8);

       if(rounded_side==BOTH_SIDES || rounded_side==LEFT_SIDE)
	  {
	     arc((x_1+1),(y_1+radius),90,270,radius);

	     line((x_1-1),(y_1+1),(x_2-1),(y_1+1));
	  }

       if(rounded_side==RIGHT_SIDE)
	  {
	     line((x_1+1),(y_1+1),(x_1+1),(y_2-1));
	     line((x_1+1),(y_1+1),(x_2-1),(y_1+1));
	  }

       int label_size=strlen(Label);

       char Title[35]={NULL};

       if(red_char_position)
	  {
	     for(int count_1=0;count_1<red_char_position;count_1++)
		strcat(Title," ");

	     strrev(Title);
	  }

       char Red_char[5]={NULL};

       Red_char[0]=Label[red_char_position];

       if(red_char_position)
	  strcat(Title,Red_char);

       else
	  Title[0]=Label[0];

       int size=(label_size-1-red_char_position);

       for(int count_2=0;count_2<size;count_2++)
	  strcat(Title," ");

       settextstyle(0,0,1);
       setcolor(button_color);
	 outtextxy(mid_x,mid_y,Label);

       if(button_color==0 && text_color==0)
	  setcolor(15);

       else
	  setcolor(0);

       outtextxy((mid_x+1),(mid_y+1),Label);

       if(button_color==4)
	  setcolor(0);

       else
	  setcolor(4);

       if(red_char_position!=-1)
	  outtextxy((mid_x+1),(mid_y+1),Title);

       RestorePreviousSettings( );
       ShowMouse( );
    }

 /************************************************************************/
 //------------------------  PressAndRelease( )  ------------------------//
 /************************************************************************/

 void RoundButton::PressAndRelease(const int pressed_key)
    {
       Press( );

       if(pressed_key==KEY_BOARD)
	  delay(250);

       else if(pressed_key==LEFT_MOUSE_KEY)
	  while(Hit( ) && LeftMouseKeyPressed( ) && !kbhit( ));

       else if(pressed_key==RIGHT_MOUSE_KEY)
	  while(Hit( ) && RightMouseKeyPressed( ) && !kbhit( ));

       Show( );
    }

 /************************************************************************/
 //---------------------------  Hit( )  ---------------------------------//
 /************************************************************************/

 const int RoundButton::Hit( )
    {
       int x=0;
       int y=0;
       int flag=0;

       GetMouseCoordinates(&x,&y);

       if(x>=x_1 && x<=x_2 && y>=y_1 && y<=y_2)
	  flag=1;

       if(rounded_side==BOTH_SIDES || rounded_side==LEFT_SIDE)
	  {
	    double distance=sqrt((powl((x-x_1),2))+(pow((y-(y_1+radius)),2)));

	    if(distance<=radius)
	       flag=1;
	  }

       if(rounded_side==BOTH_SIDES || rounded_side==RIGHT_SIDE)
	  {
	    double distance=sqrt((powl((x-x_2),2))+(pow((y-(y_1+radius)),2)));

	    if(distance<=radius)
	       flag=1;
	  }

       return flag;
    }

 /************************************************************************/
 /************************************************************************/
 //-----------------------------  THE END  ------------------------------//
 /************************************************************************/
 /************************************************************************/
