//---------------------------------------------------------------------------

#ifndef FormUnitH
#define FormUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Buttons.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TLabel *LabelFileName;
	TButton *OpenFileButton;
	TOpenDialog *OpenDialogFile;
	TLabel *LabelTableName;
	TButton *OpenTableButton;
	TOpenDialog *OpenDialogTable;
	TMemo *LogMemo;
	TRadioGroup *RadioGroup1;
	TButton *OpenKeyButton;
	TEdit *KeyEdit;
	TOpenDialog *OpenDialogKey;
	TLabel *LabelKeyName;
	TButton *CryptButton;
	TButton *DecryptButton;
	TSaveDialog *SaveDialog1;
	TButton *Button2;
	TStatusBar *StatusBar;
	TButton *TableButton;
	TLabel *LabelReverseTableName;
	TButton *OpenReverseTableButton;
	TOpenDialog *OpenDialogReverseTable;
	TProgressBar *ProgressBar;
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall OpenFileButtonClick(TObject *Sender);
	void __fastcall OpenTableButtonClick(TObject *Sender);
	void __fastcall OpenKeyButtonClick(TObject *Sender);
	void __fastcall KeyEditChange(TObject *Sender);
	void __fastcall RadioGroup1Click(TObject *Sender);
	void __fastcall TableButtonClick(TObject *Sender);
	void __fastcall OpenReverseTableButtonClick(TObject *Sender);
	void __fastcall CryptButtonClick(TObject *Sender);
	void __fastcall DecryptButtonClick(TObject *Sender);

private:	// User declarations
	bool TForm1::CheckOption();
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
	char* UnicodeToChar(UnicodeString input);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
