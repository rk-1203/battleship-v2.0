#include <graphics.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
int main_page();
int game_page();
int setting_page();
int difficulty_page();
int checkbox(int mat[][10],int,int,int, int dis1[][10],int dis[][10]);
int show(int,int,int,int,int [][10],int ,int, int,int);
void move_ships(int);
class ship_details;

//int player1[10][10],player2[10][10],discover1[10][10],discover2[10][10];
int gridsize_flag=6,topleftx,toplefty,bottomrightx,bottomrighty,hitarray[100][4],missarray[100][4],ind=0,t,c1,c2,ship_index=0;

class ship_details
{
	public :
		
		int x1,x2,y1,y2;
		int length,isAttacked;
		int dir[4];
		
		ship_details()
		{
			dir[0]=0;
			dir[1]=0;
			dir[2]=0;
			dir[3]=0;
			length = 0;
			isAttacked = 0; //0 : not attacked , 1 : attacked
			x1=x2=y1=y2= -1;
		}
		
		bool insideMe(int i,int j)
		{
			if(i==x1 && i==x2 && j>=min(y1,y2) && j<=max(y1,y2))
				return true;
			else if(j==y1 && j==y2 && i>=min(x1,x2) && i<=max(x1,x2))
				return true;
			else
				return false;
		}
};


ship_details p1ship[10],p2ship[10];

void move_ships(int flag,int player[][10],int discover[][10])
{
	int i,j,tempx,tempy,fx=0;
	int hash[2][4]={{0,0,-1,1},{1,-1,0,0}};
	if(flag==1)
	{
		for(i=0;i<ship_index;i++)
		{
			fx = 0;
			if(p1ship[i].dir[0]==1 && fx == 0)
			{
				tempx = p1ship[i].x1;
				tempy = max(p1ship[i].y1,p1ship[i].y2)+1;
				
				if(tempy<gridsize_flag && (player[tempx][tempy]==0) && (discover[tempx][tempy]==1) && (p1ship[i].isAttacked==0))
				{
					player[tempx][tempy] = 1;
					player[tempx][min(p1ship[i].y1,p1ship[i].y2)] = 0;
					p1ship[i].y1++;
					p1ship[i].y2++;
					fx = 1;
				}
			}
			if(p1ship[i].dir[1]==1 && fx == 0)
			{
				tempx = p1ship[i].x1;
				tempy = min(p1ship[i].y1,p1ship[i].y2)-1;
				
				if(tempy>=0 && (player[tempx][tempy]==0) && (discover[tempx][tempy]==1) && (p1ship[i].isAttacked==0))
				{
					player[tempx][tempy] = 1;
					player[tempx][max(p1ship[i].y1,p1ship[i].y2)] = 0;
					p1ship[i].y1--;
					p1ship[i].y2--;
					fx = 1;
				}
			}
			if(p1ship[i].dir[2]==1 && fx == 0)
			{
				tempx = min(p1ship[i].x1,p1ship[i].x2)-1;
				tempy = p1ship[i].y1;
				
				if(tempx>=0 && (player[tempx][tempy]==0) && (discover[tempx][tempy]==1) && (p1ship[i].isAttacked==0))
				{
					player[tempx][tempy] = 1;
					player[max(p1ship[i].x1,p1ship[i].x2)][tempy] = 0;
					p1ship[i].x1--;
					p1ship[i].x2--;
					fx = 1;
				}
			}
			if(p1ship[i].dir[3]==1 && fx == 0)
			{
				tempx = max(p1ship[i].x1,p1ship[i].x2)+1;
				tempy = p1ship[i].y1;
				
				if(tempx<gridsize_flag && (player[tempx][tempy]==0) && (discover[tempx][tempy]==1) && (p1ship[i].isAttacked==0))
				{
					player[tempx][tempy] = 1;
					player[min(p1ship[i].x1,p1ship[i].x2)][tempy] = 0;
					p1ship[i].x1++;
					p1ship[i].x2++;
					fx = 1;
				}
			}
		}
	}
	else
	{
		for(i=0;i<ship_index;i++)
		{
			fx = 0;
			if(p2ship[i].dir[0]==1 && fx == 0)
			{
				tempx = p2ship[i].x1;
				tempy = max(p2ship[i].y1,p2ship[i].y2)+1;
				
				if(tempy<gridsize_flag && (player[tempx][tempy]==0) && (discover[tempx][tempy]==1) && (p2ship[i].isAttacked==0))
				{
					player[tempx][tempy] = 1;
					player[tempx][min(p2ship[i].y1,p2ship[i].y2)] = 0;
					p2ship[i].y1++;
					p2ship[i].y2++;
					fx = 1;
				}
			}
			if(p2ship[i].dir[1]==1 && fx == 0)
			{
				tempx = p2ship[i].x1;
				tempy = min(p2ship[i].y1,p2ship[i].y2)-1;
				
				if(tempy>=0 && (player[tempx][tempy]==0) && (discover[tempx][tempy]==1) && (p2ship[i].isAttacked==0))
				{
					player[tempx][tempy] = 1;
					player[tempx][max(p2ship[i].y1,p2ship[i].y2)] = 0;
					p2ship[i].y1--;
					p2ship[i].y2--;
					fx = 1;
				}
			}
			if(p2ship[i].dir[2]==1 && fx == 0)
			{
				tempx = min(p2ship[i].x1,p2ship[i].x2)-1;
				tempy = p2ship[i].y1;
				
				if(tempx>=0 && (player[tempx][tempy]==0) && (discover[tempx][tempy]==1) && (p2ship[i].isAttacked==0))
				{
					player[tempx][tempy] = 1;
					player[max(p2ship[i].x1,p2ship[i].x2)][tempy] = 0;
					p2ship[i].x1--;
					p2ship[i].x2--;
					fx = 1;
				}
			}
			if(p2ship[i].dir[3]==1 && fx == 0)
			{
				tempx = max(p2ship[i].x1,p2ship[i].x2)+1;
				tempy = p2ship[i].y1;
				
				if(tempx<gridsize_flag && (player[tempx][tempy]==0) && (discover[tempx][tempy]==1) && (p2ship[i].isAttacked==0))
				{
					player[tempx][tempy] = 1;
					player[min(p2ship[i].x1,p2ship[i].x2)][tempy] = 0;
					p2ship[i].x1++;
					p2ship[i].x2++;
					fx = 1;
				}
			}
		}
	}
}

int make_ship(int ship[][10],int length,int f)
{
	
//	printf("length=%d\n",length);
	int direction,i,hash[3][4]={{0,0,-1,1},{1,-1,0,0},{0,0,0,0}},tempx,tempy,j,flag=0,x,y;
	x = rand()%gridsize_flag;
	y= rand()%gridsize_flag;
	while(ship[x][y]!=0)
	{
		
		x = rand()%gridsize_flag;
		//srand(time(NULL));
		y= rand()%gridsize_flag;
	}
    printf("##");
//	printf("r1=%d, r2=%d\n",x,y);
	direction=rand()%4;
//	printf("--------------------direction=%d\n",direction);
	for(i=0;i<4;i++)
	{
//		printf("random direction =%d\n",direction);
		hash[2][direction]=1;
		tempx=x;
		tempy=y;
		flag=0;
		for(j=0;j<length;j++)
		{
//			printf("tempx=%d,tempy=%d\n",tempx,tempy);
			if(tempx>=gridsize_flag || tempy>=gridsize_flag ||  tempx<0 || tempy<0 || ship[tempx][tempy]!=0)
			{
				flag=1;
				break;
			}
			tempx+=hash[0][direction];
			tempy+=hash[1][direction];
		}
		
		if(flag==0)
		{
			tempx=x;
			tempy=y;
			if(	ship[tempx-hash[0][direction]][tempy-hash[1][direction]]==0)
				ship[tempx-hash[0][direction]][tempy-hash[1][direction]]=2;
			if(ship[tempx+hash[0][direction]+length*hash[0][direction]][tempy+hash[1][direction]+length*hash[1][direction]]==0)
				ship[tempx+hash[0][direction]+length*hash[0][direction]][tempy+hash[1][direction]+length*hash[1][direction]]=2;
			for(j=0;j<length;j++)
			{
				ship[tempx][tempy]=1;
				tempx+=hash[0][direction];
		     	tempy+=hash[1][direction];
			}
			break;
		}
		
		direction=(direction+1)%4;
		
	}
	if(flag==0 && f==1)
	{
		p1ship[ship_index].length = length;
		p1ship[ship_index].x1 = x;
		p1ship[ship_index].y1 = y;
		if(direction == 3)
		{
			p1ship[ship_index].x2 = x + length - 1;
			p1ship[ship_index].y2 = y;
		}
		else if(direction == 2)
		{
			p1ship[ship_index].x2 = x - length + 1;	
			p1ship[ship_index].y2 = y;
		}
		else if(direction == 1)
		{
			p1ship[ship_index].y2 = y - length + 1;
			p1ship[ship_index].x2 = x;	
			//cout<<"#"<<endl;
		}
		else if(direction == 0)
		{
			p1ship[ship_index].y2 = y + length - 1;
			p1ship[ship_index].x2 = x;
		}
		
		if(length == 1)
		{
			p1ship[ship_index].dir[0] =1;
			p1ship[ship_index].dir[1] =1;
			p1ship[ship_index].dir[2] =1;
			p1ship[ship_index].dir[3] =1;
		}
		else if(p1ship[ship_index].x1 == p1ship[ship_index].x2)
		{
			p1ship[ship_index].dir[0] =1;
			p1ship[ship_index].dir[1] =1;
			p1ship[ship_index].dir[2] =0;
			p1ship[ship_index].dir[3] =0;
		}
		else if(p1ship[ship_index].y1 == p1ship[ship_index].y2)
		{
			p1ship[ship_index].dir[0] =0;
			p1ship[ship_index].dir[1] =0;
			p1ship[ship_index].dir[2] =1;
			p1ship[ship_index].dir[3] =1;
		}
		
		ship_index++;
	}
	if(flag==0 && f==2)
	{
		p2ship[ship_index].length = length;
		p2ship[ship_index].x1 = x;
		p2ship[ship_index].y1 = y;
		if(direction == 3)
		{
			p2ship[ship_index].x2 = x + length - 1;
			p2ship[ship_index].y2 = y;
			//cout << "*"<<y<<"*"<<endl;
		}
		else if(direction == 2)
		{
			p2ship[ship_index].x2 = x - length + 1;	
			p2ship[ship_index].y2 = y;
		}
		else if(direction == 1)
		{
			p2ship[ship_index].y2 = y - length + 1;
			p2ship[ship_index].x2 = x;	
			//cout<<"#"<<endl;			
		}
		else if(direction == 0)
		{
			p2ship[ship_index].y2 = y + length - 1;
			p2ship[ship_index].x2 = x;
		}
		
		if(length == 1)
		{
			p2ship[ship_index].dir[0] =1;
			p2ship[ship_index].dir[1] =1;
			p2ship[ship_index].dir[2] =1;
			p2ship[ship_index].dir[3] =1;
		}
		else if(p2ship[ship_index].x1 == p2ship[ship_index].x2)
		{
			p2ship[ship_index].dir[0] =1;
			p2ship[ship_index].dir[1] =1;
			p2ship[ship_index].dir[2] =0;
			p2ship[ship_index].dir[3] =0;
		}
		else if(p2ship[ship_index].y1 == p2ship[ship_index].y2)
		{
			p2ship[ship_index].dir[0] =0;
			p2ship[ship_index].dir[1] =0;
			p2ship[ship_index].dir[2] =1;
			p2ship[ship_index].dir[3] =1;
		}
		
		ship_index++;
	}
	return flag;
}

int produce_ship(int ship[10][10],int f)
{
	int s1=0,s2=0,s3=0,s4=0,n1,n2,n3,n4;
	ship_index = 0;
	int i,x,j;
	for(i=0;i<gridsize_flag;i++)
	{
		for(j=0;j<gridsize_flag;j++)
		{
			ship[i][j] = 0;
		}
	}
	
	if(gridsize_flag==6)
	{
		n1 = 1;
		n2 = 2;
		n3 = 3;
		n4 = 0;
		t = 10;
	}
	else if(gridsize_flag==8)
	{
		n1 = 1;
		n2 = 2;
		n3 = 3;
		n4 = 4;
		t = 20;
	}
	else if(gridsize_flag==10)
	{
		n1 = 1;
		n2 = 2;
		n3 = 3;
		n4 = 4;
		t = 30;
	}
	
	
	while(s1<n1)
		s1+=1-make_ship(ship,gridsize_flag/2,f);
	//delay(100);
	while(s2<n2)
		s2+=1-make_ship(ship,gridsize_flag/2-1,f);
	//delay(100);
	while(s3<n3)
		s3+=1-make_ship(ship,gridsize_flag/2-2,f);
	while(s4<n4)
		s4+=1-make_ship(ship,gridsize_flag/2-3,f);		
	return 0;
}

int show(int topleftx,int toplefty,int bottomrightx,int bottomrighty,int player[][10],int i,int j, int flag,int ifship)
{
	if(ifship)
	{
		//printf("X------\n");
		settextjustify(1,1);
		outtextxy((topleftx+bottomrightx)/2,(toplefty+bottomrighty)/2,"X");
	}
	else
	{
		//printf("Y------\n");
		settextjustify(1,1);
		outtextxy((topleftx+bottomrightx)/2,(toplefty+bottomrighty)/2,".");
	}
}


int checkbox(int player[][10],int flag,int mousex,int mousey,int discover1[][10],int discover2[][10])
{
	int i,j,k,eachsize;
	if(flag==1)
	{
		eachsize=(getmaxx()/2-100)/gridsize_flag;
	   	topleftx=50;
	   	toplefty=50;
	   	bottomrightx=50+eachsize;
	   	bottomrighty=50+eachsize;
	   	int found=0;
		for(i=0;i<gridsize_flag;i++)
	   	{
	   	   for(j=0;j<gridsize_flag;j++)
	   	   {
			if(mousex>topleftx && mousex-9<bottomrightx && mousey-30<bottomrighty && mousey-30>toplefty&&(discover1[i][j]==1))
			  {
				found=1;
				if(player[i][j]==0)
				{
					discover1[i][j]=2;
					flag=2;
				}
				else
				{
					c1++;
					discover1[i][j]=2;
				}
				for(k=0;k<ship_index;k++)
				{
					if(p1ship[k].insideMe(i,j))
					{
						p1ship[k].isAttacked=1;
					}
				}
				move_ships(1,player,discover1);
				break;
			  }
			   else if(mousex>topleftx && mousex-9<bottomrightx && mousey-30<bottomrighty && mousey-30>toplefty&&(discover1[i][j]==2))
			   {
					found = 1;
					break;
			   }
			   //printf("topleftxy=%d %d  bottomrightxy=%d %d\n",topleftx,toplefty,bottomrightx,bottomrighty);
			  topleftx+=eachsize;
			  bottomrightx+=eachsize;
			}
	   	   if(found==1)
	   	   {
	   	   	  //printf("lefty=%d  righty=%d\n",toplefty,bottomrighty);
	   	   	  break;
	   	   }
	   	       
	   	   topleftx=50;
	   	   bottomrightx=50+eachsize;
	   	   toplefty+=eachsize;
	   	   bottomrighty+=eachsize;
	   	}
	   	if(found==1)
	   		show(topleftx,toplefty,bottomrightx,bottomrighty,player,i,j,flag,player[i][j]);
	   //	printf("1<%d %d %d>\n",i,j,flag);
	}
	else
	{
		eachsize=(getmaxx()/2-100)/gridsize_flag;
	   	topleftx=getmaxx()/2+50;
	    toplefty=50;
	    bottomrightx=topleftx+eachsize;
	    bottomrighty=toplefty+eachsize;
	   	int found=0;
		for(i=0;i<gridsize_flag;i++)
	   	{
	   	   for(j=0;j<gridsize_flag;j++)
	   	   {
	   	   	  if(mousex>topleftx&&mousex-9<bottomrightx && mousey-30<bottomrighty && mousey-30>toplefty&&(discover2[i][j]==1))
	   	   	  {
	   	   	  	found=1;
	   	   	  	if(player[i][j]==0)
	   	   	  	{
	   	   	  		discover2[i][j]=2;
	   	   	  		flag=1;
	   	   	  	}
	   	   	  	else
	   	   	  	{
	   	   	  		c2++;
	   	   	  		discover2[i][j]=2;
	   	   	  	}
				for(k=0;k<ship_index;k++)
				{
					if(p2ship[k].insideMe(i,j))
					{
						p2ship[k].isAttacked=1;
					}
				}
				move_ships(2,player,discover2);
	   	   	  	break;
	   	   	  }
		   	   else if(mousex>topleftx&&mousex-9<bottomrightx && mousey-30<bottomrighty && mousey-30>toplefty&&(discover2[i][j]=2))
		   	   {
		   	   		found = 1;
		   	   		break;
		   	   }
		   	   //printf("topleftxy=%d %d  bottomrightxy=%d %d\n",topleftx,toplefty,bottomrightx,bottomrighty);
	   	   	  topleftx+=eachsize;
	   	   	  bottomrightx+=eachsize;
		   }
	   	   if(found==1)
	   	       break;
	   	   topleftx=getmaxx()/2+50;
	   	   bottomrightx=getmaxx()/2+50+eachsize;
	   	   toplefty+=eachsize;
	   	   bottomrighty+=eachsize;
	   	}
	   	if(found==1)
	   		show(topleftx,toplefty,bottomrightx,bottomrighty,player,i,j,flag,player[i][j]);
	   	//printf("2<%d %d %d>\n",i,j,flag);
	}
	return flag;
}

int game_page()
{
	int player1[10][10],player2[10][10],discover1[10][10],discover2[10][10];
	c1=0;
	c2=0;
    produce_ship(player1,1);
    produce_ship(player2,2);
    int i,j;
    cout<<"Player 1\n";
   	for(i=0;i<gridsize_flag;i++)
	{
		for(j=0;j<gridsize_flag;j++)
		{
		    if(player1[i][j]==2)
				player1[i][j]=0;
			discover1[i][j]=1;
			discover2[i][j]=1;	
			printf("%d ",player1[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	cout<<"Player 2\n";
	for(i=0;i<gridsize_flag;i++)
	{
		for(j=0;j<gridsize_flag;j++)
			{
			if(player2[i][j]==2)
				player2[i][j]=0;
			
			printf("%d ",player2[i][j]);
		}
		printf("\n");
	}
	
	cout<<"\n++++++++++++++++++++++++++++++\n";
	/*
	for(i=0;i<ship_index;i++)
	{
		printf("Length : %d  ",p1ship[i].length);
		printf("Starting : %d %d  ",p1ship[i].x1,p1ship[i].y1);
		printf("End : %d %d\n",p1ship[i].x2,p1ship[i].y2);
	}
	for(i=0;i<ship_index;i++)
	{
		printf("Length : %d  ",p2ship[i].length);
		printf("Starting : %d %d  ",p2ship[i].x1,p2ship[i].y1);
		printf("End : %d %d\n",p2ship[i].x2,p2ship[i].y2);
	}
	*/
	int eachsize,flag=1;
	//int topleftx,toplefty,bottomrightx,bottomrighty;
	topleftx=50;
	toplefty=50;
	//bottomrightx=getmaxx()/2-50;
	//bottomrighty=getmaxx()/2-50;
	cleardevice();
	settextjustify(1,1);
	settextstyle(0, HORIZ_DIR, 3);
  	setcolor(RED);
   	outtextxy(150, 25, "PLAYER A");
   	line(669,0,669,680);
   	outtextxy(800, 25, "PLAYER B");
   	setcolor(WHITE);
   	setcolor(GREEN);
   	POINT cp;
   	int mousex,mousey;
   	int xmax=getmaxx();
   	int ymax=getmaxy();
   	outtextxy(getmaxx()/2, 680, "Quit");
   	
   	eachsize=(getmaxx()/2-100)/gridsize_flag;
   
   	topleftx=50;
   	toplefty=50;
   	bottomrightx=50+eachsize;
   	bottomrighty=50+eachsize;
   
   	for(i=0;i<gridsize_flag;i++)
   	{
   	   for(j=0;j<gridsize_flag;j++)
   	   {
   	   	  rectangle(topleftx,toplefty,bottomrightx,bottomrighty);
   	   	  topleftx+=eachsize;
   	   	  bottomrightx+=eachsize;
   	   }
   	   topleftx=50;
   	   bottomrightx=50+eachsize;
   	   toplefty+=eachsize;
   	   bottomrighty+=eachsize;
   	}
   
   
   topleftx=getmaxx()/2+50;
   toplefty=50;
   bottomrightx=topleftx+eachsize;
   bottomrighty=toplefty+eachsize;
   
   for(i=0;i<gridsize_flag;i++)
   {
   	   for(j=0;j<gridsize_flag;j++)
   	   {
   	   	  rectangle(topleftx,toplefty,bottomrightx,bottomrighty);
   	   	  topleftx+=eachsize;
   	   	  bottomrightx+=eachsize;
   	   }
   	   topleftx=getmaxx()/2+50;
   	   bottomrightx=getmaxx()/2+50+eachsize;
   	   toplefty+=eachsize;
   	   bottomrighty+=eachsize;
   }
   
   while(1)
   {
   		GetCursorPos(&cp);
   		mousex=cp.x;
   		mousey=cp.y;
   		if(GetAsyncKeyState(VK_LBUTTON))
   		{
   			int ht,wid;
   			
   			ht=textheight("Quit");
   			wid=textwidth("Quit");
   			
   			
   			
   			setcolor(RED);
   			
   			if(mousex>(xmax/2-wid/2 +10)&&mousex<(xmax/2+wid/2 +10) && mousey<(680+(ht/2)+20) && mousey>(680-(ht/2)+20))
   			{
   			   cleardevice();
   			   main_page();
   			}
   			else if(mousex>50&&mousex<(getmaxx()/2-50) && mousey<(50+eachsize*gridsize_flag) && mousey>50 && flag==1)
   			{
   				flag=checkbox(player1,1,mousex,mousey,discover1,discover2);
   				cout<<"\nMoved"<<endl;
				for(i=0;i<gridsize_flag;i++)
				{
					for(j=0;j<gridsize_flag;j++)
					{
						cout<<player1[i][j]<<" ";
					}
					cout<<endl;
				}
   				//printf("mousex=%d mousey=%d\n",mousex,mousey);
   			}
			else if(mousex>(50+getmaxx()/2)&&mousex<(getmaxx()-50) && mousey<(50+eachsize*gridsize_flag) && mousey>50 && flag==2)
   			{
   				flag=checkbox(player2,2,mousex,mousey,discover1,discover2);
   			}
   			if(c1==t)
   			{
   				eachsize=(getmaxx()/2-100)/gridsize_flag;
			   	topleftx=50;
			   	toplefty=50;
			   	bottomrightx=50+eachsize;
			   	bottomrighty=50+eachsize;
   				for(i=0;i<gridsize_flag;i++)
			   	{
			   	   for(j=0;j<gridsize_flag;j++)
			   	   {
			   	   		show(topleftx,toplefty,bottomrightx,bottomrighty,player1,i,j,flag,player1[i][j]);
			   	   		topleftx+=eachsize;
	   	   	  			bottomrightx+=eachsize;
			   	   }
			   	   topleftx=50;
			   	   bottomrightx=50+eachsize;
			   	   toplefty+=eachsize;
			   	   bottomrighty+=eachsize;
			   }
			   
			   eachsize=(getmaxx()/2-100)/gridsize_flag;
			   	topleftx=getmaxx()/2+50;
			    toplefty=50;
			    bottomrightx=topleftx+eachsize;
			    bottomrighty=toplefty+eachsize;
   				for(i=0;i<gridsize_flag;i++)
			   	{
			   	   for(j=0;j<gridsize_flag;j++)
			   	   {
			   	   		show(topleftx,toplefty,bottomrightx,bottomrighty,player2,i,j,flag,player2[i][j]);
			   	   		topleftx+=eachsize;
	   	   	  			bottomrightx+=eachsize;
			   	   }
			   	   topleftx=getmaxx()/2+50;
			   	   bottomrightx=getmaxx()/2+50+eachsize;
			   	   toplefty+=eachsize;
			   	   bottomrighty+=eachsize;
			   }
			   settextjustify(1,1);
			   
			   setcolor(RED);
			   outtextxy(getmaxx()/4,680,"Player A Wins");
   			}
   			else if(c2==t)
   			{
   				
   				eachsize=(getmaxx()/2-100)/gridsize_flag;
			   	topleftx=50;
			   	toplefty=50;
			   	bottomrightx=50+eachsize;
			   	bottomrighty=50+eachsize;
   				for(i=0;i<gridsize_flag;i++)
			   	{
			   	   for(j=0;j<gridsize_flag;j++)
			   	   {
			   	   		show(topleftx,toplefty,bottomrightx,bottomrighty,player1,i,j,flag,player1[i][j]);
			   	   		topleftx+=eachsize;
	   	   	  			bottomrightx+=eachsize;
			   	   }
			   	   topleftx=50;
			   	   bottomrightx=50+eachsize;
			   	   toplefty+=eachsize;
			   	   bottomrighty+=eachsize;
			   }
   				
   				eachsize=(getmaxx()/2-100)/gridsize_flag;
			   	topleftx=getmaxx()/2+50;
			    toplefty=50;
			    bottomrightx=topleftx+eachsize;
			    bottomrighty=toplefty+eachsize;
   				for(i=0;i<gridsize_flag;i++)
			   	{
			   	   for(j=0;j<gridsize_flag;j++)
			   	   {
			   	   		show(topleftx,toplefty,bottomrightx,bottomrighty,player2,i,j,flag,player2[i][j]);
			   	   		topleftx+=eachsize;
	   	   	  			bottomrightx+=eachsize;
			   	   }
			   	   topleftx=getmaxx()/2+50;
			   	   bottomrightx=getmaxx()/2+50+eachsize;
			   	   toplefty+=eachsize;
			   	   bottomrighty+=eachsize;
			   }
			   settextjustify(1,1);
			   setcolor(RED);
			   outtextxy((getmaxx()*3)/4,680,"Player B Wins");
   			}
   		}
		delay(100);
   		if(flag==1 && c1!=t && c2!=t)
		{
			setcolor(BLACK);
			outtextxy((getmaxx()*3)/4,680,"Your Turn");
			setcolor(YELLOW);
			outtextxy(getmaxx()/4,680,"Your Turn");
		}
		else if(flag==2 && c1!=t && c2!=t)
		{
			setcolor(BLACK);
			outtextxy(getmaxx()/4,680,"Your Turn");
			setcolor(YELLOW);
			outtextxy((getmaxx()*3)/4,680,"Your Turn");
			
		}
   	}
	return 0;
}

int developer_page()
{
	cleardevice();
	settextstyle(0, HORIZ_DIR, 4);
 	settextjustify(1,1);
  	setcolor(RED);
   outtextxy(getmaxx()/2, getmaxy()/2-200, "DEVELOPERS");
   setcolor(WHITE);
   settextstyle(0, HORIZ_DIR, 3);
   outtextxy(getmaxx()/2, getmaxy()/2-100, "Mohammad Aamir");
   outtextxy(getmaxx()/2, getmaxy()/2-50, "Ritesh Kumar");
   outtextxy(getmaxx()/2, getmaxy()/2, "Shubham Chourey");
   outtextxy(getmaxx()/2, getmaxy()/2+100, "Back");
   int xmax=getmaxx();
   int ymax=getmaxy();
   POINT cp;
   int mousex,mousey;
   
   while(1)
   {
   		GetCursorPos(&cp);
   		mousex=cp.x;
   		mousey=cp.y;
   		if(GetAsyncKeyState(VK_LBUTTON))
   		{
   			int ht,wid;	
   			ht=textheight("Back");
   			wid=textwidth("Back");
   			if(mousex>(xmax/2-wid/2 +10)&&mousex<(xmax/2+wid/2 +10) && mousey<(ymax/2+100+(ht/2)+20) && mousey>(ymax/2+100-(ht/2)+20))
   			{
   				cleardevice();
   				main_page();
   				getch();
		   	    closegraph();
   			}
   		}
   		delay(100);
   }
   
	return 0;
}

int difficulty_page()
{
	cleardevice();
	settextstyle(0, HORIZ_DIR, 3);
   
 	settextjustify(1,1);
  	setcolor(RED);
   outtextxy(getmaxx()/2, getmaxy()/2-200, "SET DIFFICULTY");
   setcolor(WHITE);
   settextstyle(0, HORIZ_DIR, 3);
   outtextxy(getmaxx()/2, getmaxy()/2-100, "6 X 6 Grid");
   outtextxy(getmaxx()/2, getmaxy()/2-50, "8 X 8 Grid");
   outtextxy(getmaxx()/2, getmaxy()/2, "10 X 10 Grid");
   outtextxy(getmaxx()/2, getmaxy()/2+100, "Back");
   int xmax=getmaxx();
   int ymax=getmaxy();
   POINT cp;
   int mousex,mousey;
  while(1)
   {
   		GetCursorPos(&cp);
   		mousex=cp.x;
   		mousey=cp.y;
   		if(GetAsyncKeyState(VK_LBUTTON))
   		{
   			int ht,wid;
   			
   			ht=textheight("6 X 6 Grid");
   			wid=textwidth("6 X 6 Grid");
   			if(mousex>(xmax/2-wid/2 +10)&&mousex<(xmax/2+wid/2 +10) && mousey<(ymax/2-100+(ht/2)+20) && mousey>(ymax/2-100-(ht/2)+20))
   			{
   			   gridsize_flag=6;
   			   //printf("%d",gridsize_flag);
   			}
   			
   			ht=textheight("8 X 8 Grid");
   			wid=textwidth("8 X 8 Grid");
   			if(mousex>(xmax/2-wid/2 +10)&&mousex<(xmax/2+wid/2  +10) && mousey<(ymax/2-50+(ht/2)+20) && mousey>(ymax/2-50-(ht/2)+20))
   			{
   				gridsize_flag=8;
   				//printf("%d",gridsize_flag);
   			}
   			
   			ht=textheight("10 X 10 Grid");
   			wid=textwidth("10 X 10 Grid");
   			if(mousex>(xmax/2-wid/2 +10)&&mousex<(xmax/2+wid/2 +10) && mousey<(ymax/2+(ht/2)+20) && mousey>(ymax/2-(ht/2)+20))
   			{
   				gridsize_flag=10;
   				//printf("%d",gridsize_flag);
   			}
   			
   			ht=textheight("Back");
   			wid=textwidth("Back");
   			if(mousex>(xmax/2-wid/2 +10)&&mousex<(xmax/2+wid/2 +10) && mousey<(ymax/2+100+(ht/2)+20) && mousey>(ymax/2+100-(ht/2)+20))
   			{
   				cleardevice();
   				main_page();
   				getch();
		   	    closegraph();
   			}
   			

   		}
   		delay(100);
   }
   
   
	return 0;
}
int main_page()
{
	  int xmax,ymax;
   //initwindow(1378,720);
   xmax=getmaxx();
   ymax=getmaxy();
   settextstyle(4, HORIZ_DIR, 5);
   setcolor(RED);
   settextjustify(1, 1);
   outtextxy(xmax/2,ymax/2-200,"Battleships Game");
   settextstyle(4, HORIZ_DIR, 3);
   setcolor(WHITE);
   outtextxy(xmax/2,ymax/2-120,"New Game");
   outtextxy(xmax/2,ymax/2-80,"Difficulty Level");
   outtextxy(xmax/2,ymax/2-40,"Developers");
   outtextxy(xmax/2,ymax/2,"Exit");
   //outtextxy(xmax/2,100,"New Game");
   //outtextxy(xmax/2,ymax/2-120,"New Game");
   
   
   //getmouseclick(LBTNDBLCLK);
   POINT cp;
   int mousex,mousey;
   
   
  while(1)
   {
   		GetCursorPos(&cp);
   		mousex=cp.x;
   		mousey=cp.y;
   		if(GetAsyncKeyState(VK_LBUTTON))
   		{
   			int ht,wid;
   			
   			ht=textheight("New Game");
   			wid=textwidth("New Game");
   			if(mousex>(xmax/2-wid/2 +10)&&mousex<(xmax/2+wid/2 +10) && mousey<(ymax/2-120+(ht/2)+20) && mousey>(ymax/2-120-(ht/2)+20))
   			{
   				cleardevice();
				game_page();
			    getch();
		   	    closegraph();
   			}
   			
   			ht=textheight("Difficulty Level");
   			wid=textwidth("Difficulty Level");
   			if(mousex>(xmax/2-wid/2 +10)&&mousex<(xmax/2+wid/2  +10) && mousey<(ymax/2-80+(ht/2)+20) && mousey>(ymax/2-80-(ht/2)+20))
   			{
   				cleardevice();
				difficulty_page();
			    getch();
		   	    closegraph();
   			}
   			
   			ht=textheight("Developers");
   			wid=textwidth("Developers");
   			if(mousex>(xmax/2-wid/2 +10)&&mousex<(xmax/2+wid/2 +10) && mousey<(ymax/2-40+(ht/2)+20) && mousey>(ymax/2-40-(ht/2)+20))
   			{
   				cleardevice();
				developer_page();
			    getch();
		   	    closegraph();
   			}
   			
   			ht=textheight("Exit");
   			wid=textwidth("Exit");
   			if(mousex>(xmax/2-wid/2 +10)&&mousex<(xmax/2+wid/2 +10) && mousey<(ymax/2+(ht/2)+20) && mousey>(ymax/2-(ht/2)+20))
   			{
   				//cleardevice();
		   	    closegraph();
   			}
   			

   		}
   		delay(100);
   }
  
  
}
//--------------------------------------------------------------------------------------------------------------------------------
int main()
{ 
	srand(time(NULL));
	initwindow(1378,720);
	main_page();
	getch();
	closegraph();
	return 0;
}
