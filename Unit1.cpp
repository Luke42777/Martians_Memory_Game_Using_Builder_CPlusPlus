//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "mmsystem.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int level = 0; // describing how many bulbs  needs to be shown in sequence
bool gameOpened = false;
int numbers[1000];
//---------------------------------------------------------------------------
void playSequence()
{
    //first all bulbs (non-On) are disabled
    Form1->b1->Enabled = false;
    Form1->b2->Enabled = false;
    Form1->b2->Enabled = false;
    Form1->b2->Enabled = false;
    Form1->b2->Enabled = false;

    //counting before showing sequence
    Form1->Label1->Caption = "Next round in 2:";
    Application->ProcessMessages(); //to screen be responsive whilst waiting
    Sleep(1000);
      Form1->Label1->Caption = "Next round in 1:";
    Application->ProcessMessages(); //to screen be responsive whilst waiting
    Sleep(1000);

     Form1->Label1->Caption = "Remember sequence";
     Application->ProcessMessages(); //to screen be responsive whilst waiting
     Sleep(2000);
     level++;

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
