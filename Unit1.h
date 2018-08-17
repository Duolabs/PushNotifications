//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Memo.hpp>
#include <FMX.ScrollBox.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <DW.PushClient.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TMemo *Memo1;
	TButton *ResendRequestBut;
	TButton *TestInternet;
	void __fastcall ResendRequestButClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall TestInternetClick(TObject *Sender);
private:	// User declarations
	TPushClient * FPushClient;

	void __fastcall OnReceiveNotificationEvent(TObject *Sender, TPushServiceNotification * const ANotification);
	void __fastcall OnServiceConnectionChange(TObject *Sender, TPushService::TChanges AChange);

public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------

int ConvertUnicodeToChar (UnicodeString InputUnicode, char * CharString);

#endif
