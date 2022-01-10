#include<stdio.h>
#define WAIT 1

// プロトタイプ宣言
void opening();
void ending(int flag);
int menuMain();
int menuUse(int key1, int hammer, int ladder);
int menuMove(int location);
void errorMainMenu();
int sleep(int);

// 関数定義
int main(void){
  int location = 1, flag = 0, select, use, action;
  int key1 = 0, key2 = 0, key3 = 0, drink = 3, thirsty= 7;
  int nurseroomLook = 0, nurseroomKey = 0;
  int staffroomLook = 0, staffroomKey = 0;
  opening();

  while(flag == 0){   /*--- メインループはじまり ---*/

    /* ------ 場所に関するswitch文のはじまり  -----*/
    switch(location){

    case 1:    /* ------ 場所に関するswitch文 保健室 ----- */
      printf("あなたは保健室の前にいる。\n");  sleep(WAIT);
      action = menuMain();

      switch(action){   /* --- 保健室での行動 ---- */
      case 1:  // 調べる
	printf("どうやら保健室は鍵がかかっているようだ。\n");    sleep(WAIT);
	if(key2 == 0){
	  printf("廊下の隅に何か光っている、あなたは丸い鍵を拾った。\n");  sleep(WAIT);
	  key2 = 2;
	}
	break;
      case 2:  // 道具
	use = menuUse(key1, key2, key3);
	if(use == 1) {
	  printf("あなたは鍵を差し込み回してみた...");  sleep(WAIT);
	  printf("開かない、どうやら違う鍵のようだ。\n");  sleep(WAIT);
	}
	if(use == 2){
	  printf("あなたは鍵を差し込み回してみた...\n");    sleep(WAIT);
	  printf("開かない、どうやら違う鍵のようだ。\n");    sleep(WAIT);
	}
	if(use == 3){
	  // エンディングを実行する準備
	  flag = 1;
	}
	break;
      case 3:
	printf("近くの中庭の水道に駆け付けた、なんて美味しい水だ。\n");    sleep(WAIT);
	drink--;  thirsty = 7;
	break;
      case 4:
	location = menuMove(location);
	break;
      default:
	errorMainMenu();
      }

      break;



    case 2:    /* ------ 場所に関するswitch文：職員室  ----- */
      printf("あなたは職員室の前に居る。\n");    sleep(WAIT);
      action = menuMain();
      switch(action){   /* --- 職員室での行動 ---- */
      case 1:  // 調べる
	if(staffroomLook == 1){
	  printf("どうやら鍵がかかっているようだ。\n");    sleep(WAIT);
	  staffroomLook = 2;
	  staffroomKey = 1;
	}else{
	  printf("職員室には鍵がかかっている。\n");    sleep(WAIT);
	  staffroomLook = 1;
	}
	break;
      case 2:  // 道具
	use = menuUse(key1, key2, key3);
	if(use == 1) { 
	  if(staffroomLook == 0){
	    printf("この鍵をどうしようか...\n");    sleep(WAIT);
	  } else  if(staffroomKey == 1){
	    printf("あなたは鍵を開けた");    sleep(WAIT);
	    printf("職員室の黒板に吊るしてあった平らな鍵を入手した！\n");    sleep(WAIT);
	    key3 = 1;
	  } else {
	    printf("鍵をどうしよう...\n");    sleep(WAIT);
	  }
	}
	if(use == 2) { 
	  printf("あなたは丸い鍵を差し込み回してみた...");    sleep(WAIT);
	  flag = 3;
	}
	if(use == 3) {
	  printf("あなたは平らな鍵を差し込み回してみた...どうやら違う鍵のようだ。\n");    sleep(WAIT);
	}
	break;
      case 3:  // 飲む
	printf("水道に駆け付けた、なんて美味しい水なんだ！\n");    sleep(WAIT);
	drink--;  thirsty = 7;
	break;
      case 4: // 移動
	location = menuMove(location);
	break;
      default:
	errorMainMenu();
      }
      break;



    case 3:    /* ------ 場所に関するswitch文：理科室  ----- */
      printf("理科室は鍵がかかっていない。\n");    sleep(WAIT);
      printf("あなたは理科室の中に居る。\n");    sleep(WAIT);
      action = menuMain();
      switch(action){
      case 1:  // 調べる
	printf("あなたは理科室の中を調べた。教卓の引き出しに何かの鍵がありそうだ。\n");    sleep(WAIT);
	break;
      case 2:  // 道具
	use = menuUse(key1, key2, key3);
	if(use == 1){
	  printf("あなたは四角い鍵を差し込み回してみた...どうやら違う鍵のようだ。\n");    sleep(WAIT);
	}
	if(use == 2){
	  printf("あなたは丸い鍵を差し込み回してみた....");   sleep(WAIT);
	  if(key1 == 0){
	    printf("引き出しが開き、中から四角い鍵を入手した。\n");    sleep(WAIT);
	    printf("あなたは鍵を手に入れた\n");    sleep(WAIT);
	    key1 = 1;
	  } else if (key1 == 1){
	    printf("引き出しの鍵をかけたり、開けたりすることが出来る。\n");    sleep(WAIT);
	    printf("もうこの鍵は用済みだろう。\n");    sleep(WAIT);
	  }
	}
	if(use == 3){
	  printf("あなたは平らな鍵を差し込み回してみた...どうやら違う鍵のようだ。\n");    sleep(WAIT);
	}
	break;
      case 3:  // 飲む
	printf("水道に駆け付けた、理科室の水道からは水が出なかった...！\n");    sleep(WAIT);
	printf("ためらって水道付近のボトルを飲んだ...蒸留水だ！！！まずい！！！！！！！！\n");    sleep(WAIT);
	drink--;  thirsty = 7;
	break;
      case 4:  // 移動
	location = menuMove(location);
	break;
      default:
	errorMainMenu();
      }
      
      break;

    default:    /* ------ 場所に関するswitch文：例外  ----- */
      printf("あなたはどこにも居ない、ということはプログラムのミスの可能性がある\n");    sleep(WAIT);

    }    /* ------ 場所に関するswitch文の終端 ----- */


    // 毎回の行動で発生する処理
    thirsty--;  // 渇き処理

    if(thirsty == 3){
      printf("あなたは喉が渇いた...");    sleep(WAIT*2);
      printf("このままでは倒れてしまう\n");
    }
    if(thirsty <= 0){
      flag = 2;
    }


  }  // メインループの終端
  
  ending(flag);

  return 0;
}

void opening(void){
  printf("====== ヴァーチャルマラソンゲーム ======\n");  sleep(WAIT);
  printf("あなたはフルマラソンに出場している。\n");  sleep(WAIT);
  printf("目標の３時間を切るぞ！！\n");  sleep(WAIT);
  printf("給水しつつ倒れずにゴールせねば！！！\n");  sleep(WAIT);
  printf("しかし、ライバルに足を踏まれ怪我をしてしまった。\n");  sleep(WAIT);
  printf("周りを見渡すと近くに学校がある。\n");  sleep(WAIT);
  printf("早く治療し走らねば！！！\n");  sleep(WAIT);
  printf("今日は日曜日で人の気配がないが、門が開いている\n");  sleep(WAIT);
  printf("あなたは急いで学校の中に入っていった。\n");  sleep(WAIT);

  return;
}

void ending(int flag){
  printf(":\n");    sleep(WAIT);
  printf(":\n");    sleep(WAIT);
  printf(":\n");    sleep(WAIT);
    
  switch(flag){
  case 1:
    printf("あなたは平らな鍵を使い、保健室のドアを開けることに成功した。\n");    sleep(WAIT*2);
    printf("急いで足の治療を行った。\n");    sleep(WAIT*2);
    printf("そして再び、レースに戻った...\n");   sleep(WAIT*2);
    printf("ものすごい勢いで駆け抜け、ゴールテープを切った！！！\n");    sleep(WAIT*2);
    printf("どうやらライバルは棄権したようだ。\n");    sleep(WAIT*2);
    printf("ランニングの師匠が大喜びで駆け寄ってきて叫んだ！！！\n");    sleep(WAIT*2);
    printf("「優勝おめでとうーーーーーー！！！！！！！！！！！」\n");    sleep(WAIT*2);
    printf("======== Happy End ========\n");
    break;
  case 2:
    printf("あなたは倒れて気を失ってしまった。\n");    sleep(WAIT*2);
    printf("なんてこった、必ずゴールすると約束してたのに...\n");    sleep(WAIT*2);
    printf("======== Bad End ========\n");
    break;
  case 3:
    printf("突然、背後から物音がした。\n");      sleep(WAIT*2);
    printf("振り返ると、そこには教師がいた。\n");    sleep(WAIT*2);
    printf("「ふっ不審者だー！！！！！！！」\n");    sleep(WAIT*2);
    printf("警察を呼ばれ逮捕されてしまった。\n");    sleep(WAIT*2);
    printf("======== Bad End ========\n");
    break;
  } 

  return;
}

int menuMain(){
  int ans;
  printf("1: 調べる    2:使う    3:飲む    4:移動 ");
  scanf("%d", &ans);

  return ans;
}

void errorMainMenu(){
  printf("1-4 の値を入力して下さい。\n");
}

int menuMove(int location){
  int ans;

  printf("どこに移動しますか  ");
  printf("1:保健室    2:職員室    3:理科室 ？");

  scanf("%d", &ans);

  return ans;
}

int menuUse(int key1, int key2, int key3){
  int select;

  printf("何を使う？\n");
  printf("1... 四角い鍵   2... 丸い鍵   3... 平らな鍵   ");
  scanf("%d", &select);

  if(key1 == 0 && select == 1){
    printf("あなたはそれを持っていない。\n");     sleep(WAIT);
    select = 0;
  } else if(key2 == 0 && select == 2){
    printf("あなたはそれを持っていない。\n");     sleep(WAIT);
    select = 0;
  } else if(key3 == 0 && select == 3){
    printf("あなたはそれを持っていない。\n");     sleep(WAIT);
    select = 0;
  }

  return select;
}
