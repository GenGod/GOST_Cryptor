//---------------------------------------------------------------------------

#include <vcl.h>

#include "Kuznechik.cpp"
#pragma hdrstop

#include "FormUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

//---------------------------------------------------------------------------

bool TForm1::CheckOption()
{
	bool errf=false;
	if (!FileExists(OpenDialogFile->FileName, false))
	{
		LogMemo->Lines->Add("ERR: File "+OpenDialogFile->FileName+" not found!");
		errf=true;
	}

	if (errf)
		return false;
	else
		return true;
}
//---------------------------------------------------------------------------

__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button2Click(TObject *Sender)
{
	LogMemo->Clear();
    LogMemo->Lines->Add("Log:\n");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::OpenFileButtonClick(TObject *Sender)
{
	if (OpenDialogFile->Execute())
	{
		UnicodeString temp=OpenDialogFile->FileName;
		temp= temp.SubString(temp.LastDelimiter("\\")+1,temp.Length()-temp.LastDelimiter("\\"));
		LabelFileName->Caption=temp;
		LogMemo->Lines->Add("INF: Open "+OpenDialogFile->FileName+" as base file.");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::OpenTableButtonClick(TObject *Sender)
{
	if (OpenDialogTable->Execute())
	{
		UnicodeString temp=OpenDialogTable->FileName;
		temp= temp.SubString(temp.LastDelimiter("\\")+1,temp.Length()-temp.LastDelimiter("\\"));
		LabelTableName->Caption=temp;
		LogMemo->Lines->Add("INF: Open "+OpenDialogTable->FileName+" as crypt table.");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::OpenKeyButtonClick(TObject *Sender)
{
	if (OpenDialogKey->Execute())
	{
		UnicodeString temp=OpenDialogKey->FileName;
		temp= temp.SubString(temp.LastDelimiter("\\")+1,temp.Length()-temp.LastDelimiter("\\"));
		LabelKeyName->Caption=temp;

		LogMemo->Lines->Add("INF: Open "+OpenDialogKey->FileName+" as key.");

		if (RadioGroup1->ItemIndex!=0)
			RadioGroup1->ItemIndex=0;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::KeyEditChange(TObject *Sender)
{
	if (RadioGroup1->ItemIndex!=1)
		RadioGroup1->ItemIndex=1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioGroup1Click(TObject *Sender)
{
	if (RadioGroup1->ItemIndex==1)
	{
		LogMemo->Lines->Add("INF: Switch to manualy input key");
	}
	else if (RadioGroup1->ItemIndex==0)
	{
		LogMemo->Lines->Add("INF: Switch to read key from file");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TableButtonClick(TObject *Sender)
{
	if (!FileExists(OpenDialogTable->FileName, false))
		LogMemo->Lines->Add("ERR: File "+OpenDialogTable->FileName+" not found!");
	else
	{
		String filename=OpenDialogTable->FileName;

		FILE *f1=fopen(UnicodeToChar(filename), "rb");
		if (f1==NULL)
		{
			LogMemo->Lines->Add("ERR: Can not open file "+OpenDialogTable->FileName+" !");
			return;
		}
		StatusBar->SimpleText="Load Crypt table from"+OpenDialogTable->FileName;
		fread(kPi,sizeof(unsigned char),256,f1);
		fclose(f1);
	}
	StatusBar->SimpleText="Ready";
	if (!FileExists(OpenDialogReverseTable->FileName, false))
		LogMemo->Lines->Add("ERR: File "+OpenDialogReverseTable->FileName+" not found!");
	else
	{
		FILE *f1=fopen(UnicodeToChar(OpenDialogReverseTable->FileName), "rb");
		if (f1==NULL){
			LogMemo->Lines->Add("ERR: Can not open file "+OpenDialogReverseTable->FileName+" !");
			return;
		}
		StatusBar->SimpleText="Load Crypt table from"+OpenDialogReverseTable->FileName;
		fread(kReversePi,sizeof(unsigned char),256,f1);
		fclose(f1);
	}
	StatusBar->SimpleText="Ready";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::OpenReverseTableButtonClick(TObject *Sender)
{
	if (OpenDialogReverseTable->Execute())
	{
		UnicodeString temp=OpenDialogReverseTable->FileName;
		temp= temp.SubString(temp.LastDelimiter("\\")+1,temp.Length()-temp.LastDelimiter("\\"));
		LabelReverseTableName->Caption=temp;
		LogMemo->Lines->Add("INF: Open "+OpenDialogReverseTable->FileName+" as reverse crypt table.");
	}
}
//---------------------------------------------------------------------------

char* TForm1::UnicodeToChar(UnicodeString input)
{
	AnsiString a = input.c_str();
	char *b = a.c_str();
	return b;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CryptButtonClick(TObject *Sender)
{
	unsigned char masterKey[32];
	unsigned char keyStr[33];
	unsigned char keys[160];


	if (SaveDialog1->Execute())
	{
		LogMemo->Lines->Add("INF: Select "+SaveDialog1->FileName+" as output file.");
	}
	StatusBar->SimpleText="Read KEY";
	if (RadioGroup1->ItemIndex==0)
	{
		StatusBar->SimpleText="Load key from"+OpenDialogKey->FileName;
		FILE *f1=fopen(UnicodeToChar(OpenDialogKey->FileName), "rb");
		if (f1==NULL){
			LogMemo->Lines->Add("ERR: Can not open file "+OpenDialogKey->FileName+" !");
			return;
		}
		StatusBar->SimpleText="Load KEY from"+OpenDialogKey->FileName;
		fread(keyStr,sizeof(unsigned char),32,f1);
		fclose(f1);
	}
	else
	{
		strcpy(keyStr,UnicodeToChar(KeyEdit->Text));
    }
    for (int i = 0; i < 32; i++)
	{
		masterKey[i] = keyStr[i];
	}
	StatusBar->SimpleText="Crypting.......";

	LARGE_INTEGER start, finish, freq;
	QueryPerformanceFrequency( &freq );
	QueryPerformanceCounter( &start );

	struct stat buf;
	stat(UnicodeToChar(OpenDialogFile->FileName),&buf);
	int filesize=buf.st_size;
	ProgressBar->Max=filesize;

	FILE *f=fopen(UnicodeToChar(OpenDialogFile->FileName), "rb");
	FILE *fout=fopen(UnicodeToChar(SaveDialog1->FileName), "wb");
	if (f==NULL)
	{
		LogMemo->Lines->Add("ERR: Can not open file "+OpenDialogFile->FileName+" !");
		return;
	}
	if (fout==NULL)
	{
		LogMemo->Lines->Add("ERR: Can not open file "+SaveDialog1->FileName+" !");
		return;
	}
	long long lastper=-1;
	long long curper;
	double E =100.0/filesize * 100000.0 ;
	bool OneMore=false;
	bool flag=false;
	long long readsize=0;
	while (!flag)
	{
		unsigned char plainByte[16];

		int rlen=fread(plainByte,sizeof(unsigned char),16,f);
		if (feof(f))
		{
			if (rlen<=15)
			{
				plainByte[rlen]=1;
				++rlen;
				for (int i = rlen; i < 16; i++)
				{
					plainByte[i]=0;
				}
			}
			else
			{
				OneMore=true;
			}
		}
		int ek = ExpandKey(masterKey, keys);
		int ec = Encrypt(plainByte, keys);
		fwrite(plainByte,sizeof(unsigned char),16,fout);
		flag=feof(f);
		readsize+=rlen;
		curper=readsize*100/filesize-E;
		if (lastper<curper)
		{
			StatusBar->SimpleText="Crypting......."+IntToStr(curper+(int)E)+"%";
			lastper=curper+E;
		}

	}
	if (OneMore)
	{
		unsigned char plainByte[16]={1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
		int ek = ExpandKey(masterKey, keys);
		int ec = Encrypt(plainByte, keys);
		//cout<<".";
		fwrite(plainByte,sizeof(unsigned char),16,fout);
	}
	fclose(f);
	fclose(fout);

	QueryPerformanceCounter( &finish );
	// time - ����� � ��������
	double time = (finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
	ProgressBar->Position=ProgressBar->Max;
	StatusBar->SimpleText="Crypting ready in "+FloatToStr(time)+" sec.";

	LogMemo->Lines->Add("!\tCrypting done in-> "+FloatToStr(time)+" sec.");
	LogMemo->Lines->Add("\tsize of file-> "+IntToStr(filesize)+" byte");
	LogMemo->Lines->Add("\tspeed-> "+FloatToStr(filesize*8/time/1024/1024)+" Mbit per sec.");

}
//---------------------------------------------------------------------------

void __fastcall TForm1::DecryptButtonClick(TObject *Sender)
{
	unsigned char masterKey[32];
	unsigned char keyStr[33];
	unsigned char keys[160];

	if (SaveDialog1->Execute())
	{
		LogMemo->Lines->Add("INF: Select "+SaveDialog1->FileName+" as output file.");
	}
	StatusBar->SimpleText="Read KEY";
	if (RadioGroup1->ItemIndex==0)
	{
		StatusBar->SimpleText="Load key from"+OpenDialogKey->FileName;
		FILE *f1=fopen(UnicodeToChar(OpenDialogKey->FileName), "rb");
		if (f1==NULL){
			LogMemo->Lines->Add("ERR: Can not open file "+OpenDialogKey->FileName+" !");
			return;
		}
		StatusBar->SimpleText="Load KEY from"+OpenDialogKey->FileName;
		fread(keyStr,sizeof(unsigned char),32,f1);
		fclose(f1);
	}
	else
	{
		strcpy(keyStr,UnicodeToChar(KeyEdit->Text));
    }
    for (int i = 0; i < 32; i++)
	{
		masterKey[i] = keyStr[i];
	}
	StatusBar->SimpleText="Decrypting.......";

	LARGE_INTEGER start, finish, freq;
	QueryPerformanceFrequency( &freq );
	QueryPerformanceCounter( &start );

	struct stat buf;
	stat(UnicodeToChar(OpenDialogFile->FileName),&buf);
	int filesize=buf.st_size;
	ProgressBar->Max=filesize;

	FILE *fin=fopen(UnicodeToChar(OpenDialogFile->FileName), "rb");
	FILE *fout=fopen(UnicodeToChar(SaveDialog1->FileName), "wb");
	if (fin==NULL)
	{
		LogMemo->Lines->Add("ERR: Can not open file "+OpenDialogFile->FileName+" !");
		return;
	}
	if (fout==NULL)
	{
		LogMemo->Lines->Add("ERR: Can not open file "+SaveDialog1->FileName+" !");
		return;
	}
	ExpandKey(masterKey, keys);
	long long readsize=0;
    long long lastper=-1;
	long long curper;
	double E =100.0/filesize * 200000.0 ;
	bool flag=false;
	while (!flag)
	{
		unsigned char chipherByte[16];
		fread(chipherByte,sizeof(unsigned char),16,fin);
		readsize+=16;
		if (feof(fin))
			break;
		int dc = Decrypt(chipherByte, keys);
		int i=16;
		if (readsize==filesize)
			for ( i = 15; i >=0; i--)
				if (chipherByte[i-1]!=0)
				{
					--i;
					break;
				}
		fwrite(chipherByte,sizeof(unsigned char),i,fout);
		flag=feof(fin);
		curper=readsize*100/filesize-E;
		if (lastper<curper)
		{
			StatusBar->SimpleText="Decrypting......."+IntToStr(curper+(int)E)+"%";
			lastper=curper+E;
		}
	}
	fclose(fin);
	fclose(fout);

	QueryPerformanceCounter( &finish );
	// time - ����� � ��������
	double time = (finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
    ProgressBar->Position=ProgressBar->Max;
	StatusBar->SimpleText="Derypting ready in "+FloatToStr(time)+" sec.";

	LogMemo->Lines->Add("!\tDecrypting done in-> "+FloatToStr(time)+" sec.");
	LogMemo->Lines->Add("\tsize of file-> "+IntToStr(filesize)+" byte");
	LogMemo->Lines->Add("\tspeed-> "+FloatToStr(filesize*8/time/1024/1024)+" Mbit per sec.");

}
//---------------------------------------------------------------------------

