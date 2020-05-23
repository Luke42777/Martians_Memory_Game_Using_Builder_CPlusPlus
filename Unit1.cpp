//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "mmsystem.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int howMany = 0; // describing how many bulbs  needs to be shown in sequence
bool gameOpened = false;
int numbers[1000];
int counter = 0;
//---------------------------------------------------------------------------
void playSequence()
{
    Application->ProcessMessages(); //to screen be responsive whilst waiting
    Sleep(1000);
    Form1->b1->Picture->LoadFromFile("img/p1.bmp");
    Form1->b2->Picture->LoadFromFile("img/p2.bmp");
    Form1->b3->Picture->LoadFromFile("img/p3.bmp");
    Form1->b4->Picture->LoadFromFile("img/p4.bmp");
    Form1->b5->Picture->LoadFromFile("img/p5.bmp");


    // all bulbs (non-On) are disabled
    Form1->b1->Enabled = false;
    Form1->b2->Enabled = false;
    Form1->b2->Enabled = false;
    Form1->b2->Enabled = false;
    Form1->b2->Enabled = false;

    //counting before showing sequence
    Form1->Label1->Caption = "Next round in 2:";
    Application->ProcessMessages(); //to screen be responsive whilst waiting(no freezing)
    Sleep(1000);
      Form1->Label1->Caption = "Next round in 1:";
    Application->ProcessMessages(); //to screen be responsive whilst waiting
    Sleep(1000);

     Form1->Label1->Caption = "Remember sequence";
     Application->ProcessMessages(); //to screen be responsive whilst waiting
     Sleep(1000);
     howMany++;

     for(int i = 0; i < howMany;i++)
     {
        switch(numbers[i])
        {
                case 1:
                        {
                         sndPlaySound("snd/d1.wav",SND_ASYNC);
                         Form1->b1On->Visible = true;
                         break;
                        }

                case 2:
                        {
                         sndPlaySound("snd/d2.wav",SND_ASYNC);
                         Form1->b2On->Visible = true;
                         break;
                        }

                case 3:
                        {
                         sndPlaySound("snd/d3.wav",SND_ASYNC);
                         Form1->b3On->Visible = true;
                         break;
                        }

                case 4:
                       {
                         sndPlaySound("snd/d4.wav",SND_ASYNC);
                         Form1->b4On->Visible = true;
                         break;
                       }

                case 5:
                      {
                        sndPlaySound("snd/d5.wav",SND_ASYNC);
                        Form1->b5On->Visible = true;
                        break;
                      }

          } //switch
          Application->ProcessMessages();
          Sleep(1200);

          Form1->b1On->Visible = false;
          Form1->b2On->Visible = false;
          Form1->b3On->Visible = false;
          Form1->b4On->Visible = false;
          Form1->b5On->Visible = false;

          Application->ProcessMessages();
          Sleep(100); // in case the same number is shown so we need to let the bulb swich off
     } //for

    //they must enabled again otherwise  user cannot provide his choice of bulbs sequence
    Form1->b1->Enabled = true;
    Form1->b2->Enabled = true;
    Form1->b2->Enabled = true;
    Form1->b2->Enabled = true;
    Form1->b2->Enabled = true;

    Form1->Label1->Caption = "Reapeat sequence";
    counter = 0;
}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
    randomize();

    for(int i = 0; i < 1000;i++)
    {
       numbers[i] = random(5) + 1;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Label1Click(TObject *Sender)
{
  if(gameOpened == false)
      {
         gameOpened = true;
         sndPlaySound("snd/start.wav",SND_ASYNC);
         playSequence();
      }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::b1Click(TObject *Sender)
{

    if(gameOpened == true)
    {
         counter++;
        if(numbers[counter - 1] != 1) //loose condition
         {
           howMany--; // that should be decremented before shown in the next instruction
           Label1->Caption = "You loose. Score: " + IntToStr(howMany);
           sndPlaySound("snd/koniec.wav",SND_ASYNC);
           gameOpened = false;
         }
         if(counter == howMany)
         {
            Label1->Caption = "Well done";
            playSequence();

         }

    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::b2Click(TObject *Sender)
{
   
    if(gameOpened == true)
    {
         counter++;
        if(numbers[counter - 1] != 2) //loose condition
         {
           howMany--; // that should be decremented before shown in the next instruction
           Label1->Caption = "You loose. Score: " + IntToStr(howMany);
           sndPlaySound("snd/koniec.wav",SND_ASYNC);
           gameOpened = false;
         }
         if(counter == howMany)
         {
            Label1->Caption = "Well done";
            playSequence();

         }

    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::b3Click(TObject *Sender)
{
  
    if(gameOpened == true)
    {
         counter++;
        if(numbers[counter - 1] != 3) //loose condition
         {
           howMany--; // that should be decremented before shown in the next instruction
           Label1->Caption = "You loose. Score: " + IntToStr(howMany);
           sndPlaySound("snd/koniec.wav",SND_ASYNC);
           gameOpened = false;
         }
         if(counter == howMany)
         {
            Label1->Caption = "Well done";
            playSequence();

         }

    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::b4Click(TObject *Sender)
{
  
    if(gameOpened == true)
    {
         counter++;
        if(numbers[counter - 1] != 4) //loose condition
         {
           howMany--; // that should be decremented before shown in the next instruction
           Label1->Caption = "You loose. Score: " + IntToStr(howMany);
           sndPlaySound("snd/koniec.wav",SND_ASYNC);
           gameOpened = false;
         }
         if(counter == howMany)
         {
            Label1->Caption = "Well done";
            playSequence();
         }

    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::b5Click(TObject *Sender)
{
    
    if(gameOpened == true)
    {
         counter++;
        if(numbers[counter - 1] != 5) //loose condition
         {
           howMany--; // that should be decremented before shown in the next instruction
           Label1->Caption = "You loose. Score: " + IntToStr(howMany);
           sndPlaySound("snd/koniec.wav",SND_ASYNC);
           gameOpened = false;
         }
         if(counter == howMany)
         {
            Label1->Caption = "Well done";
            playSequence();

         }

    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::b1MouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
    b1->Picture->LoadFromFile("img/p1a.bmp");
    sndPlaySound("snd/d1.wav",SND_ASYNC);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::b1MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
    b1->Picture->LoadFromFile("img/p1.bmp");
}
//---------------------------------------------------------------------------



void __fastcall TForm1::b2MouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
     b2->Picture->LoadFromFile("img/p2a.bmp");
    sndPlaySound("snd/d2.wav",SND_ASYNC);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::b2MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
       b2->Picture->LoadFromFile("img/p2.bmp");
}
//---------------------------------------------------------------------------



void __fastcall TForm1::b3MouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
        b3->Picture->LoadFromFile("img/p3a.bmp");
    sndPlaySound("snd/d3.wav",SND_ASYNC);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::b3MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
     b3->Picture->LoadFromFile("img/p3.bmp");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::b4MouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
     b4->Picture->LoadFromFile("img/p4a.bmp");
    sndPlaySound("snd/d4.wav",SND_ASYNC);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::b4MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
          b4->Picture->LoadFromFile("img/p4.bmp");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::b5MouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
         b5->Picture->LoadFromFile("img/p5a.bmp");
         sndPlaySound("snd/d5.wav",SND_ASYNC);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::b5MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
         b5->Picture->LoadFromFile("img/p5.bmp");
}
//---------------------------------------------------------------------------

