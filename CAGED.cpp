//Micih Hines   
//April 2, 2018   
//CAGED   

#include <iostream>   
#include <stdlib.h>    
#include <time.h>     
#include <ctype.h>   

using namespace std;   

void intro();   
void character_choice();   
void get_stats();   
void get_enemy_stats();   
void player_turn();   
void enemy_turn();   
void player_debuffs();  
void level_up(); 
void recover();
void fate();
void reset_stats(); 
  
int player_HP=0,player_maxHP=0,player_DPS1=0,player_DPS2=0,player_race=0,player_skill=0;   
int enemy_HP=0,enemy_maxHP=0,enemy_DPS1=0,enemy_DPS2=0;   
int matches=1;   
int damage=0;  
int Heal=0; 
int level=1; 
int new_skill1=0,new_skill2=0,new_skill3=0; 
int max_Skills=2; 
int Boost_Choice=0; 
int Bad_Karma=0,Good_Karma=0,fate_choice=0;

char safe='f'; 
char attack='t';
  

//-------------------------------------------------------------------------------------------Player Debuffs  

int scorpio_posion=0;
int leech_timer=0;
int paralysis_chance=0;
int damage_multi=0;
int lighting_multi=0;
int petrified_chance=0;
int petrified_effect=0;
int burning=0;
int spark_chance=0;
int corrosion_timer=0;
int bleed_amount=0;
int stun_chance=0;
int agile_chance=0;
int instant_bleed=0;
int burrow_wait=0;

char leech='f';
char gift_of_the_mamba='f';
char paralysis='f';
char enemy_paralyzed='f';
char dragon_hide='f';
char spark='f';
char nerve_breath='f';
char razor_fur='f';
char agile='f';
char retry='n';

//-------------------------------------------------------------------------------------------Player Debuffs  
  
int main()     
{
do
{
      
    intro();   
    character_choice();   
    get_stats();   

do
{

get_enemy_stats();  

    do   
    {    
    player_turn();   
    player_debuffs();  
    enemy_turn();   
   }   

while(player_HP>0 && enemy_HP>0);         

if(player_HP>0)
{
	fate();
}

if(matches<6 && player_HP>0)
{		
recover(); 
level_up();
}

} 
while(matches<6 && player_HP>0);

if(player_HP>0)
{
	
if(Good_Karma>Bad_Karma)
{
  if(player_race==1)
  {
  	cout <<"Once again you would be placed back that small room, fearing that you'll never truly be free of it.\nThat was what you'd believe at first.\nWhen the gate rose a bit more early than usual, you were confused to find an empty arena before you,\nbut as you turn to see that gate to the outside open you didn't hesitate to run out.\nCitizens screamed in horror as your massive form charged through the streets,\nknocking aside anyone that got in your way.\nYou worried you'd find the final gate closed, but it to was wide open for you.\nYou'd charge for the outside and never looked back...\n";
  }
  if(player_race==2)
  {
  	cout <<"Crawling back to your hole, you had grown tired of playing these human games.\nYou'd much prefer being trophy then having to suffer another day of this pointless fighting.\nBut fate had something else in mind.\nWhen the gates open prematurely, it puzzled you to view the back of wagon.\nYou then saw the faces of other gladiators beckoning you in.\nYou were hesitant, but if there was even the slightest chance of escaping this place dead or alive,\nyou'd take it. Thus you crawled on in and in the dead of night,\nthe wagon made it's way to the outside of the city,\nit's possessions never to be seen again...\n";
  }
  if(player_race==3)
  {
  	cout <<"As you slumber soundlessly in your little cell,\nyou woke to expect another pointless scuffle as your gate raises.\nInstead, you found guards and gladiators battling furiously within the arena field.\nYou don't know what force compelled you, but you'd leap in,\nslaughtering the men who'd imprisoned you alongside your fellow prisoners.\nUltimately you had taken part in a revolution that eventually ended with the tyrant king dead dead at your paws.\nYou then find yourself with a choice.\nStay and you would never need to worry about food ever again or return home.\nYou easily chose the later.\nYou were brought back to those lush jungles, your perfect kingdom,\nwhere man would never hunt you again.";
  }
}

else if(Bad_Karma>Good_Karma)
{
  if(player_race==1)
  {
  	cout << "As you acknowledge the human blood on your body, you came to the revelation that man wasn't something to fear...\nYou would not return to that cage.\nWhen those guards approached you, your jaws became agape and an inferno was born to welcome them.\nWhat remained of the mortals was ash and you wouldn't stop there.\nYour mouth parted again and from it shot lighting into the stunned crowd above,\nobliterating a group and causing the rest to flee in horror\nas you continued to destroy everything around you in a mix of fire and thunder.\nBefore long the arena was burning. Onlookers watched in horror as you emerge from the flames you breathed,\nspreading the chaos throughout the entire city until it had become a pile of smoldering ash and broken bodies...\n";
  }
  else if(player_race==2)
  {
  	cout <<"Whatever fears you had for mankind quickly dissipated.\nYou realized that humans were no different than any other regular beast you had once preyed upon.\nWhen placed back your cage, you'd no longer cower in fear, but instead, seek your freedom.\nSo you dug and dug until eventually, you saw light again and in that light was a crowd of prey.\nDay after day you'd make the city your hunting ground,\nhiding in the dark before remerging to drag more victims under to never to be seen again.\nUnfortunately, the amount food here wasn't limited.\nYou'd eventually leave with nothing but silent ruins behind you...";
  }
  else if(player_race==3)
  {
  	cout <<"The day of your capture was the day you lost your pride as the apex predator\nand the more you thought about it the madder you became until finally, you lashed out.\nThe crowd above screeched in terror as you lept upon them,\ntearing apart and devouring those within your paws reach.\n On that day you saw man as nothing more than rats who'd stolen your right as the king of beasts.\nYou'd rip, tear, and maw every human you could find, no matter where they hid.\nYou'd forsake their city until their king lay dead\n and their soft bodies were displayed across their homes,\nforever serving as an example of who the real king of beasts is...";
  }
}
}
system ("pause");
system ("CLS");
reset_stats(); 
cout << "\nWould you like to play again? (Y/N)\n";
cin>> retry;
system ("CLS");
}
while(retry=='y'||retry=='Y');
return(0);
}   

//-------------------------------------------------------------------------------------------Preparing Stats   

void intro()     
{   
    cout << "You are a predator, a being that nature had designed to live freely in her realm of survival,\nhunting your prey no matter what form it chose.\nExcept for one: man. Unlike many beasts, you acknowledged the dangers of the human race and knew not to provoke.\nYet you were still hunted by them and eventually found yourself falling into one of their devious traps like your prey.\nBut instead of having you killed outright and turned into just another trophy,\nyou were loaded in a wagon and dragged away from your home.\nYou had a good idea where they were taking you and your fears eventually became reality.\nLush jungles were replaced with the dens of man between roads made of stone,\ntheir residents gawking at you in awe like a prize.\nIt was a relief when they finally placed you in your prison.\nYou didn't know what hole you'd been left in,\nbut that mystery would soon be revealed when the gate raised up and you heard the sounds of cheering from the outside...\n\nWARNING!!!!! When it comes to choices do not type letters, or the game will break.\n\n";   
    system ("pause");   
    system ("CLS");   
}   

void character_choice()   
{     
    do   

    {   

    cout << "What are you?\n\n1.Basilisk(Moderate)\n2.Scorpio(Hard)\n3.Manticore(Easy)\n";   
    cin >> player_race;   

    if(player_race>3 || player_race<=0)   

    {   
    cout<<"\n\nInvaild choice.";   
   }   
  
   }   

    while(player_race>3 || player_race<=0);    
}   

void get_stats()   
{   

    if(player_race==1)  

    {  
    player_maxHP=200; 
    player_HP=200;   
    player_DPS1=10;   
    player_DPS2=24;   
    cout << "\n\nYou are a Basilisk!\n\nYour current states are:\nHP:" << player_HP << "\nDPS:" << player_DPS1 <<" - " << player_DPS2 << "\n\n";  
   }      

   if(player_race==2)  
   {  
    player_maxHP=120; 
    player_HP=120;    
    player_DPS1=15;   
    player_DPS2=31;   
    cout << "\n\nYou are a Scorpio!\n\nYour current states are:\nHP:" << player_HP << "\nDPS:" << player_DPS1 <<" - " << player_DPS2 << "\n\n";  
   }
   
   if(player_race==3)  
   {  
    player_maxHP=160; 
    player_HP=160;    
    player_DPS1=14;   
    player_DPS2=28;   
    cout << "\n\nYou are a Manticore!\n\nYour current states are:\nHP:" << player_HP << "\nDPS:" << player_DPS1 <<" - " << player_DPS2 << "\n\n";  
   }              

    system ("pause");   
    system ("CLS");   

}   

void get_enemy_stats()   
{   

if(matches==1) 
{ 
    cout << "A weak looking gladiator wearing a heavy helmet and wielding a short sword steps into the arena.\n\n";   
    enemy_maxHP=60;
	enemy_HP=60;   
    enemy_DPS1=5;   
    enemy_DPS2=12;   
    system ("pause");   
    system ("CLS");       
} 

else if(matches==2) 
{ 
cout << "A more skilled looking gladiator wearing a light armor and wielding an axe steps into the arena.\n\n";
enemy_maxHP=150;   
enemy_HP=150;   
enemy_DPS1=15;   
enemy_DPS2=25;   
system ("pause");   
system ("CLS");  
}

else if(matches==3)
{
cout << "The third gladiator to enter has a lot more muscle to them and wields a claymore.\n\n";
enemy_maxHP=300;   
enemy_HP=300;   
enemy_DPS1=30;   
enemy_DPS2=50;   
system ("pause");   
system ("CLS");  
}


else if(matches==4)
{
cout << "The fourth gladiator is just as muscular as the last,\nbut well equipped in thick looking silver armor and wields two long swords.\n\n";
enemy_maxHP=500;   
enemy_HP=500;   
enemy_DPS1=45;   
enemy_DPS2=75;   
system ("pause");   
system ("CLS");  
}


else if(matches==5)
{
cout << "The crowd's cheers seemed a lot louder than usual and you soon saw why.\nThe next warrior to enter the arena dawned armor comprised of steel and gold.\nHis muscular form bore many scars and his weapons comprised of a sharp steel spear and large iron shield.\nJudging from the crowd and this humans gear,\nyou dare fancy a guess that this was the arena champion.\n\n";
enemy_maxHP=800;   
enemy_HP=800;   
enemy_DPS1=40;   
enemy_DPS2=80;   
system ("pause");   
system ("CLS"); 
 } 

}    

//-------------------------------------------------------------------------------------------Preparing Stats    

//-------------------------------------------------------------------------------------------Combat   

void player_turn()   
{   
  
do 
{  

//-------------------------------------------------------------------------------------------Scorpio Skills  

if(player_race==2)  
{
    cout << "Player\nHP:" << player_HP << "\n\nEnemy\nHP:" << enemy_HP;   
    cout << "\n\n\nAttacks:\n1. Clip\n2. Posion Tail\n"; 
    
	if(max_Skills>2 && new_skill1==1) 
    { 
        cout<< "3. Triple Strike\n"; 
    } 

    else if(max_Skills>2 && new_skill1==2) 
    { 
        cout <<"3. Burrow\n"; 
    }
	
	
	 if(new_skill3==1)
	 {
	    cout << "4. Razor Back Burrow\n";
	 }      

    cin >> player_skill;   

    if(player_skill==1)     

    {   
    srand ((unsigned)time(NULL));   
    damage=rand()% (player_DPS2 - player_DPS1) + player_DPS1;  
    }     
    
	else if(player_skill==2)   
    {   
     damage=rand()% (player_DPS2 - player_DPS1) + player_DPS1;   
     scorpio_posion=3;  
    }     
 

    else if(player_skill==3) 
    {  

    if(new_skill1==1) 
    { 
     damage=rand()% (player_DPS2 - player_DPS1) + player_DPS1; 
     damage=(damage*3);    
    } 

    else if(new_skill1==2) 
    { 
    damage=0; 
    Heal=(player_maxHP*0.2); 
	if(burrow_wait>0)
	{
		cout<< "\n\nYou don't recover any HP.\n";
	 }
	 else
	 {
	 	cout << "\n\nYou recover " << Heal << " HP.\n";
	 	player_HP=(player_HP + Heal);  
	  }  
    safe='t';
	attack='f';
	burrow_wait=(burrow_wait=2);  
   
    if(player_HP>player_maxHP) 
    { 
        player_HP=player_maxHP; 
    }   
    } 
    }
	 

else if(player_skill==4)
{
	damage_multi=rand()%7 + 2;
	damage=rand()% (player_DPS2 - player_DPS1) + player_DPS1; 
    damage=(damage*damage_multi);  
	
 } 
}   

//-------------------------------------------------------------------------------------------Scorpio Skills  
  

//-------------------------------------------------------------------------------------------Basilisk Skills  

if(player_race==1)  
{  
    cout << "Player\nHP:" << player_HP << "\n\nEnemy\nHP:" << enemy_HP;   
    cout << "\n\n\nAttacks:\n1. Bite\n2. Tail Spines\n"; 
      

    if(new_skill1==1) 
      {
	cout<<"3. Medusa's Gaze\n";
      }

    else if(new_skill1==2) 
     {
	cout<<"3. Stormbreath\n";
     }
     
	 if(new_skill2==1)
     {
       cout<< "4. Nerve Breath\n";
	 }
     
     else if(new_skill2==2)
     {
     	cout<< "4. Corrosion Spit\n";
	 }
	 
	 if(new_skill3==1)
	 {
		cout<< "5. Flame Breath\n";
	 }

    cin >> player_skill; 

    if(player_skill==1)   
    {   
    srand ((unsigned)time(NULL));   
    damage=rand()% (player_DPS2 - player_DPS1) + player_DPS1;   
    }   

    else if(player_skill==2)   
    {   
     damage=rand()% (player_DPS2 - player_DPS1) + player_DPS1;   
     damage=(damage*2);   
    }
	else if(player_skill==3)
	{
		if(new_skill1==1)
		{
			petrified_chance=rand()% 2;
			if(petrified_chance==1)
			{
			petrified_effect=(petrified_effect+2);
			cout << "\n\nSuccess!\n";
		    }
		    else
		    {
		    	cout << "\n\nFail!\n";
			}
			damage=0;
		}
		
		if(new_skill1==2)
		{
			damage=rand()% (player_DPS2 - player_DPS1) + player_DPS1;   
            lighting_multi=rand()% 2;
            
			if(lighting_multi==1)
			{
			 damage=(damage*5);
			}
			else
			{
				damage=(damage/2);
			}
			spark='t'; 
		}
	 }
	 else if(player_skill==4)
	 {
	 	if(new_skill2==1)
	 	{
	 		cout<<"\n\nYou take a deep breath before dousing your oppent in a pinkish-white smoke that causes their attacks to be uneven.\n";
	 		nerve_breath='t';
	 		damage=(damage=0);
		 }
		 
		 else if(new_skill2==2)
		 {
		 	cout<<"\n\nYou douse your oppent in a strange green fluid.\n";
		 	corrosion_timer=(corrosion_timer=3);
		 	damage=(damage=0);
		 }
	  }
	  else if(player_skill==5)
	  {
	  	burning=(burning=3);
	  	damage=rand()% (player_DPS2 - player_DPS1) + player_DPS1;
		spark='t';   
	   } 

}  
//-------------------------------------------------------------------------------------------Basilisk Skills

//-------------------------------------------------------------------------------------------Manticore Skills 
if(player_race==3)
{
	cout << "Bleed Effect: " << bleed_amount << "%\n";
	cout << "Player\nHP:" << player_HP << "\n\nEnemy\nHP:" << enemy_HP;   
    cout << "\n\n\nAttacks:\n1. Tear\n2. Drain\n";
	
	    if(new_skill1==1) 
      {
	cout<<"3. Puncture\n";
      }
      else if(new_skill1==2)
      {
      	cout<<"3. Pounce\n";
	  }
	  if(new_skill3==1)
	  {
	  	cout<<"4. Blood Crazed\n";
	  }
	
	cin >> player_skill;
	
	if(player_skill==1)
	{
		damage=rand()%(player_DPS2 - player_DPS1) + player_DPS1;
		damage=(damage*2);   
		
	}
	
	if(player_skill==2)
	{
		damage=rand()%(player_DPS2 - player_DPS1) + player_DPS1; 
		player_HP=(player_HP + damage);
		cout << "\n\nYou steal " << damage << " HP from your opponent.\n";
	  }
	else if(player_skill==3)
	{
		if(new_skill1==1)
		{
			damage=rand()%(player_DPS2 - player_DPS1) + player_DPS1;
			bleed_amount=(bleed_amount+25);
			
		}
		else if(new_skill1==2)
		{
			damage=rand()%(player_DPS2 - player_DPS1) + player_DPS1;
			stun_chance=rand()%2;
			
		}
	}
	else if(player_skill==4)
	{
		damage=rand()%(player_DPS2 - player_DPS1) + player_DPS1;
		damage=(damage*3);
		instant_bleed=rand()%5;
		
		if(instant_bleed>=4)
		{
			bleed_amount=(bleed_amount+100);
		}
		
	}
   }
//-------------------------------------------------------------------------------------------Manticore Skills    

   if(player_skill>max_Skills) 
   { 
       cout<< "\n\nInvalid choice.\n"; 
   } 

   else 
   {
   if(corrosion_timer>0)
   {
   	damage=(damage*2);
   	corrosion_timer--;
	} 
   cout << "\n\nYou deal " << damage << " Damage.\n\n";   
   enemy_HP=(enemy_HP - damage);   
   system ("pause");   
} 

} 
while(player_skill>max_Skills); 
}   

//-------------------------------------------------------------------------------------------Player Debuffs  
void player_debuffs()  
{

//-------------------------------Scorpio Debuffs
if(leech=='t')
   {
	   if(leech_timer==2)
   	{
   		if(attack=='t')
   		{
		   
   		leech_timer=0;
   		player_HP=(player_HP+damage);
   		cout<<"\n\nYour attack steals " << damage << " HP.\n";
   		system ("pause");
   		}
	   }
	else
   	{
   		leech_timer++;
	   }
	 }  

    if(scorpio_posion>0)  
    {
	
	if(gift_of_the_mamba=='t')
	{
		srand ((unsigned)time(NULL));   
    damage=rand()% (player_DPS2 - player_DPS1) + player_DPS1;  
    damage=(damage*2);
	}
	
	else
	{  
    srand ((unsigned)time(NULL));   
    damage=rand()% (player_DPS2 - player_DPS1) + player_DPS1;  
    damage=(damage/2);
    }
    scorpio_posion--;
	
	if(paralysis=='t')
	{
		srand ((unsigned)time(NULL));   
    paralysis_chance=rand()% 2;  
	 }
	 if(paralysis_chance==1)
	 {
	 enemy_paralyzed='t';
     }

   cout << "\n\nYour posion deals " << damage << " Damage.\n\n";   
   enemy_HP=(enemy_HP - damage);   
   system ("pause");   
    }
//-------------------------------Scorpio Debuffs	
//-------------------------------basilisk Debuffs

if(nerve_breath=='t')
{

if(spark=='t')
{
	spark_chance=rand()% 2;
	damage=rand()% (player_DPS2 - player_DPS1) + player_DPS1;
	if(spark_chance==1)
	{
		damage=(damage*4);
		cout<<"\n\nYour attack results in a massive explosion dealing " << damage << " damage.";
		enemy_HP=(enemy_HP - damage);
		nerve_breath='f'; 
	 } 
}
}
if(burning>0)
{
	damage=rand()% (player_DPS2 - player_DPS1) + player_DPS1;
	damage=(damage*4);
	
	cout << "\n\nYour flames deal " << damage << " Damage.\n\n";   
   enemy_HP=(enemy_HP - damage);   
   system ("pause");    
}

//-------------------------------basilisk Debuffs
//-------------------------------manticore Debuffs
if(bleed_amount>=100)
{
	bleed_amount=0;
    enemy_HP=(enemy_HP-enemy_maxHP/5);
    cout<<"\n\nHaving lost a great deal of blood the gladiator is decreased 20% of their current HP.\n\n";
	system ("pause");  
	
}
if(agile=='t')
{
	agile_chance=rand()%5;
}

//-------------------------------manticore Debuffs

attack='t';
spark='f';
burrow_wait--;
}   

//-------------------------------------------------------------------------------------------Player Debuffs  

void enemy_turn()   
{   

    if(enemy_HP<=0)   
    {   
        cout <<"\n\nThe gladiator collapses in defeat!\n\n";   
    }   

    else if(safe=='t') 
    { 
    cout <<"\n\nThe gladiator was unable to attack you.\n\n";   
    safe='f'; 
    }
	
	else if(enemy_paralyzed=='t') 
	{
		enemy_paralyzed='f';
		cout<<"\n\nThe gladiators body starts to tremble as he struggles to move just his arm.";
	}
	else if(petrified_effect>0)
	{
		petrified_effect--;
		cout<<"\n\nThe gladiator is frozen like a statue.\n\n";
	}
	else if(stun_chance>=1)
	{
		cout<<"\n\nThe gladiator is still in a daze from being knocked to the ground.\n\n";
		stun_chance=(stun_chance=0);
	}
	else if(agile_chance>=4)
	{
		cout<<"\n\nThe gladiator makes a move to attack, but all his weapon strikes down is air as you bounce away from his swing.\n\n";
		agile_chance=(agile_chance=0);
	}

    else   
    {   
    srand ((unsigned)time(NULL)); //initializes random function    
    int damage=rand()% (enemy_DPS2 - enemy_DPS1) + enemy_DPS1;
	if(dragon_hide=='t')
	{
		damage=(damage/2);
	   }
	if(nerve_breath=='t')
	{
		damage=(damage*0.75);
	   }   

   if(matches==1)
   {
   	cout << "\n\nThe weak looking gladiator swings his sword,\nmanging to get a cut in that deals " << damage << " damage.\n\n";
	  }
	 else if(matches==2)
	 {
	 	cout<<"\n\nThe gladiator hurls himself at you,\nswinging his axe atop of you that deals " << damage << " damage.\n\n";
	 	
	 }
	 else if(matches==3)
	 {
	 	cout<<"\n\nDespite the weight of his sword, the gladiator is rather quick,\nmanaging to get it range to swing his long blade dealing " << damage << " damage.\n\n";
	 }
	 else if(matches==4)
	 {
	 	cout<<"\n\nThe Gladiator charges at you,\nleaping from the ground and dealing multiple stabs dealing " << damage << " damage.\n\n";
	 }
	 else if(matches==5)
	 {
	 	cout<<"\n\nThe arena champ hurls his spear at you, impaling a part of your body before charging in,\nfollowing his attack by ramming his shield into you and retrieving his weapon before leaping back\ndealing " << damage << " damage.\n\n";
	 }
   player_HP=(player_HP - damage);
   if(razor_fur=='t')
   {
   	damage=(damage/2);
   	enemy_HP=(enemy_HP - damage);
   	cout << "\n\n He also takes " << damage << " damage.\n\n";
   	bleed_amount=(bleed_amount+5);
	  }   
    }     
   system ("pause");   
   system ("CLS");   

if(player_HP<=0)  
{  

cout<< "You have lost....\n\n";  
system ("pause");   
system ("CLS");   

}  

}   

//-------------------------------------------------------------------------------------------Combat   

void fate()
{
	cout << "The warrior lays before you beaten, but not dead. How shall you make of him?\n1. Mercy\n2. Slaughter\n";
	do
	{
	
	cin >> fate_choice;
	
	if(fate_choice==1)
	{
		cout<<"\n\nYou've done enough and back away from your beaten opponent.\nEventually, they are taken away by the guards and your placed back into your cage.\n";
		Good_Karma++;
	}
	
	else if(fate_choice==2)
	{
		if(player_race==1)
		{
			cout<<"\n\nWith a swing of your tale, you let your created spines fly, impaling the warrior in the dirt.\nThey begin choking on their blood as they attempt to free themselves,\nbut eventually go limp.\n";
		}
		else if(player_race==2)
		{
			cout<<"\n\nYou hurl your tail at the gladiator, impaling their chest.\nYou proceed to lift your prey in the air as they become filled with your posion's\nbefore dropping them to the ground as a nearly liquefied mess.\n";
		}
		if(player_race==3)
		{
			cout<<"\n\nYou have no sympathy for the beaten mortal.\nYou pounce atop of them and rip them to pieces.\nThe guards had to force you back into your cage while you attempt to devour what remains of your opponent.\n";
		}
		Bad_Karma++;
	}
	
	else if(fate_choice>2)
	{
		cout<< "Choice invalid.\n";
	}
}
while(fate_choice>2);
matches++;  
system ("pause");   
system ("CLS");
}

void recover() 
{ 
    player_HP=player_maxHP; 
    scorpio_posion=0;
	leech_timer=0;
	burning=0; 
} 

void level_up() 
{ 

cout << "You've gained a level. Select a new skill.\n\n";  
level++; 

//-------------------------------------------------------------------------------------------New Skill 1
//-------------------------------------------------------------------------------------------Basilisk 
if(level==2) 
{ 
max_Skills++;

    if(player_race==1) 
    {
	cout << "1.Medusa's Gaze\n2.Stormbreath\n\n";
	cout << "Medusas Gaze - 50% chance to paralyze opponent for 2 turns.\n\nStorm Breath - Does normally low damage with a 50% chance to deal 5X normal damage.\n";     
    } 
//-------------------------------------------------------------------------------------------Basilisk  

//-------------------------------------------------------------------------------------------Scorpio
    else if(player_race==2) 
    { 
    cout << "1.Triple strike\n2.Burrow\n\n"; 
    cout << "Triple Strike - Deal 3X normal damage.\n\nBurrow - Avoid taking damage. Heal 20% HP. Wait two turns to use again.\nUsing to early will reset the wait.\n"; 
    } 
//-------------------------------------------------------------------------------------------Scorpio

//-------------------------------------------------------------------------------------------Manticore
else if(player_race==3)
{
	cout<<"1.Puncture\n2.Pounce\n\n";
	cout<<"Puncture - Deal regular damage with a 25% increase to bleed.\n\nPounce - Deal regular damage with a 50% chance to stun opponent for 1 turn.\n"; 
  }  

//-------------------------------------------------------------------------------------------Manticore   

    do 
    { 
    cin >> new_skill1; 
    if(new_skill1>2 || new_skill1<=0) 
    { 
     cout << "Choice invalid.\n"; 
    }    
    } 

    while(new_skill1>2 || new_skill1<=0); 
}
//-------------------------------------------------------------------------------------------New Skill 1

//-------------------------------------------------------------------------------------------New Skill 2
if(level==3)
{
//-------------------------------------------------------------------------------------------Basilisk
	if(player_race==1) 
	{
		max_Skills++;
		cout<<"1.Nerve Breath\n2.Corrosion Spit\n\n";
		cout<<"Nerve Breath - Lowers Opponents DPS by 25%. Has a 50% chance of exploding if magic attacks\nare dealt dealing 4X the damage.\n\nCorrosion Spit lowers opponents defense increasing all damage delt 2X for 3 turns.\n";	
	}
//-------------------------------------------------------------------------------------------Basilisk

//-------------------------------------------------------------------------------------------Scorpio 
	 else if(player_race==2) 
	 {
	 	cout<<"1.Leech\n2.Gift of the Mamba\n\n";
	 	cout<<"Leech - Attacks Steal HP every second turn.\n\nGift of the Mamba - Posion deals 200% more damage.\n";
	 }
//-------------------------------------------------------------------------------------------Scorpio 

//-------------------------------------------------------------------------------------------Manticore
else if(player_race==3)
{
	cout<<"1.Razor Fur\n2.Agile\n\n";
	cout<<"Razor Fur - If damaged 50% is reflected back to the opponent along with a 5% increase to bleed.\n\nAgile - 25% chance to avoid taking damage.\n"; 
  }   

//-------------------------------------------------------------------------------------------Manticore 
	 do 
    { 
    cin >> new_skill2; 
    if(new_skill2>2 || new_skill2<=0) 
    { 
     cout << "Choice invalid.\n"; 
    }    
    } 

    while(new_skill2>2 || new_skill2<=0);

if(player_race==2)
{
if(new_skill2==1)
{
	 leech='t';
}

else if(new_skill2==2)
{
	gift_of_the_mamba='t';
}
}
else if(player_race==3)
{
	if(new_skill2==1)
	{
		razor_fur='t';
	}
	else if(new_skill2==2)
	{
		agile='t';
	}
}

}
//-------------------------------------------------------------------------------------------New Skill 2 

//-------------------------------------------------------------------------------------------New Skill 3
if(level==4)
{
//-------------------------------------------------------------------------------------------Basilisk
   if(player_race==1) 
    {
    	cout<<"1.Flame Breath\n2.Dragon Hide\n\n";
    	cout<<"Flame Breath - does regular damage and will inflict burn on oppent for 3 turns dealing 4X the damage each turn.\n\nDragon Hide - Oppents damage is reduced by 50%.\n";
     }
//-------------------------------------------------------------------------------------------Basilisk

//-------------------------------------------------------------------------------------------Scorpio 
      else if(player_race==2)
	  {
	  	cout<<"1.Razor Back Burrow\n2.Paralysis\n\n";
	  	cout<<"Razor Back Burrow - chance to deal between 2 - 9X normal damage.\nParalysis - posion damage will have a 50% chance to stun oppenent for 1 turn.\n";
	   }
//-------------------------------------------------------------------------------------------Scorpio 

//-------------------------------------------------------------------------------------------Manticore
else if(player_race==3)
{
	cout<<"1.Blood Crazed\n2.Kings Pride\n\n";
	cout<<"Blood Crazed - Deal damage X3 with a 25% to inflict instant bleed.\n\nKings Pride - All current stats are doubled.\n";
  }   

//-------------------------------------------------------------------------------------------Manticore 
	   
	   do 
    { 
    cin >> new_skill3; 
    if(new_skill3>2 || new_skill3<=0) 
    { 
     cout << "Choice invalid.\n"; 
    }    
    }

    while(new_skill3>2 || new_skill3<=0);

if(player_race==2)
{

if(new_skill3==2)
{
	paralysis='t';
}
else if(new_skill3==1)
{
	max_Skills++;
   }
}
   
if(player_race==1)
   {
   	if(new_skill3==2)
   	{
   		dragon_hide='t';
	   }
	else
	{
		max_Skills++;
	}
   	
   }
   
   if(player_race==3)
   {
   	if(new_skill3==1)
   	{
   		max_Skills++;
	   }
	else if(new_skill3==2)
	{
	 player_maxHP=(player_maxHP+player_maxHP*2); 
     player_HP=player_maxHP;
	 player_DPS1=(player_DPS1 + player_DPS1*2); 
     player_DPS2=(player_DPS2 + player_DPS2*2);  
	}
   }
  }
//-------------------------------------------------------------------------------------------New Skill 3  

system ("CLS");  
cout << "What stat would you like boosted?\n1.HP\n2.Damage\n"; 
cin >> Boost_Choice; 

if(Boost_Choice==1) 
{ 
    player_maxHP=(player_maxHP+player_maxHP*0.25); 
    player_HP=player_maxHP; 
} 
else if(Boost_Choice==2) 
{ 
    player_DPS1=(player_DPS1 + player_DPS1*0.25); 
    player_DPS2=(player_DPS2 + player_DPS2*0.25); 
} 
}

void reset_stats()
{
player_HP=0,player_maxHP=0,player_DPS1=0,player_DPS2=0,player_race=0,player_skill=0;   
enemy_HP=0,enemy_maxHP=0,enemy_DPS1=0,enemy_DPS2=0;   
matches=1;   
damage=0;  
Heal=0; 
level=1; 
new_skill1=0,new_skill2=0,new_skill3=0; 
max_Skills=2; 
Boost_Choice=0; 
Bad_Karma=0,Good_Karma=0,fate_choice=0;

safe='f'; 
attack='t';
  

//-------------------------------------------------------------------------------------------Player Debuffs  

 scorpio_posion=0;
 leech_timer=0;
 paralysis_chance=0;
 damage_multi=0;
 lighting_multi=0;
 petrified_chance=0;
 petrified_effect=0;
 burning=0;
 spark_chance=0;
 corrosion_timer=0;
 bleed_amount=0;
 stun_chance=0;
 agile_chance=0;
 instant_bleed=0;
 burrow_wait=0;

 leech='f';
 gift_of_the_mamba='f';
 paralysis='f';
 enemy_paralyzed='f';
 dragon_hide='f';
 spark='f';
 nerve_breath='f';
 razor_fur='f';
 agile='f';
 retry='n';	
 } 
