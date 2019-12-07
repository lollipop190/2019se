#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
	int playerback[17][17] = {0};
	int mineback[17][17] = {0};
	
void printFunc();
void printtip();
void p2pplay();
void p2mplay(); 
void newbackprint();//ÿ�������Ӻ�����̴�ӡ 
int isWin(int x,int y,int turn);

int main(){

    printFunc();
    printtip();
    int index = 0;
    scanf("%d",&index);
    if(index==1)
    	p2pplay();//���˶�ս 
	else
	    p2mplay();//�˻���ս 
    
	system("pause");
	return 0;
}
void p2pplay(){
	printf("����ɹ������˶�ս��ʼ���ǵ�����ĺû���һ����Ŷ��\n");
	int turn =2;
	while(turn){
	printf("��%dλ����������������ӵ����꣬���к���Ŷ��\n",turn%2+1);
	int x = 0;
	int y = 0;
	scanf("%d %d",&x,&y);
	if(x<1||x>15||y<1||y>15){
		printf("����������������������Ŷ��\n");
		continue;
	}
	if(playerback[x][y]!=0){
		printf("����Ѿ���������������������Ŷ��\n");
		continue;
	}
	playerback[x][y] = turn%2+1;
	newbackprint();
	int result = isWin(x,y,turn%2+1);
	if(result ==4){
		printf("��%dλ��һ����ʤ��������������\n",turn%2+1);
		break;
	}
	turn++;
	}
}


void p2mplay(){
	printf("����ɹ����˻���ս��ʼ�����������\n");
	int turn =2;
	while(turn){
	printf("����������������ӵ����꣬���к���Ŷ��\n");
	int x = 0;
	int y = 0;
	scanf("%d %d",&x,&y);
    if(x<1||x>15||y<1||y>15){
		printf("����������������������Ŷ��\n");
		continue;
	}
	if(playerback[x][y]!=0){
		printf("����Ѿ���������������������Ŷ��\n");
		continue;
	}
	playerback[x][y] = 1;
	int result = isWin(x,y,1);
	if(result ==4){
		printf("��һ����ʤ��������������\n");
		break;}

	srand( (unsigned)time( NULL ) );
	while(1){
		int a=rand()%15+1;
		int b=rand()%15+2;
		if(playerback[a][b]!=0)
		continue;
		else{
		playerback[a][b] =2;
		newbackprint();
		}
		int result = isWin(a,b,2);
	    if(result ==4){
		printf("������Ȼ�����ʤ������һ�����ý����!\n");
		break;}
		break;
		}
	
	} 
	newbackprint();
}





int isWin(int x,int y,int turn){
	//�����ж� 
	
	int c = 0;
	for(int i =1;i<=4;i++){
	if(playerback[x-i][y]==turn)
	   c++;
	else 
	   break; 
	} 
	for(int i =1;i<=4;i++){
	if(playerback[x+i][y]==turn)
	   c++;
	else 
	   break; 
	} 
	if(c ==4)
	return c;
	//�����ж� 
	 c = 0;
	for(int i =1;i<=4;i++){
	if(playerback[x][y-i]==turn)
	   c++;
	else 
	   break; 
	} 
	for(int i =1;i<=4;i++){
	if(playerback[x][y+i]==turn)
	   c++;
	else 
	   break; 
	} 
	if(c ==4)
	return c;
	//��б�ж� 
	c =0;
	for(int i =1;i<=4;i++){
	if(playerback[x-i][y-i]==turn)
	   c++;
	else 
	   break; 
	} 
	for(int i =1;i<=4;i++){
	if(playerback[x+i][y+i]==turn)
	   c++;
	else 
	   break; 
	} 
	if(c ==4)
	return c;
	//��б�ж� 
	c =0;
	for(int i =1;i<=4;i++){
	if(playerback[x-i][y+i]==turn)
	   c++;
	else
	   break; 
	} 
	for(int i =1;i<=4;i++){
	if(playerback[x+i][y-i]==turn)
	  c++;
	else 
	   break; 
	} 
	if(c ==4)
	return c;
	else 
	return 0; 
}
void printFunc(){
		for(int m =0;m<=15;m++){
		if(m==0)
		printf("0   ");
		else if(m >=10)
		printf("%d ",m);
		else
		printf("%d  ",m);
		
	}
	printf("\n");
	for(int i =1;i<=15;i++){
		if(i<10)
		printf("%d   ",i);
		else 
		printf("%d  ",i);
		for(int j =0;j<15;j++){
	      printf("%c  ",'*');
		}
		printf("\n");
	}
	
}
void  printtip(){
	printf("���ã���ӭ����������ҫ�������ǣ���Ȥ�����������磬������һ��15*15�ľ������������̣���Ҫ��ʼ��\n�õģ����˶�ս������1���˻���ս������2\nP.S.�����Ƚ�ɵ�벻Ҫ�����۸�Ŷ!\n");
}

void newbackprint(){
	for(int m =0;m<=15;m++){
		if(m==0)
		printf("0   ");
		else
		printf("%d ",m);
		
	}
	printf("\n");
	for(int i =1;i<=15;i++){
		if(i<10)
		printf("%d   ",i);
		else 
		printf("%d  ",i);
		for(int j =1;j<15;j++){
			if(j>=9)
			printf("%d  ",playerback[i][j]);
			else
			printf("%d ",playerback[i][j]);
		}
		printf("\n");
	}
}




